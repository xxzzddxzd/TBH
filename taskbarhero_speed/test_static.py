#!/usr/bin/env python3
from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "taskbarhero_speed" / "winhttp_proxy.c"
INI = ROOT / "taskbarhero_speed" / "package" / "TaskBarHeroSpeed.ini"
PACKAGE_DIR = ROOT / "taskbarhero_speed" / "package"
PKG_README = ROOT / "taskbarhero_speed" / "package" / "README.txt"
DEV_README = ROOT / "taskbarhero_speed" / "README.md"
ROOT_INI = ROOT / "TaskBarHeroSpeed.ini"
DEV_INI = ROOT / "taskbarhero_speed" / "TaskBarHeroSpeed.ini"
INJECTOR = ROOT / "taskbarhero_speed" / "injector.c"
ICON_EXTRACTOR = ROOT / "taskbarhero_speed" / "extract_item_icons.py"
NAME_TABLE = ROOT / "taskbarhero_speed" / "TaskBarHeroSpeedItemNames.zh-Hans.tsv"
MARKET_TOP_SCRIPT = ROOT / "taskbarhero_speed" / "generate_market_top_lock.py"
MARKET_TOP_FILE = ROOT / "taskbarhero_speed" / "TaskBarHeroSpeedMarketTop100.tsv"
MARKET_TOP_DEFAULT_FILE = ROOT / "taskbarhero_speed" / "TaskBarHeroSpeedMarketTop100.default.tsv"
PACKAGE_SCRIPT = ROOT / "taskbarhero_speed" / "package_windows.sh"
PREBUILT_SCRIPT = ROOT / "taskbarhero_speed" / "package_prebuilt.sh"
BUILD_SCRIPT = ROOT / "taskbarhero_speed" / "build.sh"
VERSIONS_DIR = ROOT / "taskbarhero_speed" / "versions"
INSTALL_AUTOSTART = ROOT / "taskbarhero_speed" / "package" / "Install-AutoStart.bat"
UPDATE_BAT = ROOT / "taskbarhero_speed" / "package" / "Update.bat"
INJECT_RUNNING_SCRIPT = ROOT / "taskbarhero_speed" / "inject_running_game.sh"


def require(condition, message):
    if not condition:
        print(f"FAIL: {message}", file=sys.stderr)
        return 1
    return 0


