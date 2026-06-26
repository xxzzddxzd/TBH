#!/bin/sh
set -eu

ROOT="$(cd "$(dirname "$0")/.." && pwd)"

WINE_BIN="${CROSSOVER_WINE:-/Applications/CrossOver.app/Contents/SharedSupport/CrossOver/bin/wine}"
CX_BOTTLE="${CX_BOTTLE:-Steam}"
export CX_BOTTLE

GAME_WIN_DIR="${TASKBARHERO_WIN_DIR:-C:\\Program Files (x86)\\Steam\\steamapps\\common\\TaskbarHero}"
STAMP="$(date +%Y%m%d%H%M%S)"
LIVE_DIR="${TASKBARHERO_LIVE_DIR:-$ROOT/live}"
LIVE_DLL="$LIVE_DIR/TaskBarHeroSpeedLive_$STAMP.dll"

to_wine_z_path() {
  printf 'Z:%s' "$1" | sed 's#/#\\#g'
}

mkdir -p "$LIVE_DIR"
cp "$ROOT/TaskBarHeroSpeed.dll" "$LIVE_DLL"
if [ -f "$ROOT/TaskBarHeroSpeed.ini" ]; then
  cp "$ROOT/TaskBarHeroSpeed.ini" "$LIVE_DIR/TaskBarHeroSpeed.ini"
fi
if [ -f "$ROOT/TaskBarHeroChestStats.txt" ] && [ ! -f "$LIVE_DIR/TaskBarHeroChestStats.txt" ]; then
  cp "$ROOT/TaskBarHeroChestStats.txt" "$LIVE_DIR/TaskBarHeroChestStats.txt"
fi
WIN_EXE="$(to_wine_z_path "$ROOT/TaskBarHeroSpeedInject.exe")"
WIN_DLL="$(to_wine_z_path "$LIVE_DLL")"

exec "$WINE_BIN" --bottle "$CX_BOTTLE" --workdir "$GAME_WIN_DIR" --cx-app "$WIN_EXE" "$WIN_DLL"
