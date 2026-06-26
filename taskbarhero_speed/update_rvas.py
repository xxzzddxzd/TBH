#!/usr/bin/env python3
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path


BEGIN_MARKER = "/* BEGIN TASKBARHERO GENERATED RVAS */"
END_MARKER = "/* END TASKBARHERO GENERATED RVAS */"

RVA_ORDER = [
    "RVA_TIME_GET_DELTATIME",
    "RVA_TIME_GET_TIMESCALE",
    "RVA_TIME_SET_TIMESCALE",
    "RVA_SINGLETON_GET_INSTANCE",
    "RVA_STAGE_MANAGER_TYPEINFO",
    "RVA_STAGE_DATA_TYPEINFO",
    "RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK",
    "RVA_STAGE_ENTER_EXACT_KEY",
    "RVA_STAGE_SET_CURRENT_CACHE",
    "RVA_STAGE_LIST_BY_ACT_DIFFICULTY",
    "RVA_STAGECACHE_GET_TYPE",
    "RVA_STAGECACHE_GET_KEY",
    "RVA_STAGECACHE_GET_DIFFICULTY",
    "RVA_STAGECACHE_GET_ACT",
    "RVA_STAGECACHE_GET_STAGE_NO",
    "RVA_STAGECACHE_GET_BOSS_MONSTER_KEY",
    "RVA_STAGECACHE_JGM",
    "RVA_MONSTER_DATA_BY_KEY",
    "RVA_DIRECT_BOSS_BRANCH",
    "RVA_ACTBOSS_SOULSTONE_BRANCH",
    "RVA_ACTBOSS_SOULSTONE_CONSUME_BRANCH",
    "RVA_ACTBOSS_SOULSTONE_CALLBACK_FALSE",
    "RVA_NORMAL_DROP_RATE_CALC",
    "RVA_BOSS_DROP_RATE_CALC",
    "RVA_EXP_REWARD_CALC",
    "RVA_CUBE_ADD_EXP",
    "RVA_STAT_VALUE_GET",
    "RVA_GIVE_REWARD_ITEM",
    "RVA_REWARD_ADD_ITEM",
    "RVA_BOX_COUNT_GET",
    "RVA_BOX_REWARD_SELECT",
    "RVA_DICT_TRY_GET_VALUE",
    "RVA_BOX_REWARD_TRY_GET_METHODINFO",
    "RVA_IL2CPP_GC_WRITE_BARRIER",
    "RVA_DROP_ROLL_PROCESS",
    "RVA_DROP_REWARD_CALLBACK",
    "RVA_DROP_COOLDOWN_SKIP_BRANCH",
    "RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH",
    "RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH",
]

SCRIPT_NAME_RVAS = {
    "RVA_SINGLETON_GET_INSTANCE": "np<object>$$gdw",
    "RVA_STAGE_MANAGER_TYPEINFO": "np<StageManager>_TypeInfo",
    "RVA_BOX_REWARD_TRY_GET_METHODINFO": "Method$System.Collections.Generic.Dictionary<EBoxType, List<BoxData>>.TryGetValue()",
}

DUMP_REGEX_RVAS = {
    "RVA_TIME_GET_DELTATIME": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public static float get_deltaTime\(\)",
    "RVA_TIME_GET_TIMESCALE": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public static float get_timeScale\(\)",
    "RVA_TIME_SET_TIMESCALE": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public static void set_timeScale\(float value\)",
    "RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public EStageEnterResultType \w+\(int a\)",
    "RVA_STAGE_ENTER_EXACT_KEY": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public EStageEnterResultType \w+\(int a\)",
    "RVA_DROP_ROLL_PROCESS": r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*private void \w+\(int a, EStageType b, int c, float d, EMonsterType e\)",
}

FALLBACK_SCRIPT_NAMES = {
    "RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK": "TaskbarHero.StageManager$$ifu",
    "RVA_STAGE_ENTER_EXACT_KEY": "TaskbarHero.StageManager$$ifu",
    "RVA_NORMAL_DROP_RATE_CALC": "yv$$kmn",
    "RVA_BOSS_DROP_RATE_CALC": "yv$$kmo",
    "RVA_EXP_REWARD_CALC": "yv$$kmp",
}

