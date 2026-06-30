#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>
#include <stdarg.h>

#define TBHS_SUPPORTED_GAME_VERSION "1.00.21"
#define TBHS_PLUGIN_VERSION "1.00.21"
#define TBHS_PLUGIN_SUBVERSION "412"
#define TBHS_PLUGIN_DISPLAY_VERSION "1.00.21.412"
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
#define RVA_UI_CUBE_HML 0xA20FD0ULL /* UI_Cube init; caches the active UI_Cube instance */
#define RVA_UI_CUBE_ON_DISABLE 0xA20DF0ULL
#define RVA_UI_CUBE_ON_DESTROY 0xA20D60ULL
#define RVA_UI_CUBE_AUTOFILL 0xA22150ULL /* UI_Cube auto-fill current recipe */
#define RVA_UI_MANAGER_SHOW_UI_BASE 0xC391A0ULL /* UIManager.hhf shows a UI_Base main tab */
#define RVA_UI_MAIN_OPEN_CUBE 0x82E6B0ULL /* UI_Main cube tab button handler */
#define RVA_CUBE_TYPEINFO 0x5DC88E0ULL /* uz.Cube_TypeInfo */
#define RVA_CUBE_SELECT_RECIPE_TYPE 0x8A0950ULL /* uz.Cube.imr(ERecipeType) selects current recipe */
#define RVA_UI_MANAGER_TYPEINFO 0x5E3D880ULL /* np<UIManager>_TypeInfo */
#define RVA_SLOT_MANAGER_TYPEINFO 0x5E40D28ULL /* np<rd>_TypeInfo; item slot move manager */
#define RVA_SLOT_MANAGER_MOVE_ALL 0x87FEC0ULL /* rd.hyp(sourceType, targetType), used by UI_RemakeStash.lmo */
#define RVA_MASTER_DATA_SINGLETON_TYPEINFO 0x5E40568ULL /* np<bam>_TypeInfo; bam holds itemInfoData */
#define RVA_ITEM_CACHE_BY_UNIQUE_ID 0x909D00ULL /* uz.uc.izf(ulong) returns uz.uc.ua item cache */
#define RVA_ITEM_CACHE_STORE_TYPEINFO 0x5DC9198ULL /* uz.uc_TypeInfo owns live item cache dictionary */
#define RVA_ITEM_CACHE_GET_MANUAL_LOCK 0x901180ULL /* uz.uc.ua.iws() manual lock flag */
#define RVA_ITEM_CACHE_SET_MANUAL_LOCK 0x903480ULL /* uz.uc.ua.iyj/klu(bool) sets manual lock */
#define RVA_CUBE_SET_USE_STORAGE 0x8A3050ULL
#define RVA_CUBE_SET_SYNTHESIS_TYPE 0x89F690ULL
#define RVA_CUBE_CLEAR_CURRENT_RECIPE 0x8AD760ULL /* Cube clear current recipe slots */
#define RVA_CUBE_AUTOFILL_CURRENT_RECIPE 0x941B40ULL /* backend auto-fill dispatcher used by UI_Cube.kzn */
#define RVA_CUBE_TRIGGER_CURRENT_RECIPE 0x8A3F00ULL
#define RVA_CUBE_SYNTHESIS_CORE 0x8CD370ULL /* Cube synthesis state-machine core */
#define RVA_STAGE_BOX_REFRESH_AUTO_OPEN 0xA29490ULL /* StageBox::lkc refreshes auto-open cd */
#define RVA_AUTO_CHEST_OPEN_MOVE_NEXT 0xA31D30ULL /* StageBox AutoChestOpenAsync MoveNext */
#define RVA_STAT_VALUE_GET 0x9D5A20ULL
#define RVA_GIVE_REWARD_ITEM 0x9097E0ULL
#define RVA_REWARD_ADD_ITEM 0x909AB0ULL
#define RVA_BOX_COUNT_GET 0x0ULL
#define RVA_BOX_REWARD_SELECT 0x975850ULL /* vy::BoxData(int) selects concrete reward from stage box key */
#define RVA_DICT_TRY_GET_VALUE 0x2D09070ULL /* Dictionary<EBoxType, List<BoxData>>.TryGetValue */
#define RVA_BOX_REWARD_TRY_GET_METHODINFO 0x5DDAE18ULL /* MethodInfo used by box reward dictionary */
#define RVA_BOX_DATA_GET_REWARD_ITEM_ID 0x967670ULL
#define RVA_BOX_DATA_GET_REWARD_ITEM_UNIQUE_ID 0x967690ULL
#define RVA_IL2CPP_GC_WRITE_BARRIER 0x58F760ULL /* write barrier used after managed reference stores */
#define RVA_OPEN_BOX_STATS 0x9EC280ULL /* yw::kor(EBoxType) returns auto-open max/reduce seconds */
#define RVA_DROP_ROLL_PROCESS 0x891400ULL
#define RVA_DROP_REWARD_CALLBACK 0x0ULL /* 0 = wildcard active delegate invoke */
#define RVA_DROP_COOLDOWN_SKIP_BRANCH 0x89161BULL /* preserved/manual */
#define RVA_REWARD_ITEM_CONFIG_EARLY_RETURN_BRANCH 0x90988DULL /* manual branch inside reward item */
#define RVA_REWARD_ITEM_CAPACITY_SKIP_BRANCH 0x9098EBULL /* manual branch inside reward item */
/* END TASKBARHERO GENERATED RVAS */

#define STAGE_DATA_STAGE_LIST_OFFSET 56
#define STAGE_DATA_CURRENT_CACHE_OFFSET 136
#define UI_MANAGER_CURRENT_MAIN_TAB_OFFSET 0x54
#define UI_MANAGER_UI_MAIN_OFFSET 0xA8
#define UI_MANAGER_UI_HERO_OFFSET 0xB0
#define UI_MANAGER_UI_CUBE_OFFSET 0xD8
#define UI_MANAGER_UI_NEW_STASH_OFFSET 0xE8
#define CUBE_CURRENT_RECIPE_OFFSET 0x140
#define ITEM_DATA_ITEM_LIST_OFFSET 0x20
#define ITEM_INFO_ITEM_KEY_OFFSET 0x30
#define ITEM_INFO_ITEM_TYPE_OFFSET 0x34
#define ITEM_INFO_GRADE_OFFSET 0x38
#define ITEM_INFO_GEAR_TYPE_OFFSET 0x40
#define ITEM_INFO_NAME_KEY_OFFSET 0x50
#define ITEM_INFO_ICON_PATH_OFFSET 0x78
#define UI_HERO_INVENTORY_SLOTS_OFFSET 0x78
#define UI_REMAKE_STASH_SLOT_LIST_OFFSET 0x60
#define ITEM_SLOT_ITEM_CACHE_OFFSET 0xB8
#define ITEM_CACHE_ITEM_INFO_OFFSET 0x10
#define ITEM_CACHE_EQUIP_CLASS_OFFSET 0x30
#define IL2CPP_STRING_LENGTH_OFFSET 0x10
#define IL2CPP_STRING_CHARS_OFFSET 0x14
#define STAGE_BOX_BOX_TYPE_OFFSET 0x38
#define STAGE_BOX_AUTO_OPEN_DURATION_OFFSET 0x108
#define STAGE_BOX_AUTO_OPEN_SECONDS_OFFSET 0x10C
#define STAGE_BOX_AUTO_OPEN_ELAPSED_OFFSET 0x114
#define STAGE_BOX_AUTO_OPEN_PAUSED_ELAPSED_OFFSET 0x118
#define STAGE_BOX_AUTO_OPEN_ENABLED_OFFSET 0x128
#define AUTO_CHEST_OPEN_STATE_STAGE_BOX_OFFSET 0x10
#define IL2CPP_TYPE_STATIC_FIELDS_OFFSET 184
#define IL2CPP_LIST_ITEMS_OFFSET 16
#define IL2CPP_LIST_SIZE_OFFSET 24
#define IL2CPP_ARRAY_LENGTH_OFFSET 24
#define IL2CPP_ARRAY_DATA_OFFSET 32
#define IL2CPP_DICT_ENTRIES_OFFSET 24
#define IL2CPP_DICT_COUNT_OFFSET 32
#define IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET 0
#define IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET 8
#define IL2CPP_DICT_U64_OBJECT_ENTRY_VALUE_OFFSET 16
#define IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE 24
#define ESTAGE_TYPE_NORMAL 0
#define ESTAGE_TYPE_ACTBOSS 1

#define OVERLAY_CLASS_PREFIX "TaskBarHeroSpeedOverlay_"
#define OVERLAY_DISPLAY_TITLE "TaskBarHero"
#define OVERLAY_WINDOW_TITLE "TaskBarHero Overlay"
#define OVERLAY_OLD_WINDOW_TITLE "TaskBarHero Speed"
#define OVERLAY_WIDTH 684
#define OVERLAY_HEIGHT 430
#define OVERLAY_LOG_ONLY_HEIGHT 166
#define OVERLAY_MINIMIZED_HEIGHT 34
#define OVERLAY_VIEW_BUTTON_SIZE 24
#define OVERLAY_VIEW_BUTTON_GAP 4
#define OVERLAY_VIEW_BUTTON_TOP 4
#define OVERLAY_VIEW_BUTTON_EXPANDED_X (OVERLAY_WIDTH - 12 - (OVERLAY_VIEW_BUTTON_SIZE * 3 + OVERLAY_VIEW_BUTTON_GAP * 2))
#define OVERLAY_VIEW_BUTTON_LOG_ONLY_X (OVERLAY_VIEW_BUTTON_EXPANDED_X + OVERLAY_VIEW_BUTTON_SIZE + OVERLAY_VIEW_BUTTON_GAP)
#define OVERLAY_VIEW_BUTTON_MINIMIZED_X (OVERLAY_VIEW_BUTTON_LOG_ONLY_X + OVERLAY_VIEW_BUTTON_SIZE + OVERLAY_VIEW_BUTTON_GAP)
#define OVERLAY_LOG_ONLY_BOX_TOP 42
#define OVERLAY_LOG_LINE_COUNT 128
#define OVERLAY_LOG_VISIBLE_LINES 8
#define OVERLAY_LOG_LINE_SIZE 220
#define OVERLAY_LOG_FILTER_LEFT 12
#define OVERLAY_LOG_FILTER_WIDTH 126
#define OVERLAY_LOG_FILTER_ROW_HEIGHT 22
#define OVERLAY_LOG_FILTER_CHECK_SIZE 12
#define OVERLAY_LOG_BOX_LEFT 148
#define OVERLAY_LOG_BOX_TOP 304
#define OVERLAY_LOG_BOX_WIDTH 518
#define OVERLAY_LOG_BOX_HEIGHT 112
#define OVERLAY_LOG_FILTER_PRICED 1
#define OVERLAY_LOG_FILTER_LEGENDARY 2
#define OVERLAY_LOG_FILTER_MARKET_TOP 4
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
#define OVERLAY_BUTTON_SYNTH_TOGGLE 1025
#define OVERLAY_BUTTON_SYNTH_STORAGE 1029
#define OVERLAY_BUTTON_ITEM_LOCK_LIST 1030
#define OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE 1031
#define OVERLAY_BUTTON_ITEM_LOCK_COIN 1032
#define OVERLAY_BUTTON_ITEM_LOCK_MANUAL 1033
#define OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP 1034
#define OVERLAY_BUTTON_VIEW_EXPANDED 1035
#define OVERLAY_BUTTON_VIEW_LOG_ONLY 1036
#define OVERLAY_BUTTON_VIEW_MINIMIZED 1037
#define OVERLAY_VIEW_MODE_EXPANDED 0
#define OVERLAY_VIEW_MODE_LOG_ONLY 1
#define OVERLAY_VIEW_MODE_MINIMIZED 2
#define ITEM_LOCK_LIST_CLASS_PREFIX "TaskBarHeroItemLockList_"
#define ITEM_LOCK_LIST_CONTROL_TYPE 2001
#define ITEM_LOCK_LIST_CONTROL_GRADE 2002
#define ITEM_LOCK_LIST_CONTROL_LIST 2003
#define ITEM_LOCK_LIST_CONTROL_OK 2004
#define ITEM_LOCK_LIST_CONTROL_CANCEL 2005
#define ITEM_LOCK_LIST_CONTROL_STATUS 2006
#define ITEM_LOCK_LIST_CONTROL_CLEAR 2007
#define ITEM_LOCK_LIST_CONTROL_CLASS 2008
#define ITEM_LOCK_LIST_CONTROL_SEARCH 2009
#define ITEM_LOCK_LIST_TIMER_REFRESH 1
#define ITEM_LOCK_LIST_ROW_HEIGHT 32
#define ITEM_LOCK_LIST_ICON_SIZE 22
#define ITEM_LOCK_ICON_DIR_NAME "TaskBarHeroSpeedIcons"
#define ITEM_LOCK_ICON_TRANSPARENT_KEY RGB(255, 0, 255)
#define ITEM_LOCK_NAME_TABLE_FILE "TaskBarHeroSpeedItemNames.zh-Hans.tsv"
#define ITEM_LOCK_MARKET_TOP_FILE "TaskBarHeroSpeedMarketTop100.tsv"
#define ITEM_MARKET_PRICES_FILE "TaskBarHeroSpeedMarketPrices.tsv"
#define ITEM_MARKET_LAST_SOLD_LABEL "最后:"
#define AUTO_ITEM_LOCK_NAME_MAX 8192
#define AUTO_ITEM_LOCK_NAME_FILE_MAX_BYTES 1048576
#define AUTO_PORTAL_INTERVAL_MIN_MS 5000
#define AUTO_PORTAL_INTERVAL_MAX_MS 3600000
#define AUTO_OPEN_BOX_SECONDS 5
#define AUTO_SYNTHESIS_INTERVAL_MS 3000
#define AUTO_SYNTHESIS_BOX_OPEN_DELAY_MS 2000
#define AUTO_SYNTHESIS_FILL_DELAY_MS 3000
#define AUTO_SYNTHESIS_TRIGGER_DELAY_MS 2000
#define AUTO_SYNTHESIS_POST_TRIGGER_CLEAR_DELAY_MS 1000
#define AUTO_SYNTHESIS_RESULT_WATCH_MS 5000
#define AUTO_STORAGE_INTERVAL_MS 300000
#define BOX_REWARD_RESULT_WATCH_MS 4000
#define ACTBOSS_BOX_ITEM_KEY 930801
#define ACTBOSS_CACHE_WATCH_MS 15000
#define ACTBOSS_CACHE_WATCH_COOLDOWN_MS 2500
#define ACTBOSS_CACHE_WATCH_SCAN_INTERVAL_MS 250
#define ACTBOSS_CACHE_WATCH_MAX_IDS 32768
#define SYNTHESIS_CACHE_WATCH_MS 10000
#define SYNTHESIS_CACHE_WATCH_SCAN_INTERVAL_MS 100
#define SYNTHESIS_CACHE_WATCH_MAX_IDS 32768
#define RECENT_BOX_REWARD_IGNORE_MS 60000
#define RECENT_BOX_REWARD_MAX 64
#define AUTO_SYNTHESIS_PHASE_IDLE 0
#define AUTO_SYNTHESIS_PHASE_WAIT_FILL 2
#define AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER 3
#define AUTO_SYNTHESIS_PHASE_WAIT_CLEAR 4
#define AUTO_RESTART_REQUEST_NONE 0
#define AUTO_RESTART_REQUEST_LOCK 1
#define AUTO_RESTART_REQUEST_UNLOCK 2
#define AUTO_SWITCH_WAIT_NONE 0
#define AUTO_SWITCH_WAIT_NORMAL_DROP 1
#define AUTO_SWITCH_WAIT_BOSS_DROP 2
#define ERECIPE_SYNTHESIS 1
#define EMAIN_TAB_CUBE 4
#define ESLOT_TYPE_INVENTORY 1
#define ESLOT_TYPE_STASH 2
#define EMOVE_TYPE_EXPLICIT_SLOT 0
#define EITEM_SYNTHESIS_GEAR 0
#define EGRADE_LEGENDARY 3
#define EGRADE_BEYOND 6
#define EGRADE_CELESTIAL 7
#define EGRADE_DIVINE 8
#define EGRADE_COSMIC 9
#define AUTO_ITEM_LOCK_MAX_ITEMS 8192
#define AUTO_ITEM_LOCK_MAX_SELECTED 2048
#define AUTO_ITEM_LOCK_MARKET_TOP_MAX_IDS 512
#define AUTO_ITEM_MARKET_PRICE_MAX_IDS 8192
#define AUTO_ITEM_LOCK_COIN_MIN 160000
#define AUTO_ITEM_LOCK_COIN_MAX 160020
#define EITEM_TYPE_STAGEBOX 0
#define EITEM_TYPE_MATERIAL 1
#define EITEM_TYPE_GEAR 2
#define EGRADE_NONE 10
#define EEQUIP_CLASS_UNKNOWN -1
#define EEQUIP_CLASS_ALL 0
#define EEQUIP_CLASS_KNIGHT 1
#define EEQUIP_CLASS_RANGER 2
#define EEQUIP_CLASS_SORCERER 3
#define EEQUIP_CLASS_PRIEST 4
#define EEQUIP_CLASS_HUNTER 5
#define EEQUIP_CLASS_SLAYER 6
#define EGEAR_TYPE_SWORD 1
#define EGEAR_TYPE_BOW 2
#define EGEAR_TYPE_STAFF 3
#define EGEAR_TYPE_SCEPTER 4
#define EGEAR_TYPE_CROSSBOW 5
#define EGEAR_TYPE_AXE 6
#define EGEAR_TYPE_SHIELD 7
#define EGEAR_TYPE_ARROW 8
#define EGEAR_TYPE_ORB 9
#define EGEAR_TYPE_TOME 10
#define EGEAR_TYPE_BOLT 11
#define EGEAR_TYPE_HATCHET 12
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
typedef int (__fastcall *box_data_get_int_t)(void *box_data, void *method);
typedef void *(__fastcall *box_data_get_string_t)(void *box_data, void *method);
typedef unsigned char (__fastcall *dict_try_get_value_t)(void *dict, unsigned int key, void **out_value, void *method);
typedef __int64 (__fastcall *gc_write_barrier_t)(void *slot, void *obj);
typedef __int64 (__fastcall *open_box_stats_t)(void *account_status, int box_type, void *method);
typedef void (__fastcall *drop_roll_process_t)(void *stage_manager, int source_id, int stage_type, int item_key, float raw_rate, int monster_type);
typedef void (__fastcall *drop_reward_callback_t)(void *target, unsigned int reward_value, void *method);
typedef float (__fastcall *drop_rate_calc_t)(void *rate_owner, float raw_rate, void *method);
typedef float (__fastcall *exp_reward_calc_t)(void *reward_owner, float base_exp, int is_boss, char is_actboss, void *method);
typedef void (__fastcall *cube_add_exp_t)(float amount, void *method);
typedef __int64 (__fastcall *cube_synthesis_core_t)(void *state_machine);
typedef __int64 (__fastcall *ui_cube_instance_t)(void *ui_cube, void *method);
typedef void (__fastcall *ui_manager_show_base_t)(void *ui_manager, void *ui_base, void *method);
typedef void (__fastcall *ui_main_action_t)(void *ui_main, void *method);
typedef __int64 (__fastcall *slot_manager_move_all_t)(void *slot_manager, int source_type, int target_type, void *method);
typedef __int64 (__fastcall *cube_set_bool_t)(char value, void *method);
typedef __int64 (__fastcall *cube_set_int_t)(int value, void *method);
typedef __int64 (__fastcall *cube_clear_current_recipe_t)(void *method);
typedef unsigned char (__fastcall *cube_select_recipe_t)(int recipe_type, void *method);
typedef __int64 (__fastcall *cube_autofill_current_recipe_t)(void *recipe, void *method);
typedef __int64 (__fastcall *cube_trigger_current_recipe_t)(void *method);
typedef __int64 (__fastcall *auto_chest_open_move_next_t)(void *state_machine, void *method);
typedef void *(__fastcall *item_cache_by_unique_id_t)(unsigned __int64 unique_id);
typedef unsigned char (__fastcall *item_cache_get_manual_lock_t)(void *item_cache);
typedef __int64 (__fastcall *item_cache_set_manual_lock_t)(void *item_cache, unsigned char locked);

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

typedef struct AutoItemLockInfo {
    unsigned int item_id;
    int item_type;
    int grade;
    int equip_class;
    char name_key[96];
    char display_name[160];
    char icon_path[160];
    HBITMAP icon_bitmap;
    int icon_bitmap_status;
} AutoItemLockInfo;

typedef struct AutoItemLockNameEntry {
    char key[96];
    char name[160];
} AutoItemLockNameEntry;

typedef struct AutoItemMarketPriceEntry {
    unsigned int item_id;
    unsigned int price_cents;
    unsigned __int64 last_sold_at;
    char name_zh_hans[160];
    char base_name_zh_hans[120];
    char grade_name_zh_hans[32];
} AutoItemMarketPriceEntry;

typedef struct OverlayLogEntry {
    char line[OVERLAY_LOG_LINE_SIZE];
    int grade;
    unsigned int item_id;
} OverlayLogEntry;

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

typedef BOOL (WINAPI *transparent_blt_t)(HDC, int, int, int, int,
                                         HDC, int, int, int, int, UINT);

static HMODULE g_self_module;
#ifndef TBHS_STANDALONE_DLL
static HMODULE g_real_winhttp;
#endif
static char g_base_dir[MAX_PATH];
static char g_game_dir[MAX_PATH];
static char g_config_dir[MAX_PATH];
static char g_log_path[MAX_PATH];
static char g_item_log_path[MAX_PATH];
static char g_chest_stats_path[MAX_PATH];
static char g_detected_game_version[32];
static char g_config_target_game_version[32];
static char g_config_plugin_version[32];
static char g_config_plugin_subversion[16];
static volatile LONG g_initialized;
static HMODULE g_msimg32;
static transparent_blt_t g_transparent_blt;
static int g_transparent_blt_checked;

static float g_speed = SPEED_DEFAULT;
static float g_speed_min = 1.0f;
static float g_speed_max = 30.0f;
static float g_speed_step = 1.0f;
static int g_background_apply = 0;
static int g_overlay_enabled = 1;
static int g_overlay_x = 20;
static int g_overlay_y = 80;
static int g_overlay_view_mode = OVERLAY_VIEW_MODE_EXPANDED;
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
static int g_auto_synthesis_enabled = 0;
static int g_auto_synthesis_use_storage = 1;
static int g_auto_item_lock_enabled = 1;
static int g_item_lock_condition_high_grade = 1;
static int g_item_lock_condition_coin = 1;
static int g_item_lock_condition_market_top = 1;
static AutoItemLockInfo g_auto_item_lock_catalog[AUTO_ITEM_LOCK_MAX_ITEMS];
static int g_auto_item_lock_catalog_count = 0;
static DWORD g_auto_item_lock_last_catalog_log_tick = 0;
static DWORD g_auto_item_lock_last_catalog_try_tick = 0;
static volatile LONG g_auto_item_lock_catalog_version = 0;
static volatile LONG g_auto_item_lock_catalog_preload_pending = 0;
static AutoItemLockNameEntry g_auto_item_lock_name_table[AUTO_ITEM_LOCK_NAME_MAX];
static int g_auto_item_lock_name_count = 0;
static int g_auto_item_lock_names_loaded = 0;
static unsigned int g_auto_item_lock_selected_ids[AUTO_ITEM_LOCK_MAX_SELECTED];
static int g_auto_item_lock_selected_count = 0;
static unsigned int g_auto_item_lock_market_top_ids[AUTO_ITEM_LOCK_MARKET_TOP_MAX_IDS];
static int g_auto_item_lock_market_top_count = 0;
static AutoItemMarketPriceEntry g_item_market_prices[AUTO_ITEM_MARKET_PRICE_MAX_IDS];
static int g_item_market_price_count = 0;
static unsigned int g_auto_item_lock_temp_ids[AUTO_ITEM_LOCK_MAX_SELECTED];
static int g_auto_item_lock_temp_count = 0;
static volatile LONG g_auto_item_lock_pending = 0;
static unsigned int g_auto_item_lock_pending_item_id = 0;
static unsigned __int64 g_auto_item_lock_pending_unique_id = 0;
static char g_auto_item_lock_pending_unique_key[64];
static DWORD g_auto_item_lock_pending_tick = 0;
static DWORD g_auto_item_lock_last_try_tick = 0;
static volatile LONG g_manual_item_lock_pending = 0;
static volatile LONG g_speed_dirty = 1;

static HMODULE g_game_assembly;
static resolve_icall_t g_resolve_icall;
static unity_time_get_t g_real_get_delta_time;
static unity_time_get_t g_real_get_time_scale;
static unity_time_set_t g_real_set_time_scale;
static DWORD g_game_thread_id;

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
static HookPatch g_hook_open_box_stats;
static HookPatch g_hook_auto_chest_open_move_next;
static HookPatch g_hook_drop_roll_process;
static HookPatch g_hook_normal_drop_rate_observer;
static HookPatch g_hook_boss_drop_rate_observer;
static HookPatch g_hook_exp_reward_calc;
static HookPatch g_hook_cube_add_exp;
static HookPatch g_hook_cube_synthesis_core;
static HookPatch g_hook_ui_cube_hml;
static HookPatch g_hook_ui_cube_on_disable;
static HookPatch g_hook_ui_cube_on_destroy;
static HWND g_overlay_hwnd;
static HWND g_overlay_label;
static HWND g_overlay_exp_multiplier_label;
static HWND g_overlay_cube_multiplier_label;
static HWND g_overlay_synth_button;
static HWND g_overlay_synth_storage_button;
static HWND g_overlay_item_lock_high_grade_button;
static HWND g_overlay_item_lock_coin_button;
static HWND g_overlay_item_lock_market_top_button;
static HWND g_overlay_item_lock_manual_button;
static HWND g_overlay_boss_button;
static HWND g_overlay_actboss_button;
static HWND g_overlay_auto_switch_button;
static HWND g_overlay_lock_button;
static HWND g_overlay_item_lock_list_button;
static HWND g_overlay_lock_interval_label;
static HWND g_overlay_lock_stage_label;
static HWND g_overlay_chest_intervals_label;
static HWND g_item_lock_list_hwnd;
static HWND g_item_lock_type_combo;
static HWND g_item_lock_grade_combo;
static HWND g_item_lock_class_label;
static HWND g_item_lock_class_combo;
static HWND g_item_lock_search_edit;
static HWND g_item_lock_listbox;
static HWND g_item_lock_status_label;
static WNDPROC g_item_lock_listbox_old_proc;
static LONG g_item_lock_list_catalog_version_seen;
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
static open_box_stats_t g_real_open_box_stats;
static auto_chest_open_move_next_t g_real_auto_chest_open_move_next;
static drop_roll_process_t g_real_drop_roll_process;
static drop_reward_callback_t g_real_drop_reward_callback;
static drop_rate_calc_t g_real_normal_drop_rate_calc;
static drop_rate_calc_t g_real_boss_drop_rate_calc;
static exp_reward_calc_t g_real_exp_reward_calc;
static cube_add_exp_t g_real_cube_add_exp;
static cube_synthesis_core_t g_real_cube_synthesis_core;
static ui_cube_instance_t g_real_ui_cube_hml;
static ui_cube_instance_t g_real_ui_cube_on_disable;
static ui_cube_instance_t g_real_ui_cube_on_destroy;
static volatile LONG_PTR g_cached_ui_cube;
static DWORD g_auto_synthesis_next_tick;
static DWORD g_auto_synthesis_step_tick;
static DWORD g_auto_synthesis_result_watch_until;
static int g_auto_synthesis_phase;
static volatile LONG g_auto_synthesis_pending;
static volatile LONG g_auto_synthesis_result_pending;
static DWORD g_last_auto_synthesis_log_tick;
static DWORD g_periodic_storage_next_tick;
static DWORD g_box_reward_result_watch_until;
static volatile LONG g_box_reward_result_pending;
static unsigned int g_box_reward_expected_item_id;
static unsigned int g_box_reward_box_item_key;
static unsigned __int64 g_recent_box_reward_unique_ids[RECENT_BOX_REWARD_MAX];
static unsigned int g_recent_box_reward_item_ids[RECENT_BOX_REWARD_MAX];
static DWORD g_recent_box_reward_ticks[RECENT_BOX_REWARD_MAX];
static int g_recent_box_reward_next;
static volatile LONG g_actboss_cache_watch_active;
static DWORD g_actboss_cache_watch_until;
static DWORD g_actboss_cache_watch_last_begin_tick;
static DWORD g_actboss_cache_watch_last_scan_tick;
static unsigned __int64 g_actboss_cache_watch_seen_ids[ACTBOSS_CACHE_WATCH_MAX_IDS];
static int g_actboss_cache_watch_seen_count;
static int g_actboss_cache_watch_logged_count;
static int g_actboss_cache_watch_synthesis_requested;
static volatile LONG g_synthesis_cache_watch_active;
static DWORD g_synthesis_cache_watch_until;
static DWORD g_synthesis_cache_watch_last_scan_tick;
static unsigned __int64 g_synthesis_cache_watch_seen_ids[SYNTHESIS_CACHE_WATCH_MAX_IDS];
static int g_synthesis_cache_watch_seen_count;
static int g_synthesis_cache_watch_logged_count;
static DWORD g_last_open_box_stats_log_tick;
static DWORD g_last_auto_chest_open_cd_log_tick;
static int g_open_box_stats_hook_installed;
static void *g_cached_boxdata_by_type[3];
static unsigned int g_cached_boxdata_item_by_type[3];
static DropObservationContext g_drop_observation;
static volatile LONG g_drop_log_spin;
static volatile LONG g_drop_log_version;
static OverlayLogEntry g_drop_log_entries[OVERLAY_LOG_LINE_COUNT];
static int g_drop_log_next;
static int g_drop_log_count;
static int g_drop_log_scroll;
static int g_drop_log_filter_flags;
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

