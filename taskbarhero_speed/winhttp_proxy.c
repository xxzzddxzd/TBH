#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdarg.h>

#define TBHS_SUPPORTED_GAME_VERSION "1.00.21"
#define TBHS_PLUGIN_VERSION "0.4.0"
#define TBHS_PLUGIN_SUBVERSION "2"
#define TBHS_PLUGIN_DISPLAY_VERSION "0.4.0.2"
#define SPEED_DEFAULT 5.0f
#define EXP_MULTIPLIER_DEFAULT 1.0f
#define CUBE_EXP_MULTIPLIER_DEFAULT 10.0f
#define GAMEASSEMBLY_NAME "GameAssembly.dll"

#if defined(__GNUC__)
#define TBHS_UNUSED __attribute__((unused))
#else
#define TBHS_UNUSED
#endif

/*
 * TaskBarHero RVAs. Update this generated block with:
 * python3 taskbarhero_speed/update_rvas.py --dump-dir <Il2CppDumper output> --game-assembly GameAssembly.dll --apply
 * These are intentionally app-specific, not a generic Unity patch.
 */
/* BEGIN TASKBARHERO GENERATED RVAS */
#define RVA_TIME_GET_DELTATIME 0x4690DA0ULL
#define RVA_TIME_GET_TIMESCALE 0x4691030ULL
#define RVA_TIME_SET_TIMESCALE 0x46911D0ULL
#define RVA_SINGLETON_GET_INSTANCE 0x29588B0ULL
#define RVA_STAGE_MANAGER_TYPEINFO 0x5E3FF98ULL /* np<StageManager>_TypeInfo */
#define RVA_STAGE_DATA_TYPEINFO 0x5DC9958ULL
#define RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK 0x88D2F0ULL /* legacy StageManager enter hook restore target */
#define RVA_STAGE_ENTER_EXACT_KEY 0x88D2F0ULL /* StageManager::ifu enters the stage after the supplied StageKey */
#define RVA_STAGE_SET_CURRENT_CACHE 0x93CB10ULL /* unused legacy helper */
#define RVA_STAGE_LIST_BY_ACT_DIFFICULTY 0x0ULL /* unused: scan StageData list directly */
#define RVA_STAGECACHE_GET_TYPE 0x9326F0ULL
#define RVA_STAGECACHE_GET_KEY 0x932710ULL /* StageCache StageKey; previous int getter is NextStageKey */
#define RVA_STAGECACHE_GET_DIFFICULTY 0x8DAAA0ULL
#define RVA_STAGECACHE_GET_ACT 0x932730ULL
#define RVA_STAGECACHE_GET_STAGE_NO 0x932750ULL
#define RVA_STAGECACHE_GET_BOSS_MONSTER_KEY 0x932880ULL
#define RVA_STAGECACHE_JGM 0x932E70ULL /* StageCache boss data getter; old macro name retained */
#define RVA_MONSTER_DATA_BY_KEY 0x91A1A0ULL
#define RVA_DIRECT_BOSS_BRANCH 0x9FF1F2ULL /* preserved/manual */
#define RVA_ACTBOSS_SOULSTONE_BRANCH 0x0ULL /* preserved/manual */
#define RVA_ACTBOSS_SOULSTONE_CONSUME_BRANCH 0x0ULL /* preserved/manual */
#define RVA_ACTBOSS_SOULSTONE_CALLBACK_FALSE 0x0ULL /* preserved/manual */
#define RVA_NORMAL_DROP_RATE_CALC 0x9EC7F0ULL
#define RVA_BOSS_DROP_RATE_CALC 0x9EC8E0ULL
#define RVA_EXP_REWARD_CALC 0x9EC9D0ULL /* exp reward multiplier hook; not a drop rate */
#define RVA_CUBE_ADD_EXP 0x8A3580ULL /* Cube add exp void(float) */
#define RVA_STAT_VALUE_GET 0x9D5A20ULL
#define RVA_GIVE_REWARD_ITEM 0x9097E0ULL
#define RVA_REWARD_ADD_ITEM 0x909AB0ULL
#define RVA_BOX_COUNT_GET 0x0ULL
#define RVA_BOX_REWARD_SELECT 0x975850ULL /* vy::BoxData(int) selects concrete reward from stage box key */
#define RVA_DICT_TRY_GET_VALUE 0x2D09070ULL /* Dictionary<EBoxType, List<BoxData>>.TryGetValue */
#define RVA_BOX_REWARD_TRY_GET_METHODINFO 0x5DDAE18ULL /* MethodInfo used by box reward dictionary */
#define RVA_IL2CPP_GC_WRITE_BARRIER 0x58F760ULL /* write barrier used after managed reference stores */
#define RVA_DROP_ROLL_PROCESS 0x891400ULL
#define RVA_DROP_REWARD_CALLBACK 0x0ULL /* 0 = wildcard active delegate invoke */
#define RVA_DROP_COOLDOWN_SKIP_BRANCH 0x89161BULL /* preserved/manual */
#define RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH 0x90988DULL /* manual branch inside reward item */
#define RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH 0x9098EBULL /* manual branch inside reward item */
/* END TASKBARHERO GENERATED RVAS */

#define STAGE_DATA_STAGE_LIST_OFFSET 56
#define STAGE_DATA_CURRENT_CACHE_OFFSET 136
#define IL2CPP_TYPE_STATIC_FIELDS_OFFSET 184
#define IL2CPP_LIST_ITEMS_OFFSET 16
#define IL2CPP_LIST_SIZE_OFFSET 24
#define IL2CPP_ARRAY_LENGTH_OFFSET 24
#define IL2CPP_ARRAY_DATA_OFFSET 32
#define ESTAGE_TYPE_NORMAL 0
#define ESTAGE_TYPE_ACTBOSS 1

#define OVERLAY_CLASS_PREFIX "TaskBarHeroSpeedOverlay_"
#define OVERLAY_DISPLAY_TITLE "TaskBarHero"
#define OVERLAY_WINDOW_TITLE "TaskBarHero Overlay"
#define OVERLAY_OLD_WINDOW_TITLE "TaskBarHero Speed"
#define OVERLAY_WIDTH 684
#define OVERLAY_HEIGHT 242
#define OVERLAY_LOG_LINE_COUNT 8
#define OVERLAY_LOG_LINE_SIZE 160
#define OVERLAY_BUTTON_MIN 1001
#define OVERLAY_BUTTON_MINUS5 1002
#define OVERLAY_BUTTON_MINUS1 1003
#define OVERLAY_LABEL_SPEED 1004
#define OVERLAY_BUTTON_PLUS1 1005
#define OVERLAY_BUTTON_PLUS5 1006
#define OVERLAY_BUTTON_MAX 1007
#define OVERLAY_BUTTON_BOSS 1008
#define OVERLAY_BUTTON_ACTBOSS 1009
#define OVERLAY_BUTTON_LOCK_STAGE 1010
#define OVERLAY_BUTTON_LOCK_MINUS30 1011
#define OVERLAY_BUTTON_LOCK_MINUS10 1012
#define OVERLAY_LABEL_LOCK_INTERVAL 1013
#define OVERLAY_BUTTON_LOCK_PLUS10 1014
#define OVERLAY_BUTTON_LOCK_PLUS30 1015
#define OVERLAY_LABEL_CHEST_INTERVALS 1016
#define OVERLAY_BUTTON_AUTO_SWITCH 1017
#define OVERLAY_LABEL_LOCK_STAGE 1018
#define OVERLAY_BUTTON_EXP_MINUS 1019
#define OVERLAY_LABEL_EXP_MULTIPLIER 1020
#define OVERLAY_BUTTON_EXP_PLUS 1021
#define OVERLAY_BUTTON_CUBE_MINUS 1022
#define OVERLAY_LABEL_CUBE_MULTIPLIER 1023
#define OVERLAY_BUTTON_CUBE_PLUS 1024
#define AUTO_PORTAL_INTERVAL_MIN_MS 5000
#define AUTO_PORTAL_INTERVAL_MAX_MS 3600000
#define AUTO_RESTART_REQUEST_NONE 0
#define AUTO_RESTART_REQUEST_LOCK 1
#define AUTO_RESTART_REQUEST_UNLOCK 2
#define AUTO_SWITCH_WAIT_NONE 0
#define AUTO_SWITCH_WAIT_NORMAL_DROP 1
#define AUTO_SWITCH_WAIT_BOSS_DROP 2
#define OVERLAY_COLOR_BG RGB(28, 24, 20)
#define OVERLAY_COLOR_PANEL RGB(42, 35, 29)
#define OVERLAY_COLOR_PANEL_2 RGB(34, 30, 25)
#define OVERLAY_COLOR_BORDER RGB(150, 116, 61)
#define OVERLAY_COLOR_ACCENT RGB(220, 169, 74)
#define OVERLAY_COLOR_TEXT RGB(238, 225, 190)
#define OVERLAY_COLOR_MUTED RGB(164, 142, 104)
#define OVERLAY_COLOR_BUTTON RGB(52, 43, 35)
#define OVERLAY_COLOR_BUTTON_HOT RGB(66, 53, 39)
#define OVERLAY_COLOR_BUTTON_ACTIVE RGB(63, 86, 58)
#define OVERLAY_COLOR_LOG_BG RGB(20, 18, 16)
#define OVERLAY_COLOR_LOG_TEXT RGB(196, 214, 173)
#define DROP_OUTCOME_MISS 0
#define DROP_OUTCOME_DROP 1
#define DROP_OUTCOME_BLOCKED 2
#define ENABLE_DROP_RATE_BOOST 0
#define ENABLE_FORCE_BOX_REWARD_SELECT 1

typedef void *(*resolve_icall_t)(const char *name);
typedef float (*unity_time_get_t)(void);
typedef void (*unity_time_set_t)(float value);
typedef struct UnityRefreshRate {
    unsigned int numerator;
    unsigned int denominator;
} UnityRefreshRate;
typedef int (*unity_screen_get_int_t)(void);
typedef void (*unity_screen_set_bool_t)(int value);
typedef void (*unity_screen_set_int_t)(int value);
typedef void (*unity_screen_set_resolution_bool3_t)(int width, int height, int fullscreen);
typedef void (*unity_screen_set_resolution_bool4_t)(int width, int height, int fullscreen, int preferred_refresh_rate);
typedef void (*unity_screen_set_resolution_mode4_t)(int width, int height, int mode, int preferred_refresh_rate);
typedef void (*unity_screen_set_resolution_injected_t)(int width, int height, int mode, UnityRefreshRate *preferred_refresh_rate);
typedef void *(__fastcall *singleton_get_instance_t)(void *type_info);
typedef int (__fastcall *stagecache_get_int_t)(void *stage_cache);
typedef int (__fastcall *stage_enter_exact_key_t)(void *stage_manager, unsigned int stage_key, void *method);
typedef __int64 (__fastcall *stage_set_current_cache_t)(void *stage_cache);
typedef void *(__fastcall *monster_data_by_key_t)(unsigned int monster_key);
typedef int (__fastcall *stat_value_get_t)(void *stat_source, int stat_id, void *method);
typedef __int64 (__fastcall *give_reward_item_t)(unsigned int item_key, void *callback, void *method);
typedef __int64 (__fastcall *reward_add_item_t)(unsigned int item_key, void *payload, int count, int notify, void *method);
typedef int (__fastcall *box_count_get_t)(unsigned int box_type, void *method);
typedef __int64 (__fastcall *box_reward_select_t)(void *box_table, unsigned int item_key, void *context);
typedef unsigned char (__fastcall *dict_try_get_value_t)(void *dict, unsigned int key, void **out_value, void *method);
typedef __int64 (__fastcall *gc_write_barrier_t)(void *slot, void *obj);
typedef void (__fastcall *drop_roll_process_t)(void *stage_manager, int source_id, int stage_type, int item_key, float raw_rate, int monster_type);
typedef void (__fastcall *drop_reward_callback_t)(void *target, unsigned int reward_value, void *method);
typedef float (__fastcall *drop_rate_calc_t)(void *rate_owner, float raw_rate, void *method);
typedef float (__fastcall *exp_reward_calc_t)(void *reward_owner, float base_exp, int is_boss, char is_actboss, void *method);
typedef void (__fastcall *cube_add_exp_t)(float amount, void *method);

typedef struct DropObservationContext {
    volatile LONG active;
    DWORD thread_id;
    int source_id;
    int item_key;
    int monster_type;
    float raw_rate;
    float forwarded_rate;
    float final_rate;
    int final_rate_seen;
    int reward_requested;
    int reward_add_seen;
    unsigned int reward_add_low;
    unsigned int reward_add_high;
    int reward_add_notify;
    void *reward_payload;
    unsigned int reward_item_key;
    void *reward_callback;
    void *reward_callback_invoke;
    void *reward_callback_target;
    void *reward_callback_method;
    void *reward_callback_this;
    int reward_callback_seen;
    unsigned int reward_callback_value;
    void *reward_method;
    int dropped;
} DropObservationContext;

typedef struct ChestDropStats {
    unsigned __int64 last_drop_time_ms;
    unsigned __int64 last_interval_ms;
    unsigned __int64 best_interval_1_ms;
    unsigned __int64 best_interval_2_ms;
    unsigned int last_item_key;
    unsigned int drop_count;
} ChestDropStats;

typedef void *HINTERNET_LOCAL;
typedef HINTERNET_LOCAL (WINAPI *pWinHttpOpen)(
    LPCWSTR, DWORD, LPCWSTR, LPCWSTR, DWORD);
typedef BOOL (WINAPI *pWinHttpGetIEProxyConfigForCurrentUser)(void *);
typedef BOOL (WINAPI *pWinHttpGetProxyForUrl)(
    HINTERNET_LOCAL, LPCWSTR, void *, void *);
typedef BOOL (WINAPI *pWinHttpCloseHandle)(HINTERNET_LOCAL);

typedef struct HookPatch {
    void *target;
    unsigned char original[32];
    SIZE_T size;
    int installed;
    void *trampoline;
} HookPatch;

static HMODULE g_self_module;
#ifndef TBHS_STANDALONE_DLL
static HMODULE g_real_winhttp;
#endif
static char g_base_dir[MAX_PATH];
static char g_game_dir[MAX_PATH];
static char g_log_path[MAX_PATH];
static char g_chest_stats_path[MAX_PATH];
static char g_detected_game_version[32];
static char g_config_target_game_version[32];
static char g_config_plugin_version[32];
static char g_config_plugin_subversion[16];
static volatile LONG g_initialized;

static float g_speed = SPEED_DEFAULT;
static float g_speed_min = 1.0f;
static float g_speed_max = 30.0f;
static float g_speed_step = 1.0f;
static int g_background_apply = 0;
static int g_overlay_enabled = 1;
static int g_overlay_x = 20;
static int g_overlay_y = 80;
static int g_force_game_title_bar_enabled = 1;
static DWORD g_apply_interval_ms = 1000;
static int g_auto_portal_enabled = 1;
static DWORD g_auto_portal_interval_ms = 60000;
static int g_direct_boss_enabled = 0;
static int g_actboss_boss_enabled = 0;
static int g_auto_switch_enabled = 0;
static int g_auto_switch_primary_boss_enabled = 0;
static int g_free_actboss_enter_enabled = 0;
static float g_exp_multiplier = EXP_MULTIPLIER_DEFAULT;
static float g_cube_exp_multiplier = CUBE_EXP_MULTIPLIER_DEFAULT;
static int g_drop_hooks_enabled = 1;
static int g_force_drop_roll_rate_enabled = 0;
static int g_reward_trace_hooks_enabled = 0;
static int g_force_box_reward_select_enabled = 0;
static int g_keep_boxdata_after_select_enabled = 0;
static int g_force_box_reward_select_config_enabled = 0;
static int g_keep_boxdata_after_select_config_enabled = 0;
static volatile LONG g_speed_dirty = 1;

static HMODULE g_game_assembly;
static resolve_icall_t g_resolve_icall;
static unity_time_get_t g_real_get_delta_time;
static unity_time_get_t g_real_get_time_scale;
static unity_time_set_t g_real_set_time_scale;
static unity_screen_get_int_t g_screen_get_width;
static unity_screen_get_int_t g_screen_get_height;
static unity_screen_set_bool_t g_screen_set_fullscreen;
static unity_screen_set_int_t g_screen_set_fullscreen_mode;
static unity_screen_set_resolution_bool3_t g_screen_set_resolution_bool3;
static unity_screen_set_resolution_bool4_t g_screen_set_resolution_bool4;
static unity_screen_set_resolution_mode4_t g_screen_set_resolution_mode4;
static unity_screen_set_resolution_injected_t g_screen_set_resolution_injected;
static DWORD g_last_windowed_apply_tick;
static DWORD g_game_thread_id;
static int g_windowed_logged;

static HookPatch g_hook_delta_time;
static HookPatch g_hook_get_time_scale;
static HookPatch g_hook_set_time_scale;
#if ENABLE_DROP_RATE_BOOST
static HookPatch g_hook_normal_drop_rate_calc;
static HookPatch g_hook_boss_drop_rate_calc;
#endif
static HookPatch g_hook_give_reward_item;
static HookPatch g_hook_reward_add_item;
static HookPatch g_hook_box_count_get;
static HookPatch g_hook_box_reward_select;
static HookPatch g_hook_drop_roll_process;
static HookPatch g_hook_normal_drop_rate_observer;
static HookPatch g_hook_boss_drop_rate_observer;
static HookPatch g_hook_exp_reward_calc;
static HookPatch g_hook_cube_add_exp;
static HWND g_overlay_hwnd;
static HWND g_overlay_label;
static HWND g_overlay_exp_multiplier_label;
static HWND g_overlay_cube_multiplier_label;
static HWND g_overlay_boss_button;
static HWND g_overlay_actboss_button;
static HWND g_overlay_auto_switch_button;
static HWND g_overlay_lock_button;
static HWND g_overlay_lock_interval_label;
static HWND g_overlay_lock_stage_label;
static HWND g_overlay_chest_intervals_label;
static HFONT g_overlay_font;
static HFONT g_overlay_font_bold;
static HBRUSH g_overlay_bg_brush;
static HBRUSH g_overlay_panel_brush;
static HBRUSH g_overlay_panel_2_brush;
static HBRUSH g_overlay_button_brush;
static HBRUSH g_overlay_button_hot_brush;
static HBRUSH g_overlay_button_active_brush;
static HBRUSH g_overlay_border_brush;
static HBRUSH g_overlay_accent_brush;
static HPEN g_overlay_border_pen;
static HPEN g_overlay_accent_pen;
static HWND g_game_hwnd;
static int g_overlay_user_moved;
static int g_overlay_dragging;
static DWORD g_last_auto_portal_tick;
static DWORD g_last_auto_stage_drift_tick;
static int g_auto_restart_locked;
static volatile LONG g_auto_restart_request;
static int g_auto_restart_stage_key;
static int g_auto_restart_enter_key;
static int g_auto_restart_act;
static int g_auto_restart_difficulty;
static int g_auto_restart_stage_type;
static int g_auto_restart_stage_no;
static volatile LONG g_auto_switch_waiting_for;
static unsigned __int64 g_auto_switch_wait_started_ms;
static int g_direct_boss_patch_applied;
static int g_free_actboss_enter_patch_applied;
static HookPatch g_hook_stagecache_jgm;
static give_reward_item_t g_real_give_reward_item;
static reward_add_item_t g_real_reward_add_item;
static box_count_get_t g_real_box_count_get;
static box_reward_select_t g_real_box_reward_select;
static drop_roll_process_t g_real_drop_roll_process;
static drop_reward_callback_t g_real_drop_reward_callback;
static drop_rate_calc_t g_real_normal_drop_rate_calc;
static drop_rate_calc_t g_real_boss_drop_rate_calc;
static exp_reward_calc_t g_real_exp_reward_calc;
static cube_add_exp_t g_real_cube_add_exp;
static void *g_cached_boxdata_by_type[3];
static unsigned int g_cached_boxdata_item_by_type[3];
static DropObservationContext g_drop_observation;
static volatile LONG g_drop_log_spin;
static volatile LONG g_drop_log_version;
static char g_drop_log_lines[OVERLAY_LOG_LINE_COUNT][OVERLAY_LOG_LINE_SIZE];
static int g_drop_log_next;
static int g_drop_log_count;
static ChestDropStats g_normal_chest_stats;
static ChestDropStats g_boss_chest_stats;
static volatile LONG g_chest_interval_version;
static volatile LONG g_exp_reward_call_count;
static DWORD g_last_exp_reward_log_tick;
static volatile LONG g_cube_exp_call_count;
static volatile LONG g_cube_exp_call_guard;
static DWORD g_last_cube_exp_log_tick;
static RECT g_previous_overlay_rect;
static int g_previous_overlay_position_valid;
static volatile LONG g_closed_overlay_count;

static const unsigned char k_original_give_reward[] = {
    0x48, 0x89, 0x5C, 0x24, 0x08,
    0x48, 0x89, 0x74, 0x24, 0x18,
    0x48, 0x89, 0x54, 0x24, 0x10
};
static const unsigned char k_original_reward_add[] = {
    0x48, 0x89, 0x6C, 0x24, 0x10,
    0x48, 0x89, 0x74, 0x24, 0x18,
    0x48, 0x89, 0x7C, 0x24, 0x20
};
static const unsigned char k_original_reward_capacity_branch[] = {
    0x0F, 0x84, 0x95, 0x01, 0x00, 0x00
};
static const unsigned char k_original_box_count[] = {
    0x40, 0x53,
    0x48, 0x83, 0xEC, 0x20,
    0x80, 0x3D, 0xDE, 0x7B, 0x82, 0x05, 0x00,
    0x48, 0x63, 0xD9
};
static const unsigned char k_original_box_reward_select[] = {
    0x48, 0x89, 0x5C, 0x24, 0x10,
    0x56,
    0x48, 0x83, 0xEC, 0x40,
    0x80, 0x3D, 0x24, 0xEB, 0x7C, 0x05, 0x00
};
static const unsigned char k_original_drop_roll[] = {
    0x48, 0x89, 0x5C, 0x24, 0x08,
    0x48, 0x89, 0x6C, 0x24, 0x10,
    0x48, 0x89, 0x74, 0x24, 0x18,
    0x48, 0x89, 0x7C, 0x24, 0x20
};
static const unsigned char k_original_drop_rate_calc[] = {
    0x40, 0x53,
    0x48, 0x83, 0xEC, 0x40,
    0x48, 0x83, 0x79, 0x20, 0x00,
    0x48, 0x8B, 0xD9
};
static const unsigned char k_original_exp_reward_calc[] = {
    0x48, 0x83, 0xEC, 0x38,
    0x48, 0x83, 0x79, 0x20, 0x00,
    0x0F, 0x29, 0x74, 0x24, 0x20
};
static const unsigned char k_original_cube_add_exp[] = {
    0x48, 0x83, 0xEC, 0x78,
    0x80, 0x3D, 0x98, 0x08, 0x8A, 0x05, 0x00,
    0x0F, 0x29, 0x74, 0x24, 0x60
};
static const unsigned char k_original_stagecache_jgm[] = {
    0x40, 0x53,
    0x48, 0x83, 0xEC, 0x30,
    0x80, 0x3D, 0x44, 0x13, 0x81, 0x05
};
static const unsigned char k_original_legacy_bad_stage_manager_enter_prefix[] = {
    0x48, 0x89, 0x5C, 0x24, 0x10,
    0x56,
    0x48, 0x83, 0xEC, 0x30,
    0x80, 0x3D
};
static void *mem_copy_local(void *dst, const void *src, SIZE_T n)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    for (SIZE_T i = 0; i < n; i++) d[i] = s[i];
    return dst;
}