PRESERVE_ONLY = {
    "RVA_STAGE_SET_CURRENT_CACHE": "unused legacy helper; preserved from current source",
    "RVA_STAGE_LIST_BY_ACT_DIFFICULTY": "unused; plugin scans StageData.berm directly",
    "RVA_DIRECT_BOSS_BRANCH": "manual branch inside StageManager logic; confirm byte is 75 or EB in IDA",
    "RVA_ACTBOSS_SOULSTONE_BRANCH": "retired x-10 soulstone patch; preserved but not used",
    "RVA_ACTBOSS_SOULSTONE_CONSUME_BRANCH": "retired x-10 soulstone patch; preserved but not used",
    "RVA_ACTBOSS_SOULSTONE_CALLBACK_FALSE": "retired x-10 soulstone patch; preserved but not used",
    "RVA_DICT_TRY_GET_VALUE": "manual: Dictionary<EBoxType, List<BoxData>>.TryGetValue shared body",
    "RVA_IL2CPP_GC_WRITE_BARRIER": "manual: il2cpp_gc_wbarrier",
    "RVA_DROP_REWARD_CALLBACK": "retired: active delegate invoke is patched directly and restored immediately",
    "RVA_DROP_COOLDOWN_SKIP_BRANCH": "manual branch inside StageManager drop roll; confirm bytes 77 55",
    "RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH": "manual branch inside reward item; confirm bytes 0F 85",
    "RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH": "manual branch inside reward item; confirm bytes 0F 84",
}

DROP_PATTERNS = {
    "RVA_NORMAL_DROP_RATE_CALC": (4, 29),
    "RVA_BOSS_DROP_RATE_CALC": (5, 30),
    "RVA_EXP_REWARD_CALC": (22, 23, 24),
}


class PeImage:
    def __init__(self, path):
        self.path = Path(path)
        self.data = self.path.read_bytes()
        self.sections = self._parse_sections()

    def _parse_sections(self):
        data = self.data
        if data[:2] != b"MZ":
            raise ValueError(f"{self.path} is not a PE file")
        pe_off = struct.unpack_from("<I", data, 0x3C)[0]
        if data[pe_off:pe_off + 4] != b"PE\0\0":
            raise ValueError(f"{self.path} has no PE signature")
        section_count = struct.unpack_from("<H", data, pe_off + 6)[0]
        optional_size = struct.unpack_from("<H", data, pe_off + 20)[0]
        section_off = pe_off + 24 + optional_size
        sections = []
        for i in range(section_count):
            off = section_off + i * 40
            name = data[off:off + 8].split(b"\0", 1)[0].decode("ascii", "replace")
            virtual_size, virtual_address, raw_size, raw_ptr = struct.unpack_from("<IIII", data, off + 8)
            sections.append((name, virtual_address, max(virtual_size, raw_size), raw_ptr, raw_size))
        return sections

    def rva_to_offset(self, rva):
        for _name, va, size, raw_ptr, raw_size in self.sections:
            if va <= rva < va + size:
                delta = rva - va
                if delta >= raw_size:
                    raise ValueError(f"RVA 0x{rva:X} maps outside raw section data")
                return raw_ptr + delta
        raise ValueError(f"RVA 0x{rva:X} not found in PE sections")

    def read_rva(self, rva, size):
        off = self.rva_to_offset(rva)
        return self.data[off:off + size]


def parse_args():
    parser = argparse.ArgumentParser(
        description="Update TaskBarHero speed plugin RVAs from Il2CppDumper output."
    )
    parser.add_argument("--dump-dir", type=Path, help="Directory containing dump.cs and script.json")
    parser.add_argument("--dump-cs", type=Path, help="Path to dump.cs")
    parser.add_argument("--script-json", type=Path, help="Path to script.json")
    parser.add_argument("--game-assembly", type=Path, help="Path to GameAssembly.dll for byte-based validation")
    parser.add_argument("--source", type=Path, default=Path("taskbarhero_speed/winhttp_proxy.c"))
    parser.add_argument("--apply", action="store_true", help="Rewrite the generated RVA block in winhttp_proxy.c")
    return parser.parse_args()


def resolve_paths(args):
    dump_cs = args.dump_cs
    script_json = args.script_json
    if args.dump_dir:
        dump_cs = dump_cs or args.dump_dir / "dump.cs"
        script_json = script_json or args.dump_dir / "script.json"
    if not dump_cs or not dump_cs.exists():
        raise SystemExit("missing dump.cs; pass --dump-dir or --dump-cs")
    if not script_json or not script_json.exists():
        raise SystemExit("missing script.json; pass --dump-dir or --script-json")
    return dump_cs, script_json


