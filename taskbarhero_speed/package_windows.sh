#!/bin/sh
set -eu

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PKG_NAME="TaskBarHeroSpeedPatch-Windows"
OUT_DIR="$ROOT/dist/$PKG_NAME"
ZIP_PATH="$ROOT/dist/$PKG_NAME.zip"

cd "$ROOT"
sh taskbarhero_speed/build.sh

rm -rf "$OUT_DIR" "$ZIP_PATH"
mkdir -p "$OUT_DIR/AutoStart-Optional"

cp TaskBarHeroSpeed.dll "$OUT_DIR/"
cp TaskBarHeroSpeedInject.exe "$OUT_DIR/"
cp TaskBarHeroSpeed.ini "$OUT_DIR/"
cp taskbarhero_speed/package/Inject.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Inject-CrossOver-macOS.command "$OUT_DIR/"
cp taskbarhero_speed/package/Install-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Uninstall-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/README.txt "$OUT_DIR/"
cp taskbarhero_speed/package/README_AutoStart_Optional.txt "$OUT_DIR/"
cp winhttp.dll "$OUT_DIR/AutoStart-Optional/"
chmod +x "$OUT_DIR/Inject-CrossOver-macOS.command"

cd "$ROOT/dist"
zip -r "$ZIP_PATH" "$PKG_NAME"

echo "package: $ZIP_PATH"