static int mem_equal_local(const void *left, const void *right, SIZE_T n)
{
    const unsigned char *a = (const unsigned char *)left;
    const unsigned char *b = (const unsigned char *)right;
    for (SIZE_T i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

static char *find_last_char(char *s, char a, char b)
{
    char *last = NULL;
    for (; *s; s++) {
        if (*s == a || *s == b) last = s;
    }
    return last;
}

static char *find_char(char *s, char c)
{
    for (; *s; s++) {
        if (*s == c) return s;
    }
    return NULL;
}

static int starts_with_local(const char *s, const char *prefix)
{
    while (*prefix) {
        if (*s++ != *prefix++) return 0;
    }
    return 1;
}

static int parse_int_local(const char *s)
{
    int sign = 1;
    int value = 0;
    while (*s == ' ' || *s == '\t') s++;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9') {
        value = value * 10 + (*s - '0');
        s++;
    }
    return value * sign;
}

static unsigned __int64 parse_u64_local(const char *s)
{
    unsigned __int64 value = 0;
    while (*s == ' ' || *s == '\t') s++;
    while (*s >= '0' && *s <= '9') {
        value = value * 10ULL + (unsigned __int64)(*s - '0');
        s++;
    }
    return value;
}

static void format_u64_local(char *buf, int buflen, unsigned __int64 value)
{
    char tmp[32];
    int pos = 0;
    int out = 0;

    if (buflen <= 0) return;
    if (!value) {
        lstrcpynA(buf, "0", buflen);
        return;
    }
    while (value && pos < (int)sizeof(tmp)) {
        tmp[pos++] = (char)('0' + (value % 10ULL));
        value /= 10ULL;
    }
    while (pos > 0 && out < buflen - 1) {
        buf[out++] = tmp[--pos];
    }
    buf[out] = 0;
}

static float parse_float_local(const char *s)
{
    int sign = 1;
    float value = 0.0f;
    float scale = 0.1f;
    while (*s == ' ' || *s == '\t') s++;
    if (*s == '-') {
        sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9') {
        value = value * 10.0f + (float)(*s - '0');
        s++;
    }
    if (*s == '.') {
        s++;
        while (*s >= '0' && *s <= '9') {
            value += (float)(*s - '0') * scale;
            scale *= 0.1f;
            s++;
        }
    }
    return sign > 0 ? value : -value;
}

static int speed_x100(void)
{
    int v = (int)(g_speed * 100.0f + 0.5f);
    return v < 0 ? 0 : v;
}

static float clamp_exp_multiplier(float value)
{
    if (value < 1.0f) return 1.0f;
    if (value > 10.0f) return 10.0f;
    return value;
}

static int multiplier_x100(float value)
{
    int v = (int)(value * 100.0f + 0.5f);
    return v < 0 ? 0 : v;
}

static int float_x10000(float value)
{
    int scaled;
    if (value >= 0.0f) {
        scaled = (int)(value * 10000.0f + 0.5f);
    } else {
        scaled = (int)(value * 10000.0f - 0.5f);
    }
    return scaled;
}

static int percent_value_x100(float value)
{
    return float_x10000(value) / 100;
}

static int memory_range_readable(const void *ptr, SIZE_T bytes)
{
    MEMORY_BASIC_INFORMATION mbi;
    uintptr_t start = (uintptr_t)ptr;
    uintptr_t end = start + bytes;
    uintptr_t region_end;
    DWORD protect;

    if (!ptr || end < start) return 0;
    if (!VirtualQuery(ptr, &mbi, sizeof(mbi))) return 0;
    if (mbi.State != MEM_COMMIT) return 0;
    protect = mbi.Protect & 0xFF;
    if (protect == PAGE_NOACCESS || protect == PAGE_EXECUTE) return 0;
    region_end = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
    return end <= region_end;
}

static void log_line(const char *fmt, ...);
static void trim(char *s);
static void auto_switch_on_chest_drop(unsigned int box_type);
static void save_config(void);

static const char *box_type_name(unsigned int box_type)
{
    switch (box_type) {
    case 0: return "normal";
    case 1: return "boss";
    case 2: return "actboss";
    default: return "unknown";
    }
}

static int item_key_to_box_type(unsigned int item_key, unsigned int *box_type)
{
    if (item_key >= 910000 && item_key <= 919999) {
        *box_type = 0;
        return 1;
    }
    if (item_key >= 920000 && item_key <= 929999) {
        *box_type = 1;
        return 1;
    }
    if (item_key >= 930000 && item_key <= 939999) {
        *box_type = 2;
        return 1;
    }
    return 0;
}

static int auto_portal_interval_seconds(void)
{
    return (int)((g_auto_portal_interval_ms + 500) / 1000);
}

static int auto_portal_remaining_seconds(void)
{
    DWORD now;
    DWORD elapsed;
    DWORD remaining;

    if (!g_auto_restart_locked || !g_last_auto_portal_tick) return -1;
    now = GetTickCount();
    elapsed = now - g_last_auto_portal_tick;
    if (elapsed >= g_auto_portal_interval_ms) return 0;
    remaining = g_auto_portal_interval_ms - elapsed;
    return (int)((remaining + 999) / 1000);
}

static void set_auto_portal_interval_seconds(int seconds)
{
    if (seconds < (int)(AUTO_PORTAL_INTERVAL_MIN_MS / 1000)) {
        seconds = (int)(AUTO_PORTAL_INTERVAL_MIN_MS / 1000);
    }
    if (seconds > (int)(AUTO_PORTAL_INTERVAL_MAX_MS / 1000)) {
        seconds = (int)(AUTO_PORTAL_INTERVAL_MAX_MS / 1000);
    }
    g_auto_portal_interval_ms = (DWORD)seconds * 1000;
    log_line("auto restart interval set by overlay: %ds", seconds);
    save_config();
}

static void adjust_auto_portal_interval_seconds(int delta_seconds)
{
    set_auto_portal_interval_seconds(auto_portal_interval_seconds() +
                                     delta_seconds);
}

static void format_elapsed_interval_u64(char *buf,
                                        int buflen,
                                        unsigned __int64 interval_ms)
{
    char value[32];

    if (buflen <= 0) return;
    if (!interval_ms) {
        lstrcpynA(buf, "--", buflen);
        return;
    }
    format_u64_local(value, sizeof(value), (interval_ms + 500ULL) / 1000ULL);
    lstrcpynA(buf, value, buflen);
    if (lstrlenA(buf) < buflen - 1) {
        lstrcatA(buf, "s");
    }
}

static unsigned __int64 current_filetime_ms(void)
{
    FILETIME ft;
    unsigned __int64 value;

    GetSystemTimeAsFileTime(&ft);
    value = ((unsigned __int64)ft.dwHighDateTime << 32) |
            (unsigned __int64)ft.dwLowDateTime;
    return value / 10000ULL;
}

static ChestDropStats *chest_stats_for_box_type(unsigned int box_type)
{
    if (box_type == 0) return &g_normal_chest_stats;
    if (box_type == 1) return &g_boss_chest_stats;
    return NULL;
}

static void update_best_chest_intervals(ChestDropStats *stats,
                                        unsigned __int64 interval_ms)
{
    if (!stats || !interval_ms) return;
    if (!stats->best_interval_1_ms ||
        interval_ms < stats->best_interval_1_ms) {
        stats->best_interval_2_ms = stats->best_interval_1_ms;
        stats->best_interval_1_ms = interval_ms;
        return;
    }
    if (!stats->best_interval_2_ms ||
        interval_ms < stats->best_interval_2_ms) {
        stats->best_interval_2_ms = interval_ms;
    }
}

static void append_text_local(char *buf, int buflen, const char *text)
{
    int len;
    int room;

    if (!buf || buflen <= 0 || !text) return;
    len = lstrlenA(buf);
    if (len >= buflen - 1) return;
    room = buflen - len;
    lstrcpynA(buf + len, text, room);
}

static void append_u64_line(char *buf,
                            int buflen,
                            const char *key,
                            unsigned __int64 value)
{
    char number[32];

    append_text_local(buf, buflen, key);
    append_text_local(buf, buflen, "=");
    format_u64_local(number, sizeof(number), value);
    append_text_local(buf, buflen, number);
    append_text_local(buf, buflen, "\r\n");
}

static void append_int_line(char *buf, int buflen, const char *key, int value)
{
    char line[96];

    wsprintfA(line, "%s=%d\r\n", key, value);
    line[sizeof(line) - 1] = 0;
    append_text_local(buf, buflen, line);
}

static void append_float_line(char *buf, int buflen, const char *key, float value)
{
    char line[96];
    int scaled = multiplier_x100(value);

    if (scaled % 100 == 0) {
        wsprintfA(line, "%s=%d.0\r\n", key, scaled / 100);
    } else if (scaled % 10 == 0) {
        wsprintfA(line, "%s=%d.%d\r\n", key, scaled / 100, (scaled % 100) / 10);
    } else {
        wsprintfA(line, "%s=%d.%02d\r\n", key, scaled / 100, scaled % 100);
    }
    line[sizeof(line) - 1] = 0;
    append_text_local(buf, buflen, line);
}

static void append_chest_stats_lines(char *buf,
                                     int buflen,
                                     const char *prefix,
                                     const ChestDropStats *stats)
{
    char key[64];

    wsprintfA(key, "%s_last_time_ms", prefix);
    append_u64_line(buf, buflen, key, stats->last_drop_time_ms);
    wsprintfA(key, "%s_last_interval_ms", prefix);
    append_u64_line(buf, buflen, key, stats->last_interval_ms);
    wsprintfA(key, "%s_best1_ms", prefix);
    append_u64_line(buf, buflen, key, stats->best_interval_1_ms);
    wsprintfA(key, "%s_best2_ms", prefix);
    append_u64_line(buf, buflen, key, stats->best_interval_2_ms);
    wsprintfA(key, "%s_last_item", prefix);
    append_u64_line(buf, buflen, key,
                    (unsigned __int64)stats->last_item_key);
    wsprintfA(key, "%s_drop_count", prefix);
    append_u64_line(buf, buflen, key,
                    (unsigned __int64)stats->drop_count);
}

static void save_chest_stats(void)
{
    char buf[1024];
    HANDLE file;
    DWORD written = 0;

    if (!g_chest_stats_path[0]) return;
    buf[0] = 0;
    append_text_local(buf, sizeof(buf), "# TaskBarHero chest drop stats v1\r\n");
    append_chest_stats_lines(buf, sizeof(buf), "normal", &g_normal_chest_stats);
    append_chest_stats_lines(buf, sizeof(buf), "boss", &g_boss_chest_stats);

    file = CreateFileA(g_chest_stats_path, GENERIC_WRITE, FILE_SHARE_READ,
                       NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        log_line("chest stats save failed: error=%lu", GetLastError());
        return;
    }
    WriteFile(file, buf, (DWORD)lstrlenA(buf), &written, NULL);
    CloseHandle(file);
}

static void apply_chest_stats_value(const char *key,
                                    unsigned __int64 value)
{
    ChestDropStats *stats = NULL;
    const char *field = NULL;

    if (starts_with_local(key, "normal_")) {
        stats = &g_normal_chest_stats;
        field = key + 7;
    } else if (starts_with_local(key, "boss_")) {
        stats = &g_boss_chest_stats;
        field = key + 5;
    }
    if (!stats || !field) return;

    if (lstrcmpiA(field, "last_time_ms") == 0) {
        stats->last_drop_time_ms = value;
    } else if (lstrcmpiA(field, "last_interval_ms") == 0) {
        stats->last_interval_ms = value;
    } else if (lstrcmpiA(field, "best1_ms") == 0) {
        stats->best_interval_1_ms = value;
    } else if (lstrcmpiA(field, "best2_ms") == 0) {
        stats->best_interval_2_ms = value;
    } else if (lstrcmpiA(field, "last_item") == 0) {
        stats->last_item_key = (unsigned int)value;
    } else if (lstrcmpiA(field, "drop_count") == 0) {
        stats->drop_count = (unsigned int)value;
    }
}

static void load_chest_stats(void)
{
    HANDLE file;
    char buf[4096];
    DWORD read = 0;
    char *cur;

    if (!g_chest_stats_path[0]) return;
    file = CreateFileA(g_chest_stats_path, GENERIC_READ, FILE_SHARE_READ,
                       NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        save_chest_stats();
        log_line("chest stats initialized: %s", g_chest_stats_path);
        return;
    }
    if (!ReadFile(file, buf, sizeof(buf) - 1, &read, NULL)) read = 0;
    CloseHandle(file);
    buf[read] = 0;

    cur = buf;
    while (*cur) {
        char line[160];
        int pos = 0;
        char *eq;

        while (*cur && *cur != '\n' && pos < (int)sizeof(line) - 1) {
            line[pos++] = *cur++;
        }
        while (*cur && *cur != '\n') cur++;
        if (*cur == '\n') cur++;
        line[pos] = 0;
        trim(line);
        if (!line[0] || line[0] == '#' || line[0] == ';') continue;
        eq = find_char(line, '=');
        if (!eq) continue;
        *eq++ = 0;
        trim(line);
        trim(eq);
        apply_chest_stats_value(line, parse_u64_local(eq));
    }

    log_line("chest stats loaded: normal_count=%u boss_count=%u",
             g_normal_chest_stats.drop_count,
             g_boss_chest_stats.drop_count);
    InterlockedIncrement(&g_chest_interval_version);
}

static void record_chest_drop_interval(unsigned int item_key)
{
    unsigned int box_type = 0;
    ChestDropStats *stats;
    unsigned __int64 now_ms;
    char last_text[24];
    char best1_text[24];
    char best2_text[24];

    if (!item_key_to_box_type(item_key, &box_type)) return;
    stats = chest_stats_for_box_type(box_type);
    if (!stats) return;

    now_ms = current_filetime_ms();
    if (stats->last_drop_time_ms && now_ms > stats->last_drop_time_ms) {
        stats->last_interval_ms = now_ms - stats->last_drop_time_ms;
        update_best_chest_intervals(stats, stats->last_interval_ms);
        format_elapsed_interval_u64(last_text, sizeof(last_text),
                                    stats->last_interval_ms);
        format_elapsed_interval_u64(best1_text, sizeof(best1_text),
                                    stats->best_interval_1_ms);
        format_elapsed_interval_u64(best2_text, sizeof(best2_text),
                                    stats->best_interval_2_ms);
        log_line("chest drop interval: type=%s item=%u last=%s best=%s/%s count=%u",
                 box_type_name(box_type), item_key,
                 last_text, best1_text, best2_text,
                 stats->drop_count + 1);
    } else {
        log_line("chest drop observed: type=%s item=%u",
                 box_type_name(box_type),
                 item_key);
    }
    stats->last_drop_time_ms = now_ms;
    stats->last_item_key = item_key;
    stats->drop_count++;
    save_chest_stats();
    InterlockedIncrement(&g_chest_interval_version);
    auto_switch_on_chest_drop(box_type);
}

static void set_speed_value(float speed)
{
    if (speed < g_speed_min) speed = g_speed_min;
    if (speed > g_speed_max) speed = g_speed_max;
    g_speed = speed;
    InterlockedExchange(&g_speed_dirty, 1);
}

static void format_speed_label(char *buf, int buflen)
{
    int sx = speed_x100();
    if (sx % 100 == 0) {
        wsprintfA(buf, "%d", sx / 100);
    } else if (sx % 10 == 0) {
        wsprintfA(buf, "%d.%d", sx / 100, (sx % 100) / 10);
    } else {
        wsprintfA(buf, "%d.%02d", sx / 100, sx % 100);
    }
    buf[buflen - 1] = 0;
}

static void log_line(const char *fmt, ...)
{
    char line[1024];
    char final_line[1200];
    va_list ap;
    va_start(ap, fmt);
    wvsprintfA(line, fmt, ap);
    line[sizeof(line) - 1] = 0;
    va_end(ap);

    OutputDebugStringA("[TaskBarHeroSpeed] ");
    OutputDebugStringA(line);
    OutputDebugStringA("\n");

    if (g_log_path[0]) {
        HANDLE file = CreateFileA(g_log_path, FILE_APPEND_DATA, FILE_SHARE_READ,
                                  NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (file != INVALID_HANDLE_VALUE) {
            SYSTEMTIME st;
            DWORD written = 0;
            GetLocalTime(&st);
            wsprintfA(final_line, "%04u-%02u-%02u %02u:%02u:%02u.%03u %s\r\n",
                      st.wYear, st.wMonth, st.wDay,
                      st.wHour, st.wMinute, st.wSecond, st.wMilliseconds,
                      line);
            WriteFile(file, final_line, (DWORD)lstrlenA(final_line), &written, NULL);
            CloseHandle(file);
        }
    }
}

static void lock_drop_log(void)
{
    while (InterlockedCompareExchange(&g_drop_log_spin, 1, 0) != 0) {
        Sleep(0);
    }
}

static void unlock_drop_log(void)
{
    InterlockedExchange(&g_drop_log_spin, 0);
}

static void append_overlay_log_line(const char *line)
{
    lock_drop_log();
    lstrcpynA(g_drop_log_lines[g_drop_log_next], line, OVERLAY_LOG_LINE_SIZE);
    g_drop_log_next = (g_drop_log_next + 1) % OVERLAY_LOG_LINE_COUNT;
    if (g_drop_log_count < OVERLAY_LOG_LINE_COUNT) g_drop_log_count++;
    unlock_drop_log();
    InterlockedIncrement(&g_drop_log_version);
}

static void append_overlay_event(const char *fmt, ...)
{
    SYSTEMTIME st;
    char message[OVERLAY_LOG_LINE_SIZE];
    char line[OVERLAY_LOG_LINE_SIZE];
    va_list ap;

    va_start(ap, fmt);
    wvsprintfA(message, fmt, ap);
    message[sizeof(message) - 1] = 0;
    va_end(ap);

    GetLocalTime(&st);
    wsprintfA(line, "%02u:%02u:%02u %s",
              st.wHour, st.wMinute, st.wSecond, message);
    line[sizeof(line) - 1] = 0;
    append_overlay_log_line(line);
}

static int display_stage_no_from_key(int stage_key, int stage_no)
{
    int key_stage_no = stage_key % 100;
    if (stage_no > 0) return stage_no;
    if (key_stage_no > 0) return key_stage_no;
    return stage_no;
}

static int il2cpp_list_size_local(void *list);
static void *il2cpp_list_get_local(void *list, int index);
static void *get_stage_cache_list(uintptr_t base);

static int find_stage_enter_key_for_stage_key(uintptr_t base,
                                              int act,
                                              int difficulty,
                                              int stage_type,
                                              int stage_key,
                                              int *out_enter_key,
                                              int *out_previous_stage_no)
{
    stagecache_get_int_t get_act = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_ACT);
    stagecache_get_int_t get_difficulty = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_DIFFICULTY);
    stagecache_get_int_t get_type = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_TYPE);
    stagecache_get_int_t get_stage_no = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_STAGE_NO);
    stagecache_get_int_t get_key = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_KEY);
    void *stage_list;
    int count;

    if (!out_enter_key) return 0;
    *out_enter_key = 0;
    if (out_previous_stage_no) *out_previous_stage_no = 0;

    stage_list = get_stage_cache_list(base);
    count = il2cpp_list_size_local(stage_list);
    for (int i = 1; i < count; i++) {
        void *candidate = il2cpp_list_get_local(stage_list, i);
        void *previous = il2cpp_list_get_local(stage_list, i - 1);

        if (!candidate || !previous) continue;
        if (get_act(candidate) != act) continue;
        if (get_difficulty(candidate) != difficulty) continue;
        if (get_type(candidate) != stage_type) continue;
        if (get_key(candidate) != stage_key) continue;
        if (get_act(previous) != act) continue;
        if (get_difficulty(previous) != difficulty) continue;
        if (get_type(previous) != stage_type) continue;

        *out_enter_key = get_key(previous);
        if (out_previous_stage_no) *out_previous_stage_no = get_stage_no(previous);
        return *out_enter_key > 0;
    }
    return 0;
}

static void *find_stage_cache_by_stage_key(uintptr_t base,
                                           int act,
                                           int difficulty,
                                           int stage_type,
                                           int stage_key)
{
    stagecache_get_int_t get_act = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_ACT);
    stagecache_get_int_t get_difficulty = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_DIFFICULTY);
    stagecache_get_int_t get_type = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_TYPE);
    stagecache_get_int_t get_key = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_KEY);
    void *stage_list = get_stage_cache_list(base);
    int count = il2cpp_list_size_local(stage_list);

    for (int i = 0; i < count; i++) {
        void *candidate = il2cpp_list_get_local(stage_list, i);

        if (!candidate) continue;
        if (get_key(candidate) != stage_key) continue;
        if (get_act(candidate) != act) continue;
        if (get_difficulty(candidate) != difficulty) continue;
        if (get_type(candidate) != stage_type) continue;
        return candidate;
    }
    return NULL;
}

static void append_drop_observation(int source_id,
                                    int monster_type,
                                    float raw_rate,
                                    float final_rate,
                                    int outcome,
                                    unsigned int reward_item_key)
{
    static DWORD last_file_log_tick;
    const char *kind = monster_type ? "BOSS" : "MON";
    const char *outcome_name = outcome == DROP_OUTCOME_DROP ? "ADD_OK" :
                               outcome == DROP_OUTCOME_BLOCKED ? "BLOCKED" :
                               "MISS";
    int raw_percent_x100 = percent_value_x100(raw_rate);
    int final_percent_x100 = percent_value_x100(final_rate);
    DWORD now = GetTickCount();

    if (raw_percent_x100 < 0) raw_percent_x100 = 0;
    if (final_percent_x100 < 0) final_percent_x100 = 0;
    if (outcome == DROP_OUTCOME_DROP) {
        record_chest_drop_interval(reward_item_key);
    }

    if (g_reward_trace_hooks_enabled &&
        (outcome == DROP_OUTCOME_DROP ||
         !last_file_log_tick || now - last_file_log_tick >= 1000)) {
        if (outcome == DROP_OUTCOME_DROP) {
            log_line("drop outcome: type=%s source=%d raw=%d.%02d%% final=%d.%02d%% outcome=%s reward_item=%u add_high=0x%08lX add_low=0x%08lX notify=%d callback_seen=%d callback_value=%u",
                     kind, source_id,
                     raw_percent_x100 / 100, raw_percent_x100 % 100,
                     final_percent_x100 / 100, final_percent_x100 % 100,
                     outcome_name,
                     reward_item_key,
                     (unsigned long)g_drop_observation.reward_add_high,
                     (unsigned long)g_drop_observation.reward_add_low,
                     g_drop_observation.reward_add_notify,
                     g_drop_observation.reward_callback_seen,
                     g_drop_observation.reward_callback_value);
        } else {
            log_line("drop outcome: type=%s source=%d raw=%d.%02d%% final=%d.%02d%% outcome=%s reward_item=%u",
                     kind, source_id,
                     raw_percent_x100 / 100, raw_percent_x100 % 100,
                     final_percent_x100 / 100, final_percent_x100 % 100,
                     outcome_name,
                     reward_item_key);
        }
        last_file_log_tick = now;
    }
}

static void init_paths(void)
{
    char module_path[MAX_PATH];
    DWORD len = GetModuleFileNameA(g_self_module, module_path, sizeof(module_path));
    if (len == 0 || len >= sizeof(module_path)) {
        lstrcpyA(g_base_dir, ".");
    } else {
        char *slash = find_last_char(module_path, '\\', '/');
        if (slash) {
            *slash = 0;
            lstrcpynA(g_base_dir, module_path, sizeof(g_base_dir));
        } else {
            lstrcpyA(g_base_dir, ".");
        }
    }
    len = GetModuleFileNameA(NULL, module_path, sizeof(module_path));
    if (len == 0 || len >= sizeof(module_path)) {
        lstrcpyA(g_game_dir, g_base_dir);
    } else {
        char *slash = find_last_char(module_path, '\\', '/');
        if (slash) {
            *slash = 0;
            lstrcpynA(g_game_dir, module_path, sizeof(g_game_dir));
        } else {
            lstrcpyA(g_game_dir, g_base_dir);
        }
    }
    wsprintfA(g_log_path, "%s\\TaskBarHeroSpeed.log", g_base_dir);
    g_log_path[sizeof(g_log_path) - 1] = 0;
    wsprintfA(g_chest_stats_path, "%s\\TaskBarHeroChestStats.txt", g_base_dir);
    g_chest_stats_path[sizeof(g_chest_stats_path) - 1] = 0;
}

static void trim(char *s)
{
    char *p = s;
    while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;
    if (p != s) {
        char *d = s;
        while ((*d++ = *p++)) {}
    }
    int n = lstrlenA(s);
    while (n && (s[n - 1] == ' ' || s[n - 1] == '\t' ||
                 s[n - 1] == '\r' || s[n - 1] == '\n')) {
        s[--n] = 0;
    }
}