static int install_box_reward_select_hook(HMODULE game_assembly);
static void restore_box_reward_select_hook(HMODULE game_assembly);
static int box_reward_select_hook_needed(void);
static void update_box_reward_select_hook(HMODULE game_assembly);

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
static const unsigned char k_original_ui_cube_hml_prefix[] = {
    0x40, 0x56,
    0x48, 0x83, 0xEC, 0x20,
    0x80, 0x3D, 0x4E, 0x39, 0x72, 0x05, 0x00,
    0x48, 0x8B, 0xF1
};
static const unsigned char k_original_ui_cube_on_disable_prefix[] = {
    0x40, 0x53,
    0x48, 0x83, 0xEC, 0x20,
    0x80, 0x3D, 0x31, 0x3B, 0x72, 0x05, 0x00,
    0x48, 0x8B, 0xD9
};
static const unsigned char k_original_ui_cube_on_destroy_prefix[] = {
    0x48, 0x89, 0x5C, 0x24, 0x08,
    0x48, 0x89, 0x74, 0x24, 0x10,
    0x57,
    0x48, 0x83, 0xEC, 0x20
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
static const unsigned char k_original_open_box_stats[] = {
    0x40, 0x53,
    0x48, 0x83, 0xEC, 0x20,
    0x48, 0xC7, 0x44, 0x24, 0x48, 0x00, 0x00, 0x00, 0x00,
    0x48, 0x8B, 0xD9
};
static const unsigned char k_original_auto_chest_open_move_next[] = {
    0x48, 0x8B, 0xC4,
    0x48, 0x89, 0x58, 0x10,
    0x48, 0x89, 0x48, 0x08,
    0x56,
    0x57,
    0x41, 0x56,
    0x48, 0x81, 0xEC, 0x00, 0x01, 0x00, 0x00
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
static const unsigned char k_original_cube_synthesis_core[] = {
    0x48, 0x89, 0x5C, 0x24, 0x10,
    0x48, 0x89, 0x74, 0x24, 0x20,
    0x48, 0x89, 0x4C, 0x24, 0x08
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

static void zero_memory_local(void *dst, SIZE_T n)
{
    unsigned char *d = (unsigned char *)dst;
    for (SIZE_T i = 0; i < n; i++) d[i] = 0;
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

static const char *find_text_local(const char *s, const char *needle)
{
    int needle_len;

    if (!s || !needle || !needle[0]) return NULL;
    needle_len = lstrlenA(needle);
    for (; *s; s++) {
        int i;
        for (i = 0; i < needle_len; ++i) {
            if (!s[i] || s[i] != needle[i]) break;
        }
        if (i == needle_len) return s;
    }
    return NULL;
}

static int contains_text_local(const char *s, const char *needle)
{
    return find_text_local(s, needle) ? 1 : 0;
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

static int read_il2cpp_string_utf8(void *string_obj, char *buf, int buflen)
{
    int len;
    WCHAR *chars;
    int written;
    SIZE_T bytes;

    if (!buf || buflen <= 0) return 0;
    buf[0] = 0;
    if (!string_obj ||
        !memory_range_readable(string_obj,
                               IL2CPP_STRING_CHARS_OFFSET + sizeof(WCHAR))) {
        return 0;
    }
    len = *(int *)((unsigned char *)string_obj + IL2CPP_STRING_LENGTH_OFFSET);
    if (len < 0 || len > 4096) return 0;
    if (!len) return 1;
    chars = (WCHAR *)((unsigned char *)string_obj + IL2CPP_STRING_CHARS_OFFSET);
    bytes = (SIZE_T)len * sizeof(WCHAR);
    if (!memory_range_readable(chars, bytes)) return 0;
    written = WideCharToMultiByte(CP_UTF8, 0, chars, len,
                                  buf, buflen - 1, NULL, NULL);
    if (written <= 0) return 0;
    buf[written] = 0;
    return 1;
}

static void log_line(const char *fmt, ...);
static void append_overlay_event(const char *fmt, ...);
static void append_overlay_item_event(const char *action,
                                      unsigned int item_id,
                                      int locked);
static void trim(char *s);
static void clean_item_display_text(const char *src, char *dst, int dst_size);
static void auto_switch_on_chest_drop(unsigned int box_type);
static void save_config(void);
static int read_il2cpp_string_utf8(void *string_obj, char *buf, int buflen);
static void load_auto_item_lock_ids(const char *text);
static void save_auto_item_lock_ids(char *buf, int buflen);
static void load_auto_item_lock_market_top_ids(void);
static void load_item_market_prices(void);
static void update_item_lock_list_button(void);
static void update_item_lock_condition_buttons(void);
static void open_item_lock_list_window(void);
static const char *auto_item_lock_class_name(int equip_class);
static int auto_item_lock_catalog_class_from_gear_type(int gear_type);
static const char *auto_item_lock_type_name(int item_type);
static const char *auto_item_lock_grade_name(int grade);
static COLORREF auto_item_lock_grade_color(int grade);
static int auto_item_lock_catalog_copy(unsigned int item_id,
                                       AutoItemLockInfo *out_info);
static int lookup_auto_item_lock_localized_name(const char *key,
                                                char *buf,
                                                int buflen);
static int auto_item_lock_item_matches_conditions(unsigned int item_id,
                                                  int item_type,
                                                  int grade);
static int load_auto_item_lock_catalog_from_game(void);
static void *get_item_cache_dictionary(uintptr_t base);
static void queue_manual_item_lock_request(void);
static void begin_box_reward_result_watch(unsigned int box_item_key,
                                          unsigned int expected_item_id);
static void begin_synthesis_cache_watch(const char *source);
static void maybe_handle_synthesis_cache_watch_from_game_thread(void);
static void maybe_handle_box_reward_add(unsigned int item_id,
                                        unsigned int result_low,
                                        unsigned int result_high);
static void maybe_handle_auto_synthesis_reward_add(unsigned int item_id,
                                                   unsigned int result_low,
                                                   unsigned int result_high);
static void maybe_handle_manual_synthesis_reward_add(unsigned int item_id,
                                                     unsigned int result_low,
                                                     unsigned int result_high,
                                                     int box_pending_before,
                                                     int synth_pending_before);
static int handle_box_reward_select_item(unsigned int box_item_key,
                                         unsigned int reward_item_id,
                                         const char *reward_unique_key);
static int handle_box_reward_auto_item_lock(unsigned int box_item_key,
                                            unsigned int reward_item_id,
                                            const char *reward_unique_key);

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

static int item_key_is_stage_box_candidate(unsigned int item_key)
{
    return item_key >= 900000 && item_key < 1000000;
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

static void reset_auto_synthesis_state(void)
{
    g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_IDLE;
    g_auto_synthesis_next_tick = 0;
    g_auto_synthesis_step_tick = 0;
    g_auto_synthesis_result_watch_until = 0;
    InterlockedExchange(&g_auto_synthesis_pending, 0);
    InterlockedExchange(&g_auto_synthesis_result_pending, 0);
}

static void request_auto_synthesis_after_box_open(unsigned int box_item_key,
                                                  unsigned int selected_item)
{
    unsigned int box_type = 0;
    DWORD now;

    if (!g_auto_synthesis_enabled) return;
    if (!item_key_is_stage_box_candidate(box_item_key)) return;
    if (!item_key_to_box_type(box_item_key, &box_type)) box_type = 3;

    now = GetTickCount();
    InterlockedExchange(&g_auto_synthesis_pending, 1);
    if (g_auto_synthesis_phase == AUTO_SYNTHESIS_PHASE_IDLE) {
        g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_BOX_OPEN_DELAY_MS;
    }
    log_line("auto synthesis requested after box open: type=%s box_item=%u selected_item=%u delay=%lu active_phase=%d",
             box_type_name(box_type),
             box_item_key,
             selected_item,
             (unsigned long)AUTO_SYNTHESIS_BOX_OPEN_DELAY_MS,
             g_auto_synthesis_phase);
}

static void maybe_request_auto_synthesis_from_reward_item(unsigned int item_key,
                                                          const char *source)
{
    unsigned int box_type = 0;

    if (!g_auto_synthesis_enabled) return;
    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId()) {
        return;
    }
    if (!item_key_is_stage_box_candidate(item_key)) return;
    if (!item_key_to_box_type(item_key, &box_type)) box_type = 3;
    log_line("auto synthesis reward fallback: source=%s type=%s item_key=%u",
             source ? source : "-",
             box_type_name(box_type),
             item_key);
    request_auto_synthesis_after_box_open(item_key, 0);
}

static void set_auto_synthesis_enabled(int enabled)
{
    g_auto_synthesis_enabled = enabled ? 1 : 0;
    reset_auto_synthesis_state();
    log_line("auto synthesis %s", g_auto_synthesis_enabled ? "enabled" : "disabled");
    update_box_reward_select_hook(g_game_assembly);
    save_config();
}

static void set_auto_synthesis_use_storage(int enabled)
{
    g_auto_synthesis_use_storage = enabled ? 1 : 0;
    reset_auto_synthesis_state();
    g_periodic_storage_next_tick = 0;
    log_line("auto synthesis use storage %s",
             g_auto_synthesis_use_storage ? "enabled" : "disabled");
    save_config();
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

static int auto_item_lock_id_index(const unsigned int *ids,
                                   int count,
                                   unsigned int item_id)
{
    int i;

    for (i = 0; i < count; ++i) {
        if (ids[i] == item_id) return i;
    }
    return -1;
}

static int auto_item_lock_selected(unsigned int item_id)
{
    return auto_item_lock_id_index(g_auto_item_lock_selected_ids,
                                   g_auto_item_lock_selected_count,
                                   item_id) >= 0;
}

static int auto_item_lock_market_top_selected(unsigned int item_id)
{
    return auto_item_lock_id_index(g_auto_item_lock_market_top_ids,
                                   g_auto_item_lock_market_top_count,
                                   item_id) >= 0;
}

static int auto_item_lock_is_coin_item(unsigned int item_id)
{
    return item_id >= AUTO_ITEM_LOCK_COIN_MIN &&
           item_id <= AUTO_ITEM_LOCK_COIN_MAX;
}

static int auto_item_lock_item_matches_conditions(unsigned int item_id,
                                                  int item_type,
                                                  int grade)
{
    if (!item_id) return 0;
    if (auto_item_lock_selected(item_id)) return 1;
    if (g_item_lock_condition_market_top &&
        auto_item_lock_market_top_selected(item_id)) {
        return 1;
    }
    if (g_item_lock_condition_coin && auto_item_lock_is_coin_item(item_id)) {
        return 1;
    }
    if (g_item_lock_condition_high_grade &&
        (item_type == EITEM_TYPE_GEAR || item_type == EITEM_TYPE_MATERIAL) &&
        (grade == EGRADE_DIVINE || grade == EGRADE_COSMIC)) {
        return 1;
    }
    return 0;
}

static int auto_item_lock_catalog_lookup(unsigned int item_id,
                                         int *out_type,
                                         int *out_grade,
                                         int *out_class)
{
    int i;

    if (!item_id) return 0;
    for (i = 0; i < g_auto_item_lock_catalog_count; ++i) {
        AutoItemLockInfo *info = &g_auto_item_lock_catalog[i];
        if (info->item_id != item_id) continue;
        if (out_type) *out_type = info->item_type;
        if (out_grade) *out_grade = info->grade;
        if (out_class) *out_class = info->equip_class;
        return 1;
    }
    return 0;
}

static int auto_item_lock_catalog_copy(unsigned int item_id,
                                       AutoItemLockInfo *out_info)
{
    int i;

    if (!item_id || !out_info) return 0;
    for (i = 0; i < g_auto_item_lock_catalog_count; ++i) {
        AutoItemLockInfo *info = &g_auto_item_lock_catalog[i];
        if (info->item_id != item_id) continue;
        *out_info = *info;
        return 1;
    }
    return 0;
}

static int auto_item_lock_reward_matches_conditions(unsigned int item_id)
{
    int item_type = -1;
    int grade = -1;

    if (!item_id) return 0;
    if (auto_item_lock_selected(item_id)) return 1;
    if (g_item_lock_condition_market_top &&
        auto_item_lock_market_top_selected(item_id)) {
        return 1;
    }
    if (g_item_lock_condition_coin && auto_item_lock_is_coin_item(item_id)) {
        return 1;
    }
    if (!g_item_lock_condition_high_grade) return 0;
    if (!auto_item_lock_catalog_lookup(item_id,
                                       &item_type,
                                       &grade,
                                       NULL)) {
        InterlockedExchange(&g_auto_item_lock_catalog_preload_pending, 1);
    }
    return auto_item_lock_item_matches_conditions(item_id, item_type, grade);
}

static void auto_item_lock_set_id(unsigned int *ids,
                                  int *count,
                                  unsigned int item_id,
                                  int selected)
{
    int index;

    if (!ids || !count || !item_id) return;
    index = auto_item_lock_id_index(ids, *count, item_id);
    if (selected) {
        if (index >= 0 || *count >= AUTO_ITEM_LOCK_MAX_SELECTED) return;
        ids[(*count)++] = item_id;
        return;
    }
    if (index < 0) return;
    for (; index < *count - 1; ++index) {
        ids[index] = ids[index + 1];
    }
    (*count)--;
}

static void load_auto_item_lock_ids(const char *text)
{
    const char *p = text;
    unsigned int value;

    g_auto_item_lock_selected_count = 0;
    while (p && *p) {
        while (*p == ' ' || *p == '\t' || *p == ',' || *p == ';') p++;
        value = 0;
        while (*p >= '0' && *p <= '9') {
            value = value * 10u + (unsigned int)(*p - '0');
            p++;
        }
        if (value) {
            auto_item_lock_set_id(g_auto_item_lock_selected_ids,
                                  &g_auto_item_lock_selected_count,
                                  value,
                                  1);
        }
        while (*p && *p != ',' && *p != ';') p++;
    }
}

static void save_auto_item_lock_ids(char *buf, int buflen)
{
    char item[32];
    int i;

    append_text_local(buf, buflen, "auto_item_lock_ids=");
    for (i = 0; i < g_auto_item_lock_selected_count; ++i) {
        if (i) append_text_local(buf, buflen, ",");
        wsprintfA(item, "%u", g_auto_item_lock_selected_ids[i]);
        item[sizeof(item) - 1] = 0;
        append_text_local(buf, buflen, item);
    }
    append_text_local(buf, buflen, "\r\n");
}

static void auto_item_lock_add_market_top_id(unsigned int item_id)
{
    if (!item_id) return;
    if (auto_item_lock_id_index(g_auto_item_lock_market_top_ids,
                                g_auto_item_lock_market_top_count,
                                item_id) >= 0) {
        return;
    }
    if (g_auto_item_lock_market_top_count >= AUTO_ITEM_LOCK_MARKET_TOP_MAX_IDS) {
        return;
    }
    g_auto_item_lock_market_top_ids[g_auto_item_lock_market_top_count++] = item_id;
}

static int item_market_price_index(unsigned int item_id)
{
    int i;

    for (i = 0; i < g_item_market_price_count; ++i) {
        if (g_item_market_prices[i].item_id == item_id) return i;
    }
    return -1;
}

static void copy_trimmed_range(const char *start,
                               const char *end,
                               char *buf,
                               int buflen)
{
    int len;

    if (buflen <= 0) return;
    buf[0] = 0;
    if (!start || !end || end < start) return;
    while (start < end &&
           (*start == ' ' || *start == '\t' ||
            *start == '\r' || *start == '\n')) {
        start++;
    }
    while (end > start &&
           (end[-1] == ' ' || end[-1] == '\t' ||
            end[-1] == '\r' || end[-1] == '\n')) {
        end--;
    }
    len = (int)(end - start);
    if (len >= buflen) len = buflen - 1;
    if (len > 0) {
        int i;
        for (i = 0; i < len; ++i) buf[i] = start[i];
        buf[len] = 0;
    }
}

static void item_market_price_set_name(AutoItemMarketPriceEntry *entry,
                                       const char *name_zh_hans)
{
    char *open_paren;
    char *close_paren;

    if (!entry) return;
    entry->name_zh_hans[0] = 0;
    entry->base_name_zh_hans[0] = 0;
    entry->grade_name_zh_hans[0] = 0;
    if (!name_zh_hans || !name_zh_hans[0]) return;

    lstrcpynA(entry->name_zh_hans,
              name_zh_hans,
              sizeof(entry->name_zh_hans));
    lstrcpynA(entry->base_name_zh_hans,
              name_zh_hans,
              sizeof(entry->base_name_zh_hans));
    open_paren = find_char(entry->base_name_zh_hans, '(');
    if (open_paren) {
        char *trim_end = open_paren;
        while (trim_end > entry->base_name_zh_hans &&
               (trim_end[-1] == ' ' || trim_end[-1] == '\t')) {
            trim_end--;
        }
        *trim_end = 0;
    }

    open_paren = find_char(entry->name_zh_hans, '(');
    close_paren = open_paren ? find_char(open_paren + 1, ')') : NULL;
    if (open_paren && close_paren && close_paren > open_paren + 1) {
        copy_trimmed_range(open_paren + 1,
                           close_paren,
                           entry->grade_name_zh_hans,
                           sizeof(entry->grade_name_zh_hans));
    }
}

static void item_market_price_add(unsigned int item_id,
                                  unsigned int price_cents,
                                  unsigned __int64 last_sold_at,
                                  const char *name_zh_hans)
{
    int index;

    if (!item_id || !price_cents || !last_sold_at) return;
    index = item_market_price_index(item_id);
    if (index >= 0) {
        g_item_market_prices[index].price_cents = price_cents;
        g_item_market_prices[index].last_sold_at = last_sold_at;
        item_market_price_set_name(&g_item_market_prices[index],
                                   name_zh_hans);
        return;
    }
    if (g_item_market_price_count >= AUTO_ITEM_MARKET_PRICE_MAX_IDS) return;
    g_item_market_prices[g_item_market_price_count].item_id = item_id;
    g_item_market_prices[g_item_market_price_count].price_cents = price_cents;
    g_item_market_prices[g_item_market_price_count].last_sold_at = last_sold_at;
    item_market_price_set_name(&g_item_market_prices[g_item_market_price_count],
                               name_zh_hans);
    g_item_market_price_count++;
}

static int item_market_price_lookup(unsigned int item_id,
                                    unsigned int *out_price_cents,
                                    unsigned __int64 *out_last_sold_at)
{
    int index = item_market_price_index(item_id);

    if (out_price_cents) *out_price_cents = 0;
    if (out_last_sold_at) *out_last_sold_at = 0;
    if (index < 0) return 0;
    if (out_price_cents) {
        *out_price_cents = g_item_market_prices[index].price_cents;
    }
    if (out_last_sold_at) {
        *out_last_sold_at = g_item_market_prices[index].last_sold_at;
    }
    return 1;
}

static int item_market_price_lookup_from_line(const char *line,
                                              unsigned int *out_price_cents,
                                              unsigned __int64 *out_last_sold_at)
{
    int i;

    if (out_price_cents) *out_price_cents = 0;
    if (out_last_sold_at) *out_last_sold_at = 0;
    if (!line || !line[0]) return 0;
    for (i = 0; i < g_item_market_price_count; ++i) {
        AutoItemMarketPriceEntry *entry = &g_item_market_prices[i];
        char grade_pattern[48];

        if (!entry->price_cents || !entry->base_name_zh_hans[0]) continue;
        if (!contains_text_local(line, entry->base_name_zh_hans)) continue;
        if (entry->grade_name_zh_hans[0]) {
            wsprintfA(grade_pattern, "[%s]", entry->grade_name_zh_hans);
            grade_pattern[sizeof(grade_pattern) - 1] = 0;
            if (!contains_text_local(line, grade_pattern)) continue;
        }
        if (out_price_cents) *out_price_cents = entry->price_cents;
        if (out_last_sold_at) *out_last_sold_at = entry->last_sold_at;
        return 1;
    }
    return 0;
}

static void format_market_last_sold_date(unsigned __int64 last_sold_at,
                                         char *buf,
                                         int buflen)
{
    ULARGE_INTEGER ticks;
    FILETIME utc_time;
    FILETIME local_time;
    SYSTEMTIME st;

    if (buflen <= 0) return;
    buf[0] = 0;
    if (!last_sold_at) return;

    ticks.QuadPart =
        (last_sold_at * 10000000ULL) + 116444736000000000ULL;
    utc_time.dwLowDateTime = ticks.LowPart;
    utc_time.dwHighDateTime = ticks.HighPart;
    if (!FileTimeToLocalFileTime(&utc_time, &local_time) ||
        !FileTimeToSystemTime(&local_time, &st)) {
        return;
    }
    wsprintfA(buf, "%u.%u", st.wMonth, st.wDay);
    buf[buflen - 1] = 0;
}

static void format_market_price_text(unsigned int price_cents,
                                     unsigned __int64 last_sold_at,
                                     char *buf,
                                     int buflen)
{
    char date_text[24];

    if (buflen <= 0) return;
    buf[0] = 0;
    if (!price_cents || !last_sold_at) return;
    format_market_last_sold_date(last_sold_at,
                                 date_text,
                                 sizeof(date_text));
    if (!date_text[0]) return;
    wsprintfA(buf,
              "成交价:%u.%02u " ITEM_MARKET_LAST_SOLD_LABEL "%s",
              price_cents / 100u,
              price_cents % 100u,
              date_text);
    buf[buflen - 1] = 0;
}

static void format_item_market_price(unsigned int item_id,
                                     char *buf,
                                     int buflen)
{
    unsigned int price_cents = 0;
    unsigned __int64 last_sold_at = 0;

    if (buflen <= 0) return;
    buf[0] = 0;
    if (!item_market_price_lookup(item_id,
                                  &price_cents,
                                  &last_sold_at) ||
        !price_cents ||
        !last_sold_at) {
        return;
    }
    format_market_price_text(price_cents, last_sold_at, buf, buflen);
}

static void append_item_market_price_to_log_line(const char *line,
                                                 unsigned int item_id,
                                                 char *out,
                                                 int out_size)
{
    unsigned int price_cents = 0;
    unsigned __int64 last_sold_at = 0;
    char price_text[48];
    const char *insert_at;
    int prefix_len;
    int has_price;

    if (out_size <= 0) return;
    out[0] = 0;
    if (!line || !line[0]) return;
    has_price = contains_text_local(line, "成交价:");
    if (has_price && contains_text_local(line, ITEM_MARKET_LAST_SOLD_LABEL)) {
        lstrcpynA(out, line, out_size);
        return;
    }
    if (item_id) {
        item_market_price_lookup(item_id,
                                 &price_cents,
                                 &last_sold_at);
    }
    if (!price_cents) {
        item_market_price_lookup_from_line(line,
                                           &price_cents,
                                           &last_sold_at);
    }
    if (!price_cents || !last_sold_at) {
        lstrcpynA(out, line, out_size);
        return;
    }

    if (has_price) {
        char date_text[24];

        format_market_last_sold_date(last_sold_at,
                                     date_text,
                                     sizeof(date_text));
        if (!date_text[0]) {
            lstrcpynA(out, line, out_size);
            return;
        }
        wsprintfA(price_text,
                  ITEM_MARKET_LAST_SOLD_LABEL "%s",
                  date_text);
        price_text[sizeof(price_text) - 1] = 0;
    } else {
        format_market_price_text(price_cents,
                                 last_sold_at,
                                 price_text,
                                 sizeof(price_text));
    }
    if (!price_text[0]) {
        lstrcpynA(out, line, out_size);
        return;
    }
    insert_at = find_text_local(line, "（");
    if (!insert_at) insert_at = line + lstrlenA(line);
    prefix_len = (int)(insert_at - line);
    if (prefix_len >= out_size) prefix_len = out_size - 1;
    copy_trimmed_range(line, line + prefix_len, out, out_size);
    append_text_local(out, out_size, " ");
    append_text_local(out, out_size, price_text);
    if (*insert_at) {
        append_text_local(out, out_size, " ");
        append_text_local(out, out_size, insert_at);
    }
}

static int parse_market_top_row(const char *start,
                                const char *end,
                                int has_rank,
                                unsigned int *out_item_id,
                                unsigned int *out_price_cents,
                                unsigned __int64 *out_last_sold_at,
                                char *out_name_zh_hans,
                                int out_name_size)
{
    const char *p = start;
    unsigned __int64 item_id = 0;
    unsigned __int64 price_cents = 0;
    unsigned __int64 last_sold_at = 0;

    if (out_item_id) *out_item_id = 0;
    if (out_price_cents) *out_price_cents = 0;
    if (out_last_sold_at) *out_last_sold_at = 0;
    if (out_name_size > 0) out_name_zh_hans[0] = 0;
    while (p < end && (*p == ' ' || *p == '\t' || *p == '\r')) p++;
    if (p >= end || *p == '#' || *p < '0' || *p > '9') return 0;

    while (p < end && *p >= '0' && *p <= '9') {
        item_id = item_id * 10ULL + (unsigned __int64)(*p - '0');
        p++;
    }
    if (!item_id || item_id > 0xffffffffULL) return 0;

    if (p < end && *p == '\t') {
        p++;
        while (p < end && *p >= '0' && *p <= '9') {
            price_cents = price_cents * 10ULL + (unsigned __int64)(*p - '0');
            p++;
        }
    }
    if (price_cents > 0xffffffffULL) price_cents = 0xffffffffULL;

    if (has_rank) {
        if (p < end && *p == '\t') p++;
        while (p < end && *p >= '0' && *p <= '9') p++;
    }
    if (p < end && *p == '\t') {
        p++;
        while (p < end && *p >= '0' && *p <= '9') {
            last_sold_at =
                last_sold_at * 10ULL +
                (unsigned __int64)(*p - '0');
            p++;
        }
    }
    if (!last_sold_at) return 0;

    if (out_name_zh_hans && out_name_size > 0) {
        int tabs_seen = 0;
        const char *name_start = NULL;
        const char *q;
        int name_tab = has_rank ? 5 : 4;

        for (q = start; q < end; ++q) {
            if (*q == '\t') {
                tabs_seen++;
                if (tabs_seen == name_tab) {
                    name_start = q + 1;
                    break;
                }
            }
        }
        if (name_start && name_start < end) {
            copy_trimmed_range(name_start,
                               end,
                               out_name_zh_hans,
                               out_name_size);
        }
    }

    if (out_item_id) *out_item_id = (unsigned int)item_id;
    if (out_price_cents) *out_price_cents = (unsigned int)price_cents;
    if (out_last_sold_at) *out_last_sold_at = last_sold_at;
    return 1;
}

static int load_market_file(const char *path,
                            int load_ids,
                            int load_prices,
                            int has_rank)
{
    HANDLE file;
    DWORD size;
    DWORD read = 0;
    char *data;
    DWORD pos = 0;
    int loaded_before = g_auto_item_lock_market_top_count;
    int prices_before = g_item_market_price_count;

    if (!path || !path[0]) return 0;
    file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) return 0;
    size = GetFileSize(file, NULL);
    if (size == INVALID_FILE_SIZE || size == 0 || size > 1048576) {
        CloseHandle(file);
        return 0;
    }
    data = (char *)HeapAlloc(GetProcessHeap(), 0, (SIZE_T)size + 1);
    if (!data) {
        CloseHandle(file);
        return 0;
    }
    if (!ReadFile(file, data, size, &read, NULL)) {
        HeapFree(GetProcessHeap(), 0, data);
        CloseHandle(file);
        return 0;
    }
    CloseHandle(file);
    data[read] = 0;

    while (pos < read) {
        DWORD line_start = pos;
        DWORD line_end;
        unsigned int item_id = 0;
        unsigned int price_cents = 0;
        unsigned __int64 last_sold_at = 0;
        char name_zh_hans[160];
        while (pos < read && data[pos] != '\n') pos++;
        line_end = pos;
        if (pos < read && data[pos] == '\n') pos++;
        while (line_end > line_start &&
               (data[line_end - 1] == '\r' || data[line_end - 1] == '\n')) {
            line_end--;
        }
        if (parse_market_top_row(data + line_start,
                                 data + line_end,
                                 has_rank,
                                 &item_id,
                                 &price_cents,
                                 &last_sold_at,
                                 name_zh_hans,
                                 sizeof(name_zh_hans))) {
            if (load_ids) auto_item_lock_add_market_top_id(item_id);
            if (load_prices) {
                item_market_price_add(item_id,
                                      price_cents,
                                      last_sold_at,
                                      name_zh_hans);
            }
        }
    }
    HeapFree(GetProcessHeap(), 0, data);
    if (load_prices && !load_ids) {
        return g_item_market_price_count - prices_before;
    }
    return g_auto_item_lock_market_top_count - loaded_before;
}

static int load_auto_item_lock_market_top_file(const char *path)
{
    return load_market_file(path, 1, 0, 1);
}

static int load_item_market_prices_from_file(const char *path)
{
    return load_market_file(path, 0, 1, 0);
}

static void load_auto_item_lock_market_top_ids(void)
{
    char path[MAX_PATH];
    int loaded = 0;

    g_auto_item_lock_market_top_count = 0;
    if (g_base_dir[0]) {
        wsprintfA(path, "%s\\%s", g_base_dir, ITEM_LOCK_MARKET_TOP_FILE);
        path[sizeof(path) - 1] = 0;
        loaded += load_auto_item_lock_market_top_file(path);
    }
    if (!loaded && g_config_dir[0] &&
        lstrcmpiA(g_config_dir, g_base_dir) != 0) {
        wsprintfA(path, "%s\\%s", g_config_dir, ITEM_LOCK_MARKET_TOP_FILE);
        path[sizeof(path) - 1] = 0;
        loaded += load_auto_item_lock_market_top_file(path);
    }

    if (loaded) {
        log_line("market top item lock list loaded: ids=%d file=%s",
                 g_auto_item_lock_market_top_count,
                 ITEM_LOCK_MARKET_TOP_FILE);
    } else {
        log_line("market top item lock list not found: %s",
                 ITEM_LOCK_MARKET_TOP_FILE);
    }
}

static void load_item_market_prices(void)
{
    char path[MAX_PATH];
    int loaded = 0;

    g_item_market_price_count = 0;
    if (g_base_dir[0]) {
        wsprintfA(path, "%s\\%s", g_base_dir, ITEM_MARKET_PRICES_FILE);
        path[sizeof(path) - 1] = 0;
        loaded += load_item_market_prices_from_file(path);
    }
    if (!loaded && g_config_dir[0] &&
        lstrcmpiA(g_config_dir, g_base_dir) != 0) {
        wsprintfA(path, "%s\\%s", g_config_dir, ITEM_MARKET_PRICES_FILE);
        path[sizeof(path) - 1] = 0;
        loaded += load_item_market_prices_from_file(path);
    }

    if (loaded) {
        log_line("market traded price list loaded: prices=%d file=%s",
                 g_item_market_price_count,
                 ITEM_MARKET_PRICES_FILE);
    } else {
        log_line("market traded price list not found: %s",
                 ITEM_MARKET_PRICES_FILE);
    }
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

static void append_overlay_log_line_with_grade(const char *line,
                                               int grade,
                                               unsigned int item_id)
{
    lock_drop_log();
    lstrcpynA(g_drop_log_entries[g_drop_log_next].line,
              line,
              OVERLAY_LOG_LINE_SIZE);
    g_drop_log_entries[g_drop_log_next].line[OVERLAY_LOG_LINE_SIZE - 1] = 0;
    g_drop_log_entries[g_drop_log_next].grade = grade;
    g_drop_log_entries[g_drop_log_next].item_id = item_id;
    g_drop_log_next = (g_drop_log_next + 1) % OVERLAY_LOG_LINE_COUNT;
    if (g_drop_log_count < OVERLAY_LOG_LINE_COUNT) g_drop_log_count++;
    g_drop_log_scroll = 0;
    unlock_drop_log();
    InterlockedIncrement(&g_drop_log_version);
    if (g_overlay_hwnd) {
        InvalidateRect(g_overlay_hwnd, NULL, FALSE);
    }
}

static void TBHS_UNUSED append_overlay_log_line(const char *line)
{
    append_overlay_log_line_with_grade(line, -1, 0);
}

static void append_loaded_item_log_line(const char *line,
                                        int grade,
                                        unsigned int item_id)
{
    if (!line || !line[0]) return;
    lock_drop_log();
    lstrcpynA(g_drop_log_entries[g_drop_log_next].line,
              line,
              OVERLAY_LOG_LINE_SIZE);
    g_drop_log_entries[g_drop_log_next].line[OVERLAY_LOG_LINE_SIZE - 1] = 0;
    g_drop_log_entries[g_drop_log_next].grade = grade;
    g_drop_log_entries[g_drop_log_next].item_id = item_id;
    g_drop_log_next = (g_drop_log_next + 1) % OVERLAY_LOG_LINE_COUNT;
    if (g_drop_log_count < OVERLAY_LOG_LINE_COUNT) g_drop_log_count++;
    g_drop_log_scroll = 0;
    unlock_drop_log();
}

static void persist_item_log_entry(const char *line,
                                   int grade,
                                   unsigned int item_id)
{
    HANDLE file;
    DWORD written = 0;
    char record[OVERLAY_LOG_LINE_SIZE + 64];

    if (!line || !line[0] || !g_item_log_path[0]) return;
    wsprintfA(record, "%d\t%u\t%s\r\n", grade, item_id, line);
    record[sizeof(record) - 1] = 0;
    file = CreateFileA(g_item_log_path,
                       FILE_APPEND_DATA,
                       FILE_SHARE_READ,
                       NULL,
                       OPEN_ALWAYS,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL);
    if (file == INVALID_HANDLE_VALUE) return;
    WriteFile(file, record, (DWORD)lstrlenA(record), &written, NULL);
    CloseHandle(file);
}

static void load_item_log_history(void)
{
    HANDLE file;
    DWORD size;
    DWORD read = 0;
    char *data;
    DWORD pos = 0;

    if (!g_item_log_path[0]) return;
    file = CreateFileA(g_item_log_path,
                       GENERIC_READ,
                       FILE_SHARE_READ | FILE_SHARE_WRITE,
                       NULL,
                       OPEN_EXISTING,
                       FILE_ATTRIBUTE_NORMAL,
                       NULL);
    if (file == INVALID_HANDLE_VALUE) return;
    size = GetFileSize(file, NULL);
    if (size == INVALID_FILE_SIZE || size == 0 || size > (1024 * 1024)) {
        CloseHandle(file);
        return;
    }
    data = (char *)HeapAlloc(GetProcessHeap(), 0, (SIZE_T)size + 1);
    if (!data) {
        CloseHandle(file);
        return;
    }
    if (!ReadFile(file, data, size, &read, NULL)) read = 0;
    CloseHandle(file);
    data[read] = 0;

    while (pos < read) {
        DWORD line_start = pos;
        DWORD line_end;
        DWORD text_start;
        DWORD field_start;
        int grade = -1;
        unsigned int loaded_item_id = 0;
        char line[OVERLAY_LOG_LINE_SIZE];
        char enriched_line[OVERLAY_LOG_LINE_SIZE];
        int sign = 1;

        while (pos < read && data[pos] != '\n') pos++;
        line_end = pos;
        if (pos < read && data[pos] == '\n') pos++;
        while (line_end > line_start &&
               (data[line_end - 1] == '\r' || data[line_end - 1] == '\n')) {
            line_end--;
        }
        if (line_end <= line_start) continue;

        text_start = line_start;
        if (data[text_start] == '-') {
            sign = -1;
            text_start++;
        }
        if (text_start < line_end &&
            data[text_start] >= '0' &&
            data[text_start] <= '9') {
            grade = 0;
            while (text_start < line_end &&
                   data[text_start] >= '0' &&
                   data[text_start] <= '9') {
                grade = grade * 10 + (int)(data[text_start] - '0');
                text_start++;
            }
            grade *= sign;
            if (text_start < line_end && data[text_start] == '\t') {
                text_start++;
            } else {
                grade = -1;
                text_start = line_start;
            }
        }
        field_start = text_start;
        if (field_start < line_end &&
            data[field_start] >= '0' &&
            data[field_start] <= '9') {
            unsigned __int64 parsed_item_id = 0;
            DWORD p = field_start;

            while (p < line_end &&
                   data[p] >= '0' &&
                   data[p] <= '9') {
                parsed_item_id =
                    parsed_item_id * 10ULL +
                    (unsigned __int64)(data[p] - '0');
                p++;
            }
            if (p < line_end && data[p] == '\t' &&
                parsed_item_id > 0 &&
                parsed_item_id <= 0xffffffffULL) {
                loaded_item_id = (unsigned int)parsed_item_id;
                text_start = p + 1;
            }
        }
        if (line_end <= text_start) continue;
        {
            DWORD copy_len = line_end - text_start;
            DWORD j;
            if (copy_len >= OVERLAY_LOG_LINE_SIZE) {
                copy_len = OVERLAY_LOG_LINE_SIZE - 1;
            }
            for (j = 0; j < copy_len; ++j) {
                line[j] = data[text_start + j];
            }
            line[copy_len] = 0;
        }
        append_item_market_price_to_log_line(line,
                                             loaded_item_id,
                                             enriched_line,
                                             sizeof(enriched_line));
        append_loaded_item_log_line(enriched_line, grade, loaded_item_id);
    }
    HeapFree(GetProcessHeap(), 0, data);
    InterlockedIncrement(&g_drop_log_version);
}

static int overlay_current_height(void)
{
    if (g_overlay_view_mode == OVERLAY_VIEW_MODE_MINIMIZED) {
        return OVERLAY_MINIMIZED_HEIGHT;
    }
    if (g_overlay_view_mode == OVERLAY_VIEW_MODE_LOG_ONLY) {
        return OVERLAY_LOG_ONLY_HEIGHT;
    }
    return OVERLAY_HEIGHT;
}

static RECT overlay_log_box_rect(void)
{
    RECT box;

    box.left = OVERLAY_LOG_BOX_LEFT;
    box.top = g_overlay_view_mode == OVERLAY_VIEW_MODE_LOG_ONLY ?
              OVERLAY_LOG_ONLY_BOX_TOP : OVERLAY_LOG_BOX_TOP;
    box.right = OVERLAY_LOG_BOX_LEFT + OVERLAY_LOG_BOX_WIDTH;
    box.bottom = box.top + OVERLAY_LOG_BOX_HEIGHT;
    return box;
}

static int point_in_drop_log_box(POINT pt)
{
    RECT box = overlay_log_box_rect();

    return PtInRect(&box, pt) ? 1 : 0;
}

static RECT overlay_drop_log_filter_row_rect(int filter_id)
{
    RECT box = overlay_log_box_rect();
    RECT rc;
    int row = 0;

    if (filter_id == OVERLAY_LOG_FILTER_LEGENDARY) {
        row = 1;
    } else if (filter_id == OVERLAY_LOG_FILTER_MARKET_TOP) {
        row = 2;
    }
    rc.left = OVERLAY_LOG_FILTER_LEFT;
    rc.top = box.top + 5 + row * OVERLAY_LOG_FILTER_ROW_HEIGHT;
    rc.right = OVERLAY_LOG_FILTER_LEFT + OVERLAY_LOG_FILTER_WIDTH;
    rc.bottom = rc.top + OVERLAY_LOG_FILTER_ROW_HEIGHT;
    return rc;
}

static int overlay_drop_log_filter_hit_test(POINT pt)
{
    RECT rc;

    rc = overlay_drop_log_filter_row_rect(OVERLAY_LOG_FILTER_PRICED);
    if (PtInRect(&rc, pt)) return OVERLAY_LOG_FILTER_PRICED;
    rc = overlay_drop_log_filter_row_rect(OVERLAY_LOG_FILTER_LEGENDARY);
    if (PtInRect(&rc, pt)) return OVERLAY_LOG_FILTER_LEGENDARY;
    rc = overlay_drop_log_filter_row_rect(OVERLAY_LOG_FILTER_MARKET_TOP);
    if (PtInRect(&rc, pt)) return OVERLAY_LOG_FILTER_MARKET_TOP;
    return 0;
}

static int drop_log_entry_matches_filters(const OverlayLogEntry *entry)
{
    int flags = g_drop_log_filter_flags;

    if (!entry || !entry->line[0]) return 0;
    if (!flags) return 1;
    if ((flags & OVERLAY_LOG_FILTER_PRICED) &&
        contains_text_local(entry->line, "成交价:")) {
        return 1;
    }
    if ((flags & OVERLAY_LOG_FILTER_LEGENDARY) &&
        entry->grade >= EGRADE_LEGENDARY &&
        entry->grade < EGRADE_NONE) {
        return 1;
    }
    if ((flags & OVERLAY_LOG_FILTER_MARKET_TOP) &&
        auto_item_lock_market_top_selected(entry->item_id)) {
        return 1;
    }
    return 0;
}

static void toggle_drop_log_filter(int filter_id)
{
    if (filter_id != OVERLAY_LOG_FILTER_PRICED &&
        filter_id != OVERLAY_LOG_FILTER_LEGENDARY &&
        filter_id != OVERLAY_LOG_FILTER_MARKET_TOP) {
        return;
    }
    g_drop_log_filter_flags ^= filter_id;
    lock_drop_log();
    g_drop_log_scroll = 0;
    unlock_drop_log();
    if (g_overlay_hwnd) {
        InvalidateRect(g_overlay_hwnd, NULL, FALSE);
    }
}

static void adjust_drop_log_scroll(int delta)
{
    int max_scroll;
    int filtered_count = 0;
    int changed = 0;

    if (!delta) return;
    lock_drop_log();
    if (g_drop_log_count > 0) {
        int count = g_drop_log_count;
        int start = g_drop_log_next - count;
        int i;

        while (start < 0) start += OVERLAY_LOG_LINE_COUNT;
        for (i = 0; i < count && i < OVERLAY_LOG_LINE_COUNT; ++i) {
            int index = (start + i) % OVERLAY_LOG_LINE_COUNT;
            if (drop_log_entry_matches_filters(&g_drop_log_entries[index])) {
                filtered_count++;
            }
        }
    }
    max_scroll = filtered_count > OVERLAY_LOG_VISIBLE_LINES ?
                 filtered_count - OVERLAY_LOG_VISIBLE_LINES : 0;
    g_drop_log_scroll += delta;
    if (g_drop_log_scroll < 0) g_drop_log_scroll = 0;
    if (g_drop_log_scroll > max_scroll) g_drop_log_scroll = max_scroll;
    changed = 1;
    unlock_drop_log();

    if (changed && g_overlay_hwnd) {
        RECT box;
        box = overlay_log_box_rect();
        InvalidateRect(g_overlay_hwnd, &box, FALSE);
    }
}

static void append_overlay_event(const char *fmt, ...)
{
    (void)fmt;
}

static void append_overlay_item_event(const char *action,
                                      unsigned int item_id,
                                      int locked)
{
    SYSTEMTIME st;
    AutoItemLockInfo info;
    char name[160];
    char price_text[48];
    char line[OVERLAY_LOG_LINE_SIZE];
    int grade = -1;
    int item_type = -1;

    if (!item_id) return;
    zero_memory_local(&info, sizeof(info));
    name[0] = 0;
    price_text[0] = 0;
    auto_item_lock_catalog_copy(item_id, &info);
    if (info.item_id == item_id) {
        grade = info.grade;
        item_type = info.item_type;
        if (info.display_name[0]) {
            lstrcpynA(name, info.display_name, sizeof(name));
        } else if (info.name_key[0]) {
            clean_item_display_text(info.name_key, name, sizeof(name));
        }
    }
    if (!name[0]) {
        char generated_key[64];
        wsprintfA(generated_key, "ItemName_%u", item_id);
        generated_key[sizeof(generated_key) - 1] = 0;
        lookup_auto_item_lock_localized_name(generated_key,
                                            name,
                                            sizeof(name));
    }
    if (!name[0]) {
        wsprintfA(name, "item %u", item_id);
        name[sizeof(name) - 1] = 0;
    }

    format_item_market_price(item_id, price_text, sizeof(price_text));
    GetLocalTime(&st);
    wsprintfA(line,
              "[%u.%u %02u:%02u] [%s]->[%s][%s]%s%s%s %s",
              st.wMonth,
              st.wDay,
              st.wHour,
              st.wMinute,
              action ? action : "-",
              auto_item_lock_grade_name(grade),
              auto_item_lock_type_name(item_type),
              name,
              price_text[0] ? " " : "",
              price_text,
              locked ? "（已锁定）" : "（未锁定）");
    line[sizeof(line) - 1] = 0;
    append_overlay_log_line_with_grade(line, grade, item_id);
    persist_item_log_entry(line, grade, item_id);
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
    lstrcpynA(g_config_dir, g_game_dir[0] ? g_game_dir : g_base_dir,
              sizeof(g_config_dir));
    wsprintfA(g_log_path, "%s\\TaskBarHeroSpeed.log", g_base_dir);
    g_log_path[sizeof(g_log_path) - 1] = 0;
    wsprintfA(g_item_log_path, "%s\\TaskBarHeroSpeedItemLog.tsv",
              g_config_dir[0] ? g_config_dir : g_base_dir);
    g_item_log_path[sizeof(g_item_log_path) - 1] = 0;
    wsprintfA(g_chest_stats_path, "%s\\TaskBarHeroChestStats.txt",
              g_config_dir[0] ? g_config_dir : g_base_dir);
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
    wsprintfA(path, "%s\\TaskBarHeroSpeed.ini", g_config_dir);
    path[sizeof(path) - 1] = 0;
    log_line("config path: %s", path);

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
        } else if (lstrcmpiA(line, "auto_synthesis") == 0 ||
                   lstrcmpiA(line, "auto_gear_synthesis") == 0) {
            g_auto_synthesis_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_synthesis_use_storage") == 0 ||
                   lstrcmpiA(line, "auto_synthesis_storage") == 0) {
            g_auto_synthesis_use_storage = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_item_lock") == 0 ||
                   lstrcmpiA(line, "auto_lock_item") == 0) {
            g_auto_item_lock_enabled = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "item_lock_condition_high_grade") == 0 ||
                   lstrcmpiA(line, "auto_item_lock_high_grade") == 0) {
            g_item_lock_condition_high_grade = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "item_lock_condition_coin") == 0 ||
                   lstrcmpiA(line, "auto_item_lock_coin") == 0) {
            g_item_lock_condition_coin = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "item_lock_condition_market_top") == 0 ||
                   lstrcmpiA(line, "auto_item_lock_market_top") == 0 ||
                   lstrcmpiA(line, "item_lock_condition_price_top") == 0) {
            g_item_lock_condition_market_top = parse_int_local(eq) ? 1 : 0;
        } else if (lstrcmpiA(line, "auto_item_lock_ids") == 0 ||
                   lstrcmpiA(line, "auto_lock_item_ids") == 0) {
            load_auto_item_lock_ids(eq);
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
    log_line("config loaded: plugin=%s.%s target_game=%s speed=%d.%02d step=%d.%02d exp=%d.%02d cube_exp=%d.%02d overlay=%d background_apply=%d interval=%lu auto_portal=%d/%lu direct_boss=%d actboss_boss=%d auto_switch=%d auto_synthesis=%d storage=%d auto_item_lock=%d high_grade=%d coin=%d market_top=%d market_ids=%d ids=%d free_actboss_enter=%d drop_hooks=%d force_drop_roll=%d reward_trace_hooks=%d force_box_reward_select=%d keep_boxdata_after_select=%d",
             g_config_plugin_version[0] ? g_config_plugin_version : TBHS_PLUGIN_VERSION,
             g_config_plugin_subversion[0] ? g_config_plugin_subversion : TBHS_PLUGIN_SUBVERSION,
             g_config_target_game_version[0] ? g_config_target_game_version : TBHS_SUPPORTED_GAME_VERSION,
             sx / 100, sx % 100,
             (int)(g_speed_step * 100.0f) / 100,
             (int)(g_speed_step * 100.0f) % 100,
             expx / 100, expx % 100,
             cubex / 100, cubex % 100,
             g_overlay_enabled,
             g_background_apply, (unsigned long)g_apply_interval_ms,
             g_auto_portal_enabled, (unsigned long)g_auto_portal_interval_ms,
             g_direct_boss_enabled, g_actboss_boss_enabled,
             g_auto_switch_enabled,
             g_auto_synthesis_enabled,
             g_auto_synthesis_use_storage,
             g_auto_item_lock_enabled,
             g_item_lock_condition_high_grade,
             g_item_lock_condition_coin,
             g_item_lock_condition_market_top,
             g_auto_item_lock_market_top_count,
             g_auto_item_lock_selected_count,
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
    char buf[32768];
    HANDLE file;
    DWORD written = 0;

    if (!g_config_dir[0]) return;
    wsprintfA(path, "%s\\TaskBarHeroSpeed.ini", g_config_dir);
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
    append_int_line(buf, sizeof(buf), "auto_synthesis", g_auto_synthesis_enabled);
    append_int_line(buf, sizeof(buf), "auto_synthesis_use_storage", g_auto_synthesis_use_storage);
    append_int_line(buf, sizeof(buf), "auto_item_lock", g_auto_item_lock_enabled);
    append_int_line(buf, sizeof(buf), "item_lock_condition_high_grade", g_item_lock_condition_high_grade);
    append_int_line(buf, sizeof(buf), "item_lock_condition_coin", g_item_lock_condition_coin);
    append_int_line(buf, sizeof(buf), "item_lock_condition_market_top", g_item_lock_condition_market_top);
    save_auto_item_lock_ids(buf, sizeof(buf));
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

    if (lstrcmpiA(config_game, TBHS_SUPPORTED_GAME_VERSION) != 0 ||
        lstrcmpiA(config_plugin, TBHS_PLUGIN_VERSION) != 0 ||
        lstrcmpiA(config_subversion, TBHS_PLUGIN_SUBVERSION) != 0) {
        log_line("config version metadata updated: config game=%s plugin=%s.%s dll game=%s plugin=%s",
                 config_game,
                 config_plugin,
                 config_subversion,
                 TBHS_SUPPORTED_GAME_VERSION,
                 TBHS_PLUGIN_DISPLAY_VERSION);
        save_config();
    }

    log_line("version check: game=%s supported=%s plugin=%s",
             g_detected_game_version[0] ? g_detected_game_version : "unknown",
             TBHS_SUPPORTED_GAME_VERSION,
             TBHS_PLUGIN_DISPLAY_VERSION);
    return 1;
}

#define TBHS_TRAMPOLINE_MAX_DISTANCE 0x70000000ULL
#define TBHS_TRAMPOLINE_MIN_ADDRESS 0x10000ULL

static uintptr_t align_down_address(uintptr_t value, uintptr_t alignment)
{
    if (!alignment) return value;
    return value & ~(alignment - 1);
}

static void *try_alloc_executable_at(uintptr_t address, SIZE_T size)
{
    if (address < TBHS_TRAMPOLINE_MIN_ADDRESS) return NULL;
    return VirtualAlloc((void *)address,
                        size,
                        MEM_COMMIT | MEM_RESERVE,
                        PAGE_EXECUTE_READWRITE);
}

static void *alloc_executable_near(void *target, SIZE_T size)
{
    SYSTEM_INFO si;
    uintptr_t granularity = 0x10000;
    uintptr_t target_addr = (uintptr_t)target;
    uintptr_t start;
    uintptr_t max_delta;

    GetSystemInfo(&si);
    if (si.dwAllocationGranularity) {
        granularity = (uintptr_t)si.dwAllocationGranularity;
    }
    start = align_down_address(target_addr, granularity);
    max_delta = TBHS_TRAMPOLINE_MAX_DISTANCE -
                (TBHS_TRAMPOLINE_MAX_DISTANCE % granularity);

    for (uintptr_t delta = 0;; delta += granularity) {
        void *mem;
        uintptr_t candidate;

        if (start >= delta) {
            candidate = start - delta;
            mem = try_alloc_executable_at(candidate, size);
            if (mem) return mem;
        }

        if (delta != 0 && start <= ~(uintptr_t)0 - delta) {
            candidate = start + delta;
            mem = try_alloc_executable_at(candidate, size);
            if (mem) return mem;
        }

        if (delta >= max_delta || max_delta - delta < granularity) {
            break;
        }
    }

    log_line("near trampoline allocation failed for target=%p size=%lu; trying fallback",
             target,
             (unsigned long)size);
    return VirtualAlloc(NULL,
                        size,
                        MEM_COMMIT | MEM_RESERVE,
                        PAGE_EXECUTE_READWRITE);
}

static int32_t read_i32_local(const unsigned char *p)
{
    uint32_t value =
        (uint32_t)p[0] |
        ((uint32_t)p[1] << 8) |
        ((uint32_t)p[2] << 16) |
        ((uint32_t)p[3] << 24);
    return (int32_t)value;
}

static void write_i32_local(unsigned char *p, int32_t value)
{
    uint32_t encoded = (uint32_t)value;
    p[0] = (unsigned char)(encoded & 0xFFu);
    p[1] = (unsigned char)((encoded >> 8) & 0xFFu);
    p[2] = (unsigned char)((encoded >> 16) & 0xFFu);
    p[3] = (unsigned char)((encoded >> 24) & 0xFFu);
}

static uintptr_t add_i32_to_address(uintptr_t address, int32_t offset)
{
    if (offset >= 0) {
        return address + (uintptr_t)offset;
    }
    return address - (uintptr_t)(-(int64_t)offset);
}

static int displacement32_from_to(uintptr_t from, uintptr_t to, int32_t *out)
{
    if (to >= from) {
        uintptr_t diff = to - from;
        if (diff > 0x7FFFFFFFULL) return 0;
        *out = (int32_t)diff;
        return 1;
    } else {
        uintptr_t diff = from - to;
        if (diff > 0x80000000ULL) return 0;
        *out = (int32_t)(-(int64_t)diff);
        return 1;
    }
}

static int relocate_trampoline_rip_relative(unsigned char *trampoline,
                                            unsigned char *source,
                                            SIZE_T stolen_size)
{
    int relocated = 0;

    for (SIZE_T offset = 0; offset + 7 <= stolen_size; offset++) {
        if (source[offset] == 0x80 && source[offset + 1] == 0x3D) {
            int32_t old_disp = read_i32_local(source + offset + 2);
            uintptr_t original_next = (uintptr_t)(source + offset + 7);
            uintptr_t relocated_next = (uintptr_t)(trampoline + offset + 7);
            uintptr_t referenced = add_i32_to_address(original_next, old_disp);
            int32_t new_disp;

            if (!displacement32_from_to(relocated_next, referenced, &new_disp)) {
                log_line("trampoline RIP relocation out of range: source=%p trampoline=%p offset=%lu ref=%p",
                         source,
                         trampoline,
                         (unsigned long)offset,
                         (void *)referenced);
                return 0;
            }
            write_i32_local(trampoline + offset + 2, new_disp);
            relocated = 1;
            offset += 6;
        }
    }

    if (relocated) {
        FlushInstructionCache(GetCurrentProcess(), trampoline, stolen_size);
    }
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

    trampoline = (unsigned char *)alloc_executable_near(
        target,
        stolen_size + sizeof(jump_back));
    if (!trampoline) {
        log_line("VirtualAlloc trampoline failed, error=%lu", GetLastError());
        return 0;
    }

    resume = (void *)((unsigned char *)target + stolen_size);
    mem_copy_local(trampoline, target, stolen_size);
    if (!relocate_trampoline_rip_relative(trampoline, (unsigned char *)target, stolen_size)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
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

static int write_absolute_jump_with_trampoline_preserve_rax(void *target,
                                                            void *detour,
                                                            HookPatch *hook,
                                                            SIZE_T stolen_size,
                                                            void **out_trampoline)
{
    unsigned char patch[32];
    unsigned char jump_back[13];
    unsigned char *trampoline;
    void *resume;
    DWORD old_protect = 0;

    if (stolen_size < 12 || stolen_size > sizeof(hook->original)) {
        log_line("invalid preserve-rax trampoline stolen size=%lu for target=%p",
                 (unsigned long)stolen_size, target);
        return 0;
    }

    trampoline = (unsigned char *)alloc_executable_near(
        target,
        stolen_size + sizeof(jump_back));
    if (!trampoline) {
        log_line("VirtualAlloc preserve-rax trampoline failed, error=%lu",
                 GetLastError());
        return 0;
    }

    resume = (void *)((unsigned char *)target + stolen_size);
    mem_copy_local(trampoline, target, stolen_size);
    if (!relocate_trampoline_rip_relative(trampoline, (unsigned char *)target, stolen_size)) {
        VirtualFree(trampoline, 0, MEM_RELEASE);
        return 0;
    }
    jump_back[0] = 0x49;
    jump_back[1] = 0xBB;
    mem_copy_local(&jump_back[2], &resume, sizeof(resume));
    jump_back[10] = 0x41;
    jump_back[11] = 0xFF;
    jump_back[12] = 0xE3;
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

static __int64 __fastcall hook_cube_synthesis_core(void *state_machine)
{
    int synthesis_state = 0;

    if (state_machine &&
        memory_range_readable(state_machine, sizeof(synthesis_state))) {
        synthesis_state = *(int *)state_machine;
        if (synthesis_state == -1) {
            begin_synthesis_cache_watch("core");
        }
    }

    if (g_real_cube_synthesis_core) {
        return g_real_cube_synthesis_core(state_machine);
    }
    return 0;
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
    maybe_request_auto_synthesis_from_reward_item(item_key, "give_reward");
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
    int box_pending_before;
    int synth_pending_before;

    if (g_reward_trace_hooks_enabled) {
        log_line("reward add request: item_key=%u payload=%p count=%d notify=%d method=%p",
                 item_key,
                 payload,
                 count,
                 notify,
                 method);
    }
    maybe_request_auto_synthesis_from_reward_item(item_key, "reward_add");
    if (!g_real_reward_add_item) return 0;
    result = g_real_reward_add_item(item_key, payload, count, notify, method);
    low = (unsigned int)(result & 0xFFFFFFFFu);
    high = (unsigned int)(((unsigned __int64)result >> 32) & 0xFFFFFFFFu);
    box_pending_before = g_box_reward_result_pending ? 1 : 0;
    synth_pending_before = g_auto_synthesis_result_pending ? 1 : 0;
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
    maybe_handle_box_reward_add(item_key, low, high);
    maybe_handle_auto_synthesis_reward_add(item_key, low, high);
    maybe_handle_manual_synthesis_reward_add(item_key, low, high, box_pending_before, synth_pending_before);
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

typedef struct ManualItemLockStats {
    int scanned;
    int matched;
    int locked;
    int already_locked;
    int skipped;
} ManualItemLockStats;

static int auto_item_lock_read_cache_info(void *item_cache,
                                          unsigned int *out_item_id,
                                          int *out_item_type,
                                          int *out_grade,
                                          int *out_equip_class)
{
    void *item_info;

    if (!item_cache ||
        !memory_range_readable(item_cache,
                               ITEM_CACHE_EQUIP_CLASS_OFFSET + sizeof(int))) {
        return 0;
    }
    item_info = *(void **)((unsigned char *)item_cache +
                           ITEM_CACHE_ITEM_INFO_OFFSET);
    if (!item_info ||
        !memory_range_readable(item_info,
                               ITEM_INFO_ICON_PATH_OFFSET + sizeof(void *))) {
        return 0;
    }
    if (out_item_id) {
        *out_item_id = *(unsigned int *)((unsigned char *)item_info +
                                         ITEM_INFO_ITEM_KEY_OFFSET);
    }
    if (out_item_type) {
        *out_item_type = *(int *)((unsigned char *)item_info +
                                  ITEM_INFO_ITEM_TYPE_OFFSET);
    }
    if (out_grade) {
        *out_grade = *(int *)((unsigned char *)item_info +
                              ITEM_INFO_GRADE_OFFSET);
    }
    if (out_equip_class) {
        *out_equip_class = *(int *)((unsigned char *)item_cache +
                                    ITEM_CACHE_EQUIP_CLASS_OFFSET);
    }
    return 1;
}

static int auto_item_lock_apply_cache_now(void *item_cache,
                                          unsigned int item_id,
                                          const char *source,
                                          int *out_already_locked)
{
    uintptr_t base;
    item_cache_get_manual_lock_t get_manual_lock;
    item_cache_set_manual_lock_t set_manual_lock;
    unsigned char was_locked;
    unsigned char now_locked;

    if (out_already_locked) *out_already_locked = 0;
    if (!g_game_assembly || !item_cache) return 0;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return 0;

    base = (uintptr_t)g_game_assembly;
    get_manual_lock =
        (item_cache_get_manual_lock_t)(base + RVA_ITEM_CACHE_GET_MANUAL_LOCK);
    set_manual_lock =
        (item_cache_set_manual_lock_t)(base + RVA_ITEM_CACHE_SET_MANUAL_LOCK);

    if (!memory_range_readable((void *)get_manual_lock, 12) ||
        !memory_range_readable((void *)set_manual_lock, 12)) {
        log_line("ITEM LOCK skipped: lock functions unavailable");
        return 0;
    }

    was_locked = get_manual_lock(item_cache) ? 1 : 0;
    if (out_already_locked) *out_already_locked = was_locked ? 1 : 0;
    if (!was_locked) {
        set_manual_lock(item_cache, 1);
        now_locked = get_manual_lock(item_cache) ? 1 : 0;
    } else {
        now_locked = 1;
    }

    if (now_locked) {
        log_line("%s item lock sent: item_id=%u cache=%p already=%d",
                 source ? source : "manual",
                 item_id,
                 item_cache,
                 was_locked ? 1 : 0);
        return 1;
    }

    log_line("%s item lock failed: item_id=%u cache=%p",
             source ? source : "manual",
             item_id,
             item_cache);
    return 0;
}

static int try_auto_item_lock_now(unsigned int item_id,
                                  unsigned __int64 unique_id,
                                  const char *unique_key)
{
    uintptr_t base;
    void *item_cache;
    item_cache_by_unique_id_t cache_by_unique_id;
    item_cache_get_manual_lock_t get_manual_lock;
    item_cache_set_manual_lock_t set_manual_lock;
    unsigned char was_locked = 0;
    unsigned char now_locked = 0;
    char unique_id_text[32];

    if (!g_game_assembly || !unique_id) return 0;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return 0;

    base = (uintptr_t)g_game_assembly;
    cache_by_unique_id =
        (item_cache_by_unique_id_t)(base + RVA_ITEM_CACHE_BY_UNIQUE_ID);
    get_manual_lock =
        (item_cache_get_manual_lock_t)(base + RVA_ITEM_CACHE_GET_MANUAL_LOCK);
    set_manual_lock =
        (item_cache_set_manual_lock_t)(base + RVA_ITEM_CACHE_SET_MANUAL_LOCK);

    if (!memory_range_readable((void *)cache_by_unique_id, 12) ||
        !memory_range_readable((void *)get_manual_lock, 12) ||
        !memory_range_readable((void *)set_manual_lock, 12)) {
        log_line("AUTO ITEM LOCK skipped: lock functions unavailable");
        return 0;
    }

    item_cache = cache_by_unique_id(unique_id);
    if (!item_cache) return 0;

    was_locked = get_manual_lock(item_cache) ? 1 : 0;
    if (!was_locked) {
        set_manual_lock(item_cache, 1);
        now_locked = get_manual_lock(item_cache) ? 1 : 0;
    } else {
        now_locked = 1;
    }

    format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
    if (now_locked) {
        log_line("AUTO ITEM LOCK sent: item_id=%u unique_key=%s unique_id=%s cache=%p already=%d",
                 item_id,
                 unique_key && unique_key[0] ? unique_key : "-",
                 unique_id_text,
                 item_cache,
                 was_locked ? 1 : 0);
        append_overlay_event("LOCK ITEM %u", item_id);
        return 1;
    }

    log_line("AUTO ITEM LOCK failed: item_id=%u unique_key=%s unique_id=%s cache=%p",
             item_id,
             unique_key && unique_key[0] ? unique_key : "-",
             unique_id_text,
             item_cache);
    return 0;
}

static void queue_auto_item_lock_request(unsigned int item_id,
                                         const char *unique_key)
{
    unsigned __int64 unique_id = unique_key ? parse_u64_local(unique_key) : 0;
    char unique_id_text[32];

    g_auto_item_lock_pending_item_id = item_id;
    g_auto_item_lock_pending_unique_id = unique_id;
    g_auto_item_lock_pending_unique_key[0] = 0;
    if (unique_key) {
        lstrcpynA(g_auto_item_lock_pending_unique_key,
                  unique_key,
                  sizeof(g_auto_item_lock_pending_unique_key));
    }
    g_auto_item_lock_pending_tick = GetTickCount();
    g_auto_item_lock_last_try_tick = 0;
    InterlockedExchange(&g_auto_item_lock_pending, 1);

    format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
    log_line("AUTO ITEM LOCK pending: item_id=%u unique_key=%s unique_id=%s",
             item_id,
             g_auto_item_lock_pending_unique_key[0] ?
                 g_auto_item_lock_pending_unique_key : "-",
             unique_id_text);
    append_overlay_event("LOCK ITEM pending %u", item_id);
    if (try_auto_item_lock_now(item_id, unique_id, unique_key)) {
        InterlockedExchange(&g_auto_item_lock_pending, 0);
    }
}

static void begin_box_reward_result_watch(unsigned int box_item_key,
                                          unsigned int expected_item_id)
{
    if (!item_key_is_stage_box_candidate(box_item_key)) return;
    g_box_reward_box_item_key = box_item_key;
    g_box_reward_expected_item_id = expected_item_id;
    g_box_reward_result_watch_until = GetTickCount() + BOX_REWARD_RESULT_WATCH_MS;
    InterlockedExchange(&g_box_reward_result_pending, 1);
}

static void remember_recent_box_reward(unsigned int item_id,
                                       unsigned __int64 unique_id)
{
    DWORD now;
    int i;
    int slot;

    if (!item_id || !unique_id) return;
    now = GetTickCount();
    for (i = 0; i < RECENT_BOX_REWARD_MAX; ++i) {
        if (g_recent_box_reward_unique_ids[i] != unique_id) continue;
        g_recent_box_reward_item_ids[i] = item_id;
        g_recent_box_reward_ticks[i] = now;
        return;
    }

    slot = g_recent_box_reward_next++ % RECENT_BOX_REWARD_MAX;
    if (g_recent_box_reward_next < 0) g_recent_box_reward_next = 0;
    g_recent_box_reward_unique_ids[slot] = unique_id;
    g_recent_box_reward_item_ids[slot] = item_id;
    g_recent_box_reward_ticks[slot] = now;
}

static void remember_recent_box_reward_unique_id(unsigned int reward_item_id,
                                                 const char *reward_unique_key)
{
    unsigned __int64 unique_id;

    if (!reward_unique_key || !reward_unique_key[0]) return;
    unique_id = parse_u64_local(reward_unique_key);
    remember_recent_box_reward(reward_item_id, unique_id);
}

static int recent_box_reward_matches(unsigned __int64 unique_id,
                                     unsigned int item_id)
{
    DWORD now;
    int i;

    if (!unique_id) return 0;
    now = GetTickCount();
    for (i = 0; i < RECENT_BOX_REWARD_MAX; ++i) {
        if (!g_recent_box_reward_unique_ids[i]) continue;
        if ((DWORD)(now - g_recent_box_reward_ticks[i]) >
            RECENT_BOX_REWARD_IGNORE_MS) {
            g_recent_box_reward_unique_ids[i] = 0;
            g_recent_box_reward_item_ids[i] = 0;
            g_recent_box_reward_ticks[i] = 0;
            continue;
        }
        if (g_recent_box_reward_unique_ids[i] == unique_id &&
            (!item_id || g_recent_box_reward_item_ids[i] == item_id)) {
            return 1;
        }
    }
    return 0;
}

static void maybe_handle_box_reward_add(unsigned int item_id,
                                        unsigned int result_low,
                                        unsigned int result_high)
{
    DWORD now;
    unsigned __int64 unique_id;
    char unique_key[32];
    int locked = 0;

    if (!item_id || result_high == 0xFFFFFFFFu) return;
    if (!g_box_reward_result_pending) return;

    now = GetTickCount();
    if (!g_box_reward_result_watch_until ||
        (LONG)(now - g_box_reward_result_watch_until) > 0) {
        InterlockedExchange(&g_box_reward_result_pending, 0);
        g_box_reward_result_watch_until = 0;
        g_box_reward_expected_item_id = 0;
        g_box_reward_box_item_key = 0;
        return;
    }
    if (item_key_is_stage_box_candidate(item_id)) return;
    if (g_box_reward_expected_item_id &&
        g_box_reward_expected_item_id != item_id) {
        return;
    }
    if (InterlockedExchange(&g_box_reward_result_pending, 0) == 0) return;
    g_box_reward_result_watch_until = 0;
    g_box_reward_expected_item_id = 0;
    g_box_reward_box_item_key = 0;

    unique_id = ((unsigned __int64)result_high << 32) |
                (unsigned __int64)result_low;
    format_u64_local(unique_key, sizeof(unique_key), unique_id);
    remember_recent_box_reward(item_id, unique_id);

    if (g_auto_item_lock_enabled &&
        auto_item_lock_reward_matches_conditions(item_id)) {
        queue_auto_item_lock_request(item_id, unique_key);
        locked = 1;
    }
    append_overlay_item_event("开箱", item_id, locked);
}

static void maybe_handle_auto_synthesis_reward_add(unsigned int item_id,
                                                   unsigned int result_low,
                                                   unsigned int result_high)
{
    DWORD now;
    unsigned __int64 unique_id;
    char unique_key[32];
    int locked = 0;

    if (!item_id || result_high == 0xFFFFFFFFu) return;
    if (!g_auto_synthesis_result_pending) return;
    if (item_key_is_stage_box_candidate(item_id)) return;

    now = GetTickCount();
    if (!g_auto_synthesis_result_watch_until ||
        (LONG)(now - g_auto_synthesis_result_watch_until) > 0) {
        InterlockedExchange(&g_auto_synthesis_result_pending, 0);
        g_auto_synthesis_result_watch_until = 0;
        return;
    }
    if (InterlockedExchange(&g_auto_synthesis_result_pending, 0) == 0) return;
    g_auto_synthesis_result_watch_until = 0;

    unique_id = ((unsigned __int64)result_high << 32) |
                (unsigned __int64)result_low;
    if (recent_box_reward_matches(unique_id, item_id)) return;

    if (g_auto_item_lock_enabled &&
        auto_item_lock_reward_matches_conditions(item_id)) {
        format_u64_local(unique_key, sizeof(unique_key), unique_id);
        queue_auto_item_lock_request(item_id, unique_key);
        locked = 1;
    }
    append_overlay_item_event("合成", item_id, locked);
}

static void maybe_handle_manual_synthesis_reward_add(unsigned int item_id,
                                                     unsigned int result_low,
                                                     unsigned int result_high,
                                                     int box_pending_before,
                                                     int synth_pending_before)
{
    unsigned __int64 unique_id;
    char unique_key[32];
    int item_type = -1;
    int grade = -1;
    int catalog_found;
    int locked = 0;

    if (!item_id || result_high == 0xFFFFFFFFu) return;
    if (box_pending_before || synth_pending_before) return;
    if (!g_cached_ui_cube) return;
    if (g_drop_observation.active &&
        g_drop_observation.thread_id == GetCurrentThreadId()) {
        return;
    }
    if (item_key_is_stage_box_candidate(item_id)) return;

    catalog_found = auto_item_lock_catalog_lookup(item_id,
                                                  &item_type,
                                                  &grade,
                                                  NULL);
    if (!catalog_found) {
        InterlockedExchange(&g_auto_item_lock_catalog_preload_pending, 1);
    }
    if (catalog_found &&
        item_type != EITEM_TYPE_GEAR && item_type != EITEM_TYPE_MATERIAL) {
        return;
    }

    unique_id = ((unsigned __int64)result_high << 32) |
                (unsigned __int64)result_low;
    if (recent_box_reward_matches(unique_id, item_id)) return;
    format_u64_local(unique_key, sizeof(unique_key), unique_id);
    if (g_auto_item_lock_enabled &&
        auto_item_lock_item_matches_conditions(item_id, item_type, grade)) {
        queue_auto_item_lock_request(item_id, unique_key);
        locked = 1;
    }
    append_overlay_item_event("合成", item_id, locked);
    log_line("manual synthesis item event: item_id=%u result_key=%s grade=%d type=%d locked=%d",
             item_id,
             unique_key,
             grade,
             item_type,
             locked);
}

static void reset_synthesis_cache_watch(void)
{
    InterlockedExchange(&g_synthesis_cache_watch_active, 0);
    g_synthesis_cache_watch_until = 0;
    g_synthesis_cache_watch_last_scan_tick = 0;
    g_synthesis_cache_watch_seen_count = 0;
    g_synthesis_cache_watch_logged_count = 0;
}

static int synthesis_cache_watch_has_seen_id(unsigned __int64 unique_id)
{
    int i;

    if (!unique_id) return 1;
    for (i = 0; i < g_synthesis_cache_watch_seen_count; ++i) {
        if (g_synthesis_cache_watch_seen_ids[i] == unique_id) return 1;
    }
    return 0;
}

static int synthesis_cache_watch_remember_id(unsigned __int64 unique_id)
{
    if (!unique_id) return 0;
    if (synthesis_cache_watch_has_seen_id(unique_id)) return 1;
    if (g_synthesis_cache_watch_seen_count >= SYNTHESIS_CACHE_WATCH_MAX_IDS) {
        return 0;
    }
    g_synthesis_cache_watch_seen_ids[g_synthesis_cache_watch_seen_count++] =
        unique_id;
    return 1;
}

static void snapshot_synthesis_cache_watch_ids(void)
{
    uintptr_t base;
    void *dict;
    void *entries;
    int count;
    int array_len;
    int i;

    g_synthesis_cache_watch_seen_count = 0;
    if (!g_game_assembly) return;
    base = (uintptr_t)g_game_assembly;
    dict = get_item_cache_dictionary(base);
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return;
    }
    count = *(int *)((unsigned char *)dict + IL2CPP_DICT_COUNT_OFFSET);
    if (count <= 0 || count > 200000) return;
    entries = *(void **)((unsigned char *)dict + IL2CPP_DICT_ENTRIES_OFFSET);
    if (!entries ||
        !memory_range_readable(entries,
                               IL2CPP_ARRAY_DATA_OFFSET + sizeof(void *))) {
        return;
    }
    array_len = *(int *)((unsigned char *)entries + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len <= 0 || array_len > 200000 || count > array_len) return;

    for (i = 0; i < count; ++i) {
        unsigned char *entry = (unsigned char *)entries +
                               IL2CPP_ARRAY_DATA_OFFSET +
                               ((SIZE_T)i *
                                IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE);
        int hash_code;
        unsigned __int64 unique_id;

        if (!memory_range_readable(entry,
                                   IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE)) {
            break;
        }
        hash_code = *(int *)(entry +
                             IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET);
        if (hash_code < 0) continue;
        unique_id = *(unsigned __int64 *)(entry +
                                          IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET);
        if (!synthesis_cache_watch_remember_id(unique_id)) break;
    }
}

static void begin_synthesis_cache_watch(const char *source)
{
    DWORD now;

    if (!g_game_assembly) return;
    if (!g_game_thread_id) g_game_thread_id = GetCurrentThreadId();

    now = GetTickCount();
    if (g_synthesis_cache_watch_active &&
        (LONG)(now - g_synthesis_cache_watch_until) < 0) {
        g_synthesis_cache_watch_until = now + SYNTHESIS_CACHE_WATCH_MS;
        return;
    }

    reset_synthesis_cache_watch();
    snapshot_synthesis_cache_watch_ids();
    g_synthesis_cache_watch_until = now + SYNTHESIS_CACHE_WATCH_MS;
    InterlockedExchange(&g_synthesis_cache_watch_active, 1);
    log_line("synthesis cache watch started: source=%s baseline=%d window_ms=%lu",
             source ? source : "unknown",
             g_synthesis_cache_watch_seen_count,
             (unsigned long)SYNTHESIS_CACHE_WATCH_MS);
}

static void maybe_handle_synthesis_cache_watch_from_game_thread(void)
{
    uintptr_t base;
    DWORD now;
    void *dict;
    void *entries;
    int count;
    int array_len;
    int i;

    if (!g_synthesis_cache_watch_active) return;
    if (!g_game_assembly) {
        reset_synthesis_cache_watch();
        return;
    }
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;

    now = GetTickCount();
    if (!g_synthesis_cache_watch_until ||
        (LONG)(now - g_synthesis_cache_watch_until) > 0) {
        log_line("synthesis cache watch ended: logged=%d seen=%d",
                 g_synthesis_cache_watch_logged_count,
                 g_synthesis_cache_watch_seen_count);
        reset_synthesis_cache_watch();
        return;
    }
    if (g_synthesis_cache_watch_last_scan_tick &&
        (DWORD)(now - g_synthesis_cache_watch_last_scan_tick) <
            SYNTHESIS_CACHE_WATCH_SCAN_INTERVAL_MS) {
        return;
    }
    g_synthesis_cache_watch_last_scan_tick = now;

    base = (uintptr_t)g_game_assembly;
    dict = get_item_cache_dictionary(base);
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return;
    }
    count = *(int *)((unsigned char *)dict + IL2CPP_DICT_COUNT_OFFSET);
    if (count <= 0 || count > 200000) return;
    entries = *(void **)((unsigned char *)dict + IL2CPP_DICT_ENTRIES_OFFSET);
    if (!entries ||
        !memory_range_readable(entries,
                               IL2CPP_ARRAY_DATA_OFFSET + sizeof(void *))) {
        return;
    }
    array_len = *(int *)((unsigned char *)entries + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len <= 0 || array_len > 200000 || count > array_len) return;

    for (i = 0; i < count; ++i) {
        unsigned char *entry = (unsigned char *)entries +
                               IL2CPP_ARRAY_DATA_OFFSET +
                               ((SIZE_T)i *
                                IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE);
        int hash_code;
        unsigned __int64 unique_id;
        void *item_cache;
        unsigned int item_id = 0;
        int item_type = -1;
        int grade = -1;
        int equip_class = -1;
        int locked = 0;
        int already_locked = 0;
        char unique_id_text[32];

        if (!memory_range_readable(entry,
                                   IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE)) {
            break;
        }
        hash_code = *(int *)(entry +
                             IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET);
        if (hash_code < 0) continue;
        unique_id = *(unsigned __int64 *)(entry +
                                          IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET);
        if (synthesis_cache_watch_has_seen_id(unique_id)) continue;
        if (!synthesis_cache_watch_remember_id(unique_id)) continue;

        item_cache = *(void **)(entry +
                                IL2CPP_DICT_U64_OBJECT_ENTRY_VALUE_OFFSET);
        if (!auto_item_lock_read_cache_info(item_cache,
                                            &item_id,
                                            &item_type,
                                            &grade,
                                            &equip_class)) {
            continue;
        }
        if (!item_id || item_key_is_stage_box_candidate(item_id)) continue;
        if (item_type != EITEM_TYPE_GEAR && item_type != EITEM_TYPE_MATERIAL) {
            continue;
        }
        if (recent_box_reward_matches(unique_id, item_id)) {
            format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
            log_line("synthesis cache skipped recent box reward: item_id=%u unique_id=%s",
                     item_id,
                     unique_id_text);
            continue;
        }

        if (g_auto_item_lock_enabled &&
            auto_item_lock_item_matches_conditions(item_id,
                                                   item_type,
                                                   grade) &&
            auto_item_lock_apply_cache_now(item_cache, item_id, "synthesis cache watch",
                                           &already_locked)) {
            locked = 1;
        }
        append_overlay_item_event("合成", item_id, locked);
        g_synthesis_cache_watch_logged_count++;

        format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
        log_line("synthesis cache item event: item_id=%u unique_id=%s grade=%d type=%d class=%d locked=%d already=%d",
                 item_id,
                 unique_id_text,
                 grade,
                 item_type,
                 equip_class,
                 locked,
                 already_locked);
    }
}

static void reset_actboss_cache_watch(void)
{
    InterlockedExchange(&g_actboss_cache_watch_active, 0);
    g_actboss_cache_watch_until = 0;
    g_actboss_cache_watch_last_scan_tick = 0;
    g_actboss_cache_watch_seen_count = 0;
    g_actboss_cache_watch_logged_count = 0;
    g_actboss_cache_watch_synthesis_requested = 0;
}

static int actboss_cache_watch_has_seen_id(unsigned __int64 unique_id)
{
    int i;

    if (!unique_id) return 1;
    for (i = 0; i < g_actboss_cache_watch_seen_count; ++i) {
        if (g_actboss_cache_watch_seen_ids[i] == unique_id) return 1;
    }
    return 0;
}

static int actboss_cache_watch_remember_id(unsigned __int64 unique_id)
{
    if (!unique_id) return 0;
    if (actboss_cache_watch_has_seen_id(unique_id)) return 1;
    if (g_actboss_cache_watch_seen_count >= ACTBOSS_CACHE_WATCH_MAX_IDS) {
        return 0;
    }
    g_actboss_cache_watch_seen_ids[g_actboss_cache_watch_seen_count++] =
        unique_id;
    return 1;
}

static void snapshot_actboss_cache_watch_ids(void)
{
    uintptr_t base;
    void *dict;
    void *entries;
    int count;
    int array_len;
    int i;

    g_actboss_cache_watch_seen_count = 0;
    if (!g_game_assembly) return;
    base = (uintptr_t)g_game_assembly;
    dict = get_item_cache_dictionary(base);
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return;
    }
    count = *(int *)((unsigned char *)dict + IL2CPP_DICT_COUNT_OFFSET);
    if (count <= 0 || count > 200000) return;
    entries = *(void **)((unsigned char *)dict + IL2CPP_DICT_ENTRIES_OFFSET);
    if (!entries ||
        !memory_range_readable(entries,
                               IL2CPP_ARRAY_DATA_OFFSET + sizeof(void *))) {
        return;
    }
    array_len = *(int *)((unsigned char *)entries + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len <= 0 || array_len > 200000 || count > array_len) return;

    for (i = 0; i < count; ++i) {
        unsigned char *entry = (unsigned char *)entries +
                               IL2CPP_ARRAY_DATA_OFFSET +
                               ((SIZE_T)i *
                                IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE);
        int hash_code;
        unsigned __int64 unique_id;

        if (!memory_range_readable(entry,
                                   IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE)) {
            break;
        }
        hash_code = *(int *)(entry +
                             IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET);
        if (hash_code < 0) continue;
        unique_id = *(unsigned __int64 *)(entry +
                                          IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET);
        if (!actboss_cache_watch_remember_id(unique_id)) break;
    }
}

static void begin_actboss_cache_watch_from_stage_box(void *stage_box,
                                                     const char *source)
{
    unsigned char *box;
    int box_type;
    int enabled;
    float duration;
    DWORD now;

    if (!stage_box ||
        !memory_range_readable(stage_box,
                               STAGE_BOX_AUTO_OPEN_ENABLED_OFFSET +
                                   sizeof(unsigned char))) {
        return;
    }

    box = (unsigned char *)stage_box;
    box_type = *(int *)(box + STAGE_BOX_BOX_TYPE_OFFSET);
    if (box_type != 2) return;
    enabled = *(unsigned char *)(box + STAGE_BOX_AUTO_OPEN_ENABLED_OFFSET) ? 1 : 0;
    if (!enabled) return;
    duration = *(float *)(box + STAGE_BOX_AUTO_OPEN_DURATION_OFFSET);
    if (!(duration > 0.0f) ||
        duration > ((float)AUTO_OPEN_BOX_SECONDS + 0.5f)) {
        return;
    }

    now = GetTickCount();
    if (g_actboss_cache_watch_active &&
        (LONG)(now - g_actboss_cache_watch_until) < 0) {
        return;
    }
    if (g_actboss_cache_watch_last_begin_tick &&
        (DWORD)(now - g_actboss_cache_watch_last_begin_tick) <
            ACTBOSS_CACHE_WATCH_COOLDOWN_MS) {
        return;
    }

    reset_actboss_cache_watch();
    snapshot_actboss_cache_watch_ids();
    g_actboss_cache_watch_until = now + ACTBOSS_CACHE_WATCH_MS;
    g_actboss_cache_watch_last_begin_tick = now;
    InterlockedExchange(&g_actboss_cache_watch_active, 1);
    log_line("actboss cache watch started: source=%s duration=%ds baseline=%d window_ms=%lu",
             source ? source : "unknown",
             (int)(duration + 0.5f),
             g_actboss_cache_watch_seen_count,
             (unsigned long)ACTBOSS_CACHE_WATCH_MS);
}

static void maybe_handle_actboss_cache_watch_from_game_thread(void)
{
    uintptr_t base;
    DWORD now;
    void *dict;
    void *entries;
    int count;
    int array_len;
    int i;

    if (!g_actboss_cache_watch_active) return;
    if (!g_game_assembly) {
        reset_actboss_cache_watch();
        return;
    }
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;

    now = GetTickCount();
    if (!g_actboss_cache_watch_until ||
        (LONG)(now - g_actboss_cache_watch_until) > 0) {
        log_line("actboss cache watch ended: logged=%d seen=%d",
                 g_actboss_cache_watch_logged_count,
                 g_actboss_cache_watch_seen_count);
        reset_actboss_cache_watch();
        return;
    }
    if (g_actboss_cache_watch_last_scan_tick &&
        (DWORD)(now - g_actboss_cache_watch_last_scan_tick) <
            ACTBOSS_CACHE_WATCH_SCAN_INTERVAL_MS) {
        return;
    }
    g_actboss_cache_watch_last_scan_tick = now;

    base = (uintptr_t)g_game_assembly;
    dict = get_item_cache_dictionary(base);
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return;
    }
    count = *(int *)((unsigned char *)dict + IL2CPP_DICT_COUNT_OFFSET);
    if (count <= 0 || count > 200000) return;
    entries = *(void **)((unsigned char *)dict + IL2CPP_DICT_ENTRIES_OFFSET);
    if (!entries ||
        !memory_range_readable(entries,
                               IL2CPP_ARRAY_DATA_OFFSET + sizeof(void *))) {
        return;
    }
    array_len = *(int *)((unsigned char *)entries + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len <= 0 || array_len > 200000 || count > array_len) return;

    for (i = 0; i < count; ++i) {
        unsigned char *entry = (unsigned char *)entries +
                               IL2CPP_ARRAY_DATA_OFFSET +
                               ((SIZE_T)i *
                                IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE);
        int hash_code;
        unsigned __int64 unique_id;
        void *item_cache;
        unsigned int item_id = 0;
        int item_type = -1;
        int grade = -1;
        int equip_class = -1;
        int locked = 0;
        int already_locked = 0;
        char unique_id_text[32];

        if (!memory_range_readable(entry,
                                   IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE)) {
            break;
        }
        hash_code = *(int *)(entry +
                             IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET);
        if (hash_code < 0) continue;
        unique_id = *(unsigned __int64 *)(entry +
                                          IL2CPP_DICT_U64_OBJECT_ENTRY_KEY_OFFSET);
        if (actboss_cache_watch_has_seen_id(unique_id)) continue;
        if (!actboss_cache_watch_remember_id(unique_id)) continue;

        item_cache = *(void **)(entry +
                                IL2CPP_DICT_U64_OBJECT_ENTRY_VALUE_OFFSET);
        if (!auto_item_lock_read_cache_info(item_cache,
                                            &item_id,
                                            &item_type,
                                            &grade,
                                            &equip_class)) {
            continue;
        }
        if (!item_id || item_key_is_stage_box_candidate(item_id)) continue;
        remember_recent_box_reward(item_id, unique_id);

        if (g_auto_item_lock_enabled &&
            auto_item_lock_item_matches_conditions(item_id,
                                                   item_type,
                                                   grade) &&
            auto_item_lock_apply_cache_now(item_cache, item_id, "actboss cache watch",
                                           &already_locked)) {
            locked = 1;
        }
        if (!g_actboss_cache_watch_synthesis_requested) {
            request_auto_synthesis_after_box_open(ACTBOSS_BOX_ITEM_KEY, ACTBOSS_BOX_ITEM_KEY);
            g_actboss_cache_watch_synthesis_requested = 1;
        }
        append_overlay_item_event("开箱", item_id, locked);
        g_actboss_cache_watch_logged_count++;

        format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
        log_line("actboss cache item event: item_id=%u unique_id=%s grade=%d type=%d class=%d locked=%d already=%d",
                 item_id,
                 unique_id_text,
                 grade,
                 item_type,
                 equip_class,
                 locked,
                 already_locked);
    }
}

static int read_boxdata_reward_fields(void *box_data,
                                      unsigned int *out_reward_item_id,
                                      char *out_reward_unique_key,
                                      int unique_key_len)
{
    uintptr_t base;
    box_data_get_int_t get_reward_item_id;
    box_data_get_string_t get_reward_item_unique_id;
    void *unique_key_obj = NULL;
    unsigned int reward_item_id = 0;

    if (out_reward_item_id) *out_reward_item_id = 0;
    if (out_reward_unique_key && unique_key_len > 0) {
        out_reward_unique_key[0] = 0;
    }
    if (!box_data || !memory_range_readable(box_data, 0x18)) return 0;

    if (g_game_assembly) {
        base = (uintptr_t)g_game_assembly;
        get_reward_item_id =
            (box_data_get_int_t)(base + RVA_BOX_DATA_GET_REWARD_ITEM_ID);
        get_reward_item_unique_id =
            (box_data_get_string_t)(base + RVA_BOX_DATA_GET_REWARD_ITEM_UNIQUE_ID);
        if (memory_range_readable((void *)get_reward_item_id, 12)) {
            reward_item_id = (unsigned int)get_reward_item_id(box_data, NULL);
        }
        if (memory_range_readable((void *)get_reward_item_unique_id, 12)) {
            unique_key_obj = get_reward_item_unique_id(box_data, NULL);
        }
        if (unique_key_obj && out_reward_unique_key && unique_key_len > 0) {
            read_il2cpp_string_utf8(unique_key_obj,
                                    out_reward_unique_key,
                                    unique_key_len);
        }
    }

    if (!reward_item_id && memory_range_readable(box_data, 0x78)) {
        reward_item_id = *(unsigned int *)((unsigned char *)box_data + 0x68);
    }
    if ((!out_reward_unique_key || !out_reward_unique_key[0]) &&
        memory_range_readable(box_data, 0x78)) {
        unique_key_obj = *(void **)((unsigned char *)box_data + 0x70);
        if (unique_key_obj && out_reward_unique_key && unique_key_len > 0) {
            read_il2cpp_string_utf8(unique_key_obj,
                                    out_reward_unique_key,
                                    unique_key_len);
        }
    }

    if (out_reward_item_id) *out_reward_item_id = reward_item_id;
    return reward_item_id ||
           (out_reward_unique_key && out_reward_unique_key[0]);
}

static int handle_box_reward_select_item(unsigned int box_item_key,
                                         unsigned int reward_item_id,
                                         const char *reward_unique_key)
{
    int locked = 0;

    if (!item_key_is_stage_box_candidate(box_item_key)) return 0;
    if (!reward_item_id || item_key_is_stage_box_candidate(reward_item_id)) return 0;
    remember_recent_box_reward_unique_id(reward_item_id, reward_unique_key);

    if (g_auto_item_lock_enabled &&
        auto_item_lock_reward_matches_conditions(reward_item_id) &&
        reward_unique_key && reward_unique_key[0]) {
        queue_auto_item_lock_request(reward_item_id, reward_unique_key);
        locked = 1;
    }

    append_overlay_item_event("开箱", reward_item_id, locked);
    log_line("box reward item event: box_item=%u reward_item=%u reward_key=%s locked=%d",
             box_item_key,
             reward_item_id,
             reward_unique_key && reward_unique_key[0] ? reward_unique_key : "-",
             locked);

    InterlockedExchange(&g_box_reward_result_pending, 0);
    g_box_reward_result_watch_until = 0;
    g_box_reward_expected_item_id = 0;
    g_box_reward_box_item_key = 0;
    return 1;
}

static int TBHS_UNUSED handle_box_reward_auto_item_lock(unsigned int box_item_key,
                                                        unsigned int reward_item_id,
                                                        const char *reward_unique_key)
{
    if (!g_auto_item_lock_enabled || !reward_item_id) return 0;
    if (!auto_item_lock_reward_matches_conditions(reward_item_id)) return 0;
    log_line("AUTO ITEM LOCK matched: box_item=%u reward_item=%u reward_key=%s",
             box_item_key,
             reward_item_id,
             reward_unique_key && reward_unique_key[0] ? reward_unique_key : "-");
    queue_auto_item_lock_request(reward_item_id, reward_unique_key);
    return 1;
}

static __int64 __fastcall hook_box_reward_select(void *box_table,
                                                 unsigned int item_key,
                                                 void *context)
{
    __int64 result;
    unsigned int selected_item = 0;
    unsigned int reward_item_id = 0;
    char reward_unique_key[64];
#if ENABLE_FORCE_BOX_REWARD_SELECT
    unsigned int forced_item = 0;
    int forced_count = 0;
#endif
    int readable = 0;

    if (g_reward_trace_hooks_enabled &&
        item_key >= 900000 && item_key < 1000000) {
        log_line("box reward select request: item_key=%u table=%p context=%p",
                 item_key,
                 box_table,
                 context);
    }
    if (!g_real_box_reward_select) return 0;
    begin_box_reward_result_watch(item_key, 0);
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
    reward_unique_key[0] = 0;
    readable = memory_range_readable((void *)result, 0x78);
    if (readable) {
        selected_item = *(unsigned int *)((unsigned char *)result + 0x54);
        read_boxdata_reward_fields((void *)result, &reward_item_id, reward_unique_key, sizeof(reward_unique_key));
        cache_boxdata_candidate(item_key, (void *)result, selected_item);
        request_auto_synthesis_after_box_open(item_key, selected_item);
        handle_box_reward_select_item(item_key, reward_item_id, reward_unique_key);
    }
#if ENABLE_FORCE_BOX_REWARD_SELECT
    if (readable) {
        keep_boxdata_available(box_table, item_key, (void *)result, selected_item);
    }
#endif
    if (g_reward_trace_hooks_enabled &&
        item_key >= 900000 && item_key < 1000000) {
        log_line("box reward select result: item_key=%u result=%p readable=%d selected_item=%u reward_item=%u reward_key=%s",
                 item_key,
                 (void *)result,
                 readable,
                 selected_item,
                 reward_item_id,
                 reward_unique_key[0] ? reward_unique_key : "-");
    }
    return result;
}

static __int64 __fastcall hook_open_box_stats(void *account_status,
                                              int box_type,
                                              void *method)
{
    __int64 result;
    int max_time;
    int reduce_time;
    DWORD now;

    if (!g_real_open_box_stats) return 0;
    result = g_real_open_box_stats(account_status, box_type, method);
    max_time = (int)(result & 0xFFFFFFFFu);
    reduce_time = (int)(((unsigned __int64)result >> 32) & 0xFFFFFFFFu);
    if (max_time <= 0) return result;

    now = GetTickCount();
    if (!g_last_open_box_stats_log_tick ||
        (DWORD)(now - g_last_open_box_stats_log_tick) >= 10000) {
        log_line("auto open box cd forced: type=%d(%s) original=%ds-%ds forced=%ds",
                 box_type,
                 box_type_name((unsigned int)box_type),
                 max_time,
                 reduce_time,
                 AUTO_OPEN_BOX_SECONDS);
        g_last_open_box_stats_log_tick = now;
    }
    return (__int64)(unsigned int)AUTO_OPEN_BOX_SECONDS;
}

static int clamp_stage_box_auto_open_cd(void *stage_box, const char *source)
{
    unsigned char *box;
    int box_type;
    int enabled;
    int changed = 0;
    int duration_was_clamped = 0;
    float before_duration;
    float before_configured;
    float before_elapsed;
    float before_paused_elapsed;
    float after_duration;
    float after_configured;
    float after_elapsed;
    float after_paused_elapsed;
    DWORD now;

    if (!stage_box ||
        !memory_range_readable(stage_box,
                               STAGE_BOX_AUTO_OPEN_ENABLED_OFFSET + sizeof(unsigned char))) {
        return 0;
    }

    box = (unsigned char *)stage_box;
    box_type = *(int *)(box + STAGE_BOX_BOX_TYPE_OFFSET);
    enabled = *(unsigned char *)(box + STAGE_BOX_AUTO_OPEN_ENABLED_OFFSET) ? 1 : 0;
    before_duration = *(float *)(box + STAGE_BOX_AUTO_OPEN_DURATION_OFFSET);
    before_configured = *(float *)(box + STAGE_BOX_AUTO_OPEN_SECONDS_OFFSET);
    before_elapsed = *(float *)(box + STAGE_BOX_AUTO_OPEN_ELAPSED_OFFSET);
    before_paused_elapsed =
        *(float *)(box + STAGE_BOX_AUTO_OPEN_PAUSED_ELAPSED_OFFSET);

    if (!enabled && !(before_duration > 0.0f) && !(before_configured > 0.0f)) {
        return 0;
    }
    if (before_configured > (float)AUTO_OPEN_BOX_SECONDS ||
        (enabled && !(before_configured > 0.0f))) {
        *(float *)(box + STAGE_BOX_AUTO_OPEN_SECONDS_OFFSET) =
            (float)AUTO_OPEN_BOX_SECONDS;
        changed = 1;
    }
    if (before_duration > (float)AUTO_OPEN_BOX_SECONDS ||
        (enabled && !(before_duration > 0.0f))) {
        *(float *)(box + STAGE_BOX_AUTO_OPEN_DURATION_OFFSET) =
            (float)AUTO_OPEN_BOX_SECONDS;
        changed = 1;
        duration_was_clamped = 1;
    }
    after_duration = *(float *)(box + STAGE_BOX_AUTO_OPEN_DURATION_OFFSET);
    if (duration_was_clamped && enabled && before_elapsed > after_duration) {
        *(float *)(box + STAGE_BOX_AUTO_OPEN_ELAPSED_OFFSET) = 0.0f;
        changed = 1;
    }
    if (duration_was_clamped && before_paused_elapsed > after_duration) {
        *(float *)(box + STAGE_BOX_AUTO_OPEN_PAUSED_ELAPSED_OFFSET) = 0.0f;
        changed = 1;
    }
    if (!changed) return 0;

    after_duration = *(float *)(box + STAGE_BOX_AUTO_OPEN_DURATION_OFFSET);
    after_configured = *(float *)(box + STAGE_BOX_AUTO_OPEN_SECONDS_OFFSET);
    after_elapsed = *(float *)(box + STAGE_BOX_AUTO_OPEN_ELAPSED_OFFSET);
    after_paused_elapsed =
        *(float *)(box + STAGE_BOX_AUTO_OPEN_PAUSED_ELAPSED_OFFSET);
    now = GetTickCount();
    if (!g_last_auto_chest_open_cd_log_tick ||
        (DWORD)(now - g_last_auto_chest_open_cd_log_tick) >= 5000) {
        log_line("auto chest open cd clamped: source=%s type=%d(%s) enabled=%d duration=%ds->%ds configured=%ds->%ds elapsed=%ds->%ds paused=%ds->%ds",
                 source ? source : "unknown",
                 box_type,
                 box_type_name((unsigned int)box_type),
                 enabled,
                 (int)(before_duration + 0.5f),
                 (int)(after_duration + 0.5f),
                 (int)(before_configured + 0.5f),
                 (int)(after_configured + 0.5f),
                 (int)(before_elapsed + 0.5f),
                 (int)(after_elapsed + 0.5f),
                 (int)(before_paused_elapsed + 0.5f),
                 (int)(after_paused_elapsed + 0.5f));
        g_last_auto_chest_open_cd_log_tick = now;
    }
    return 1;
}

static __int64 __fastcall hook_auto_chest_open_move_next(void *state_machine,
                                                         void *method)
{
    void *stage_box = NULL;

    if (state_machine &&
        memory_range_readable(state_machine,
                              AUTO_CHEST_OPEN_STATE_STAGE_BOX_OFFSET + sizeof(void *))) {
        stage_box = *(void **)((unsigned char *)state_machine +
                               AUTO_CHEST_OPEN_STATE_STAGE_BOX_OFFSET);
    }
    clamp_stage_box_auto_open_cd(stage_box, "timer");
    begin_actboss_cache_watch_from_stage_box(stage_box, "timer");
    if (g_real_auto_chest_open_move_next) {
        return g_real_auto_chest_open_move_next(state_machine, method);
    }
    return 0;
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

static int install_cube_synthesis_core_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_CUBE_SYNTHESIS_CORE);
    int original = mem_equal_local(target,
                                   k_original_cube_synthesis_core,
                                   sizeof(k_original_cube_synthesis_core));

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_cube_synthesis_core,
                                          sizeof(k_original_cube_synthesis_core),
                                          "cube synthesis core")) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("cube synthesis core hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (!write_absolute_jump_with_trampoline(target,
                                             (void *)hook_cube_synthesis_core,
                                             &g_hook_cube_synthesis_core,
                                             sizeof(k_original_cube_synthesis_core),
                                             (void **)&g_real_cube_synthesis_core)) {
        log_line("cube synthesis core hook install failed");
        return 0;
    }
    log_line("cube synthesis core hook installed");
    return 1;
}

