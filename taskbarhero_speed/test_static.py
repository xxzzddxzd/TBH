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
        ("install_exp_reward_calc_hook", src),
        ("OVERLAY_BUTTON_EXP_MINUS", src),
        ("OVERLAY_BUTTON_CUBE_PLUS", src),
        ("validate_runtime_versions", src),
        ("target_game_version=1.00.21", ini),
        ("plugin_version=", ini),
        ("plugin_subversion=", ini),
        ("plugin_subversion=2", ini),
        ("exp_multiplier=", ini),
        ("cube_exp_multiplier=", ini),
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
