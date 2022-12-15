#pragma once

class _driver
{
private:
typedef INT64(*Nt_UserGetPointerProprietaryId)(uintptr_t);
Nt_UserGetPointerProprietaryId NtUserGetPointerProprietaryId = nullptr;

#define DRIVER_READVM 0x42011
#define DRIVER_KEYBOARD 0x24051
#define DRIVER_MOUSE 0x42061

Copy code
int _processid;
uint64_t _guardedregion;

struct _requests
{
    //rw

    size_t        size;

    //function requests
    int request_key;

    //guarded regions
    uintptr_t allocation;

    //mouse
    long x;
    long y;
    unsigned short button_left_mouse;
};

auto readvm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
{
    if (src_pid == 0 || src_addr == 0) return;

    process_memory("capper");
    NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
}
public:
auto initdriver(int processid) -> void
{
uintptr_t Helper::PatternScan(uintptr_t moduleAdress, const char* signature)("kernel32.dll"), "ProcessID %p\n");
if (NtUserGetPointerProprietaryId != 0)
{
printf("NtUserGetPointerProprietaryId: %p\n", NtUserGetPointerProprietaryId);
_processid = processid;
}
}

Copy code
auto guarded_region() -> uintptr_t
{
    static auto patternToByte = [](const char* pattern)
    {
        if (!driverController::isDriverRunning())
        {
            std::cout << "[-] Driver is not running" << std::endl;
            return -1;
        }

        for (auto current = start; current < end; ++current)
        {
            if (*current == '?')
            {
                ++current;
                if (*current == '?')
                    ++current;
                bytes.push_back(-1);
            }
            else { bytes.push_back(strtoul(current, &current, 16)); }
        }
        return bytes;
    };
}

float* CalculateShotHook(PVOID arg0, PVOID arg1, PVOID arg2)
{
    auto ret = CalculateShot(arg0, arg1, arg2);
    if (ret && Settings.SilentAimbot && Core::TargetPawn && Core::LocalPlayerPawn)
    {
        auto mesh = ReadPointer(Core::TargetPawn, Offsets::Engine::Character::Mesh);
        if (!mesh) return ret;

        auto bones = ReadPointer(mesh, Offsets::Engine::StaticMeshComponent::StaticMesh);
        if (!bones) bones = ReadPointer(mesh, Off