static void load_config(void)
{
    char path[MAX_PATH];
    wsprintfA(path, "%s\\TaskBarHeroSpeed.ini", g_base_dir);
    path[sizeof(path) - 1] = 0;

    HANDLE file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                              OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        int sx = speed_x100();
        log_line("config not found, using speed=%d.%02d", sx / 100, sx % 100);
        return;
    }

    char buf[4096];
    DWORD read = 0;
    if (!ReadFile(file, buf, sizeof(buf) - 1, &read, NULL)) read = 0;
    CloseHandle(file);
    buf[read] = 0;

    char *cur = buf;
    while (*cur) {
        char line[256];
        int pos = 0;
        while (*cur && *cur != '\n' && pos < (int)sizeof(line) - 1) {
            line[pos++] = *cur++;
        }
        while (*cur && *cur != '\n') cur++;
        if (*cur == '\n') cur++;
        line[pos] = 0;

        trim(line);
        if (!line[0] || line[0] == '#' || line[0] == ';') continue;

        char *eq = find_char(line, '=');
        if (!eq) continue;
        *eq++ = 0;
        trim(line);
        trim(eq);

        if (lstrcmpiA(line, "speed") == 0) {
            float v = parse_float_local(eq);
            if (v > 0.0f && v <= 100.0f) g_speed = v;
        } else if (lstrcmpiA(line, "target_game_version") == 0 ||
                   lstrcmpiA(line, "game_version") == 0) {
            lstrcpynA(g_config_target_game_version, eq,
                      sizeof(g_config_target_game_version));
        } else if (lstrcmpiA(line, "plugin_version") == 0) {
            lstrcpynA(g_config_plugin_version, eq,
                      sizeof(g_config_plugin_version));
        } else if (lstrcmpiA(line, "plugin_subversion") == 0 ||
                   lstrcmpiA(line, "plugin_build") == 0) {
            lstrcpynA(g_config_plugin_subversion, eq,
                      sizeof(g_config_plugin_subversion));
        } else if (lstrcmpiA(line, "speed_min") == 0) {
            float v = parse_float_local(eq);
            if (v > 0.0f && v <= 100.0f) g_speed_min = v;
        } else if (lstrcmpiA(line, "speed_max") == 0) {
            float v = parse_float_local(eq);
            if (v > 0.0f && v <= 100.0f) g_speed_max = v;
        } else if (lstrcmpiA(line, "speed_step") == 0) {
            float v = parse_float_local(eq);
            if (v > 0.0f && v <= 20.0f) g_speed_step = v;
        } else if (lstrcmpiA(line, "overlay") == 0) {
            g_overlay_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "overlay_x") == 0) {
            int v = parse_int_local(eq);
            if (v >= -2000 && v <= 4000) g_overlay_x = v;
        } else if (lstrcmpiA(line, "overlay_y") == 0) {
            int v = parse_int_local(eq);
            if (v >= -2000 && v <= 4000) g_overlay_y = v;
        } else if (lstrcmpiA(line, "force_game_title_bar") == 0 ||
                   lstrcmpiA(line, "force_title_bar") == 0) {
            g_force_game_title_bar_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "background_apply") == 0) {
            g_background_apply = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "apply_interval_ms") == 0) {
            int v = parse_int_local(eq);
            if (v >= 100 && v <= 60000) g_apply_interval_ms = (DWORD)v;
        } else if (lstrcmpiA(line, "auto_portal") == 0) {
            g_auto_portal_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_portal_interval_ms") == 0) {
            int v = parse_int_local(eq);
            if (v >= AUTO_PORTAL_INTERVAL_MIN_MS &&
                v <= AUTO_PORTAL_INTERVAL_MAX_MS) {
                g_auto_portal_interval_ms = (DWORD)v;
            }
        } else if (lstrcmpiA(line, "auto_portal_locked") == 0) {
            g_auto_restart_locked = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_portal_stage_key") == 0) {
            g_auto_restart_stage_key = parse_int_local(eq);
        } else if (lstrcmpiA(line, "auto_portal_enter_key") == 0) {
            g_auto_restart_enter_key = parse_int_local(eq);
        } else if (lstrcmpiA(line, "auto_portal_act") == 0) {
            g_auto_restart_act = parse_int_local(eq);
        } else if (lstrcmpiA(line, "auto_portal_difficulty") == 0) {
            g_auto_restart_difficulty = parse_int_local(eq);
        } else if (lstrcmpiA(line, "auto_portal_stage_type") == 0) {
            g_auto_restart_stage_type = parse_int_local(eq);
        } else if (lstrcmpiA(line, "auto_portal_stage_no") == 0) {
            g_auto_restart_stage_no = parse_int_local(eq);
        } else if (lstrcmpiA(line, "direct_boss") == 0) {
            g_direct_boss_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "actboss_boss") == 0) {
            g_actboss_boss_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_switch") == 0 ||
                   lstrcmpiA(line, "auto_boss_switch") == 0) {
            g_auto_switch_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "free_actboss_enter") == 0) {
            g_free_actboss_enter_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "exp_multiplier") == 0 ||
                   lstrcmpiA(line, "experience_multiplier") == 0) {
            g_exp_multiplier = clamp_exp_multiplier(parse_float_local(eq));
        } else if (lstrcmpiA(line, "cube_exp_multiplier") == 0 ||
                   lstrcmpiA(line, "cube_multiplier") == 0) {
            g_cube_exp_multiplier = clamp_exp_multiplier(parse_float_local(eq));
        } else if (lstrcmpiA(line, "drop_hooks") == 0 ||
                   lstrcmpiA(line, "drop_logging") == 0) {
            g_drop_hooks_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "force_drop_roll") == 0 ||
                   lstrcmpiA(line, "force_drop_rate") == 0) {
            g_force_drop_roll_rate_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "reward_trace_hooks") == 0 ||
                   lstrcmpiA(line, "drop_reward_hooks") == 0) {
            g_reward_trace_hooks_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "force_box_reward_select") == 0) {
            g_force_box_reward_select_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "keep_boxdata_after_select") == 0 ||
                   lstrcmpiA(line, "keep_boxdata") == 0) {
            g_keep_boxdata_after_select_enabled = parse_int_local(eq) ? 1 : 0;
        }
    }
    set_speed_value(g_speed);
    g_exp_multiplier = clamp_exp_multiplier(g_exp_multiplier);
    g_cube_exp_multiplier = clamp_exp_multiplier(g_cube_exp_multiplier);
    if (g_auto_restart_locked && g_auto_restart_stage_key <= 0) {
        g_auto_restart_locked = 0;
    }
    g_force_box_reward_select_config_enabled = g_force_box_reward_select_enabled;
    g_keep_boxdata_after_select_config_enabled = g_keep_boxdata_after_select_enabled;
    if (g_force_drop_roll_rate_enabled) {
        g_force_box_reward_select_enabled = 1;
        g_keep_boxdata_after_select_enabled = 1;
    }
    int sx = speed_x100();
    int expx = multiplier_x100(g_exp_multiplier);
    int cubex = multiplier_x100(g_cube_exp_multiplier);
    log_line("config loaded: plugin=%s.%s target_game=%s speed=%d.%02d step=%d.%02d exp=%d.%02d cube_exp=%d.%02d overlay=%d force_game_title_bar=%d background_apply=%d interval=%lu auto_portal=%d/%lu direct_boss=%d actboss_boss=%d auto_switch=%d free_actboss_enter=%d drop_hooks=%d force_drop_roll=%d reward_trace_hooks=%d force_box_reward_select=%d keep_boxdata_after_select=%d",
             g_config_plugin_version[0] ? g_config_plugin_version : TBHS_PLUGIN_VERSION,
             g_config_plugin_subversion[0] ? g_config_plugin_subversion : TBHS_PLUGIN_SUBVERSION,
             g_config_target_game_version[0] ? g_config_target_game_version : TBHS_SUPPORTED_GAME_VERSION,
             sx / 100, sx % 100,
             (int)(g_speed_step * 100.0f) / 100,
             (int)(g_speed_step * 100.0f) % 100,
             expx / 100, expx % 100,
             cubex / 100, cubex % 100,
             g_overlay_enabled, g_force_game_title_bar_enabled,
             g_background_apply, (unsigned long)g_apply_interval_ms,
             g_auto_portal_enabled, (unsigned long)g_auto_portal_interval_ms,
             g_direct_boss_enabled, g_actboss_boss_enabled,
             g_auto_switch_enabled,
             g_free_actboss_enter_enabled,
             g_drop_hooks_enabled,
             g_force_drop_roll_rate_enabled,
             g_reward_trace_hooks_enabled,
             g_force_box_reward_select_enabled,
             g_keep_boxdata_after_select_enabled);
}

static void save_config(void)
{
    char path[MAX_PATH];
    char buf[4096];
    HANDLE file;
    DWORD written = 0;

    if (!g_base_dir[0]) return;
    wsprintfA(path, "%s\\TaskBarHeroSpeed.ini", g_base_dir);
    path[sizeof(path) - 1] = 0;

    buf[0] = 0;
    append_text_local(buf, sizeof(buf), "# TaskBarHero plugin config.\r\n");
    append_text_local(buf, sizeof(buf), "# This file is updated by the overlay when settings change.\r\n");
    append_text_local(buf, sizeof(buf), "target_game_version=" TBHS_SUPPORTED_GAME_VERSION "\r\n");
    append_text_local(buf, sizeof(buf), "plugin_version=" TBHS_PLUGIN_VERSION "\r\n");
    append_text_local(buf, sizeof(buf), "plugin_subversion=" TBHS_PLUGIN_SUBVERSION "\r\n\r\n");

    append_float_line(buf, sizeof(buf), "speed", g_speed);
    append_float_line(buf, sizeof(buf), "speed_step", g_speed_step);
    append_float_line(buf, sizeof(buf), "speed_min", g_speed_min);
    append_float_line(buf, sizeof(buf), "speed_max", g_speed_max);
    append_float_line(buf, sizeof(buf), "exp_multiplier", g_exp_multiplier);
    append_float_line(buf, sizeof(buf), "cube_exp_multiplier", g_cube_exp_multiplier);
    append_text_local(buf, sizeof(buf), "\r\n");

    append_int_line(buf, sizeof(buf), "overlay", g_overlay_enabled);
    append_int_line(buf, sizeof(buf), "overlay_x", g_overlay_x);
    append_int_line(buf, sizeof(buf), "overlay_y", g_overlay_y);
    append_int_line(buf, sizeof(buf), "force_game_title_bar", g_force_game_title_bar_enabled);
    append_text_local(buf, sizeof(buf), "\r\n");

    append_int_line(buf, sizeof(buf), "auto_portal", g_auto_portal_enabled);
    append_int_line(buf, sizeof(buf), "auto_portal_interval_ms", (int)g_auto_portal_interval_ms);
    append_int_line(buf, sizeof(buf), "auto_portal_locked", g_auto_restart_locked);
    append_int_line(buf, sizeof(buf), "auto_portal_stage_key", g_auto_restart_stage_key);
    append_int_line(buf, sizeof(buf), "auto_portal_enter_key", g_auto_restart_enter_key);
    append_int_line(buf, sizeof(buf), "auto_portal_act", g_auto_restart_act);
    append_int_line(buf, sizeof(buf), "auto_portal_difficulty", g_auto_restart_difficulty);
    append_int_line(buf, sizeof(buf), "auto_portal_stage_type", g_auto_restart_stage_type);
    append_int_line(buf, sizeof(buf), "auto_portal_stage_no", g_auto_restart_stage_no);
    append_int_line(buf, sizeof(buf), "direct_boss",
                    g_auto_switch_enabled ? g_auto_switch_primary_boss_enabled : g_direct_boss_enabled);
    append_int_line(buf, sizeof(buf), "actboss_boss", g_actboss_boss_enabled);
    append_int_line(buf, sizeof(buf), "auto_switch", g_auto_switch_enabled);
    append_int_line(buf, sizeof(buf), "free_actboss_enter", g_free_actboss_enter_enabled);
    append_text_local(buf, sizeof(buf), "\r\n");

    append_int_line(buf, sizeof(buf), "drop_hooks", g_drop_hooks_enabled);
    append_int_line(buf, sizeof(buf), "force_drop_roll", g_force_drop_roll_rate_enabled);
    append_int_line(buf, sizeof(buf), "reward_trace_hooks", g_reward_trace_hooks_enabled);
    append_int_line(buf, sizeof(buf), "force_box_reward_select", g_force_box_reward_select_config_enabled);
    append_int_line(buf, sizeof(buf), "keep_boxdata_after_select", g_keep_boxdata_after_select_config_enabled);
    append_text_local(buf, sizeof(buf), "\r\n");

    append_int_line(buf, sizeof(buf), "background_apply", g_background_apply);
    append_int_line(buf, sizeof(buf), "apply_interval_ms", (int)g_apply_interval_ms);

    file = CreateFileA(path, GENERIC_WRITE, FILE_SHARE_READ, NULL,
                       CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        log_line("config save failed: error=%lu", GetLastError());
        return;
    }
    WriteFile(file, buf, (DWORD)lstrlenA(buf), &written, NULL);
    CloseHandle(file);
    log_line("config saved: %s", path);
}

static int read_first_line_file(const char *path, char *out, int out_size)
{
    HANDLE file;
    DWORD read = 0;
    int i;

    if (!out || out_size <= 0) return 0;
    out[0] = 0;
    file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) return 0;
    if (!ReadFile(file, out, (DWORD)out_size - 1, &read, NULL)) read = 0;
    CloseHandle(file);
    out[read] = 0;
    for (i = 0; out[i]; i++) {
        if (out[i] == '\r' || out[i] == '\n') {
            out[i] = 0;
            break;
        }
    }
    trim(out);
    return out[0] != 0;
}

static int validate_runtime_versions(void)
{
    char version_path[MAX_PATH];
    char message[512];
    const char *config_game =
        g_config_target_game_version[0] ?
        g_config_target_game_version :
        TBHS_SUPPORTED_GAME_VERSION;
    const char *config_plugin =
        g_config_plugin_version[0] ?
        g_config_plugin_version :
        TBHS_PLUGIN_VERSION;
    const char *config_subversion =
        g_config_plugin_subversion[0] ?
        g_config_plugin_subversion :
        TBHS_PLUGIN_SUBVERSION;

    wsprintfA(version_path, "%s\\Version.txt", g_game_dir[0] ? g_game_dir : g_base_dir);
    version_path[sizeof(version_path) - 1] = 0;
    if (!read_first_line_file(version_path,
                              g_detected_game_version,
                              sizeof(g_detected_game_version))) {
        log_line("game Version.txt not found: %s", version_path);
    }

    if (lstrcmpiA(config_game, TBHS_SUPPORTED_GAME_VERSION) != 0 ||
        lstrcmpiA(config_plugin, TBHS_PLUGIN_VERSION) != 0 ||
        lstrcmpiA(config_subversion, TBHS_PLUGIN_SUBVERSION) != 0) {
        wsprintfA(message,
                  "TaskBarHeroSpeed config version mismatch.\r\nConfig: game %s plugin %s.%s\r\nDLL: game %s plugin %s",
                  config_game,
                  config_plugin,
                  config_subversion,
                  TBHS_SUPPORTED_GAME_VERSION,
                  TBHS_PLUGIN_DISPLAY_VERSION);
        message[sizeof(message) - 1] = 0;
        log_line("%s", message);
        MessageBoxA(NULL, message, "TaskBarHeroSpeed", MB_OK | MB_ICONWARNING | MB_TOPMOST);
    }

    if (g_detected_game_version[0] &&
        lstrcmpiA(g_detected_game_version, TBHS_SUPPORTED_GAME_VERSION) != 0) {
        wsprintfA(message,
                  "TaskBarHero game version mismatch.\r\nGame: %s\r\nPlugin supports: %s\r\nHooks were not installed.",
                  g_detected_game_version,
                  TBHS_SUPPORTED_GAME_VERSION);
        message[sizeof(message) - 1] = 0;
        log_line("%s", message);
        MessageBoxA(NULL, message, "TaskBarHeroSpeed", MB_OK | MB_ICONERROR | MB_TOPMOST);
        return 0;
    }

    log_line("version check: game=%s supported=%s plugin=%s",
             g_detected_game_version[0] ? g_detected_game_version : "unknown",
             TBHS_SUPPORTED_GAME_VERSION,
             TBHS_PLUGIN_DISPLAY_VERSION);
    return 1;
}

static int write_absolute_jump(void *target, void *detour, HookPatch *hook)
{
    unsigned char patch[12];
    DWORD old_protect = 0;

    patch[0] = 0x48;
    patch[1] = 0xB8;
    mem_copy_local(&patch[2], &detour, sizeof(detour));
    patch[10] = 0xFF;
    patch[11] = 0xE0;

    hook->target = target;
    hook->size = sizeof(patch);
    mem_copy_local(hook->original, target, sizeof(patch));

    if (!VirtualProtect(target, sizeof(patch), PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }

    mem_copy_local(target, patch, sizeof(patch));
    FlushInstructionCache(GetCurrentProcess(), target, sizeof(patch));
    VirtualProtect(target, sizeof(patch), old_protect, &old_protect);
    hook->installed = 1;
    return 1;
}

static int write_absolute_jump_sized(void *target,
                                     void *detour,
                                     HookPatch *hook,
                                     SIZE_T patch_size)
{
    unsigned char patch[32];
    DWORD old_protect = 0;

    if (patch_size < 12 || patch_size > sizeof(hook->original)) {
        log_line("invalid absolute jump patch size=%lu for target=%p",
                 (unsigned long)patch_size, target);
        return 0;
    }

    for (SIZE_T i = 0; i < sizeof(patch); i++) patch[i] = 0x90;
    patch[0] = 0x48;
    patch[1] = 0xB8;
    mem_copy_local(&patch[2], &detour, sizeof(detour));
    patch[10] = 0xFF;
    patch[11] = 0xE0;

    hook->target = target;
    hook->size = patch_size;
    hook->trampoline = NULL;
    mem_copy_local(hook->original, target, patch_size);

    if (!VirtualProtect(target, patch_size, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }

    mem_copy_local(target, patch, patch_size);
    FlushInstructionCache(GetCurrentProcess(), target, patch_size);
    VirtualProtect(target, patch_size, old_protect, &old_protect);
    hook->installed = 1;
    return 1;
}

static int write_absolute_jump_with_trampoline(void *target,
                                               void *detour,
                                               HookPatch *hook,
                                               SIZE_T stolen_size,
                                               void **out_trampoline)
{
    unsigned char patch[32];
    unsigned char jump_back[12];
    unsigned char *trampoline;
    void *resume;
    DWORD old_protect = 0;

    if (stolen_size < 12 || stolen_size > sizeof(hook->original)) {
        log_line("invalid trampoline stolen size=%lu for target=%p",
                 (unsigned long)stolen_size, target);
        return 0;
    }

    trampoline = (unsigned char *)VirtualAlloc(NULL, stolen_size + sizeof(jump_back),
                                               MEM_COMMIT | MEM_RESERVE,
                                               PAGE_EXECUTE_READWRITE);
    if (!trampoline) {
        log_line("VirtualAlloc trampoline failed, error=%lu", GetLastError());
        return 0;
    }

    resume = (void *)((unsigned char *)target + stolen_size);
    mem_copy_local(trampoline, target, stolen_size);
    jump_back[0] = 0x48;
    jump_back[1] = 0xB8;
    mem_copy_local(&jump_back[2], &resume, sizeof(resume));
    jump_back[10] = 0xFF;
    jump_back[11] = 0xE0;
    mem_copy_local(trampoline + stolen_size, jump_back, sizeof(jump_back));

    for (SIZE_T i = 0; i < sizeof(patch); i++) patch[i] = 0x90;
    patch[0] = 0x48;
    patch[1] = 0xB8;
    mem_copy_local(&patch[2], &detour, sizeof(detour));
    patch[10] = 0xFF;
    patch[11] = 0xE0;

    hook->target = target;
    hook->size = stolen_size;
    hook->trampoline = trampoline;
    mem_copy_local(hook->original, target, stolen_size);

    if (!VirtualProtect(target, stolen_size, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }

    mem_copy_local(target, patch, stolen_size);
    FlushInstructionCache(GetCurrentProcess(), target, stolen_size);
    VirtualProtect(target, stolen_size, old_protect, &old_protect);
    hook->installed = 1;
    if (out_trampoline) *out_trampoline = trampoline;
    return 1;
}

static int write_one_byte(void *target, unsigned char value)
{
    DWORD old_protect = 0;
    if (!VirtualProtect(target, 1, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }
    *(unsigned char *)target = value;
    FlushInstructionCache(GetCurrentProcess(), target, 1);
    VirtualProtect(target, 1, old_protect, &old_protect);
    return 1;
}

static int write_two_bytes(void *target, unsigned char a, unsigned char b)
{
    DWORD old_protect = 0;
    unsigned char *p = (unsigned char *)target;
    if (!VirtualProtect(target, 2, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }
    p[0] = a;
    p[1] = b;
    FlushInstructionCache(GetCurrentProcess(), target, 2);
    VirtualProtect(target, 2, old_protect, &old_protect);
    return 1;
}

static int write_nops(void *target, SIZE_T size)
{
    DWORD old_protect = 0;
    SIZE_T i;
    unsigned char *p = (unsigned char *)target;

    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }
    for (i = 0; i < size; i++) p[i] = 0x90;
    FlushInstructionCache(GetCurrentProcess(), target, size);
    VirtualProtect(target, size, old_protect, &old_protect);
    return 1;
}

static int write_code_bytes(void *target, const unsigned char *bytes, SIZE_T size)
{
    DWORD old_protect = 0;

    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }
    mem_copy_local(target, bytes, size);
    FlushInstructionCache(GetCurrentProcess(), target, size);
    VirtualProtect(target, size, old_protect, &old_protect);
    return 1;
}

static int is_absolute_jump_local(const unsigned char *target)
{
    return target[0] == 0x48 &&
           target[1] == 0xB8 &&
           target[10] == 0xFF &&
           target[11] == 0xE0;
}

static int restore_original_if_abs_jump(unsigned char *target,
                                        const unsigned char *original,
                                        SIZE_T size,
                                        const char *label)
{
    DWORD old_protect = 0;

    if (!is_absolute_jump_local(target)) return 1;
    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return 0;
    }
    mem_copy_local(target, original, size);
    FlushInstructionCache(GetCurrentProcess(), target, size);
    VirtualProtect(target, size, old_protect, &old_protect);
    log_line("restored previous %s hook", label);
    return 1;
}

static void apply_direct_boss_patch(void)
{
    if (!g_game_assembly) return;
    if (RVA_DIRECT_BOSS_BRANCH == 0) {
        if (g_direct_boss_enabled) {
            log_line("direct boss unavailable for this game build");
        }
        return;
    }

    unsigned char *branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_DIRECT_BOSS_BRANCH);
    unsigned char want = g_direct_boss_enabled ? 0xEB : 0x75;
    unsigned char current = *branch;

    if (current == want) {
        g_direct_boss_patch_applied = g_direct_boss_enabled;
        return;
    }
    if (current != 0x75 && current != 0xEB) {
        log_line("direct boss branch unexpected byte at %p: 0x%02X", branch, current);
        return;
    }
    if (write_one_byte(branch, want)) {
        g_direct_boss_patch_applied = g_direct_boss_enabled;
        log_line("direct boss %s", g_direct_boss_enabled ? "enabled" : "disabled");
    }
}

static void apply_drop_cooldown_bypass_patch(void)
{
    unsigned char *branch;

    if (!g_game_assembly) return;
    branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_DROP_COOLDOWN_SKIP_BRANCH);
    if (branch[0] == 0x90 && branch[1] == 0x90) return;
    if (branch[0] != 0x77 || branch[1] != 0x55) {
        log_line("drop cooldown branch unexpected byte at %p: %02X %02X",
                 branch, branch[0], branch[1]);
        return;
    }
    if (write_two_bytes(branch, 0x90, 0x90)) {
        log_line("drop cooldown bypass enabled");
    }
}

static void restore_drop_cooldown_bypass_patch(void)
{
    unsigned char *branch;

    if (!g_game_assembly) return;
    branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_DROP_COOLDOWN_SKIP_BRANCH);
    if (branch[0] == 0x77 && branch[1] == 0x55) return;
    if (branch[0] != 0x90 || branch[1] != 0x90) {
        log_line("drop cooldown restore skipped, unexpected byte at %p: %02X %02X",
                 branch, branch[0], branch[1]);
        return;
    }
    if (write_two_bytes(branch, 0x77, 0x55)) {
        log_line("drop cooldown bypass disabled");
    }
}

