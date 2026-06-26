@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch - AutoStart install
echo.
echo 1. Start TaskBarHero first and keep it running.
echo 2. This installer will find the running TaskBarHero.exe folder.
echo 3. It will copy winhttp.dll and TaskBarHeroSpeed.ini there.
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$ErrorActionPreference='Stop';" ^
  "$p = Get-CimInstance Win32_Process -Filter \"name='TaskBarHero.exe'\" | Select-Object -First 1;" ^
  "if (-not $p -or -not $p.ExecutablePath) { Write-Host 'TaskBarHero.exe process not found. Start the game first.'; exit 2 }" ^
  "$gameDir = Split-Path -Parent $p.ExecutablePath;" ^
  "$src = (Get-Location).Path;" ^
  "Write-Host ('Game folder: ' + $gameDir);" ^
  "Copy-Item -Force (Join-Path $src 'AutoStart-Optional\winhttp.dll') (Join-Path $gameDir 'winhttp.dll');" ^
  "Copy-Item -Force (Join-Path $src 'TaskBarHeroSpeed.ini') (Join-Path $gameDir 'TaskBarHeroSpeed.ini');" ^
  "Set-Content -Encoding ASCII -Path (Join-Path $src 'TaskBarHeroSpeedInstallPath.txt') -Value $gameDir;" ^
  "Write-Host 'Installed. Restart TaskBarHero to load automatically.'"

echo.
if errorlevel 1 (
  echo Install failed. If the game is under Program Files, right-click this BAT and choose "Run as administrator".
) else (
  echo AutoStart installed. Close and restart TaskBarHero.
)
echo.
pause