static void restore_cube_synthesis_core_hook(HMODULE game_assembly)
{
    uintptr_t base;

    if (!game_assembly) return;
    base = (uintptr_t)game_assembly;
    restore_original_if_abs_jump((unsigned char *)(base + RVA_CUBE_SYNTHESIS_CORE),
                                 k_original_cube_synthesis_core,
                                 sizeof(k_original_cube_synthesis_core),
                                 "cube synthesis core");
}

static __int64 __fastcall hook_ui_cube_hml(void *ui_cube, void *method)
{
    if (ui_cube && memory_range_readable(ui_cube, sizeof(void *) * 4)) {
        if (g_cached_ui_cube != (LONG_PTR)ui_cube) {
            g_cached_ui_cube = (LONG_PTR)ui_cube;
            log_line("UI_Cube cached: %p", ui_cube);
        }
    }
    if (g_real_ui_cube_hml) return g_real_ui_cube_hml(ui_cube, method);
    return 0;
}

static __int64 __fastcall hook_ui_cube_on_disable(void *ui_cube, void *method)
{
    __int64 result = 0;

    if (g_real_ui_cube_on_disable) {
        result = g_real_ui_cube_on_disable(ui_cube, method);
    }
    if (ui_cube && g_cached_ui_cube == (LONG_PTR)ui_cube) {
        g_cached_ui_cube = 0;
        reset_auto_synthesis_state();
        log_line("UI_Cube cache cleared on disable");
    }
    return result;
}

