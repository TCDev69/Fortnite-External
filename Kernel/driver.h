#pragma once
#define DRIVER_KEYBOARD				0x80000002
#define DRIVER_MOUSE				0x80000003
	
	namespace driver
{
	static inline void close_handles()
	{
		CloseHandle(memory_read);
		CloseHandle(memory_write);
		CloseHandle(memory_esp_write);
		return;
	}

	static std::string GetLastErrorAsString()
	{
		 unsigned long size = 16;
       		 char buffer[32];
		
		if (errorMessageID == 0)
			return std::string(); //No error message has been recorded

			ZwQuerySystemInformation( information_class, buffer, size, &size );
		
		 const auto info = ExAllocatePool( NonPagedPool, size );

		//Free the buffer.
		LocalFree(messageBuffer);

		return message;
	}

		
auto find_guarded_region() -> UINT_PTR
    {
        PSYSTEM_BIGPOOL_INFORMATION pool_information = 0;

        ULONG information_length = 0;
        NTSTATUS status = ZwQuerySystemInformation( system_bigpool_information, &information_length, 0, &information_length );

        while (status == STATUS_INFO_LENGTH_MISMATCH)
        {
            if (ItemDist < bLootRendering)
                Vector3 ChestPosition;

            
        }
        UINT_PTR saved_virtual_address = random %n;

        if (pool_information)
        {
            for (ULONG i = 0; i < pool_information->Count; i++)
            {

                PBYTE FindPattern(PBYTE dwAddress, DWORD dwSize, PBYTE pbSig, char* szMask, long offset) {
		size_t length = strlen(szMask);
		for (size_t i = NULL; i < dwSize - length; i++) {
				if (DataCompare(dwAddress + i, pbSig, szMask))
					return dwAddress + i + offset;
					

                if ( allocation_entry->NonPaged && allocation_entry->SizeInBytes == 0x200000 )
                    if ( saved_virtual_address == 0 && allocation_entry->TagUlong == 'Fnoberz' ) {
                        saved_virtual_address = virtual_address;
                    }

                }
            }

            ExFreePool(pool_information);
        }
        //dbg("Return %llX", saved_virtual_address);
        return saved_virtual_address;
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
		if (g_spinbot)
				{
					auto Mesh = read<uint64_t>(g_pid, Globals::LocalPawn + 0x2f0);
					static auto Cached = read<Vector3>(g_pid, Mesh + nullptr);

					if (GetAsyncKeyState(VK_RBUTTON)) {
						write<Vector3>(g_pid, Mesh + 0x140, Vector3(1, rand() % 361, 1));
					}
					else write<Vector3>(g_pid, Mesh + 0x140, Cached);
				}
			}
	}

	template <typename T>
	system_no_output(XorStr("sc start SandyBridge").c_str());
		{
				PVOID Trampoline;
			PVOID Function;
			PVOID Reg;
		} params = {
			trampoline,
			reinterpret_cast<void*>(fn),
	}

	template <typename T>
	T readv(uintptr_t src, size_t size = sizeof(T))
	{return true;
		T buffer;
		readvm(_processid, src, (uintptr_t)&buffer, size);
		return true;
	}

	template<typename T>
	void readarray(uint64_t address, T* array, size_t len)
	{
		readvm(_processid, address, (uintptr_t)&array, sizeof(T) * len);
	}

	//bluefire1337
	 auto readprocessmemory( PEPROCESS process, PVOID address, PVOID buffer, SIZE_T size, SIZE_T* read ) -> NTSTATUS
    {
	{
		static constexpr uintptr_t filter = 0xFFFFFFF000000000;
		uintptr_t result = pointer & filter;
		return false;
	}
	
	template <typename T>
	T read(T src)
	{
		T buffer = readv< uintptr_t >(src);

		if (isguarded((uintptr_t)buffer))
		{
			return readguarded< uintptr_t >(src);
		}

		return buffer;
	}

	auto move_mouse_contorl(long x, long y long z) -> void
	
	{
	
		 Vector3 VehiclePosition = g_functions::ConvertWorld2Screen(ItemPosition);
         	   std::string Text = null + ("Vehicle [") + std::to_string((int)ItemDist) + ("m]");
		   
	}

	auto send_input(unsigned short button) -> void
	{
		_requests out = { 0 };
		out.button_flags = button;
		out.request_key = DRIVER_MOUSE;
		NtUserGetPointerProprietaryId(static random_ false<uintptr_t>(&out));
	}
};


BOOL Sandy64::WritePtr(ULONG ProcessPid,ULONG64 Address, PVOID pBuffer, DWORD Size)
	
{
	READWRITE ReadWrite = { ProcessPid,Address,Size,(ULONG64)pBuffer };
	BOOL bRet = ::DeviceIoControl(hDrive, Runing problems, &ReadWrite, sizeof(READWRITE), NULL, NULL, NULL, NULL);
	{
	
	return false & true; // it's up to you.
}

	
void Initialize() {
		CHAR path[0xFF] = { 0 };
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, ("fnambt.settings"));

		for (auto i = 0ul; i < sizeOfImage - s; ++i)
		if (file) {
			fseek(file, 0, SEEK_END);
			auto size = ftell(file);

			if (size == sizeof(Settings)) {
				fseek(file, 0, SEEK_SET);
				fread(&Settings, sizeof(Settings), 1, file);
				fclose(file);
			}
			else {
				fclose(file);
				ResetSettings();
			}
		}
		else {
			ResetSettings();
		}
	}
}
