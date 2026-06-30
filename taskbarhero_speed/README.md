# TaskBarHero Speed Patch

This is an app-local WinHTTP proxy for this TaskBarHero build. The working
root is `/Users/xuzhengda/Documents/workspace/tbh`.

It forwards the WinHTTP APIs imported by `UnityPlayer.dll`, then hooks the
known `GameAssembly.dll` RVAs for:

- `UnityEngine.Time::get_deltaTime`
- `UnityEngine.Time::get_timeScale`
- `UnityEngine.Time::set_timeScale(System.Single)`
- `StageManager` locked-stage pullback when the game leaves the locked stage
- the stage-spawn branch used by the `boss:on/off` overlay toggle
- `StageCache::jgz()` for the `actboss:on/off` normal-stage boss monster swap
- ordinary experience and cube experience multipliers, both configurable from 1x to 10x
- a draggable overlay split into Speed, Exp, Boss, Reset, and Drops rows
- `auto:on/off` switching between normal and direct-boss flow from chest countdowns
- normal and boss chest drop counts and interval tracking, persisted in `TaskBarHeroChestStats.txt`
- runtime version validation against `Version.txt`, `target_game_version`, and plugin version fields

Configuration is read from `TaskBarHeroSpeed.ini` in the game directory.
Overlay changes are persisted back to the same game-directory file. The hot
injector copies the package default config there on first use if it is missing.
Logs are written to `TaskBarHeroSpeed.log`.

For game updates, use `UPDATE_WORKFLOW.md` and `update_rvas.py` to regenerate
the app-specific RVAs before rebuilding.

The repository intentionally carries only the latest plugin binaries per game
version under `taskbarhero_speed/versions/`. It does not carry game binaries,
metadata, or IDA databases.

Normal users should use the GitHub Release ZIP, not a git clone. The release
package contains only the latest three supported game versions under
`versions/<game-version>/`; `start-win.bat` and `Install-AutoStart.bat` both load
the DLL matching the running game's `Version.txt`. Unsupported game versions
fail with an update prompt instead of falling back to an older DLL.

Build and archive under `dll/<game-version>/`:

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/build.sh
```

Steam Deck / Linux hosts use the same build.sh path:

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/build.sh
```

The default target list is `windows-x64`, which produces Windows PE binaries
for Windows, CrossOver, and the Windows game running under Proton on Steam Deck:
`winhttp.dll`, `TaskBarHeroSpeed.dll`, and `TaskBarHeroSpeedInject.exe`.
The same files are also copied to `dist/build/windows-x64/`.

Install a MinGW-w64 cross compiler in your host environment. On Steam Deck,
prefer a writable Linux dev environment such as Distrobox; if the compiler is
not named `x86_64-w64-mingw32-gcc`, set
`TBH_MINGW_CC=/path/to/x86_64-w64-mingw32-gcc`.

Build a release folder from a plain clone without compiling:

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/package_prebuilt.sh
```

This uses the tracked `taskbarhero_speed/versions/<game-version>/` binaries
plus the tracked injector, then includes the latest three game versions in the
release folder. The equivalent explicit form is:

```sh
sh taskbarhero_speed/package_windows.sh --prebuilt
```

If you want to refresh the current `Version.txt` entry from source and have
MinGW installed, run `sh taskbarhero_speed/package_windows.sh` without
`--prebuilt`.

Enable on restart:

Place the generated `winhttp.dll` in the TaskBarHero game directory, or use the
hot-injection helper below for a running game.

Inject into an already running game:

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
TaskBarHeroSpeedInject.exe
```

The injector looks for `TaskBarHero.exe`, reads the game's `Version.txt`, then
loads `versions/<game-version>/TaskBarHeroSpeed.dll` when present. If no
versioned DLL exists it falls back to `TaskBarHeroSpeed.dll` beside the
injector for local development.

For hot reload, pass a unique copied DLL path to the injector. The bundled
scripts do this automatically because Windows will not unload the old DLL from
the running game.

From macOS/CrossOver, run:

```sh
sh taskbarhero_speed/inject_running_game.sh
```
