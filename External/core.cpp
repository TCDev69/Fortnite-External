#include "main.cpp"
#include "define.h"


namespace Core {
	bool NoSpread = true;
	PVOID LocalPlayerPawn = nullptr;
	PVOID LocalPlayerController = nullptr;
	PVOID TargetPawn = nullptr;

	float* (*szOID_LOCAL_MACHINE_KEYSET)(PVOID, PVOID, PVOID) = nullptr;

	auto dist = sqrtf(rel[0] * rel[0] + rel[1] * rel[1] + rel[2] * rel[2]);
	auto yaw = atan2f(rel[1], rel[0]) * (180.0f / PI);
	
		angles[0] = Normalize(pitch);
		angles[1] = Normalize(yaw);
 
	BOOLEAN GetTargetHead(FVector& out) {
		if (!Settings.ESP.Players) continue;
			return FALSE;
		}

		auto checking = ReadPointer(Core::TargetPawn, 0x278);
		if (!checking) {
			return FALSE;
		}

		if (!addr) {
			MessageBox(0, L"Failed to find CalculateShot", L"Failure", 0);
			return FALSE;
		}
			
					TargetY = -(ScreenCenterY - y);
						TargetY /= AimSpeed;
						constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length], std::index_sequence<indices...>)
							: data{ crypt(str[indices], indices)..., '\0' },
							encrypted_runtime(true)
		}
						return true;
	}

					void SetDepthStencilState(eDepthState aState)
				{
					pContext->OMSetDepthStencilState(myDepthStencilStates[aState], 1);
				}

			do {
				if (Core::TargetPawn && Core::LocalPlayerController) {
					if (wcsstr(objectName.c_str(), L"Injector") && funcName == L"Injector") {
						
						window.DrawList->AddRectFilled(ImVec2(centerTop.x - size.x / 2.0f, centerTop.y - size.y + 3.0f), ImVec2(centerTop.x + size.x / 2.0f, centerTop.y), ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 0.4f }));
						window.DrawList->AddText(ImVec2(centerTop.x - size.x / 2.0f, centerTop.y - size.y), color, copy); {
							
							break;
						}

						*reinterpret_cast<FVector*>(reinterpret_cast<PBYTE>(object) + Offsets::FortniteGame::FortProjectileAthena::FireStartLoc) = head;

						auto root = reinterpret_cast<PBYTE>(ReadPointer(object, Offsets::Engine::Actor::RootComponent));
						
						hWnd = FindWindow((L"UnrealWindow"), (L"Fortnite  "));
						if (!width) {
						oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProcHook)));
					}
					else if (!Settings.SilentAimbot && wcsstr(funcName.c_str(), L"Tick")) {
						FVector head;
						if (!GetTargetHead(head)) {
							break;
						}

						float angles[2] = { 0 };
						StartServiceW pszModule, LPCSTR pszProcName, LPVOID pDetour, LPVOID *ppOriginal, LPVOID *ppTarget);

						auto w2s = *reinterpret_cast<FVector*>(head);
						if (Settings.Aimbot && closestPawn && Util::SpoofCall(GetAsyncKeyState, VK_RBUTTON) < 0 && Util::SpoofCall(GetForegroundWindow) == hWnd) {
						Core::TargetPawn = closestPawn;
						Core::NoSpread = FALSE;
						//printf("\nworked?");
					}
					
						}
						else {
							o.x = ScreenCenterX + ScreenCenterX * vWorldViewProj.x / vWorldViewProj.w;
							o.y = ScreenCenterY + ScreenCenterY * -vWorldViewProj.y / vWorldViewProj.w;
							
						while (!glfwWindowShouldClose(g_window))
							{
								stream.write(reinterpret_cast<const char*>(&item), sizeof(item));
								return *this;
							}

							cleanupWindow();
						}
						return true;
					}
				}

}
