#!/bin/sh
set -eu

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

exec sh taskbarhero_speed/package_windows.sh --prebuilt
