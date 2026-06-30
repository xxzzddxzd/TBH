#!/usr/bin/env python3
"""extract_item_icons.py: export TaskBarHero item sprites for the overlay."""

from __future__ import annotations

import argparse
import csv
import io
import os
import re
import sys
from pathlib import Path


TRANSPARENT_KEY = (255, 0, 255)
SCRIPT_DIR = Path(__file__).resolve().parent
DEFAULT_OUT_DIR = SCRIPT_DIR / "TaskBarHeroSpeedIcons"
DEFAULT_NAMES_OUT = SCRIPT_DIR / "TaskBarHeroSpeedItemNames.zh-Hans.tsv"
ASSET_RELATIVE_PATH = Path("TaskBarHero_Data") / "sharedassets0.assets"
AA_RELATIVE_DIR = Path("TaskBarHero_Data") / "StreamingAssets" / "aa" / "StandaloneWindows64"
SHARED_LOCALIZATION_BUNDLE = "localization-assets-shared_assets_all.bundle"
ZH_HANS_LOCALIZATION_BUNDLE = (
    "localization-string-tables-chinese(simplified)(zh-hans)_assets_all.bundle"
)
GRADE_ZH = {
    "COMMON": "普通",
    "UNCOMMON": "优秀",
    "RARE": "稀有",
    "LEGENDARY": "传说",
    "IMMORTAL": "不朽",
    "ARCANA": "奥秘",
    "BEYOND": "超凡",
    "CELESTIAL": "天界",
    "DIVINE": "神圣",
    "COSMIC": "宇宙",
}


def add_optional_module_path() -> None:
    extra = os.environ.get("TBH_UNITYPY_PATH")
    if extra:
        sys.path.insert(0, extra)


def import_unitypy():
    add_optional_module_path()
    try:
        import UnityPy  # type: ignore
    except ImportError as exc:
        raise SystemExit(
            "UnityPy is required. Install it with: "
            "python3 -m pip install --target /tmp/tbh_unitypy UnityPy "
            "and run with TBH_UNITYPY_PATH=/tmp/tbh_unitypy"
        ) from exc
    return UnityPy


def default_game_dir() -> Path | None:
    env_dir = os.environ.get("TBH_GAME_DIR")
    candidates = []
    if env_dir:
        candidates.append(Path(env_dir))
    candidates.append(
        Path.home()
        / "Library/Application Support/CrossOver/Bottles/Steam/drive_c"
        / "Program Files (x86)/Steam/steamapps/common/TaskbarHero"
    )
    for candidate in candidates:
        if (candidate / ASSET_RELATIVE_PATH).is_file():
            return candidate
    return None


def safe_filename(name: str) -> str:
    chars = []
    for ch in name:
        if ch.isascii() and (ch.isalnum() or ch in "._-"):
            chars.append(ch)
        else:
            chars.append("_")
    return "".join(chars) or "Item_unknown"


def item_info_rows(env) -> list[dict[str, str]]:
    for obj in env.objects:
        if obj.type.name != "TextAsset":
            continue
        data = obj.read()
        if getattr(data, "m_Name", "") != "ItemInfoData":
            continue
        text = getattr(data, "m_Script", "").lstrip("\ufeff")
        return list(csv.DictReader(io.StringIO(text)))
    raise SystemExit("ItemInfoData TextAsset was not found in sharedassets0.assets")


def item_icon_names(env) -> set[str]:
    return {
        row.get("IconPath", "").strip()
        for row in item_info_rows(env)
        if row.get("IconPath", "").strip()
    }


def save_colorkey_bmp(image, path: Path) -> None:
    rgba = image.convert("RGBA")
    rgb = rgba.convert("RGB")
    alpha = rgba.getchannel("A")
    output = rgb.copy()
    pixels = output.load()
    alpha_pixels = alpha.load()
    width, height = output.size
    for y in range(height):
        for x in range(width):
            if alpha_pixels[x, y] < 16:
                pixels[x, y] = TRANSPARENT_KEY
    output.save(path, "BMP")


