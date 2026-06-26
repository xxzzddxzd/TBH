#!/bin/sh
set -eu

cd "$(dirname "$0")/.."
ROOT="$(pwd)"

x86_64-w64-mingw32-gcc \
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

x86_64-w64-mingw32-gcc \
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

x86_64-w64-mingw32-gcc \
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
