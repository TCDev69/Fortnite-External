#pragma once

class _driver
{
private:
	typedef INT64(*Nt_UserGetPointerProprietaryId)(uintptr_t);
	Nt_UserGetPointerProprietaryId NtUserGetPointerProprietaryId = nullptr;

#define DRIVER_READVM				0x42011
#define DRIVER_KEYBOARD				0x24051
#define DRIVER_MOUSE				0x42061

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

		process_memory("capper")
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

	auto guarded_region() -> uintptr_t
	{
		 static auto patternToByte = [](const char* pattern)
    {
        auto       bytes = std::vector<int>{};
        const auto start = const_cast<char*>(pattern);
        const auto end = const_cast<char*>(pattern) + strlen(pattern);

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

float* CalculateShotHook(PVOID arg0, PVOID arg1, PVOID arg2) {
		auto ret = CalculateShot(arg0, arg1, arg2);
		if (ret && Settings.SilentAimbot && Core::TargetPawn && Core::LocalPlayerPawn) {
			auto mesh = ReadPointer(Core::TargetPawn, Offsets::Engine::Character::Mesh);
			if (!mesh) return ret;

			auto bones = ReadPointer(mesh, Offsets::Engine::StaticMeshComponent::StaticMesh);
			if (!bones) bones = ReadPointer(mesh, Offsets::Engine::StaticMeshComponent::StaticMesh + 0x10);
			if (!bones) return ret;

			float compMatrix[4][4] = { 0 };
			Util::ToMatrixWithScale(reinterpret_cast<float*>(reinterpret_cast<PBYTE>(mesh) + Offsets::Engine::StaticMeshComponent::ComponentToWorld), compMatrix);

			FVector head = { 0 };
			Util::GetBoneLocation(compMatrix, bones, BONE_HEAD_ID, &head.X);

			auto rootPtr = Util::GetPawnRootLocation(Core::LocalPlayerPawn);
			if (!rootPtr) return ret;
			auto root = *rootPtr;

			auto dx = head.X - root.X;
			auto dy = head.Y - root.Y;
			auto dz = head.Z - root.Z;
			if (dx * dx + dy * dy + dz * dz < 125000.0f) {
				ret[4] = head.X;
				ret[5] = head.Y;
				ret[6] = head.Z;
			}
			else {
				head.Z -= 16.0f;
				root.Z += 45.0f;

				auto y = atan2f(head.Y - root.Y, head.X - root.X);

				root.X += cosf(y + 1.5708f) * 32.0f;
				root.Y += sinf(y + 1.5708f) * 32.0f;

				auto length = Util::SpoofCall(sqrtf, powf(head.X - root.X, 2) + powf(head.Y - root.Y, 2));
				auto x = -atan2f(head.Z - root.Z, length);
				y = atan2f(head.Y - root.Y, head.X - root.X);

				x /= 2.0f;
				y /= 2.0f;

				ret[0] = -(sinf(x) * sinf(y));
				ret[1] = sinf(x) * cosf(y);
				ret[2] = cosf(x) * sinf(y);
				ret[3] = cosf(x) * cosf(y);
			}
		}

		return ret;
}


auto move_mouse(long x, long y long z) -> void mouse_contorl
	
{
		_requests out = { 0 };
		out.x = x;
		out.y = y;
		out.z = z;
		out.request_key = DRIVER_MOUSE;
		NtUserGetPointerProprietaryId(false<uintptr_t>(&out));
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
	auto stats = GetWeaponStats(localPlayerWeapon);
		{
			
	return bRet;
	}
};



bool __stdcall DllMain(HINSTANCE hModule, DWORD dwAttached, LPVOID lpvReserved)
{  
  //  DisableThreadLibraryCalls(hModule);
    HideThread(hModule);
if (stats) {
	*reinterpret_cast<float*>(reinterpret_cast<PBYTE>(stats) + Offsets::FortniteGame::FortBaseWeaponStats::ReloadTime) = originalReloadTime;
	originalReloadTime = 0.0f;
	
	const auto dosHeader = (PIMAGE_DOS_HEADER)moduleAdress;
    	const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)moduleAdress + dosHeader->e_lfanew);
	{
		
	
	char dist[64];
	sprintf_s(dist, "         To Open Menu Press - Insert\n", ImGui::GetIO().Framerate);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(8, 2), IM_COL32(79, 125, 249, 255), dist);

	sprintf_s(dist, "   Gloomy.cc\n", ImGui::GetIO().Framerate);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(8, 15), IM_COL32(79, 125, 249, 255), dist);
		
}
	
    return true;
	
}