def parse_script_entries(script_json, interesting_names):
    found = {}
    function_entries = []
    function_addresses = []
    current = {}

    with script_json.open("r", encoding="utf-8") as f:
        for raw in f:
            line = raw.strip()
            if line.startswith('"Address":'):
                current["Address"] = int(line.split(":", 1)[1].rstrip(", "))
            elif line.startswith('"Name":'):
                current["Name"] = json.loads(line.split(":", 1)[1].rstrip(", "))
            elif line.startswith('"Signature":'):
                value = line.split(":", 1)[1].rstrip(", ")
                current["Signature"] = None if value == "null" else json.loads(value)
            elif line == "}," or line == "}":
                name = current.get("Name")
                if name in interesting_names and "Address" in current:
                    found[name] = current["Address"]
                sig = current.get("Signature") or ""
                if name and sig and "(" in sig and "Address" in current and not name.startswith("Method$"):
                    function_addresses.append(current["Address"])
                    function_entries.append({
                        "name": name,
                        "address": current["Address"],
                        "signature": sig,
                    })
                current = {}
    return found, function_entries, sorted(set(function_addresses))


def parse_script_addresses(script_json, interesting_names):
    found, _function_entries, _function_addresses = parse_script_entries(
        script_json, interesting_names
    )
    return found


def read_existing_rvas(source):
    if not source.exists():
        return {}
    text = source.read_text(encoding="utf-8")
    out = {}
    for name, value in re.findall(r"#define\s+(RVA_[A-Z0-9_]+)\s+0x([0-9A-Fa-f]+)ULL", text):
        out[name] = int(value, 16)
    return out


def extract_dump_rvas(dump_cs):
    text = dump_cs.read_text(encoding="utf-8", errors="replace")
    found = {}
    notes = []
    for macro, pattern in DUMP_REGEX_RVAS.items():
        matches = re.findall(pattern, text)
        unique = sorted(set(matches), key=lambda s: int(s, 16))
        if len(unique) == 1:
            found[macro] = int(unique[0], 16)
        elif len(unique) > 1:
            notes.append(f"{macro}: ambiguous dump.cs matches {', '.join(unique)}")
    return found, notes


def class_block(text, declaration):
    start = text.find(declaration)
    if start < 0:
        return ""
    end = text.find("\n// Namespace:", start + 1)
    if end < 0:
        end = len(text)
    return text[start:end]


CLASS_DECL_RE = re.compile(
    r"(?m)^(?:\[[^\n]+\]\s*\n)*"
    r"(?:public|private|internal)\s+"
    r"(?:sealed\s+)?(?:static\s+)?class\s+"
    r"([A-Za-z_]\w*(?:\.[A-Za-z_]\w*)*)\b(?!\.)"
)


def iter_class_blocks(text):
    for match in CLASS_DECL_RE.finditer(text):
        start = match.start()
        end = text.find("\n// Namespace:", start + 1)
        if end < 0:
            end = len(text)
        yield match.group(1), text[start:end]


def class_block_by_suffix(text, suffix):
    matches = [
        (name, block)
        for name, block in iter_class_blocks(text)
        if name.rsplit(".", 1)[-1] == suffix
    ]
    if len(matches) == 1:
        return matches[0]
    return "", ""


def dump_method_entries(block):
    out = []
    pattern = re.compile(
        r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n"
        r"\s*(?:\[[^\n]+\]\s*\n\s*)*"
        r"(?:public|private|internal)\s+(static\s+)?(.+?)\s+(\.ctor|[A-Za-z_]\w*)\(([^)]*)\)"
    )
    for match in pattern.finditer(block):
        out.append({
            "address": int(match.group(1), 16),
            "static": bool(match.group(2)),
            "return_type": match.group(3).strip(),
            "name": match.group(4),
            "params": " ".join(match.group(5).strip().split()),
        })
    return out


