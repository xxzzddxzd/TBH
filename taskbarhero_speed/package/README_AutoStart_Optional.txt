Optional AutoStart Mode
=======================

This mode loads the patch when the game starts.

Recommended:

1. Start TaskBarHero first and keep it running.
2. Double-click Install-AutoStart.bat.
3. Restart the game.

Install-AutoStart.bat automatically finds the running TaskBarHero.exe folder,
reads Version.txt, and copies versions\<game-version>\winhttp.dll.
If TaskBarHeroSpeed.ini already exists in the game folder, it is preserved.

Manual mode, if you know the TaskBarHero install folder:

1. Open the folder that contains TaskBarHero.exe.
2. Open Version.txt and note the game version.
3. Copy versions\<game-version>\winhttp.dll into that folder as winhttp.dll.
4. Copy TaskBarHeroSpeed.ini into that folder too, unless one already exists.
5. Start the game.

To uninstall AutoStart mode, close the game and run Uninstall-AutoStart.bat.
Manual uninstall: delete winhttp.dll from the TaskBarHero.exe folder.

For most users, Inject.bat is easier.
