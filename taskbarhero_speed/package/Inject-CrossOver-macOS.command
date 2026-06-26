#!/bin/sh
set -u

SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"
WINE_BIN="${CROSSOVER_WINE:-/Applications/CrossOver.app/Contents/SharedSupport/CrossOver/bin/wine}"
BOTTLES_ROOT="${CROSSOVER_BOTTLES_DIR:-$HOME/Library/Application Support/CrossOver/Bottles}"
LIVE_DIR="${TASKBARHERO_LIVE_DIR:-$SCRIPT_DIR/live}"
STAMP="$(date +%Y%m%d%H%M%S)"
LIVE_DLL="$LIVE_DIR/TaskBarHeroSpeedLive_$STAMP.dll"

FOUND_PID=""
FOUND_LINE=""
FOUND_BOTTLE=""
FOUND_GAME_MAC_EXE=""
FOUND_GAME_WIN_DIR=""

pause_if_interactive() {
  if [ -t 0 ]; then
    printf '\nPress Enter to close...'
    read -r _unused || true
  fi
}

to_wine_z_path() {
  printf 'Z:%s' "$1" | sed 's#/#\\#g'
}

to_windows_dir_from_drive_c_path() {
  bottle_dir=$1
  mac_exe=$2
  mac_dir=${mac_exe%/*}
  rel=${mac_dir#"$bottle_dir/drive_c/"}
  printf 'C:\\%s' "$rel" | sed 's#/#\\#g'
}

find_taskbarhero_process() {
  FOUND_LINE=$(
    ps -axo pid=,command= 2>/dev/null |
      awk 'BEGIN{IGNORECASE=1}
           /TaskBarHero\.exe/ &&
           !/TaskBarHeroSpeedInject\.exe/ &&
           !/Inject-CrossOver-macOS/ {
             sub(/^[[:space:]]+/, "", $0);
             print;
             exit
           }'
  )
  if [ -n "$FOUND_LINE" ]; then
    FOUND_PID=${FOUND_LINE%% *}
  fi
}

extract_bottle_from_process_line() {
  if [ -z "$FOUND_LINE" ]; then
    return
  fi
  FOUND_BOTTLE=$(printf '%s\n' "$FOUND_LINE" |
    sed -n 's#.*--bottle[ =]\([^ ]*\).*#\1#p' |
    head -n 1)
  if [ -n "$FOUND_BOTTLE" ]; then
    return
  fi
  FOUND_BOTTLE=$(printf '%s\n' "$FOUND_LINE" |
    sed -n 's#.*CrossOver/Bottles/\([^/]*\)/.*#\1#p' |
    head -n 1)
}

find_game_exe_in_bottles() {
  search_root=$BOTTLES_ROOT
  if [ -n "${CX_BOTTLE:-}" ] && [ -d "$BOTTLES_ROOT/$CX_BOTTLE" ]; then
    search_root=$BOTTLES_ROOT/$CX_BOTTLE
  elif [ -n "$FOUND_BOTTLE" ] && [ -d "$BOTTLES_ROOT/$FOUND_BOTTLE" ]; then
    search_root=$BOTTLES_ROOT/$FOUND_BOTTLE
  fi

  FOUND_GAME_MAC_EXE=$(
    find "$search_root" -type f -iname 'TaskBarHero.exe' -path '*/drive_c/*' 2>/dev/null |
      head -n 1
  )

  if [ -n "$FOUND_GAME_MAC_EXE" ] && [ -z "$FOUND_BOTTLE" ]; then
    FOUND_BOTTLE=$(printf '%s\n' "$FOUND_GAME_MAC_EXE" |
      sed -n 's#.*CrossOver/Bottles/\([^/]*\)/.*#\1#p' |
      head -n 1)
  fi

  if [ -n "$FOUND_GAME_MAC_EXE" ] && [ -n "$FOUND_BOTTLE" ]; then
    bottle_dir="$BOTTLES_ROOT/$FOUND_BOTTLE"
    if [ -d "$bottle_dir/drive_c" ]; then
      FOUND_GAME_WIN_DIR=$(to_windows_dir_from_drive_c_path "$bottle_dir" "$FOUND_GAME_MAC_EXE")
    fi
  fi
}

echo "TaskBarHero speed patch - CrossOver/macOS"
echo
echo "1. Make sure TaskBarHero is already running in CrossOver."
echo "2. This will discover the running game process and inject TaskBarHeroSpeed.dll."
echo

if [ ! -x "$WINE_BIN" ]; then
  echo "CrossOver wine not found:"
  echo "  $WINE_BIN"
  echo
  echo "Set CROSSOVER_WINE to the correct wine path if CrossOver is installed elsewhere."
  pause_if_interactive
  exit 1
fi

if [ ! -f "$SCRIPT_DIR/TaskBarHeroSpeedInject.exe" ]; then
  echo "Missing TaskBarHeroSpeedInject.exe in:"
  echo "  $SCRIPT_DIR"
  pause_if_interactive
  exit 1
fi

if [ ! -f "$SCRIPT_DIR/TaskBarHeroSpeed.dll" ]; then
  echo "Missing TaskBarHeroSpeed.dll in:"
  echo "  $SCRIPT_DIR"
  pause_if_interactive
  exit 1
fi

find_taskbarhero_process
if [ -z "$FOUND_PID" ]; then
  echo "TaskBarHero.exe process not found from macOS process list."
  echo "Start the game in CrossOver first, then run this script again."
  pause_if_interactive
  exit 2
fi

extract_bottle_from_process_line
find_game_exe_in_bottles

CX_BOTTLE_EFFECTIVE="${CX_BOTTLE:-$FOUND_BOTTLE}"
GAME_WIN_DIR_EFFECTIVE="${TASKBARHERO_WIN_DIR:-$FOUND_GAME_WIN_DIR}"

if [ -z "$CX_BOTTLE_EFFECTIVE" ]; then
  echo "Found TaskBarHero.exe pid=$FOUND_PID, but could not infer the CrossOver bottle."
  echo "Run again with CX_BOTTLE set, for example:"
  echo "  CX_BOTTLE=Steam \"$0\""
  pause_if_interactive
  exit 3
fi

mkdir -p "$LIVE_DIR"
cp "$SCRIPT_DIR/TaskBarHeroSpeed.dll" "$LIVE_DLL"

if [ -f "$SCRIPT_DIR/TaskBarHeroSpeed.ini" ]; then
  cp "$SCRIPT_DIR/TaskBarHeroSpeed.ini" "$LIVE_DIR/TaskBarHeroSpeed.ini"
fi

if [ -f "$SCRIPT_DIR/TaskBarHeroChestStats.txt" ] &&
   [ ! -f "$LIVE_DIR/TaskBarHeroChestStats.txt" ]; then
  cp "$SCRIPT_DIR/TaskBarHeroChestStats.txt" "$LIVE_DIR/TaskBarHeroChestStats.txt"
fi

WIN_EXE="$(to_wine_z_path "$SCRIPT_DIR/TaskBarHeroSpeedInject.exe")"
WIN_DLL="$(to_wine_z_path "$LIVE_DLL")"

echo "Found TaskBarHero.exe pid=$FOUND_PID"
echo "CrossOver bottle: $CX_BOTTLE_EFFECTIVE"
if [ -n "$GAME_WIN_DIR_EFFECTIVE" ]; then
  echo "Game workdir: $GAME_WIN_DIR_EFFECTIVE"
else
  echo "Game workdir: not inferred; injector will still search TaskBarHero.exe inside the bottle."
fi
echo

export CX_BOTTLE="$CX_BOTTLE_EFFECTIVE"
set -- "$WINE_BIN" --bottle "$CX_BOTTLE_EFFECTIVE"
if [ -n "$GAME_WIN_DIR_EFFECTIVE" ]; then
  set -- "$@" --workdir "$GAME_WIN_DIR_EFFECTIVE"
fi
set -- "$@" --cx-app "$WIN_EXE" "$WIN_DLL"

"$@"
STATUS=$?

echo
if [ "$STATUS" -eq 0 ]; then
  echo "Done. If you saw \"Injected ... into TaskBarHero.exe\", it succeeded."
else
  echo "Inject failed with exit code $STATUS."
  echo "If the wrong bottle was inferred, run with CX_BOTTLE=<BottleName>."
fi

pause_if_interactive
exit "$STATUS"