def extract_dump_structural_rvas(dump_cs):
    text = dump_cs.read_text(encoding="utf-8", errors="replace")
    found = {}
    aux = {}
    notes = []
    add_item_candidates = []

    stage_class, stage_block = class_block_by_suffix(text, "StageCache")
    stage_methods = [
        item for item in dump_method_entries(stage_block)
        if item["name"] != ".ctor"
    ]
    if stage_methods:
        stage_class_re = re.escape(stage_class)
        for class_name, block in iter_class_blocks(text):
            if class_name == stage_class:
                continue
            has_stage_list = re.search(rf"\bstatic\s+List<{stage_class_re}>\s+\w+;\s*//\s*0x([0-9A-Fa-f]+)", block)
            has_current_stage = re.search(rf"\bpublic\s+static\s+{stage_class_re}\s+\w+;\s*//\s*0x([0-9A-Fa-f]+)", block)
            if has_stage_list and has_current_stage:
                aux["STAGE_DATA_TYPEINFO_NAME"] = class_name + "_TypeInfo"
                stage_list_offset = int(has_stage_list.group(1), 16)
                current_stage_offset = int(has_current_stage.group(1), 16)
                if stage_list_offset != 0x38 or current_stage_offset != 0x88:
                    notes.append(
                        "StageData static field offsets changed: "
                        f"list=0x{stage_list_offset:X} current=0x{current_stage_offset:X}"
                    )
                break
        if "STAGE_DATA_TYPEINFO_NAME" not in aux:
            notes.append("RVA_STAGE_DATA_TYPEINFO: StageData static class not found")
        type_idx = next((i for i, m in enumerate(stage_methods)
                         if m["return_type"] == "EStageType"), None)
        if type_idx is not None:
            found["RVA_STAGECACHE_GET_TYPE"] = stage_methods[type_idx]["address"]
            if type_idx + 1 < len(stage_methods) and stage_methods[type_idx + 1]["return_type"] == "int":
                found["RVA_STAGECACHE_GET_KEY"] = stage_methods[type_idx + 1]["address"]
            else:
                notes.append("RVA_STAGECACHE_GET_KEY: could not derive getter after EStageType")
        diff_idx = next((i for i, m in enumerate(stage_methods)
                         if m["return_type"] == "ESTAGEDIFFICULTY"), None)
        if diff_idx is not None:
            found["RVA_STAGECACHE_GET_DIFFICULTY"] = stage_methods[diff_idx]["address"]
            ints_after = [m for m in stage_methods[diff_idx + 1:] if m["return_type"] == "int"]
            if len(ints_after) >= 2:
                found["RVA_STAGECACHE_GET_ACT"] = ints_after[0]["address"]
                found["RVA_STAGECACHE_GET_STAGE_NO"] = ints_after[1]["address"]
            else:
                notes.append("RVA_STAGECACHE_GET_ACT/STAGE_NO: not enough int getters after difficulty")
        if len(stage_methods) > 14 and stage_methods[14]["return_type"] == "int":
            found["RVA_STAGECACHE_GET_BOSS_MONSTER_KEY"] = stage_methods[14]["address"]
        else:
            notes.append("RVA_STAGECACHE_GET_BOSS_MONSTER_KEY: StageCache getter order changed; confirm manually")
        primitive_returns = {
            "void", "bool", "int", "float", "string",
            "EStageType", "ESTAGEDIFFICULTY",
        }
        stage_boss_methods = [
            m for m in stage_methods
            if m["return_type"] not in primitive_returns and "." in m["return_type"]
        ]
        if stage_boss_methods:
            found["RVA_STAGECACHE_JGM"] = stage_boss_methods[-1]["address"]
            aux["MONSTER_DATA_TYPE"] = stage_boss_methods[-1]["return_type"]
        else:
            notes.append("RVA_STAGECACHE_JGM: no object-returning StageCache getter found")
    else:
        notes.append("StageCache class not found in dump.cs")

    all_methods = dump_method_entries(text)
    monster_type = aux.get("MONSTER_DATA_TYPE")
    monster_methods = all_methods
    monster_by_key = [
        m for m in monster_methods
        if monster_type and m["static"] and m["return_type"] == monster_type and
        m["params"] == "int a"
    ]
    if monster_by_key:
        found["RVA_MONSTER_DATA_BY_KEY"] = monster_by_key[0]["address"]
        if len(monster_by_key) > 1:
            notes.append("RVA_MONSTER_DATA_BY_KEY: multiple monster-data int candidates; using first dump order")
    else:
        notes.append("RVA_MONSTER_DATA_BY_KEY: monster-data static int lookup not found")

    reward_block_name = ""
    reward_callbacks = []
    for class_name, block in iter_class_blocks(text):
        methods = dump_method_entries(block)
        callbacks = [
            m for m in methods
            if m["static"] and m["return_type"] == "void" and
            m["params"] == "int a, Action<int> b"
        ]
        add_candidates = [
            m["address"] for m in methods
            if m["static"] and m["return_type"] == "AddItemResult" and
            m["params"].startswith("int a, ulong b, int c = 1, bool d = False")
        ]
        if callbacks and add_candidates:
            reward_block_name = class_name
            reward_callbacks = callbacks
            add_item_candidates = add_candidates
            break
    if reward_callbacks:
        found["RVA_GIVE_REWARD_ITEM"] = reward_callbacks[0]["address"]
        if len(reward_callbacks) > 1:
            aux["GIVE_REWARD_ITEM_CANDIDATES"] = [m["address"] for m in reward_callbacks]
            notes.append(
                f"RVA_GIVE_REWARD_ITEM: multiple {reward_block_name} Action<int> candidates; using first dump order"
            )
    else:
        notes.append("RVA_GIVE_REWARD_ITEM: Action<int> reward entry not found")

    vw_methods = dump_method_entries(class_block(text, "public class vy"))
    box_select = [
        m for m in vw_methods
        if m["return_type"] == "BoxData" and m["params"] == "int a"
    ]
    if len(box_select) == 1:
        found["RVA_BOX_REWARD_SELECT"] = box_select[0]["address"]
    elif box_select:
        aux["BOX_REWARD_SELECT_CANDIDATES"] = [m["address"] for m in box_select]
        notes.append("RVA_BOX_REWARD_SELECT: ambiguous vy BoxData(int) candidates")
    else:
        notes.append("RVA_BOX_REWARD_SELECT: vy BoxData(int) not found")

    box_count_match = re.search(
        r"// RVA: (0x[0-9A-Fa-f]+)[^\n]*\n\s*public static int csr\(int a\)",
        text
    )
    if box_count_match:
        found["RVA_BOX_COUNT_GET"] = int(box_count_match.group(1), 16)
    else:
        found["RVA_BOX_COUNT_GET"] = 0
        notes.append("RVA_BOX_COUNT_GET: csr(int) not found; disabled trace-only box-count hook")

    _cube_class, cube_block = class_block_by_suffix(text, "Cube")
    cube_methods = dump_method_entries(cube_block)
    cube_add_exp = [
        m for m in cube_methods
        if m["static"] and m["return_type"] == "void" and
        m["params"] == "float a"
    ]
    if len(cube_add_exp) == 1:
        found["RVA_CUBE_ADD_EXP"] = cube_add_exp[0]["address"]
    elif cube_add_exp:
        notes.append("RVA_CUBE_ADD_EXP: ambiguous Cube void(float) candidates")
    else:
        notes.append("RVA_CUBE_ADD_EXP: Cube void(float) not found")

    account_status_block = class_block(text, "public class AccountStatus")
    account_status_methods = dump_method_entries(account_status_block)
    stat_getters = [
        m for m in account_status_methods
        if not m["static"] and m["return_type"] == "int" and
        m["params"] == "EAccountStatus a"
    ]
    if len(stat_getters) == 1:
        found["RVA_STAT_VALUE_GET"] = stat_getters[0]["address"]
    elif stat_getters:
        found["RVA_STAT_VALUE_GET"] = stat_getters[0]["address"]
        notes.append("RVA_STAT_VALUE_GET: multiple AccountStatus int(EAccountStatus) candidates; using first dump order")
    else:
        notes.append("RVA_STAT_VALUE_GET: AccountStatus int(EAccountStatus) not found")

    monster_methods = dump_method_entries(
        class_block(text, "public class MonsterSpawnManager")
    )
    boss_flow = [
        m for m in monster_methods
        if m["return_type"] == "void" and m["params"] == "bool a = False"
    ]
    if len(boss_flow) == 1:
        aux["MONSTER_SPAWN_BOSS_FLOW"] = boss_flow[0]["address"]
    elif boss_flow:
        notes.append("RVA_DIRECT_BOSS_BRANCH: ambiguous MonsterSpawnManager void(bool=False) candidates")
    else:
        notes.append("RVA_DIRECT_BOSS_BRANCH: MonsterSpawnManager void(bool=False) not found")

    return found, notes, aux, add_item_candidates


