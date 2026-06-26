#!/bin/sh
set -eu

ROOT="$(cd "$(dirname "$0")/.." && pwd)"

WINE_BIN="${CROSSOVER_WINE:-/Applications/CrossOver.app/Contents/SharedSupport/CrossOver/bin/wine}"
CX_BOTTLE="${CX_BOTTLE:-Steam}"
export CX_BOTTLE

GAME_WIN_DIR="${TASKBARHERO_WIN_DIR:-C:\\Program Files (x86)\\Steam\\steamapps\\common\\TaskbarHero}"

to_wine_z_path() {
  printf 'Z:%s' "$1" | sed 's#/#\\#g'
}

WIN_EXE="$(to_wine_z_path "$ROOT/TaskBarHeroSpeedInject.exe")"

exec "$WINE_BIN" --bottle "$CX_BOTTLE" --workdir "$GAME_WIN_DIR" --cx-app "$WIN_EXE"