def read_localization_table(bundle_path: Path, table_name: str) -> dict[int, str]:
    UnityPy = import_unitypy()
    env = UnityPy.load(str(bundle_path))
    for obj in env.objects:
        if obj.type.name != "MonoBehaviour":
            continue
        data = obj.read()
        if getattr(data, "m_Name", "") != table_name:
            continue
        tree = obj.read_typetree()
        if table_name == "ItemTable Shared Data":
            return {
                int(entry["m_Id"]): str(entry["m_Key"])
                for entry in tree.get("m_Entries", [])
                if entry.get("m_Key")
            }
        if table_name == "ItemTable_zh-Hans":
            return {
                int(entry["m_Id"]): str(entry["m_Localized"])
                for entry in tree.get("m_TableData", [])
                if entry.get("m_Localized")
            }
    raise SystemExit(f"{table_name} was not found in {bundle_path}")


def clean_tsv_value(value: str) -> str:
    return value.replace("\t", " ").replace("\r", " ").replace("\n", " ").strip()


def clean_plain_name(value: str) -> str:
    value = clean_tsv_value(value)
    value = re.sub(r"[_]+", " ", value)
    value = re.sub(r"\s+", " ", value)
    return value.strip()


def stage_box_fallback_name(name_key: str) -> str:
    suffix = ""
    level = re.search(r"\bLv\s*(\d+)", name_key, re.IGNORECASE)
    trailing = re.search(r"\b(\d+)\s*$", name_key)
    if level:
        suffix = f" Lv{level.group(1)}"
    elif trailing:
        suffix = f" {trailing.group(1)}"

    if "Normal Monster Box" in name_key:
        return f"普通怪物宝箱{suffix}"
    if "Stage Boss Box" in name_key:
        return f"关卡 Boss 宝箱{suffix}"
    if "Act Boss Box" in name_key:
        return f"幕 Boss 宝箱{suffix}"
    return ""


def fallback_item_name(row: dict[str, str]) -> str:
    item_id = row.get("ItemKey", "").strip()
    item_type = row.get("ITEMTYPE", "").strip()
    grade = row.get("GRADE", "").strip()
    name_key = row.get("NameKey", "").strip()

    if item_type == "STAGEBOX":
        name = stage_box_fallback_name(name_key)
        if name:
            return name
    if item_type == "MATERIAL" and item_id.startswith("150"):
        return f"{GRADE_ZH.get(grade, grade or '未知')}合成材料"
    if name_key and not name_key.startswith("ItemName_"):
        return clean_plain_name(name_key)
    if item_type:
        return f"{GRADE_ZH.get(grade, grade or '未知')}物品 {item_id}"
    return f"物品 {item_id}"


def export_item_names(asset_path: Path,
                      shared_bundle: Path,
                      locale_bundle: Path,
                      out_path: Path) -> tuple[int, int]:
    UnityPy = import_unitypy()
    env = UnityPy.load(str(asset_path))
    item_rows = item_info_rows(env)
    id_to_key = read_localization_table(shared_bundle, "ItemTable Shared Data")
    id_to_name = read_localization_table(locale_bundle, "ItemTable_zh-Hans")
    key_to_name = {
        key: clean_tsv_value(id_to_name.get(entry_id, ""))
        for entry_id, key in id_to_key.items()
        if clean_tsv_value(id_to_name.get(entry_id, ""))
    }
    rows: dict[str, str] = {}

    def add_name(key: str, localized: str) -> None:
        key = clean_tsv_value(key)
        localized = clean_tsv_value(localized)
        if key and localized and key not in rows:
            rows[key] = localized

    for row in item_rows:
        item_id = row.get("ItemKey", "").strip()
        name_key = row.get("NameKey", "").strip()
        if not item_id:
            continue
        generated_key = "ItemName_{item_id}".format(item_id=item_id)
        localized = (
            key_to_name.get(name_key)
            or key_to_name.get(generated_key)
            or fallback_item_name(row)
        )
        add_name(generated_key, localized)
        if name_key and name_key != generated_key:
            add_name(name_key, localized)

    for entry_id, key in id_to_key.items():
        localized = id_to_name.get(entry_id, "").strip()
        if not localized:
            continue
        add_name(key, localized)

    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8", newline="\n") as f:
        f.write("key\tzh-Hans\n")
        for key, localized in sorted(rows.items()):
            f.write(f"{clean_tsv_value(key)}\t{localized}\n")
    return len(rows), len(item_rows)


