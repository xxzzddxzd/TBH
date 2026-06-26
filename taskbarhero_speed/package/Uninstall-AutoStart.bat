@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch - AutoStart uninstall
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$ErrorActionPreference='Stop';" ^
  "$src = (Get-Location).Path;" ^
  "$pathFile = Join-Path $src 'TaskBarHeroSpeedInstallPath.txt';" ^
  "if (Test-Path $pathFile) { $gameDir = (Get-Content $pathFile -TotalCount 1).Trim() } else { $gameDir = $null }" ^
  "if (-not $gameDir) {" ^
  "  $p = Get-CimInstance Win32_Process -Filter \"name='TaskBarHero.exe'\" | Select-Object -First 1;" ^
  "  if ($p -and $p.ExecutablePath) { $gameDir = Split-Path -Parent $p.ExecutablePath }" ^
  "}" ^
  "if (-not $gameDir) { Write-Host 'Game folder unknown. Start TaskBarHero first or reinstall from the same patch folder.'; exit 2 }" ^
  "$target = Join-Path $gameDir 'winhttp.dll';" ^
  "Write-Host ('Game folder: ' + $gameDir);" ^
  "if (Test-Path $target) { Remove-Item -Force $target; Write-Host 'Removed winhttp.dll.' } else { Write-Host 'winhttp.dll was not found.' }" ^
  "if (Test-Path $pathFile) { Remove-Item -Force $pathFile }"

echo.
if errorlevel 1 (
  echo Uninstall failed. Close TaskBarHero first, then right-click this BAT and choose "Run as administrator".
) else (
  echo AutoStart uninstalled.
)
echo.
pause