static __int64 __fastcall hook_ui_cube_on_destroy(void *ui_cube, void *method)
{
    __int64 result = 0;

    if (g_real_ui_cube_on_destroy) {
        result = g_real_ui_cube_on_destroy(ui_cube, method);
    }
    if (ui_cube && g_cached_ui_cube == (LONG_PTR)ui_cube) {
        g_cached_ui_cube = 0;
        reset_auto_synthesis_state();
        log_line("UI_Cube cache cleared on destroy");
    }
    return result;
}

static int install_ui_cube_cache_hook(HMODULE game_assembly,
                                      uintptr_t rva,
                                      const unsigned char *original_prefix,
                                      SIZE_T prefix_size,
                                      void *detour,
                                      HookPatch *hook,
                                      ui_cube_instance_t *out_real,
                                      const char *label)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + rva);
    int original = mem_equal_local(target, original_prefix, prefix_size);

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          original_prefix,
                                          prefix_size,
                                          label)) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("%s hook RVA unexpected: %02X %02X %02X %02X",
                 label, target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (!write_absolute_jump_with_trampoline(target,
                                             detour,
                                             hook,
                                             prefix_size,
                                             (void **)out_real)) {
        log_line("%s hook install failed", label);
        return 0;
    }
    log_line("%s hook installed", label);
    return 1;
}