def has_status_ids(code, ids):
    for stat_id in ids:
        pattern = b"\xBA" + struct.pack("<I", stat_id)
        if pattern not in code:
            return False
    return True


def call_targets_from_code(start_rva, code):
    targets = set()
    for i in range(0, max(0, len(code) - 4)):
        if code[i] != 0xE8:
            continue
        rel = struct.unpack_from("<i", code, i + 1)[0]
        targets.add((start_rva + i + 5 + rel) & 0xFFFFFFFF)
    return targets


def function_size(address, function_addresses):
    for next_address in function_addresses:
        if next_address > address:
            return max(1, min(next_address - address, 0x260))
    return 0x260


def find_status_functions(pe, function_entries, function_addresses, drop_roll_rva=None):
    found = {}
    notes = []
    drop_roll_calls = set()
    if drop_roll_rva:
        try:
            drop_roll_code = pe.read_rva(drop_roll_rva, function_size(drop_roll_rva, function_addresses))
            drop_roll_calls = call_targets_from_code(drop_roll_rva, drop_roll_code)
        except ValueError:
            drop_roll_calls = set()

    for macro, stat_ids in DROP_PATTERNS.items():
        matches = []
        for item in function_entries:
            sig = item.get("signature", "")
            if "float " not in sig:
                continue
            try:
                code = pe.read_rva(item["address"], function_size(item["address"], function_addresses))
            except ValueError:
                continue
            if has_status_ids(code, stat_ids):
                matches.append(item)
        preferred = matches
        if macro in {"RVA_NORMAL_DROP_RATE_CALC", "RVA_BOSS_DROP_RATE_CALC"} and drop_roll_calls:
            called = [item for item in matches if item["address"] in drop_roll_calls]
            if called:
                preferred = called
        unique_addresses = sorted({item["address"] for item in preferred})
        if len(unique_addresses) == 1:
            address = unique_addresses[0]
            item = next(item for item in preferred if item["address"] == address)
            found[macro] = address
            source = "drop-roll call + byte scan" if preferred is not matches else "byte scan"
            notes.append(f"{macro}: {source} matched {item['name']} stat ids {stat_ids}")
        elif len(matches) > 1:
            notes.append(f"{macro}: ambiguous byte scan for stat ids {stat_ids}: " +
                         ", ".join(f"{m['name']}@0x{m['address']:X}" for m in matches))
        else:
            notes.append(f"{macro}: no byte-scan match for stat ids {stat_ids}; falling back to name map")
    return found, notes