def main():
    src = SRC.read_text(encoding="utf-8")
    ini = INI.read_text(encoding="utf-8")
    readme = PKG_README.read_text(encoding="utf-8")
    dev_readme = DEV_README.read_text(encoding="utf-8")
    root_ini = ROOT_INI.read_text(encoding="utf-8") if ROOT_INI.exists() else ""
    dev_ini = DEV_INI.read_text(encoding="utf-8") if DEV_INI.exists() else ""
    injector = INJECTOR.read_text(encoding="utf-8")
    icon_extractor = ICON_EXTRACTOR.read_text(encoding="utf-8") if ICON_EXTRACTOR.exists() else ""
    market_top_script = MARKET_TOP_SCRIPT.read_text(encoding="utf-8") if MARKET_TOP_SCRIPT.exists() else ""
    market_top_file = MARKET_TOP_FILE.read_text(encoding="utf-8") if MARKET_TOP_FILE.exists() else ""
    market_top_default_file = MARKET_TOP_DEFAULT_FILE.read_text(encoding="utf-8") if MARKET_TOP_DEFAULT_FILE.exists() else ""
    package_script = PACKAGE_SCRIPT.read_text(encoding="utf-8")
    prebuilt_script = PREBUILT_SCRIPT.read_text(encoding="utf-8")
    build_script = BUILD_SCRIPT.read_text(encoding="utf-8")
    install_autostart = INSTALL_AUTOSTART.read_text(encoding="utf-8")
    update_bat = UPDATE_BAT.read_text(encoding="utf-8") if UPDATE_BAT.exists() else ""
    inject_running_script = INJECT_RUNNING_SCRIPT.read_text(encoding="utf-8")
    failures = 0

    expectations = [
        ("TBHS_SUPPORTED_GAME_VERSION", src),
        ("TBHS_PLUGIN_VERSION", src),
        ("TBHS_PLUGIN_SUBVERSION", src),
        ("g_exp_multiplier", src),
        ("g_cube_exp_multiplier", src),
        ("g_auto_synthesis_enabled", src),
        ("g_auto_synthesis_use_storage", src),
        ("g_auto_synthesis_pending", src),
        ("g_config_dir", src),
        ("config path:", src),
        ("g_auto_item_lock_enabled", src),
        ("AUTO_ITEM_LOCK_MAX_ITEMS 8192", src),
        ("g_auto_item_lock_selected_count", src),
        ("AUTO ITEM LOCK pending", src),
        ("RVA_ITEM_CACHE_BY_UNIQUE_ID", src),
        ("RVA_ITEM_CACHE_STORE_TYPEINFO", src),
        ("RVA_ITEM_CACHE_GET_MANUAL_LOCK", src),
        ("RVA_ITEM_CACHE_SET_MANUAL_LOCK", src),
        ("RVA_MASTER_DATA_SINGLETON_TYPEINFO 0x5E40568ULL", src),
        ("bam holds itemInfoData", src),
        ("maybe_load_auto_item_lock_catalog_from_game_thread", src),
        ("maybe_auto_item_lock_from_game_thread", src),
        ("ITEM_LOCK_LIST_TIMER_REFRESH", src),
        ("refresh_item_lock_list_if_catalog_changed", src),
        ("item_lock_filter_dropdown_open", src),
        ("CB_GETDROPPEDSTATE", src),
        ("CBN_DROPDOWN", src),
        ("CBN_CLOSEUP", src),
        ("EGRADE_CELESTIAL 7", src),
        ("EGRADE_DIVINE 8", src),
        ("EGRADE_COSMIC 9", src),
        ("AUTO_ITEM_LOCK_COIN_MIN 160000", src),
        ("AUTO_ITEM_LOCK_COIN_MAX 160020", src),
        ("g_item_lock_condition_high_grade", src),
        ("g_item_lock_condition_coin", src),
        ("g_item_lock_condition_market_top", src),
        ("g_manual_item_lock_pending", src),
        ("auto_item_lock_item_matches_conditions", src),
        ("auto_item_lock_market_top_selected", src),
        ("load_auto_item_lock_market_top_ids", src),
        ("TaskBarHeroSpeedMarketTop100.tsv", src),
        ("OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP", src),
        ("queue_manual_item_lock_request", src),
        ("manual_item_lock_from_game_thread", src),
        ("UI_MANAGER_UI_HERO_OFFSET 0xB0", src),
        ("UI_HERO_INVENTORY_SLOTS_OFFSET 0x78", src),
        ("UI_REMAKE_STASH_SLOT_LIST_OFFSET 0x60", src),
        ("ITEM_SLOT_ITEM_CACHE_OFFSET 0xB8", src),
        ("ITEM_CACHE_ITEM_INFO_OFFSET 0x10", src),
        ("ITEM_CACHE_EQUIP_CLASS_OFFSET 0x30", src),
        ("IL2CPP_DICT_ENTRIES_OFFSET", src),
        ("IL2CPP_DICT_COUNT_OFFSET", src),
        ("IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE", src),
        ("get_item_cache_dictionary", src),
        ("manual_item_lock_scan_item_cache_dictionary", src),
        ("auto_item_lock_class_name", src),
        ("auto_item_lock_catalog_class_from_gear_type", src),
        ("item_lock_catalog_is_highest_rarity", src),
        ("OVERLAY_BUTTON_ITEM_LOCK_LIST", src),
        ("OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE", src),
        ("OVERLAY_BUTTON_ITEM_LOCK_COIN", src),
        ("OVERLAY_BUTTON_ITEM_LOCK_MANUAL", src),
        ("ITEM_LOCK_LIST_CLASS_PREFIX", src),
        ("ITEM_LOCK_LIST_CONTROL_LIST", src),
        ("ITEM_LOCK_LIST_CONTROL_CLASS", src),
        ("ITEM_LOCK_LIST_CONTROL_SEARCH", src),
        ("ITEM_LOCK_LIST_CONTROL_CLEAR", src),
        ("draw_item_lock_checkbox_row", src),
        ("draw_item_lock_icon_cue", src),
        ("ITEM_LOCK_ICON_DIR_NAME", src),
        ("TaskBarHeroSpeedIcons", src),
        ("ITEM_LOCK_NAME_TABLE_FILE", src),
        ("TaskBarHeroSpeedItemNames.zh-Hans.tsv", src),
        ("AutoItemLockNameEntry", src),
        ("load_auto_item_lock_name_table", src),
        ("lookup_auto_item_lock_localized_name", src),
        ("ensure_auto_item_lock_localized_names_loaded();", src),
        ("return \"材料\";", src),
        ("return \"装备\";", src),
        ("return \"关卡宝箱\";", src),
        ("case EGRADE_DIVINE: return \"神圣\";", src),
        ("case EGRADE_COSMIC: return \"宇宙\";", src),
        ("load_item_lock_icon_bitmap", src),
        ("draw_item_lock_icon_bitmap", src),
        ("LR_LOADFROMFILE | LR_CREATEDIBSECTION", src),
        ("transparent_blt_t", src),
        ("DeleteObject(info->icon_bitmap)", src),
        ("draw_item_lock_icon_bitmap(draw->hDC, &icon, info, checked)", src),
        ("item_lock_listbox_proc", src),
        ("item_lock_toggle_catalog_index", src),
        ("item_lock_combo_add_utf8", src),
        ("item_lock_catalog_matches_search", src),
        ("auto_item_lock_ids", src),
        ("load_auto_item_lock_ids", src),
        ("save_auto_item_lock_ids", src),
        ("handle_box_reward_auto_item_lock", src),
        ("read_il2cpp_string_utf8", src),
        ("ITEM_INFO_ICON_PATH_OFFSET 0x78", src),
        ("icon_path", src),
        ("display_name", src),
        ("auto_item_lock_make_display_name", src),
        ("RVA_BOX_DATA_GET_REWARD_ITEM_ID 0x967670ULL", src),
        ("RVA_BOX_DATA_GET_REWARD_ITEM_UNIQUE_ID 0x967690ULL", src),
        ("read_boxdata_reward_fields", src),
        ("AUTO_SYNTHESIS_BOX_OPEN_DELAY_MS 2000", src),
        ("AUTO_SYNTHESIS_STASH_DELAY_MS 3000", src),
        ("AUTO_SYNTHESIS_FILL_DELAY_MS 3000", src),
        ("AUTO_SYNTHESIS_TRIGGER_DELAY_MS 2000", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_STASH", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_FILL", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER", src),
        ("install_exp_reward_calc_hook", src),
        ("install_ui_cube_hooks", src),
        ("request_auto_synthesis_after_box_open", src),
        ("maybe_request_auto_synthesis_from_reward_item", src),
        ("maybe_auto_synthesis_from_game_thread", src),
        ("g_auto_synthesis_result_watch_until", src),
        ("maybe_handle_auto_synthesis_reward_add", src),
        ("RVA_UI_CUBE_HML", src),
        ("RVA_CUBE_TYPEINFO 0x5DC88E0ULL", src),
        ("RVA_CUBE_SELECT_RECIPE_TYPE 0x8A0950ULL", src),
        ("RVA_CUBE_AUTOFILL_CURRENT_RECIPE 0x941B40ULL", src),
        ("CUBE_CURRENT_RECIPE_OFFSET 0x140", src),
        ("ERECIPE_SYNTHESIS 1", src),
        ("get_cube_current_recipe", src),
        ("ensure_cube_current_recipe", src),
        ("RVA_UI_REMAKE_STASH_INVENTORY_TO_STASH", src),
        ("RVA_UI_REMAKE_STASH_INVENTORY_TO_STASH 0xA3B120ULL", src),
        ("RVA_CUBE_CLEAR_CURRENT_RECIPE", src),
        ("RVA_CUBE_TRIGGER_CURRENT_RECIPE", src),
        ("UI_MANAGER_UI_NEW_STASH_OFFSET", src),
        ("RVA_OPEN_BOX_STATS", src),
        ("RVA_STAGE_BOX_REFRESH_AUTO_OPEN", src),
        ("RVA_AUTO_CHEST_OPEN_MOVE_NEXT", src),
        ("RVA_BOX_DATA_GET_REWARD_ITEM_ID 0x967670ULL", src),
        ("RVA_BOX_DATA_GET_REWARD_ITEM_UNIQUE_ID 0x967690ULL", src),
        ("STAGE_BOX_AUTO_OPEN_DURATION_OFFSET", src),
        ("AUTO_OPEN_BOX_SECONDS 5", src),
        ("install_open_box_stats_hook", src),
        ("install_stage_box_auto_open_hooks", src),
        ("hook_auto_chest_open_move_next", src),
        ("write_absolute_jump_with_trampoline_preserve_rax", src),
        ("duration_was_clamped", src),
        ("OVERLAY_BUTTON_EXP_MINUS", src),
        ("OVERLAY_BUTTON_CUBE_PLUS", src),
        ("OVERLAY_BUTTON_SYNTH_TOGGLE", src),
        ("OVERLAY_BUTTON_SYNTH_STORAGE", src),
        ("typedef struct OverlayLogEntry", src),
        ("g_drop_log_entries", src),
        ("g_item_log_path", src),
        ("load_item_log_history", src),
        ("persist_item_log_entry", src),
        ("append_overlay_item_event", src),
        ("draw_overlay_drop_log", src),
        ("adjust_drop_log_scroll", src),
        ("OVERLAY_LOG_BOX_TOP", src),
        ("BOX_REWARD_RESULT_WATCH_MS", src),
        ("g_box_reward_result_pending", src),
        ("maybe_handle_box_reward_add", src),
        ("begin_box_reward_result_watch", src),
        ("item_key_is_stage_box_candidate", src),
        ("Item Lock", src),
        ("auto_item_lock_catalog_copy", src),
        ("append_overlay_item_event(\"开箱\"", src),
        ("append_overlay_item_event(\"合成\"", src),
        ("box_reward_select_hook_needed", src),
        ("update_box_reward_select_hook", src),
        ("validate_runtime_versions", src),
        ("target_game_version=1.00.21", ini),
        ("plugin_version=1.00.21", ini),
        ("plugin_subversion=404", ini),
        ("exp_multiplier=", ini),
        ("cube_exp_multiplier=", ini),
        ("auto_synthesis=", ini),
        ("auto_synthesis_use_storage=", ini),
        ("auto_item_lock=", ini),
        ("item_lock_condition_high_grade=", ini),
        ("item_lock_condition_coin=", ini),
        ("item_lock_condition_market_top=", ini),
        ("auto_item_lock_ids=", ini),
        ("auto_portal_locked=", ini),
        ("auto_portal_stage_key=", ini),
        ("versions\\\\%s\\\\%s", injector),
        ("select_versioned_dll", injector),
        ("ensure_game_config", injector),
        ("TaskBarHeroSpeed.ini", injector),
        ("No plugin DLL for game version %s. Expected versions\\\\%s\\\\%s", injector),
        ("MIN_VALID_REMOTE_MODULE", injector),
        ("LoadLibraryA returned suspicious module", injector),
        ("versions.json", package_script),
        ('PLUGIN_VERSION="1.00.21.404"', package_script),
        ("versions/$VERSION/TaskBarHeroSpeed.dll", package_script),
        ("TaskBarHeroSpeedIcons", package_script),
        ("TaskBarHeroSpeedItemNames.zh-Hans.tsv", package_script),
        ("TaskBarHeroSpeedMarketTop100.tsv", package_script),
        ("TaskBarHeroSpeedMarketTop100.default.tsv", package_script),
        ("generate_market_top_lock.py", package_script),
        ("TRACKED_VERSIONS_DIR", package_script),
        ("MAX_RELEASE_GAME_VERSIONS=3", package_script),
        ("release_version_dirs", package_script),
        ("--prebuilt", package_script),
        ("package_windows.sh --prebuilt", prebuilt_script),
        ("TBH_MINGW_CC", build_script),
        ("MINGW_CC", build_script),
        ("TARGETS=\"${TBH_BUILD_TARGETS:-windows-x64}\"", build_script),
        ("build_windows_x64()", build_script),
        ("dist/build/$target", build_script),
        ("Steam Deck", dev_readme),
        ("Proton", dev_readme),
        ("Windows PE", dev_readme),
        ("Update.bat", package_script),
        ("api.github.com/repos/xxzzddxzd/TBH/releases/latest", update_bat),
        ("SCRIPT_DIR", inject_running_script),
        ("$SCRIPT_DIR/TaskBarHeroSpeedInject.exe", inject_running_script),
        ("TaskBarHeroSpeed", readme),
        ("versions\\<游戏版本>\\TaskBarHeroSpeed.dll", readme),
        ("最近 3 个游戏版本", readme),
        ("Update.bat", readme),
        ("UnityPy", icon_extractor),
        ("ItemInfoData", icon_extractor),
        ("ItemTable Shared Data", icon_extractor),
        ("ItemTable_zh-Hans", icon_extractor),
        ("export_item_names", icon_extractor),
        ("TaskBarHeroSpeedItemNames.zh-Hans.tsv", icon_extractor),
        ("item_info_rows", icon_extractor),
        ("fallback_item_name", icon_extractor),
        ("ItemName_{item_id}", icon_extractor),
        ("Stage Boss Box", icon_extractor),
        ("Act Boss Box", icon_extractor),
        ("sharedassets0.assets", icon_extractor),
        ("TRANSPARENT_KEY", icon_extractor),
        ("save_colorkey_bmp", icon_extractor),
    ]
    for needle, haystack in expectations:
        failures += require(needle in haystack, f"missing {needle}")

    failures += require(ICON_EXTRACTOR.is_file(),
                        "missing item icon extractor script")
    failures += require(MARKET_TOP_SCRIPT.is_file(),
                        "missing market top lock generator script")
    failures += require(MARKET_TOP_FILE.is_file(),
                        "missing generated market top lock TSV")
    failures += require(MARKET_TOP_DEFAULT_FILE.is_file(),
                        "missing default market top lock fallback TSV")
    if market_top_file:
        failures += require("item_id\tprice_cents\trank\tmarket_hash\tname_zh_hans" in market_top_file,
                            "market top TSV must expose item ids and price metadata")
        data_lines = [
            line for line in market_top_file.splitlines()
            if line and not line.startswith("#") and not line.startswith("item_id\t")
        ]
        failures += require(len(data_lines) >= 100,
                            "market top TSV must contain the expanded item ids for the top 100 market entries")
    if market_top_default_file:
        failures += require("item_id\tprice_cents\trank\tmarket_hash\tname_zh_hans" in market_top_default_file,
                            "default market top TSV must expose item ids and price metadata")
        default_data_lines = [
            line for line in market_top_default_file.splitlines()
            if line and not line.startswith("#") and not line.startswith("item_id\t")
        ]
        failures += require(len(default_data_lines) >= 100,
                            "default market top TSV must preserve the expanded current top 100 item ids")
    failures += require("DEFAULT_FALLBACK_OUTPUT" in market_top_script,
                        "market top generator must name the default fallback TSV")
    failures += require("copy_default_fallback" in market_top_script,
                        "market top generator must copy the default TSV when live fetch fails")
    failures += require("using default fallback" in market_top_script,
                        "market top generator must report fallback usage")
    if NAME_TABLE.exists():
        name_rows = [
            line.split("\t", 1)
            for line in NAME_TABLE.read_text(encoding="utf-8").splitlines()
            if line and not line.startswith("key\t")
        ]
        name_map = {key: value for key, value in name_rows if key and value}
        failures += require(len(name_rows) >= 5900,
                            "zh-Hans item name table must cover the full ItemInfoData item id surface")
        for key, expected in (
            ("ItemName_621011", "铜戒指"),
            ("ItemName_622011", "铜戒指"),
            ("ItemName_116001", "虚空蛋白石"),
            ("ItemName_930101", "幕 Boss 宝箱 1"),
            ("ItemName_150010", "宇宙合成材料"),
        ):
            failures += require(name_map.get(key) == expected,
                                f"zh-Hans item name table missing direct item id name {key}")
    failures += require('CreateWindowExW(0, L"STATIC", L"\\x9501\\x5B9A"' not in src,
                        "overlay item lock row title must not use the old Chinese static label")
    failures += require('DrawTextA(hdc, "Item Lock"' in src or
                        'CreateWindowExA(0, "STATIC", "Item Lock"' in src,
                        "overlay item lock row title must render as Item Lock")
    failures += require("entry.grade >= 0 ? auto_item_lock_grade_color(entry.grade)" in src,
                        "overlay drop log must color each item line by item grade")
    failures += require("draw_overlay_log_text_utf8" in src,
                        "overlay drop log must render UTF-8 Chinese through a wide-text helper")
    failures += require("DrawTextW(hdc, wide" in src,
                        "overlay drop log must use DrawTextW for Chinese item names")
    failures += require("DrawTextA(hdc, entry.line" not in src,
                        "overlay drop log must not draw UTF-8 item names with DrawTextA")
    failures += require('append_overlay_event("SYNTH' not in src,
                        "overlay must not print intermediate SYNTH action logs")
    overlay_start = src.find("static void append_overlay_event(const char *fmt, ...)\n{")
    item_start = src.find("static void append_overlay_item_event(const char *action,",
                          overlay_start + 1 if overlay_start >= 0 else 0)
    display_stage_start = src.find("static int display_stage_no_from_key(")
    failures += require(overlay_start >= 0 and item_start > overlay_start,
                        "overlay event helper missing")
    if overlay_start >= 0 and item_start > overlay_start:
        overlay_body = src[overlay_start:item_start]
        failures += require("append_overlay_log_line_with_grade" not in overlay_body,
                            "generic overlay events must not write to the item-only Drops log")
        failures += require("persist_item_log_entry" not in overlay_body,
                            "generic overlay events must not be persisted as item history")
    failures += require(item_start >= 0 and display_stage_start > item_start,
                        "overlay item event helper missing")
    if item_start >= 0 and display_stage_start > item_start:
        item_body = src[item_start:display_stage_start]
        failures += require("append_overlay_log_line_with_grade(line, grade);" in item_body,
                            "only item events should append to the Drops log")
        failures += require("persist_item_log_entry(line, grade);" in item_body,
                            "item events must be persisted to disk")
        failures += require('wsprintfA(generated_key, "ItemName_%u", item_id);' in item_body and
                            "lookup_auto_item_lock_localized_name(generated_key" in item_body,
                            "item event log must fall back to direct item id zh-Hans lookup when catalog data is unavailable")
    failures += require("TaskBarHeroSpeedItemLog.tsv" in src,
                        "item event history must have a stable TSV file")
    failures += require("load_item_log_history();" in src,
                        "plugin startup must load persisted item history")
    failures += require("case WM_MOUSEWHEEL:" in src and "adjust_drop_log_scroll" in src,
                        "Drops item log must be scrollable with the mouse wheel")
    failures += require("OVERLAY_LOG_VISIBLE_LINES" in src and
                        "OVERLAY_LOG_LINE_COUNT 128" in src,
                        "Drops item log must keep more history than the visible rows")
    for reset_event in (
        'append_overlay_event("LOCK REQUESTED',
        'append_overlay_event("UNLOCK REQUESTED',
        'append_overlay_event("LOCK FAILED',
        'append_overlay_event("LOCKED %d-%d',
        'append_overlay_event("UNLOCKED',
        'append_overlay_event("AUTO RETURN',
    ):
        failures += require(reset_event not in src,
                            f"reset overlay event must not be printed: {reset_event}")

    failures += require("RVA_NP_GET_INSTANCE" not in src,
                        "plugin must not call np<T>.gea; it can crash inside GameAssembly")
    failures += require("np_get_instance_t" not in src,
                        "plugin must not keep the np<T>.gea function pointer")
    failures += require("RVA_UI_MANAGER_SINGLETON_TYPEINFO" not in src,
                        "UIManager lookup must use static fields, not np<UIManager>.gea")
    failures += require("get_instance(" not in src,
                        "plugin must not call np<T>.gea from any runtime path")

    failures += require("alloc_executable_near" in src,
                        "trampolines must be allocated near the hooked function for RIP-relative prologues")
    failures += require("relocate_trampoline_rip_relative" in src,
                        "trampolines must relocate RIP-relative instructions copied from GameAssembly")
    failures += require("source[offset] == 0x80" in src and "source[offset + 1] == 0x3D" in src,
                        "trampoline relocation must handle cmp byte ptr [rip+disp32], imm8 prologues")
    failures += require(src.count("relocate_trampoline_rip_relative(trampoline, (unsigned char *)target, stolen_size)") >= 2,
                        "normal and preserve-rax trampolines must relocate copied RIP-relative bytes before execution")

    failures += require("#define CUBE_EXP_MULTIPLIER 10.0f" not in src,
                        "cube multiplier must be runtime configurable, not the old fixed macro")
    removed_title_bar_text = src + ini + readme + dev_readme + root_ini + dev_ini
    for removed in (
        "force_" + "game_title_bar",
        "force_" + "title_bar",
        "enforce_" + "game_title_bar",
        "resolve_unity_" + "screen_calls",
        "UnityEngine." + "Screen",
        "Unity " + "Screen windowed",
        "Unity" + "RefreshRate",
        "g_" + "screen_",
        "g_last_" + "windowed_apply_tick",
        "g_" + "windowed_logged",
        "game " + "windowed mode requested",
    ):
        failures += require(removed not in removed_title_bar_text,
                            f"removed title bar/windowed feature must not leave {removed}")
    failures += require("Versioned DLL missing" not in injector,
                        "injector must not fall back to the root DLL for unsupported game versions")
    failures += require(not (ROOT / "taskbarhero_speed" / "build_steamdeck_linux.sh").exists(),
                        "Steam Deck/Linux support must be integrated into build.sh, not a separate script")
    failures += require("build_steamdeck_linux.sh" not in dev_readme + package_script,
                        "docs and package script must not reference a separate Steam Deck build script")
    failures += require("Steam Deck / Linux hosts use the same build.sh" in dev_readme,
                        "README must document the integrated Steam Deck/Linux build path")
    failures += require("case \"$target\" in" in build_script,
                        "build.sh must dispatch all configured build targets")
    failures += require("windows-x64)" in build_script,
                        "build.sh must include the Windows x64 target used by Windows, CrossOver, and Proton")
    failures += require('"$MINGW_CC" \\' in build_script,
                        "build.sh must use the configurable MinGW compiler")
    failures += require(build_script.count("x86_64-w64-mingw32-gcc \\") == 0,
                        "build.sh must not hard-code compiler invocations")
    failures += require('MINGW_CC="${TBH_MINGW_CC:-x86_64-w64-mingw32-gcc}"' in package_script,
                        "package script must honor TBH_MINGW_CC")
    failures += require("TaskBarHeroSpeed.dll\" \"$OUT_DIR/\"" not in package_script,
                        "release package must not include a root fallback TaskBarHeroSpeed.dll")
    failures += require((PACKAGE_DIR / "start-win.bat").is_file(),
                        "Windows package entrypoint must be start-win.bat")
    failures += require((PACKAGE_DIR / "start-mac.command").is_file(),
                        "macOS package entrypoint must be start-mac.command")
    failures += require((PACKAGE_DIR / "Inject.bat").exists() is False,
                        "old Windows package entrypoint Inject.bat must be renamed")
    failures += require((PACKAGE_DIR / "Inject-CrossOver-macOS.command").exists() is False,
                        "old macOS package entrypoint Inject-CrossOver-macOS.command must be renamed")
    failures += require("taskbarhero_speed/package/start-win.bat" in package_script,
                        "release package must copy start-win.bat")
    failures += require("taskbarhero_speed/package/start-mac.command" in package_script,
                        "release package must copy start-mac.command")
    failures += require("MARKET_TOP_FILE=" in package_script,
                        "release package must name the market top lock file")
    failures += require("MARKET_TOP_SCRIPT=" in package_script,
                        "release package must name the market top generator script")
    failures += require("taskbarhero_speed/package/Inject.bat" not in package_script,
                        "release package must not copy old Inject.bat")
    failures += require("taskbarhero_speed/package/Inject-CrossOver-macOS.command" not in package_script,
                        "release package must not copy old macOS entrypoint")
    failures += require("Inject-CrossOver-macOS" not in readme + package_script,
                        "release docs and package script must not mention old macOS entrypoint")
    failures += require("Inject.bat" not in readme + package_script,
                        "release docs and package script must not mention old Windows entrypoint")
    failures += require("static char g_config_dir[MAX_PATH];" in src,
                        "plugin must keep a separate config directory")
    failures += require("lstrcpynA(g_config_dir, g_game_dir[0] ? g_game_dir : g_base_dir," in src,
                        "config directory must resolve to the game executable directory")
    failures += require(src.count('wsprintfA(path, "%s\\\\TaskBarHeroSpeed.ini", g_config_dir);') >= 2,
                        "load_config and save_config must both use g_config_dir")
    failures += require('wsprintfA(path, "%s\\\\TaskBarHeroSpeed.ini", g_base_dir);' not in src,
                        "config must not be read or saved from the injected DLL directory")
    failures += require("AutoStart-Optional" not in package_script,
                        "release package must not include AutoStart-Optional fallback DLLs")
    failures += require("AutoStart-Optional" not in install_autostart,
                        "auto-start install must not fall back to an unversioned winhttp.dll")
    failures += require("$ROOT/TaskBarHeroSpeedInject.exe" not in inject_running_script,
                        "macOS dev inject script must launch the injector beside versions/")
    failures += require("remote_result < MIN_VALID_REMOTE_MODULE" in injector,
                        "injector must reject low LoadLibraryA return values like 0x103")
    failures += require("ensure_game_config(game_dir);" in injector,
                        "injector must install a default game-directory config before injection")
    failures += require("CopyFileA(default_config, target_config, TRUE)" in injector,
                        "injector must copy the package config only when the game config is missing")

    version_match = re.search(r'#define\s+TBHS_SUPPORTED_GAME_VERSION\s+"([^"]+)"', src)
    plugin_version_match = re.search(r'#define\s+TBHS_PLUGIN_VERSION\s+"([^"]+)"', src)
    plugin_subversion_match = re.search(r'#define\s+TBHS_PLUGIN_SUBVERSION\s+"([^"]+)"', src)
    plugin_display_match = re.search(r'#define\s+TBHS_PLUGIN_DISPLAY_VERSION\s+"([^"]+)"', src)
    failures += require(bool(version_match), "supported game version macro not found")
    if version_match:
        failures += require(version_match.group(1) == "1.00.21",
                            "supported game version should be 1.00.21")
    failures += require(bool(plugin_version_match), "plugin base version macro not found")
    failures += require(bool(plugin_subversion_match), "plugin subversion macro not found")
    failures += require(bool(plugin_display_match), "plugin display version macro not found")
    if version_match and plugin_version_match:
        failures += require(plugin_version_match.group(1) == version_match.group(1),
                            "plugin base version must match the supported game version")
    if plugin_subversion_match:
        failures += require(plugin_subversion_match.group(1) == "404",
                            "plugin subversion should be 404 for this change set")
    if plugin_display_match:
        failures += require(plugin_display_match.group(1) == "1.00.21.404",
                            "plugin display version should be game version plus subversion")

    for key in ("exp_multiplier", "cube_exp_multiplier"):
        match = re.search(rf"^{key}=([0-9.]+)$", ini, re.MULTILINE)
        failures += require(bool(match), f"{key} missing from ini")
        if match:
            value = float(match.group(1))
            failures += require(1.0 <= value <= 10.0, f"{key} out of 1..10 range")

    auto_synthesis_match = re.search(r"^auto_synthesis=([01])$", ini, re.MULTILINE)
    failures += require(bool(auto_synthesis_match), "auto_synthesis missing from ini")
    storage_match = re.search(r"^auto_synthesis_use_storage=([01])$", ini, re.MULTILINE)
    failures += require(bool(storage_match), "auto_synthesis_use_storage missing from ini")
    failures += require("auto_synthesis_grade=" not in ini,
                        "auto synthesis grade should not be user configurable")
    market_top_condition_match = re.search(r"^item_lock_condition_market_top=([01])$", ini, re.MULTILINE)
    failures += require(bool(market_top_condition_match),
                        "market top lock condition missing from ini")
    if market_top_condition_match:
        failures += require(market_top_condition_match.group(1) == "1",
                            "market top lock condition should default to enabled")
    failures += require("OVERLAY_BUTTON_SYNTH_GRADE" not in src,
                        "auto synthesis grade buttons should not exist")
    failures += require('"g-"' not in src and '"g+"' not in src,
                        "auto synthesis grade +/- buttons should not be created")
    failures += require("RVA_ITEM_DATA_SINGLETON_TYPEINFO" not in src,
                        "item lock catalog must not use the old wrong item data singleton macro")
    failures += require("np<baj>" not in src,
                        "item lock catalog must not use baj; itemInfoData lives on bam")
    failures += require("ZeroMemory(" not in src,
                        "proxy DLL must use zero_memory_local instead of CRT-backed ZeroMemory")

    master_data_match = re.search(
        r"static void \*get_master_data_instance\(uintptr_t base\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(master_data_match), "master data instance helper missing")
    if master_data_match:
        body = master_data_match.group("body")
        failures += require("get_instance(" not in body,
                            "item lock catalog must not call np<bam>.gea; static singleton read is enough")
        failures += require("RVA_MASTER_DATA_SINGLETON_METHODINFO" not in body,
                            "item lock catalog must not depend on Method$np<bam>.gea()")
        failures += require("RVA_MASTER_DATA_SINGLETON_TYPEINFO" in body,
                            "master data helper must still try the np<bam> static singleton first")

    auto_synth_func_match = re.search(
        r"static void maybe_auto_synthesis_from_game_thread\(void\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(auto_synth_func_match), "auto synthesis function body missing")
    if auto_synth_func_match:
        body = auto_synth_func_match.group("body")
        clear_index = body.find("clear_current_recipe(NULL);")
        fill_index = body.find("autofill_current_recipe(current_recipe, NULL);")
        trigger_index = body.find("trigger_current_recipe(NULL);")
        failures += require(clear_index >= 0, "auto synthesis must clear current recipe before filling")
        failures += require(fill_index >= 0, "auto synthesis must auto-fill the current recipe without UI_Cube")
        failures += require(trigger_index >= 0, "auto synthesis must still trigger synthesis")
        failures += require("get_ui_cube_instance(base)" not in body,
                            "auto synthesis must not wait on UI_Cube before running")
        failures += require("UI_Cube unavailable" not in body,
                            "auto synthesis must not block on UI_Cube availability")
        failures += require("current_recipe = ensure_cube_current_recipe(base);" in body,
                            "auto synthesis must ensure the Cube synthesis recipe exists")
        failures += require("current_recipe = get_cube_current_recipe(base);" not in body,
                            "auto synthesis must not only read the Cube recipe; it must initialize it when absent")
        failures += require("autofill_current_recipe =\n            (cube_autofill_current_recipe_t)(base + RVA_CUBE_AUTOFILL_CURRENT_RECIPE);" in body,
                            "auto synthesis must call the backend current-recipe autofill dispatcher")
        failures += require("set_synthesis_type(EITEM_SYNTHESIS_GEAR, NULL);" in body,
                            "auto synthesis must still keep the Cube on gear synthesis")
        failures += require("select_recipe(" not in body,
                            "auto synthesis must let auto-fill choose the recipe instead of forcing grade")
        failures += require("g_auto_synthesis_grade" not in body,
                            "auto synthesis flow must not depend on a configured grade")
        stash_index = body.find("inventory_to_stash(ui_stash, NULL);")
        failures += require(stash_index >= 0,
                            "auto synthesis must call inventory-to-stash before filling when storage is enabled")
        if stash_index >= 0 and fill_index >= 0:
            failures += require(stash_index < fill_index,
                                "auto synthesis stash move must happen before autofill")
        if fill_index >= 0 and trigger_index >= 0:
            failures += require(fill_index < trigger_index,
                                "auto synthesis autofill must happen before trigger")
        failures += require("g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_STASH;" in body,
                            "auto synthesis must wait after clearing before stash move")
        failures += require("if (g_auto_synthesis_use_storage) {\n        g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_STASH;" in body,
                            "auto synthesis must enter stash phase after clear when storage is enabled")
        failures += require("inventory_to_stash(ui_stash, NULL);\n            log_line(\"auto synthesis stash move sent" in body,
                            "auto synthesis stash phase must execute the stash move")
        failures += require("g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_FILL;\n        g_auto_synthesis_step_tick = now + AUTO_SYNTHESIS_FILL_DELAY_MS;" in body,
                            "auto synthesis stash phase must enter wait-fill after moving to stash")
        failures += require("g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_FILL;" in body,
                            "auto synthesis must enter wait-fill phase after clearing")
        failures += require("g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER;" in body,
                            "auto synthesis must enter wait-trigger phase after autofill")
        failures += require("auto synthesis stash move sent" in body,
                            "auto synthesis must log the stash move step")
        failures += require("auto synthesis clear sent" in body,
                            "auto synthesis must log a separate clear step")
        failures += require("auto synthesis autofill sent" in body,
                            "auto synthesis must log a separate autofill step")
        failures += require("InterlockedExchange(&g_auto_synthesis_pending, 0)" in body,
                            "auto synthesis must consume a pending box-open request before starting")
        failures += require("if (!g_auto_synthesis_pending ||" in body,
                            "auto synthesis must not start without a pending box-open request")
        failures += require("clear+fill" not in body,
                            "auto synthesis must not clear and fill in the same visible step")

    core_hook_match = re.search(
        r"static DWORD WINAPI speed_thread\(LPVOID arg\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(core_hook_match), "speed thread body missing")
    if core_hook_match:
        body = core_hook_match.group("body")
        failures += require("ensure_auto_item_lock_localized_names_loaded();" in body,
                            "speed thread startup must load the complete zh-Hans item name table")
        failures += require("update_box_reward_select_hook(game_assembly);" in body,
                            "box reward select hook must be updated from core hook install")
    failures += require(re.search(r"box_reward_select_hook_needed\(void\).*?g_auto_synthesis_enabled.*?g_auto_item_lock_enabled",
                                  src,
                                  re.DOTALL) is not None,
                        "box reward select hook must be required for auto synthesis and auto item lock")
    failures += require("update_box_reward_select_hook(g_game_assembly);" in src,
                        "enabling auto synthesis at runtime must install the box reward hook")

    apply_speed_match = re.search(
        r"static void apply_speed_from_game_thread\(void\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(apply_speed_match), "apply speed loop body missing")
    if apply_speed_match:
        body = apply_speed_match.group("body")
        catalog_index = body.find("maybe_load_auto_item_lock_catalog_from_game_thread();")
        lock_index = body.find("maybe_auto_item_lock_from_game_thread();")
        manual_lock_index = body.find("manual_item_lock_from_game_thread();")
        synth_index = body.find("maybe_auto_synthesis_from_game_thread();")
        failures += require(catalog_index >= 0, "game-thread loop must load item lock catalog")
        failures += require(lock_index >= 0, "game-thread loop must process pending auto item locks")
        failures += require(manual_lock_index >= 0, "game-thread loop must process manual item lock requests")
        failures += require(synth_index >= 0, "game-thread loop must process pending auto synthesis")
        if catalog_index >= 0 and lock_index >= 0:
            failures += require(catalog_index < lock_index,
                                "item lock catalog must load before processing pending item locks")
        if lock_index >= 0 and manual_lock_index >= 0:
            failures += require(lock_index < manual_lock_index,
                                "queued auto item locks should run before manual batch locking")
        if manual_lock_index >= 0 and synth_index >= 0:
            failures += require(manual_lock_index < synth_index,
                                "manual item lock requests should run before synthesis after box open")

    catalog_loader_match = re.search(
        r"static void maybe_load_auto_item_lock_catalog_from_game_thread\(void\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(catalog_loader_match), "item lock catalog loader body missing")
    if catalog_loader_match:
        body = catalog_loader_match.group("body")
        failures += require("g_auto_item_lock_catalog_count > 0" in body,
                            "item lock catalog loader must stop after data is loaded")
        failures += require("g_auto_item_lock_enabled" not in body and "g_item_lock_list_hwnd" in body,
                            "item lock catalog loader must run only while the list window is open")

    catalog_load_match = re.search(
        r"static int load_auto_item_lock_catalog_from_game\(void\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(catalog_load_match), "item lock catalog load body missing")
    if catalog_load_match:
        body = catalog_load_match.group("body")
        failures += require("ITEM_INFO_ICON_PATH_OFFSET + sizeof(void *)" in body,
                            "item lock catalog must validate IconPath before reading it")
        failures += require("icon_path_obj = *(void **)((unsigned char *)item + ITEM_INFO_ICON_PATH_OFFSET);" in body,
                            "item lock catalog must read ItemInfoData.IconPath")
        failures += require("read_il2cpp_string_utf8(icon_path_obj, info->icon_path, sizeof(info->icon_path));" in body,
                            "item lock catalog must store IconPath as UTF-8 text")
        failures += require("auto_item_lock_make_display_name(info);" in body,
                            "item lock catalog must derive a clearer display name for rows")
        failures += require("info->equip_class = auto_item_lock_catalog_class_from_gear_type(" in body,
                            "item lock catalog must derive a class filter value from gear type data")

    item_lock_wnd_match = re.search(
        r"static LRESULT CALLBACK item_lock_list_wnd_proc\(.*?\)\s*\{(?P<body>.*?)\n\}\n\nstatic void open_item_lock_list_window",
        src,
        re.DOTALL,
    )
    failures += require(bool(item_lock_wnd_match), "item lock list window proc body missing")
    if item_lock_wnd_match:
        body = item_lock_wnd_match.group("body")
        wm_create = re.search(r"case WM_CREATE:.*?return 0;\n    \}", body, re.DOTALL)
        failures += require(bool(wm_create), "item lock list WM_CREATE body missing")
        if wm_create:
            create_body = wm_create.group(0)
            failures += require("load_auto_item_lock_catalog_from_game();" not in create_body,
                                "item lock list must not read managed item data from the UI thread")
            failures += require("SetTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH" in create_body,
                                "item lock list must poll for the game-thread loaded catalog")
            failures += require("LBS_OWNERDRAWFIXED" in create_body,
                                "item lock list rows must render as visible checkboxes")
            failures += require("LBS_EXTENDEDSEL" not in create_body,
                                "item lock list must not use old multi-select list behavior")
            failures += require("SetWindowLongPtrA(g_item_lock_listbox, GWLP_WNDPROC" in create_body,
                                "item lock list must subclass the listbox so row clicks toggle checkboxes")
            failures += require("ITEM_LOCK_LIST_CONTROL_CLEAR" in create_body,
                                "item lock list must expose a clear button")
            failures += require("ITEM_LOCK_LIST_CONTROL_CLASS" in create_body,
                                "item lock list must expose a class filter for gear rows")
            failures += require("g_item_lock_class_combo" in create_body,
                                "item lock list must create a class filter combo")
            failures += require("ITEM_LOCK_LIST_CONTROL_SEARCH" in create_body and '"EDIT"' in create_body,
                                "item lock list must create a search edit box")
            failures += require("ES_AUTOHSCROLL" in create_body,
                                "item lock search edit must be a normal single-line filter input")
        failures += require("case WM_TIMER:" in body,
                            "item lock list must handle refresh timer messages")
        failures += require("case WM_DRAWITEM:" in body,
                            "item lock list must owner-draw checkbox rows")
        failures += require("case WM_MEASUREITEM:" in body,
                            "item lock list must set a stable checkbox row height")
        failures += require("refresh_item_lock_list_if_catalog_changed(hwnd);" in body,
                            "item lock list timer must refresh after catalog changes")
        failures += require("KillTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH);" in body,
                            "item lock list must stop the refresh timer on close")
        failures += require("clear_item_lock_temp_selection();" in body,
                            "item lock list must clear temporary selected IDs from the Clear button")
        failures += require("LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_CLASS" in body,
                            "item lock list must refresh when the class filter changes")
        failures += require("LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_SEARCH" in body and "EN_CHANGE" in body,
                            "item lock list must refresh when the search filter changes")

    listbox_proc_match = re.search(
        r"static LRESULT CALLBACK item_lock_listbox_proc\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(listbox_proc_match), "item lock checkbox listbox proc missing")
    if listbox_proc_match:
        body = listbox_proc_match.group("body")
        failures += require("LB_ITEMFROMPOINT" in body and "item_lock_toggle_row" in body,
                            "item lock checkbox listbox must toggle rows on mouse click")
        failures += require("VK_SPACE" in body and "LB_GETCURSEL" in body,
                            "item lock checkbox listbox must toggle rows from keyboard")

    item_lock_filter_match = re.search(
        r"static int item_lock_catalog_matches_filter\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(item_lock_filter_match), "item lock filter body missing")
    if item_lock_filter_match:
        body = item_lock_filter_match.group("body")
        failures += require("item_lock_catalog_selectable(info)" in body,
                            "item lock list must use the selectable material/gear range")
        failures += require("if (!item_lock_catalog_selectable(info)) return 0;" in body,
                            "selectable range must be mandatory before UI filters")
        failures += require("info->equip_class" in body and "class_filter" in body,
                            "item lock list must apply the gear class filter")
        failures += require("item_lock_catalog_matches_search(info)" in body,
                            "item lock list must apply the text search filter")

    grade_combo_match = re.search(
        r"static void init_item_lock_filter_combo\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(grade_combo_match), "item lock grade combo body missing")
    if grade_combo_match:
        body = grade_combo_match.group("body")
        failures += require("for (i = 0; i <= EGRADE_NONE; ++i)" in body,
                            "item lock grade combo must expose all rarity grades for all-material locking")
        failures += require("for (i = EGRADE_DIVINE; i <= EGRADE_COSMIC; ++i)" not in body,
                            "item lock grade combo must no longer be limited to the two highest rarity grades")
        failures += require("item_lock_combo_add_utf8(combo" in body,
                            "item lock filter combos must add UTF-8 labels through the wide Win32 API")

    item_lock_search_match = re.search(
        r"static int item_lock_catalog_matches_search\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(item_lock_search_match), "item lock search filter helper missing")
    if item_lock_search_match:
        body = item_lock_search_match.group("body")
        failures += require("GetWindowTextW(g_item_lock_search_edit" in body,
                            "item lock search must read Unicode text from the edit box")
        failures += require("MultiByteToWideChar(CP_UTF8" in body,
                            "item lock search must compare UTF-8 item names as Unicode")
        failures += require("wsprintfW(id_text, L\"%u\", info->item_id)" in body,
                            "item lock search must support filtering by item id")

    manual_lock_match = re.search(
        r"static void manual_item_lock_from_game_thread\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(manual_lock_match), "manual item lock game-thread body missing")
    if manual_lock_match:
        body = manual_lock_match.group("body")
        failures += require("manual_item_lock_scan_item_cache_dictionary(\"manual item cache\", &stats);" in body,
                            "manual item lock must scan the global uz.uc item cache dictionary")
        failures += require("inventory=%p stash=%p cache_dict=%p" in body,
                            "manual item lock log must report whether the global cache dictionary was available")

    item_cache_dict_match = re.search(
        r"static void manual_item_lock_scan_item_cache_dictionary\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(item_cache_dict_match), "manual item cache dictionary scanner missing")
    if item_cache_dict_match:
        body = item_cache_dict_match.group("body")
        failures += require("RVA_ITEM_CACHE_STORE_TYPEINFO" in body,
                            "manual item cache scanner must use uz.uc_TypeInfo")
        failures += require("IL2CPP_DICT_U64_OBJECT_ENTRY_VALUE_OFFSET" in body,
                            "manual item cache scanner must read item cache values from dictionary entries")
        failures += require("manual_item_lock_cache_if_match(item_cache, source, stats);" in body,
                            "manual item cache scanner must reuse the normal item condition and lock path")

    box_reward_func_match = re.search(
        r"static __int64 __fastcall hook_box_reward_select\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(box_reward_func_match), "box reward select hook body missing")
    if box_reward_func_match:
        body = box_reward_func_match.group("body")
        failures += require("request_auto_synthesis_after_box_open(item_key, selected_item);" in body,
                            "box reward select must request auto synthesis after a box opens")
        watch_index = body.find("begin_box_reward_result_watch(item_key, 0);")
        select_index = body.find("result = g_real_box_reward_select(box_table, item_key, context);")
        failures += require(watch_index >= 0,
                            "box reward select must watch the actual reward_add result after a box opens")
        if watch_index >= 0 and select_index >= 0:
            failures += require(watch_index < select_index,
                                "box reward add watch must start before the real box reward select call")
        failures += require("selected_item = *(unsigned int *)((unsigned char *)result + 0x54);" in body,
                            "box reward select must still read the box item id")
        failures += require("read_boxdata_reward_fields((void *)result, &reward_item_id, reward_unique_key, sizeof(reward_unique_key));" in body,
                            "box reward select must read BoxData reward values through property getters")
        failures += require("reward_item_id = *(unsigned int *)((unsigned char *)result + 0x68);" not in body,
                            "box reward select must not read obscured BoxData.rewardItemId directly")
        failures += require("handle_box_reward_select_item(item_key, reward_item_id, reward_unique_key);" in body,
                            "box reward select must print and lock the BoxData.rewardItemId directly")
        failures += require("item_key < 1000000" in body,
                            "box reward select tracing must include all 9xxxxx stage box candidates")

    give_reward_func_match = re.search(
        r"static __int64 __fastcall hook_give_reward_item\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(give_reward_func_match), "give reward hook body missing")
    if give_reward_func_match:
        body = give_reward_func_match.group("body")
        failures += require('maybe_request_auto_synthesis_from_reward_item(item_key, "give_reward");' in body,
                            "give reward hook must request synthesis when a box item is processed")

    reward_add_func_match = re.search(
        r"static __int64 __fastcall hook_reward_add_item\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(reward_add_func_match), "reward add hook body missing")
    if reward_add_func_match:
        body = reward_add_func_match.group("body")
        failures += require("box_pending_before = g_box_reward_result_pending ? 1 : 0;" in body,
                            "reward add hook must remember whether the item belongs to an open-box result before handlers consume the watch")
        failures += require("synth_pending_before = g_auto_synthesis_result_pending ? 1 : 0;" in body,
                            "reward add hook must remember whether the item belongs to an auto-synthesis result before handlers consume the watch")
        failures += require("maybe_handle_box_reward_add(item_key, low, high);" in body,
                            "reward add hook must print and lock the actual item added after opening a box")
        failures += require("maybe_handle_manual_synthesis_reward_add(item_key, low, high, box_pending_before, synth_pending_before);" in body,
                            "reward add hook must print manually triggered Cube synthesis results")
        failures += require('maybe_request_auto_synthesis_from_reward_item(item_key, "reward_add");' in body,
                            "reward add hook must request synthesis when a box item is processed")

    synthesis_reward_start = src.find(
        "static void maybe_handle_auto_synthesis_reward_add(unsigned int item_id,\n"
        "                                                   unsigned int result_low,\n"
        "                                                   unsigned int result_high)\n{"
    )
    synthesis_reward_end = src.find("static void reset_actboss_cache_watch(void)",
                                    synthesis_reward_start + 1
                                    if synthesis_reward_start >= 0 else 0)
    failures += require(synthesis_reward_start >= 0 and
                        synthesis_reward_end > synthesis_reward_start,
                        "auto synthesis result watcher missing")
    if synthesis_reward_start >= 0 and synthesis_reward_end > synthesis_reward_start:
        body = src[synthesis_reward_start:synthesis_reward_end]
        failures += require("if (item_key_is_stage_box_candidate(item_id)) return;" in body,
                            "auto synthesis result watcher must not log stage boxes as synthesized items")

    manual_synthesis_match = re.search(
        r"static void maybe_handle_manual_synthesis_reward_add\(unsigned int item_id,\s*"
        r"unsigned int result_low,\s*unsigned int result_high,\s*"
        r"int box_pending_before,\s*int synth_pending_before\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(manual_synthesis_match), "manual Cube synthesis reward helper missing")
    if manual_synthesis_match:
        body = manual_synthesis_match.group("body")
        failures += require("if (box_pending_before || synth_pending_before) return;" in body,
                            "manual synthesis helper must not double-log open-box or auto-synthesis rewards")
        failures += require("if (!g_cached_ui_cube) return;" in body,
                            "manual synthesis helper must require the Cube UI context")
        failures += require("g_drop_observation.active" in body,
                            "manual synthesis helper must not log monster drops")
        failures += require("item_key_is_stage_box_candidate(item_id)" in body,
                            "manual synthesis helper must not log stage boxes as synthesized items")
        failures += require("auto_item_lock_catalog_lookup(item_id," in body,
                            "manual synthesis helper must resolve grade/type for log coloring and lock conditions")
        failures += require("item_type != EITEM_TYPE_GEAR && item_type != EITEM_TYPE_MATERIAL" in body,
                            "manual synthesis helper must only log synthesized gear/material results")
        failures += require('append_overlay_item_event("合成", item_id, locked);' in body,
                            "manual synthesis helper must append the synthesized item log")

    reward_fallback_match = re.search(
        r"static void maybe_request_auto_synthesis_from_reward_item\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(reward_fallback_match), "reward fallback synthesis helper missing")
    if reward_fallback_match:
        body = reward_fallback_match.group("body")
        failures += require("g_drop_observation.active" in body,
                            "reward fallback must not fire for monster box drops")
        failures += require("item_key_is_stage_box_candidate(item_key)" in body,
                            "reward fallback must only fire for stage box item keys")
        failures += require("request_auto_synthesis_after_box_open(item_key, 0);" in body,
                            "reward fallback must queue the same post-box synthesis flow")

    stage_box_candidate_match = re.search(
        r"static int item_key_is_stage_box_candidate\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(stage_box_candidate_match), "stage box candidate helper missing")
    if stage_box_candidate_match:
        body = stage_box_candidate_match.group("body")
        failures += require("item_key >= 900000" in body and "item_key < 1000000" in body,
                            "stage box candidate helper must cover unknown 9xxxxx act boss/event boxes")

    begin_box_watch_match = re.search(
        r"static void begin_box_reward_result_watch\(unsigned int box_item_key,\s*"
        r"unsigned int expected_item_id\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(begin_box_watch_match), "box reward result watch helper missing")
    if begin_box_watch_match:
        body = begin_box_watch_match.group("body")
        failures += require("item_key_is_stage_box_candidate(box_item_key)" in body,
                            "box reward result watch must start for unknown 9xxxxx stage box candidates")

    failures += require("ACTBOSS_CACHE_WATCH_MS" in src,
                        "act boss async server rewards need a short item cache watch")
    failures += require("ACTBOSS_BOX_ITEM_KEY 930801" in src,
                        "act boss cache watch must use the known act boss box item key for synthesis flow")
    failures += require("IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET 8" in src,
                        "item cache dictionary scanner must read ulong entry keys")
    actboss_watch_match = re.search(
        r"static void maybe_handle_actboss_cache_watch_from_game_thread\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(actboss_watch_match), "act boss item cache watch game-thread helper missing")
    if actboss_watch_match:
        body = actboss_watch_match.group("body")
        failures += require("IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET" in body,
                            "act boss cache watch must dedupe by the item cache dictionary unique id key")
        failures += require("auto_item_lock_apply_cache_now(item_cache, item_id, \"actboss cache watch\"" in body,
                            "act boss cache watch must lock matched new items immediately on the game thread")
        failures += require('append_overlay_item_event("开箱", item_id, locked);' in body,
                            "act boss cache watch must print new server rewards as open-box item logs")
        failures += require("request_auto_synthesis_after_box_open(ACTBOSS_BOX_ITEM_KEY, ACTBOSS_BOX_ITEM_KEY);" in body,
                            "act boss cache watch must connect server rewards to the post-box synthesis flow")

    auto_chest_match = re.search(
        r"static __int64 __fastcall hook_auto_chest_open_move_next\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(auto_chest_match), "auto chest timer hook body missing")
    if auto_chest_match:
        body = auto_chest_match.group("body")
        failures += require('begin_actboss_cache_watch_from_stage_box(stage_box, "timer");' in body,
                            "act boss auto-open timer must start the item cache watch before the server reward lands")

    apply_speed_match = re.search(
        r"static void apply_speed_from_game_thread\(.*?\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(apply_speed_match), "game-thread periodic hook body missing")
    if apply_speed_match:
        body = apply_speed_match.group("body")
        failures += require("maybe_handle_actboss_cache_watch_from_game_thread();" in body,
                            "act boss cache watch must be polled from the game thread")

    for version in ("1.00.19", "1.00.20", "1.00.21"):
        failures += require((VERSIONS_DIR / version / "TaskBarHeroSpeed.dll").is_file(),
                            f"missing tracked TaskBarHeroSpeed.dll for {version}")
        failures += require((VERSIONS_DIR / version / "winhttp.dll").is_file(),
                            f"missing tracked winhttp.dll for {version}")
    failures += require((ROOT / "taskbarhero_speed" / "TaskBarHeroSpeedInject.exe").is_file(),
                        "missing tracked injector exe")

    return failures


if __name__ == "__main__":
    sys.exit(main())