static void TBHS_UNUSED apply_reward_item_config_early_return_bypass_patch(void)
{
    unsigned char *branch;

    if (!g_game_assembly) return;
    branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH);
    if (branch[0] == 0x90 && branch[1] == 0x90 && branch[2] == 0x90 &&
        branch[3] == 0x90 && branch[4] == 0x90 && branch[5] == 0x90) {
        return;
    }
    if (branch[0] != 0x0F || branch[1] != 0x85) {
        log_line("reward item config branch unexpected byte at %p: %02X %02X",
                 branch, branch[0], branch[1]);
        return;
    }
    if (write_nops(branch, 6)) {
        log_line("reward item config early-return bypass enabled");
    }
}

static void TBHS_UNUSED apply_reward_item_capacity_bypass_patch(void)
{
    unsigned char *branch;

    if (!g_game_assembly) return;
    branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH);
    if (branch[0] == 0x90 && branch[1] == 0x90 && branch[2] == 0x90 &&
        branch[3] == 0x90 && branch[4] == 0x90 && branch[5] == 0x90) {
        return;
    }
    if (branch[0] != 0x0F || branch[1] != 0x84) {
        log_line("reward item capacity branch unexpected byte at %p: %02X %02X",
                 branch, branch[0], branch[1]);
        return;
    }
    if (write_nops(branch, 6)) {
        log_line("reward item capacity bypass enabled");
    }
}

static void restore_reward_item_capacity_bypass_patch(void)
{
    unsigned char *branch;

    if (!g_game_assembly) return;
    branch = (unsigned char *)((uintptr_t)g_game_assembly + RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH);
    if (mem_equal_local(branch,
                        k_original_reward_capacity_branch,
                        sizeof(k_original_reward_capacity_branch))) {
        return;
    }
    if (branch[0] != 0x90 || branch[1] != 0x90 ||
        branch[2] != 0x90 || branch[3] != 0x90 ||
        branch[4] != 0x90 || branch[5] != 0x90) {
        log_line("reward item capacity restore skipped, unexpected bytes at %p: %02X %02X",
                 branch, branch[0], branch[1]);
        return;
    }
    if (write_code_bytes(branch,
                         k_original_reward_capacity_branch,
                         sizeof(k_original_reward_capacity_branch))) {
        log_line("reward item capacity bypass disabled");
    }
}

static void apply_free_actboss_enter_patch(void)
{
    if (!g_free_actboss_enter_enabled) {
        g_free_actboss_enter_patch_applied = 0;
        log_line("free actboss enter disabled");
        return;
    }
    g_free_actboss_enter_enabled = 0;
    g_free_actboss_enter_patch_applied = 0;
    log_line("free actboss enter unavailable for this game build");
}

static void restore_mistaken_exp_reward_hook(uintptr_t base)
{
    unsigned char *target = (unsigned char *)(base + RVA_EXP_REWARD_CALC);
    DWORD old_protect = 0;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;
    int already_original = 1;

    for (SIZE_T i = 0; i < sizeof(k_original_exp_reward_calc); i++) {
        if (target[i] != k_original_exp_reward_calc[i]) {
            already_original = 0;
            break;
        }
    }
    if (already_original) return;

    if (!abs_jump) {
        log_line("exp reward calc restore skipped: unexpected bytes %02X %02X",
                 target[0], target[1]);
        return;
    }
    if (!VirtualProtect(target, sizeof(k_original_exp_reward_calc), PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return;
    }
    mem_copy_local(target, k_original_exp_reward_calc,
                   sizeof(k_original_exp_reward_calc));
    FlushInstructionCache(GetCurrentProcess(), target,
                          sizeof(k_original_exp_reward_calc));
    VirtualProtect(target, sizeof(k_original_exp_reward_calc),
                   old_protect, &old_protect);
    log_line("restored mistaken exp reward hook at %p", target);
}

static void restore_drop_rate_calc_hook_at(uintptr_t base, uintptr_t rva, const char *label)
{
    unsigned char *target = (unsigned char *)(base + rva);
    DWORD old_protect = 0;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;
    int already_original = 1;

    for (SIZE_T i = 0; i < sizeof(k_original_drop_rate_calc); i++) {
        if (target[i] != k_original_drop_rate_calc[i]) {
            already_original = 0;
            break;
        }
    }
    if (already_original) return;

    if (!abs_jump) {
        log_line("drop rate %s restore skipped: unexpected bytes %02X %02X",
                 label, target[0], target[1]);
        return;
    }
    if (!VirtualProtect(target, sizeof(k_original_drop_rate_calc), PAGE_EXECUTE_READWRITE, &old_protect)) {
        log_line("VirtualProtect failed at %p, error=%lu", target, GetLastError());
        return;
    }
    mem_copy_local(target, k_original_drop_rate_calc,
                   sizeof(k_original_drop_rate_calc));
    FlushInstructionCache(GetCurrentProcess(), target,
                          sizeof(k_original_drop_rate_calc));
    VirtualProtect(target, sizeof(k_original_drop_rate_calc),
                   old_protect, &old_protect);
    log_line("restored drop rate %s hook at %p", label, target);
}

static void restore_drop_rate_calc_hooks(uintptr_t base)
{
    restore_mistaken_exp_reward_hook(base);
    restore_drop_rate_calc_hook_at(base, RVA_NORMAL_DROP_RATE_CALC, "normal");
    restore_drop_rate_calc_hook_at(base, RVA_BOSS_DROP_RATE_CALC, "stage_boss");
}

#if ENABLE_DROP_RATE_BOOST
static float calculate_drop_rate_with_divisor10(void *rate_owner,
                                                float raw_rate,
                                                int flat_stat_id,
                                                int percent_stat_id,
                                                const char *label)
{
    void *stat_source;
    int flat_bonus;
    int percent_bonus;
    float before_rate = raw_rate;
    float after_flat_rate;
    float final_rate;
    static DWORD last_normal_log_tick;
    static DWORD last_boss_log_tick;
    static int last_normal_before;
    static int last_normal_after;
    static int last_boss_before;
    static int last_boss_after;
    DWORD now;
    DWORD *last_tick;
    int *last_before;
    int *last_after;
    int before_scaled;
    int after_scaled;

    if (!rate_owner || !g_game_assembly) return raw_rate;
    stat_source = *(void **)((unsigned char *)rate_owner + 32);
    if (!stat_source) return raw_rate;

    stat_value_get_t get_stat =
        (stat_value_get_t)((uintptr_t)g_game_assembly + RVA_STAT_VALUE_GET);
    flat_bonus = get_stat(stat_source, flat_stat_id, NULL);
    percent_bonus = get_stat(stat_source, percent_stat_id, NULL);

    if (flat_bonus <= 0 && percent_bonus <= 0) return raw_rate;
    after_flat_rate = raw_rate + (float)flat_bonus / 10.0f;
    final_rate = after_flat_rate + ((float)percent_bonus * after_flat_rate) / 10.0f;

    now = GetTickCount();
    if (flat_stat_id == 4) {
        last_tick = &last_normal_log_tick;
        last_before = &last_normal_before;
        last_after = &last_normal_after;
    } else {
        last_tick = &last_boss_log_tick;
        last_before = &last_boss_before;
        last_after = &last_boss_after;
    }
    before_scaled = float_x10000(before_rate);
    after_scaled = float_x10000(final_rate);
    if (before_scaled != *last_before ||
        after_scaled != *last_after ||
        now - *last_tick >= 2000) {
        *last_tick = now;
        *last_before = before_scaled;
        *last_after = after_scaled;
        log_line("drop rate %s: stat=%d/%d flat=%d percent=%d before=%d.%04d after=%d.%04d",
                 label,
                 flat_stat_id, percent_stat_id,
                 flat_bonus, percent_bonus,
                 before_scaled / 10000, before_scaled < 0 ? -before_scaled % 10000 : before_scaled % 10000,
                 after_scaled / 10000, after_scaled < 0 ? -after_scaled % 10000 : after_scaled % 10000);
    }
    return final_rate;
}

static float __fastcall hook_normal_drop_rate_calc(void *rate_owner, float raw_rate)
{
    return calculate_drop_rate_with_divisor10(rate_owner, raw_rate, 4, 29, "normal");
}

static float __fastcall hook_boss_drop_rate_calc(void *rate_owner, float raw_rate)
{
    return calculate_drop_rate_with_divisor10(rate_owner, raw_rate, 5, 30, "stage_boss");
}
#endif

static float record_drop_rate_result(drop_rate_calc_t real_calc,
                                     void *rate_owner,
                                     float raw_rate,
                                     void *method)
{
    float result = real_calc ? real_calc(rate_owner, raw_rate, method) : raw_rate;
    float calculated_rate = result;

    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId()) {
        if (g_force_drop_roll_rate_enabled && result < 100.0f) {
            result = 100.0f;
        }
        g_drop_observation.raw_rate = calculated_rate;
        g_drop_observation.final_rate = result;
        g_drop_observation.final_rate_seen = 1;
    }
    return result;
}

static float __fastcall hook_normal_drop_rate_observer(void *rate_owner,
                                                       float raw_rate,
                                                       void *method)
{
    return record_drop_rate_result(g_real_normal_drop_rate_calc,
                                   rate_owner, raw_rate, method);
}

static float __fastcall hook_boss_drop_rate_observer(void *rate_owner,
                                                     float raw_rate,
                                                     void *method)
{
    return record_drop_rate_result(g_real_boss_drop_rate_calc,
                                   rate_owner, raw_rate, method);
}

static float __fastcall hook_exp_reward_calc(void *reward_owner,
                                             float base_exp,
                                             int is_boss,
                                             char is_actboss,
                                             void *method)
{
    float result = g_real_exp_reward_calc ?
                   g_real_exp_reward_calc(reward_owner,
                                          base_exp,
                                          is_boss,
                                          is_actboss,
                                          method) :
                   base_exp;
    float boosted = result * g_exp_multiplier;
    LONG call_count = InterlockedIncrement(&g_exp_reward_call_count);
    DWORD now = GetTickCount();

    if (g_exp_multiplier <= 1.0f) return result;

    if (call_count <= 20 || now - g_last_exp_reward_log_tick >= 2000) {
        int base_scaled = float_x10000(base_exp);
        int result_scaled = float_x10000(result);
        int boosted_scaled = float_x10000(boosted);
        int mult_scaled = multiplier_x100(g_exp_multiplier);
        g_last_exp_reward_log_tick = now;
        log_line("exp reward: base=%d.%04d result=%d.%04d boosted=%d.%04d mult=%d.%02d boss=%d actboss=%d call=%ld",
                 base_scaled / 10000,
                 base_scaled < 0 ? -base_scaled % 10000 : base_scaled % 10000,
                 result_scaled / 10000,
                 result_scaled < 0 ? -result_scaled % 10000 : result_scaled % 10000,
                 boosted_scaled / 10000,
                 boosted_scaled < 0 ? -boosted_scaled % 10000 : boosted_scaled % 10000,
                 mult_scaled / 100,
                 mult_scaled % 100,
                 is_boss,
                 (int)is_actboss,
                 (long)call_count);
    }
    return boosted;
}

static void __fastcall hook_cube_add_exp(float amount, void *method)
{
    float boosted = amount * g_cube_exp_multiplier;
    LONG call_count = InterlockedIncrement(&g_cube_exp_call_count);
    DWORD now = GetTickCount();
    HMODULE game_assembly;
    unsigned char *target;
    int guard_acquired = 0;

    if (call_count <= 20 || now - g_last_cube_exp_log_tick >= 2000) {
        int amount_scaled = float_x10000(amount);
        int boosted_scaled = float_x10000(boosted);
        int mult_scaled = multiplier_x100(g_cube_exp_multiplier);
        g_last_cube_exp_log_tick = now;
        log_line("cube exp add: amount=%d.%04d boosted=%d.%04d mult=%d.%02d call=%ld",
                 amount_scaled / 10000,
                 amount_scaled < 0 ? -amount_scaled % 10000 : amount_scaled % 10000,
                 boosted_scaled / 10000,
                 boosted_scaled < 0 ? -boosted_scaled % 10000 : boosted_scaled % 10000,
                 mult_scaled / 100,
                 mult_scaled % 100,
                 (long)call_count);
    }

    game_assembly = g_game_assembly;
    if (!game_assembly) return;
    target = (unsigned char *)((uintptr_t)game_assembly + RVA_CUBE_ADD_EXP);

    for (int i = 0; i < 1000; i++) {
        if (InterlockedCompareExchange(&g_cube_exp_call_guard, 1, 0) == 0) {
            guard_acquired = 1;
            break;
        }
        Sleep(0);
    }
    if (!guard_acquired) {
        log_line("cube exp original call skipped: busy");
        return;
    }

    if (!write_code_bytes(target,
                          k_original_cube_add_exp,
                          sizeof(k_original_cube_add_exp))) {
        InterlockedExchange(&g_cube_exp_call_guard, 0);
        return;
    }
    g_hook_cube_add_exp.installed = 0;

    ((cube_add_exp_t)target)(boosted, method);

    if (!write_absolute_jump_sized(target,
                                   (void *)hook_cube_add_exp,
                                   &g_hook_cube_add_exp,
                                   sizeof(k_original_cube_add_exp))) {
        log_line("cube exp hook reinstall failed");
    }
    InterlockedExchange(&g_cube_exp_call_guard, 0);
}

static void __fastcall hook_drop_reward_callback(void *target,
                                                 unsigned int reward_value,
                                                 void *method)
{
    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId()) {
        g_drop_observation.reward_callback_seen = 1;
        g_drop_observation.reward_callback_value = reward_value;
        if (g_reward_trace_hooks_enabled) {
            log_line("reward callback observed: target=%p reward_value=%u method=%p",
                     target,
                     reward_value,
                     method);
        }
    }
    if (g_real_drop_reward_callback) {
        g_real_drop_reward_callback(target, reward_value, method);
    }
}

static __int64 __fastcall hook_give_reward_item(unsigned int item_key,
                                                void *callback,
                                                void *method)
{
    __int64 result;
    void *callback_invoke = NULL;
    void *callback_target = NULL;
    void *callback_method = NULL;
    void *callback_this = NULL;
    int observed_reward_request = 0;
    int callback_patched = 0;
    void *original_callback_invoke = NULL;

    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId() &&
        g_drop_observation.item_key == (int)item_key) {
        g_drop_observation.reward_requested = 1;
        g_drop_observation.reward_callback = callback;
        g_drop_observation.reward_method = method;
        observed_reward_request = 1;
        if (callback && memory_range_readable(callback, 0x48)) {
            callback_invoke = *(void **)((unsigned char *)callback + 0x18);
            callback_target = *(void **)((unsigned char *)callback + 0x20);
            callback_method = *(void **)((unsigned char *)callback + 0x28);
            callback_this = *(void **)((unsigned char *)callback + 0x40);
            g_drop_observation.reward_callback_invoke = callback_invoke;
            g_drop_observation.reward_callback_target = callback_target;
            g_drop_observation.reward_callback_method = callback_method;
            g_drop_observation.reward_callback_this = callback_this;
            if (g_game_assembly &&
                callback_invoke &&
                (RVA_DROP_REWARD_CALLBACK == 0 ||
                 callback_invoke == (void *)((uintptr_t)g_game_assembly + RVA_DROP_REWARD_CALLBACK))) {
                original_callback_invoke = callback_invoke;
                g_real_drop_reward_callback = (drop_reward_callback_t)callback_invoke;
                *(void **)((unsigned char *)callback + 0x18) = (void *)hook_drop_reward_callback;
                callback_patched = 1;
            }
        }
        if (g_reward_trace_hooks_enabled) {
            log_line("reward item observed: item_key=%u callback=%p invoke=%p target=%p cb_method=%p cb_this=%p method=%p",
                     item_key,
                     callback,
                     callback_invoke,
                     callback_target,
                     callback_method,
                     callback_this,
                     method);
        }
    }
    if (g_reward_trace_hooks_enabled) {
        log_line("reward item request: item_key=%u callback=%p method=%p",
                 item_key, callback, method);
    }
    if (!g_real_give_reward_item) return 0;
    result = g_real_give_reward_item(item_key, callback, method);
    if (callback_patched &&
        callback &&
        memory_range_readable(callback, 0x20) &&
        *(void **)((unsigned char *)callback + 0x18) == (void *)hook_drop_reward_callback) {
        *(void **)((unsigned char *)callback + 0x18) = original_callback_invoke;
    }
    if (g_reward_trace_hooks_enabled && observed_reward_request) {
        log_line("reward item result: item_key=%u result=%p", item_key, (void *)result);
    }
    return result;
}

static __int64 __fastcall hook_reward_add_item(unsigned int item_key,
                                               void *payload,
                                               int count,
                                               int notify,
                                               void *method)
{
    __int64 result;
    unsigned int low;
    unsigned int high;

    if (g_reward_trace_hooks_enabled) {
        log_line("reward add request: item_key=%u payload=%p count=%d notify=%d method=%p",
                 item_key,
                 payload,
                 count,
                 notify,
                 method);
    }
    if (!g_real_reward_add_item) return 0;
    result = g_real_reward_add_item(item_key, payload, count, notify, method);
    low = (unsigned int)(result & 0xFFFFFFFFu);
    high = (unsigned int)(((unsigned __int64)result >> 32) & 0xFFFFFFFFu);
    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId()) {
        g_drop_observation.reward_add_seen = 1;
        g_drop_observation.reward_add_low = low;
        g_drop_observation.reward_add_high = high;
        g_drop_observation.reward_add_notify = notify;
        g_drop_observation.reward_payload = payload;
        g_drop_observation.reward_item_key = item_key;
        g_drop_observation.dropped = high != 0xFFFFFFFFu;
        if (g_reward_trace_hooks_enabled) {
            log_line("reward add observed: item_key=%u result_high=0x%08lX result_low=0x%08lX success=%d notify=%d payload=%p",
                     item_key,
                     (unsigned long)high,
                     (unsigned long)low,
                     high != 0xFFFFFFFFu,
                     notify,
                     payload);
        }
    }
    if (g_reward_trace_hooks_enabled) {
        log_line("reward add result: item_key=%u result_high=0x%08lX result_low=0x%08lX low=%u high=%u success=%d",
                 item_key,
                 (unsigned long)high,
                 (unsigned long)low,
                 low,
                 high,
                 high != 0xFFFFFFFFu);
    }
    return result;
}

static int __fastcall hook_box_count_get(unsigned int box_type, void *method)
{
    int count;

    if (!g_real_box_count_get) return 0;
    count = g_real_box_count_get(box_type, method);
    log_line("box count: type=%u(%s) count=%d",
             box_type,
             box_type_name(box_type),
             count);
    return count;
}

#if ENABLE_FORCE_BOX_REWARD_SELECT
static void cache_boxdata_candidate(unsigned int item_key,
                                    void *box_data,
                                    unsigned int selected_item)
{
    unsigned int box_type;

    if (!box_data || selected_item != item_key) return;
    if (!item_key_to_box_type(item_key, &box_type) || box_type >= 3) return;
    if (!memory_range_readable(box_data, 0x58)) return;
    if (g_cached_boxdata_by_type[box_type] != box_data) {
        log_line("boxdata cached: item_key=%u type=%u(%s) boxdata=%p",
                 item_key,
                 box_type,
                 box_type_name(box_type),
                 box_data);
    }
    g_cached_boxdata_by_type[box_type] = box_data;
    g_cached_boxdata_item_by_type[box_type] = item_key;
}

static __int64 cached_box_reward_candidate(unsigned int item_key,
                                           unsigned int *out_selected_item,
                                           int *out_list_count)
{
    unsigned int box_type;
    void *box_data;
    unsigned int selected_item;

    if (!item_key_to_box_type(item_key, &box_type) || box_type >= 3) return 0;
    box_data = g_cached_boxdata_by_type[box_type];
    if (!box_data || g_cached_boxdata_item_by_type[box_type] != item_key) return 0;
    if (!memory_range_readable(box_data, 0x58)) return 0;

    selected_item = *(unsigned int *)((unsigned char *)box_data + 0x54);
    if (selected_item != item_key) return 0;
    if (out_selected_item) *out_selected_item = selected_item;
    if (out_list_count) *out_list_count = -1;
    return (__int64)box_data;
}

static __int64 force_first_box_reward_candidate(void *box_table,
                                                unsigned int item_key,
                                                unsigned int *out_selected_item,
                                                int *out_list_count)
{
    uintptr_t base;
    void *dict;
    void *method;
    void *list = NULL;
    void *items;
    void *candidate;
    unsigned int box_type;
    int list_count;
    int array_len;
    dict_try_get_value_t try_get;

    if (out_selected_item) *out_selected_item = 0;
    if (out_list_count) *out_list_count = 0;
    if (!g_force_box_reward_select_enabled || !g_game_assembly) return 0;
    if (!item_key_to_box_type(item_key, &box_type)) return 0;
    if (!memory_range_readable(box_table, 0x18)) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }

    dict = *(void **)((unsigned char *)box_table + 0x10);
    if (!dict) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }

    base = (uintptr_t)g_game_assembly;
    method = *(void **)(base + RVA_BOX_REWARD_TRY_GET_METHODINFO);
    try_get = (dict_try_get_value_t)(base + RVA_DICT_TRY_GET_VALUE);
    if (!try_get(dict, box_type, &list, method) || !list) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }
    if (!memory_range_readable(list, 0x20)) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }

    list_count = *(int *)((unsigned char *)list + 0x18);
    if (out_list_count) *out_list_count = list_count;
    if (list_count <= 0) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }

    items = *(void **)((unsigned char *)list + 0x10);
    if (!items || !memory_range_readable(items, 0x28)) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }
    array_len = *(int *)((unsigned char *)items + 0x18);
    if (array_len <= 0) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }

    candidate = *(void **)((unsigned char *)items + 0x20);
    if (!candidate || !memory_range_readable(candidate, 0x58)) {
        return cached_box_reward_candidate(item_key, out_selected_item, out_list_count);
    }
    if (out_selected_item) {
        *out_selected_item = *(unsigned int *)((unsigned char *)candidate + 0x54);
    }
    cache_boxdata_candidate(item_key, candidate, out_selected_item ? *out_selected_item : 0);
    return (__int64)candidate;
}

static int boxdata_list_contains(void *list, void *box_data)
{
    void *items;
    int count;
    int i;

    if (!list || !box_data || !memory_range_readable(list, 0x20)) return 0;
    count = *(int *)((unsigned char *)list + IL2CPP_LIST_SIZE_OFFSET);
    if (count <= 0 || count > 100000) return 0;

    items = *(void **)((unsigned char *)list + IL2CPP_LIST_ITEMS_OFFSET);
    if (!items || !memory_range_readable(items, IL2CPP_ARRAY_DATA_OFFSET)) return 0;
    for (i = 0; i < count; ++i) {
        void **slot = (void **)((unsigned char *)items +
                                IL2CPP_ARRAY_DATA_OFFSET +
                                ((SIZE_T)i * sizeof(void *)));
        if (!memory_range_readable(slot, sizeof(void *))) return 0;
        if (*slot == box_data) return 1;
    }
    return 0;
}

static int append_boxdata_to_list(void *list, void *box_data, int *out_count)
{
    uintptr_t base;
    void *items;
    void **slot;
    int count;
    int array_len;
    gc_write_barrier_t write_barrier;

    if (out_count) *out_count = 0;
    if (!g_game_assembly || !list || !box_data ||
        !memory_range_readable(list, 0x20)) {
        return 0;
    }

    count = *(int *)((unsigned char *)list + IL2CPP_LIST_SIZE_OFFSET);
    items = *(void **)((unsigned char *)list + IL2CPP_LIST_ITEMS_OFFSET);
    if (count < 0 || count > 100000 || !items ||
        !memory_range_readable(items, IL2CPP_ARRAY_DATA_OFFSET)) {
        return 0;
    }

    array_len = *(int *)((unsigned char *)items + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len < 0 || array_len > 100000 || count > array_len) return 0;
    if (out_count) *out_count = count;
    if (boxdata_list_contains(list, box_data)) return 2;
    if (count >= array_len) return 0;

    slot = (void **)((unsigned char *)items +
                     IL2CPP_ARRAY_DATA_OFFSET +
                     ((SIZE_T)count * sizeof(void *)));
    if (!memory_range_readable(slot, sizeof(void *))) return 0;

    *(int *)((unsigned char *)list + 0x1C) += 1;
    *(int *)((unsigned char *)list + IL2CPP_LIST_SIZE_OFFSET) = count + 1;
    *slot = box_data;

    base = (uintptr_t)g_game_assembly;
    write_barrier = (gc_write_barrier_t)(base + RVA_IL2CPP_GC_WRITE_BARRIER);
    write_barrier(slot, box_data);
    if (out_count) *out_count = count + 1;
    return 1;
}

