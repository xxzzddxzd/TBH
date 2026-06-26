#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <stdarg.h>

#define TARGET_PROCESS "TaskBarHero.exe"
#define TARGET_DLL "TaskBarHeroSpeed.dll"
#ifndef PROCESS_QUERY_LIMITED_INFORMATION
#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000
#endif

static char g_base_dir[MAX_PATH];
static char g_log_path[MAX_PATH];

static char *find_last_char(char *s, char a, char b)
{
    char *last = NULL;
    for (; *s; s++) {
        if (*s == a || *s == b) last = s;
    }
    return last;
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

    OutputDebugStringA("[TaskBarHeroSpeedInject] ");
    OutputDebugStringA(line);
    OutputDebugStringA("\n");

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    if (out && out != INVALID_HANDLE_VALUE) {
        DWORD written = 0;
        wsprintfA(final_line, "%s\r\n", line);
        WriteFile(out, final_line, (DWORD)lstrlenA(final_line), &written, NULL);
    }

    if (g_log_path[0]) {
        HANDLE file = CreateFileA(g_log_path, FILE_APPEND_DATA, FILE_SHARE_READ,
                                  NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (file != INVALID_HANDLE_VALUE) {
            DWORD written = 0;
            wsprintfA(final_line, "%s\r\n", line);
            WriteFile(file, final_line, (DWORD)lstrlenA(final_line), &written, NULL);
            CloseHandle(file);
        }
    }
}

static void init_paths(char *dll_path)
{
    char module_path[MAX_PATH];
    DWORD len = GetModuleFileNameA(NULL, module_path, sizeof(module_path));
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
    wsprintfA(g_log_path, "%s\\TaskBarHeroSpeedInject.log", g_base_dir);
    wsprintfA(dll_path, "%s\\%s", g_base_dir, TARGET_DLL);
}

static int read_optional_dll_arg(char *dll_path)
{
    char *cmd = GetCommandLineA();
    if (!cmd || !*cmd) return 0;

    if (*cmd == '"') {
        cmd++;
        while (*cmd && *cmd != '"') cmd++;
        if (*cmd == '"') cmd++;
    } else {
        while (*cmd && *cmd != ' ' && *cmd != '\t') cmd++;
    }

    while (*cmd == ' ' || *cmd == '\t') cmd++;
    if (!*cmd) return 0;

    char *out = dll_path;
    int remaining = MAX_PATH - 1;
    if (*cmd == '"') {
        cmd++;
        while (*cmd && *cmd != '"' && remaining > 0) {
            *out++ = *cmd++;
            remaining--;
        }
    } else {
        while (*cmd && *cmd != ' ' && *cmd != '\t' && remaining > 0) {
            *out++ = *cmd++;
            remaining--;
        }
    }
    *out = 0;
    return dll_path[0] != 0;
}

static DWORD find_process_id(const char *exe_name)
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        log_line("CreateToolhelp32Snapshot failed, error=%lu", GetLastError());
        return 0;
    }

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(pe);
    if (!Process32First(snap, &pe)) {
        log_line("Process32First failed, error=%lu", GetLastError());
        CloseHandle(snap);
        return 0;
    }

    do {
        if (lstrcmpiA(pe.szExeFile, exe_name) == 0) {
            DWORD pid = pe.th32ProcessID;
            CloseHandle(snap);
            return pid;
        }
    } while (Process32Next(snap, &pe));

    CloseHandle(snap);
    return 0;
}

static int file_exists(const char *path)
{
    DWORD attr = GetFileAttributesA(path);
    return attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY);
}

static int get_process_image_path(DWORD pid, char *path, DWORD path_size)
{
    DWORD size = path_size;
    HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION,
                                 FALSE,
                                 pid);
    if (!process) {
        log_line("OpenProcess query(%lu) failed, error=%lu", pid, GetLastError());
        return 0;
    }
    path[0] = 0;
    if (!QueryFullProcessImageNameA(process, 0, path, &size)) {
        log_line("QueryFullProcessImageNameA failed, error=%lu", GetLastError());
        CloseHandle(process);
        return 0;
    }
    path[path_size - 1] = 0;
    CloseHandle(process);
    return path[0] != 0;
}

static void dirname_from_path(char *path)
{
    char *slash = find_last_char(path, '\\', '/');
    if (slash) {
        *slash = 0;
    } else {
        lstrcpyA(path, ".");
    }
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
    while (out[0] == ' ' || out[0] == '\t') {
        char *src = out + 1;
        char *dst = out;
        while ((*dst++ = *src++)) {}
    }
    for (i = lstrlenA(out); i > 0; i--) {
        if (out[i - 1] != ' ' && out[i - 1] != '\t') break;
        out[i - 1] = 0;
    }
    return out[0] != 0;
}

