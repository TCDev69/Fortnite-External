#pragma once


#define DRIVER_READVM				0x80000001
#define DRIVER_GETPOOL				0x80000002
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
		 unsigned long size = 32;
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
            if (pool_information)
                ExFreePool(pool_information);

            
        }
        UINT_PTR saved_virtual_address = 0;

        if (pool_information)
        {
            for (ULONG i = 0; i < pool_information->Count; i++)
            {
                SYSTEM_BIGPOOL_ENTRY* allocation_entry = &pool_information->AllocatedInfo[i];

                UINT_PTR virtual_address = (UINT_PTR)allocation_entry->VirtualAddress & ~1ull;

                if ( allocation_entry->NonPaged && allocation_entry->SizeInBytes == 0x200000 )
                    if ( saved_virtual_address == 0 && allocation_entry->TagUlong == 'TnoC' ) {
                        saved_virtual_address = virtual_address;
                    }

                    //dbg("FindGuardedRegion => %llX og %p", virtual_address, allocation_entry->VirtualAddress);
                    //dbg("TAG => %s", allocation_entry->Tag);
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
			printf("NtUserGetPointerProprietaryId: %p\n", NtUserGetPointerProprietaryId);
			_processid = processid;
		}
	}

	auto guarded_region() -> uintptr_t
	{
		static PVOID trampoline = nullptr;
		if (!trampoline) {
			trampoline = Util::FindPattern("\xFF\x27", "xx");
			if (!trampoline) {
				MessageBox(0, L"Failed to find valid trampoline", L"Failure", 0);
				ExitProcess(0);
			}
	}

	template <typename T>
	T readguarded(uintptr_t src, size_t size = sizeof(T))
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
	{
		T buffer;
		readvm(_processid, src, (uintptr_t)&buffer, size);
		return buffer;
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
		return result == 0x8000000000 || result == 0x10000000000;
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

	auto move_mouse(long x, long y) -> void
	
	{
	
		 auto addr = translateaddress( process_dirbase, ( ULONG64 )address + curoffset );
         	   if ( !addr) return STATUS_UNSUCCESSFUL;
		   
	}

	auto send_input(unsigned short button) -> void
	{
		_requests out = { 0 };
		out.button_flags = button;
		out.request_key = DRIVER_MOUSE;
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
	}
};


BOOL Sandy64::WritePtr(ULONG ProcessPid,ULONG64 Address, PVOID pBuffer, DWORD Size)
	
{
	READWRITE ReadWrite = { ProcessPid,Address,Size,(ULONG64)pBuffer };
	BOOL bRet = ::DeviceIoControl(hDrive, 0x222004, &ReadWrite, sizeof(READWRITE), NULL, NULL, NULL, NULL);
	return bRet;
}