def find_call_target(pe, function_rva, function_addresses, candidate_rvas):
    try:
        code = pe.read_rva(function_rva, function_size(function_rva, function_addresses))
    except ValueError:
        return None
    calls = call_targets_from_code(function_rva, code)
    matches = sorted(set(candidate_rvas) & calls)
    if len(matches) == 1:
        return matches[0]
    return None


def find_direct_boss_branch(pe, function_rva, function_addresses):
    try:
        code = pe.read_rva(function_rva, function_size(function_rva, function_addresses))
    except ValueError:
        return None
    needle = b"\x80\x7F\x40\x00\x75"
    at = code.find(needle)
    if at >= 0:
        return function_rva + at + 4
    return None


def find_drop_cooldown_branch(pe, drop_roll_rva, function_addresses):
    try:
        code = pe.read_rva(drop_roll_rva, function_size(drop_roll_rva, function_addresses))
    except ValueError:
        return None
    needle = b"\x0F\x2F\xC8\x77"
    at = code.find(needle)
    if at >= 0:
        return drop_roll_rva + at + 3
    return None


def find_reward_item_branches(pe, give_reward_rva, function_addresses):
    found = {}
    try:
        code = pe.read_rva(give_reward_rva, function_size(give_reward_rva, function_addresses))
    except ValueError:
        return found

    config = code.find(b"\x83\x78\x34\x00\x0F\x85")
    if config >= 0:
        found["RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH"] = give_reward_rva + config + 4

    capacity = code.find(b"\x84\xC0\x0F\x84")
    if capacity >= 0:
        found["RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH"] = give_reward_rva + capacity + 2
    return found


def validate_source_rvas(source):
    if not source.exists():
        return []
    text = source.read_text(encoding="utf-8")
    used = set(re.findall(r"\bRVA_[A-Z0-9_]+\b", text))
    defined = set(RVA_ORDER)
    defined.update(name for name, _ in re.findall(
        r"#define\s+(RVA_[A-Z0-9_]+)\s+0x([0-9A-Fa-f]+)ULL", text
    ))
    return sorted(used - defined)


