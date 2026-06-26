#!/usr/bin/env python3
from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "taskbarhero_speed" / "winhttp_proxy.c"
INI = ROOT / "taskbarhero_speed" / "package" / "TaskBarHeroSpeed.ini"
PKG_README = ROOT / "taskbarhero_speed" / "package" / "README.txt"
INJECTOR = ROOT / "taskbarhero_speed" / "injector.c"
PACKAGE_SCRIPT = ROOT / "taskbarhero_speed" / "package_windows.sh"
PREBUILT_SCRIPT = ROOT / "taskbarhero_speed" / "package_prebuilt.sh"
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
    injector = INJECTOR.read_text(encoding="utf-8")
    package_script = PACKAGE_SCRIPT.read_text(encoding="utf-8")
    prebuilt_script = PREBUILT_SCRIPT.read_text(encoding="utf-8")
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
        ("g_auto_synthesis_grade", src),
        ("g_auto_synthesis_use_storage", src),
        ("AUTO_SYNTHESIS_STASH_DELAY_MS 3000", src),
        ("AUTO_SYNTHESIS_FILL_DELAY_MS 3000", src),
        ("AUTO_SYNTHESIS_TRIGGER_DELAY_MS 2000", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_STASH", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_FILL", src),
        ("AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER", src),
        ("install_exp_reward_calc_hook", src),
        ("install_ui_cube_hooks", src),
        ("maybe_auto_synthesis_from_game_thread", src),
        ("RVA_UI_CUBE_HML", src),
        ("RVA_UI_CUBE_AUTOFILL", src),
        ("RVA_UI_REMAKE_STASH_INVENTORY_TO_STASH", src),
        ("RVA_UI_REMAKE_STASH_INVENTORY_TO_STASH 0xA3B120ULL", src),
        ("RVA_CUBE_CLEAR_CURRENT_RECIPE", src),
        ("RVA_CUBE_SELECT_RECIPE", src),
        ("RVA_CUBE_TRIGGER_CURRENT_RECIPE", src),
        ("RVA_UI_MANAGER_SINGLETON_TYPEINFO", src),
        ("UI_MANAGER_UI_NEW_STASH_OFFSET", src),
        ("RVA_NP_GET_INSTANCE", src),
        ("np_get_instance_t", src),
        ("RVA_OPEN_BOX_STATS", src),
        ("RVA_STAGE_BOX_REFRESH_AUTO_OPEN", src),
        ("RVA_AUTO_CHEST_OPEN_MOVE_NEXT", src),
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
        ("OVERLAY_BUTTON_SYNTH_GRADE_PLUS", src),
        ("OVERLAY_BUTTON_SYNTH_STORAGE", src),
        ("validate_runtime_versions", src),
        ("target_game_version=1.00.21", ini),
        ("plugin_version=", ini),
        ("plugin_subversion=", ini),
        ("plugin_subversion=3", ini),
        ("exp_multiplier=", ini),
        ("cube_exp_multiplier=", ini),
        ("auto_synthesis=", ini),
        ("auto_synthesis_grade=", ini),
        ("auto_synthesis_use_storage=", ini),
        ("auto_portal_locked=", ini),
        ("auto_portal_stage_key=", ini),
        ("versions\\\\%s\\\\%s", injector),
        ("select_versioned_dll", injector),
        ("No plugin DLL for game version %s. Expected versions\\\\%s\\\\%s", injector),
        ("versions.json", package_script),
        ("versions/$VERSION/TaskBarHeroSpeed.dll", package_script),
        ("TRACKED_VERSIONS_DIR", package_script),
        ("MAX_RELEASE_GAME_VERSIONS=3", package_script),
        ("release_version_dirs", package_script),
        ("--prebuilt", package_script),
        ("package_windows.sh --prebuilt", prebuilt_script),
        ("Update.bat", package_script),
        ("api.github.com/repos/xxzzddxzd/TBH/releases/latest", update_bat),
        ("SCRIPT_DIR", inject_running_script),
        ("$SCRIPT_DIR/TaskBarHeroSpeedInject.exe", inject_running_script),
        ("TaskBarHeroSpeed", readme),
        ("versions\\<游戏版本>\\TaskBarHeroSpeed.dll", readme),
        ("最近 3 个游戏版本", readme),
        ("Update.bat", readme),
    ]
    for needle, haystack in expectations:
        failures += require(needle in haystack, f"missing {needle}")

    failures += require("#define CUBE_EXP_MULTIPLIER 10.0f" not in src,
                        "cube multiplier must be runtime configurable, not the old fixed macro")
    failures += require("Versioned DLL missing" not in injector,
                        "injector must not fall back to the root DLL for unsupported game versions")
    failures += require("TaskBarHeroSpeed.dll\" \"$OUT_DIR/\"" not in package_script,
                        "release package must not include a root fallback TaskBarHeroSpeed.dll")
    failures += require("AutoStart-Optional" not in package_script,
                        "release package must not include AutoStart-Optional fallback DLLs")
    failures += require("AutoStart-Optional" not in install_autostart,
                        "auto-start install must not fall back to an unversioned winhttp.dll")
    failures += require("$ROOT/TaskBarHeroSpeedInject.exe" not in inject_running_script,
                        "macOS dev inject script must launch the injector beside versions/")

    version_match = re.search(r'#define\s+TBHS_SUPPORTED_GAME_VERSION\s+"([^"]+)"', src)
    failures += require(bool(version_match), "supported game version macro not found")
    if version_match:
        failures += require(version_match.group(1) == "1.00.21",
                            "supported game version should be 1.00.21")

    for key in ("exp_multiplier", "cube_exp_multiplier"):
        match = re.search(rf"^{key}=([0-9.]+)$", ini, re.MULTILINE)
        failures += require(bool(match), f"{key} missing from ini")
        if match:
            value = float(match.group(1))
            failures += require(1.0 <= value <= 10.0, f"{key} out of 1..10 range")

    auto_synthesis_match = re.search(r"^auto_synthesis=([01])$", ini, re.MULTILINE)
    failures += require(bool(auto_synthesis_match), "auto_synthesis missing from ini")
    auto_synthesis_grade_match = re.search(r"^auto_synthesis_grade=([0-9]+)$", ini, re.MULTILINE)
    failures += require(bool(auto_synthesis_grade_match), "auto_synthesis_grade missing from ini")
    if auto_synthesis_grade_match:
        grade = int(auto_synthesis_grade_match.group(1))
        failures += require(6 <= grade <= 9, "auto_synthesis_grade out of 6..9 range")
    storage_match = re.search(r"^auto_synthesis_use_storage=([01])$", ini, re.MULTILINE)
    failures += require(bool(storage_match), "auto_synthesis_use_storage missing from ini")

    auto_synth_func_match = re.search(
        r"static void maybe_auto_synthesis_from_game_thread\(void\)\s*\{(?P<body>.*?)\n\}",
        src,
        re.DOTALL,
    )
    failures += require(bool(auto_synth_func_match), "auto synthesis function body missing")
    if auto_synth_func_match:
        body = auto_synth_func_match.group("body")
        clear_index = body.find("clear_current_recipe(NULL);")
        fill_index = body.find("autofill(ui_cube, NULL);")
        trigger_index = body.find("trigger_current_recipe(NULL);")
        failures += require(clear_index >= 0, "auto synthesis must clear current recipe before filling")
        failures += require(fill_index >= 0, "auto synthesis must auto-fill after clearing")
        failures += require(trigger_index >= 0, "auto synthesis must still trigger synthesis")
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
        failures += require("clear+fill" not in body,
                            "auto synthesis must not clear and fill in the same visible step")

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