static int keep_boxdata_available(void *box_table,
                                  unsigned int item_key,
                                  void *box_data,
                                  unsigned int selected_item)
{
    uintptr_t base;
    void *dict;
    void *method;
    void *list = NULL;
    unsigned int box_type;
    int list_count = 0;
    int status;
    dict_try_get_value_t try_get;

    if (!g_keep_boxdata_after_select_enabled || !g_game_assembly) return 0;
    if (!item_key_to_box_type(item_key, &box_type)) return 0;
    if (!box_table || !memory_range_readable(box_table, 0x18)) return 0;

    dict = *(void **)((unsigned char *)box_table + 0x10);
    if (!dict) return 0;

    base = (uintptr_t)g_game_assembly;
    method = *(void **)(base + RVA_BOX_REWARD_TRY_GET_METHODINFO);
    try_get = (dict_try_get_value_t)(base + RVA_DICT_TRY_GET_VALUE);
    if (!try_get(dict, box_type, &list, method) || !list) {
        if (g_reward_trace_hooks_enabled) {
            log_line("boxdata keep skipped: item_key=%u type=%u no available list",
                     item_key,
                     box_type);
        }
        return 0;
    }

    status = append_boxdata_to_list(list, box_data, &list_count);
    if (status == 1) {
        log_line("boxdata kept: item_key=%u type=%u(%s) selected_item=%u list_count=%d boxdata=%p",
                 item_key,
                 box_type,
                 box_type_name(box_type),
                 selected_item,
                 list_count,
                 box_data);
        return 1;
    }
    if (g_reward_trace_hooks_enabled) {
        log_line("boxdata keep skipped: item_key=%u type=%u status=%d list_count=%d boxdata=%p",
                 item_key,
                 box_type,
                 status,
                 list_count,
                 box_data);
    }
    return 0;
}
#endif

static __int64 __fastcall hook_box_reward_select(void *box_table,
                                                 unsigned int item_key,
                                                 void *context)
{
    __int64 result;
    unsigned int selected_item = 0;
#if ENABLE_FORCE_BOX_REWARD_SELECT
    unsigned int forced_item = 0;
    int forced_count = 0;
#endif
    int readable = 0;

    if (g_reward_trace_hooks_enabled &&
        item_key >= 900000 && item_key < 940000) {
        log_line("box reward select request: item_key=%u table=%p context=%p",
                 item_key,
                 box_table,
                 context);
    }
    if (!g_real_box_reward_select) return 0;
    result = g_real_box_reward_select(box_table, item_key, context);
#if ENABLE_FORCE_BOX_REWARD_SELECT
    if (!result) {
        result = force_first_box_reward_candidate(box_table,
                                                 item_key,
                                                 &forced_item,
                                                 &forced_count);
        if (result) {
            log_line("box reward select forced%s: item_key=%u list_count=%d selected_item=%u result=%p",
                     forced_count < 0 ? " cached" : "",
                     item_key,
                     forced_count,
                     forced_item,
                     (void *)result);
        }
    }
#endif
    readable = memory_range_readable((void *)result, 0x58);
    if (readable) {
        selected_item = *(unsigned int *)((unsigned char *)result + 0x54);
        cache_boxdata_candidate(item_key, (void *)result, selected_item);
    }
#if ENABLE_FORCE_BOX_REWARD_SELECT
    if (readable) {
        keep_boxdata_available(box_table, item_key, (void *)result, selected_item);
    }
#endif
    if (g_reward_trace_hooks_enabled &&
        item_key >= 900000 && item_key < 940000) {
        log_line("box reward select result: item_key=%u result=%p readable=%d selected_item=%u",
                 item_key,
                 (void *)result,
                 readable,
                 selected_item);
    }
    return result;
}

static void __fastcall hook_drop_roll_process(void *stage_manager,
                                              int source_id,
                                              int stage_type,
                                              int item_key,
                                              float raw_rate,
                                              int monster_type)
{
    static DWORD last_log_tick;
    static unsigned int suppressed_logs;
    DWORD now;
    float forwarded_rate = raw_rate;
    float final_rate;
    int raw_scaled;
    int forwarded_scaled;
    int owns_observation;
    int outcome;
    float observed_rate;

    owns_observation =
        InterlockedCompareExchange(&g_drop_observation.active, 1, 0) == 0;
    if (owns_observation) {
        g_drop_observation.thread_id = GetCurrentThreadId();
        g_drop_observation.source_id = source_id;
        g_drop_observation.item_key = item_key;
        g_drop_observation.monster_type = monster_type;
        g_drop_observation.raw_rate = raw_rate;
        g_drop_observation.forwarded_rate = forwarded_rate;
        g_drop_observation.final_rate = forwarded_rate;
        g_drop_observation.final_rate_seen = 0;
        g_drop_observation.reward_requested = 0;
        g_drop_observation.reward_add_seen = 0;
        g_drop_observation.reward_add_low = 0;
        g_drop_observation.reward_add_high = 0xFFFFFFFFu;
        g_drop_observation.reward_add_notify = 0;
        g_drop_observation.reward_payload = NULL;
        g_drop_observation.reward_item_key = 0;
        g_drop_observation.reward_callback = NULL;
        g_drop_observation.reward_callback_invoke = NULL;
        g_drop_observation.reward_callback_target = NULL;
        g_drop_observation.reward_callback_method = NULL;
        g_drop_observation.reward_callback_this = NULL;
        g_drop_observation.reward_callback_seen = 0;
        g_drop_observation.reward_callback_value = 0;
        g_drop_observation.reward_method = NULL;
        g_drop_observation.dropped = 0;
    }

    now = GetTickCount();
    if (g_reward_trace_hooks_enabled &&
        (!last_log_tick || now - last_log_tick >= 1000)) {
        raw_scaled = float_x10000(raw_rate);
        forwarded_scaled = float_x10000(forwarded_rate);
        log_line("drop roll call: stage_manager=%p source=%d stage_type=%d item_key=%d raw=%d.%04d forwarded=%d.%04d monster_type=%d suppressed=%u",
                 stage_manager,
                 source_id,
                 stage_type,
                 item_key,
                 raw_scaled / 10000,
                 raw_scaled < 0 ? -raw_scaled % 10000 : raw_scaled % 10000,
                 forwarded_scaled / 10000,
                 forwarded_scaled < 0 ? -forwarded_scaled % 10000 : forwarded_scaled % 10000,
                 monster_type,
                 suppressed_logs);
        last_log_tick = now;
        suppressed_logs = 0;
    } else if (g_reward_trace_hooks_enabled) {
        suppressed_logs++;
    }

    if (g_real_drop_roll_process) {
        g_real_drop_roll_process(stage_manager,
                                 source_id,
                                 stage_type,
                                 item_key,
                                 forwarded_rate,
                                 monster_type);
    }

    if (owns_observation) {
        final_rate = g_drop_observation.final_rate_seen ?
                     g_drop_observation.final_rate : forwarded_rate;
        observed_rate = g_drop_observation.final_rate_seen ?
                        g_drop_observation.raw_rate : raw_rate;
        outcome = g_drop_observation.dropped ? DROP_OUTCOME_DROP :
                  g_drop_observation.reward_requested ? DROP_OUTCOME_BLOCKED :
                  DROP_OUTCOME_MISS;
        append_drop_observation(source_id,
                                monster_type,
                                observed_rate,
                                final_rate,
                                outcome,
                                g_drop_observation.reward_item_key);
        InterlockedExchange(&g_drop_observation.active, 0);
    }
}

#if ENABLE_DROP_RATE_BOOST
static int install_drop_rate_calc_hooks(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *normal_target = (unsigned char *)(base + RVA_NORMAL_DROP_RATE_CALC);
    unsigned char *boss_target = (unsigned char *)(base + RVA_BOSS_DROP_RATE_CALC);
    int normal_original =
        (normal_target[0] == 0x40 &&
         normal_target[1] == 0x53 &&
         normal_target[2] == 0x48 &&
         normal_target[3] == 0x83) ||
        (normal_target[0] == 0x48 &&
         normal_target[1] == 0x83 &&
         normal_target[2] == 0xEC);
    int boss_original =
        (boss_target[0] == 0x40 &&
         boss_target[1] == 0x53 &&
         boss_target[2] == 0x48 &&
         boss_target[3] == 0x83) ||
        (boss_target[0] == 0x48 &&
         boss_target[1] == 0x83 &&
         boss_target[2] == 0xEC);
    int normal_abs_jump =
        normal_target[0] == 0x48 &&
        normal_target[1] == 0xB8 &&
        normal_target[10] == 0xFF &&
        normal_target[11] == 0xE0;
    int boss_abs_jump =
        boss_target[0] == 0x48 &&
        boss_target[1] == 0xB8 &&
        boss_target[10] == 0xFF &&
        boss_target[11] == 0xE0;
    int ok = 1;

    restore_mistaken_exp_reward_hook(base);

    if ((!normal_original && !normal_abs_jump) ||
        (!boss_original && !boss_abs_jump)) {
        log_line("drop rate calc RVAs unexpected: normal=%02X %02X boss=%02X %02X",
                 normal_target[0], normal_target[1], boss_target[0], boss_target[1]);
        return 0;
    }

    ok &= write_absolute_jump(normal_target, (void *)hook_normal_drop_rate_calc,
                              &g_hook_normal_drop_rate_calc);
    ok &= write_absolute_jump(boss_target, (void *)hook_boss_drop_rate_calc,
                              &g_hook_boss_drop_rate_calc);
    if (ok) {
        log_line("drop rate calc hooks installed: flat and percent divisors -> 10");
    }
    return ok;
}
#endif

static int install_drop_rate_observer_at(HMODULE game_assembly,
                                         uintptr_t rva,
                                         void *detour,
                                         HookPatch *hook,
                                         drop_rate_calc_t *out_real,
                                         const char *label)
{
    unsigned char *target =
        (unsigned char *)((uintptr_t)game_assembly + rva);
    int original = 1;

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_drop_rate_calc,
                                          sizeof(k_original_drop_rate_calc),
                                          label)) {
            return 0;
        }
    }
    for (SIZE_T i = 0; i < sizeof(k_original_drop_rate_calc); i++) {
        if (target[i] != k_original_drop_rate_calc[i]) {
            original = 0;
            break;
        }
    }
    if (!original) {
        log_line("%s observer RVA unexpected: %02X %02X %02X %02X",
                 label, target[0], target[1], target[2], target[3]);
        return 0;
    }
    if (!write_absolute_jump_with_trampoline(target,
                                             detour,
                                             hook,
                                             sizeof(k_original_drop_rate_calc),
                                             (void **)out_real)) {
        log_line("%s observer install failed", label);
        return 0;
    }
    return 1;
}

static int install_drop_rate_observer_hooks(HMODULE game_assembly)
{
    int normal_ok = install_drop_rate_observer_at(
        game_assembly,
        RVA_NORMAL_DROP_RATE_CALC,
        (void *)hook_normal_drop_rate_observer,
        &g_hook_normal_drop_rate_observer,
        &g_real_normal_drop_rate_calc,
        "normal drop rate");
    int boss_ok = install_drop_rate_observer_at(
        game_assembly,
        RVA_BOSS_DROP_RATE_CALC,
        (void *)hook_boss_drop_rate_observer,
        &g_hook_boss_drop_rate_observer,
        &g_real_boss_drop_rate_calc,
        "boss drop rate");

    if (normal_ok && boss_ok) {
        log_line("drop rate observer hooks installed");
        return 1;
    }
    return 0;
}

static int install_exp_reward_calc_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_EXP_REWARD_CALC);
    int original = mem_equal_local(target,
                                   k_original_exp_reward_calc,
                                   sizeof(k_original_exp_reward_calc));
    int mult_scaled = multiplier_x100(g_exp_multiplier);

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_exp_reward_calc,
                                          sizeof(k_original_exp_reward_calc),
                                          "exp reward")) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("exp reward hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (!write_absolute_jump_with_trampoline(target,
                                             (void *)hook_exp_reward_calc,
                                             &g_hook_exp_reward_calc,
                                             sizeof(k_original_exp_reward_calc),
                                             (void **)&g_real_exp_reward_calc)) {
        log_line("exp reward hook install failed");
        return 0;
    }
    log_line("exp reward hook installed: multiplier=%d.%02d",
             mult_scaled / 100,
             mult_scaled % 100);
    return 1;
}

static void restore_exp_reward_calc_hook(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_EXP_REWARD_CALC),
                                 k_original_exp_reward_calc,
                                 sizeof(k_original_exp_reward_calc),
                                 "exp reward");
}

static int install_cube_add_exp_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_CUBE_ADD_EXP);
    int original = mem_equal_local(target,
                                   k_original_cube_add_exp,
                                   sizeof(k_original_cube_add_exp));

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_cube_add_exp,
                                          sizeof(k_original_cube_add_exp),
                                          "cube exp")) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("cube exp hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    g_real_cube_add_exp = (cube_add_exp_t)target;
    if (!write_absolute_jump_sized(target,
                                   (void *)hook_cube_add_exp,
                                   &g_hook_cube_add_exp,
                                   sizeof(k_original_cube_add_exp))) {
        log_line("cube exp hook install failed");
        return 0;
    }
    int mult_scaled = multiplier_x100(g_cube_exp_multiplier);
    log_line("cube exp hook installed: multiplier=%d.%02d safe-original-call=1",
             mult_scaled / 100,
             mult_scaled % 100);
    return 1;
}

static void restore_cube_add_exp_hook(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_CUBE_ADD_EXP),
                                 k_original_cube_add_exp,
                                 sizeof(k_original_cube_add_exp),
                                 "cube exp");
}

static int install_give_reward_item_hook(HMODULE game_assembly)
{
    static const unsigned char original_give_reward[] = {
        0x48, 0x89, 0x5C, 0x24, 0x08,
        0x48, 0x89, 0x74, 0x24, 0x18,
        0x48, 0x89, 0x54, 0x24, 0x10
    };
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_GIVE_REWARD_ITEM);
    int original =
        target[0] == 0x48 &&
        target[1] == 0x89 &&
        target[2] == 0x5C &&
        target[3] == 0x24;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          original_give_reward,
                                          sizeof(original_give_reward),
                                          "reward item")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("reward item hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (write_absolute_jump_with_trampoline(target,
                                            (void *)hook_give_reward_item,
                                            &g_hook_give_reward_item,
                                            15,
                                            (void **)&g_real_give_reward_item)) {
        log_line("reward item hook installed");
        return 1;
    }
    return 0;
}

static int install_reward_add_item_hook(HMODULE game_assembly)
{
    static const unsigned char original_reward_add[] = {
        0x48, 0x89, 0x6C, 0x24, 0x10,
        0x48, 0x89, 0x74, 0x24, 0x18,
        0x48, 0x89, 0x7C, 0x24, 0x20
    };
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_REWARD_ADD_ITEM);
    int original =
        target[0] == 0x48 &&
        target[1] == 0x89 &&
        target[3] == 0x24;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          original_reward_add,
                                          sizeof(original_reward_add),
                                          "reward add")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("reward add hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (write_absolute_jump_with_trampoline(target,
                                            (void *)hook_reward_add_item,
                                            &g_hook_reward_add_item,
                                            15,
                                            (void **)&g_real_reward_add_item)) {
        log_line("reward add hook installed");
        return 1;
    }
    return 0;
}

static int install_box_count_get_hook(HMODULE game_assembly)
{
    static const unsigned char original_box_count[] = {
        0x40, 0x53,
        0x48, 0x83, 0xEC, 0x20,
        0x80, 0x3D, 0xDE, 0x7B, 0x82, 0x05, 0x00,
        0x48, 0x63, 0xD9
    };
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target;
    int original =
        0;
    int abs_jump;

    if (RVA_BOX_COUNT_GET == 0) {
        log_line("box count hook unavailable for this game build");
        return 0;
    }

    target = (unsigned char *)(base + RVA_BOX_COUNT_GET);
    original = mem_equal_local(target, original_box_count,
                               sizeof(original_box_count));
    abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          original_box_count,
                                          sizeof(original_box_count),
                                          "box count")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("box count hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (write_absolute_jump_with_trampoline(target,
                                            (void *)hook_box_count_get,
                                            &g_hook_box_count_get,
                                            sizeof(original_box_count),
                                            (void **)&g_real_box_count_get)) {
        log_line("box count hook installed");
        return 1;
    }
    return 0;
}

static int install_box_reward_select_hook(HMODULE game_assembly)
{
    static const unsigned char original_select[] = {
        0x48, 0x89, 0x5C, 0x24, 0x10,
        0x56,
        0x48, 0x83, 0xEC, 0x40,
        0x80, 0x3D, 0x24, 0xEB, 0x7C, 0x05, 0x00
    };
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_BOX_REWARD_SELECT);
    int original =
        target[0] == 0x48 &&
        target[1] == 0x89 &&
        target[3] == 0x24 &&
        target[5] == 0x56 &&
        target[6] == 0x48 &&
        target[7] == 0x83 &&
        target[8] == 0xEC;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          original_select,
                                          sizeof(original_select),
                                          "box reward select")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("box reward select hook RVA unexpected: %02X %02X %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3], target[4], target[5]);
        return 0;
    }

    if (write_absolute_jump_with_trampoline(target,
                                            (void *)hook_box_reward_select,
                                            &g_hook_box_reward_select,
                                            17,
                                            (void **)&g_real_box_reward_select)) {
        log_line("box reward select hook installed");
        return 1;
    }
    log_line("box reward select hook install failed");
    return 0;
}

static int install_drop_roll_process_hook(HMODULE game_assembly)
{
    static const unsigned char original_drop_roll[] = {
        0x48, 0x89, 0x5C, 0x24, 0x08,
        0x48, 0x89, 0x6C, 0x24, 0x10,
        0x48, 0x89, 0x74, 0x24, 0x18,
        0x48, 0x89, 0x7C, 0x24, 0x20
    };
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_DROP_ROLL_PROCESS);
    int original =
        target[0] == 0x48 &&
        target[1] == 0x89 &&
        target[2] == 0x5C &&
        target[3] == 0x24 &&
        target[4] == 0x08;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          original_drop_roll,
                                          sizeof(original_drop_roll),
                                          "drop roll")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("drop roll hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (write_absolute_jump_with_trampoline(target,
                                            (void *)hook_drop_roll_process,
                                            &g_hook_drop_roll_process,
                                            20,
                                            (void **)&g_real_drop_roll_process)) {
        log_line("drop roll hook installed");
        return 1;
    }
    return 0;
}

static void restore_box_count_hook(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    if (RVA_BOX_COUNT_GET == 0) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_BOX_COUNT_GET),
                                 k_original_box_count,
                                 sizeof(k_original_box_count),
                                 "box count");
}

static void restore_box_reward_select_hook(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_BOX_REWARD_SELECT),
                                 k_original_box_reward_select,
                                 sizeof(k_original_box_reward_select),
                                 "box reward select");
}

static void restore_optional_reward_trace_hooks(HMODULE game_assembly)
{
    restore_box_count_hook(game_assembly);
    restore_box_reward_select_hook(game_assembly);
}

static void restore_reward_trace_hooks(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_GIVE_REWARD_ITEM),
                                 k_original_give_reward,
                                 sizeof(k_original_give_reward),
                                 "reward item");
    restore_original_if_abs_jump((unsigned char *)(base + RVA_REWARD_ADD_ITEM),
                                 k_original_reward_add,
                                 sizeof(k_original_reward_add),
                                 "reward add");
    restore_optional_reward_trace_hooks(game_assembly);
}

static void restore_drop_related_patches(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_drop_cooldown_bypass_patch();
    restore_reward_item_capacity_bypass_patch();
    restore_reward_trace_hooks(game_assembly);
    restore_original_if_abs_jump((unsigned char *)(base + RVA_DROP_ROLL_PROCESS),
                                 k_original_drop_roll,
                                 sizeof(k_original_drop_roll),
                                 "drop roll");
}

static void invalidate_overlay_button(HWND button);
static void update_boss_button(void);
static void update_auto_switch_button(void);

static LONG auto_switch_waiting_for(void)
{
    return InterlockedCompareExchange(&g_auto_switch_waiting_for,
                                      AUTO_SWITCH_WAIT_NONE,
                                      AUTO_SWITCH_WAIT_NONE);
}

static const char *auto_switch_wait_name(LONG wait)
{
    if (wait == AUTO_SWITCH_WAIT_NORMAL_DROP) return "normal";
    if (wait == AUTO_SWITCH_WAIT_BOSS_DROP) return "boss";
    return "none";
}

static void clear_auto_switch_wait(const char *reason)
{
    LONG wait = InterlockedExchange(&g_auto_switch_waiting_for,
                                    AUTO_SWITCH_WAIT_NONE);
    g_auto_switch_wait_started_ms = 0;
    if (wait != AUTO_SWITCH_WAIT_NONE) {
        log_line("auto switch wait cleared: wait=%s reason=%s",
                 auto_switch_wait_name(wait),
                 reason ? reason : "unknown");
        append_overlay_event("AUTO SWITCH CANCEL %s",
                             reason ? reason : "unknown");
    }
    update_auto_switch_button();
}

static void set_direct_boss_enabled_for_auto(int enabled, const char *reason)
{
    g_direct_boss_enabled = enabled ? 1 : 0;
    apply_direct_boss_patch();
    update_boss_button();
    log_line("auto switch set boss:%s reason=%s",
             g_direct_boss_enabled ? "on" : "off",
             reason ? reason : "unknown");
    append_overlay_event("AUTO SWITCH boss:%s",
                         g_direct_boss_enabled ? "on" : "off");
}

static void set_direct_boss_enabled(int enabled)
{
    clear_auto_switch_wait("manual boss toggle");
    g_direct_boss_enabled = enabled ? 1 : 0;
    if (g_auto_switch_enabled) {
        g_auto_switch_primary_boss_enabled = g_direct_boss_enabled;
        log_line("auto switch primary flow changed by manual boss toggle: boss:%s",
                 g_auto_switch_primary_boss_enabled ? "on" : "off");
    }
    apply_direct_boss_patch();
    save_config();
}

static void update_boss_button(void)
{
    if (!g_overlay_boss_button) return;
    SetWindowTextA(g_overlay_boss_button,
                   g_direct_boss_enabled ? "boss:on" : "boss:off");
    invalidate_overlay_button(g_overlay_boss_button);
}

static void set_actboss_boss_enabled(int enabled)
{
    g_actboss_boss_enabled = enabled ? 1 : 0;
    log_line("actboss boss %s", g_actboss_boss_enabled ? "enabled" : "disabled");
    save_config();
}

static void update_actboss_button(void)
{
    if (!g_overlay_actboss_button) return;
    SetWindowTextA(g_overlay_actboss_button,
                   g_actboss_boss_enabled ? "actboss:on" : "actboss:off");
    invalidate_overlay_button(g_overlay_actboss_button);
}

static void set_auto_switch_enabled(int enabled)
{
    g_auto_switch_enabled = enabled ? 1 : 0;
    if (g_auto_switch_enabled) {
        g_auto_switch_primary_boss_enabled = g_direct_boss_enabled ? 1 : 0;
        log_line("auto switch primary flow captured: boss:%s",
                 g_auto_switch_primary_boss_enabled ? "on" : "off");
    } else {
        clear_auto_switch_wait("disabled");
    }
    log_line("auto switch %s", g_auto_switch_enabled ? "enabled" : "disabled");
    append_overlay_event("AUTO SWITCH %s",
                         g_auto_switch_enabled ? "ON" : "OFF");
    update_auto_switch_button();
    save_config();
}

