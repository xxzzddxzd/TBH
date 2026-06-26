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
MAX_RELEASE_GAME_VERSIONS=3

if [ -n "${TBH_MAX_RELEASE_GAME_VERSIONS:-}" ]; then
  MAX_RELEASE_GAME_VERSIONS="$TBH_MAX_RELEASE_GAME_VERSIONS"
fi

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

release_version_dirs() {
  (
    cd "$TRACKED_VERSIONS_DIR"
    for VERSION in *; do
      [ -d "$VERSION" ] || continue
      [ -f "$VERSION/TaskBarHeroSpeed.dll" ] || continue
      [ -f "$VERSION/winhttp.dll" ] || continue
      printf '%s\n' "$VERSION"
    done | sort -t. -k1,1n -k2,2n -k3,3n | tail -n "$MAX_RELEASE_GAME_VERSIONS"
  )
}

RELEASE_VERSIONS="$(release_version_dirs)"
if [ -z "$RELEASE_VERSIONS" ]; then
  echo "missing tracked plugin binaries under $TRACKED_VERSIONS_DIR" >&2
  exit 1
fi

rm -rf "$OUT_DIR" "$ZIP_PATH"
mkdir -p "$OUT_DIR/versions"

if [ "$PREBUILT_ONLY" -eq 0 ] && [ -f TaskBarHeroSpeedInject.exe ]; then
  cp TaskBarHeroSpeedInject.exe "$OUT_DIR/"
else
  cp "$ROOT/taskbarhero_speed/TaskBarHeroSpeedInject.exe" "$OUT_DIR/"
fi
cp "$PACKAGE_INI" "$OUT_DIR/TaskBarHeroSpeed.ini"
cp taskbarhero_speed/package/Inject.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Update.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Inject-CrossOver-macOS.command "$OUT_DIR/"
cp taskbarhero_speed/package/Install-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/Uninstall-AutoStart.bat "$OUT_DIR/"
cp taskbarhero_speed/package/README.txt "$OUT_DIR/"
cp taskbarhero_speed/package/README_AutoStart_Optional.txt "$OUT_DIR/"
chmod +x "$OUT_DIR/Inject-CrossOver-macOS.command"

FIRST_VERSION=1
{
  printf '{\n'
  printf '  "plugin_version": "%s",\n' "$PLUGIN_VERSION"
  printf '  "versions": {\n'
  for VERSION in $RELEASE_VERSIONS; do
    VERSION_DIR="$TRACKED_VERSIONS_DIR/$VERSION"
    DLL_SRC="$VERSION_DIR/TaskBarHeroSpeed.dll"
    WINHTTP_SRC="$VERSION_DIR/winhttp.dll"
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