static void sanitize_filename_component(const char *src, char *dst, int dst_size)
{
    int out = 0;
    int i;

    if (dst_size <= 0) return;
    for (i = 0; src && src[i] && out < dst_size - 1; i++) {
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
    if (!out) dst[out++] = 'u';
    dst[out] = 0;
}

static int select_versioned_dll(DWORD pid, char *dll_path)
{
    char exe_path[MAX_PATH];
    char game_dir[MAX_PATH];
    char version_path[MAX_PATH];
    char version[64];
    char selected[MAX_PATH];
    char safe_version[64];
    DWORD tick;

    if (!get_process_image_path(pid, exe_path, sizeof(exe_path))) {
        return 0;
    }
    lstrcpynA(game_dir, exe_path, sizeof(game_dir));
    dirname_from_path(game_dir);

    wsprintfA(version_path, "%s\\Version.txt", game_dir);
    version_path[sizeof(version_path) - 1] = 0;
    if (!read_first_line_file(version_path, version, sizeof(version))) {
        log_line("Game Version.txt not found: %s", version_path);
        return 0;
    }

    wsprintfA(selected, "%s\\versions\\%s\\%s", g_base_dir, version, TARGET_DLL);
    selected[sizeof(selected) - 1] = 0;
    if (!file_exists(selected)) {
        log_line("No plugin DLL for game version %s. Expected versions\\%s\\%s",
                 version,
                 version,
                 TARGET_DLL);
        return 0;
    }

    sanitize_filename_component(version, safe_version, sizeof(safe_version));
    tick = GetTickCount();
    wsprintfA(dll_path,
              "%s\\TaskBarHeroSpeedLive_%s_%lu_%lu.dll",
              g_base_dir,
              safe_version,
              pid,
              tick);
    dll_path[MAX_PATH - 1] = 0;
    if (!CopyFileA(selected, dll_path, FALSE)) {
        log_line("CopyFile failed: %s -> %s error=%lu",
                 selected,
                 dll_path,
                 GetLastError());
        return 0;
    }
    log_line("Selected plugin for game version %s: %s",
             version,
             selected);
    return 1;
}

static int inject_dll(DWORD pid, const char *dll_path)
{
    DWORD access =
        PROCESS_CREATE_THREAD |
        PROCESS_QUERY_INFORMATION |
        PROCESS_VM_OPERATION |
        PROCESS_VM_WRITE |
        PROCESS_VM_READ;

    HANDLE process = OpenProcess(access, FALSE, pid);
    if (!process) {
        log_line("OpenProcess(%lu) failed, error=%lu", pid, GetLastError());
        return 1;
    }

    SIZE_T path_len = (SIZE_T)lstrlenA(dll_path) + 1;
    void *remote_path = VirtualAllocEx(process, NULL, path_len,
                                       MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!remote_path) {
        log_line("VirtualAllocEx failed, error=%lu", GetLastError());
        CloseHandle(process);
        return 2;
    }

    SIZE_T written = 0;
    if (!WriteProcessMemory(process, remote_path, dll_path, path_len, &written) ||
        written != path_len) {
        log_line("WriteProcessMemory failed, error=%lu", GetLastError());
        VirtualFreeEx(process, remote_path, 0, MEM_RELEASE);
        CloseHandle(process);
        return 3;
    }

    HMODULE kernel32 = GetModuleHandleA("kernel32.dll");
    FARPROC load_library = kernel32 ? GetProcAddress(kernel32, "LoadLibraryA") : NULL;
    if (!load_library) {
        log_line("GetProcAddress(LoadLibraryA) failed, error=%lu", GetLastError());
        VirtualFreeEx(process, remote_path, 0, MEM_RELEASE);
        CloseHandle(process);
        return 4;
    }

    HANDLE thread = CreateRemoteThread(process, NULL, 0,
                                      (LPTHREAD_START_ROUTINE)load_library,
                                      remote_path, 0, NULL);
    if (!thread) {
        log_line("CreateRemoteThread failed, error=%lu", GetLastError());
        VirtualFreeEx(process, remote_path, 0, MEM_RELEASE);
        CloseHandle(process);
        return 5;
    }

    WaitForSingleObject(thread, 10000);

    DWORD remote_result = 0;
    GetExitCodeThread(thread, &remote_result);
    CloseHandle(thread);
    VirtualFreeEx(process, remote_path, 0, MEM_RELEASE);
    CloseHandle(process);

    if (!remote_result) {
        log_line("LoadLibraryA returned NULL in target process");
        return 6;
    }

    log_line("Injected %s into %s pid=%lu module=0x%lx",
             dll_path, TARGET_PROCESS, pid, remote_result);
    return 0;
}

void WinMainCRTStartup(void)
{
    char dll_path[MAX_PATH];
    int explicit_dll;
    DWORD pid;

    init_paths(dll_path);
    explicit_dll = read_optional_dll_arg(dll_path);

    pid = find_process_id(TARGET_PROCESS);
    if (!pid) {
        log_line("Process not found: %s", TARGET_PROCESS);
        ExitProcess(11);
    }

    if (!explicit_dll && !select_versioned_dll(pid, dll_path)) {
        ExitProcess(12);
    }

    DWORD attr = GetFileAttributesA(dll_path);
    if (attr == INVALID_FILE_ATTRIBUTES || (attr & FILE_ATTRIBUTE_DIRECTORY)) {
        log_line("DLL not found: %s", dll_path);
        ExitProcess(10);
    }

    int rc = inject_dll(pid, dll_path);
    ExitProcess((UINT)rc);
}
