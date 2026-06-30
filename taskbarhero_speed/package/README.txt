TaskBarHero Speed Patch for Windows
===================================

最简单用法:

1. 解压整个文件夹到任意位置。
2. 先启动 TaskBarHero，并保持游戏正在运行。
3. 双击 start-win.bat。
4. 看到类似下面这行就是成功:

   Injected ... TaskBarHeroSpeed.dll into TaskBarHero.exe

正式 Release 包只包含最近 3 个游戏版本的 DLL。
start-win.bat 会自动查找正在运行的 TaskBarHero.exe，读取游戏 Version.txt，并注入 versions\<游戏版本>\TaskBarHeroSpeed.dll。
如果当前游戏版本不在 versions 目录里，请运行 Update.bat 更新补丁包，或去 GitHub Releases 下载最新版 ZIP。

这种方式不需要知道游戏安装目录。
配置统一读写 TaskBarHero.exe 所在目录的 TaskBarHeroSpeed.ini。
首次热注入时，如果游戏目录还没有这个文件，会从补丁包里复制一份默认配置过去。

默认速度是 5 倍。注入成功后，游戏窗口上会出现一个小悬浮框:

  TaskBarHero game:1.00.21 plugin:1.00.21.412
  Speed [min -5 -1  5  +1 +5 max]
  Exp   [exp- x1 exp+] [cube- x10 cube+]
  Boss  [boss:off] [actboss:off] [auto:off]
  Reset [-30s -10s 60s(--s) +10s +30s] [lock]
  Drops N count 0 last -- best --/-- next --
        B count 0 last -- best --/-- next --

Speed 行调整速度，范围 1 到 30。
Exp 行调整普通经验和魔方经验倍数，范围 1 到 10。exp 是普通经验，cube 是魔方经验。
Boss 行 boss:on/off 是直打 Boss 开关，默认关闭。
actboss:on/off 会把普通关最终 Boss 怪物替换成当前章节的 ACTBOSS 怪物，掉落仍走普通关 Boss 箱路径。
auto:on 是自动切换模式，默认关闭。打开 auto 时会记录当前 boss:on/off 作为主流程。
如果主流程是 boss:on，普通箱 next 到 ready 后会临时切到 boss:off 打小怪；打到普通箱后切回 boss:on。
如果主流程是 boss:off，Boss 箱 next 到 ready 后会临时切到 boss:on；打到 Boss 箱后切回 boss:off。
等待普通箱时按钮显示 auto:N，等待 Boss 箱时显示 auto:B。
lock 会把当前关卡设为锁定目标，按钮会变成 unlock。
unlock 会解除锁定，方便正常推进关卡。
Reset 行 -30s/-10s/+10s/+30s 会调整 lock 自动回关间隔。
60s(--s) 中前一个数是设置间隔，括号里是距离下次自动回关还差多少秒；未锁定时显示 --s。
Drops 行显示宝箱计数和间隔统计：N 是普通宝箱，B 是 Boss 宝箱。
count 是当前记录的累计掉落次数。
last 是同类宝箱最近两次成功掉落的间隔，best 是已记录的最短两个同类间隔。
next 是按同类 best 的最短间隔预测的下一次掉落倒计时；到时间后显示 ready。
统计会保存到 TaskBarHeroChestStats.txt，重开游戏后继续使用。
按住悬浮框空白区域可以拖动位置。
面板里改过的速度、经验倍数、boss/actboss/auto、lock 间隔、lock 目标关卡和悬浮框位置会自动保存到游戏目录的 TaskBarHeroSpeed.ini，下次启动自动读取。

未锁定时不会自动重进或推进。


修改速度:

打开 TaskBarHero.exe 所在目录的 TaskBarHeroSpeed.ini，改这一行:

  speed=5.0

每次点击加减的幅度:

  speed_step=1.0

速度范围:

  speed_min=1.0
  speed_max=30.0

普通经验和魔方经验倍数:

  exp_multiplier=1.0
  cube_exp_multiplier=10.0

悬浮框开关和位置:

  overlay=1
  overlay_x=20
  overlay_y=80

例如 2 倍:

  speed=2.0

锁定当前关卡:

  auto_portal=1
  auto_portal_interval_ms=60000

记录普通宝箱和 Boss 宝箱掉落间隔:

  drop_hooks=1

统计文件:

  TaskBarHero.exe 所在目录的 TaskBarHeroChestStats.txt

直打 Boss 默认值:

  direct_boss=0

普通关 Boss 替换为章节 ACTBOSS 默认值:

  actboss_boss=0

自动切换默认值:

  auto_switch=0

如果游戏里已经注入过，改完后可以直接再双击 start-win.bat。
注入器会复制一个临时 DLL 文件再注入，不需要重启游戏。


更新补丁:

双击 Update.bat 会下载 GitHub 最新 Release，覆盖当前补丁文件夹，并保留:

  TaskBarHeroSpeed.ini
  TaskBarHeroChestStats.txt
  TaskBarHeroSpeedInstallPath.txt

更新完成后，重新双击 start-win.bat 即可。

macOS / CrossOver:

如果你是在 macOS 的 CrossOver 里运行 Windows 版 TaskBarHero:

1. 解压整个文件夹到任意位置。
2. 先在 CrossOver 里启动 TaskBarHero，并保持游戏正在运行。
3. 双击 start-mac.command。

这个脚本会从 macOS 进程列表发现正在运行的 TaskBarHero.exe，再推断对应的
CrossOver bottle 和游戏目录，不依赖固定 Steam 路径。

如果自动推断 bottle 失败，可以从终端指定:

  CX_BOTTLE=Steam ./start-mac.command

如果 CrossOver 不在默认位置，可以指定:

  CROSSOVER_WINE="/path/to/CrossOver/.../wine" ./start-mac.command

卸载:

关闭游戏，删除这个补丁文件夹即可。


常见问题:

1. Process not found
   先启动 TaskBarHero，再双击 start-win.bat。

2. 注入失败或没有效果
   右键 start-win.bat，选择“以管理员身份运行”。

3. 想确认是否成功
   看 TaskBarHeroSpeed.log，里面有下面这行就是 hook 成功:

   Unity Time hooks installed ... speed=5.00

4. 游戏更新后失效
   这个补丁只适配 versions 目录里已有的游戏版本。插件启动时会读取游戏 Version.txt；版本不支持会提示更新并停止安装 hook。
   如果发布包内有 versions\<新版号>，start-win.bat 会自动选择新版号对应的插件。


可选: 自动加载方式

如果不想每次启动游戏后点 start-win.bat:

1. 先启动 TaskBarHero，并保持游戏正在运行。
2. 双击 Install-AutoStart.bat。
3. 如果复制失败，右键 Install-AutoStart.bat，选择“以管理员身份运行”。
4. 关闭并重新启动游戏，以后会自动加载补丁。

Install-AutoStart.bat 会从正在运行的 TaskBarHero.exe 自动找到游戏目录，读取 Version.txt，并复制 versions\<游戏版本>\winhttp.dll。

卸载自动加载方式:

1. 先关闭 TaskBarHero。
2. 双击 Uninstall-AutoStart.bat。
3. 如果删除失败，右键 Uninstall-AutoStart.bat，选择“以管理员身份运行”。
