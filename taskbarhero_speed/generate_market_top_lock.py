#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime as _dt
import json
import re
import shutil
import sys
import urllib.request
from pathlib import Path


PRICES_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/data/prices.json"
ITEM_NAMES_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/main/DpsMeter/item_names.json"
ITEM_META_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/main/DpsMeter/item_meta.json"
DEFAULT_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketTop100.tsv")
DEFAULT_FALLBACK_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketTop100.default.tsv")
DEFAULT_PRICE_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketPrices.tsv")
DEFAULT_PRICE_FALLBACK_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketPrices.default.tsv")

RARITY_TO_META_GRADE = {
    "Common": "COMMON",
    "Uncommon": "UNCOMMON",
    "Rare": "RARE",
    "Legendary": "LEGENDARY",
    "Immortal": "IMMORTAL",
    "Arcana": "ARCANA",
    "Beyond": "BEYOND",
    "Celestial": "CELESTIAL",
    "Divine": "DIVINE",
    "Cosmic": "COSMIC",
}

RARITY_TO_ZH_HANS = {
    "Common": "普通",
    "Uncommon": "罕见",
    "Rare": "稀有",
    "Legendary": "传奇",
    "Immortal": "不朽",
    "Arcana": "至宝",
    "Beyond": "超凡",
    "Celestial": "天界",
    "Divine": "神圣",
    "Cosmic": "宇宙",
}


def load_json_source(source: str):
    if source.startswith(("http://", "https://")):
        req = urllib.request.Request(
            source,
            headers={"User-Agent": "TaskBarHeroSpeed-market-top-lock"},
        )
        with urllib.request.urlopen(req, timeout=30) as response:
            return json.loads(response.read().decode("utf-8"))
    return json.loads(Path(source).read_text(encoding="utf-8"))


def build_name_index(item_names: dict) -> dict[str, list[str]]:
    by_en: dict[str, list[str]] = {}
    for item_id, names in item_names.items():
        if not isinstance(names, dict):
            continue
        en_name = names.get("en-US")
        if not en_name:
            continue
        by_en.setdefault(en_name, []).append(str(item_id))
    return by_en


def item_ids_for_market_hash(market_hash: str, by_en: dict[str, list[str]], item_meta: dict) -> list[str]:
    gear_match = re.match(r"^(.+) \(([^)]+)\) \S+$", market_hash)
    if gear_match:
        base_name, rarity_name = gear_match.group(1), gear_match.group(2)
        grade = RARITY_TO_META_GRADE.get(rarity_name, rarity_name.upper())
        out = []
        for item_id in by_en.get(base_name, []):
            meta = item_meta.get(str(item_id), {})
            if isinstance(meta, dict) and str(meta.get("g", "")).upper() == grade:
                out.append(str(item_id))
        return sorted(out, key=lambda value: int(value))
    return sorted(by_en.get(market_hash, []), key=lambda value: int(value))


def clean_cell(value: object) -> str:
    return str(value if value is not None else "").replace("\t", " ").replace("\r", " ").replace("\n", " ")


def localized_market_name(market_hash: str, item_ids: list[str], item_names: dict) -> str:
    first_id = item_ids[0] if item_ids else ""
    names = item_names.get(first_id, {}) if first_id else {}
    base_zh = names.get("zh-Hans") if isinstance(names, dict) else ""
    gear_match = re.match(r"^(.+) \(([^)]+)\)(.*)$", market_hash)
    if gear_match:
        grade_zh = RARITY_TO_ZH_HANS.get(gear_match.group(2), gear_match.group(2))
        suffix = gear_match.group(3).strip()
        if base_zh:
            return f"{base_zh} ({grade_zh}) {suffix}".strip()
    if base_zh:
        return base_zh
    return market_hash


def last_sold_timestamp(item: dict) -> int:
    hist = item.get("hist")
    last = 0
    if isinstance(hist, list):
        for point in hist:
            if not isinstance(point, list) or len(point) < 3:
                continue
            try:
                timestamp = int(point[0])
                volume = int(point[2])
            except (TypeError, ValueError):
                continue
            if timestamp > 0 and volume > 0:
                last = timestamp
    return last


def traded_market_entries(prices: dict, item_names: dict, item_meta: dict) -> tuple[list[dict], list[str]]:
    by_en = build_name_index(item_names)
    entries = []
    missing = []
    price_items = prices.get("items", {})

    for market_hash, item in price_items.items():
        if not isinstance(item, dict):
            continue
        try:
            price_cents = int(item.get("medianCents") or 0)
        except (TypeError, ValueError):
            price_cents = 0
        if price_cents <= 0:
            continue
        last_sold_at = last_sold_timestamp(item)
        if last_sold_at <= 0:
            continue
        if not market_hash:
            continue
        item_ids = item_ids_for_market_hash(market_hash, by_en, item_meta)
        if not item_ids:
            missing.append(market_hash)
            continue
        entries.append(
            {
                "market_hash": market_hash,
                "item_ids": item_ids,
                "price_cents": price_cents,
                "last_sold_at": last_sold_at,
                "name_zh_hans": localized_market_name(market_hash, item_ids, item_names),
            }
        )
    entries.sort(key=lambda item: item["price_cents"], reverse=True)
    return entries, missing


def build_market_top_lock(prices: dict, item_names: dict, item_meta: dict, limit: int) -> tuple[list[str], list[str]]:
    rows = []
    seen_item_ids = set()
    entries, missing = traded_market_entries(prices, item_names, item_meta)

    for rank, item in enumerate(entries[:limit], 1):
        for item_id in item["item_ids"]:
            if item_id in seen_item_ids:
                continue
            seen_item_ids.add(item_id)
            rows.append(
                "\t".join(
                    [
                        item_id,
                        str(item["price_cents"]),
                        str(rank),
                        str(item["last_sold_at"]),
                        clean_cell(item["market_hash"]),
                        clean_cell(item["name_zh_hans"]),
                    ]
                )
            )
    return rows, missing