static int install_ui_cube_hooks(HMODULE game_assembly)
{
    int ok = 1;

    ok &= install_ui_cube_cache_hook(game_assembly,
                                     RVA_UI_CUBE_HML,
                                     k_original_ui_cube_hml_prefix,
                                     sizeof(k_original_ui_cube_hml_prefix),
                                     (void *)hook_ui_cube_hml,
                                     &g_hook_ui_cube_hml,
                                     &g_real_ui_cube_hml,
                                     "UI_Cube hml");
    ok &= install_ui_cube_cache_hook(game_assembly,
                                     RVA_UI_CUBE_ON_DISABLE,
                                     k_original_ui_cube_on_disable_prefix,
                                     sizeof(k_original_ui_cube_on_disable_prefix),
                                     (void *)hook_ui_cube_on_disable,
                                     &g_hook_ui_cube_on_disable,
                                     &g_real_ui_cube_on_disable,
                                     "UI_Cube OnDisable");
    ok &= install_ui_cube_cache_hook(game_assembly,
                                     RVA_UI_CUBE_ON_DESTROY,
                                     k_original_ui_cube_on_destroy_prefix,
                                     sizeof(k_original_ui_cube_on_destroy_prefix),
                                     (void *)hook_ui_cube_on_destroy,
                                     &g_hook_ui_cube_on_destroy,
                                     &g_real_ui_cube_on_destroy,
                                     "UI_Cube OnDestroy");
    return ok ? 1 : 0;
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

static int install_open_box_stats_hook(HMODULE game_assembly)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + RVA_OPEN_BOX_STATS);
    int original = mem_equal_local(target,
                                   k_original_open_box_stats,
                                   sizeof(k_original_open_box_stats));

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          k_original_open_box_stats,
                                          sizeof(k_original_open_box_stats),
                                          "open box stats")) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("open box stats hook RVA unexpected: %02X %02X %02X %02X",
                 target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (!write_absolute_jump_with_trampoline(target,
                                             (void *)hook_open_box_stats,
                                             &g_hook_open_box_stats,
                                             sizeof(k_original_open_box_stats),
                                             (void **)&g_real_open_box_stats)) {
        log_line("open box stats hook install failed");
        return 0;
    }
    log_line("open box stats hook installed: auto-open cd=%ds",
             AUTO_OPEN_BOX_SECONDS);
    g_open_box_stats_hook_installed = 1;
    return 1;
}

static int install_stage_box_auto_open_hook_at(HMODULE game_assembly,
                                               uintptr_t rva,
                                               const unsigned char *original_prefix,
                                               SIZE_T prefix_size,
                                               void *detour,
                                               HookPatch *hook,
                                               void **out_real,
                                               const char *label)
{
    uintptr_t base = (uintptr_t)game_assembly;
    unsigned char *target = (unsigned char *)(base + rva);
    int original = mem_equal_local(target, original_prefix, prefix_size);

    if (is_absolute_jump_local(target)) {
        if (!restore_original_if_abs_jump(target,
                                          original_prefix,
                                          prefix_size,
                                          label)) {
            return 0;
        }
        original = 1;
    }

    if (!original) {
        log_line("%s hook RVA unexpected: %02X %02X %02X %02X",
                 label, target[0], target[1], target[2], target[3]);
        return 0;
    }

    if (!write_absolute_jump_with_trampoline_preserve_rax(target,
                                                          detour,
                                                          hook,
                                                          prefix_size,
                                                          out_real)) {
        log_line("%s hook install failed", label);
        return 0;
    }
    log_line("%s hook installed", label);
    return 1;
}

static int install_stage_box_auto_open_hooks(HMODULE game_assembly)
{
    int timer_ok;

    timer_ok = install_stage_box_auto_open_hook_at(
        game_assembly,
        RVA_AUTO_CHEST_OPEN_MOVE_NEXT,
        k_original_auto_chest_open_move_next,
        sizeof(k_original_auto_chest_open_move_next),
        (void *)hook_auto_chest_open_move_next,
        &g_hook_auto_chest_open_move_next,
        (void **)&g_real_auto_chest_open_move_next,
        "auto chest open timer");
    if (timer_ok) {
        log_line("auto chest open timer hook installed: cd=%ds",
                 AUTO_OPEN_BOX_SECONDS);
    }
    return timer_ok;
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

static int box_reward_select_hook_needed(void)
{
    return g_reward_trace_hooks_enabled ||
           g_force_box_reward_select_enabled ||
           g_keep_boxdata_after_select_enabled ||
           g_auto_synthesis_enabled ||
           g_auto_item_lock_enabled;
}

static void update_box_reward_select_hook(HMODULE game_assembly)
{
    if (!game_assembly) return;
    if (box_reward_select_hook_needed()) {
        if (!install_box_reward_select_hook(game_assembly)) {
            log_line("box reward select hook not installed");
        }
    } else {
        restore_box_reward_select_hook(game_assembly);
    }
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
static void update_auto_synthesis_buttons(void);
static void update_item_lock_list_button(void);

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

static void update_auto_synthesis_buttons(void)
{
    if (g_overlay_synth_button) {
        SetWindowTextA(g_overlay_synth_button,
                       g_auto_synthesis_enabled ? "synth:on" : "synth:off");
        invalidate_overlay_button(g_overlay_synth_button);
    }
    if (g_overlay_synth_storage_button) {
        SetWindowTextA(g_overlay_synth_storage_button,
                       g_auto_synthesis_use_storage ? "store:on" : "store:off");
        invalidate_overlay_button(g_overlay_synth_storage_button);
    }
}

static void update_item_lock_list_button(void)
{
    WCHAR text[64];

    if (!g_overlay_item_lock_list_button) return;
    wsprintfW(text, L"\x9501\x5B9A\x6E05\x5355(%d)",
              g_auto_item_lock_selected_count);
    SetWindowTextW(g_overlay_item_lock_list_button, text);
    invalidate_overlay_button(g_overlay_item_lock_list_button);
}

static void update_item_lock_condition_buttons(void)
{
    if (g_overlay_item_lock_high_grade_button) {
        SetWindowTextW(g_overlay_item_lock_high_grade_button,
                       g_item_lock_condition_high_grade ?
                       L"G8/G9\x88C5\x5907\x6750\x6599:on" :
                       L"G8/G9\x88C5\x5907\x6750\x6599:off");
        invalidate_overlay_button(g_overlay_item_lock_high_grade_button);
    }
    if (g_overlay_item_lock_coin_button) {
        SetWindowTextW(g_overlay_item_lock_coin_button,
                       g_item_lock_condition_coin ?
                       L"\x786C\x5E01:on" :
                       L"\x786C\x5E01:off");
        invalidate_overlay_button(g_overlay_item_lock_coin_button);
    }
    if (g_overlay_item_lock_market_top_button) {
        WCHAR text[64];
        wsprintfW(text,
                  g_item_lock_condition_market_top ?
                  L"\x9AD8\x4EF7Top100(%d):on" :
                  L"\x9AD8\x4EF7Top100(%d):off",
                  g_auto_item_lock_market_top_count);
        SetWindowTextW(g_overlay_item_lock_market_top_button, text);
        invalidate_overlay_button(g_overlay_item_lock_market_top_button);
    }
    if (g_overlay_item_lock_manual_button) {
        SetWindowTextW(g_overlay_item_lock_manual_button,
                       InterlockedCompareExchange(&g_manual_item_lock_pending, 0, 0) ?
                       L"\x9501\x5B9A\x4E2D" :
                       L"\x624B\x52A8\x9501\x5B9A");
        invalidate_overlay_button(g_overlay_item_lock_manual_button);
    }
}

static void set_item_lock_condition_high_grade(int enabled)
{
    g_item_lock_condition_high_grade = enabled ? 1 : 0;
    log_line("item lock condition high grade %s",
             g_item_lock_condition_high_grade ? "enabled" : "disabled");
    append_overlay_event("LOCK G8/G9 %s",
                         g_item_lock_condition_high_grade ? "ON" : "OFF");
    update_item_lock_condition_buttons();
    save_config();
}

static void set_item_lock_condition_coin(int enabled)
{
    g_item_lock_condition_coin = enabled ? 1 : 0;
    log_line("item lock condition coin %s",
             g_item_lock_condition_coin ? "enabled" : "disabled");
    append_overlay_event("LOCK COIN %s",
                         g_item_lock_condition_coin ? "ON" : "OFF");
    update_item_lock_condition_buttons();
    save_config();
}

static void set_item_lock_condition_market_top(int enabled)
{
    g_item_lock_condition_market_top = enabled ? 1 : 0;
    if (g_item_lock_condition_market_top &&
        g_auto_item_lock_market_top_count <= 0) {
        load_auto_item_lock_market_top_ids();
    }
    log_line("item lock condition market top %s ids=%d",
             g_item_lock_condition_market_top ? "enabled" : "disabled",
             g_auto_item_lock_market_top_count);
    append_overlay_event("LOCK TOP100 %s",
                         g_item_lock_condition_market_top ? "ON" : "OFF");
    update_item_lock_condition_buttons();
    save_config();
}

static void queue_manual_item_lock_request(void)
{
    InterlockedExchange(&g_manual_item_lock_pending, 1);
    log_line("manual item lock requested from overlay");
    append_overlay_event("MANUAL LOCK requested");
    update_item_lock_condition_buttons();
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
    } else {
        log_line("auto restart unlock requested from overlay");
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

static const char *auto_item_lock_type_name(int item_type)
{
    switch (item_type) {
    case EITEM_TYPE_STAGEBOX: return "关卡宝箱";
    case EITEM_TYPE_MATERIAL: return "材料";
    case EITEM_TYPE_GEAR: return "装备";
    default: return "未知";
    }
}

static const char *auto_item_lock_grade_name(int grade)
{
    switch (grade) {
    case 0: return "普通";
    case 1: return "罕见";
    case 2: return "稀有";
    case 3: return "传奇";
    case 4: return "不朽";
    case 5: return "至宝";
    case 6: return "超凡";
    case 7: return "天界";
    case EGRADE_DIVINE: return "神圣";
    case EGRADE_COSMIC: return "宇宙";
    case EGRADE_NONE: return "无";
    default: return "未知";
    }
}

static char ascii_upper_local(char c)
{
    if (c >= 'a' && c <= 'z') return (char)(c - ('a' - 'A'));
    return c;
}

static int starts_with_i_ascii(const char *s, const char *prefix)
{
    while (*prefix) {
        if (!*s) return 0;
        if (ascii_upper_local(*s++) != ascii_upper_local(*prefix++)) {
            return 0;
        }
    }
    return 1;
}

static const char *last_path_component_local(const char *text)
{
    const char *last = text;

    if (!text) return "";
    for (const char *p = text; *p; ++p) {
        if (*p == '/' || *p == '\\' || *p == '.') {
            last = p + 1;
        }
    }
    return last;
}

static void clean_item_display_text(const char *src, char *dst, int dst_size)
{
    const char *p;
    int out = 0;
    int last_space = 1;

    if (!dst || dst_size <= 0) return;
    dst[0] = 0;
    if (!src || !src[0]) return;

    p = last_path_component_local(src);
    if (starts_with_i_ascii(p, "item_name_")) p += 10;
    else if (starts_with_i_ascii(p, "itemname_")) p += 9;
    else if (starts_with_i_ascii(p, "item_")) p += 5;
    else if (starts_with_i_ascii(p, "name_")) p += 5;

    for (; *p && out < dst_size - 1; ++p) {
        char c = *p;
        if (c == '_' || c == '-' || c == '.') {
            if (!last_space && out < dst_size - 1) {
                dst[out++] = ' ';
                last_space = 1;
            }
            continue;
        }
        dst[out++] = c;
        last_space = c == ' ' || c == '\t';
    }
    while (out > 0 && dst[out - 1] == ' ') out--;
    dst[out] = 0;
}

static void copy_auto_item_lock_name_field(char *dst,
                                           int dst_size,
                                           const char *src,
                                           int len)
{
    int out = 0;

    if (!dst || dst_size <= 0) return;
    dst[0] = 0;
    while (len > 0 &&
           (src[len - 1] == '\r' || src[len - 1] == '\n' ||
            src[len - 1] == ' ' || src[len - 1] == '\t')) {
        len--;
    }
    while (len > 0 && (*src == ' ' || *src == '\t')) {
        src++;
        len--;
    }
    while (len > 0 && out < dst_size - 1) {
        dst[out++] = *src++;
        len--;
    }
    dst[out] = 0;
}

static int load_auto_item_lock_name_table_file(const char *path)
{
    HANDLE file;
    DWORD size;
    DWORD read = 0;
    char *data;
    DWORD pos = 0;
    int loaded_before = g_auto_item_lock_name_count;

    if (!path || !path[0]) return 0;
    file = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, NULL,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE) return 0;
    size = GetFileSize(file, NULL);
    if (size == INVALID_FILE_SIZE || size == 0 ||
        size > AUTO_ITEM_LOCK_NAME_FILE_MAX_BYTES) {
        CloseHandle(file);
        return 0;
    }

    data = (char *)HeapAlloc(GetProcessHeap(), 0, (SIZE_T)size + 1);
    if (!data) {
        CloseHandle(file);
        return 0;
    }
    if (!ReadFile(file, data, size, &read, NULL)) {
        HeapFree(GetProcessHeap(), 0, data);
        CloseHandle(file);
        return 0;
    }
    CloseHandle(file);
    data[read] = 0;

    while (pos < read && g_auto_item_lock_name_count < AUTO_ITEM_LOCK_NAME_MAX) {
        DWORD line_start = pos;
        DWORD line_end;
        DWORD tab = 0;
        int has_tab = 0;
        int key_len;
        int name_len;
        AutoItemLockNameEntry *entry;

        while (pos < read && data[pos] != '\n') pos++;
        line_end = pos;
        if (pos < read && data[pos] == '\n') pos++;
        while (line_end > line_start &&
               (data[line_end - 1] == '\r' || data[line_end - 1] == '\n')) {
            line_end--;
        }
        for (tab = line_start; tab < line_end; ++tab) {
            if (data[tab] == '\t') {
                has_tab = 1;
                break;
            }
        }
        if (!has_tab || tab == line_start || tab + 1 >= line_end) continue;
        key_len = (int)(tab - line_start);
        if (key_len == 3 && mem_equal_local(data + line_start, "key", 3)) {
            continue;
        }
        name_len = (int)(line_end - tab - 1);
        entry = &g_auto_item_lock_name_table[g_auto_item_lock_name_count];
        copy_auto_item_lock_name_field(entry->key,
                                       sizeof(entry->key),
                                       data + line_start,
                                       key_len);
        copy_auto_item_lock_name_field(entry->name,
                                       sizeof(entry->name),
                                       data + tab + 1,
                                       name_len);
        if (entry->key[0] && entry->name[0]) {
            g_auto_item_lock_name_count++;
        }
    }

    HeapFree(GetProcessHeap(), 0, data);
    if (g_auto_item_lock_name_count > loaded_before) {
        log_line("auto item lock zh-Hans names loaded: count=%d source=%s",
                 g_auto_item_lock_name_count - loaded_before,
                 path);
        return 1;
    }
    return 0;
}

static int load_auto_item_lock_name_table(const char *dir)
{
    char path[MAX_PATH];

    if (!dir || !dir[0]) return 0;
    wsprintfA(path, "%s\\%s", dir, ITEM_LOCK_NAME_TABLE_FILE);
    path[sizeof(path) - 1] = 0;
    return load_auto_item_lock_name_table_file(path);
}

static void ensure_auto_item_lock_localized_names_loaded(void)
{
    if (g_auto_item_lock_names_loaded) return;
    g_auto_item_lock_names_loaded = 1;
    g_auto_item_lock_name_count = 0;
    if (load_auto_item_lock_name_table(g_base_dir)) return;
    if (g_game_dir[0] && lstrcmpiA(g_game_dir, g_base_dir) != 0) {
        load_auto_item_lock_name_table(g_game_dir);
    }
}

static int lookup_auto_item_lock_localized_name(const char *key,
                                                char *buf,
                                                int buflen)
{
    int i;

    if (!key || !key[0] || !buf || buflen <= 0) return 0;
    ensure_auto_item_lock_localized_names_loaded();
    for (i = 0; i < g_auto_item_lock_name_count; ++i) {
        if (lstrcmpA(g_auto_item_lock_name_table[i].key, key) == 0) {
            lstrcpynA(buf, g_auto_item_lock_name_table[i].name, buflen);
            buf[buflen - 1] = 0;
            return 1;
        }
    }
    return 0;
}

static void auto_item_lock_make_display_name(AutoItemLockInfo *info)
{
    char generated_key[64];

    if (!info) return;
    info->display_name[0] = 0;
    if (lookup_auto_item_lock_localized_name(info->name_key,
                                            info->display_name,
                                            sizeof(info->display_name))) {
        return;
    }
    wsprintfA(generated_key, "ItemName_%u", info->item_id);
    generated_key[sizeof(generated_key) - 1] = 0;
    if (lookup_auto_item_lock_localized_name(generated_key,
                                            info->display_name,
                                            sizeof(info->display_name))) {
        return;
    }
    clean_item_display_text(info->name_key,
                            info->display_name,
                            sizeof(info->display_name));
    if (!info->display_name[0]) {
        clean_item_display_text(info->icon_path,
                                info->display_name,
                                sizeof(info->display_name));
    }
    if (!info->display_name[0]) {
        wsprintfA(info->display_name, "item %u", info->item_id);
        info->display_name[sizeof(info->display_name) - 1] = 0;
    }
}

static COLORREF auto_item_lock_grade_color(int grade)
{
    switch (grade) {
    case 0: return RGB(178, 188, 196);
    case 1: return RGB(112, 201, 132);
    case 2: return RGB(90, 166, 234);
    case 3: return RGB(242, 157, 67);
    case 4: return RGB(235, 77, 79);
    case 5: return RGB(178, 105, 242);
    case EGRADE_BEYOND: return RGB(238, 90, 171);
    case EGRADE_CELESTIAL: return RGB(124, 203, 255);
    case EGRADE_DIVINE: return RGB(226, 180, 72);
    case EGRADE_COSMIC: return RGB(134, 162, 235);
    case EGRADE_NONE: return OVERLAY_COLOR_MUTED;
    default: return OVERLAY_COLOR_TEXT;
    }
}

static void auto_item_lock_icon_cue_text(const AutoItemLockInfo *info,
                                         char *buf,
                                         int buflen)
{
    const char *source;
    int out = 0;

    if (!buf || buflen <= 0) return;
    buf[0] = 0;
    source = info && info->display_name[0] ? info->display_name :
             info && info->icon_path[0] ? last_path_component_local(info->icon_path) : "";
    for (const char *p = source; *p && out < buflen - 1; ++p) {
        char c = *p;
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) {
            buf[out++] = ascii_upper_local(c);
            if (out >= 2) break;
        }
    }
    if (!out) {
        buf[out++] = '?';
    }
    buf[out] = 0;
}

static void auto_item_lock_format_item_label(const AutoItemLockInfo *info,
                                             char *buf,
                                             int buflen)
{
    if (!buf || buflen <= 0) return;
    if (!info) {
        lstrcpynA(buf, "", buflen);
        return;
    }
    if (info->display_name[0]) {
        if (info->item_type == EITEM_TYPE_GEAR) {
            wsprintfA(buf, "%s  #%u  [%s] [%s] [%s]",
                      info->display_name,
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type),
                      auto_item_lock_class_name(info->equip_class));
        } else {
            wsprintfA(buf, "%s  #%u  [%s] [%s]",
                      info->display_name,
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type));
        }
    } else if (info->name_key[0]) {
        if (info->item_type == EITEM_TYPE_GEAR) {
            wsprintfA(buf, "%s  #%u  [%s] [%s] [%s]",
                      info->name_key,
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type),
                      auto_item_lock_class_name(info->equip_class));
        } else {
            wsprintfA(buf, "%s  #%u  [%s] [%s]",
                      info->name_key,
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type));
        }
    } else {
        if (info->item_type == EITEM_TYPE_GEAR) {
            wsprintfA(buf, "#%u  [%s] [%s] [%s]",
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type),
                      auto_item_lock_class_name(info->equip_class));
        } else {
            wsprintfA(buf, "#%u  [%s] [%s]",
                      info->item_id,
                      auto_item_lock_grade_name(info->grade),
                      auto_item_lock_type_name(info->item_type));
        }
    }
    buf[buflen - 1] = 0;
}

static void *get_master_data_instance(uintptr_t base)
{
    void **type_slot = (void **)(base + RVA_MASTER_DATA_SINGLETON_TYPEINFO);
    void *type_info;
    void *instance;
    void *static_fields;

    if (!memory_range_readable(type_slot, sizeof(void *))) {
        return NULL;
    }
    type_info = *type_slot;
    if (!type_info ||
        !memory_range_readable(type_info,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)type_info +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (static_fields && memory_range_readable(static_fields, sizeof(void *))) {
        instance = *(void **)static_fields;
        if (instance &&
            memory_range_readable(instance,
                                  ITEM_DATA_ITEM_LIST_OFFSET + sizeof(void *))) {
            return instance;
        }
    }
    return NULL;
}

static void *get_item_cache_dictionary(uintptr_t base)
{
    void **type_slot = (void **)(base + RVA_ITEM_CACHE_STORE_TYPEINFO);
    void *type_info;
    void *static_fields;
    void *dict;

    if (!memory_range_readable(type_slot, sizeof(void *))) return NULL;
    type_info = *type_slot;
    if (!type_info ||
        !memory_range_readable(type_info,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)type_info +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields || !memory_range_readable(static_fields, sizeof(void *))) {
        return NULL;
    }
    dict = *(void **)static_fields;
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return NULL;
    }
    return dict;
}

