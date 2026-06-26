#!/usr/bin/env python3
from pathlib import Path
import re
import sys


ROOT = Path(__file__).resolve().parents[1]
SRC = ROOT / "taskbarhero_speed" / "winhttp_proxy.c"
INI = ROOT / "TaskBarHeroSpeed.ini"
PKG_README = ROOT / "taskbarhero_speed" / "package" / "README.txt"
INJECTOR = ROOT / "taskbarhero_speed" / "injector.c"
PACKAGE_SCRIPT = ROOT / "taskbarhero_speed" / "package_windows.sh"


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
        ("versions.json", package_script),
        ("versions/$VERSION/TaskBarHeroSpeed.dll", package_script),
        ("TaskBarHeroSpeed", readme),
        ("versions\\<游戏版本>\\TaskBarHeroSpeed.dll", readme),
    ]
    for needle, haystack in expectations:
        failures += require(needle in haystack, f"missing {needle}")

    failures += require("#define CUBE_EXP_MULTIPLIER 10.0f" not in src,
                        "cube multiplier must be runtime configurable, not the old fixed macro")

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

    return failures


if __name__ == "__main__":
    sys.exit(main())
