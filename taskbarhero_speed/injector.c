#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>

#define TARGET_PROCESS "TaskBarHero.exe"
#define TARGET_DLL "TaskBarHeroSpeed.dll"

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

static void read_optional_dll_arg(char *dll_path)
{
    char *cmd = GetCommandLineA();
    if (!cmd || !*cmd) return;

    if (*cmd == '"') {
        cmd++;
        while (*cmd && *cmd != '"') cmd++;
        if (*cmd == '"') cmd++;
    } else {
        while (*cmd && *cmd != ' ' && *cmd != '\t') cmd++;
    }

    while (*cmd == ' ' || *cmd == '\t') cmd++;
    if (!*cmd) return;

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
    init_paths(dll_path);
    read_optional_dll_arg(dll_path);

    DWORD attr = GetFileAttributesA(dll_path);
    if (attr == INVALID_FILE_ATTRIBUTES || (attr & FILE_ATTRIBUTE_DIRECTORY)) {
        log_line("DLL not found: %s", dll_path);
        ExitProcess(10);
    }

    DWORD pid = find_process_id(TARGET_PROCESS);
    if (!pid) {
        log_line("Process not found: %s", TARGET_PROCESS);
        ExitProcess(11);
    }

    int rc = inject_dll(pid, dll_path);
    ExitProcess((UINT)rc);
}