static int load_auto_item_lock_catalog_from_game(void)
{
    uintptr_t base;
    void *item_data;
    void *list;
    int count;
    int loaded = 0;
    int i;
    DWORD now;

    if (!g_game_assembly) return 0;
    base = (uintptr_t)g_game_assembly;
    item_data = get_master_data_instance(base);
    if (!item_data) {
        log_line("auto item lock catalog load failed: master data np<bam> unavailable");
        return 0;
    }
    list = *(void **)((unsigned char *)item_data + ITEM_DATA_ITEM_LIST_OFFSET);
    count = il2cpp_list_size_local(list);
    if (count <= 0) {
        log_line("auto item lock catalog load failed: itemInfoData list unavailable or empty");
        return 0;
    }

    for (i = 0; i < count && loaded < AUTO_ITEM_LOCK_MAX_ITEMS; ++i) {
        void *item = il2cpp_list_get_local(list, i);
        AutoItemLockInfo *info = &g_auto_item_lock_catalog[loaded];
        void *name_key;
        void *icon_path_obj;
        int gear_type = 0;

        if (!item ||
            !memory_range_readable(item,
                                   ITEM_INFO_ICON_PATH_OFFSET + sizeof(void *))) {
            continue;
        }
        info->item_id = *(unsigned int *)((unsigned char *)item +
                                          ITEM_INFO_ITEM_KEY_OFFSET);
        info->item_type = *(int *)((unsigned char *)item +
                                   ITEM_INFO_ITEM_TYPE_OFFSET);
        info->grade = *(int *)((unsigned char *)item + ITEM_INFO_GRADE_OFFSET);
        gear_type = *(int *)((unsigned char *)item +
                             ITEM_INFO_GEAR_TYPE_OFFSET);
        info->equip_class = auto_item_lock_catalog_class_from_gear_type(
            info->item_type == EITEM_TYPE_GEAR ? gear_type : 0);
        info->name_key[0] = 0;
        info->display_name[0] = 0;
        info->icon_path[0] = 0;
        info->icon_bitmap = NULL;
        info->icon_bitmap_status = 0;
        name_key = *(void **)((unsigned char *)item + ITEM_INFO_NAME_KEY_OFFSET);
        read_il2cpp_string_utf8(name_key, info->name_key, sizeof(info->name_key));
        icon_path_obj = *(void **)((unsigned char *)item + ITEM_INFO_ICON_PATH_OFFSET);
        read_il2cpp_string_utf8(icon_path_obj, info->icon_path, sizeof(info->icon_path));
        auto_item_lock_make_display_name(info);
        if (!info->item_id) continue;
        loaded++;
    }

    g_auto_item_lock_catalog_count = loaded;
    InterlockedIncrement(&g_auto_item_lock_catalog_version);
    now = GetTickCount();
    if (!g_auto_item_lock_last_catalog_log_tick ||
        now - g_auto_item_lock_last_catalog_log_tick > 10000) {
        log_line("auto item lock catalog loaded: items=%d source=np<bam>.itemInfoData",
                 g_auto_item_lock_catalog_count);
        g_auto_item_lock_last_catalog_log_tick = now;
    }
    return loaded;
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

static void *get_ui_manager_instance(uintptr_t base)
{
    void **type_slot = (void **)(base + RVA_UI_MANAGER_TYPEINFO);
    void *ui_manager_type;
    void *static_fields;
    void *ui_manager;

    if (!memory_range_readable(type_slot, sizeof(void *))) return NULL;
    ui_manager_type = *type_slot;
    if (!ui_manager_type ||
        !memory_range_readable(ui_manager_type,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)ui_manager_type +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields || !memory_range_readable(static_fields, sizeof(void *))) {
        return NULL;
    }
    ui_manager = *(void **)static_fields;
    if (!ui_manager ||
        !memory_range_readable(ui_manager,
                               UI_MANAGER_UI_NEW_STASH_OFFSET + sizeof(void *))) {
        return NULL;
    }
    return ui_manager;
}

static void *get_slot_manager_instance(uintptr_t base)
{
    void **type_slot = (void **)(base + RVA_SLOT_MANAGER_TYPEINFO);
    void *slot_manager_type;
    void *static_fields;
    void *slot_manager;

    if (!memory_range_readable(type_slot, sizeof(void *))) return NULL;
    slot_manager_type = *type_slot;
    if (!slot_manager_type ||
        !memory_range_readable(slot_manager_type,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)slot_manager_type +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields || !memory_range_readable(static_fields, sizeof(void *))) {
        return NULL;
    }
    slot_manager = *(void **)static_fields;
    if (!slot_manager || !memory_range_readable(slot_manager, sizeof(void *) * 4)) {
        return NULL;
    }
    return slot_manager;
}

static void *get_cube_static_fields(uintptr_t base)
{
    void **type_slot = (void **)(base + RVA_CUBE_TYPEINFO);
    void *type_info;
    void *static_fields;

    if (!memory_range_readable(type_slot, sizeof(void *))) return NULL;
    type_info = *type_slot;
    if (!type_info ||
        !memory_range_readable(type_info,
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET + sizeof(void *))) {
        return NULL;
    }
    static_fields = *(void **)((unsigned char *)type_info +
                               IL2CPP_TYPE_STATIC_FIELDS_OFFSET);
    if (!static_fields ||
        !memory_range_readable(static_fields,
                               CUBE_CURRENT_RECIPE_OFFSET + sizeof(void *))) {
        return NULL;
    }
    return static_fields;
}

static void *get_cube_current_recipe(uintptr_t base)
{
    void *static_fields = get_cube_static_fields(base);
    void *current_recipe;

    if (!static_fields) return NULL;
    current_recipe = *(void **)((unsigned char *)static_fields +
                                CUBE_CURRENT_RECIPE_OFFSET);
    if (!current_recipe ||
        !memory_range_readable(current_recipe, 0xD8)) {
        return NULL;
    }
    return current_recipe;
}

static void *ensure_cube_current_recipe(uintptr_t base)
{
    cube_select_recipe_t select_recipe;
    void *current_recipe;

    current_recipe = get_cube_current_recipe(base);
    if (current_recipe) return current_recipe;

    select_recipe =
        (cube_select_recipe_t)(base + RVA_CUBE_SELECT_RECIPE_TYPE);
    if (!memory_range_readable((void *)select_recipe, 12)) {
        return NULL;
    }
    select_recipe(ERECIPE_SYNTHESIS, NULL);
    return get_cube_current_recipe(base);
}

static TBHS_UNUSED void *get_ui_cube_instance(uintptr_t base)
{
    void *ui_cube = (void *)g_cached_ui_cube;
    void *ui_manager;

    if (ui_cube && memory_range_readable(ui_cube, sizeof(void *) * 4)) {
        return ui_cube;
    }
    if (ui_cube) {
        g_cached_ui_cube = 0;
    }

    ui_manager = get_ui_manager_instance(base);
    if (!ui_manager) return NULL;
    ui_cube = *(void **)((unsigned char *)ui_manager + UI_MANAGER_UI_CUBE_OFFSET);
    if (!ui_cube || !memory_range_readable(ui_cube, sizeof(void *) * 4)) {
        return NULL;
    }
    g_cached_ui_cube = (LONG_PTR)ui_cube;
    return ui_cube;
}

static void *get_ui_hero_instance(uintptr_t base)
{
    void *ui_manager = get_ui_manager_instance(base);
    void *ui_hero;

    if (!ui_manager ||
        !memory_range_readable(ui_manager,
                               UI_MANAGER_UI_HERO_OFFSET + sizeof(void *))) {
        return NULL;
    }
    ui_hero = *(void **)((unsigned char *)ui_manager + UI_MANAGER_UI_HERO_OFFSET);
    if (!ui_hero || !memory_range_readable(ui_hero, sizeof(void *) * 4)) {
        return NULL;
    }
    return ui_hero;
}

static int move_inventory_slots_to_stash_from_backend(uintptr_t base)
{
    void *slot_manager;
    slot_manager_move_all_t move_all;

    slot_manager = get_slot_manager_instance(base);
    move_all = (slot_manager_move_all_t)(base + RVA_SLOT_MANAGER_MOVE_ALL);
    if (!slot_manager ||
        !memory_range_readable((void *)move_all, 12)) {
        log_line("inventory stash backend unavailable: slot_manager=%p move_all=%d",
                 slot_manager,
                 memory_range_readable((void *)move_all, 12) ? 1 : 0);
        return 0;
    }

    move_all(slot_manager, ESLOT_TYPE_INVENTORY, ESLOT_TYPE_STASH, NULL);
    return 1;
}

static void *get_ui_new_stash_instance(uintptr_t base)
{
    void *ui_manager = get_ui_manager_instance(base);
    void *ui_stash;

    if (!ui_manager ||
        !memory_range_readable(ui_manager,
                               UI_MANAGER_UI_NEW_STASH_OFFSET + sizeof(void *))) {
        return NULL;
    }
    ui_stash = *(void **)((unsigned char *)ui_manager + UI_MANAGER_UI_NEW_STASH_OFFSET);
    if (!ui_stash || !memory_range_readable(ui_stash, sizeof(void *) * 4)) {
        return NULL;
    }
    return ui_stash;
}

static int main_tab_target_ready(uintptr_t base, int tab)
{
    if (tab == EMAIN_TAB_CUBE) {
        return get_ui_cube_instance(base) != NULL;
    }
    return 1;
}

static int ensure_main_tab_open(uintptr_t base, int tab)
{
    void *ui_manager;
    void *ui_main;
    void *target_ui = NULL;
    ui_manager_show_base_t show_ui_base;
    ui_main_action_t open_tab = NULL;
    int current_tab;

    ui_manager = get_ui_manager_instance(base);
    if (!ui_manager ||
        !memory_range_readable(ui_manager,
                               UI_MANAGER_UI_NEW_STASH_OFFSET + sizeof(void *))) {
        return 0;
    }

    current_tab = 0;
    if (memory_range_readable((unsigned char *)ui_manager +
                                  UI_MANAGER_CURRENT_MAIN_TAB_OFFSET,
                              sizeof(int))) {
        current_tab = *(int *)((unsigned char *)ui_manager +
                               UI_MANAGER_CURRENT_MAIN_TAB_OFFSET);
    }
    if (current_tab == tab && main_tab_target_ready(base, tab)) {
        return 1;
    }

    if (tab == EMAIN_TAB_CUBE &&
        memory_range_readable(ui_manager,
                              UI_MANAGER_UI_CUBE_OFFSET + sizeof(void *))) {
        target_ui = *(void **)((unsigned char *)ui_manager +
                               UI_MANAGER_UI_CUBE_OFFSET);
    }

    show_ui_base = (ui_manager_show_base_t)(base + RVA_UI_MANAGER_SHOW_UI_BASE);
    if (target_ui &&
        memory_range_readable(target_ui, sizeof(void *) * 4) &&
        memory_range_readable((void *)show_ui_base, 12)) {
        show_ui_base(ui_manager, target_ui, NULL);
        return 1;
    }

    if (!memory_range_readable(ui_manager,
                               UI_MANAGER_UI_MAIN_OFFSET + sizeof(void *))) {
        return 0;
    }
    ui_main = *(void **)((unsigned char *)ui_manager + UI_MANAGER_UI_MAIN_OFFSET);
    if (!ui_main || !memory_range_readable(ui_main, sizeof(void *) * 4)) {
        return 0;
    }

    if (tab == EMAIN_TAB_CUBE) {
        open_tab = (ui_main_action_t)(base + RVA_UI_MAIN_OPEN_CUBE);
    }
    if (!open_tab || !memory_range_readable((void *)open_tab, 12)) {
        return 0;
    }

    open_tab(ui_main, NULL);
    return 0;
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
        return 0;
    }
    if (!get_current_stage_target(base, current_stage,
                                  &act, &difficulty, &stage_type, &stage_no, &stage_key)
        || stage_key <= 0) {
        log_line("auto restart lock failed: current stage key unavailable");
        return 0;
    }
    if (stage_type != ESTAGE_TYPE_NORMAL) {
        log_line("auto restart lock failed: only normal stages are supported, type=%d stage_no=%d",
                 stage_type, stage_no);
        return 0;
    }
    find_stage_enter_key_for_stage_key(base, act, difficulty,
                                       ESTAGE_TYPE_NORMAL, stage_key,
                                       &enter_key, &previous_stage_no);
    if (enter_key <= 0) {
        log_line("auto restart lock failed: previous stage key unavailable: act=%d difficulty=%d type=%d stage_no=%d stage_key=%d",
                 act, difficulty, stage_type, stage_no, stage_key);
        return 0;
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
    (void)was_locked;
    (void)act;
    (void)difficulty;
    (void)stage_no;
    (void)stage_key;
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
}

static void maybe_preload_auto_item_lock_catalog_from_game_thread(void)
{
    DWORD now;
    int preload_pending;
    int list_window_open;

    preload_pending = g_auto_item_lock_catalog_preload_pending ? 1 : 0;
    list_window_open = (g_item_lock_list_hwnd && IsWindow(g_item_lock_list_hwnd)) ? 1 : 0;
    if (g_auto_item_lock_catalog_count > 0) {
        InterlockedExchange(&g_auto_item_lock_catalog_preload_pending, 0);
        return;
    }
    if (!preload_pending && !list_window_open) return;
    if (!g_game_assembly) return;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;

    now = GetTickCount();
    if (g_auto_item_lock_last_catalog_try_tick &&
        (DWORD)(now - g_auto_item_lock_last_catalog_try_tick) < 2000) {
        return;
    }
    g_auto_item_lock_last_catalog_try_tick = now;
    if (load_auto_item_lock_catalog_from_game()) {
        InterlockedExchange(&g_auto_item_lock_catalog_preload_pending, 0);
    }
}

static void maybe_auto_item_lock_from_game_thread(void)
{
    DWORD now;
    unsigned int item_id;
    unsigned __int64 unique_id;
    char unique_key[64];
    char unique_id_text[32];

    if (!g_game_assembly) return;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;
    if (!g_auto_item_lock_pending) return;

    now = GetTickCount();
    if (g_auto_item_lock_last_try_tick &&
        (DWORD)(now - g_auto_item_lock_last_try_tick) < 500) {
        return;
    }
    g_auto_item_lock_last_try_tick = now;

    item_id = g_auto_item_lock_pending_item_id;
    unique_id = g_auto_item_lock_pending_unique_id;
    unique_key[0] = 0;
    lstrcpynA(unique_key,
              g_auto_item_lock_pending_unique_key,
              sizeof(unique_key));

    if (!unique_id) {
        log_line("AUTO ITEM LOCK canceled: missing unique id for item_id=%u unique_key=%s",
                 item_id,
                 unique_key[0] ? unique_key : "-");
        InterlockedExchange(&g_auto_item_lock_pending, 0);
        return;
    }

    if (try_auto_item_lock_now(item_id, unique_id, unique_key)) {
        InterlockedExchange(&g_auto_item_lock_pending, 0);
        return;
    }

    if (g_auto_item_lock_pending_tick &&
        (DWORD)(now - g_auto_item_lock_pending_tick) > 15000) {
        format_u64_local(unique_id_text, sizeof(unique_id_text), unique_id);
        log_line("AUTO ITEM LOCK expired: item_id=%u unique_key=%s unique_id=%s",
                 item_id,
                 unique_key[0] ? unique_key : "-",
                 unique_id_text);
        append_overlay_event("LOCK ITEM expired %u", item_id);
        InterlockedExchange(&g_auto_item_lock_pending, 0);
    }
}

static void manual_item_lock_cache_if_match(void *item_cache,
                                            const char *source,
                                            ManualItemLockStats *stats)
{
    unsigned int item_id = 0;
    int item_type = -1;
    int grade = -1;
    int already_locked = 0;

    if (!stats) return;
    if (!item_cache) {
        stats->skipped++;
        return;
    }
    stats->scanned++;
    if (!auto_item_lock_read_cache_info(item_cache,
                                        &item_id,
                                        &item_type,
                                        &grade,
                                        NULL)) {
        stats->skipped++;
        return;
    }
    if (!auto_item_lock_item_matches_conditions(item_id, item_type, grade)) {
        return;
    }
    stats->matched++;
    if (auto_item_lock_apply_cache_now(item_cache,
                                       item_id,
                                       source,
                                       &already_locked)) {
        if (already_locked) {
            stats->already_locked++;
        } else {
            stats->locked++;
        }
    } else {
        stats->skipped++;
    }
}

static void manual_item_lock_scan_slot_list(void *slot_list,
                                            const char *source,
                                            ManualItemLockStats *stats)
{
    int count;
    int i;

    if (!stats) return;
    count = il2cpp_list_size_local(slot_list);
    for (i = 0; i < count; ++i) {
        void *slot = il2cpp_list_get_local(slot_list, i);
        void *item_cache;

        if (!slot ||
            !memory_range_readable(slot,
                                   ITEM_SLOT_ITEM_CACHE_OFFSET + sizeof(void *))) {
            stats->skipped++;
            continue;
        }
        item_cache = *(void **)((unsigned char *)slot +
                                ITEM_SLOT_ITEM_CACHE_OFFSET);
        manual_item_lock_cache_if_match(item_cache, source, stats);
    }
}

static void manual_item_lock_scan_item_cache_dictionary(const char *source,
                                                        ManualItemLockStats *stats)
{
    uintptr_t base;
    uintptr_t type_slot_address;
    void *dict;
    void *entries;
    int count;
    int array_len;
    int i;

    if (!stats || !g_game_assembly) return;
    base = (uintptr_t)g_game_assembly;
    type_slot_address = base + RVA_ITEM_CACHE_STORE_TYPEINFO;
    if (!memory_range_readable((void *)type_slot_address, sizeof(void *))) {
        return;
    }

    dict = get_item_cache_dictionary(base);
    if (!dict ||
        !memory_range_readable(dict,
                               IL2CPP_DICT_COUNT_OFFSET + sizeof(int))) {
        return;
    }
    count = *(int *)((unsigned char *)dict + IL2CPP_DICT_COUNT_OFFSET);
    if (count <= 0 || count > 200000) return;

    entries = *(void **)((unsigned char *)dict + IL2CPP_DICT_ENTRIES_OFFSET);
    if (!entries ||
        !memory_range_readable(entries,
                               IL2CPP_ARRAY_DATA_OFFSET + sizeof(void *))) {
        return;
    }
    array_len = *(int *)((unsigned char *)entries + IL2CPP_ARRAY_LENGTH_OFFSET);
    if (array_len <= 0 || array_len > 200000 || count > array_len) return;

    for (i = 0; i < count; ++i) {
        unsigned char *entry = (unsigned char *)entries +
                               IL2CPP_ARRAY_DATA_OFFSET +
                               ((SIZE_T)i *
                                IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE);
        int hash_code;
        void *item_cache;

        if (!memory_range_readable(entry,
                                   IL2CPP_DICT_U64_OBJECT_ENTRY_SIZE)) {
            break;
        }
        hash_code = *(int *)(entry +
                             IL2CPP_DICT_U64_OBJECT_ENTRY_HASH_OFFSET);
        if (hash_code < 0) continue;
        item_cache = *(void **)(entry +
                                IL2CPP_DICT_U64_OBJECT_ENTRY_VALUE_OFFSET);
        manual_item_lock_cache_if_match(item_cache, source, stats);
    }
}

static void manual_item_lock_from_game_thread(void)
{
    uintptr_t base;
    void *ui_hero = NULL;
    void *ui_stash = NULL;
    void *cache_dict = NULL;
    void *inventory_slots = NULL;
    void *stash_slots = NULL;
    ManualItemLockStats stats;

    if (!g_game_assembly) return;
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;
    if (!InterlockedExchange(&g_manual_item_lock_pending, 0)) return;

    stats.scanned = 0;
    stats.matched = 0;
    stats.locked = 0;
    stats.already_locked = 0;
    stats.skipped = 0;

    base = (uintptr_t)g_game_assembly;
    cache_dict = get_item_cache_dictionary(base);
    if (cache_dict) {
        manual_item_lock_scan_item_cache_dictionary("manual item cache", &stats);
    } else {
        ui_hero = get_ui_hero_instance(base);
        if (ui_hero &&
            memory_range_readable(ui_hero,
                                  UI_HERO_INVENTORY_SLOTS_OFFSET + sizeof(void *))) {
            inventory_slots = *(void **)((unsigned char *)ui_hero +
                                         UI_HERO_INVENTORY_SLOTS_OFFSET);
            manual_item_lock_scan_slot_list(inventory_slots, "manual inventory", &stats);
        }

        ui_stash = get_ui_new_stash_instance(base);
        if (ui_stash &&
            memory_range_readable(ui_stash,
                                  UI_REMAKE_STASH_SLOT_LIST_OFFSET + sizeof(void *))) {
            stash_slots = *(void **)((unsigned char *)ui_stash +
                                     UI_REMAKE_STASH_SLOT_LIST_OFFSET);
            manual_item_lock_scan_slot_list(stash_slots, "manual stash", &stats);
        }
    }

    log_line("manual item lock done: inventory=%p stash=%p cache_dict=%p scanned=%d matched=%d locked=%d already=%d skipped=%d",
             inventory_slots,
             stash_slots,
             cache_dict,
             stats.scanned,
             stats.matched,
             stats.locked,
             stats.already_locked,
             stats.skipped);
    append_overlay_event("MANUAL LOCK %d/%d already %d",
                         stats.locked,
                         stats.matched,
                         stats.already_locked);
    update_item_lock_condition_buttons();
}

static void maybe_auto_synthesis_from_game_thread(void)
{
    uintptr_t base;
    DWORD now;
    void *current_recipe;
    cube_set_bool_t set_use_storage;
    cube_set_int_t set_synthesis_type;
    cube_clear_current_recipe_t clear_current_recipe;
    cube_autofill_current_recipe_t autofill_current_recipe;
    cube_trigger_current_recipe_t trigger_current_recipe;

    if (!g_auto_synthesis_enabled || !g_game_assembly) {
        reset_auto_synthesis_state();
        return;
    }
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;

    now = GetTickCount();
    base = (uintptr_t)g_game_assembly;

    if (g_auto_synthesis_phase == AUTO_SYNTHESIS_PHASE_IDLE) {
        if (g_auto_synthesis_next_tick &&
            (LONG)(now - g_auto_synthesis_next_tick) < 0) {
            return;
        }
        if (!g_auto_synthesis_pending ||
            InterlockedExchange(&g_auto_synthesis_pending, 0) == 0) {
            g_auto_synthesis_next_tick = 0;
            return;
        }

        ensure_main_tab_open(base, EMAIN_TAB_CUBE);
        log_line("auto synthesis Cube page open requested");

        current_recipe = ensure_cube_current_recipe(base);
        if (!current_recipe) {
            if (!g_last_auto_synthesis_log_tick ||
                (DWORD)(now - g_last_auto_synthesis_log_tick) >= 10000) {
                log_line("auto synthesis waiting: Cube current recipe unavailable");
                g_last_auto_synthesis_log_tick = now;
            }
            g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
            InterlockedExchange(&g_auto_synthesis_pending, 1);
            return;
        }

        set_use_storage = (cube_set_bool_t)(base + RVA_CUBE_SET_USE_STORAGE);
        set_synthesis_type = (cube_set_int_t)(base + RVA_CUBE_SET_SYNTHESIS_TYPE);
        clear_current_recipe =
            (cube_clear_current_recipe_t)(base + RVA_CUBE_CLEAR_CURRENT_RECIPE);

        if (!memory_range_readable((void *)set_use_storage, 12) ||
            !memory_range_readable((void *)set_synthesis_type, 12) ||
            !memory_range_readable((void *)clear_current_recipe, 12)) {
            g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
            log_line("auto synthesis skipped: synthesis functions unavailable");
            return;
        }

        set_use_storage((char)(g_auto_synthesis_use_storage ? 1 : 0), NULL);
        set_synthesis_type(EITEM_SYNTHESIS_GEAR, NULL);
        clear_current_recipe(NULL);

        g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_FILL;
        g_auto_synthesis_step_tick = now + AUTO_SYNTHESIS_FILL_DELAY_MS;
        g_auto_synthesis_next_tick = 0;
        log_line("auto synthesis clear sent: recipe=%p storage=%d next_delay=%lu",
                 current_recipe,
                 g_auto_synthesis_use_storage,
                 (unsigned long)AUTO_SYNTHESIS_FILL_DELAY_MS);
        return;
    }

    if (g_auto_synthesis_phase == AUTO_SYNTHESIS_PHASE_WAIT_FILL) {
        if ((LONG)(now - g_auto_synthesis_step_tick) < 0) return;

        current_recipe = ensure_cube_current_recipe(base);
        autofill_current_recipe =
            (cube_autofill_current_recipe_t)(base + RVA_CUBE_AUTOFILL_CURRENT_RECIPE);
        if (!current_recipe ||
            !memory_range_readable((void *)autofill_current_recipe, 12)) {
            g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_IDLE;
            g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
            if (!current_recipe) {
                InterlockedExchange(&g_auto_synthesis_pending, 1);
            }
            log_line("auto synthesis autofill skipped: Cube current recipe or function unavailable");
            return;
        }
        set_synthesis_type = (cube_set_int_t)(base + RVA_CUBE_SET_SYNTHESIS_TYPE);
        if (memory_range_readable((void *)set_synthesis_type, 12)) {
            set_synthesis_type(EITEM_SYNTHESIS_GEAR, NULL);
        }
        autofill_current_recipe(current_recipe, NULL);
        g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER;
        g_auto_synthesis_step_tick = now + AUTO_SYNTHESIS_TRIGGER_DELAY_MS;
        log_line("auto synthesis autofill sent: recipe=%p trigger_delay=%lu",
                 current_recipe,
                 (unsigned long)AUTO_SYNTHESIS_TRIGGER_DELAY_MS);
        return;
    }

    if (g_auto_synthesis_phase == AUTO_SYNTHESIS_PHASE_WAIT_TRIGGER) {
        if ((LONG)(now - g_auto_synthesis_step_tick) < 0) return;

        trigger_current_recipe =
            (cube_trigger_current_recipe_t)(base + RVA_CUBE_TRIGGER_CURRENT_RECIPE);
        if (!memory_range_readable((void *)trigger_current_recipe, 12)) {
            g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_IDLE;
            g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
            log_line("auto synthesis trigger skipped: trigger function unavailable");
            return;
        }
        g_auto_synthesis_result_watch_until =
            now + AUTO_SYNTHESIS_RESULT_WATCH_MS;
        InterlockedExchange(&g_auto_synthesis_result_pending, 1);
        trigger_current_recipe(NULL);
        g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_WAIT_CLEAR;
        g_auto_synthesis_step_tick = now + AUTO_SYNTHESIS_POST_TRIGGER_CLEAR_DELAY_MS;
        g_auto_synthesis_next_tick = 0;
        log_line("auto synthesis trigger sent: storage=%d clear_delay=%lu",
                 g_auto_synthesis_use_storage,
                 (unsigned long)AUTO_SYNTHESIS_POST_TRIGGER_CLEAR_DELAY_MS);
        return;
    }

    if (g_auto_synthesis_phase == AUTO_SYNTHESIS_PHASE_WAIT_CLEAR) {
        if ((LONG)(now - g_auto_synthesis_step_tick) < 0) return;

        current_recipe = ensure_cube_current_recipe(base);
        clear_current_recipe =
            (cube_clear_current_recipe_t)(base + RVA_CUBE_CLEAR_CURRENT_RECIPE);
        if (!current_recipe ||
            !memory_range_readable((void *)clear_current_recipe, 12)) {
            g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_IDLE;
            g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
            g_auto_synthesis_step_tick = 0;
            log_line("auto synthesis post-trigger clear skipped: Cube current recipe or function unavailable");
            return;
        }
        clear_current_recipe(NULL);
        g_auto_synthesis_phase = AUTO_SYNTHESIS_PHASE_IDLE;
        g_auto_synthesis_next_tick = now + AUTO_SYNTHESIS_INTERVAL_MS;
        g_auto_synthesis_step_tick = 0;
        log_line("auto synthesis post-trigger clear sent: recipe=%p storage=%d next_delay=%lu",
                 current_recipe,
                 g_auto_synthesis_use_storage,
                 (unsigned long)AUTO_SYNTHESIS_INTERVAL_MS);
        return;
    }

}

static void maybe_periodic_storage_from_game_thread(void)
{
    uintptr_t base;
    DWORD now;
    int backend_moves;

    if (!g_auto_synthesis_use_storage || !g_game_assembly) {
        g_periodic_storage_next_tick = 0;
        return;
    }
    if (!g_game_thread_id || GetCurrentThreadId() != g_game_thread_id) return;
    if (g_auto_synthesis_phase != AUTO_SYNTHESIS_PHASE_IDLE) return;

    now = GetTickCount();
    if (g_periodic_storage_next_tick &&
        (LONG)(now - g_periodic_storage_next_tick) < 0) {
        return;
    }

    base = (uintptr_t)g_game_assembly;
    backend_moves = move_inventory_slots_to_stash_from_backend(base);
    if (backend_moves > 0) {
        log_line("periodic stash backend batch sent: source=inventory target=stash next_delay=%lu",
                 (unsigned long)AUTO_STORAGE_INTERVAL_MS);
    } else {
        log_line("periodic stash move skipped: backend unavailable next_delay=%lu",
                 (unsigned long)AUTO_STORAGE_INTERVAL_MS);
    }
    g_periodic_storage_next_tick = now + AUTO_STORAGE_INTERVAL_MS;
}

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
    maybe_auto_switch_from_game_thread();
    maybe_preload_auto_item_lock_catalog_from_game_thread();
    maybe_auto_item_lock_from_game_thread();
    manual_item_lock_from_game_thread();
    maybe_handle_actboss_cache_watch_from_game_thread();
    maybe_handle_synthesis_cache_watch_from_game_thread();
    maybe_auto_synthesis_from_game_thread();
    maybe_periodic_storage_from_game_thread();
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

static void release_auto_item_lock_icon_bitmaps(void)
{
    int i;

    for (i = 0; i < g_auto_item_lock_catalog_count; ++i) {
        AutoItemLockInfo *info = &g_auto_item_lock_catalog[i];
        if (info->icon_bitmap) {
            DeleteObject(info->icon_bitmap);
            info->icon_bitmap = NULL;
        }
        info->icon_bitmap_status = 0;
    }
    if (g_msimg32) {
        FreeLibrary(g_msimg32);
        g_msimg32 = NULL;
    }
    g_transparent_blt = NULL;
    g_transparent_blt_checked = 0;
}

static void draw_overlay_log_text_utf8(HDC hdc, const char *text, RECT *row)
{
    WCHAR wide[OVERLAY_LOG_LINE_SIZE];
    int written;

    if (!text || !row) return;
    written = MultiByteToWideChar(CP_UTF8, 0, text, -1,
                                  wide, OVERLAY_LOG_LINE_SIZE);
    if (written <= 0) {
        written = MultiByteToWideChar(CP_ACP, 0, text, -1,
                                      wide, OVERLAY_LOG_LINE_SIZE);
    }
    if (written <= 0) return;
    wide[OVERLAY_LOG_LINE_SIZE - 1] = 0;
    DrawTextW(hdc, wide, -1, row,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE |
              DT_END_ELLIPSIS | DT_NOPREFIX);
}

static RECT overlay_view_button_rect(int id)
{
    RECT rc;
    int left = OVERLAY_VIEW_BUTTON_MINIMIZED_X;

    if (id == OVERLAY_BUTTON_VIEW_EXPANDED) {
        left = OVERLAY_VIEW_BUTTON_EXPANDED_X;
    } else if (id == OVERLAY_BUTTON_VIEW_LOG_ONLY) {
        left = OVERLAY_VIEW_BUTTON_LOG_ONLY_X;
    }

    rc.left = left;
    rc.top = OVERLAY_VIEW_BUTTON_TOP;
    rc.right = left + OVERLAY_VIEW_BUTTON_SIZE;
    rc.bottom = OVERLAY_VIEW_BUTTON_TOP + OVERLAY_VIEW_BUTTON_SIZE;
    return rc;
}

static int overlay_view_button_active(int id)
{
    if (id == OVERLAY_BUTTON_VIEW_EXPANDED) {
        return g_overlay_view_mode == OVERLAY_VIEW_MODE_EXPANDED;
    }
    if (id == OVERLAY_BUTTON_VIEW_LOG_ONLY) {
        return g_overlay_view_mode == OVERLAY_VIEW_MODE_LOG_ONLY;
    }
    if (id == OVERLAY_BUTTON_VIEW_MINIMIZED) {
        return g_overlay_view_mode == OVERLAY_VIEW_MODE_MINIMIZED;
    }
    return 0;
}

static void draw_overlay_view_button(HDC hdc, int id, const char *text)
{
    RECT rc;
    RECT top;
    HBRUSH fill;
    HBRUSH border;
    HGDIOBJ old_font;
    int active;

    if (!hdc || !text) return;
    init_overlay_style();
    rc = overlay_view_button_rect(id);
    active = overlay_view_button_active(id);
    fill = active ? g_overlay_button_active_brush : g_overlay_button_brush;
    border = active ? g_overlay_accent_brush : g_overlay_border_brush;

    FillRect(hdc, &rc, fill);
    FrameRect(hdc, &rc, border);
    top = rc;
    top.bottom = top.top + 1;
    FillRect(hdc, &top, active ? g_overlay_accent_brush : g_overlay_panel_brush);

    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, active ? RGB(246, 237, 190) : OVERLAY_COLOR_TEXT);
    old_font = SelectObject(hdc, active ? g_overlay_font_bold : g_overlay_font);
    DrawTextA(hdc, text, -1, &rc,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    SelectObject(hdc, old_font);
}

static void draw_overlay_view_buttons(HDC hdc)
{
    draw_overlay_view_button(hdc, OVERLAY_BUTTON_VIEW_EXPANDED, "A");
    draw_overlay_view_button(hdc, OVERLAY_BUTTON_VIEW_LOG_ONLY, "L");
    draw_overlay_view_button(hdc, OVERLAY_BUTTON_VIEW_MINIMIZED, "_");
}

static int overlay_view_button_hit_test(POINT pt)
{
    RECT rc;

    rc = overlay_view_button_rect(OVERLAY_BUTTON_VIEW_EXPANDED);
    if (PtInRect(&rc, pt)) return OVERLAY_BUTTON_VIEW_EXPANDED;
    rc = overlay_view_button_rect(OVERLAY_BUTTON_VIEW_LOG_ONLY);
    if (PtInRect(&rc, pt)) return OVERLAY_BUTTON_VIEW_LOG_ONLY;
    rc = overlay_view_button_rect(OVERLAY_BUTTON_VIEW_MINIMIZED);
    if (PtInRect(&rc, pt)) return OVERLAY_BUTTON_VIEW_MINIMIZED;
    return 0;
}

static void draw_overlay_drop_log_filter_row(HDC hdc,
                                             int filter_id,
                                             const WCHAR *label)
{
    RECT rc = overlay_drop_log_filter_row_rect(filter_id);
    RECT check;
    RECT text;
    HBRUSH fill;
    HBRUSH border;
    HGDIOBJ old_font;
    int active = (g_drop_log_filter_flags & filter_id) ? 1 : 0;

    if (!hdc || !label) return;
    init_overlay_style();
    check.left = rc.left;
    check.top = rc.top + 4;
    check.right = check.left + OVERLAY_LOG_FILTER_CHECK_SIZE;
    check.bottom = check.top + OVERLAY_LOG_FILTER_CHECK_SIZE;
    fill = active ? g_overlay_button_active_brush : g_overlay_button_brush;
    border = active ? g_overlay_accent_brush : g_overlay_border_brush;
    FillRect(hdc, &check, fill);
    FrameRect(hdc, &check, border);
    if (active) {
        MoveToEx(hdc, check.left + 3, check.top + 6, NULL);
        LineTo(hdc, check.left + 5, check.bottom - 3);
        LineTo(hdc, check.right - 3, check.top + 3);
    }

    text.left = check.right + 6;
    text.top = rc.top;
    text.right = rc.right;
    text.bottom = rc.bottom;
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, active ? RGB(246, 237, 190) : OVERLAY_COLOR_TEXT);
    old_font = SelectObject(hdc, active ? g_overlay_font_bold : g_overlay_font);
    DrawTextW(hdc, label, -1, &text,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE |
              DT_END_ELLIPSIS | DT_NOPREFIX);
    SelectObject(hdc, old_font);
}

