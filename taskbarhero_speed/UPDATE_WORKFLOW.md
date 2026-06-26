# TaskBarHero 更新适配流程

这个插件是按 `GameAssembly.dll` RVA 写死的。游戏更新后以
`/Users/xuzhengda/Documents/workspace/tbh` 为工作根目录，按游戏版本号在
`dll/<version>/` 归档游戏 DLL、metadata、IDA 数据库和对应插件 DLL。

## 1. 归档新版本游戏 DLL

在 `tbh` 目录写入当前游戏版本号，并把新版游戏文件复制到版本目录：

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
printf '%s\n' '1.00.19' > Version.txt
mkdir -p "dll/$(cat Version.txt)"
cp -p "$TASKBARHERO_GAME_DIR/GameAssembly.dll" "dll/$(cat Version.txt)/GameAssembly.dll"
cp -p "$TASKBARHERO_GAME_DIR/TaskBarHero_Data/il2cpp_data/Metadata/global-metadata.dat" "dll/$(cat Version.txt)/global-metadata.dat"
cp -p "$TASKBARHERO_GAME_DIR/Version.txt" "dll/$(cat Version.txt)/Version.txt"
```

`TASKBARHERO_GAME_DIR` 指向 Steam/CrossOver 里的游戏目录。不要把新版文件散放在
`dll/` 根目录下。

## 2. 生成 dump

用版本目录里的文件跑 Il2CppDumper：

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
mkdir -p "dll/$(cat Version.txt)/il2cpp_dump"
/Users/xuzhengda/bin/Il2CppDumper \
  "dll/$(cat Version.txt)/GameAssembly.dll" \
  "dll/$(cat Version.txt)/global-metadata.dat" \
  "dll/$(cat Version.txt)/il2cpp_dump"
```

如果 Il2CppDumper 最后停在 `Press any key` 或返回非 0，但 `dump.cs` 和
`script.json` 已生成，一般可以继续。

## 3. 自动更新 RVA

在 `tbh` 目录运行：

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
python3 taskbarhero_speed/update_rvas.py \
  --dump-dir "dll/$(cat Version.txt)/il2cpp_dump" \
  --game-assembly "dll/$(cat Version.txt)/GameAssembly.dll" \
  --apply
```

脚本会更新 `taskbarhero_speed/winhttp_proxy.c` 里的 `BEGIN/END TASKBARHERO GENERATED RVAS` 区块。
运行后必须保留并阅读脚本输出里的 `Sources`、`Notes`、`Manual checks`：

- `script.json ...`、`dump.cs signature` 表示这次从新版 dump 自动更新。
- `fallback script.json ...` 表示字节扫描没确认成功，只是按混淆名回退，必须人工确认语义。
- `preserved from current source` 或 `preserved/manual` 表示没有从新版 dump 更新，不能默认正确，必须在 IDA 里确认或手工迁移。
- 出现 `no byte-scan match` 时，不要直接热注入；先确认对应函数仍然读取正确的状态 ID。

自动抽取来源：

- `UnityEngine.Time` 的 `get_deltaTime/get_timeScale/set_timeScale` 从 `dump.cs` 抽取。
- `StageManager`、StageData TypeInfo、`AccountStatus` 等优先从 `script.json` 抽取。
- StageData TypeInfo 必须指向持有全局关卡缓存的静态类，不是 `StageCache` 内部的小列表项类。识别规则是类里同时有 `static List<StageCache>` 和 `public static StageCache`；1.00.21 为 `uz.us_TypeInfo`，字段偏移仍是 list `0x38`、current `0x88`。
- `StageCache` 不再只按混淆名迁移，必须按 `StageCache` 的 getter 顺序或构造函数字段偏移确认；1.00.21 已从 `va.*` 变成 `uz.*`：
  - `StageKey` 是 `EStageType` getter 后面的 `int` getter，不是前一个 `NextStageKey`。
  - Boss Monster Key 是 `0xE0` 字段对应 getter。
  - Boss 数据 hook 必须挂最后一个返回怪物数据对象的 getter。
- `RVA_MONSTER_DATA_BY_KEY` 必须按 StageCache boss getter 的返回类型继续找 `static <monster-data-type> <name>(int a)`，不能保留旧宏值。1.00.20 中旧 `0x91C7C0` 已变成其他实例方法，boss:on 会因把 monster key 当对象指针而崩溃；1.00.20 正确值是 `0x930370`，1.00.21 正确值是 `0x91A1A0`。
- 掉率函数会用 `GameAssembly.dll` 字节扫描做校验：普通箱必须引用状态 `4/29`，关卡 Boss 箱必须引用 `5/30`。如果普通箱命中多个候选，优先选择 `RVA_DROP_ROLL_PROCESS` 里实际 `call` 到的目标。
- `RVA_EXP_REWARD_CALC` 是普通经验倍数 hook，必须引用 `22/23/24`，返回值是基础经验加 AdditionalExp 后的结果；它不能当掉率函数 hook。
- 魔方经验入口不要写死 `va.Cube.imy(float)`，按 `Cube` 类中唯一 `static void(float)` 抽取；1.00.21 为 `uz.Cube.inj(float)`。
- 奖励入口、加物品函数和箱子选择函数按“同一个类里同时存在 `Action<int>` 奖励入口和 `AddItemResult` 加物品函数”的结构抽取后，再用 `RVA_GIVE_REWARD_ITEM` 内部实际 `call` 到的目标消歧。
- `RVA_BOX_COUNT_GET` 只是 trace-only hook；如果新版无法唯一确认旧 `csr(int)` 等价函数，应置为 `0` 并让源码跳过安装，不要保留旧地址。
- 脚本必须检查源码里所有 `RVA_*` 宏都在生成清单里；如果源码用到了未生成的宏，视为流程 bug，先补脚本再编译。

## 4. 人工确认项

脚本不能可靠自动找函数内部跳转和部分混淆后改名的方法。游戏更新后至少确认：

```c
RVA_STAGE_ENTER_EXACT_KEY
RVA_STAGECACHE_JGM
RVA_MONSTER_DATA_BY_KEY
RVA_DIRECT_BOSS_BRANCH
RVA_GIVE_REWARD_ITEM
RVA_REWARD_ADD_ITEM
RVA_BOX_REWARD_SELECT
RVA_DROP_ROLL_PROCESS
RVA_DROP_REWARD_CALLBACK
RVA_DROP_COOLDOWN_SKIP_BRANCH
RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH
RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH
```

如果第 3 步输出显示其他关键 RVA 是 `preserved from current source`，也加入本轮人工确认清单。
游戏更新后需要在 IDA 里确认它仍然是“直接进 Boss 波”的条件跳转，原始字节应是 `75`，开启后改 `EB`。
`RVA_DROP_COOLDOWN_SKIP_BRANCH` 原始字节应是 `77 55`。两个 reward item 分支原始字节应分别是
`0F 85` 和 `0F 84`。`RVA_DROP_REWARD_CALLBACK` 现在允许为 `0`，表示不再固定 delegate invoke RVA，而是在一次 active drop observation 内临时替换当前 delegate 的 invoke 并立即恢复。

确认 hook 恢复字节时不要只看 RVA，还要看 trampoline 复制的长度是否落在完整指令边界上。例如 1.00.20 的 `RVA_BOX_COUNT_GET` 前 16 字节结束在 `movsxd rbx, ecx`，第 17 字节开始是 `jne`，所以 hook 长度必须用 16，不能复制半条跳转指令。

下面三个 x-10 灵魂石地址已退役，当前代码不会使用，只保留旧宏值：

```c
RVA_ACTBOSS_SOULSTONE_BRANCH
RVA_ACTBOSS_SOULSTONE_CONSUME_BRANCH
RVA_ACTBOSS_SOULSTONE_CALLBACK_FALSE
```

## 5. 编译、归档、按需热注入

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/build.sh
```

