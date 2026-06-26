#!/bin/sh
set -eu

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PKG_NAME="TaskBarHeroSpeedPatch-Windows"
OUT_DIR="$ROOT/dist/$PKG_NAME"
ZIP_PATH="$ROOT/dist/$PKG_NAME.zip"
TRACKED_VERSIONS_DIR="$ROOT/taskbarhero_speed/versions"
PACKAGE_INI="$ROOT/taskbarhero_speed/package/TaskBarHeroSpeed.ini"
PLUGIN_VERSION="0.4.0.2"
PREBUILT_ONLY=0

if [ "${1:-}" = "--prebuilt" ] || [ "${TBH_PREBUILT_ONLY:-0}" = "1" ] || [ "${TBH_SKIP_BUILD:-0}" = "1" ]; then
  PREBUILT_ONLY=1
fi

cd "$ROOT"
GAME_VERSION="${TBH_GAME_VERSION:-}"
if [ -z "$GAME_VERSION" ] && [ -f "$ROOT/Version.txt" ]; then
  GAME_VERSION="$(sed -n '1p' "$ROOT/Version.txt" | tr -d '\r')"
fi

if [ "$PREBUILT_ONLY" -eq 1 ]; then
  echo "packaging tracked plugin binaries without compiling"
elif command -v x86_64-w64-mingw32-gcc >/dev/null 2>&1; then
  sh taskbarhero_speed/build.sh
  if [ -n "$GAME_VERSION" ]; then
    mkdir -p "$TRACKED_VERSIONS_DIR/$GAME_VERSION"
    cp TaskBarHeroSpeed.dll "$TRACKED_VERSIONS_DIR/$GAME_VERSION/TaskBarHeroSpeed.dll"
    cp winhttp.dll "$TRACKED_VERSIONS_DIR/$GAME_VERSION/winhttp.dll"
  fi
  cp TaskBarHeroSpeedInject.exe "$ROOT/taskbarhero_speed/TaskBarHeroSpeedInject.exe"
else
  echo "x86_64-w64-mingw32-gcc not found; packaging tracked plugin binaries"
fi

if [ -z "$GAME_VERSION" ]; then
  echo "missing game version; set TBH_GAME_VERSION or create Version.txt" >&2
  exit 1
fi

TRACKED_DLL="$TRACKED_VERSIONS_DIR/$GAME_VERSION/TaskBarHeroSpeed.dll"
TRACKED_WINHTTP="$TRACKED_VERSIONS_DIR/$GAME_VERSION/winhttp.dll"
if [ ! -f "$TRACKED_DLL" ] || [ ! -f "$TRACKED_WINHTTP" ]; then
  echo "missing tracked plugin binaries for game version $GAME_VERSION" >&2
  exit 1
fi

rm -rf "$OUT_DIR" "$ZIP_PATH"
mkdir -p "$OUT_DIR/AutoStart-Optional"
mkdir -p "$OUT_DIR/versions"

if [ "$PREBUILT_ONLY" -eq 0 ] && [ -f TaskBarHeroSpeed.dll ]; then
  cp TaskBarHeroSpeed.dll "$OUT_DIR/"
else
  cp "$TRACKED_DLL" "$OUT_DIR/"
fi
if [ "$PREBUILT_ONLY" -eq 0 ] && [ -f TaskBarHeroSpeedInject.exe ]; then
  cp TaskBarHeroSpeedInject.exe "$OUT_DIR/"
else
  cp "$ROOT/taskbarhero_speed/TaskBarHeroSpeedInject.exe" "$OUT_DIR/"
fi
cp "$PACKAGE_INI" "$OUT_DIR/TaskBarHeroSpeed.ini"
cp taskbarhero_speed/package/Inject.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Inject-CrossOver-macOS.command "$OUT_DIR/"
cp taskbarhero_speed/package/Install-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Uninstall-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/README.txt "$OUT_DIR/"
cp taskbarhero_speed/package/README_AutoStart_Optional.txt "$OUT_DIR/"
if [ "$PREBUILT_ONLY" -eq 0 ] && [ -f winhttp.dll ]; then
  cp winhttp.dll "$OUT_DIR/AutoStart-Optional/"
else
  cp "$TRACKED_WINHTTP" "$OUT_DIR/AutoStart-Optional/"
fi
chmod +x "$OUT_DIR/Inject-CrossOver-macOS.command"

FIRST_VERSION=1
{
  printf '{\n'
  printf '  "plugin_version": "%s",\n' "$PLUGIN_VERSION"
  printf '  "versions": {\n'
  for VERSION_DIR in "$TRACKED_VERSIONS_DIR"/*; do
    [ -d "$VERSION_DIR" ] || continue
    VERSION="$(basename "$VERSION_DIR")"
    DLL_SRC="$VERSION_DIR/TaskBarHeroSpeed.dll"
    WINHTTP_SRC="$VERSION_DIR/winhttp.dll"
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