static void draw_overlay_drop_log_filters(HDC hdc)
{
    draw_overlay_drop_log_filter_row(hdc,
                                     OVERLAY_LOG_FILTER_PRICED,
                                     L"\x6709\x4EF7\x683C");
    draw_overlay_drop_log_filter_row(hdc,
                                     OVERLAY_LOG_FILTER_LEGENDARY,
                                     L"\x4F20\x5947+");
    draw_overlay_drop_log_filter_row(hdc,
                                     OVERLAY_LOG_FILTER_MARKET_TOP,
                                     L"Top100");
}

static void draw_overlay_drop_log(HDC hdc)
{
    OverlayLogEntry entries[OVERLAY_LOG_LINE_COUNT];
    OverlayLogEntry filtered[OVERLAY_LOG_LINE_COUNT];
    RECT box;
    RECT row;
    RECT track;
    RECT thumb;
    HGDIOBJ old_font;
    int count;
    int filtered_count = 0;
    int start;
    int max_scroll;
    int scroll;
    int visible;
    int first;
    int i;

    zero_memory_local(entries, sizeof(entries));
    zero_memory_local(filtered, sizeof(filtered));
    lock_drop_log();
    count = g_drop_log_count;
    start = g_drop_log_next - count;
    while (start < 0) start += OVERLAY_LOG_LINE_COUNT;
    for (i = 0; i < count && i < OVERLAY_LOG_LINE_COUNT; ++i) {
        int index = (start + i) % OVERLAY_LOG_LINE_COUNT;
        entries[i] = g_drop_log_entries[index];
        if (drop_log_entry_matches_filters(&entries[i])) {
            filtered[filtered_count++] = entries[i];
        }
    }
    max_scroll = filtered_count > OVERLAY_LOG_VISIBLE_LINES ?
                 filtered_count - OVERLAY_LOG_VISIBLE_LINES : 0;
    if (g_drop_log_scroll < 0) g_drop_log_scroll = 0;
    if (g_drop_log_scroll > max_scroll) g_drop_log_scroll = max_scroll;
    scroll = g_drop_log_scroll;
    unlock_drop_log();

    box = overlay_log_box_rect();
    draw_overlay_drop_log_filters(hdc);
    FillRect(hdc, &box, g_overlay_panel_brush);
    FrameRect(hdc, &box, g_overlay_border_brush);

    SetBkMode(hdc, TRANSPARENT);
    old_font = SelectObject(hdc, g_overlay_font);
    visible = filtered_count < OVERLAY_LOG_VISIBLE_LINES ?
              filtered_count : OVERLAY_LOG_VISIBLE_LINES;
    first = filtered_count - visible - scroll;
    if (first < 0) first = 0;
    for (i = 0; i < visible; ++i) {
        OverlayLogEntry entry = filtered[first + i];
        if (!entry.line[0]) continue;
        row.left = box.left + 8;
        row.top = box.top + 5 + i * 13;
        row.right = box.right - (max_scroll > 0 ? 16 : 8);
        row.bottom = row.top + 14;
        SetTextColor(hdc, entry.grade >= 0 ? auto_item_lock_grade_color(entry.grade) : OVERLAY_COLOR_MUTED);
        draw_overlay_log_text_utf8(hdc, entry.line, &row);
    }
    if (max_scroll > 0) {
        int track_height;
        int thumb_height;
        int thumb_top;

        track.left = box.right - 9;
        track.top = box.top + 5;
        track.right = box.right - 5;
        track.bottom = box.bottom - 5;
        FillRect(hdc, &track, g_overlay_border_brush);
        track_height = track.bottom - track.top;
        thumb_height = (track_height * OVERLAY_LOG_VISIBLE_LINES) /
                       filtered_count;
        if (thumb_height < 14) thumb_height = 14;
        if (thumb_height > track_height) thumb_height = track_height;
        thumb_top = track.top;
        if (max_scroll > 0 && track_height > thumb_height) {
            thumb_top = track.top +
                        ((max_scroll - scroll) * (track_height - thumb_height)) /
                        max_scroll;
        }
        thumb.left = track.left;
        thumb.top = thumb_top;
        thumb.right = track.right;
        thumb.bottom = thumb_top + thumb_height;
        FillRect(hdc, &thumb, g_overlay_accent_brush);
    }
    SelectObject(hdc, old_font);
}

