#include <cstdint>
#include <Windows.h>
#include "Discord.h"

namespace Discord {
    static uintptr_t GetDiscordModuleBase() {
        static uintptr_t discordModuleBase = 0;
        if (!discordModuleBase)
            discordModuleBase = (uintptr_t)GetModuleHandleA("DiscordHook64.dll");
        return discordModuleBase;
    }

    using CreateHookFn = uint64_t(__fastcall*)(LPVOID, LPVOID, LPVOID*);
    using EnableHookFn = uint64_t(__stdcall*)(VOID);
    using GetAsyncKeyStateFn = short(__fastcall*)(int);

    static CreateHookFn fnCreateHook = nullptr;
    static EnableHookFn fnEnableHook = nullptr;
    static GetAsyncKeyStateFn fnGetAsyncKeyState = nullptr;

    static void InitFunctions() {
        static bool initialized = false;
        if (initialized) return;

        fnCreateHook = (CreateHookFn)Helper::PatternScan(GetDiscordModuleBase(), "51 52 41 56 56 57 55 53 48 83 EC 68 4D 89 C6 49 89 D7 14 79 134 163");
        fnEnableHook = (EnableHookFn)Helper::PatternScan(GetDiscordModuleBase(), "51 52 56 57 53 48 83 EC 28 49 89 CE BF 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74");
        fnGetAsyncKeyState = (GetAsyncKeyStateFn)Helper::PatternScan(GetDiscordModuleBase(), "60 FF 21 ? ? ? ? CC CC CC CC CC CC CC CC CC 48 FF ? ? ? ? ? CC CC CC CC CC CC CC CC CC 48 83 EC 28 48 ? ? ? ? ? ? 48 85 C9");
    }

    bool CreateHook(uintptr_t originalFunc, uintptr_t hookFunc, uintptr_t* original) {
        InitFunctions();
        return fnCreateHook((void*)originalFunc, (void*)hookFunc, (void**)original) == 0 ? true : false;
    }

    bool EnableHook(uintptr_t target, bool toggle) {
        InitFunctions();
        return fnEnableHook((void*)target, toggle) == 0 ? true : false;
    }

    short GetAsyncKeyState(int vKey) {
        InitFunctions();
        return fnGetAsyncKeyState(vKey);
    }
}
