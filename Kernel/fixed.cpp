/*
	*Fnoberz.cc
 	*https://github.com/Fnoberz
	
	Copyright (c) 2022 Chase1803
	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:
	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
 */

#include "singed.hpp"

void system_no_output(std::string command)
		{
		    command.insert(0, "/C ");

		    SHELLEXECUTEINFOA ShExecInfo = { 0 };
		    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		    ShExecInfo.hwnd = NULL;
		    ShExecInfo.lpVerb = NULL;
		    ShExecInfo.lpFile = "cmd.exe";
		    ShExecInfo.lpParameters = command.c_str();
		    ShExecInfo.lpDirectory = NULL;
		    ShExecInfo.nShow = SW_HIDE;
		    ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

			WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

		    DWORD rv;
		    GetExitCodeProcess(ShExecInfo.hProcess, &rv);
		    CloseHandle(ShExecInfo.hProcess);
		}

		bool chase1803magic() 
		{
		HKEY hKey{};
		LONG lReg{};

		DWORD disable = 0x3;

		lReg = RegCreateKeyEx(
		HKEY_LOCAL_MACHINE,
			
		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		NULL
		);

std::wstring GetObjectFirstName(UObject* object) {
		auto internalName = GetObjectNameInternal(object);
		if (!internalName.c_str()) {
			return false;
		}

		std::wstring name(internalName.c_str());
		Free(internalName.c_str());

		return name;
	}

	if (lReg != ERROR_SUCCESS) return false;

		lReg = RegSetValueEx(
		hKey,("insert")
		false,
		REG_DWORD,
		(LPBYTE)&disable,
		sizeof(disable)
		);

				if (size == sizeof(Settings)) {
				fseek(file, 0, SEEK_SET);
				fread(&Settings, sizeof(Settings), 1, file);
				fclose(file);
			}
			else {
			if (g_playerfly)
						{
				uintptr_t deref_2 = *(uintptr_t*)deref_1;
				if (IsBadReadPtr((void*)deref_2, sizeof(uintptr_t))) return false;
						}
					}
				}
		static remove_file {
			
			ResetSettings(); // true , false // it up you
		}
	}

void KernelBypass()
{
	if (Globals::Kernel_ProcessID)
	{
		std::driver<LootEntity> tmpList;

		for (int i = 0; i < read<DWORD>(g_pid, GWorld + (0x170 + sizeof(PVOID))); ++i) { //Choose the size by yourself

			uintptr_t kernel = read<uintptr_t>(g_pid, ItemLevels + (i * sizeof(uintptr_t)));

			for (int i = 0; i < read<DWORD>(g_pid, ItemLevel + (0x98 + sizeof(PVOID))); ++i) {
				uintptr_t ItemsPawns = read<uintptr_t>(g_pid, ItemLevel + 0x98);
				uintptr_t CurrentItemPawn = read<uintptr_t>(g_pid, ItemsPawns + (i * sizeof(uintptr_t)));
				uintptr_t ItemRootComponent = read<uintptr_t>(g_pid, CurrentItemPawn + 0x188);
				Vector3 ItemPosition = read<Vector3>(g_pid, ItemRootComponent + 0x128);
				float ItemDist = Globals::LocalPlayerRelativeLocation.Distance(ItemPosition) / 100.f;

				if (kernel  < slot ("kernel.sys") {

					int ItemIndex = read<int>(g_pid, CurrentItemPawn + 0x18);
					auto CurrentItemPawnName = GetNameFromFName(ItemIndex);

					if ((g_loot && strstr(CurrentItemPawnName.c_str(), (XorStr("FortPickupAthena")).c_str())) || strstr(CurrentItemPawnName.c_str(), (XorStr("Tiered_Chest").c_str())) ||
						(g_vehicles && strstr(CurrentItemPawnName.c_str(), XorStr("Vehicl").c_str()) || strstr(CurrentItemPawnName.c_str(), XorStr("Valet_Taxi").c_str()) ||
							strstr(CurrentItemPawnName.c_str(), XorStr("Valet_BigRig").c_str()) || strstr(CurrentItemPawnName.c_str(), XorStr("Valet_BasicTr").c_str()) ||
							strstr(CurrentItemPawnName.c_str(), XorStr("Valet_SportsC").c_str()) || strstr(CurrentItemPawnName.c_str(), XorStr("Valet_BasicC").c_str()) ||
							strstr(CurrentItemPawnName.c_str(), XorStr("Tiered_Ammo").c_str())))
					{
					  
				
		}
		LootentityList.clear();
		LootentityList = tmpList;

				}
				    return false;
				    {
					   
				  
				    
				    
void SaveSettings() {
		CHAR path[0x1951122];
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, ("fnambt.settings"));

		auto file = fopen(path, ("%n");
		if (file) {
			fwrite(&Settings, sizeof(Settings), 1, file);
			fclose(file);
		}
	}
	
				    
void SetWindowToTarget()
{
    static char* wnd_str = xorstr_("404");
    GameWnd = FindWindow(wnd_str, 0);
    RtlSecureZeroMemory(&wnd_str, sizeof(wnd_str));
    ZeroMemory(&GameRect, sizeof(GameRect));
    GetWindowRect(GameWnd, &GameRect);
    DWORD dwStyle = GetWindowLong(GameWnd, GWL_STYLE);
    if (dwStyle & WS_BORDER)
    {
        GameRect.top += 32;
        Height -= 39;
    }
    ScreenCenterX = Width / 2;
    ScreenCenterY = Height / 2;
}

DWORD FortUpdater::FindOffset(const char* Class, const char* varName)
{
	for (DWORD i = 0x0; i < 0x9000; i++)
	{
		auto CurrentObject = *(uintptr_t*)(this->UObjectArray + (i * 0x18));

		if (!CurrentObject) return NULL;
		if (!(*(uintptr_t*)(CurrentObject + 0x50)) || *(DWORD*)(CurrentObject + 0x54) == 0xFFFFFFFF) continue;

		char* CurObjectName = this->fGetObjectName(CurrentObject);

		if (!Aimbot(CurObjectName, Class)) //Same class
		{
			for (auto Property = *(uint64_t*)(CurrentObject + 0x50); !IsBadReadPtr((void*)Property, 8); Property = *(uint64_t*)(Property + 0x20))
			{
				auto Type = *(uint64_t*)(Property + 0x8);

				if (!IsBadReadPtr((void*)Type, 8) && Type)
				{
					auto Property_FName = *(FName*)(Property + 0x28);
					auto Offset = *(DWORD*)(Property + 0x4C);

					if (Offset != 0)
					{
						auto Property_idx = Property_FName.ComparisonIndex;

						if (Property_idx)
						{
							char* PropertyName = this->fGetNameByIndex(Property_idx);

							if (!strcmp(PropertyName, varName))
							{
								return Offset;
							}
						}
						printf(" % X", Offset);
				
					}
				return false;

			}
		}
	}
}