static void paint_overlay_chrome(HWND hwnd, HDC hdc)
{
    RECT rc;
    RECT title;
    RECT line;
    RECT label;
    RECT separator;
    RECT log_box;
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
    title.right = OVERLAY_VIEW_BUTTON_EXPANDED_X - 8;
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
    draw_overlay_view_buttons(hdc);

    if (g_overlay_view_mode == OVERLAY_VIEW_MODE_MINIMIZED) {
        SelectObject(hdc, old_pen);
        SelectObject(hdc, old_brush);
        return;
    }

    if (g_overlay_view_mode == OVERLAY_VIEW_MODE_LOG_ONLY) {
        log_box = overlay_log_box_rect();
        SetTextColor(hdc, OVERLAY_COLOR_MUTED);
        old_font = SelectObject(hdc, g_overlay_font_bold);
        label.left = 12;
        label.right = 70;
        label.top = log_box.top;
        label.bottom = log_box.top + 24;
        DrawTextA(hdc, "Drops", -1, &label,
                  DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
        SelectObject(hdc, old_font);
        draw_overlay_drop_log(hdc);
        SelectObject(hdc, old_pen);
        SelectObject(hdc, old_brush);
        return;
    }

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
    DrawTextA(hdc, "Synth", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 182;
    label.bottom = 206;
    DrawTextA(hdc, "Item Lock", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 218;
    label.bottom = 242;
    DrawTextA(hdc, "Reset", -1, &label,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    label.top = 254;
    label.bottom = 278;
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
    separator.top = 212;
    separator.bottom = 213;
    FillRect(hdc, &separator, g_overlay_border_brush);
    separator.top = 248;
    separator.bottom = 249;
    FillRect(hdc, &separator, g_overlay_border_brush);
    separator.top = 300;
    separator.bottom = 301;
    FillRect(hdc, &separator, g_overlay_border_brush);

    draw_overlay_drop_log(hdc);

    SelectObject(hdc, old_pen);
    SelectObject(hdc, old_brush);
}

static void draw_overlay_button(const DRAWITEMSTRUCT *item)
{
    RECT rc;
    RECT top;
    WCHAR text[64];
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
    if (id == OVERLAY_BUTTON_SYNTH_TOGGLE && g_auto_synthesis_enabled) active = 1;
    if (id == OVERLAY_BUTTON_SYNTH_STORAGE && g_auto_synthesis_use_storage) active = 1;
    if (id == OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE &&
        g_item_lock_condition_high_grade) active = 1;
    if (id == OVERLAY_BUTTON_ITEM_LOCK_COIN &&
        g_item_lock_condition_coin) active = 1;
    if (id == OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP &&
        g_item_lock_condition_market_top &&
        g_auto_item_lock_market_top_count > 0) active = 1;
    if (id == OVERLAY_BUTTON_ITEM_LOCK_MANUAL &&
        InterlockedCompareExchange(&g_manual_item_lock_pending, 0, 0)) {
        active = 1;
    }
    if (id == OVERLAY_BUTTON_ITEM_LOCK_LIST &&
        g_auto_item_lock_selected_count > 0) active = 1;
    if (id == OVERLAY_BUTTON_VIEW_EXPANDED &&
        g_overlay_view_mode == OVERLAY_VIEW_MODE_EXPANDED) active = 1;
    if (id == OVERLAY_BUTTON_VIEW_LOG_ONLY &&
        g_overlay_view_mode == OVERLAY_VIEW_MODE_LOG_ONLY) active = 1;
    if (id == OVERLAY_BUTTON_VIEW_MINIMIZED &&
        g_overlay_view_mode == OVERLAY_VIEW_MODE_MINIMIZED) active = 1;

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
    GetWindowTextW(item->hwndItem, text,
                   (int)(sizeof(text) / sizeof(text[0])));
    text[(sizeof(text) / sizeof(text[0])) - 1] = 0;

    SetBkMode(item->hDC, TRANSPARENT);
    SetTextColor(item->hDC, text_color);
    old_font = SelectObject(item->hDC,
                            active ? g_overlay_font_bold : g_overlay_font);
    DrawTextW(item->hDC, text, -1, &rc,
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

static void apply_overlay_window_region(HWND hwnd)
{
    HRGN region;

    if (!hwnd) return;
    region = CreateRoundRectRgn(0, 0, OVERLAY_WIDTH + 1,
                                overlay_current_height() + 1, 10, 10);
    if (region && !SetWindowRgn(hwnd, region, TRUE)) {
        DeleteObject(region);
    }
}

static int overlay_title_button_visible(int child_id)
{
    return child_id == OVERLAY_BUTTON_VIEW_EXPANDED ||
           child_id == OVERLAY_BUTTON_VIEW_LOG_ONLY ||
           child_id == OVERLAY_BUTTON_VIEW_MINIMIZED;
}

static BOOL CALLBACK update_overlay_child_visibility_proc(HWND child,
                                                          LPARAM lparam)
{
    int child_id;
    int visible;

    (void)lparam;
    child_id = GetDlgCtrlID(child);
    visible = overlay_title_button_visible(child_id) ||
              g_overlay_view_mode == OVERLAY_VIEW_MODE_EXPANDED;
    ShowWindow(child, visible ? SW_SHOW : SW_HIDE);
    return TRUE;
}

static void update_overlay_view_layout(HWND hwnd)
{
    if (!hwnd) return;
    EnumChildWindows(hwnd, update_overlay_child_visibility_proc, 0);
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0,
                 OVERLAY_WIDTH, overlay_current_height(),
                 SWP_NOMOVE | SWP_NOACTIVATE);
    apply_overlay_window_region(hwnd);
    InvalidateRect(hwnd, NULL, TRUE);
}

static const char *overlay_view_mode_name(int mode)
{
    if (mode == OVERLAY_VIEW_MODE_LOG_ONLY) return "log-only";
    if (mode == OVERLAY_VIEW_MODE_MINIMIZED) return "minimized";
    return "expanded";
}

static void set_overlay_view_mode(HWND hwnd, int mode)
{
    if (mode < OVERLAY_VIEW_MODE_EXPANDED ||
        mode > OVERLAY_VIEW_MODE_MINIMIZED) {
        return;
    }
    g_overlay_view_mode = mode;
    update_overlay_view_layout(hwnd);
    log_line("overlay view mode: %s", overlay_view_mode_name(mode));
}

static void apply_overlay_fonts(HWND hwnd)
{
    int ids[] = {
        OVERLAY_BUTTON_MIN,
        OVERLAY_BUTTON_VIEW_EXPANDED,
        OVERLAY_BUTTON_VIEW_LOG_ONLY,
        OVERLAY_BUTTON_VIEW_MINIMIZED,
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
        OVERLAY_BUTTON_SYNTH_TOGGLE,
        OVERLAY_BUTTON_SYNTH_STORAGE,
        OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE,
        OVERLAY_BUTTON_ITEM_LOCK_COIN,
        OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP,
        OVERLAY_BUTTON_ITEM_LOCK_MANUAL,
        OVERLAY_BUTTON_ITEM_LOCK_LIST,
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

static void position_overlay(HWND hwnd)
{
    HWND game = find_game_window();
    RECT rc;
    int x = g_overlay_x;
    int y = g_overlay_y;
    int height = overlay_current_height();
    if (g_overlay_user_moved || g_overlay_dragging) {
        SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, OVERLAY_WIDTH, height,
                     SWP_NOMOVE | SWP_NOACTIVATE | SWP_SHOWWINDOW);
        return;
    }
    if (game && GetWindowRect(game, &rc)) {
        x = rc.left + g_overlay_x;
        y = rc.top + g_overlay_y;
    }
    SetWindowPos(hwnd, HWND_TOPMOST, x, y, OVERLAY_WIDTH, height,
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

static int combo_current_item_data(HWND combo, int fallback)
{
    LRESULT sel;
    LRESULT data;

    if (!combo) return fallback;
    sel = SendMessageA(combo, CB_GETCURSEL, 0, 0);
    if (sel == CB_ERR) return fallback;
    data = SendMessageA(combo, CB_GETITEMDATA, (WPARAM)sel, 0);
    if (data == CB_ERR) return fallback;
    return (int)data;
}

static void set_window_text_utf8(HWND hwnd, const char *text)
{
    WCHAR wbuf[512];
    int written;

    if (!hwnd) return;
    if (!text) text = "";
    written = MultiByteToWideChar(CP_UTF8, 0, text, -1,
                                  wbuf, (int)(sizeof(wbuf) / sizeof(wbuf[0])));
    if (written > 0) {
        SetWindowTextW(hwnd, wbuf);
    } else {
        SetWindowTextA(hwnd, text);
    }
}

static LRESULT listbox_add_utf8(HWND listbox, const char *text)
{
    WCHAR wbuf[512];
    int written;

    if (!listbox) return LB_ERR;
    if (!text) text = "";
    written = MultiByteToWideChar(CP_UTF8, 0, text, -1,
                                  wbuf, (int)(sizeof(wbuf) / sizeof(wbuf[0])));
    if (written > 0) {
        return SendMessageW(listbox, LB_ADDSTRING, 0, (LPARAM)wbuf);
    }
    return SendMessageA(listbox, LB_ADDSTRING, 0, (LPARAM)text);
}

static WCHAR item_lock_ascii_upper_w(WCHAR ch)
{
    if (ch >= L'a' && ch <= L'z') return (WCHAR)(ch - (L'a' - L'A'));
    return ch;
}

static void item_lock_trim_wide(WCHAR *text)
{
    int start = 0;
    int end;
    int out = 0;

    if (!text) return;
    while (text[start] == L' ' || text[start] == L'\t') start++;
    end = lstrlenW(text);
    while (end > start &&
           (text[end - 1] == L' ' || text[end - 1] == L'\t')) {
        end--;
    }
    while (start < end) {
        text[out++] = text[start++];
    }
    text[out] = 0;
}

static int item_lock_wide_contains_i(const WCHAR *text, const WCHAR *needle)
{
    int i;
    int j;

    if (!needle || !needle[0]) return 1;
    if (!text) return 0;
    for (i = 0; text[i]; ++i) {
        for (j = 0; needle[j]; ++j) {
            if (!text[i + j]) return 0;
            if (item_lock_ascii_upper_w(text[i + j]) !=
                item_lock_ascii_upper_w(needle[j])) {
                break;
            }
        }
        if (!needle[j]) return 1;
    }
    return 0;
}

static int item_lock_catalog_matches_search(const AutoItemLockInfo *info)
{
    WCHAR query[96];
    WCHAR id_text[32];
    WCHAR label_text[512];
    char label[256];
    int written;

    if (!info) return 0;
    if (!g_item_lock_search_edit || !IsWindow(g_item_lock_search_edit)) return 1;
    query[0] = 0;
    GetWindowTextW(g_item_lock_search_edit,
                   query,
                   (int)(sizeof(query) / sizeof(query[0])));
    query[(sizeof(query) / sizeof(query[0])) - 1] = 0;
    item_lock_trim_wide(query);
    if (!query[0]) return 1;

    wsprintfW(id_text, L"%u", info->item_id);
    id_text[(sizeof(id_text) / sizeof(id_text[0])) - 1] = 0;
    if (item_lock_wide_contains_i(id_text, query)) return 1;

    auto_item_lock_format_item_label(info, label, sizeof(label));
    written = MultiByteToWideChar(CP_UTF8,
                                  0,
                                  label,
                                  -1,
                                  label_text,
                                  (int)(sizeof(label_text) /
                                        sizeof(label_text[0])));
    if (written <= 0) {
        written = MultiByteToWideChar(CP_ACP,
                                      0,
                                      label,
                                      -1,
                                      label_text,
                                      (int)(sizeof(label_text) /
                                            sizeof(label_text[0])));
    }
    if (written <= 0) return 0;
    label_text[(sizeof(label_text) / sizeof(label_text[0])) - 1] = 0;
    return item_lock_wide_contains_i(label_text, query);
}

static int item_lock_catalog_is_highest_rarity(const AutoItemLockInfo *info)
{
    if (!info) return 0;
    return info->grade == EGRADE_DIVINE || info->grade == EGRADE_COSMIC;
}

static const char *auto_item_lock_class_name(int equip_class)
{
    switch (equip_class) {
    case EEQUIP_CLASS_ALL: return "通用";
    case EEQUIP_CLASS_KNIGHT: return "骑士";
    case EEQUIP_CLASS_RANGER: return "游侠";
    case EEQUIP_CLASS_SORCERER: return "法师";
    case EEQUIP_CLASS_PRIEST: return "牧师";
    case EEQUIP_CLASS_HUNTER: return "猎人";
    case EEQUIP_CLASS_SLAYER: return "杀手";
    default: return "未知";
    }
}

static int auto_item_lock_catalog_class_from_gear_type(int gear_type)
{
    switch (gear_type) {
    case EGEAR_TYPE_SWORD:
    case EGEAR_TYPE_SHIELD:
        return EEQUIP_CLASS_KNIGHT;
    case EGEAR_TYPE_BOW:
    case EGEAR_TYPE_ARROW:
        return EEQUIP_CLASS_RANGER;
    case EGEAR_TYPE_STAFF:
    case EGEAR_TYPE_ORB:
        return EEQUIP_CLASS_SORCERER;
    case EGEAR_TYPE_SCEPTER:
    case EGEAR_TYPE_TOME:
        return EEQUIP_CLASS_PRIEST;
    case EGEAR_TYPE_CROSSBOW:
    case EGEAR_TYPE_BOLT:
        return EEQUIP_CLASS_HUNTER;
    case EGEAR_TYPE_AXE:
    case EGEAR_TYPE_HATCHET:
        return EEQUIP_CLASS_SLAYER;
    default:
        return EEQUIP_CLASS_ALL;
    }
}

static int item_lock_catalog_selectable(const AutoItemLockInfo *info)
{
    if (!info) return 0;
    if (info->item_type == EITEM_TYPE_MATERIAL) return 1;
    if (info->item_type == EITEM_TYPE_GEAR &&
        (info->grade == EGRADE_CELESTIAL ||
         item_lock_catalog_is_highest_rarity(info))) {
        return 1;
    }
    return 0;
}

static int item_lock_catalog_matches_filter(const AutoItemLockInfo *info,
                                            int type_filter,
                                            int grade_filter,
                                            int class_filter)
{
    if (!info) return 0;
    if (!item_lock_catalog_selectable(info)) return 0;
    if (type_filter == -2) {
        if (info->item_type == EITEM_TYPE_STAGEBOX ||
            info->item_type == EITEM_TYPE_MATERIAL ||
            info->item_type == EITEM_TYPE_GEAR) {
            return 0;
        }
    } else if (type_filter >= 0 && info->item_type != type_filter) {
        return 0;
    }
    if (grade_filter >= 0 && info->grade != grade_filter) return 0;
    if (class_filter >= 0 && info->item_type == EITEM_TYPE_GEAR) {
        if (info->equip_class != class_filter &&
            info->equip_class != EEQUIP_CLASS_ALL) {
            return 0;
        }
    }
    if (!item_lock_catalog_matches_search(info)) return 0;
    return 1;
}

static void populate_item_lock_listbox(void);
static void update_item_lock_list_status(void);

static int item_lock_temp_selected(unsigned int item_id)
{
    return auto_item_lock_id_index(g_auto_item_lock_temp_ids,
                                   g_auto_item_lock_temp_count,
                                   item_id) >= 0;
}

static void item_lock_invalidate_row(int row)
{
    RECT rc;

    if (!g_item_lock_listbox || row < 0) return;
    if (SendMessageA(g_item_lock_listbox, LB_GETITEMRECT,
                     (WPARAM)row, (LPARAM)&rc) != LB_ERR) {
        InvalidateRect(g_item_lock_listbox, &rc, TRUE);
    }
}

static void item_lock_toggle_catalog_index(int catalog_index)
{
    AutoItemLockInfo *info;
    int selected;

    if (catalog_index < 0 ||
        catalog_index >= g_auto_item_lock_catalog_count) {
        return;
    }
    info = &g_auto_item_lock_catalog[catalog_index];
    selected = item_lock_temp_selected(info->item_id) ? 0 : 1;
    auto_item_lock_set_id(g_auto_item_lock_temp_ids,
                          &g_auto_item_lock_temp_count,
                          info->item_id,
                          selected);
    update_item_lock_list_status();
}

static void item_lock_toggle_row(int row)
{
    LRESULT data;

    if (!g_item_lock_listbox || row < 0) return;
    data = SendMessageA(g_item_lock_listbox, LB_GETITEMDATA,
                        (WPARAM)row, 0);
    if (data == LB_ERR) return;
    item_lock_toggle_catalog_index((int)data);
    item_lock_invalidate_row(row);
}

static void clear_item_lock_temp_selection(void)
{
    g_auto_item_lock_temp_count = 0;
    update_item_lock_list_status();
}

static void sync_visible_item_lock_selection_to_temp(void)
{
    update_item_lock_list_status();
}

static LRESULT CALLBACK item_lock_listbox_proc(HWND hwnd,
                                               UINT msg,
                                               WPARAM wp,
                                               LPARAM lp)
{
    if (msg == WM_LBUTTONDOWN) {
        LRESULT hit = SendMessageA(hwnd, LB_ITEMFROMPOINT, 0, lp);
        int row = (short)LOWORD(hit);
        int outside = HIWORD(hit) ? 1 : 0;

        if (!outside && row >= 0) {
            SendMessageA(hwnd, LB_SETCURSEL, (WPARAM)row, 0);
            item_lock_toggle_row(row);
            return 0;
        }
    } else if (msg == WM_KEYDOWN && wp == VK_SPACE) {
        int row = (int)SendMessageA(hwnd, LB_GETCURSEL, 0, 0);
        if (row >= 0 && row != LB_ERR) {
            item_lock_toggle_row(row);
            return 0;
        }
    }

    if (g_item_lock_listbox_old_proc) {
        return CallWindowProcA(g_item_lock_listbox_old_proc,
                               hwnd, msg, wp, lp);
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

static void sanitize_item_lock_icon_component(const char *src,
                                              char *dst,
                                              int dst_size)
{
    int out = 0;
    int i;

    if (!dst || dst_size <= 0) return;
    for (i = 0; src && src[i] && out < dst_size - 1; ++i) {
        char c = src[i];
        if ((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9') ||
            c == '.' || c == '_' || c == '-') {
            dst[out++] = c;
        } else {
            dst[out++] = '_';
        }
    }
    if (!out) {
        lstrcpynA(dst, "Item_unknown", dst_size);
        return;
    }
    dst[out] = 0;
}

static HBITMAP load_item_lock_icon_bitmap_from_dir(const char *dir,
                                                   const char *filename)
{
    char path[MAX_PATH];

    if (!dir || !dir[0] || !filename || !filename[0]) return NULL;
    wsprintfA(path, "%s\\%s\\%s.bmp",
              dir, ITEM_LOCK_ICON_DIR_NAME, filename);
    path[sizeof(path) - 1] = 0;
    return (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, 0, 0,
                               LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

static HBITMAP load_item_lock_icon_bitmap(AutoItemLockInfo *info)
{
    char filename[192];
    HBITMAP bitmap;

    if (!info) return NULL;
    if (info->icon_bitmap_status > 0) return info->icon_bitmap;
    if (info->icon_bitmap_status < 0) return NULL;
    info->icon_bitmap_status = -1;
    if (!info->icon_path[0]) return NULL;

    sanitize_item_lock_icon_component(info->icon_path,
                                      filename,
                                      sizeof(filename));
    bitmap = load_item_lock_icon_bitmap_from_dir(g_base_dir, filename);
    if (!bitmap && g_game_dir[0] &&
        lstrcmpiA(g_game_dir, g_base_dir) != 0) {
        bitmap = load_item_lock_icon_bitmap_from_dir(g_game_dir, filename);
    }
    if (!bitmap) return NULL;

    info->icon_bitmap = bitmap;
    info->icon_bitmap_status = 1;
    return info->icon_bitmap;
}

static transparent_blt_t get_transparent_blt_proc(void)
{
    if (!g_transparent_blt_checked) {
        g_transparent_blt_checked = 1;
        g_msimg32 = LoadLibraryA("msimg32.dll");
        if (g_msimg32) {
            g_transparent_blt =
                (transparent_blt_t)GetProcAddress(g_msimg32,
                                                  "TransparentBlt");
        }
    }
    return g_transparent_blt;
}

static int draw_item_lock_icon_bitmap(HDC hdc,
                                      const RECT *icon,
                                      AutoItemLockInfo *info,
                                      int selected)
{
    HBITMAP bitmap;
    HDC mem_dc;
    HGDIOBJ old_bitmap;
    BITMAP bm;
    HBRUSH fill;
    transparent_blt_t transparent_blt;
    BOOL drawn = FALSE;

    if (!hdc || !icon || !info) return 0;
    bitmap = load_item_lock_icon_bitmap(info);
    if (!bitmap) return 0;
    if (!GetObjectA(bitmap, sizeof(bm), &bm) ||
        bm.bmWidth <= 0 || bm.bmHeight <= 0) {
        return 0;
    }

    fill = CreateSolidBrush(auto_item_lock_grade_color(info->grade));
    FillRect(hdc, icon, fill);
    DeleteObject(fill);

    mem_dc = CreateCompatibleDC(hdc);
    if (!mem_dc) return 0;
    old_bitmap = SelectObject(mem_dc, bitmap);
    SetStretchBltMode(hdc, COLORONCOLOR);

    transparent_blt = get_transparent_blt_proc();
    if (transparent_blt) {
        drawn = transparent_blt(hdc,
                                icon->left,
                                icon->top,
                                icon->right - icon->left,
                                icon->bottom - icon->top,
                                mem_dc,
                                0,
                                0,
                                bm.bmWidth,
                                bm.bmHeight,
                                ITEM_LOCK_ICON_TRANSPARENT_KEY);
    }
    if (!drawn) {
        drawn = StretchBlt(hdc,
                           icon->left,
                           icon->top,
                           icon->right - icon->left,
                           icon->bottom - icon->top,
                           mem_dc,
                           0,
                           0,
                           bm.bmWidth,
                           bm.bmHeight,
                           SRCCOPY);
    }

    SelectObject(mem_dc, old_bitmap);
    DeleteDC(mem_dc);
    FrameRect(hdc, icon,
              selected ? g_overlay_accent_brush : g_overlay_border_brush);
    return drawn ? 1 : 0;
}

static void draw_item_lock_icon_cue(HDC hdc,
                                    const RECT *icon,
                                    const AutoItemLockInfo *info,
                                    int selected)
{
    HBRUSH fill;
    char cue[4];
    COLORREF grade_color;
    COLORREF text_color;
    RECT text_rc;

    if (!hdc || !icon || !info) return;
    grade_color = auto_item_lock_grade_color(info->grade);
    fill = CreateSolidBrush(grade_color);
    FillRect(hdc, icon, fill);
    DeleteObject(fill);
    FrameRect(hdc, icon,
              selected ? g_overlay_accent_brush : g_overlay_border_brush);

    auto_item_lock_icon_cue_text(info, cue, sizeof(cue));
    text_rc = *icon;
    SetBkMode(hdc, TRANSPARENT);
    text_color = selected ? RGB(18, 16, 12) : RGB(28, 24, 20);
    SetTextColor(hdc, text_color);
    DrawTextA(hdc, cue, -1, &text_rc,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

static void draw_item_lock_checkbox_row(const DRAWITEMSTRUCT *draw)
{
    RECT rc;
    RECT check;
    RECT icon;
    RECT text_rc;
    AutoItemLockInfo *info;
    char label[256];
    WCHAR wlabel[256];
    int catalog_index;
    int checked;
    HBRUSH fill;
    HPEN pen;
    HGDIOBJ old_pen;
    HGDIOBJ old_font;

    if (!draw || draw->itemID == (UINT)-1) return;
    if (draw->CtlID != ITEM_LOCK_LIST_CONTROL_LIST) return;
    if ((int)draw->itemData < 0 ||
        (int)draw->itemData >= g_auto_item_lock_catalog_count) {
        return;
    }

    init_overlay_style();
    rc = draw->rcItem;
    catalog_index = (int)draw->itemData;
    info = &g_auto_item_lock_catalog[catalog_index];
    checked = item_lock_temp_selected(info->item_id);
    fill = (draw->itemState & ODS_SELECTED) ?
           g_overlay_button_hot_brush : g_overlay_panel_brush;
    FillRect(draw->hDC, &rc, fill);

    check.left = rc.left + 8;
    check.top = rc.top + ((rc.bottom - rc.top) - 16) / 2;
    check.right = check.left + 16;
    check.bottom = check.top + 16;
    FillRect(draw->hDC, &check, g_overlay_panel_2_brush);
    FrameRect(draw->hDC, &check,
              checked ? g_overlay_accent_brush : g_overlay_border_brush);
    if (checked) {
        pen = CreatePen(PS_SOLID, 2, OVERLAY_COLOR_ACCENT);
        old_pen = SelectObject(draw->hDC, pen);
        MoveToEx(draw->hDC, check.left + 3, check.top + 8, NULL);
        LineTo(draw->hDC, check.left + 7, check.bottom - 4);
        LineTo(draw->hDC, check.right - 3, check.top + 4);
        SelectObject(draw->hDC, old_pen);
        DeleteObject(pen);
    }

    icon.left = check.right + 8;
    icon.top = rc.top + ((rc.bottom - rc.top) - ITEM_LOCK_LIST_ICON_SIZE) / 2;
    icon.right = icon.left + ITEM_LOCK_LIST_ICON_SIZE;
    icon.bottom = icon.top + ITEM_LOCK_LIST_ICON_SIZE;
    if (!draw_item_lock_icon_bitmap(draw->hDC, &icon, info, checked)) {
        draw_item_lock_icon_cue(draw->hDC, &icon, info, checked);
    }

    auto_item_lock_format_item_label(info, label, sizeof(label));
    wlabel[0] = 0;
    if (MultiByteToWideChar(CP_UTF8, 0, label, -1,
                            wlabel,
                            (int)(sizeof(wlabel) / sizeof(wlabel[0]))) <= 0) {
        MultiByteToWideChar(CP_ACP, 0, label, -1,
                            wlabel,
                            (int)(sizeof(wlabel) / sizeof(wlabel[0])));
    }
    wlabel[(sizeof(wlabel) / sizeof(wlabel[0])) - 1] = 0;

    text_rc = rc;
    text_rc.left = icon.right + 10;
    text_rc.right -= 6;
    SetBkMode(draw->hDC, TRANSPARENT);
    SetTextColor(draw->hDC,
                 checked ? RGB(246, 237, 190) : OVERLAY_COLOR_TEXT);
    old_font = SelectObject(draw->hDC,
                            checked ? g_overlay_font_bold : g_overlay_font);
    DrawTextW(draw->hDC, wlabel, -1, &text_rc,
              DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    SelectObject(draw->hDC, old_font);

    if (draw->itemState & ODS_FOCUS) {
        DrawFocusRect(draw->hDC, &rc);
    }
}

static void update_item_lock_list_status(void)
{
    char text[160];

    if (!g_item_lock_status_label) return;
    if (g_auto_item_lock_catalog_count <= 0) {
        wsprintfA(text, "items:loading selected:%d", g_auto_item_lock_temp_count);
    } else {
        wsprintfA(text, "items:%d selected:%d",
                  g_auto_item_lock_catalog_count,
                  g_auto_item_lock_temp_count);
    }
    text[sizeof(text) - 1] = 0;
    set_window_text_utf8(g_item_lock_status_label, text);
}

static int item_lock_filter_dropdown_open(void)
{
    if (g_item_lock_type_combo && IsWindow(g_item_lock_type_combo) &&
        SendMessageA(g_item_lock_type_combo, CB_GETDROPPEDSTATE, 0, 0)) {
        return 1;
    }
    if (g_item_lock_grade_combo && IsWindow(g_item_lock_grade_combo) &&
        SendMessageA(g_item_lock_grade_combo, CB_GETDROPPEDSTATE, 0, 0)) {
        return 1;
    }
    if (g_item_lock_class_combo && IsWindow(g_item_lock_class_combo) &&
        SendMessageA(g_item_lock_class_combo, CB_GETDROPPEDSTATE, 0, 0)) {
        return 1;
    }
    return 0;
}

static void update_item_lock_class_filter_visibility(void)
{
    int type_filter;
    int show_class;

    if (!g_item_lock_class_combo) return;
    type_filter = combo_current_item_data(g_item_lock_type_combo, -1);
    show_class = type_filter == EITEM_TYPE_GEAR ? 1 : 0;
    ShowWindow(g_item_lock_class_combo, show_class ? SW_SHOW : SW_HIDE);
    EnableWindow(g_item_lock_class_combo, show_class);
    if (g_item_lock_class_label) {
        ShowWindow(g_item_lock_class_label, show_class ? SW_SHOW : SW_HIDE);
    }
    if (!show_class) {
        SendMessageA(g_item_lock_class_combo, CB_SETCURSEL, 0, 0);
    }
}

static void refresh_item_lock_list_if_catalog_changed(HWND hwnd)
{
    LONG version;

    if (item_lock_filter_dropdown_open()) return;
    version = InterlockedCompareExchange(&g_auto_item_lock_catalog_version, 0, 0);
    if (version != g_item_lock_list_catalog_version_seen) {
        sync_visible_item_lock_selection_to_temp();
        g_item_lock_list_catalog_version_seen = version;
        populate_item_lock_listbox();
    } else {
        update_item_lock_list_status();
    }
    if (g_auto_item_lock_catalog_count > 0) {
        KillTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH);
    }
}

static void populate_item_lock_listbox(void)
{
    int type_filter;
    int grade_filter;
    int class_filter;
    int i;

    if (!g_item_lock_listbox) return;
    type_filter = combo_current_item_data(g_item_lock_type_combo, -1);
    grade_filter = combo_current_item_data(g_item_lock_grade_combo, -1);
    update_item_lock_class_filter_visibility();
    class_filter = combo_current_item_data(g_item_lock_class_combo, -1);

    SendMessageA(g_item_lock_listbox, WM_SETREDRAW, FALSE, 0);
    SendMessageA(g_item_lock_listbox, LB_RESETCONTENT, 0, 0);
    for (i = 0; i < g_auto_item_lock_catalog_count; ++i) {
        char label[256];
        LRESULT row;
        AutoItemLockInfo *info = &g_auto_item_lock_catalog[i];

        if (!item_lock_catalog_matches_filter(info,
                                              type_filter,
                                              grade_filter,
                                              class_filter)) {
            continue;
        }
        auto_item_lock_format_item_label(info, label, sizeof(label));
        row = listbox_add_utf8(g_item_lock_listbox, label);
        if (row != LB_ERR) {
            SendMessageA(g_item_lock_listbox, LB_SETITEMDATA,
                         (WPARAM)row, (LPARAM)i);
        }
    }
    if (SendMessageA(g_item_lock_listbox, LB_GETCOUNT, 0, 0) > 0) {
        SendMessageA(g_item_lock_listbox, LB_SETCURSEL, 0, 0);
    }
    SendMessageA(g_item_lock_listbox, WM_SETREDRAW, TRUE, 0);
    InvalidateRect(g_item_lock_listbox, NULL, TRUE);
    update_item_lock_list_status();
}

static int item_lock_combo_add_utf8(HWND combo, const char *label, int data)
{
    WCHAR wbuf[128];
    LRESULT index;
    int written;

    if (!combo) return -1;
    if (!label) label = "";
    written = MultiByteToWideChar(CP_UTF8, 0, label, -1,
                                  wbuf, (int)(sizeof(wbuf) / sizeof(wbuf[0])));
    if (written > 0) {
        index = SendMessageW(combo, CB_ADDSTRING, 0, (LPARAM)wbuf);
    } else {
        index = SendMessageA(combo, CB_ADDSTRING, 0, (LPARAM)label);
    }
    if (index == CB_ERR || index == CB_ERRSPACE) return -1;
    SendMessageA(combo, CB_SETITEMDATA, (WPARAM)index, (LPARAM)data);
    return (int)index;
}

static void init_item_lock_filter_combo(HWND combo, int is_type)
{
    int i;

    if (!combo) return;
    SendMessageA(combo, CB_RESETCONTENT, 0, 0);
    item_lock_combo_add_utf8(combo, "all", -1);
    if (is_type == 1) {
        item_lock_combo_add_utf8(combo, "material", EITEM_TYPE_MATERIAL);
        item_lock_combo_add_utf8(combo, "gear", EITEM_TYPE_GEAR);
        item_lock_combo_add_utf8(combo, "other", -2);
    } else if (is_type == 2) {
        item_lock_combo_add_utf8(combo, "common", EEQUIP_CLASS_ALL);
        item_lock_combo_add_utf8(combo, "knight", EEQUIP_CLASS_KNIGHT);
        item_lock_combo_add_utf8(combo, "ranger", EEQUIP_CLASS_RANGER);
        item_lock_combo_add_utf8(combo, "sorcerer", EEQUIP_CLASS_SORCERER);
        item_lock_combo_add_utf8(combo, "priest", EEQUIP_CLASS_PRIEST);
        item_lock_combo_add_utf8(combo, "hunter", EEQUIP_CLASS_HUNTER);
        item_lock_combo_add_utf8(combo, "slayer", EEQUIP_CLASS_SLAYER);
    } else {
        for (i = 0; i <= EGRADE_NONE; ++i) {
            char label[32];
            wsprintfA(label, "g%d %s", i, auto_item_lock_grade_name(i));
            label[sizeof(label) - 1] = 0;
            item_lock_combo_add_utf8(combo, label, i);
        }
    }
    SendMessageA(combo, CB_SETCURSEL, 0, 0);
}

static void commit_item_lock_temp_selection(void)
{
    int bytes = g_auto_item_lock_temp_count * (int)sizeof(unsigned int);

    if (g_auto_item_lock_temp_count < 0) g_auto_item_lock_temp_count = 0;
    if (g_auto_item_lock_temp_count > AUTO_ITEM_LOCK_MAX_SELECTED) {
        g_auto_item_lock_temp_count = AUTO_ITEM_LOCK_MAX_SELECTED;
    }
    if (bytes > 0) {
        mem_copy_local(g_auto_item_lock_selected_ids,
                       g_auto_item_lock_temp_ids,
                       (SIZE_T)bytes);
    }
    g_auto_item_lock_selected_count = g_auto_item_lock_temp_count;
    save_config();
    update_item_lock_list_button();
    log_line("auto item lock selection saved: ids=%d",
             g_auto_item_lock_selected_count);
    append_overlay_event("LOCK LIST saved %d",
                         g_auto_item_lock_selected_count);
}

static LRESULT CALLBACK item_lock_list_wnd_proc(HWND hwnd,
                                                UINT msg,
                                                WPARAM wp,
                                                LPARAM lp)
{
    switch (msg) {
    case WM_CREATE: {
        int bytes;

        init_overlay_style();
        g_auto_item_lock_temp_count = g_auto_item_lock_selected_count;
        bytes = g_auto_item_lock_temp_count * (int)sizeof(unsigned int);
        if (bytes > 0) {
            mem_copy_local(g_auto_item_lock_temp_ids,
                           g_auto_item_lock_selected_ids,
                           (SIZE_T)bytes);
        }

        CreateWindowExA(0, "STATIC", "type",
                        WS_CHILD | WS_VISIBLE | SS_LEFT,
                        14, 14, 48, 22, hwnd, NULL, g_self_module, NULL);
        g_item_lock_type_combo = CreateWindowExA(
                        0, "COMBOBOX", "",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
                        CBS_DROPDOWNLIST | WS_VSCROLL,
                        62, 10, 150, 220, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_TYPE,
                        g_self_module, NULL);
        CreateWindowExA(0, "STATIC", "grade",
                        WS_CHILD | WS_VISIBLE | SS_LEFT,
                        226, 14, 52, 22, hwnd, NULL, g_self_module, NULL);
        g_item_lock_grade_combo = CreateWindowExA(
                        0, "COMBOBOX", "",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
                        CBS_DROPDOWNLIST | WS_VSCROLL,
                        282, 10, 150, 260, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_GRADE,
                        g_self_module, NULL);
        g_item_lock_class_label = CreateWindowExA(0, "STATIC", "class",
                        WS_CHILD | WS_VISIBLE | SS_LEFT,
                        446, 14, 48, 22, hwnd, NULL, g_self_module, NULL);
        g_item_lock_class_combo = CreateWindowExA(
                        0, "COMBOBOX", "",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP |
                        CBS_DROPDOWNLIST | WS_VSCROLL,
                        496, 10, 120, 220, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_CLASS,
                        g_self_module, NULL);
        CreateWindowExA(0, "STATIC", "filter",
                        WS_CHILD | WS_VISIBLE | SS_LEFT,
                        630, 14, 46, 22, hwnd, NULL, g_self_module, NULL);
        g_item_lock_search_edit = CreateWindowExA(
                        WS_EX_CLIENTEDGE, "EDIT", "",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL,
                        676, 10, 128, 24, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_SEARCH,
                        g_self_module, NULL);
        g_item_lock_listbox = CreateWindowExA(
                        WS_EX_CLIENTEDGE, "LISTBOX", "",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL |
                        LBS_NOTIFY | LBS_OWNERDRAWFIXED |
                        LBS_HASSTRINGS | LBS_NOINTEGRALHEIGHT,
                        14, 44, 790, 320, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_LIST,
                        g_self_module, NULL);
        g_item_lock_status_label = CreateWindowExA(
                        0, "STATIC", "",
                        WS_CHILD | WS_VISIBLE | SS_LEFT,
                        14, 374, 360, 26, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_STATUS,
                        g_self_module, NULL);
        CreateWindowExW(0, L"BUTTON", L"\x786E\x5B9A",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                        604, 374, 92, 30, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_OK,
                        g_self_module, NULL);
        CreateWindowExW(0, L"BUTTON", L"\x6E05\x7A7A",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                        496, 374, 92, 30, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_CLEAR,
                        g_self_module, NULL);
        CreateWindowExW(0, L"BUTTON", L"\x53D6\x6D88",
                        WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
                        712, 374, 92, 30, hwnd,
                        (HMENU)(uintptr_t)ITEM_LOCK_LIST_CONTROL_CANCEL,
                        g_self_module, NULL);

        SendMessageA(g_item_lock_type_combo, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        SendMessageA(g_item_lock_grade_combo, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        SendMessageA(g_item_lock_class_combo, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        SendMessageA(g_item_lock_search_edit, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        SendMessageA(g_item_lock_listbox, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        SendMessageA(g_item_lock_listbox, LB_SETITEMHEIGHT, 0,
                     ITEM_LOCK_LIST_ROW_HEIGHT);
        g_item_lock_listbox_old_proc =
            (WNDPROC)SetWindowLongPtrA(g_item_lock_listbox, GWLP_WNDPROC,
                                       (LONG_PTR)item_lock_listbox_proc);
        SendMessageA(g_item_lock_status_label, WM_SETFONT,
                     (WPARAM)g_overlay_font, TRUE);
        if (g_item_lock_class_label) {
            SendMessageA(g_item_lock_class_label, WM_SETFONT,
                         (WPARAM)g_overlay_font, TRUE);
        }

        init_item_lock_filter_combo(g_item_lock_type_combo, 1);
        init_item_lock_filter_combo(g_item_lock_grade_combo, 0);
        init_item_lock_filter_combo(g_item_lock_class_combo, 2);
        update_item_lock_class_filter_visibility();
        g_item_lock_list_catalog_version_seen =
            InterlockedCompareExchange(&g_auto_item_lock_catalog_version, 0, 0);
        populate_item_lock_listbox();
        if (g_auto_item_lock_catalog_count <= 0) {
            SetTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH, 500, NULL);
        }
        return 0;
    }
    case WM_TIMER:
        if (wp == ITEM_LOCK_LIST_TIMER_REFRESH) {
            refresh_item_lock_list_if_catalog_changed(hwnd);
            return 0;
        }
        break;
    case WM_MEASUREITEM:
        if (((MEASUREITEMSTRUCT *)lp)->CtlID == ITEM_LOCK_LIST_CONTROL_LIST) {
            ((MEASUREITEMSTRUCT *)lp)->itemHeight = ITEM_LOCK_LIST_ROW_HEIGHT;
            return TRUE;
        }
        break;
    case WM_DRAWITEM:
        if (((DRAWITEMSTRUCT *)lp)->CtlID == ITEM_LOCK_LIST_CONTROL_LIST) {
            draw_item_lock_checkbox_row((const DRAWITEMSTRUCT *)lp);
            return TRUE;
        }
        break;
    case WM_COMMAND:
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_TYPE ||
            LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_GRADE ||
            LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_CLASS) {
            if (HIWORD(wp) == CBN_DROPDOWN) {
                KillTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH);
                return 0;
            }
            if (HIWORD(wp) == CBN_CLOSEUP) {
                if (g_auto_item_lock_catalog_count <= 0) {
                    SetTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH, 500, NULL);
                }
                return 0;
            }
            if (HIWORD(wp) == CBN_SELCHANGE) {
                sync_visible_item_lock_selection_to_temp();
                populate_item_lock_listbox();
                return 0;
            }
        }
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_LIST) {
            if (HIWORD(wp) == LBN_SELCHANGE) {
                sync_visible_item_lock_selection_to_temp();
                update_item_lock_list_status();
                return 0;
            }
        }
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_SEARCH) {
            if (HIWORD(wp) == EN_CHANGE) {
                sync_visible_item_lock_selection_to_temp();
                populate_item_lock_listbox();
                return 0;
            }
        }
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_OK) {
            sync_visible_item_lock_selection_to_temp();
            commit_item_lock_temp_selection();
            DestroyWindow(hwnd);
            return 0;
        }
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_CLEAR) {
            clear_item_lock_temp_selection();
            populate_item_lock_listbox();
            append_overlay_event("LOCK LIST clear");
            return 0;
        }
        if (LOWORD(wp) == ITEM_LOCK_LIST_CONTROL_CANCEL) {
            DestroyWindow(hwnd);
            return 0;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    case WM_DESTROY:
        KillTimer(hwnd, ITEM_LOCK_LIST_TIMER_REFRESH);
        g_item_lock_list_catalog_version_seen = 0;
        if (g_item_lock_list_hwnd == hwnd) {
            if (g_item_lock_listbox && g_item_lock_listbox_old_proc) {
                SetWindowLongPtrA(g_item_lock_listbox, GWLP_WNDPROC,
                                  (LONG_PTR)g_item_lock_listbox_old_proc);
            }
            g_item_lock_list_hwnd = NULL;
            g_item_lock_type_combo = NULL;
            g_item_lock_grade_combo = NULL;
            g_item_lock_class_label = NULL;
            g_item_lock_class_combo = NULL;
            g_item_lock_search_edit = NULL;
            g_item_lock_listbox = NULL;
            g_item_lock_status_label = NULL;
            g_item_lock_listbox_old_proc = NULL;
        }
        return 0;
    default:
        break;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}

static void open_item_lock_list_window(void)
{
    WNDCLASSA wc;
    char class_name[96];
    unsigned char *wc_bytes = (unsigned char *)&wc;
    int x = g_overlay_x + 80;
    int y = g_overlay_y + 80;

    if (g_item_lock_list_hwnd && IsWindow(g_item_lock_list_hwnd)) {
        ShowWindow(g_item_lock_list_hwnd, SW_SHOWNORMAL);
        SetForegroundWindow(g_item_lock_list_hwnd);
        return;
    }

    for (SIZE_T i = 0; i < sizeof(wc); ++i) wc_bytes[i] = 0;
    wsprintfA(class_name, "%s%p", ITEM_LOCK_LIST_CLASS_PREFIX, g_self_module);
    wc.lpfnWndProc = item_lock_list_wnd_proc;
    wc.hInstance = g_self_module;
    wc.lpszClassName = class_name;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursorA(NULL, IDC_ARROW);
    RegisterClassA(&wc);

    if (g_overlay_hwnd) {
        RECT rc;
        if (GetWindowRect(g_overlay_hwnd, &rc)) {
            x = rc.left + 28;
            y = rc.top + 28;
        }
    }

    g_item_lock_list_hwnd = CreateWindowExA(
        WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
        class_name,
        "Item Lock List",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
        x, y, 830, 455,
        g_overlay_hwnd, NULL, g_self_module, NULL);
    if (!g_item_lock_list_hwnd) {
        log_line("CreateWindowEx item lock list failed, error=%lu",
                 GetLastError());
        return;
    }
    SetWindowTextW(g_item_lock_list_hwnd, L"\x9501\x5B9A\x6E05\x5355");
    ShowWindow(g_item_lock_list_hwnd, SW_SHOWNORMAL);
    UpdateWindow(g_item_lock_list_hwnd);
}

static LRESULT CALLBACK overlay_wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg) {
    case WM_CREATE:
        apply_overlay_window_region(hwnd);
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
        g_overlay_synth_button = create_overlay_button(hwnd, "synth:off",
                        76, 144, 102, 26, OVERLAY_BUTTON_SYNTH_TOGGLE);
        g_overlay_synth_storage_button = create_overlay_button(hwnd, "store:on",
                        184, 144, 102, 26, OVERLAY_BUTTON_SYNTH_STORAGE);
        g_overlay_item_lock_high_grade_button = create_overlay_button(hwnd, "",
                        76, 180, 132, 26,
                        OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE);
        g_overlay_item_lock_coin_button = create_overlay_button(hwnd, "",
                        214, 180, 66, 26,
                        OVERLAY_BUTTON_ITEM_LOCK_COIN);
        g_overlay_item_lock_market_top_button = create_overlay_button(hwnd, "",
                        286, 180, 124, 26,
                        OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP);
        g_overlay_item_lock_list_button = create_overlay_button(hwnd, "",
                        416, 180, 116, 26,
                        OVERLAY_BUTTON_ITEM_LOCK_LIST);
        g_overlay_item_lock_manual_button = create_overlay_button(hwnd, "",
                        538, 180, 126, 26,
                        OVERLAY_BUTTON_ITEM_LOCK_MANUAL);
        create_overlay_button(hwnd, "-30s", 76, 216, 42, 26,
                              OVERLAY_BUTTON_LOCK_MINUS30);
        create_overlay_button(hwnd, "-10s", 122, 216, 42, 26,
                              OVERLAY_BUTTON_LOCK_MINUS10);
        g_overlay_lock_interval_label = CreateWindowExA(
                        0, "STATIC", "60s(--s)",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_CENTER | SS_CENTERIMAGE,
                        168, 216, 82, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_LOCK_INTERVAL,
                        g_self_module, NULL);
        create_overlay_button(hwnd, "+10s", 254, 216, 42, 26,
                              OVERLAY_BUTTON_LOCK_PLUS10);
        create_overlay_button(hwnd, "+30s", 300, 216, 42, 26,
                              OVERLAY_BUTTON_LOCK_PLUS30);
        g_overlay_lock_button = create_overlay_button(hwnd, "lock",
                        346, 216, 80, 26, OVERLAY_BUTTON_LOCK_STAGE);
        g_overlay_lock_stage_label = CreateWindowExA(
                        0, "STATIC", "--",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_LEFT | SS_CENTERIMAGE,
                        434, 216, 90, 26, hwnd,
                        (HMENU)(uintptr_t)OVERLAY_LABEL_LOCK_STAGE,
                        g_self_module, NULL);
        g_overlay_chest_intervals_label = CreateWindowExA(
                        0, "STATIC", "N count 0 last -- best --/-- next --\r\nB count 0 last -- best --/-- next --",
                        WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |
                        SS_LEFT,
                        76, 254, 590, 44,
                        hwnd, (HMENU)(uintptr_t)OVERLAY_LABEL_CHEST_INTERVALS,
                        g_self_module, NULL);
        apply_overlay_fonts(hwnd);
        update_overlay_label();
        update_exp_multiplier_labels();
        update_boss_button();
        update_actboss_button();
        update_auto_switch_button();
        update_auto_synthesis_buttons();
        update_item_lock_list_button();
        update_item_lock_condition_buttons();
        update_lock_button(hwnd);
        update_lock_stage_label();
        update_lock_interval_label();
        update_chest_interval_label();
        update_overlay_view_layout(hwnd);
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
        POINT pt;

        if (hit != HTCLIENT) return hit;
        pt.x = (short)LOWORD(lp);
        pt.y = (short)HIWORD(lp);
        ScreenToClient(hwnd, &pt);
        if (overlay_view_button_hit_test(pt)) return HTCLIENT;
        if (overlay_drop_log_filter_hit_test(pt)) return HTCLIENT;
        return HTCAPTION;
    }
    case WM_LBUTTONDOWN: {
        POINT pt;
        int button_id;

        pt.x = (short)LOWORD(lp);
        pt.y = (short)HIWORD(lp);
        button_id = overlay_view_button_hit_test(pt);
        if (!button_id) {
            int filter_id = overlay_drop_log_filter_hit_test(pt);
            if (filter_id) {
                toggle_drop_log_filter(filter_id);
                return 0;
            }
        }
        if (button_id == OVERLAY_BUTTON_VIEW_EXPANDED) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_EXPANDED);
            return 0;
        }
        if (button_id == OVERLAY_BUTTON_VIEW_LOG_ONLY) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_LOG_ONLY);
            return 0;
        }
        if (button_id == OVERLAY_BUTTON_VIEW_MINIMIZED) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_MINIMIZED);
            return 0;
        }
        break;
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
        if (!item_lock_filter_dropdown_open()) {
            position_overlay(hwnd);
        }
        update_lock_button(hwnd);
        update_lock_stage_label();
        update_lock_interval_label();
        update_auto_switch_button();
        update_auto_synthesis_buttons();
        update_item_lock_list_button();
        update_item_lock_condition_buttons();
        update_exp_multiplier_labels();
        update_chest_interval_label();
        return 0;
    case WM_MOUSEWHEEL: {
        POINT pt;
        int delta = (short)HIWORD(wp);
        int steps;

        pt.x = (short)LOWORD(lp);
        pt.y = (short)HIWORD(lp);
        ScreenToClient(hwnd, &pt);
        if (!point_in_drop_log_box(pt)) break;
        steps = delta / WHEEL_DELTA;
        if (!steps) steps = delta > 0 ? 1 : -1;
        adjust_drop_log_scroll(steps);
        return 0;
    }
    case WM_COMMAND:
        if (LOWORD(wp) == OVERLAY_BUTTON_VIEW_EXPANDED) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_EXPANDED);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_VIEW_LOG_ONLY) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_LOG_ONLY);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_VIEW_MINIMIZED) {
            set_overlay_view_mode(hwnd, OVERLAY_VIEW_MODE_MINIMIZED);
            return 0;
        }
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
        if (LOWORD(wp) == OVERLAY_BUTTON_SYNTH_TOGGLE) {
            set_auto_synthesis_enabled(!g_auto_synthesis_enabled);
            update_auto_synthesis_buttons();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_SYNTH_STORAGE) {
            set_auto_synthesis_use_storage(!g_auto_synthesis_use_storage);
            update_auto_synthesis_buttons();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ITEM_LOCK_HIGH_GRADE) {
            set_item_lock_condition_high_grade(!g_item_lock_condition_high_grade);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ITEM_LOCK_COIN) {
            set_item_lock_condition_coin(!g_item_lock_condition_coin);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ITEM_LOCK_MARKET_TOP) {
            set_item_lock_condition_market_top(!g_item_lock_condition_market_top);
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ITEM_LOCK_LIST) {
            open_item_lock_list_window();
            update_item_lock_list_button();
            return 0;
        }
        if (LOWORD(wp) == OVERLAY_BUTTON_ITEM_LOCK_MANUAL) {
            queue_manual_item_lock_request();
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
        g_overlay_synth_button = NULL;
        g_overlay_synth_storage_button = NULL;
        g_overlay_item_lock_high_grade_button = NULL;
        g_overlay_item_lock_coin_button = NULL;
        g_overlay_item_lock_market_top_button = NULL;
        g_overlay_item_lock_manual_button = NULL;
        g_overlay_item_lock_list_button = NULL;
        g_overlay_lock_button = NULL;
        g_overlay_lock_interval_label = NULL;
        g_overlay_lock_stage_label = NULL;
        g_overlay_chest_intervals_label = NULL;
        if (g_item_lock_list_hwnd && IsWindow(g_item_lock_list_hwnd)) {
            DestroyWindow(g_item_lock_list_hwnd);
        }
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
    ensure_auto_item_lock_localized_names_loaded();
    load_auto_item_lock_market_top_ids();
    load_item_market_prices();
    load_item_log_history();
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
    InterlockedExchange(&g_auto_item_lock_catalog_preload_pending, 1);

    for (int i = 0; i < 240; i++) {
        if (resolve_unity_time_calls(game_assembly)) break;
        Sleep(500);
    }

    if (!g_real_get_delta_time || !g_real_set_time_scale) {
        log_line("failed to resolve Unity Time icalls");
        return 0;
    }

    if (!install_unity_time_hooks(game_assembly)) {
        log_line("failed to install hooks");
        return 0;
    }
    restore_legacy_bad_stage_manager_enter_hook(game_assembly);
    if (!install_stagecache_jgm_hook(game_assembly)) {
        log_line("actboss boss hook not installed");
    }
    if (!install_ui_cube_hooks(game_assembly)) {
        log_line("UI_Cube hooks not fully installed");
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
    if (!install_cube_synthesis_core_hook(game_assembly)) {
        restore_cube_synthesis_core_hook(game_assembly);
        log_line("cube synthesis core hook not installed");
    }
    if (!install_open_box_stats_hook(game_assembly)) {
        log_line("open box stats hook not installed");
    }
    if (!install_stage_box_auto_open_hooks(game_assembly)) {
        log_line("stage box auto-open hooks not fully installed");
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
        if (!g_reward_trace_hooks_enabled) log_line("reward trace hooks disabled");
        if (g_force_box_reward_select_enabled) log_line("force box reward select enabled");
        if (g_keep_boxdata_after_select_enabled) log_line("keep boxdata after select enabled");
        install_drop_roll_process_hook(game_assembly);
    } else {
        restore_drop_related_patches(game_assembly);
        log_line("drop hooks disabled");
    }
    update_box_reward_select_hook(game_assembly);

    InterlockedExchange(&g_initialized, 1);

    if (g_overlay_enabled) {
        HANDLE overlay = CreateThread(NULL, 0, overlay_thread, NULL, 0, NULL);
        if (overlay) CloseHandle(overlay);
    }

    while (1) {
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
    } else if (reason == DLL_PROCESS_DETACH) {
        release_auto_item_lock_icon_bitmaps();
        destroy_overlay_style();
    }
    return TRUE;
}

BOOL WINAPI DllMainCRTStartup(HINSTANCE hinst, DWORD reason, LPVOID reserved)
{
    return DllMain(hinst, reason, reserved);
}