static void update_auto_switch_button(void)
{
    LONG wait;

    if (!g_overlay_auto_switch_button) return;
    wait = auto_switch_waiting_for();
    if (!g_auto_switch_enabled) {
        SetWindowTextA(g_overlay_auto_switch_button, "auto:off");
    } else if (wait == AUTO_SWITCH_WAIT_NORMAL_DROP) {
        SetWindowTextA(g_overlay_auto_switch_button, "auto:N");
    } else if (wait == AUTO_SWITCH_WAIT_BOSS_DROP) {
        SetWindowTextA(g_overlay_auto_switch_button, "auto:B");
    } else {
        SetWindowTextA(g_overlay_auto_switch_button, "auto:on");
    }
    invalidate_overlay_button(g_overlay_auto_switch_button);
}

static int chest_countdown_due(const ChestDropStats *stats)
{
    unsigned __int64 now_ms;
    unsigned __int64 target_ms;

    if (!stats || !stats->last_drop_time_ms || !stats->best_interval_1_ms) {
        return 0;
    }
    target_ms = stats->last_drop_time_ms + stats->best_interval_1_ms;
    if (target_ms < stats->last_drop_time_ms) return 0;
    now_ms = current_filetime_ms();
    return now_ms >= target_ms;
}

static void maybe_auto_switch_from_game_thread(void)
{
    LONG wait;

    if (!g_auto_switch_enabled || !g_drop_hooks_enabled) return;
    wait = auto_switch_waiting_for();
    if (wait != AUTO_SWITCH_WAIT_NONE) return;

    if (g_auto_switch_primary_boss_enabled) {
        if (!chest_countdown_due(&g_normal_chest_stats)) return;
        InterlockedExchange(&g_auto_switch_waiting_for,
                            AUTO_SWITCH_WAIT_NORMAL_DROP);
        g_auto_switch_wait_started_ms = current_filetime_ms();
        log_line("auto switch normal countdown due: boss:on -> boss:off");
        append_overlay_event("AUTO SWITCH wait N chest");
        set_direct_boss_enabled_for_auto(0, "normal countdown due");
        update_auto_switch_button();
        return;
    }

    if (!chest_countdown_due(&g_boss_chest_stats)) return;
    InterlockedExchange(&g_auto_switch_waiting_for,
                        AUTO_SWITCH_WAIT_BOSS_DROP);
    g_auto_switch_wait_started_ms = current_filetime_ms();
    log_line("auto switch boss countdown due: boss:off -> boss:on");
    append_overlay_event("AUTO SWITCH wait B chest");
    set_direct_boss_enabled_for_auto(1, "boss countdown due");
    update_auto_switch_button();
}

static void auto_switch_on_chest_drop(unsigned int box_type)
{
    LONG wait;

    if (!g_auto_switch_enabled) return;
    wait = auto_switch_waiting_for();
    if (wait == AUTO_SWITCH_WAIT_NORMAL_DROP && box_type == 0) {
        InterlockedExchange(&g_auto_switch_waiting_for,
                            AUTO_SWITCH_WAIT_NONE);
        g_auto_switch_wait_started_ms = 0;
        log_line("auto switch normal chest acquired: boss:off -> boss:on");
        append_overlay_event("AUTO SWITCH N chest -> boss:on");
        set_direct_boss_enabled_for_auto(g_auto_switch_primary_boss_enabled,
                                         "normal chest dropped");
        update_auto_switch_button();
    } else if (wait == AUTO_SWITCH_WAIT_BOSS_DROP && box_type == 1) {
        InterlockedExchange(&g_auto_switch_waiting_for,
                            AUTO_SWITCH_WAIT_NONE);
        g_auto_switch_wait_started_ms = 0;
        log_line("auto switch boss chest acquired: boss:on -> boss:off");
        append_overlay_event("AUTO SWITCH B chest -> boss:off");
        set_direct_boss_enabled_for_auto(g_auto_switch_primary_boss_enabled,
                                         "boss chest dropped");
        update_auto_switch_button();
    }
}

static LONG auto_restart_pending_request(void)
{
    return InterlockedCompareExchange(&g_auto_restart_request,
                                      AUTO_RESTART_REQUEST_NONE,
                                      AUTO_RESTART_REQUEST_NONE);
}

static int auto_restart_effective_locked(void)
{
    LONG request = auto_restart_pending_request();

    if (request == AUTO_RESTART_REQUEST_LOCK) return 1;
    if (request == AUTO_RESTART_REQUEST_UNLOCK) return 0;
    return g_auto_restart_locked;
}

static void queue_auto_restart_request(LONG request)
{
    if (request != AUTO_RESTART_REQUEST_LOCK &&
        request != AUTO_RESTART_REQUEST_UNLOCK) {
        return;
    }

    InterlockedExchange(&g_auto_restart_request, request);
    if (request == AUTO_RESTART_REQUEST_LOCK) {
        log_line("auto restart lock requested from overlay");
        append_overlay_event("LOCK REQUESTED");
    } else {
        log_line("auto restart unlock requested from overlay");
        append_overlay_event("UNLOCK REQUESTED");
    }
}

static void update_lock_button(HWND hwnd)
{
    HWND button = GetDlgItem(hwnd, OVERLAY_BUTTON_LOCK_STAGE);
    LONG request;

    if (!button) return;
    request = auto_restart_pending_request();
    SetWindowTextA(button, request != AUTO_RESTART_REQUEST_NONE ?
                   "wait" :
                   (g_auto_restart_locked ? "unlock" : "lock"));
    invalidate_overlay_button(button);
}

static void update_lock_stage_label(void)
{
    char text[48];
    int stage_no;
    LONG request;

    if (!g_overlay_lock_stage_label) return;
    request = auto_restart_pending_request();
    if (request == AUTO_RESTART_REQUEST_LOCK) {
        lstrcpynA(text, "...", sizeof(text));
    } else if (g_auto_restart_locked && g_auto_restart_stage_key > 0) {
        stage_no = display_stage_no_from_key(g_auto_restart_stage_key,
                                             g_auto_restart_stage_no);
        if (g_auto_restart_act > 0 && stage_no > 0) {
            wsprintfA(text, "%d-%d", g_auto_restart_act, stage_no);
        } else {
            wsprintfA(text, "key %d", g_auto_restart_stage_key);
        }
    } else {
        lstrcpynA(text, "--", sizeof(text));
    }
    text[sizeof(text) - 1] = 0;
    SetWindowTextA(g_overlay_lock_stage_label, text);
}

static void update_lock_interval_label(void)
{
    char text[48];
    int interval_seconds;
    int remaining_seconds;

    if (!g_overlay_lock_interval_label) return;
    interval_seconds = auto_portal_interval_seconds();
    remaining_seconds = auto_portal_remaining_seconds();
    if (remaining_seconds >= 0) {
        wsprintfA(text, "%ds(%ds)", interval_seconds, remaining_seconds);
    } else {
        wsprintfA(text, "%ds(--s)", interval_seconds);
    }
    text[sizeof(text) - 1] = 0;
    SetWindowTextA(g_overlay_lock_interval_label, text);
}

static void format_chest_next_countdown(char *buf,
                                        int buflen,
                                        const ChestDropStats *stats)
{
    unsigned __int64 now_ms;
    unsigned __int64 target_ms;
    unsigned __int64 remaining_ms;

    if (buflen <= 0) return;
    if (!stats || !stats->last_drop_time_ms || !stats->best_interval_1_ms) {
        lstrcpynA(buf, "--", buflen);
        return;
    }

    now_ms = current_filetime_ms();
    target_ms = stats->last_drop_time_ms + stats->best_interval_1_ms;
    remaining_ms = target_ms > now_ms ? target_ms - now_ms : 0;
    if (!remaining_ms) {
        lstrcpynA(buf, "ready", buflen);
        return;
    }
    format_elapsed_interval_u64(buf, buflen, remaining_ms);
}

static void update_chest_interval_label(void)
{
    char normal_last[24];
    char normal_best_1[24];
    char normal_best_2[24];
    char normal_next[24];
    char boss_last[24];
    char boss_best_1[24];
    char boss_best_2[24];
    char boss_next[24];
    char text[192];

    if (!g_overlay_chest_intervals_label) return;
    format_elapsed_interval_u64(normal_last, sizeof(normal_last),
                                g_normal_chest_stats.last_interval_ms);
    format_elapsed_interval_u64(normal_best_1, sizeof(normal_best_1),
                                g_normal_chest_stats.best_interval_1_ms);
    format_elapsed_interval_u64(normal_best_2, sizeof(normal_best_2),
                                g_normal_chest_stats.best_interval_2_ms);
    format_chest_next_countdown(normal_next, sizeof(normal_next),
                                &g_normal_chest_stats);
    format_elapsed_interval_u64(boss_last, sizeof(boss_last),
                                g_boss_chest_stats.last_interval_ms);
    format_elapsed_interval_u64(boss_best_1, sizeof(boss_best_1),
                                g_boss_chest_stats.best_interval_1_ms);
    format_elapsed_interval_u64(boss_best_2, sizeof(boss_best_2),
                                g_boss_chest_stats.best_interval_2_ms);
    format_chest_next_countdown(boss_next, sizeof(boss_next),
                                &g_boss_chest_stats);
    wsprintfA(text, "N count %u last %s best %s/%s next %s\r\nB count %u last %s best %s/%s next %s",
              g_normal_chest_stats.drop_count,
              normal_last, normal_best_1, normal_best_2, normal_next,
              g_boss_chest_stats.drop_count,
              boss_last, boss_best_1, boss_best_2, boss_next);
    text[sizeof(text) - 1] = 0;
    SetWindowTextA(g_overlay_chest_intervals_label, text);
}

static int il2cpp_list_size_local(void *list)
{
    int size;
    void *items;
    int capacity;

    if (!list) return 0;
    size = *(int *)((unsigned char *)list + IL2CPP_LIST_SIZE_OFFSET);
    if (size < 0 || size > 10000) return 0;
    if (!size) return 0;

    items = *(void **)((unsigned char *)list + IL2CPP_LIST_ITEMS_OFFSET);
    if (!items) return 0;
    capacity = *(int *)((unsigned char *)items + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (capacity < size) return 0;
    return size;
}

static void *il2cpp_list_get_local(void *list, int index)
{
    int size;
    void *items;

    if (!list || index < 0) return NULL;
    size = il2cpp_list_size_local(list);
    if (index >= size) return NULL;
    items = *(void **)((unsigned char *)list + IL2CPP_LIST_ITEMS_OFFSET);
    if (!items) return NULL;
    return *(void **)((unsigned char *)items + IL2CPP_ARRAY_DATA_OFFSET + ((uintptr_t)index * sizeof(void *)));
}

static void *get_stage_cache_list(uintptr_t base)
{
    void *stage_data_type = *(void **)(base + RVA_STAGE_DATA_TYPEINFO);
    void *static_fields;

    if (!stage_data_type) return NULL;
    static_fields = *(void **)((unsigned char *)stage_data_type + IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields) return NULL;
    return *(void **)((unsigned char *)static_fields + STAGE_DATA_STAGE_LIST_OFFSET);
}

static void *get_current_stage_cache(uintptr_t base)
{
    void *stage_data_type = *(void **)(base + RVA_STAGE_DATA_TYPEINFO);
    void *static_fields;

    if (!stage_data_type) return NULL;
    static_fields = *(void **)((unsigned char *)stage_data_type + IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields) return NULL;
    return *(void **)((unsigned char *)static_fields + STAGE_DATA_CURRENT_CACHE_OFFSET);
}

static void *get_stage_manager_instance(uintptr_t base)
{
    void *stage_manager_type = *(void **)(base + RVA_STAGE_MANAGER_TYPEINFO);
    void *static_fields;
    void *stage_manager;

    if (!stage_manager_type ||
        !memory_range_readable(stage_manager_type,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)stage_manager_type +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields || !memory_range_readable(static_fields, sizeof(void *))) {
        return NULL;
    }
    stage_manager = *(void **)static_fields;
    if (!stage_manager || !memory_range_readable(stage_manager, sizeof(void *) * 2)) {
        return NULL;
    }
    return stage_manager;
}

static void *find_actboss_stage_for_stage(uintptr_t base,
                                          void *source_stage,
                                          int *out_act,
                                          int *out_difficulty,
                                          int *out_stage_no,
                                          int *out_stage_key)
{
    stagecache_get_int_t get_act = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_ACT);
    stagecache_get_int_t get_difficulty = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_DIFFICULTY);
    stagecache_get_int_t get_type = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_TYPE);
    stagecache_get_int_t get_stage_no = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_STAGE_NO);
    stagecache_get_int_t get_key = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_KEY);
    int act;
    int difficulty;
    void *stage_list;
    int count;
    void *best = NULL;
    int best_stage_no = 0x7fffffff;
    int best_stage_key = 0;

    if (!source_stage) return NULL;

    act = get_act(source_stage);
    difficulty = get_difficulty(source_stage);
    stage_list = get_stage_cache_list(base);
    count = il2cpp_list_size_local(stage_list);

    for (int i = 0; i < count; i++) {
        void *candidate = il2cpp_list_get_local(stage_list, i);
        int stage_type;
        int stage_no;

        if (!candidate) continue;
        if (get_act(candidate) != act) continue;
        if (get_difficulty(candidate) != difficulty) continue;
        stage_type = get_type(candidate);
        if (stage_type != ESTAGE_TYPE_ACTBOSS) continue;

        stage_no = get_stage_no(candidate);
        if (!best || stage_no < best_stage_no) {
            best = candidate;
            best_stage_no = stage_no;
            best_stage_key = get_key(candidate);
        }
    }

    if (!best) {
        static DWORD last_diagnostic_tick;
        DWORD now = GetTickCount();

        if (!last_diagnostic_tick || now - last_diagnostic_tick >= 5000) {
            int logged = 0;
            log_line("actboss lookup miss: source_key=%d act=%d difficulty=%d list_count=%d",
                     get_key(source_stage), act, difficulty, count);
            for (int i = 0; i < count && logged < 8; i++) {
                void *candidate = il2cpp_list_get_local(stage_list, i);
                int stage_type;

                if (!candidate) continue;
                stage_type = get_type(candidate);
                if (stage_type != ESTAGE_TYPE_ACTBOSS) continue;
                log_line("actboss candidate: key=%d act=%d difficulty=%d stage_no=%d",
                         get_key(candidate),
                         get_act(candidate),
                         get_difficulty(candidate),
                         get_stage_no(candidate));
                logged++;
            }
            if (!logged) {
                log_line("actboss lookup miss: no ACTBOSS entries in StageData.berm");
            }
            last_diagnostic_tick = now;
        }
        return NULL;
    }

    if (out_act) *out_act = act;
    if (out_difficulty) *out_difficulty = difficulty;
    if (out_stage_no) *out_stage_no = best_stage_no;
    if (out_stage_key) *out_stage_key = best_stage_key;
    return best;
}

static void *get_stage_boss_monster_data(uintptr_t base, void *stage_cache)
{
    stagecache_get_int_t get_boss_key =
        (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_BOSS_MONSTER_KEY);
    monster_data_by_key_t monster_by_key =
        (monster_data_by_key_t)(base + RVA_MONSTER_DATA_BY_KEY);
    int boss_key;

    if (!stage_cache) return NULL;
    boss_key = get_boss_key(stage_cache);
    if (boss_key <= 0) return NULL;
    return monster_by_key((unsigned int)boss_key);
}

static void * __fastcall hook_stagecache_jgm(void *stage_cache)
{
    uintptr_t base = (uintptr_t)g_game_assembly;
    void *target_stage = stage_cache;
    void *monster_data;

    if (base && stage_cache && g_actboss_boss_enabled) {
        stagecache_get_int_t get_type = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_TYPE);
        int stage_type = get_type(stage_cache);

        if (stage_type == ESTAGE_TYPE_NORMAL) {
            int act = 0;
            int difficulty = 0;
            int stage_no = 0;
            int stage_key = 0;
            void *actboss_stage = find_actboss_stage_for_stage(base, stage_cache,
                                                               &act, &difficulty,
                                                               &stage_no, &stage_key);
            if (actboss_stage) {
                target_stage = actboss_stage;
                log_line("actboss boss selected: act=%d difficulty=%d stage_no=%d stage_key=%d",
                         act, difficulty, stage_no, stage_key);
            } else {
                log_line("actboss boss fallback: actboss stage unavailable");
            }
        }
    }

    monster_data = get_stage_boss_monster_data(base, target_stage);
    if (!monster_data && target_stage != stage_cache) {
        monster_data = get_stage_boss_monster_data(base, stage_cache);
    }
    return monster_data;
}

static int install_stagecache_jgm_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_STAGECACHE_JGM);
    int original =
        target[0] == 0x40 &&
        target[1] == 0x53 &&
        target[2] == 0x48 &&
        target[3] == 0x83 &&
        target[4] == 0xEC &&
        target[5] == 0x30;
    int abs_jump =
        target[0] == 0x48 &&
        target[1] == 0xB8 &&
        target[10] == 0xFF &&
        target[11] == 0xE0;

    if (abs_jump) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_stagecache_jgm,
                                          sizeof(k_original_stagecache_jgm),
                                          "StageCache boss data")) {
            return 0;
        }
        original = 1;
        abs_jump = 0;
    }

    if (!original && !abs_jump) {
        log_line("StageCache boss data RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (write_absolute_jump(target, (void *)hook_stagecache_jgm,
                            &g_hook_stagecache_jgm)) {
        log_line("StageCache boss data hook installed");
        return 1;
    }
    return 0;
}

static void restore_legacy_bad_stage_manager_enter_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target =
        (unsigned char *)(base + RVA_LEGACY_BAD_STAGE_MANAGER_ENTER_HOOK);

    if (!is_absolute_jump_local(target)) return;
    if (write_code_bytes(target,
                         k_original_legacy_bad_stage_manager_enter_prefix,
                         sizeof(k_original_legacy_bad_stage_manager_enter_prefix))) {
        log_line("restored legacy bad StageManager enter hook");
    } else {
        log_line("failed to restore legacy bad StageManager enter hook");
    }
}

static int get_current_stage_target(uintptr_t base,
                                    void *current_stage,
                                    int *out_act,
                                    int *out_difficulty,
                                    int *out_stage_type,
                                    int *out_stage_no,
                                    int *out_stage_key)
{
    stagecache_get_int_t get_act = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_ACT);
    stagecache_get_int_t get_difficulty = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_DIFFICULTY);
    stagecache_get_int_t get_type = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_TYPE);
    stagecache_get_int_t get_stage_no = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_STAGE_NO);
    stagecache_get_int_t get_key = (stagecache_get_int_t)(base + RVA_STAGECACHE_GET_KEY);

    if (!current_stage) return 0;

    if (out_act) *out_act = get_act(current_stage);
    if (out_difficulty) *out_difficulty = get_difficulty(current_stage);
    if (out_stage_type) *out_stage_type = get_type(current_stage);
    if (out_stage_no) *out_stage_no = get_stage_no(current_stage);
    if (out_stage_key) *out_stage_key = get_key(current_stage);
    return 1;
}

static int lock_auto_restart_stage_from_current(void)
{
    uintptr_t base = (uintptr_t)g_game_assembly;
    void *current_stage;
    int act = 0;
    int difficulty = 0;
    int stage_type = 0;
    int stage_no = 0;
    int stage_key = 0;
    int enter_key = 0;
    int previous_stage_no = 0;

    if (!base) return 0;
    current_stage = get_current_stage_cache(base);
    if (!current_stage) {
        log_line("auto restart lock failed: current stage cache unavailable");
        append_overlay_event("LOCK FAILED current stage unavailable");
        return 0;
    }
    if (!get_current_stage_target(base, current_stage,
                                  &act, &difficulty, &stage_type, &stage_no, &stage_key)
        || stage_key <= 0) {
        log_line("auto restart lock failed: current stage key unavailable");
        append_overlay_event("LOCK FAILED current stage key unavailable");
        return 0;
    }
    if (stage_type != ESTAGE_TYPE_NORMAL) {
        log_line("auto restart lock failed: only normal stages are supported, type=%d stage_no=%d",
                 stage_type, stage_no);
        append_overlay_event("LOCK FAILED normal stages only type=%d",
                             stage_type);
        return 0;
    }
    find_stage_enter_key_for_stage_key(base, act, difficulty,
                                       ESTAGE_TYPE_NORMAL, stage_key,
                                       &enter_key, &previous_stage_no);
    if (enter_key <= 0 && stage_key > 1) {
        enter_key = stage_key - 1;
        previous_stage_no = stage_no - 1;
    }

    g_auto_restart_stage_key = stage_key;
    g_auto_restart_enter_key = enter_key;
    g_auto_restart_act = act;
    g_auto_restart_difficulty = difficulty;
    g_auto_restart_stage_type = stage_type;
    g_auto_restart_stage_no = stage_no;
    g_auto_restart_locked = 1;
    g_last_auto_portal_tick = GetTickCount();
    g_last_auto_stage_drift_tick = 0;
    log_line("auto restart locked: act=%d difficulty=%d type=%d stage_no=%d stage_key=%d restart_key=%d previous_stage_no=%d",
             act, difficulty, stage_type, stage_no, stage_key,
             enter_key, previous_stage_no);
    append_overlay_event("LOCKED %d-%d diff=%d key=%d",
                         act, display_stage_no_from_key(stage_key, stage_no),
                         difficulty, stage_key);
    save_config();
    return 1;
}

static void unlock_auto_restart_stage(void)
{
    int was_locked = g_auto_restart_locked;
    int act = g_auto_restart_act;
    int difficulty = g_auto_restart_difficulty;
    int stage_no = g_auto_restart_stage_no;
    int stage_key = g_auto_restart_stage_key;

    g_auto_restart_locked = 0;
    g_auto_restart_stage_key = 0;
    g_auto_restart_enter_key = 0;
    g_auto_restart_act = 0;
    g_auto_restart_difficulty = 0;
    g_auto_restart_stage_type = 0;
    g_auto_restart_stage_no = 0;
    g_last_auto_portal_tick = 0;
    g_last_auto_stage_drift_tick = 0;
    log_line("auto restart unlocked");
    if (was_locked) {
        append_overlay_event("UNLOCKED %d-%d diff=%d key=%d",
                             act, display_stage_no_from_key(stage_key, stage_no),
                             difficulty, stage_key);
    } else {
        append_overlay_event("UNLOCKED");
    }
    save_config();
}

static void process_auto_restart_request_from_game_thread(void)
{
    LONG request = InterlockedExchange(&g_auto_restart_request,
                                       AUTO_RESTART_REQUEST_NONE);

    if (request == AUTO_RESTART_REQUEST_LOCK) {
        lock_auto_restart_stage_from_current();
    } else if (request == AUTO_RESTART_REQUEST_UNLOCK) {
        unlock_auto_restart_stage();
    }
}

