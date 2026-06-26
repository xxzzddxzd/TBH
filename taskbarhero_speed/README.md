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
- Unity `Screen` windowed mode so CrossOver/macOS can show a draggable native title bar
- ordinary experience and cube experience multipliers, both configurable from 1x to 10x
- a draggable overlay split into Speed, Exp, Boss, Reset, and Drops rows
- `auto:on/off` switching between normal and direct-boss flow from chest countdowns
- normal and boss chest drop counts and interval tracking, persisted in `TaskBarHeroChestStats.txt`
- runtime version validation against `Version.txt`, `target_game_version`, and plugin version fields

Configuration is read from `TaskBarHeroSpeed.ini` in the game directory.
Overlay changes are persisted back to `TaskBarHeroSpeed.ini`.
Logs are written to `TaskBarHeroSpeed.log`.

For game updates, use `UPDATE_WORKFLOW.md` and `update_rvas.py` to regenerate
the app-specific RVAs before rebuilding.

Build and archive under `dll/<game-version>/`:

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/build.sh
```

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
