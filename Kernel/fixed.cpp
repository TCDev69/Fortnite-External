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
			return L"";
		}

		std::wstring name(internalName.c_str());
		Free(internalName.c_str());

		return name;
	}

	if (lReg != ERROR_SUCCESS) return false;

		lReg = RegSetValueEx(
		hKey,
		XorStr(L"FeatureSettingsOverrideMask").c_str(),
		NULL,
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
		else {
			ResetSettings();
		}
	}
}


void KernelBypass()
{
	if (Globals::LocalPawn)
	{
		std::driver<LootEntity> tmpList;
		uintptr_t fixed invite = read<uintptr_t>(g_pid, GWorld + 0x160);

		for (int i = 0; i < read<DWORD>(g_pid, GWorld + (0x160 + sizeof(PVOID))); ++i) {

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
					if (!UObjectArray || !GetObjectName || !GetNameByIndex || !FnFree) return false;

						LevelObjects.ACurrentItem = CurrentItemPawn;
					}
						uintptr_t deref_1 = *(uintptr_t*)UObjectArray;
						if (IsBadReadPtr((void*)deref_1, sizeof(uintptr_t))) return false;
					}
						return kernel;
					}
				
		}
		LootentityList.clear();
		LootentityList = tmpList;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
				    }
				   
SETTINGS Settings = { 0 };

namespace SettingsHelper {
	VOID SaveSettings() {
		CHAR path[0xFF];
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, ("fnambt.settings"));

		auto file = fopen(path, ("wb"));
		if (file) {
			fwrite(&Settings, sizeof(Settings), 1, file);
			fclose(file);
		}
	}
	
				    
void SetWindowToTarget()
{
    const char* wnd_str = xorstr_("UnrealWindow");
    GameWnd = FindWindow(wnd_str, 0);
    RtlSecureZeroMemory(&wnd_str, sizeof(wnd_str));
    ZeroMemory(&GameRect, sizeof(GameRect));
    GetWindowRect(GameWnd, &GameRect);
    Width = GameRect.right - GameRect.left;
    Height = GameRect.bottom - GameRect.top;
    DWORD dwStyle = GetWindowLong(GameWnd, GWL_STYLE);
    if (dwStyle & WS_BORDER)
    {
        GameRect.top += 32;
        Height -= 39;
    }
    ScreenCenterX = Width / 2;
    ScreenCenterY = Height / 2;
}

void ASCDAVSDFASCXD()
{
    while (!GetModuleHandleA(xorstr_("d3d9.dll"))) {
        Sleep(1);
    }
    std::string yey = gen_random(12);
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
	
	
 	this->UObjectArray = deref_2;
	this->GetObjectName = GetObjectName;
	this->GetNameByIndex = GetNameByIndex;
	this->FnFree = FnFree;ON);
	
	
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(RGB(0, 0, 0));
    wc.lpszMenuName = NULL;
    wc.lpszClassName = yey.c_str();
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    if (!RegisterClassEx(&wc))
        exit(1);
    SetWindowToTarget();
    MyWnd = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_TOPMOST,
        yey.c_str(),
        gen_random(8).c_str(),//""
        WS_POPUP | WS_VISIBLE,
        GameRect.left, GameRect.top, Width, Height,
	    
					auto Property_FName = *(FName*)(Property + 0x28);
					auto Offset = *(DWORD*)(Property + 0x4C);
}
}
				    return true;
				    }
				    
				    
				    
 char* FortUpdater::fGetNameByIndex(int Index)
{
	if (Index == 0) return (char*)"";

	auto fGetNameByIdx = reinterpret_cast<FString * (__fastcall*)(int*, FString*)>(this->GetNameByIndex);

	FString result;
	fGetNameByIdx(&Index, &result);

	if (result.c_str() == NULL) return (char*)"";

	auto tmp = result.ToString();

	char return_string[1024];
	memcpy(return_string, std::string(tmp.begin(), tmp.end()).c_str(), 1024);

	FreeObjName((uintptr_t)result.c_str());

	char* PropertyName = this->fGetNameByIndex(Property_idx);


	return return_string;
}