static void maybe_auto_restart_current_stage_from_game_thread(void)
{
    if (!g_auto_portal_enabled || !g_game_assembly) return;

    DWORD now = GetTickCount();
    uintptr_t base = (uintptr_t)g_game_assembly;
    void *current_stage;
    void *locked_stage;
    void *stage_manager;
    stage_enter_exact_key_t enter_stage_exact;
    __int64 result = -1;
    int current_act = 0;
    int current_difficulty = 0;
    int current_stage_type = 0;
    int current_stage_no = 0;
    int current_stage_key = 0;
    int after_act = 0;
    int after_difficulty = 0;
    int after_stage_type = 0;
    int after_stage_no = 0;
    int after_stage_key = 0;
    int stage_drifted = 0;
    int restart_key;
    const char *reason = "interval";

    if (!g_auto_restart_locked) return;
    if (g_auto_restart_stage_key <= 0) {
        log_line("auto restart skipped: locked stage key unavailable");
        return;
    }

    current_stage = get_current_stage_cache(base);
    if (current_stage &&
        get_current_stage_target(base,
                                 current_stage,
                                 &current_act,
                                 &current_difficulty,
                                 &current_stage_type,
                                 &current_stage_no,
                                 &current_stage_key)) {
        stage_drifted =
            current_act != g_auto_restart_act ||
            current_difficulty != g_auto_restart_difficulty ||
            current_stage_type != g_auto_restart_stage_type ||
            current_stage_no != g_auto_restart_stage_no ||
            current_stage_key != g_auto_restart_stage_key;
        if (!stage_drifted) {
            g_last_auto_stage_drift_tick = 0;
        } else {
            g_last_auto_stage_drift_tick = now;
            reason = "drift";
        }
    } else {
        return;
    }
    if ((DWORD)(now - g_last_auto_portal_tick) <
        g_auto_portal_interval_ms) {
        return;
    }
    g_last_auto_portal_tick = now;

    locked_stage = find_stage_cache_by_stage_key(base,
                                                 g_auto_restart_act,
                                                 g_auto_restart_difficulty,
                                                 g_auto_restart_stage_type,
                                                 g_auto_restart_stage_key);
    restart_key = g_auto_restart_enter_key > 0 ?
                  g_auto_restart_enter_key :
                  g_auto_restart_stage_key;
    stage_manager = get_stage_manager_instance(base);
    if (!stage_manager) {
        log_line("auto restart skipped: StageManager instance unavailable");
        append_overlay_event("AUTO RETURN FAILED StageManager unavailable");
        return;
    }
    enter_stage_exact =
        (stage_enter_exact_key_t)(base + RVA_STAGE_ENTER_EXACT_KEY);
    log_line("auto restart enter call: stage_manager=%p restart_key=%d locked_cache=%p",
             stage_manager, restart_key, locked_stage);
    result = enter_stage_exact(stage_manager, (unsigned int)restart_key, NULL);

    current_stage = get_current_stage_cache(base);
    if (current_stage) {
        get_current_stage_target(base,
                                 current_stage,
                                 &after_act,
                                 &after_difficulty,
                                 &after_stage_type,
                                 &after_stage_no,
                                 &after_stage_key);
    }

    log_line("auto restart locked stage refresh: reason=%s locked_act=%d locked_difficulty=%d locked_type=%d locked_stage_no=%d locked_stage_key=%d restart_key=%d current_act=%d current_difficulty=%d current_type=%d current_stage_no=%d current_stage_key=%d locked_cache=%p result_low=%ld after_act=%d after_difficulty=%d after_type=%d after_stage_no=%d after_stage_key=%d",
             reason,
             g_auto_restart_act, g_auto_restart_difficulty, g_auto_restart_stage_type,
             g_auto_restart_stage_no, g_auto_restart_stage_key,
             restart_key,
             current_act, current_difficulty, current_stage_type,
             current_stage_no, current_stage_key,
             locked_stage, (long)result,
             after_act, after_difficulty, after_stage_type,
             after_stage_no, after_stage_key);
    append_overlay_event("AUTO RETURN %s %d-%d current=%d-%d key=%d after=%d-%d",
                         reason,
                         g_auto_restart_act,
                         display_stage_no_from_key(g_auto_restart_stage_key,
                                                   g_auto_restart_stage_no),
                         current_act,
                         display_stage_no_from_key(current_stage_key,
                                                   current_stage_no),
                         restart_key,
                         after_act,
                         display_stage_no_from_key(after_stage_key,
                                                   after_stage_no));
}

static void enforce_game_title_bar(void);

static void apply_speed_from_game_thread(void)
{
    static DWORD last_tick;
    DWORD now = GetTickCount();
    LONG dirty = InterlockedExchange(&g_speed_dirty, 0);
    if (!g_game_thread_id) g_game_thread_id = GetCurrentThreadId();
    if (!dirty && last_tick && now - last_tick < g_apply_interval_ms) return;
    last_tick = now;

    if (g_real_set_time_scale) {
        g_real_set_time_scale(g_speed);
    }
    process_auto_restart_request_from_game_thread();
    enforce_game_title_bar();
    maybe_auto_switch_from_game_thread();
    maybe_auto_restart_current_stage_from_game_thread();
}

static float hook_time_get_delta_time(void *method)
{
    (void)method;
    apply_speed_from_game_thread();
    if (g_real_get_delta_time) {
        return g_real_get_delta_time();
    }
    return 0.0166667f * g_speed;
}

static float hook_time_get_time_scale(void *method)
{
    (void)method;
    return g_speed;
}

static void hook_time_set_time_scale(float value, void *method)
{
    (void)value;
    (void)method;
    if (g_real_set_time_scale) {
        g_real_set_time_scale(g_speed);
    }
}

static void delete_gdi_object(HGDIOBJ object)
{
    if (object) DeleteObject(object);
}

static void init_overlay_style(void)
{
    if (!g_overlay_bg_brush) {
        g_overlay_bg_brush = CreateSolidBrush(OVERLAY_COLOR_BG);
        g_overlay_panel_brush = CreateSolidBrush(OVERLAY_COLOR_PANEL);
        g_overlay_panel_2_brush = CreateSolidBrush(OVERLAY_COLOR_PANEL_2);
        g_overlay_button_brush = CreateSolidBrush(OVERLAY_COLOR_BUTTON);
        g_overlay_button_hot_brush = CreateSolidBrush(OVERLAY_COLOR_BUTTON_HOT);
        g_overlay_button_active_brush = CreateSolidBrush(OVERLAY_COLOR_BUTTON_ACTIVE);
        g_overlay_border_brush = CreateSolidBrush(OVERLAY_COLOR_BORDER);
        g_overlay_accent_brush = CreateSolidBrush(OVERLAY_COLOR_ACCENT);
        g_overlay_border_pen = CreatePen(PS_SOLID, 1, OVERLAY_COLOR_BORDER);
        g_overlay_accent_pen = CreatePen(PS_SOLID, 1, OVERLAY_COLOR_ACCENT);
    }
    if (!g_overlay_font) {
        g_overlay_font = CreateFontA(-13, 0, 0, 0, 500, 0, 0, 0,
                                     DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                     CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                     DEFAULT_PITCH | FF_SWISS, "Segoe UI");
        g_overlay_font_bold = CreateFontA(-14, 0, 0, 0, 700, 0, 0, 0,
                                          DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                                          CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                          DEFAULT_PITCH | FF_SWISS, "Segoe UI");
    }
}

static void destroy_overlay_style(void)
{
    delete_gdi_object((HGDIOBJ)g_overlay_font);
    delete_gdi_object((HGDIOBJ)g_overlay_font_bold);
    delete_gdi_object((HGDIOBJ)g_overlay_bg_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_panel_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_panel_2_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_button_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_button_hot_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_button_active_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_border_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_accent_brush);
    delete_gdi_object((HGDIOBJ)g_overlay_border_pen);
    delete_gdi_object((HGDIOBJ)g_overlay_accent_pen);
    g_overlay_font = NULL;
    g_overlay_font_bold = NULL;
    g_overlay_bg_brush = NULL;
    g_overlay_panel_brush = NULL;
    g_overlay_panel_2_brush = NULL;
    g_overlay_button_brush = NULL;
    g_overlay_button_hot_brush = NULL;
    g_overlay_button_active_brush = NULL;
    g_overlay_border_brush = NULL;
    g_overlay_accent_brush = NULL;
    g_overlay_border_pen = NULL;
    g_overlay_accent_pen = NULL;
}