def export_icons(asset_path: Path, out_dir: Path) -> tuple[int, int]:
    UnityPy = import_unitypy()
    env = UnityPy.load(str(asset_path))
    wanted = item_icon_names(env)
    out_dir.mkdir(parents=True, exist_ok=True)

    exported = 0
    for obj in env.objects:
        if obj.type.name != "Sprite":
            continue
        data = obj.read()
        name = getattr(data, "m_Name", "")
        if name not in wanted:
            continue
        save_colorkey_bmp(data.image, out_dir / f"{safe_filename(name)}.bmp")
        exported += 1
    return exported, len(wanted)


def parse_args() -> argparse.Namespace:
    detected_game_dir = default_game_dir()
    parser = argparse.ArgumentParser(
        description="Export TaskBarHero item icons from UnityPy-readable assets."
    )
    parser.add_argument(
        "--game-dir",
        type=Path,
        default=detected_game_dir,
        help="TaskbarHero install directory; defaults to TBH_GAME_DIR or CrossOver Steam path.",
    )
    parser.add_argument(
        "--asset",
        type=Path,
        default=None,
        help="Direct path to sharedassets0.assets.",
    )
    parser.add_argument(
        "--out-dir",
        type=Path,
        default=DEFAULT_OUT_DIR,
        help="Output directory for TaskBarHeroSpeedIcons BMP files.",
    )
    parser.add_argument(
        "--names-out",
        type=Path,
        default=DEFAULT_NAMES_OUT,
        help="Output TSV path for zh-Hans item names.",
    )
    parser.add_argument(
        "--shared-bundle",
        type=Path,
        default=None,
        help="Direct path to localization-assets-shared_assets_all.bundle.",
    )
    parser.add_argument(
        "--locale-bundle",
        type=Path,
        default=None,
        help="Direct path to ItemTable_zh-Hans localization bundle.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.asset:
        asset_path = args.asset
    elif args.game_dir:
        asset_path = args.game_dir / ASSET_RELATIVE_PATH
    else:
        print("Game directory was not detected; pass --game-dir or --asset.", file=sys.stderr)
        return 2

    if not asset_path.is_file():
        print(f"sharedassets0.assets not found: {asset_path}", file=sys.stderr)
        return 2

    if args.shared_bundle:
        shared_bundle = args.shared_bundle
    elif args.game_dir:
        shared_bundle = args.game_dir / AA_RELATIVE_DIR / SHARED_LOCALIZATION_BUNDLE
    else:
        print("Game directory was not detected; pass --game-dir or --shared-bundle.", file=sys.stderr)
        return 2
    if args.locale_bundle:
        locale_bundle = args.locale_bundle
    elif args.game_dir:
        locale_bundle = args.game_dir / AA_RELATIVE_DIR / ZH_HANS_LOCALIZATION_BUNDLE
    else:
        print("Game directory was not detected; pass --game-dir or --locale-bundle.", file=sys.stderr)
        return 2

    if not shared_bundle.is_file():
        print(f"localization shared bundle not found: {shared_bundle}", file=sys.stderr)
        return 2
    if not locale_bundle.is_file():
        print(f"zh-Hans localization bundle not found: {locale_bundle}", file=sys.stderr)
        return 2

    exported, wanted = export_icons(asset_path, args.out_dir)
    print(f"exported {exported}/{wanted} item icons to {args.out_dir}")
    name_count, item_count = export_item_names(asset_path,
                                               shared_bundle,
                                               locale_bundle,
                                               args.names_out)
    print(
        f"exported {name_count} zh-Hans item names for "
        f"{item_count} ItemInfoData rows to {args.names_out}"
    )
    if exported <= 0:
        return 3
    if name_count <= 0:
        return 4
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