`build.sh` 会读取 `Version.txt`，并把插件 DLL 复制到 `dll/<version>/`：

```text
TaskBarHeroSpeed_<timestamp>.dll
TaskBarHeroSpeed_latest.dll
winhttp_<timestamp>.dll
winhttp_latest.dll
```

游戏运行时再热注入：

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/inject_running_game.sh
```

成功日志至少要看到：

```text
Unity Time hooks installed
StageCache boss data hook installed
exp reward hook installed
drop rate observer hooks installed
drop roll hook installed
overlay created
```

如果看到 `Unity Time RVAs unexpected`、`drop roll hook RVA unexpected` 或
`observer RVA unexpected`，先不要继续用，重新检查对应 RVA。

## 6. 打 Windows 包

```sh
cd /Users/xuzhengda/Documents/workspace/tbh
sh taskbarhero_speed/package_windows.sh
```

输出：

```text
dist/TaskBarHeroSpeedPatch-Windows.zip
```

发布包内必须包含两个热注入入口：

- `Inject.bat`：原生 Windows 使用，自动查找正在运行的 `TaskBarHero.exe`。
- `Inject-CrossOver-macOS.command`：macOS/CrossOver 使用，先从 macOS 进程列表发现正在运行的 `TaskBarHero.exe`，再推断 CrossOver bottle 和游戏目录；不要写死本机 CrossOver/Steam 路径。

`package_windows.sh` 负责复制这两个入口到 `dist/TaskBarHeroSpeedPatch-Windows/` 并打进 zip。修改发布脚本时要重新运行本节命令确认 zip 内文件齐全。

## 关键坑

- `RVA_STAGE_MANAGER_TYPEINFO` 名字是历史遗留，实际保存的是 `Method$np<StageManager>.gdw()` 全局地址，不是 `StageManager_TypeInfo`。
- `dump.cs` 每个方法行里的 `Offset:` 不是 RVA，不要填进源码；必须使用 `RVA:`。1.00.20 的 `BOX_COUNT_GET` 曾因此被误写成 `0x8F5540`，正确 RVA 是 `0x8F6540`。
- 1.00.21 中 `RVA_BOX_COUNT_GET` 未自动确认，当前置 `0` 禁用；不要为了消除日志把旧 `0x8F6540` 填回去。
- `yv.kmb(float, EMonsterType, bool)` 是经验奖励加成，读 `AdditionalExpStageBoss/ActBoss/NormalMonster`，用于普通经验倍数 hook；不要当掉率函数。
- 正确掉率函数应读：
  - 普通箱：`DropChanceNormalChest(4)` 和 `DropChanceNormalChestPercent(29)`
  - 关卡 Boss 箱：`DropChanceStageBossChest(5)` 和 `DropChanceStageBossChestPercent(30)`
