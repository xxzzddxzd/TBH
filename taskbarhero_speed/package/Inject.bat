@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch
echo.
echo 1. Make sure TaskBarHero is already running.
echo 2. This will read the game Version.txt and inject the matching plugin.
echo.
TaskBarHeroSpeedInject.exe
echo.
echo If you see "Injected ... into TaskBarHero.exe", it succeeded.
echo If it says "Process not found", start the game first.
echo If it says "No plugin DLL for game version", use a package that supports your game version.
echo.
pause