def format_block(rvas):
    lines = [BEGIN_MARKER]
    for name in RVA_ORDER:
        if name not in rvas:
            raise SystemExit(f"missing {name}")
        suffix = ""
        if name == "RVA_STAGE_MANAGER_TYPEINFO":
            suffix = " /* np<StageManager>_TypeInfo */"
        elif name == "RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK":
            suffix = " /* legacy StageManager enter hook restore target */"
        elif name == "RVA_STAGE_ENTER_EXACT_KEY":
            suffix = " /* StageManager::ifu enters the stage after the supplied StageKey */"
        elif name == "RVA_STAGE_SET_CURRENT_CACHE":
            suffix = " /* unused legacy helper */"
        elif name == "RVA_STAGE_LIST_BY_ACT_DIFFICULTY":
            suffix = " /* unused: scan StageData list directly */"
        elif name == "RVA_STAGECACHE_GET_KEY":
            suffix = " /* StageCache StageKey; previous int getter is NextStageKey */"
        elif name == "RVA_STAGECACHE_JGM":
            suffix = " /* StageCache boss data getter; old macro name retained */"
        elif name == "RVA_EXP_REWARD_CALC":
            suffix = " /* exp reward multiplier hook; not a drop rate */"
        elif name == "RVA_CUBE_ADD_EXP":
            suffix = " /* Cube add exp void(float) */"
        elif name == "RVA_BOX_REWARD_SELECT":
            suffix = " /* vy::BoxData(int) selects concrete reward from stage box key */"
        elif name == "RVA_DICT_TRY_GET_VALUE":
            suffix = " /* Dictionary<EBoxType, List<BoxData>>.TryGetValue */"
        elif name == "RVA_BOX_REWARD_TRY_GET_METHODINFO":
            suffix = " /* MethodInfo used by box reward dictionary */"
        elif name == "RVA_IL2CPP_GC_WRITE_BARRIER":
            suffix = " /* write barrier used after managed reference stores */"
        elif name == "RVA_DROP_REWARD_CALLBACK":
            suffix = " /* 0 = wildcard active delegate invoke */"
        elif name == "RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH":
            suffix = " /* manual branch inside reward item */"
        elif name == "RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH":
            suffix = " /* manual branch inside reward item */"
        elif name in PRESERVE_ONLY:
            suffix = " /* preserved/manual */"
        lines.append(f"#define {name} 0x{rvas[name]:X}ULL{suffix}")
    lines.append(END_MARKER)
    return "\n".join(lines)


def apply_block(source, block):
    text = source.read_text(encoding="utf-8")
    start = text.find(BEGIN_MARKER)
    end = text.find(END_MARKER)
    if start < 0 or end < 0 or end < start:
        raise SystemExit(f"{source} is missing generated RVA markers")
    end += len(END_MARKER)
    source.write_text(text[:start] + block + text[end:], encoding="utf-8")


