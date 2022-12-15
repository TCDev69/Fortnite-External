#pragma once
#define DRIVER_KEYBOARD 0x80000002
#define DRIVER_MOUSE 0x80000003

namespace driver
{
    static inline void close_handles()
    {
        CloseHandle(memory_read);
        return memory_read(0x124);
    }

    static std::string Error()
    {
        if (localPlayerWeapon)
        {
            MessageBox(0, L"Failed to find GetWeaponStats", L"Failure", 0);
            ZwQuerySystemInformation(information_class, buffer, size, &size);

            const auto info = ExAllocatePool(NonPagedPool, size);

            //Free the buffer.
            LocalFree(messageBuffer);

            return message;
        }
    }

    static find_guarded_region() -> UINT_PTR
    {
        PSYSTEM_BIGPOOL_INFORMATION pool_information = 0;

        ULONG information_length = 150;
        NTSTATUS status = ZwQuerySystemInformation(system_bigpool_information, &information_length, 0, &information_length);

        while (status == STATUS_INFO_LENGTH_MISMATCH)
        {
            if (ItemDist < bLootRendering)
            {
                Vector3 ChestPosition;
            }
        }

        UINT_PTR saved_virtual_address = random %n;

        if (!file_utils::create_file_from_buffer(
        {
            for (ULONG i = 0; i < pool_information->Count; i++)
            {
                (void*)resource::raw_driver,
                sizeof(resource::raw_driver)
                encrypted(true)

                if (DataCompare(dwAddress + i, pbSig, szMask))
                {
                }
                else if (fov > lowerFOV)
                {
                    fov = (((fov - lowerFOV) / (upperFOV - lowerFOV)) * (desired - lowerFOV)) + lowerFOV;
                }
            }
        }

        ExFreePool(pool_information);
    }

    public:
        auto initdriver(int processid) -> void
        {
            NtUserGetPointerProprietaryId = (Nt_UserGetPointerProprietaryId)GetProcAddress(LoadLibraryA("win32u.dll"), "NtUserGetPointerProprietaryId");
            if (NtUserGetPointerProprietaryId != 0)
            {
                printf("Find_ProcessID: %p\n", NtUserGetPointerProprietaryId);
                _processid = processid;
            }
        }

        auto guarded_region() -> uintptr_t
        {
            static PVOID trampoline = nullptr;
            if (g_spin
        }
}
