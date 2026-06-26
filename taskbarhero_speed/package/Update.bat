@echo off
cd /d "%~dp0"
echo TaskBarHero speed patch - update
echo.
echo This will download the latest GitHub Release and update this folder.
echo User settings and drop statistics will be preserved.
echo.

powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "$ErrorActionPreference='Stop';" ^
  "[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12;" ^
  "$root = (Get-Location).Path;" ^
  "$api = 'https://api.github.com/repos/xxzzddxzd/TBH/releases/latest';" ^
  "$temp = Join-Path ([IO.Path]::GetTempPath()) ('TBHUpdate_' + [Guid]::NewGuid().ToString('N'));" ^
  "$zip = Join-Path $temp 'TaskBarHeroSpeedPatch-Windows.zip';" ^
  "$extract = Join-Path $temp 'extract';" ^
  "$backup = Join-Path $temp 'preserve';" ^
  "New-Item -ItemType Directory -Force -Path $temp,$extract,$backup | Out-Null;" ^
  "$preserve = @('TaskBarHeroSpeed.ini','TaskBarHeroChestStats.txt','TaskBarHeroSpeedInstallPath.txt');" ^
  "foreach ($name in $preserve) { $p = Join-Path $root $name; if (Test-Path $p) { Copy-Item -Force $p (Join-Path $backup $name) } }" ^
  "Write-Host 'Checking latest release...';" ^
  "$release = Invoke-RestMethod -Uri $api -Headers @{ 'User-Agent' = 'TaskBarHeroSpeedUpdater' };" ^
  "$asset = $release.assets | Where-Object { $_.name -eq 'TaskBarHeroSpeedPatch-Windows.zip' } | Select-Object -First 1;" ^
  "if (-not $asset) { throw 'Release asset TaskBarHeroSpeedPatch-Windows.zip was not found.' }" ^
  "Write-Host ('Downloading ' + $release.tag_name + '...');" ^
  "Invoke-WebRequest -Uri $asset.browser_download_url -OutFile $zip -Headers @{ 'User-Agent' = 'TaskBarHeroSpeedUpdater' };" ^
  "Expand-Archive -Force -Path $zip -DestinationPath $extract;" ^
  "$pkg = Join-Path $extract 'TaskBarHeroSpeedPatch-Windows';" ^
  "if (-not (Test-Path $pkg)) { $pkg = (Get-ChildItem -Path $extract -Directory | Select-Object -First 1).FullName }" ^
  "if (-not $pkg -or -not (Test-Path $pkg)) { throw 'Extracted package folder was not found.' }" ^
  "$oldVersions = Join-Path $root 'versions';" ^
  "if (Test-Path $oldVersions) { Remove-Item -Recurse -Force $oldVersions }" ^
  "Copy-Item -Recurse -Force -Path (Join-Path $pkg '*') -Destination $root;" ^
  "foreach ($name in $preserve) { $p = Join-Path $backup $name; if (Test-Path $p) { Copy-Item -Force $p (Join-Path $root $name) } }" ^
  "Remove-Item -Recurse -Force $temp;" ^
  "Write-Host ('Updated to ' + $release.tag_name + '.');"

echo.
if errorlevel 1 (
  echo Update failed. Download the latest release ZIP manually if GitHub cannot be reached.
) else (
  echo Update complete.
)
echo.
pause