def main():
    args = parse_args()
    dump_cs, script_json = resolve_paths(args)
    existing = read_existing_rvas(args.source)
    interesting_names = set(SCRIPT_NAME_RVAS.values()) | set(FALLBACK_SCRIPT_NAMES.values())
    script_found, function_entries, function_addresses = parse_script_entries(script_json, interesting_names)

    rvas = dict(existing)
    sources = {}
    dump_found, dump_notes = extract_dump_rvas(dump_cs)
    for macro, value in dump_found.items():
        rvas[macro] = value
        sources[macro] = "dump.cs signature"

    for macro, script_name in SCRIPT_NAME_RVAS.items():
        if script_name in script_found:
            rvas[macro] = script_found[script_name]
            sources[macro] = f"script.json {script_name}"

    notes = list(dump_notes)
    structural_found, structural_notes, aux_rvas, add_item_candidates = extract_dump_structural_rvas(dump_cs)
    notes.extend(structural_notes)
    dynamic_script_names = set()
    if aux_rvas.get("STAGE_DATA_TYPEINFO_NAME"):
        dynamic_script_names.add(aux_rvas["STAGE_DATA_TYPEINFO_NAME"])
    if dynamic_script_names:
        dynamic_script_found = parse_script_addresses(script_json, dynamic_script_names)
        stage_data_name = aux_rvas.get("STAGE_DATA_TYPEINFO_NAME")
        if stage_data_name in dynamic_script_found:
            structural_found["RVA_STAGE_DATA_TYPEINFO"] = dynamic_script_found[stage_data_name]
            sources["RVA_STAGE_DATA_TYPEINFO"] = f"script.json {stage_data_name}"
        elif stage_data_name:
            notes.append(f"RVA_STAGE_DATA_TYPEINFO: {stage_data_name} not found in script.json")
    for macro, value in structural_found.items():
        rvas[macro] = value
        sources.setdefault(macro, "dump.cs structure")
    rvas["RVA_DROP_REWARD_CALLBACK"] = 0
    sources["RVA_DROP_REWARD_CALLBACK"] = "retired wildcard"

    if args.game_assembly:
        pe = PeImage(args.game_assembly)
        scanned, scan_notes = find_status_functions(
            pe,
            function_entries,
            function_addresses,
            rvas.get("RVA_DROP_ROLL_PROCESS")
        )
        notes.extend(scan_notes)
        for macro, value in scanned.items():
            rvas[macro] = value
            sources[macro] = "GameAssembly byte scan"

        if rvas.get("RVA_GIVE_REWARD_ITEM") and add_item_candidates:
            reward_add = find_call_target(
                pe,
                rvas["RVA_GIVE_REWARD_ITEM"],
                function_addresses,
                add_item_candidates
            )
            if reward_add is not None:
                rvas["RVA_REWARD_ADD_ITEM"] = reward_add
                sources["RVA_REWARD_ADD_ITEM"] = "GameAssembly call target from reward entry"
            else:
                notes.append("RVA_REWARD_ADD_ITEM: no unique AddItemResult call from reward entry")

        if rvas.get("RVA_GIVE_REWARD_ITEM") and aux_rvas.get("BOX_REWARD_SELECT_CANDIDATES"):
            box_select = find_call_target(
                pe,
                rvas["RVA_GIVE_REWARD_ITEM"],
                function_addresses,
                aux_rvas["BOX_REWARD_SELECT_CANDIDATES"]
            )
            if box_select is not None:
                rvas["RVA_BOX_REWARD_SELECT"] = box_select
                sources["RVA_BOX_REWARD_SELECT"] = "GameAssembly call target from reward entry"
            else:
                notes.append("RVA_BOX_REWARD_SELECT: no unique BoxData(int) call from reward entry")

        if aux_rvas.get("MONSTER_SPAWN_BOSS_FLOW"):
            direct_branch = find_direct_boss_branch(
                pe,
                aux_rvas["MONSTER_SPAWN_BOSS_FLOW"],
                function_addresses
            )
            if direct_branch is not None:
                rvas["RVA_DIRECT_BOSS_BRANCH"] = direct_branch
                sources["RVA_DIRECT_BOSS_BRANCH"] = "GameAssembly branch scan"
            else:
                notes.append("RVA_DIRECT_BOSS_BRANCH: byte pattern not found in MonsterSpawnManager boss flow")

        if rvas.get("RVA_DROP_ROLL_PROCESS"):
            drop_branch = find_drop_cooldown_branch(
                pe,
                rvas["RVA_DROP_ROLL_PROCESS"],
                function_addresses
            )
            if drop_branch is not None:
                rvas["RVA_DROP_COOLDOWN_SKIP_BRANCH"] = drop_branch
                sources["RVA_DROP_COOLDOWN_SKIP_BRANCH"] = "GameAssembly branch scan"
            else:
                notes.append("RVA_DROP_COOLDOWN_SKIP_BRANCH: byte pattern not found in drop roll")

        if rvas.get("RVA_GIVE_REWARD_ITEM"):
            reward_branches = find_reward_item_branches(
                pe,
                rvas["RVA_GIVE_REWARD_ITEM"],
                function_addresses
            )
            for macro, value in reward_branches.items():
                rvas[macro] = value
                sources[macro] = "GameAssembly branch scan"
            for macro in (
                "RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH",
                "RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH",
            ):
                if macro not in reward_branches:
                    notes.append(f"{macro}: byte pattern not found in reward entry")

        digest = hashlib.sha256(pe.data).hexdigest()
        notes.append(f"GameAssembly SHA256: {digest}")

    for macro, script_name in FALLBACK_SCRIPT_NAMES.items():
        if macro not in sources and script_name in script_found:
            rvas[macro] = script_found[script_name]
            sources[macro] = f"fallback script.json {script_name}"
        elif macro in {"RVA_NORMAL_DROP_RATE_CALC", "RVA_BOSS_DROP_RATE_CALC", "RVA_EXP_REWARD_CALC"}:
            if sources.get(macro) != "GameAssembly byte scan" and script_name in script_found:
                rvas[macro] = script_found[script_name]
                sources[macro] = f"fallback script.json {script_name}"

    missing = [name for name in RVA_ORDER if name not in rvas]
    if missing:
        raise SystemExit("missing RVAs: " + ", ".join(missing))

    unknown_source_rvas = validate_source_rvas(args.source)
    if unknown_source_rvas:
        raise SystemExit("source uses RVA macros not covered by updater: " +
                         ", ".join(unknown_source_rvas))

    block = format_block(rvas)
    print(block)
    print("\nSources:")
    for name in RVA_ORDER:
        print(f"  {name}: {sources.get(name, 'preserved from current source')}")
    if notes:
        print("\nNotes:")
        for note in notes:
            print(f"  - {note}")
    print("\nManual checks:")
    print("  - Confirm RVA_DIRECT_BOSS_BRANCH in IDA; byte should be 0x75 before patch or 0xEB after patch.")
    print("  - Confirm drop functions reference stat ids 4/29 and 5/30; exp function references 22/23/24.")
    print("  - Confirm RVA_CUBE_ADD_EXP is Cube void(float) and starts with the expected stack/prologue bytes.")
    print("  - Rebuild, inject, then check TaskBarHeroSpeed.log for Unity Time hooks and drop rate hooks.")

    if args.apply:
        apply_block(args.source, block)
        print(f"\nupdated {args.source}")


if __name__ == "__main__":
    main()
