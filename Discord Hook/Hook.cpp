/*


*/
#include <cstdint>
#include <Windows.h>
#include "../Helper/Helper.h"
#include "Discord.h"

#define DEVELOPER

uintptr_t Discord::GetDiscordModuleBase()
{
    // This is static because we only need to get once.
    static uintptr_t discordModuleBase = 0;

    // If its false, we use GetModuleHandle to grab the Module Base adress. 
    if (!discordModuleBase)
        discordModuleBase = (uintptr_t)GetModuleHandleA("DiscordHook64.dll");

    return discordModuleBase;
}

bool Discord::CreateHook(uintptr_t originalPresent, uintptr_t hookFunction, uintptr_t pOriginal)
{

    static uintptr_t addrCreateHook = NULL;

    if (!addrCreateHook)
    {
        addrCreateHook = Helper::PatternScan(GetDiscordModuleBase(), "41 57 41 56 56 57 55 53 48 83 EC 68 4D 89 C6 49 89 D7");

#ifdef DEVELOPER
#endif
    }

    if (!addrCreateHook)
        return false;

    using CreateHook_t = uint64_t(__fastcall*)(LPVOID, LPVOID, LPVOID*);
    auto fnCreateHook = (CreateHook_t)addrCreateHook;
    return fnCreateHook((void*)originalPresent, (void*)hookFunction, (void**)pOriginal) == 0 ? true : false;

}

bool Discord::EnableHook(uintptr_t pTarget, bool toggle)
{
    static uintptr_t addrEnableHook = NULL;

    if (!addrEnableHook)
    {
        addrEnableHook = Helper::PatternScan(GetDiscordModuleBase(),
            "41 56 56 57 53 48 83 EC 28 49 89 CE BF 01 00 00 00 31 C0 F0 ? ? ? ? ? ? ? 74"
        );
    }

    if (!addrEnableHook)
        return false;

    using EnableHook_t = uint64_t(__fastcall*)(LPVOID, bool);
    auto fnEnableHook = (EnableHook_t)addrEnableHook;

    return fnEnableHook((void*)pTarget, toggle) == 0 ? true : false;
}



