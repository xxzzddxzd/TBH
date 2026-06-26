@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch
echo.
echo 1. Make sure TaskBarHero is already running.
echo 2. This will inject TaskBarHeroSpeed.dll into TaskBarHero.exe.
echo.
set LIVE_DLL=TaskBarHeroSpeedLive_%RANDOM%%RANDOM%.dll
copy /Y "TaskBarHeroSpeed.dll" "%LIVE_DLL%" >nul
TaskBarHeroSpeedInject.exe "%~dp0%LIVE_DLL%"
echo.
echo If you see "Injected ... into TaskBarHero.exe", it succeeded.
echo If it says "Process not found", start the game first.
echo.
pause