def build_market_prices(prices: dict, item_names: dict, item_meta: dict) -> tuple[list[str], list[str]]:
    rows = []
    seen_item_ids = set()
    entries, missing = traded_market_entries(prices, item_names, item_meta)

    for item in entries:
        for item_id in item["item_ids"]:
            if item_id in seen_item_ids:
                continue
            seen_item_ids.add(item_id)
            rows.append(
                "\t".join(
                    [
                        item_id,
                        str(item["price_cents"]),
                        str(item["last_sold_at"]),
                        clean_cell(item["market_hash"]),
                        clean_cell(item["name_zh_hans"]),
                    ]
                )
            )
    return rows, missing


def write_top_tsv(output: Path, rows: list[str], missing: list[str], prices: dict, limit: int) -> None:
    now = _dt.datetime.now(_dt.timezone.utc).replace(microsecond=0).isoformat()
    lines = [
        "# TaskBarHeroSpeed traded market top lock list",
        f"# generated_at_utc={now}",
        f"# source_prices={PRICES_URL}",
        f"# prices_cached_at={prices.get('cachedAt', '')}",
        f"# limit={limit}",
        f"# item_ids={len(rows)}",
    ]
    if missing:
        lines.append("# missing_market_hashes=" + ",".join(clean_cell(x) for x in missing))
    lines.append("item_id\tprice_cents\trank\tlast_sold_at\tmarket_hash\tname_zh_hans")
    lines.extend(rows)
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_prices_tsv(output: Path, rows: list[str], missing: list[str], prices: dict) -> None:
    now = _dt.datetime.now(_dt.timezone.utc).replace(microsecond=0).isoformat()
    lines = [
        "# TaskBarHeroSpeed traded market price list",
        f"# generated_at_utc={now}",
        f"# source_prices={PRICES_URL}",
        f"# prices_cached_at={prices.get('cachedAt', '')}",
        f"# item_ids={len(rows)}",
    ]
    if missing:
        lines.append("# missing_market_hashes=" + ",".join(clean_cell(x) for x in missing))
    lines.append("item_id\tprice_cents\tlast_sold_at\tmarket_hash\tname_zh_hans")
    lines.extend(rows)
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")


def copy_default_fallback(output: Path, fallback: Path, reason: str) -> bool:
    if not fallback.is_file():
        print(f"{reason}; default fallback missing: {fallback}", file=sys.stderr)
        return False
    output.parent.mkdir(parents=True, exist_ok=True)
    if output.resolve() != fallback.resolve():
        shutil.copyfile(fallback, output)
    print(f"using default fallback {fallback}: {reason}", file=sys.stderr)
    print(f"wrote {output}: default market top lock list")
    return True


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Generate TaskBarHeroSpeed lock IDs and traded price tables.")
    parser.add_argument("--prices-source", "--market", dest="prices_source", default=PRICES_URL,
                        help="prices.json URL or local path")
    parser.add_argument("--item-names", default=ITEM_NAMES_URL, help="item_names.json URL or local path")
    parser.add_argument("--item-meta", default=ITEM_META_URL, help="item_meta.json URL or local path")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="output TSV path")
    parser.add_argument("--fallback", default=str(DEFAULT_FALLBACK_OUTPUT), help="default TSV to copy if live sources cannot be loaded")
    parser.add_argument("--prices-output", default=str(DEFAULT_PRICE_OUTPUT), help="full traded-price TSV path")
    parser.add_argument("--prices-fallback", default=str(DEFAULT_PRICE_FALLBACK_OUTPUT),
                        help="default traded-price TSV to copy if live sources cannot be loaded")
    parser.add_argument("--limit", type=int, default=100, help="number of market entries to include")
    args = parser.parse_args(argv)

    if args.limit <= 0:
        raise SystemExit("--limit must be positive")
    output = Path(args.output)
    fallback = Path(args.fallback)
    prices_output = Path(args.prices_output)
    prices_fallback = Path(args.prices_fallback)
    try:
        prices = load_json_source(args.prices_source)
        item_names = load_json_source(args.item_names)
        item_meta = load_json_source(args.item_meta)
        rows, missing = build_market_top_lock(prices, item_names, item_meta, args.limit)
        price_rows, price_missing = build_market_prices(prices, item_names, item_meta)
    except Exception as exc:
        top_ok = copy_default_fallback(output, fallback, f"live fetch failed: {exc}")
        prices_ok = copy_default_fallback(prices_output, prices_fallback, f"live fetch failed: {exc}")
        return 0 if top_ok and prices_ok else 1
    if missing:
        print("missing market hashes:", ", ".join(missing), file=sys.stderr)
    extra_missing = [item for item in price_missing if item not in set(missing)]
    if extra_missing:
        print("missing price market hashes:", ", ".join(extra_missing), file=sys.stderr)
    if not rows:
        top_ok = copy_default_fallback(output, fallback, "no item ids generated from live sources")
    else:
        write_top_tsv(output, rows, missing, prices, args.limit)
        print(f"wrote {output}: {len(rows)} item ids from top {args.limit} traded market entries")
        top_ok = True
    if not price_rows:
        prices_ok = copy_default_fallback(prices_output, prices_fallback,
                                          "no traded price item ids generated from live sources")
    else:
        write_prices_tsv(prices_output, price_rows, price_missing, prices)
        print(f"wrote {prices_output}: {len(price_rows)} item ids with traded prices")
        prices_ok = True
    return 0 if top_ok and prices_ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
