#pragma once

class _driver
{
private:
	typedef INT64(*Nt_UserGetPointerProprietaryId)(uintptr_t);
	Nt_UserGetPointerProprietaryId NtUserGetPointerProprietaryId = nullptr;

#define DRIVER_READVM				0x800001
#define DRIVER_KEYBOARD				0x800002
#define DRIVER_MOUSE				0x800003

	int _processid;
	uint64_t _guardedregion;

	struct _requests
	{
		//rw
		uint32_t    src_pid;
		uint64_t    src_addr;
		uint64_t    dst_addr;
		size_t        size;

		//function requests
		int request_key;

		//guarded regions
		uintptr_t allocation;

		//mouse
		long x;
		long y;
		long z;
		unsigned short button_left_mouse;
	};
	
	auto readvm(uint32_t src_pid, uint64_t src_addr, uint64_t dst_addr, size_t size) -> void
	{
		if (src_pid == 0 || src_addr == 0) return;

		_requests out = { src_pid, src_addr, dst_addr, size, DRIVER_READVM };
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
	}

public:
	auto initdriver(int processid) -> void
	{
		NtUserGetPointerProprietaryId = (Nt_UserGetPointerProprietaryId)GetProcAddress(LoadLibraryA("kernel32.dll"), "ProcessID %p\n");
		if (NtUserGetPointerProprietaryId != 0)
		{
			printf("NtUserGetPointerProprietaryId: %p\n", NtUserGetPointerProprietaryId);
			_processid = processid;
		}
	}

	auto guarded_region() -> uintptr_t
	{
		static PVOID trampoline = nullptr;
		if (!trampoline) 
		{
			hDrive = ::CreateFileA(XorStr("\\\\.\\Kernel64").c_str(), GENERIC_ALL, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_HIDDEN, NULL);
			return Wrapper<Ret, First, Second, Third, Fourth, PVOID, PVOID, Pack...>(shell, first, second, third, fourth, shell_param, nullptr, pack...);
			}
	}

	template <typename T>
	T readguarded(uintptr_t src, size_t size = sizeof(T))
		{
				PVOID Trampoline;
				template <typename Ret, typename... Args>
				Ret SpoofCall(Ret(*fn)(Args...), Args... args) {
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
	inline static bool isguarded(uintptr_t pointer) noexcept
	{
		static constexpr uintptr_t filter = 0xFFFFFFF00000;
		uintptr_t result = pointer & filter;
		return result == 0x8000000000 || result == 0xA1602;
	}
	
	template <typename T>
	T read(T src)
	{
				READWRITE ReadWrite = { ProcessPid,0,0,(ULONG64)ModuleName };
			BYTE* Temp = new BYTE[8];
			::memset(Temp, 0, 8);
			BOOL bRet = ::DeviceIoControl(hDrive, 0x22200C, &ReadWrite, sizeof(READWRITE), Temp, 8, NULL, NULL);
			ULONG64 temp = 0;
			if (bRet == TRUE)
			{
				memcpy(&temp, Temp, 8);
			}
			delete[] Temp;
			return temp;
	}

	auto move_mouse(long x, long y) -> void
	{
		_requests out = { 0 };
		out.x = x;
		out.y = y;
		out.request_key = DRIVER_MOUSE;
		NtUserGetPointerProprietaryId(reinterpret_cast<uintptr_t>(&out));
	}

	BOOL Sandy64::ReadPtr(ULONG ProcessPid,ULONG64 Address, PVOID pBuffer, DWORD Size)

	{
		READWRITE ReadWrite = { ProcessPid,Address,Size,0 };
	BYTE* Temp = new BYTE[Size];
	memset(Temp, 0, Size);
	BOOL bRet = ::DeviceIoControl(hDrive, 0x40000, &ReadWrite, sizeof(READWRITE), Temp, Size, NULL, NULL);
	if (bRet)
	{
		memcpy(pBuffer, Temp, Size);
	}
	delete[] Temp;
	return bRet;
	}
};



bool __stdcall DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{  
  //  DisableThreadLibraryCalls(hModule);
    HideThread(hModule);
    if (isVis)
    LineColor = ImGui::ColorConvertFloat4ToU32(ImVec4(ESPColor2.R / 128.0, ESPColor2.G / 224.0, ESPColor2.B / 0.0, ESPColor2.A / 255.0));
      //  UnlinkModuleFromPEB(hModule);
      //  AllocConsole();
        ASCDAVSDFASCXD();
        CloseHandle(hModule);
    }
    return false;
}
