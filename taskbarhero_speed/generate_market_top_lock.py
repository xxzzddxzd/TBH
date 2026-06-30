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


MARKET_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/data/market.json"
ITEM_NAMES_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/main/DpsMeter/item_names.json"
ITEM_META_URL = "https://raw.githubusercontent.com/WarmBed/TBH-DPS-dashboard/main/DpsMeter/item_meta.json"
DEFAULT_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketTop100.tsv")
DEFAULT_FALLBACK_OUTPUT = Path(__file__).with_name("TaskBarHeroSpeedMarketTop100.default.tsv")

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


def build_market_top_lock(market: dict, item_names: dict, item_meta: dict, limit: int) -> tuple[list[str], list[str]]:
    by_en = build_name_index(item_names)
    rows = []
    seen_item_ids = set()
    missing = []
    market_list = market.get("list", [])
    top_items = sorted(
        (item for item in market_list if isinstance(item, dict)),
        key=lambda item: int(item.get("price") or 0),
        reverse=True,
    )[:limit]

    for rank, item in enumerate(top_items, 1):
        market_hash = item.get("hash") or item.get("name") or ""
        if not market_hash:
            continue
        item_ids = item_ids_for_market_hash(market_hash, by_en, item_meta)
        if not item_ids:
            missing.append(market_hash)
            continue
        zh_hans = ""
        localized = item.get("names")
        if isinstance(localized, dict):
            zh_hans = localized.get("zh-Hans") or ""
        for item_id in item_ids:
            if item_id in seen_item_ids:
                continue
            seen_item_ids.add(item_id)
            rows.append(
                "\t".join(
                    [
                        item_id,
                        str(int(item.get("price") or 0)),
                        str(rank),
                        clean_cell(market_hash),
                        clean_cell(zh_hans),
                    ]
                )
            )
    return rows, missing


def write_tsv(output: Path, rows: list[str], missing: list[str], market: dict, limit: int) -> None:
    now = _dt.datetime.now(_dt.timezone.utc).replace(microsecond=0).isoformat()
    lines = [
        "# TaskBarHeroSpeed market top lock list",
        f"# generated_at_utc={now}",
        f"# source_market={MARKET_URL}",
        f"# market_built_at={market.get('builtAt', '')}",
        f"# limit={limit}",
        f"# item_ids={len(rows)}",
    ]
    if missing:
        lines.append("# missing_market_hashes=" + ",".join(clean_cell(x) for x in missing))
    lines.append("item_id\tprice_cents\trank\tmarket_hash\tname_zh_hans")
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
    parser = argparse.ArgumentParser(description="Generate TaskBarHeroSpeed lock IDs for the top priced market items.")
    parser.add_argument("--market", default=MARKET_URL, help="market.json URL or local path")
    parser.add_argument("--item-names", default=ITEM_NAMES_URL, help="item_names.json URL or local path")
    parser.add_argument("--item-meta", default=ITEM_META_URL, help="item_meta.json URL or local path")
    parser.add_argument("--output", default=str(DEFAULT_OUTPUT), help="output TSV path")
    parser.add_argument("--fallback", default=str(DEFAULT_FALLBACK_OUTPUT), help="default TSV to copy if live sources cannot be loaded")
    parser.add_argument("--limit", type=int, default=100, help="number of market entries to include")
    args = parser.parse_args(argv)

    if args.limit <= 0:
        raise SystemExit("--limit must be positive")
    output = Path(args.output)
    fallback = Path(args.fallback)
    try:
        market = load_json_source(args.market)
        item_names = load_json_source(args.item_names)
        item_meta = load_json_source(args.item_meta)
        rows, missing = build_market_top_lock(market, item_names, item_meta, args.limit)
    except Exception as exc:
        return 0 if copy_default_fallback(output, fallback, f"live fetch failed: {exc}") else 1
    if missing:
        print("missing market hashes:", ", ".join(missing), file=sys.stderr)
    if not rows:
        return 0 if copy_default_fallback(output, fallback, "no item ids generated from live sources") else 1
    write_tsv(output, rows, missing, market, args.limit)
    print(f"wrote {output}: {len(rows)} item ids from top {args.limit} market entries")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
