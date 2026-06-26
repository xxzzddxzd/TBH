@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch - AutoStart install
echo.
echo 1. Start TaskBarHero first and keep it running.
echo 2. This installer will find the running TaskBarHero.exe folder.
echo 3. It will copy the matching winhttp.dll and preserve existing settings.
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$ErrorActionPreference='Stop';" ^
  "$p = Get-CimInstance Win32_Process -Filter \"name='TaskBarHero.exe'\" | Select-Object -First 1;" ^
  "if (-not $p -or -not $p.ExecutablePath) { Write-Host 'TaskBarHero.exe process not found. Start the game first.'; exit 2 }" ^
  "$gameDir = Split-Path -Parent $p.ExecutablePath;" ^
  "$versionPath = Join-Path $gameDir 'Version.txt';" ^
  "if (Test-Path $versionPath) { $gameVersion = (Get-Content $versionPath -TotalCount 1).Trim() } else { $gameVersion = '' }" ^
  "$src = (Get-Location).Path;" ^
  "$displayVersion = if ($gameVersion) { $gameVersion } else { 'unknown' };" ^
  "Write-Host ('Game folder: ' + $gameDir);" ^
  "Write-Host ('Game version: ' + $displayVersion);" ^
  "$versionedWinhttp = if ($gameVersion) { Join-Path $src ('versions\' + $gameVersion + '\winhttp.dll') } else { '' };" ^
  "$fallbackWinhttp = Join-Path $src 'AutoStart-Optional\winhttp.dll';" ^
  "if ($versionedWinhttp -and (Test-Path $versionedWinhttp)) { $winhttp = $versionedWinhttp } elseif (Test-Path $fallbackWinhttp) { $winhttp = $fallbackWinhttp; Write-Host 'Versioned winhttp.dll not found; using fallback.' } else { Write-Host 'No winhttp.dll found for this package.'; exit 3 }" ^
  "Copy-Item -Force $winhttp (Join-Path $gameDir 'winhttp.dll');" ^
  "$targetIni = Join-Path $gameDir 'TaskBarHeroSpeed.ini';" ^
  "if (-not (Test-Path $targetIni)) { Copy-Item -Force (Join-Path $src 'TaskBarHeroSpeed.ini') $targetIni; Write-Host 'TaskBarHeroSpeed.ini installed.' } else { Write-Host 'Existing TaskBarHeroSpeed.ini preserved.' }" ^
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
