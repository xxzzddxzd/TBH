#!/bin/sh
set -eu

cd "$(dirname "$0")/.."
ROOT="$(pwd)"
MINGW_CC="${TBH_MINGW_CC:-x86_64-w64-mingw32-gcc}"
TARGETS="${TBH_BUILD_TARGETS:-windows-x64}"

if ! command -v "$MINGW_CC" >/dev/null 2>&1; then
  echo "missing MinGW cross compiler: $MINGW_CC" >&2
  echo "Set TBH_MINGW_CC=/path/to/x86_64-w64-mingw32-gcc or install mingw-w64-gcc." >&2
  exit 127
fi

build_windows_x64() {
  "$MINGW_CC" \
    -shared \
    -O2 \
    -Wall \
    -Wextra \
    -Wno-cast-function-type \
    -ffreestanding \
    -fno-builtin \
    -nostdlib \
    -Wl,--entry,DllMainCRTStartup \
    -Wl,--subsystem,windows \
    -o winhttp.dll \
    taskbarhero_speed/winhttp_proxy.c \
    -lgcc \
    -lkernel32 \
    -luser32 \
    -lgdi32

  echo "built winhttp.dll"

  "$MINGW_CC" \
    -shared \
    -O2 \
    -Wall \
    -Wextra \
    -Wno-cast-function-type \
    -ffreestanding \
    -fno-builtin \
    -nostdlib \
    -DTBHS_STANDALONE_DLL \
    -Wl,--entry,DllMainCRTStartup \
    -Wl,--subsystem,windows \
    -o TaskBarHeroSpeed.dll \
    taskbarhero_speed/winhttp_proxy.c \
    -lgcc \
    -lkernel32 \
    -luser32 \
    -lgdi32

  echo "built TaskBarHeroSpeed.dll"

  "$MINGW_CC" \
    -O2 \
    -Wall \
    -Wextra \
    -Wno-cast-function-type \
    -ffreestanding \
    -fno-builtin \
    -nostdlib \
    -Wl,--entry,WinMainCRTStartup \
    -Wl,--subsystem,console \
    -o TaskBarHeroSpeedInject.exe \
    taskbarhero_speed/injector.c \
    -lgcc \
    -lkernel32 \
    -luser32

  echo "built TaskBarHeroSpeedInject.exe"
}

for target in $TARGETS; do
  case "$target" in
    windows-x64)
      echo "building target: windows-x64 (Windows PE for Windows, CrossOver, Proton, Steam Deck)"
      build_windows_x64
      TARGET_OUT_DIR="$ROOT/dist/build/$target"
      mkdir -p "$TARGET_OUT_DIR"
      cp -p winhttp.dll "$TARGET_OUT_DIR/winhttp.dll"
      cp -p TaskBarHeroSpeed.dll "$TARGET_OUT_DIR/TaskBarHeroSpeed.dll"
      cp -p TaskBarHeroSpeedInject.exe "$TARGET_OUT_DIR/TaskBarHeroSpeedInject.exe"
      echo "copied target files: dist/build/$target"
      ;;
    *)
      echo "unknown build target: $target" >&2
      exit 2
      ;;
  esac
done

STAMP="$(date +%Y%m%d%H%M%S)"
GAME_VERSION="${TBH_GAME_VERSION:-}"
if [ -z "$GAME_VERSION" ] && [ -f "$ROOT/Version.txt" ]; then
  GAME_VERSION="$(sed -n '1p' "$ROOT/Version.txt" | tr -d '\r')"
fi
if [ -z "$GAME_VERSION" ]; then
  for version_file in "$ROOT"/dll/*/Version.txt; do
    [ -f "$version_file" ] || continue
    GAME_VERSION="$(sed -n '1p' "$version_file" | tr -d '\r')"
    [ -n "$GAME_VERSION" ] && break
  done
fi
case "$GAME_VERSION" in
  ""|*[!A-Za-z0-9._-]*)
    echo "missing or invalid game version; set TBH_GAME_VERSION or create Version.txt" >&2
    exit 1
    ;;
esac
DLL_ARCHIVE_DIR="${TBH_DLL_ARCHIVE_DIR:-$ROOT/dll/$GAME_VERSION}"
mkdir -p "$DLL_ARCHIVE_DIR"
cp -p TaskBarHeroSpeed.dll "$DLL_ARCHIVE_DIR/TaskBarHeroSpeed_$STAMP.dll"
cp -p winhttp.dll "$DLL_ARCHIVE_DIR/winhttp_$STAMP.dll"
cp -p TaskBarHeroSpeed.dll "$DLL_ARCHIVE_DIR/TaskBarHeroSpeed_latest.dll"
cp -p winhttp.dll "$DLL_ARCHIVE_DIR/winhttp_latest.dll"
if [ -f "$ROOT/Version.txt" ] && [ ! -f "$DLL_ARCHIVE_DIR/Version.txt" ]; then
  cp -p "$ROOT/Version.txt" "$DLL_ARCHIVE_DIR/Version.txt"
fi
echo "archived DLLs for game $GAME_VERSION: $DLL_ARCHIVE_DIR"

PLUGIN_VERSION_DIR="$ROOT/taskbarhero_speed/versions/$GAME_VERSION"
mkdir -p "$PLUGIN_VERSION_DIR"
cp -p TaskBarHeroSpeed.dll "$PLUGIN_VERSION_DIR/TaskBarHeroSpeed.dll"
cp -p winhttp.dll "$PLUGIN_VERSION_DIR/winhttp.dll"
if [ -f "$ROOT/Version.txt" ]; then
  cp -p "$ROOT/Version.txt" "$PLUGIN_VERSION_DIR/Version.txt"
fi
echo "updated injectable DLLs: taskbarhero_speed/versions/$GAME_VERSION"