static void paint_overlay_chrome(HWND hwnd, HDC hdc)
{
    RECT rc;
    RECT title;
    RECT line;
    RECT label;
    RECT separator;
    HGDIOBJ old_brush;
    HGDIOBJ old_pen;
    HGDIOBJ old_font;
    char title_text[128];

    init_overlay_style();
    GetClientRect(hwnd, &rc);

    old_brush = SelectObject(hdc, g_overlay_bg_brush);
    old_pen = SelectObject(hdc, g_overlay_border_pen);
    RoundRect(hdc, rc.left, rc.top, rc.right, rc.bottom, 10, 10);

    title.left = 12;
    title.top = 5;
    title.right = OVERLAY_WIDTH - 12;
    title.bottom = 26;
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, OVERLAY_COLOR_TEXT);
    old_font = SelectObject(hdc, g_overlay_font_bold);
    wsprintfA(title_text, "%s  game:%s  plugin:%s",
              OVERLAY_DISPLAY_TITLE,
              g_detected_game_version[0] ? g_detected_game_version : TBHS_SUPPORTED_GAME_VERSION,
              TBHS_PLUGIN_DISPLAY_VERSION);
    title_text[sizeof(title_text) - 1] = 0;
    DrawTextA(hdc, title_text, -1, &title,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    SelectObject(hdc, old_font);

    line.left = 10;
    line.top = 29;
    line.right = OVERLAY_WIDTH - 10;
    line.bottom = 30;
    FillRect(hdc, &line, g_overlay_accent_brush);

    SetTextColor(hdc, OVERLAY_COLOR_MUTED);
    old_font = SelectObject(hdc, g_overlay_font_bold);
    label.left = 12;
    label.right = 70;
    label.top = 38;
    label.bottom = 62;
    DrawTextA(hdc, "Speed", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 74;
    label.bottom = 98;
    DrawTextA(hdc, "Exp", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 110;
    label.bottom = 134;
    DrawTextA(hdc, "Boss", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 146;
    label.bottom = 170;
    DrawTextA(hdc, "Reset", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 182;
    label.bottom = 206;
    DrawTextA(hdc, "Drops", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    SelectObject(hdc, old_font);

    separator.left = 10;
    separator.right = OVERLAY_WIDTH - 10;
    separator.top = 68;
    separator.bottom = 69;
    FillRect(hdc, &separator, g_overlay_border_brush);
    separator.top = 104;
    separator.bottom = 105;
    FillRect(hdc, &separator, g_overlay_border_brush);
    separator.top = 140;
    separator.bottom = 141;
    FillRect(hdc, &separator, g_overlay_border_brush);
    separator.top = 176;
    separator.bottom = 177;
    FillRect(hdc, &separator, g_overlay_border_brush);

    SelectObject(hdc, old_pen);
    SelectObject(hdc, old_brush);
}

static void draw_overlay_button(const DRAWITEMSTRUCT *item)
{
    RECT rc;
    RECT top;
    char text[64];
    int id;
    int active = 0;
    int pressed;
    HBRUSH fill;
    HBRUSH border;
    COLORREF text_color;
    HGDIOBJ old_font;

    if (!item || !item->hwndItem) return;
    init_overlay_style();

    rc = item->rcItem;
    id = (int)item->CtlID;
    pressed = (item->itemState & ODS_SELECTED) ? 1 : 0;
    if (id == OVERLAY_BUTTON_BOSS && g_direct_boss_enabled) active = 1;
    if (id == OVERLAY_BUTTON_ACTBOSS && g_actboss_boss_enabled) active = 1;
    if (id == OVERLAY_BUTTON_AUTO_SWITCH && g_auto_switch_enabled) active = 1;
    if (id == OVERLAY_BUTTON_LOCK_STAGE && g_auto_restart_locked) active = 1;

    fill = active ? g_overlay_button_active_brush :
           (pressed ? g_overlay_button_hot_brush : g_overlay_button_brush);
    border = active ? g_overlay_accent_brush : g_overlay_border_brush;
    text_color = active ? RGB(246, 237, 190) : OVERLAY_COLOR_TEXT;

    FillRect(item->hDC, &rc, fill);
    FrameRect(item->hDC, &rc, border);
    top = rc;
    top.bottom = top.top + 1;
    FillRect(item->hDC, &top, active ? g_overlay_accent_brush : g_overlay_panel_brush);

    text[0] = 0;
    GetWindowTextA(item->hwndItem, text, sizeof(text));
    text[sizeof(text) - 1] = 0;

    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, text_color);
    old_font = SelectObject(item->hDC,
                            active ? g_overlay_font_bold : g_overlay_font);
    DrawTextA(item->hDC, text, -1, &rc,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    SelectObject(item->hDC, old_font);
}

static HWND create_overlay_button(HWND hwnd, const char *text, int x, int y,
                                  int width, int height, int id)
{
    return CreateWindowExA(0, "BUTTON", text,
                           WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                           BS_OWNERDRAW,
                           x, y, width, height, hwnd,
                           (HMENU)(uintptr_t)id, g_self_module, NULL);
}

static void apply_overlay_fonts(HWND hwnd)
{
    int ids[] = {
        OVERLAY_BUTTON_MIN,
        OVERLAY_BUTTON_MINUS5,
        OVERLAY_BUTTON_MINUS1,
        OVERLAY_BUTTON_PLUS1,
        OVERLAY_BUTTON_PLUS5,
        OVERLAY_BUTTON_MAX,
        OVERLAY_BUTTON_EXP_MINUS,
        OVERLAY_BUTTON_EXP_PLUS,
        OVERLAY_BUTTON_CUBE_MINUS,
        OVERLAY_BUTTON_CUBE_PLUS,
        OVERLAY_BUTTON_BOSS,
        OVERLAY_BUTTON_ACTBOSS,
        OVERLAY_BUTTON_AUTO_SWITCH,
        OVERLAY_BUTTON_LOCK_STAGE,
        OVERLAY_BUTTON_LOCK_MINUS30,
        OVERLAY_BUTTON_LOCK_MINUS10,
        OVERLAY_BUTTON_LOCK_PLUS10,
        OVERLAY_BUTTON_LOCK_PLUS30
    };

    init_overlay_style();
    for (int i = 0; i < (int)(sizeof(ids) / sizeof(ids[0])); i++) {
        HWND child = GetDlgItem(hwnd, ids[i]);
        if (child) SendMessageA(child, WM_SETFONT, (WPARAM)g_overlay_font, TRUE);
    }
    if (g_overlay_label) {
        SendMessageA(g_overlay_label, WM_SETFONT,
                     (WPARAM)g_overlay_font_bold, TRUE);
    }
    if (g_overlay_exp_multiplier_label) {
        SendMessageA(g_overlay_exp_multiplier_label, WM_SETFONT,
                     (WPARAM)g_overlay_font_bold, TRUE);
    }
    if (g_overlay_cube_multiplier_label) {
        SendMessageA(g_overlay_cube_multiplier_label, WM_SETFONT,
                     (WPARAM)g_overlay_font_bold, TRUE);
    }
    if (g_overlay_lock_interval_label) {
        SendMessageA(g_overlay_lock_interval_label, WM_SETFONT,
                     (WPARAM)g_overlay_font_bold, TRUE);
    }
    if (g_overlay_lock_stage_label) {
        SendMessageA(g_overlay_lock_stage_label, WM_SETFONT,
                     (WPARAM)g_overlay_font_bold, TRUE);
    }
    if (g_overlay_chest_intervals_label) {
        SendMessageA(g_overlay_chest_intervals_label, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
    }
}

static void invalidate_overlay_button(HWND button)
{
    if (button) InvalidateRect(button, NULL, TRUE);
}

static void update_overlay_label(void)
{
    char text[32];
    if (!g_overlay_label) return;
    format_speed_label(text, sizeof(text));
    SetWindowTextA(g_overlay_label, text);
}

static void format_multiplier_label(float value, char *buf, int buflen)
{
    int scaled;

    if (buflen <= 0) return;
    scaled = multiplier_x100(value);
    if (scaled % 100 == 0) {
        wsprintfA(buf, "x%d", scaled / 100);
    } else if (scaled % 10 == 0) {
        wsprintfA(buf, "x%d.%d", scaled / 100, (scaled % 100) / 10);
    } else {
        wsprintfA(buf, "x%d.%02d", scaled / 100, scaled % 100);
    }
    buf[buflen - 1] = 0;
}

static void update_exp_multiplier_labels(void)
{
    char text[32];

    if (g_overlay_exp_multiplier_label) {
        format_multiplier_label(g_exp_multiplier, text, sizeof(text));
        SetWindowTextA(g_overlay_exp_multiplier_label, text);
    }
    if (g_overlay_cube_multiplier_label) {
        format_multiplier_label(g_cube_exp_multiplier, text, sizeof(text));
        SetWindowTextA(g_overlay_cube_multiplier_label, text);
    }
}

static void adjust_speed(float delta)
{
    int before = speed_x100();
    set_speed_value(g_speed + delta);
    int after = speed_x100();
    update_overlay_label();
    log_line("speed changed by overlay: %d.%02d -> %d.%02d",
             before / 100, before % 100, after / 100, after % 100);
    save_config();
}

static void adjust_exp_multiplier_value(float delta)
{
    int before = multiplier_x100(g_exp_multiplier);
    int after;

    g_exp_multiplier = clamp_exp_multiplier(g_exp_multiplier + delta);
    after = multiplier_x100(g_exp_multiplier);
    update_exp_multiplier_labels();
    log_line("exp multiplier changed by overlay: %d.%02d -> %d.%02d",
             before / 100, before % 100,
             after / 100, after % 100);
    save_config();
}

static void adjust_cube_exp_multiplier_value(float delta)
{
    int before = multiplier_x100(g_cube_exp_multiplier);
    int after;

    g_cube_exp_multiplier = clamp_exp_multiplier(g_cube_exp_multiplier + delta);
    after = multiplier_x100(g_cube_exp_multiplier);
    update_exp_multiplier_labels();
    log_line("cube exp multiplier changed by overlay: %d.%02d -> %d.%02d",
             before / 100, before % 100,
             after / 100, after % 100);
    save_config();
}

static int is_speed_overlay_window(HWND hwnd)
{
    char text[96];
    char cls[96];

    if (hwnd == g_overlay_hwnd) return 1;

    text[0] = 0;
    cls[0] = 0;
    GetWindowTextA(hwnd, text, sizeof(text));
    GetClassNameA(hwnd, cls, sizeof(cls));
    text[sizeof(text) - 1] = 0;
    cls[sizeof(cls) - 1] = 0;

    if (lstrcmpA(text, OVERLAY_WINDOW_TITLE) == 0 ||
        lstrcmpA(text, OVERLAY_OLD_WINDOW_TITLE) == 0) {
        return 1;
    }
    if (starts_with_local(cls, OVERLAY_CLASS_PREFIX)) return 1;
    return 0;
}

static BOOL CALLBACK enum_game_window_proc(HWND hwnd, LPARAM lparam)
{
    DWORD pid = 0;
    (void)lparam;
    GetWindowThreadProcessId(hwnd, &pid);
    if (pid != GetCurrentProcessId()) return TRUE;
    if (!IsWindowVisible(hwnd)) return TRUE;
    if (GetWindow(hwnd, GW_OWNER) != NULL) return TRUE;
    if (is_speed_overlay_window(hwnd)) return TRUE;
    g_game_hwnd = hwnd;
    return FALSE;
}

static BOOL CALLBACK enum_old_overlay_window_proc(HWND hwnd, LPARAM lparam)
{
    DWORD pid = 0;
    DWORD thread_id;
    char title[64];
    (void)lparam;
    thread_id = GetWindowThreadProcessId(hwnd, &pid);
    if (pid != GetCurrentProcessId()) return TRUE;
    if (hwnd == g_overlay_hwnd) return TRUE;
    title[0] = 0;
    GetWindowTextA(hwnd, title, sizeof(title));
    title[sizeof(title) - 1] = 0;
    if (lstrcmpA(title, OVERLAY_WINDOW_TITLE) == 0 ||
        lstrcmpA(title, OVERLAY_OLD_WINDOW_TITLE) == 0 ||
        is_speed_overlay_window(hwnd)) {
        if (!g_previous_overlay_position_valid && IsWindowVisible(hwnd) &&
            GetWindowRect(hwnd, &g_previous_overlay_rect)) {
            g_previous_overlay_position_valid = 1;
        }
        PostMessageA(hwnd, WM_CLOSE, 0, 0);
        if (thread_id && thread_id != GetCurrentThreadId()) {
            PostThreadMessageA(thread_id, WM_QUIT, 0, 0);
        }
        InterlockedIncrement(&g_closed_overlay_count);
    }
    return TRUE;
}

static void close_old_overlay_windows(void)
{
    EnumWindows(enum_old_overlay_window_proc, 0);
    if (g_closed_overlay_count) {
        Sleep(100);
        log_line("closed %ld previous overlay window(s)",
                 g_closed_overlay_count);
    }
}

static HWND find_game_window(void)
{
    if (g_game_hwnd && IsWindow(g_game_hwnd)) return g_game_hwnd;
    g_game_hwnd = NULL;
    EnumWindows(enum_game_window_proc, 0);
    return g_game_hwnd;
}

static void enforce_game_title_bar(void)
{
    HWND game;
    RECT rc;
    UnityRefreshRate refresh_rate;
    int width = 0;
    int height = 0;
    DWORD now;

    if (!g_force_game_title_bar_enabled) return;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;
    if (!g_screen_set_fullscreen && !g_screen_set_fullscreen_mode &&
        !g_screen_set_resolution_injected && !g_screen_set_resolution_bool3 &&
        !g_screen_set_resolution_bool4 && !g_screen_set_resolution_mode4) {
        return;
    }

    now = GetTickCount();
    if (g_last_windowed_apply_tick &&
        (DWORD)(now - g_last_windowed_apply_tick) < 2000) {
        return;
    }
    g_last_windowed_apply_tick = now;

    game = find_game_window();
    if (!game) return;

    if (g_screen_get_width) width = g_screen_get_width();
    if (g_screen_get_height) height = g_screen_get_height();
    if ((width <= 0 || height <= 0) && GetClientRect(game, &rc)) {
        width = rc.right - rc.left;
        height = rc.bottom - rc.top;
    }
    if (width <= 0 || height <= 0) return;

    if (g_screen_set_fullscreen_mode) {
        g_screen_set_fullscreen_mode(3);
    }
    if (g_screen_set_fullscreen) {
        g_screen_set_fullscreen(0);
    }
    if (g_screen_set_resolution_injected) {
        refresh_rate.numerator = 0;
        refresh_rate.denominator = 1;
        g_screen_set_resolution_injected(width, height, 3, &refresh_rate);
    } else if (g_screen_set_resolution_mode4) {
        g_screen_set_resolution_mode4(width, height, 3, 0);
    } else if (g_screen_set_resolution_bool4) {
        g_screen_set_resolution_bool4(width, height, 0, 0);
    } else if (g_screen_set_resolution_bool3) {
        g_screen_set_resolution_bool3(width, height, 0);
    }

    if (!g_windowed_logged) {
        g_windowed_logged = 1;
        log_line("game windowed mode requested for macOS title bar: hwnd=%p size=%dx%d",
                 game, width, height);
    }
}

static void position_overlay(HWND hwnd)
{
    HWND game = find_game_window();
    RECT rc;
    int x = g_overlay_x;
    int y = g_overlay_y;
    if (g_overlay_user_moved || g_overlay_dragging) {
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, OVERLAY_WIDTH, OVERLAY_HEIGHT,
                     SWP_NOMOVE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
        return;
    }
    if (game && GetWindowRect(game, &rc)) {
        x = rc.left + g_overlay_x;
        y = rc.top + g_overlay_y;
    }
    SetWindowPos(hwnd, HWND_TOPMOST, x, y, OVERLAY_WIDTH, OVERLAY_HEIGHT,
                 SWP_NOACTIVATE | SWP_SHOWWINDOW);
}

static void persist_overlay_position(HWND hwnd)
{
    HWND game;
    RECT overlay_rc;
    RECT game_rc;

    if (!hwnd || !GetWindowRect(hwnd, &overlay_rc)) return;
    game = find_game_window();
    if (game && GetWindowRect(game, &game_rc)) {
        g_overlay_x = overlay_rc.left - game_rc.left;
        g_overlay_y = overlay_rc.top - game_rc.top;
    } else {
        g_overlay_x = overlay_rc.left;
        g_overlay_y = overlay_rc.top;
    }
    save_config();
}

static LRESULT CALLBACK overlay_wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg) {
    case WM_CREATE:
        {
            HRGN region = CreateRoundRectRgn(0, 0, OVERLAY_WIDTH + 1,
                                            OVERLAY_HEIGHT + 1, 10, 10);
            if (region && !SetWindowRgn(hwnd, region, TRUE)) {
                DeleteObject(region);
            }
        }
        init_overlay_style();
        create_overlay_button(hwnd, "min", 76, 36, 42, 26,
                              OVERLAY_BUTTON_MIN);
        create_overlay_button(hwnd, "-5", 122, 36, 42, 26,
                              OVERLAY_BUTTON_MINUS5);
        create_overlay_button(hwnd, "-1", 168, 36, 42, 26,
                              OVERLAY_BUTTON_MINUS1);
        g_overlay_label = CreateWindowExA(0, "STATIC", "5",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_CENTER | SS_CENTERIMAGE,
                        214, 36, 64, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_SPEED,
                        g_self_module, NULL);
        create_overlay_button(hwnd, "+1", 282, 36, 42, 26,
                              OVERLAY_BUTTON_PLUS1);
        create_overlay_button(hwnd, "+5", 328, 36, 42, 26,
                              OVERLAY_BUTTON_PLUS5);
        create_overlay_button(hwnd, "max", 374, 36, 42, 26,
                              OVERLAY_BUTTON_MAX);
        create_overlay_button(hwnd, "exp-", 76, 72, 56, 26,
                              OVERLAY_BUTTON_EXP_MINUS);
        g_overlay_exp_multiplier_label = CreateWindowExA(
                        0, "STATIC", "x1",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_CENTER | SS_CENTERIMAGE,
                        136, 72, 64, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_EXP_MULTIPLIER,
                        g_self_module, NULL);
        create_overlay_button(hwnd, "exp+", 204, 72, 56, 26,
                              OVERLAY_BUTTON_EXP_PLUS);
        create_overlay_button(hwnd, "cube-", 282, 72, 64, 26,
                              OVERLAY_BUTTON_CUBE_MINUS);
        g_overlay_cube_multiplier_label = CreateWindowExA(
                        0, "STATIC", "x10",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_CENTER | SS_CENTERIMAGE,
                        350, 72, 64, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_CUBE_MULTIPLIER,
                        g_self_module, NULL);
        create_overlay_button(hwnd, "cube+", 418, 72, 64, 26,
                              OVERLAY_BUTTON_CUBE_PLUS);
        g_overlay_boss_button = create_overlay_button(hwnd, "boss:off",
                        76, 108, 92, 26, OVERLAY_BUTTON_BOSS);
        g_overlay_actboss_button = create_overlay_button(hwnd, "actboss:off",
                        174, 108, 122, 26, OVERLAY_BUTTON_ACTBOSS);
        g_overlay_auto_switch_button = create_overlay_button(hwnd, "auto:off",
                        302, 108, 104, 26, OVERLAY_BUTTON_AUTO_SWITCH);
        create_overlay_button(hwnd, "-30s", 76, 144, 42, 26,
                              OVERLAY_BUTTON_LOCK_MINUS30);
        create_overlay_button(hwnd, "-10s", 122, 144, 42, 26,
                              OVERLAY_BUTTON_LOCK_MINUS10);
        g_overlay_lock_interval_label = CreateWindowExA(
                        0, "STATIC", "60s(--s)",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_CENTER | SS_CENTERIMAGE,
                        168, 144, 82, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_LOCK_INTERVAL,
                        g_self_module, NULL);
        create_overlay_button(hwnd, "+10s", 254, 144, 42, 26,
                              OVERLAY_BUTTON_LOCK_PLUS10);
        create_overlay_button(hwnd, "+30s", 300, 144, 42, 26,
                              OVERLAY_BUTTON_LOCK_PLUS30);
        g_overlay_lock_button = create_overlay_button(hwnd, "lock",
                        346, 144, 80, 26, OVERLAY_BUTTON_LOCK_STAGE);
        g_overlay_lock_stage_label = CreateWindowExA(
                        0, "STATIC", "--",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_LEFT | SS_CENTERIMAGE,
                        434, 144, 90, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_LOCK_STAGE,
                        g_self_module, NULL);
        g_overlay_chest_intervals_label = CreateWindowExA(
                        0, "STATIC", "N count 0 last -- best --/-- next --\r\nB count 0 last -- best --/-- next --",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_LEFT,
                        76, 182, 590, 44,
                        hwnd, (HMENU)(uintptr_t)OVERLAY_LABEL_CHEST_INTERVALS,
                        g_self_module, NULL);
        apply_overlay_fonts(hwnd);
        update_overlay_label();
        update_exp_multiplier_labels();
        update_boss_button();
        update_actboss_button();
        update_auto_switch_button();
        update_lock_button(hwnd);
        update_lock_stage_label();
        update_lock_interval_label();
        update_chest_interval_label();
        SetTimer(hwnd, 1, 500, NULL);
        return 0;
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        paint_overlay_chrome(hwnd, hdc);
        EndPaint(hwnd, &ps);
        return 0;
    }
    case WM_DRAWITEM:
        if (((DRAWITEMSTRUCT *)lp)->CtlType == ODT_BUTTON) {
            draw_overlay_button((const DRAWITEMSTRUCT *)lp);
            return TRUE;
        }
        break;
    case WM_CTLCOLORSTATIC:
    case WM_CTLCOLOREDIT: {
        HDC hdc = (HDC)wp;
        HWND child = (HWND)lp;
        init_overlay_style();
        if (child == g_overlay_label ||
            child == g_overlay_exp_multiplier_label ||
            child == g_overlay_cube_multiplier_label) {
            SetBkMode(hdc, OPAQUE);
            SetBkColor(hdc, OVERLAY_COLOR_PANEL);
            SetTextColor(hdc, OVERLAY_COLOR_ACCENT);
            return (LRESULT)g_overlay_panel_brush;
        }
        if (child == g_overlay_lock_interval_label) {
            SetBkMode(hdc, OPAQUE);
            SetBkColor(hdc, OVERLAY_COLOR_PANEL);
            SetTextColor(hdc, OVERLAY_COLOR_ACCENT);
            return (LRESULT)g_overlay_panel_brush;
        }
        if (child == g_overlay_lock_stage_label) {
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, OVERLAY_COLOR_ACCENT);
            return (LRESULT)g_overlay_bg_brush;
        }
        if (child == g_overlay_chest_intervals_label) {
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, OVERLAY_COLOR_TEXT);
            return (LRESULT)g_overlay_bg_brush;
        }
        SetBkMode(hdc, TRANSPARENT);
        SetTextColor(hdc, OVERLAY_COLOR_TEXT);
        return (LRESULT)g_overlay_bg_brush;
    }
    case WM_CTLCOLORBTN:
        init_overlay_style();
        return (LRESULT)g_overlay_button_brush;
    case WM_NCHITTEST: {
        LRESULT hit = DefWindowProcA(hwnd, msg, wp, lp);
        if (hit == HTCLIENT) return HTCAPTION;
        return hit;
    }
    case WM_ENTERSIZEMOVE:
        g_overlay_dragging = 1;
        g_overlay_user_moved = 1;
        return 0;
    case WM_EXITSIZEMOVE:
        g_overlay_dragging = 0;
        g_overlay_user_moved = 1;
        persist_overlay_position(hwnd);
        return 0;
    case WM_TIMER:
        position_overlay(hwnd);
        update_lock_button(hwnd);
        update_lock_stage_label();
        update_lock_interval_label();
        update_auto_switch_button();
        update_exp_multiplier_labels();
        update_chest_interval_label();
        return 0;
    case WM_COMMAND:
        if (LOWORD(wp) == OVERLAY_BUTTON_MIN) {
            set_speed_value(g_speed_min);
            update_overlay_label();
            log_line("speed set by overlay: min");
            save_config();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_MINUS5) {
            adjust_speed(-5.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_MINUS1) {
            adjust_speed(-1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_PLUS1) {
            adjust_speed(1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_PLUS5) {
            adjust_speed(5.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_MAX) {
            set_speed_value(g_speed_max);
            update_overlay_label();
            log_line("speed set by overlay: max");
            save_config();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_EXP_MINUS) {
            adjust_exp_multiplier_value(-1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_EXP_PLUS) {
            adjust_exp_multiplier_value(1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_CUBE_MINUS) {
            adjust_cube_exp_multiplier_value(-1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_CUBE_PLUS) {
            adjust_cube_exp_multiplier_value(1.0f);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_BOSS) {
            set_direct_boss_enabled(!g_direct_boss_enabled);
            update_boss_button();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ACTBOSS) {
            set_actboss_boss_enabled(!g_actboss_boss_enabled);
            update_actboss_button();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_AUTO_SWITCH) {
            set_auto_switch_enabled(!g_auto_switch_enabled);
            update_auto_switch_button();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_LOCK_MINUS30) {
            adjust_auto_portal_interval_seconds(-30);
            update_lock_interval_label();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_LOCK_MINUS10) {
            adjust_auto_portal_interval_seconds(-10);
            update_lock_interval_label();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_LOCK_PLUS10) {
            adjust_auto_portal_interval_seconds(10);
            update_lock_interval_label();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_LOCK_PLUS30) {
            adjust_auto_portal_interval_seconds(30);
            update_lock_interval_label();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_LOCK_STAGE) {
            if (auto_restart_effective_locked()) {
                queue_auto_restart_request(AUTO_RESTART_REQUEST_UNLOCK);
            } else {
                queue_auto_restart_request(AUTO_RESTART_REQUEST_LOCK);
            }
            update_lock_button(hwnd);
            update_lock_stage_label();
            update_lock_interval_label();
            return 0;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        g_overlay_hwnd = NULL;
        g_overlay_label = NULL;
        g_overlay_exp_multiplier_label = NULL;
        g_overlay_cube_multiplier_label = NULL;
        g_overlay_boss_button = NULL;
        g_overlay_actboss_button = NULL;
        g_overlay_auto_switch_button = NULL;
        g_overlay_lock_button = NULL;
        g_overlay_lock_interval_label = NULL;
        g_overlay_lock_stage_label = NULL;
        g_overlay_chest_intervals_label = NULL;
        destroy_overlay_style();
        PostQuitMessage(0);
        return 0;
    default:
        break;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

static DWORD WINAPI overlay_thread(LPVOID arg)
{
    (void)arg;
    WNDCLASSA wc;
    char overlay_class_name[80];
    int initial_x = 100;
    int initial_y = 100;
    unsigned char *wc_bytes = (unsigned char *)&wc;
    for (SIZE_T i = 0; i < sizeof(wc); i++) wc_bytes[i] = 0;
    wsprintfA(overlay_class_name, "%s%p", OVERLAY_CLASS_PREFIX, g_self_module);
    close_old_overlay_windows();
    if (g_previous_overlay_position_valid) {
        initial_x = g_previous_overlay_rect.left;
        initial_y = g_previous_overlay_rect.top;
        g_overlay_user_moved = 1;
    }

    wc.lpfnWndProc = overlay_wnd_proc;
    wc.hInstance = g_self_module;
    wc.lpszClassName = overlay_class_name;
    wc.hbrBackground = NULL;
    wc.hCursor = LoadCursorA(NULL, IDC_ARROW);

    RegisterClassA(&wc);

    g_overlay_hwnd = CreateWindowExA(
        WS_EX_TOPMOST | WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
        overlay_class_name,
        OVERLAY_WINDOW_TITLE,
        WS_POPUP,
        initial_x, initial_y, OVERLAY_WIDTH, OVERLAY_HEIGHT,
        NULL, NULL, g_self_module, NULL);

    if (!g_overlay_hwnd) {
        log_line("CreateWindowEx overlay failed, error=%lu", GetLastError());
        return 0;
    }

    position_overlay(g_overlay_hwnd);
    ShowWindow(g_overlay_hwnd, SW_SHOWNOACTIVATE);
    log_line("overlay created");

    MSG msg;
    while (GetMessageA(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    return 0;
}

static void *resolve_time_icall(const char **names, int count)
{
    if (!g_resolve_icall) return NULL;
    for (int i = 0; i < count; i++) {
        void *p = g_resolve_icall(names[i]);
        if (p) {
            log_line("resolved icall %s => %p", names[i], p);
            return p;
        }
    }
    return NULL;
}

static int resolve_unity_time_calls(HMODULE game_assembly)
{
    static const char *delta_names[] = {
        "UnityEngine.Time::get_deltaTime()",
        "UnityEngine.Time::get_deltaTime"
    };
    static const char *get_scale_names[] = {
        "UnityEngine.Time::get_timeScale()",
        "UnityEngine.Time::get_timeScale"
    };
    static const char *set_scale_names[] = {
        "UnityEngine.Time::set_timeScale(System.Single)",
        "UnityEngine.Time::set_timeScale"
    };

    g_resolve_icall = (resolve_icall_t)GetProcAddress(game_assembly, "il2cpp_resolve_icall");
    if (!g_resolve_icall) return 0;

    g_real_get_delta_time = (unity_time_get_t)resolve_time_icall(delta_names, 2);
    g_real_get_time_scale = (unity_time_get_t)resolve_time_icall(get_scale_names, 2);
    g_real_set_time_scale = (unity_time_set_t)resolve_time_icall(set_scale_names, 2);

    return g_real_get_delta_time && g_real_set_time_scale;
}

static int resolve_unity_screen_calls(void)
{
    static const char *get_width_names[] = {
        "UnityEngine.Screen::get_width()",
        "UnityEngine.Screen::get_width"
    };
    static const char *get_height_names[] = {
        "UnityEngine.Screen::get_height()",
        "UnityEngine.Screen::get_height"
    };
    static const char *set_fullscreen_names[] = {
        "UnityEngine.Screen::set_fullScreen(System.Boolean)",
        "UnityEngine.Screen::set_fullScreen"
    };
    static const char *set_fullscreen_mode_names[] = {
        "UnityEngine.Screen::set_fullScreenMode(UnityEngine.FullScreenMode)",
        "UnityEngine.Screen::set_fullScreenMode"
    };
    static const char *set_resolution_injected_names[] = {
        "UnityEngine.Screen::SetResolution_Injected(System.Int32,System.Int32,UnityEngine.FullScreenMode,UnityEngine.RefreshRate&)"
    };
    static const char *set_resolution_bool3_names[] = {
        "UnityEngine.Screen::SetResolution(System.Int32,System.Int32,System.Boolean)",
        "UnityEngine.Screen::SetResolution"
    };
    static const char *set_resolution_bool4_names[] = {
        "UnityEngine.Screen::SetResolution(System.Int32,System.Int32,System.Boolean,System.Int32)"
    };
    static const char *set_resolution_mode4_names[] = {
        "UnityEngine.Screen::SetResolution(System.Int32,System.Int32,UnityEngine.FullScreenMode,System.Int32)"
    };

    g_screen_get_width = (unity_screen_get_int_t)resolve_time_icall(get_width_names, 2);
    g_screen_get_height = (unity_screen_get_int_t)resolve_time_icall(get_height_names, 2);
    g_screen_set_fullscreen = (unity_screen_set_bool_t)resolve_time_icall(set_fullscreen_names, 2);
    g_screen_set_fullscreen_mode = (unity_screen_set_int_t)resolve_time_icall(set_fullscreen_mode_names, 2);
    g_screen_set_resolution_injected =
        (unity_screen_set_resolution_injected_t)resolve_time_icall(set_resolution_injected_names, 1);
    g_screen_set_resolution_mode4 =
        (unity_screen_set_resolution_mode4_t)resolve_time_icall(set_resolution_mode4_names, 1);
    g_screen_set_resolution_bool4 =
        (unity_screen_set_resolution_bool4_t)resolve_time_icall(set_resolution_bool4_names, 1);
    g_screen_set_resolution_bool3 =
        (unity_screen_set_resolution_bool3_t)resolve_time_icall(set_resolution_bool3_names, 2);

    if (!g_screen_set_fullscreen && !g_screen_set_fullscreen_mode &&
        !g_screen_set_resolution_injected && !g_screen_set_resolution_bool3 &&
        !g_screen_set_resolution_bool4 && !g_screen_set_resolution_mode4) {
        log_line("Unity Screen windowed icalls not resolved");
        return 0;
    }
    return 1;
}

static int install_unity_time_hooks(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    int ok = 1;
    const unsigned char prologue_stack_28[] = {0x48, 0x83, 0xEC, 0x28};
    const unsigned char prologue_stack_38[] = {0x48, 0x83, 0xEC, 0x38};
    void *delta_target = (void *)(base + RVA_TIME_GET_DELTATIME);
    void *get_scale_target = (void *)(base + RVA_TIME_GET_TIMESCALE);
    void *set_scale_target = (void *)(base + RVA_TIME_SET_TIMESCALE);

    int delta_original =
        ((unsigned char *)delta_target)[0] == prologue_stack_28[0] &&
        ((unsigned char *)delta_target)[1] == prologue_stack_28[1] &&
        ((unsigned char *)delta_target)[2] == prologue_stack_28[2] &&
        ((unsigned char *)delta_target)[3] == prologue_stack_28[3];
    int set_original =
        ((unsigned char *)set_scale_target)[0] == prologue_stack_38[0] &&
        ((unsigned char *)set_scale_target)[1] == prologue_stack_38[1] &&
        ((unsigned char *)set_scale_target)[2] == prologue_stack_38[2] &&
        ((unsigned char *)set_scale_target)[3] == prologue_stack_38[3];
    int delta_abs_jump =
        ((unsigned char *)delta_target)[0] == 0x48 &&
        ((unsigned char *)delta_target)[1] == 0xB8 &&
        ((unsigned char *)delta_target)[10] == 0xFF &&
        ((unsigned char *)delta_target)[11] == 0xE0;
    int set_abs_jump =
        ((unsigned char *)set_scale_target)[0] == 0x48 &&
        ((unsigned char *)set_scale_target)[1] == 0xB8 &&
        ((unsigned char *)set_scale_target)[10] == 0xFF &&
        ((unsigned char *)set_scale_target)[11] == 0xE0;

    if ((!delta_original && !delta_abs_jump) ||
        (!set_original && !set_abs_jump)) {
        log_line("Unity Time RVAs unexpected for this build");
        return 0;
    }

    ok &= write_absolute_jump(delta_target, (void *)hook_time_get_delta_time,
                              &g_hook_delta_time);
    ok &= write_absolute_jump(set_scale_target, (void *)hook_time_set_time_scale,
                              &g_hook_set_time_scale);
    if (g_real_get_time_scale) {
        ok &= write_absolute_jump(get_scale_target, (void *)hook_time_get_time_scale,
                                  &g_hook_get_time_scale);
    }

    if (ok) {
        int sx = speed_x100();
        log_line("Unity Time hooks installed at base=%p speed=%d.%02d",
                 game_assembly, sx / 100, sx % 100);
    }
    return ok;
}

#ifndef TBHS_STANDALONE_DLL
static FARPROC get_real_proc(const char *name)
{
    if (!g_real_winhttp) {
        char sysdir[MAX_PATH];
        char path[MAX_PATH];
        UINT len = GetSystemDirectoryA(sysdir, sizeof(sysdir));
        if (len == 0 || len >= sizeof(sysdir)) {
            lstrcpyA(path, "C:\\Windows\\System32\\winhttp.dll");
        } else {
            wsprintfA(path, "%s\\winhttp.dll", sysdir);
            path[sizeof(path) - 1] = 0;
        }
        g_real_winhttp = LoadLibraryA(path);
        if (!g_real_winhttp) {
            log_line("failed to load real winhttp.dll, error=%lu", GetLastError());
            return NULL;
        }
    }
    return GetProcAddress(g_real_winhttp, name);
}
#endif

static DWORD WINAPI speed_thread(LPVOID arg)
{
    (void)arg;
    init_paths();
    load_config();
    if (!validate_runtime_versions()) {
        return 0;
    }
    load_chest_stats();
#ifdef TBHS_STANDALONE_DLL
    log_line("standalone speed dll loaded");
#else
    log_line("winhttp proxy loaded");
#endif

    HMODULE game_assembly = NULL;
    for (int i = 0; i < 240; i++) {
        game_assembly = GetModuleHandleA(GAMEASSEMBLY_NAME);
        if (game_assembly) break;
        Sleep(500);
    }

    if (!game_assembly) {
        log_line("GameAssembly.dll not loaded");
        return 0;
    }
    g_game_assembly = game_assembly;

    for (int i = 0; i < 240; i++) {
        if (resolve_unity_time_calls(game_assembly)) break;
        Sleep(500);
    }

    if (!g_real_get_delta_time || !g_real_set_time_scale) {
        log_line("failed to resolve Unity Time icalls");
        return 0;
    }

    resolve_unity_screen_calls();

    if (!install_unity_time_hooks(game_assembly)) {
        log_line("failed to install hooks");
        return 0;
    }
    restore_legacy_bad_stage_manager_enter_hook(game_assembly);
    if (!install_stagecache_jgm_hook(game_assembly)) {
        log_line("actboss boss hook not installed");
    }
    g_last_auto_portal_tick = GetTickCount();
    apply_direct_boss_patch();
    apply_free_actboss_enter_patch();
    restore_drop_rate_calc_hooks((uintptr_t)game_assembly);
    if (!install_exp_reward_calc_hook(game_assembly)) {
        restore_exp_reward_calc_hook(game_assembly);
        log_line("exp reward hook not installed");
    }
    if (!install_cube_add_exp_hook(game_assembly)) {
        restore_cube_add_exp_hook(game_assembly);
        log_line("cube exp hook not installed");
    }
    if (g_drop_hooks_enabled) {
        if (g_force_drop_roll_rate_enabled) {
            apply_drop_cooldown_bypass_patch();
            apply_reward_item_capacity_bypass_patch();
        } else {
            restore_drop_cooldown_bypass_patch();
            restore_reward_item_capacity_bypass_patch();
        }
        install_drop_rate_observer_hooks(game_assembly);
        install_give_reward_item_hook(game_assembly);
        install_reward_add_item_hook(game_assembly);
        if (g_reward_trace_hooks_enabled) {
            install_box_count_get_hook(game_assembly);
        } else {
            restore_box_count_hook(game_assembly);
        }
        if (g_reward_trace_hooks_enabled ||
            g_force_box_reward_select_enabled ||
            g_keep_boxdata_after_select_enabled) {
            install_box_reward_select_hook(game_assembly);
        } else {
            restore_box_reward_select_hook(game_assembly);
        }
        if (!g_reward_trace_hooks_enabled) log_line("reward trace hooks disabled");
        if (g_force_box_reward_select_enabled) log_line("force box reward select enabled");
        if (g_keep_boxdata_after_select_enabled) log_line("keep boxdata after select enabled");
        install_drop_roll_process_hook(game_assembly);
    } else {
        restore_drop_related_patches(game_assembly);
        log_line("drop hooks disabled");
    }
    enforce_game_title_bar();

    InterlockedExchange(&g_initialized, 1);

    if (g_overlay_enabled) {
        HANDLE overlay = CreateThread(NULL, 0, overlay_thread, NULL, 0, NULL);
        if (overlay) CloseHandle(overlay);
    }

    while (1) {
        enforce_game_title_bar();
        if (g_background_apply && g_real_set_time_scale) {
            g_real_set_time_scale(g_speed);
        }
        Sleep(g_apply_interval_ms);
    }
}

#ifndef TBHS_STANDALONE_DLL
__declspec(dllexport)
HINTERNET_LOCAL WINAPI WinHttpOpen(LPCWSTR agent, DWORD access_type,
                                   LPCWSTR proxy_name, LPCWSTR proxy_bypass,
                                   DWORD flags)
{
    pWinHttpOpen fn = (pWinHttpOpen)get_real_proc("WinHttpOpen");
    if (!fn) return NULL;
    return fn(agent, access_type, proxy_name, proxy_bypass, flags);
}

__declspec(dllexport)
BOOL WINAPI WinHttpGetIEProxyConfigForCurrentUser(
    void *config)
{
    pWinHttpGetIEProxyConfigForCurrentUser fn =
        (pWinHttpGetIEProxyConfigForCurrentUser)
            get_real_proc("WinHttpGetIEProxyConfigForCurrentUser");
    if (!fn) {
        return FALSE;
    }
    return fn(config);
}

__declspec(dllexport)
BOOL WINAPI WinHttpGetProxyForUrl(HINTERNET_LOCAL session, LPCWSTR url,
                                  void *options, void *proxy_info)
{
    pWinHttpGetProxyForUrl fn =
        (pWinHttpGetProxyForUrl)get_real_proc("WinHttpGetProxyForUrl");
    if (!fn) return FALSE;
    return fn(session, url, options, proxy_info);
}

__declspec(dllexport)
BOOL WINAPI WinHttpCloseHandle(HINTERNET_LOCAL handle)
{
    pWinHttpCloseHandle fn =
        (pWinHttpCloseHandle)get_real_proc("WinHttpCloseHandle");
    if (!fn) return FALSE;
    return fn(handle);
}
#endif

BOOL WINAPI DllMain(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    (void)reserved;
    if (reason == DLL_PROCESS_ATTACH) {
        g_self_module = (HMODULE)hinst;
        DisableThreadLibraryCalls(hinst);
        HANDLE thread = CreateThread(NULL, 0, speed_thread, NULL, 0, NULL);
        if (thread) CloseHandle(thread);
    }
    return TRUE;
}

BOOL WINAPI DllMainCRTStartup(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    return DllMain(hinst, reason, reserved);
}
