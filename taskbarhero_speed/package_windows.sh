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
mkdir -p "$OUT_DIR/versions"

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

FIRST_VERSION=1
{
  printf '{\n'
  printf '  "plugin_version": "0.4.0.2",\n'
  printf '  "versions": {\n'
  for VERSION_DIR in "$ROOT"/dll/*; do
    [ -d "$VERSION_DIR" ] || continue
    VERSION="$(basename "$VERSION_DIR")"
    DLL_SRC="$VERSION_DIR/TaskBarHeroSpeed_latest.dll"
    WINHTTP_SRC="$VERSION_DIR/winhttp_latest.dll"
    [ -f "$DLL_SRC" ] || continue
    [ -f "$WINHTTP_SRC" ] || continue
    mkdir -p "$OUT_DIR/versions/$VERSION"
    cp "$DLL_SRC" "$OUT_DIR/versions/$VERSION/TaskBarHeroSpeed.dll"
    cp "$WINHTTP_SRC" "$OUT_DIR/versions/$VERSION/winhttp.dll"
    if [ "$FIRST_VERSION" -eq 0 ]; then
      printf ',\n'
    fi
    FIRST_VERSION=0
    printf '    "%s": {"TaskBarHeroSpeed.dll": "versions/%s/TaskBarHeroSpeed.dll", "winhttp.dll": "versions/%s/winhttp.dll"}' "$VERSION" "$VERSION" "$VERSION"
  done
  printf '\n'
  printf '  }\n'
  printf '}\n'
} > "$OUT_DIR/versions.json"

cd "$ROOT/dist"
zip -r "$ZIP_PATH" "$PKG_NAME"

echo "package: $ZIP_PATH"
