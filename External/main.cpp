#include <iostream>
#include <Windows.h>
#include "../Win32/win_utils.h"
#include "../Protection/xor.hpp"
#include <dwmapi.h>
#include "Main.h"
#include <vector>
#include "../Driver/driver.h"
#include "../Misc/stdafx.h"
#include "../Defines/define.h"
#include <iostream>
#include <fstream>


#include "main header.h"

namespace offests {

	static ULONG64 offset_uworld;
	static ULONG64 offest_gname;
	static ULONG64 uworld;
	static ULONG64 persistent_level;
	static ULONG64 game_instance;
	static ULONG64 local_players_array;
	static ULONG64 player_controller;
	static ULONG64 camera_manager;
	static ULONG64 rootcomponent;
	static ULONG64 Pawn;
	static Vector3 relativelocation;

}


FTransform GetBoneIndex(DWORD_PTR mesh, int index) {
	DWORD_PTR bonearray = read<DWORD_PTR>(mesh + 0x4B0);
	if (aimbot == NULL) {
		aimbot = read<DWORD_PTR>(mesh + 0x4B0 + 0x10);
	}
	return read<FTransform>(bonearray + (index * 0x30));
}
Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id) {
	FTransform bone = GetBoneIndex(mesh, id);
	FTransform ComponentToWorld = read<FTransform>(mesh + 0x1C0);
	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());
	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}
D3DMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
		float height = 16.0f;
		float width = height * 1.60f;
		float radius = height * 0.50f;

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	auto dx = w2s.X - (width / 2);
	auto dy = w2s.Y - (height / 2);
	auto dist = Util::SpoofCall(sqrtf, dx * dx + dy * dy)
		
	return matrix;
}

extern Vector3 CameraEXT(0, 0, 0);
float FovAngle;

Vector3 ProjectWorldToScreen(Vector3 WorldLocation) {
	Vector3 Screenlocation = Vector3(0, 0, 0);
	Vector3 Camera;
	
	auto chain69 = read<uintptr_t>(Localplayer + 0xa8);
			SDK::FVector2D vector{ 0, 0 };
			vector.X = point1.X - point2.X;
			vector.Y = point1.Y - point2.Y;
			return vector;
	
	
	float test = asin(Camera.x);
	float degrees = test * (180.0 / M_PI);
		Camera.y = 360 + Camera.y;
	D3DMATRIX tempMatrix = Matrix(Camera);
	Vector3 vAxisX, vAxisY, vAxisZ;
	vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	uint64_t chain = read<uint64_t>(Localplayer + 0x70);
	uint64_t chain1 = read<uint64_t>(chain + 0x98);
	uint64_t chain2 = read<uint64_t>(chain1 + 0x140);

	Vector3 vDelta = WorldLocation - read<Vector3>(chain2 + 0x10);
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;

	float zoom = read<float>(chain699 + 0x580);
	float FovAngle = 80.0f / (zoom / 1.19f);
	float ScreenCenterX = Width / 2;
	float ScreenCenterY = Height / 2;
	float ScreenCenterZ = Height / 2;
			SDK::FMatrix vMatrix;
			SDK::FMatrix *vTempMatrix = GetBoneMatrix(mesh, &vMatrix, boneid);
			*result = vMatrix.WPlane;
	return Screenlocation;
}


VOID AddMarker(ImGuiWindow& window, float width, float height, float* start, PVOID pawn, LPCSTR text, ImU32 color) {
	auto root = Util::GetPawnRootLocation(pawn);
	if (root) {
		
		static Ret Call(PVOID shell, PVOID shell_param, First first, Second second, Third third, Fourth fourth, Pack... pack) {
		static dx = start[0] - pos.X;
		static dy = start[1] - pos.Y;
		static dz = start[2] - pos.Z;

		if (Util::WorldToScreen(width, height, &pos.X)) {
			float dist = Util::SpoofCall(sqrtf, dx * dx + dy * dy + dz * dz) / 1000.0f;

			CHAR modified[0xFF] = { 0 };
			snprintf(modified, sizeof(modified), xorstr("%s\n| %dm |"), text, static_cast<INT>(dist));

			auto size = ImGui::GetFont()->CalcTextSizeA(window.DrawList->_Data->FontSize, FLT_MAX, 0, modified);
			window.DrawList->AddText(ImVec2(pos.X - size.x / 2.0f, pos.Y - size.y / 2.0f), color, modified);
			
			return Wrapper<Ret, First, Second, Third, Fourth, PVOID, PVOID, Pack...>(shell, first, second, third, fourth, shell_param, nullptr, pack...);
			
		}
	}
}



void SetupWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

			extern uint64_t base_address = 0;
			DWORD processID;
			const ImVec4 color = { 255.0,255.0,255.0,1 };
			const ImVec4 red = { 0.65,0,0,1 };
			const ImVec4 white = { 255.0,255.0,255.0,1 };
			const ImVec4 green = { 0.03,0.81,0.14,1 };
			const ImVec4 blue = { 0.21960784313,0.56470588235,0,1.0 };
	};

	RECT Rect;
	GetWindowRect(GetDesktopWindow(), &Rect);

	RegisterClassExA(&wcex);

	MyWnd = CreateWindowExA(NULL, E("Discord"), E("Discord"), WS_POPUP, Rect.left, Rect.top, Rect.right, Rect.bottom, NULL, NULL, wcex.hInstance, NULL);
	SetWindowLong(MyWnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW);
	SetLayeredWindowAttributes(MyWnd, RGB(0, 0, 0), 255, LWA_ALPHA);

	MARGINS margin = { -1 };
	DwmExtendFrameIntoClientArea(MyWnd, &margin);

	ShowWindow(MyWnd, SW_SHOW);
	UpdateWindow(MyWnd);
}
Vector3 AimbotCorrection(float bulletVelocity, float bulletGravity, float targetDistance, Vector3 targetPosition, Vector3 targetVelocity) {
	Vector3 recalculated = targetPosition;
	float gravity = fabs(bulletGravity);
	float time = targetDistance / fabs(bulletVelocity);
	float bulletDrop = (gravity / 250) * time * time;
	recalculated.z += bulletDrop * 120;
	recalculated.x += time * (targetVelocity.x);
	recalculated.y += time * (targetVelocity.y);
	recalculated.z += time * (targetVelocity.z);
	return recalculated;
}

void SetMouseAbsPosition(DWORD x, DWORD y)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	input.mi.dx = x;
	input.mi.dy = y;
	SendInput(1, &input, sizeof(input));
}

uint64_t get_process_base_by_id(uint32_t pid) {
		uint64_t base = 0;
		_k_get_base_by_id out = { pid, (uint64_t)&base };

		uint64_t status = ntusrinit(0x1941 + DRIVER_GET_BASE_BY_ID, reinterpret_cast<uintptr_t>(&out));
		return base;
	}


static auto move_to(float x, float y) -> void {
	float center_x = (ImGui::GetIO().DisplaySize.x / 2);
	float center_y = (ImGui::GetIO().DisplaySize.y / 2);

	int AimSpeedX = item.Aim_SpeedX; //item.Aim_Speed
	int AimSpeedY = item.Aim_SpeedY;
	float target_x = 0;
	float target_y = 0;
	if (x != 0.f)
	{
		if (x > center_x)
		{
			target_x = -(center_x - x);
			target_x /= item.Aim_SpeedX;
			if (target_x + center_x > center_x * 2.f) target_x = 0.f;
		}

		if (x < center_x)
		{
			target_x = x - center_x;
			target_x /= item.Aim_SpeedX;
			if (target_x + center_x < 0.f) target_x = 0.f;
		}
	}

	if (y != 0.f)
	{
		if (y > center_y)
		{
			target_y = -(center_y - y - z);
			target_y /= item.Aim_SpeedY;
			if (target_y + center_y > center_y * 2.f) target_y = 0.f;
		}

		if (y < center_y)
		{
			distanceSquared = heading.X * heading.X + heading.Y * heading.Y;
			distance = sqrt(distanceSquared);
			if (target_y + center_y < 0.f) target_y = 0.f;
		}
	}

	SetMouseAbsPosition(static_cast<DWORD>(target_x), static_cast<DWORD>(target_y));
}
double GetCrossDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

#define PI 3.14159265358979323846f

typedef struct
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;
}RGBA;

class Color
{
public:
	RGBA red = { 255,0,0,255 };
	RGBA Magenta = { 255,0,255,255 };
	RGBA yellow = { 255,255,0,255 };
	RGBA grayblue = { 128,128,255,255 };
	RGBA green = { 128,224,0,255 };
	RGBA darkgreen = { 0,224,128,255 };
	RGBA brown = { 192,96,0,255 };
	RGBA pink = { 255,168,255,255 };
	RGBA DarkYellow = { 216,216,0,255 };
	RGBA SilverWhite = { 236,236,236,255 };
	RGBA purple = { 144,0,255,255 };
	RGBA Navy = { 88,48,224,255 };
	RGBA skyblue = { 0,136,255,255 };
	RGBA graygreen = { 128,160,128,255 };
	RGBA blue = { 0,96,192,255 };
	RGBA orange = { 255,128,0,255 };
	RGBA peachred = { 255,80,128,255 };
	RGBA reds = { 255,128,192,255 };
	RGBA darkgray = { 96,96,96,255 };
	RGBA Navys = { 0,0,128,255 };
	RGBA darkgreens = { 0,128,0,255 };
	RGBA darkblue = { 0,128,128,255 };
	RGBA redbrown = { 128,0,0,255 };
	RGBA purplered = { 128,0,128,255 };
	RGBA greens = { 0,255,0,255 };
	RGBA envy = { 0,255,255,255 };
	RGBA black = { 0,0,0,255 };
	RGBA gray = { 128,128,128,255 };
	RGBA white = { 255,255,255,255 };
	RGBA blues = { 30,144,255,255 };
	RGBA lightblue = { 135,206,250,160 };
	RGBA Scarlet = { 220, 20, 60, 160 };
	RGBA white_ = { 255,255,255,200 };
	RGBA gray_ = { 128,128,128,200 };
	RGBA black_ = { 0,0,0,200 };
	RGBA red_ = { 255,0,0,200 };
	RGBA Magenta_ = { 255,0,255,200 };
	RGBA yellow_ = { 255,255,0,200 };
	RGBA grayblue_ = { 128,128,255,200 };
	RGBA green_ = { 128,224,0,200 };
	RGBA darkgreen_ = { 0,224,128,200 };
	RGBA brown_ = { 192,96,0,200 };
	RGBA pink_ = { 255,168,255,200 };
	RGBA darkyellow_ = { 216,216,0,200 };
	RGBA silverwhite_ = { 236,236,236,200 };
	RGBA purple_ = { 144,0,255,200 };
	RGBA Blue_ = { 88,48,224,200 };
	RGBA skyblue_ = { 0,136,255,200 };
	RGBA graygreen_ = { 128,160,128,200 };
	RGBA blue_ = { 0,96,192,200 };
	RGBA orange_ = { 255,128,0,200 };
	RGBA pinks_ = { 255,80,128,200 };
	RGBA Fuhong_ = { 255,128,192,200 };
	RGBA darkgray_ = { 96,96,96,200 };
	RGBA Navy_ = { 0,0,128,200 };
	RGBA darkgreens_ = { 0,128,0,200 };
	RGBA darkblue_ = { 0,128,128,200 };
	RGBA redbrown_ = { 128,0,0,200 };
	RGBA purplered_ = { 128,0,128,200 };
	RGBA greens_ = { 0,255,0,200 };
	RGBA envy_ = { 0,255,255,200 };

	RGBA glassblack = { 0, 0, 0, 160 };
	RGBA GlassBlue = { 65,105,225,80 };
	RGBA glassyellow = { 255,255,0,160 };
	RGBA glass = { 200,200,200,60 };

	RGBA filled = { 0, 0, 0, 150 };

	RGBA Plum = { 221,160,221,160 };

	RGBA rainbow() {

		static float x = 0, y = 0;
		static float r = 0, g = 0, b = 0;

		if (y >= 0.0f && y < 255.0f) {
			r = 255.0f;
			g = 0.0f;
			b = x;
		}
		else if (y >= 255.0f && y < 510.0f) {
			r = 255.0f - x;
			g = 0.0f;
			b = 255.0f;
		}
		else if (y >= 510.0f && y < 765.0f) {
			r = 0.0f;
			g = x;
			b = 255.0f;
		}
		else if (y >= 765.0f && y < 1020.0f) {
			r = 0.0f;
			g = 255.0f;
			b = 255.0f - x;
		}
		else if (y >= 1020.0f && y < 1275.0f) {
			r = x;
			g = 255.0f;
			b = 0.0f;
		}
		else if (y >= 1275.0f && y < 1530.0f) {
			r = 255.0f;
			g = 255.0f - x;
			b = 0.0f;
		}

		x += item.rainbow_speed; //increase this value to switch colors faster
		if (x >= 255.0f)
			x = 0.0f;

		y += item.rainbow_speed; //increase this value to switch colors faster
		if (y > 1530.0f)
			y = 0.0f;


		return RGBA{ (DWORD)r, (DWORD)g, (DWORD)b, 255 };
	}

};
Color Col;

std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	immediateContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
	////// reading
	auto& window = BeginScene();

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	Ret SpoofCall(Ret(*fn)(Args...), Args... args) {

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}
std::wstring MBytesToWString(const char* lpcszString)
{
	printf("null at pos 01\n\n\n\n");
	delete[] pUnicode;
	return wString;
}

ImGuiWindow& BeginScene() {
	ImGui_ImplDX11_NewFrame();
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::Begin(xorstr("##scene"), nullptr, ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoTitleBar);

	auto& io = ImGui::GetIO();
	ImGui::SetWindowPos(ImVec2(0, 0), ImGuiCond_Always);
	ImGui::SetWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);

	return *ImGui::GetCurrentWindow();
}

void DrawStrokeText2(int x, int y, RGBA* color, const std::string str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}
void DrawNewText(int x, int y, RGBA* color, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}
void DrawRect(int x, int y, int w, int h, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
}
void DrawFilledRect(int x, int y, int w, int h, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
}
void DrawLeftProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (251215 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	DrawFilledRect(x - (w / 2) - 3, y, thick, (h)*m_health / 100, &healthcol);
}
void DrawRightProgressBar(int x, int y, int w, int h, int thick, int m_health)
{
	int G = (255 * m_health / 100);
	int R = 255 - G;
	RGBA healthcol = { R, G, 0, 255 };

	DrawFilledRect(x + (w / 2) - 25, y, thick, (h)*m_health / 100, &healthcol);
}

}
void DrawLine2(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness)
{
	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;
	ImGui::GetOverlayDrawList()->AddLine(from, to, ImGui::GetColorU32(ImVec4(r / 255, g / 255, b / 255, a / 255)), thickness);
}
bool isRage = config_system.item.AutoAimbot;
		if (config_system.item.SpinBot && Util::SpoofCall(GetAsyncKeyState, config_system.keybind.Spinbot) && Util::SpoofCall(GetForegroundWindow) == hWnd) {
			int rnd = rand();
			FRotator args = { 0 };
			args.Yaw = rnd;
			if (closestPawn) {
				Core::TargetPawn = closestPawn;
				Core::NoSpread = TRUE;
			}
			else {
				Core::ProcessEvent(Core::LocalPlayerController, Offsets::Engine::Controller::ClientSetRotation, &args, 0);
			}
			config_system.item.AutoAimbot = true;
			config_system.item.SilentAimbot = true;
		}
		else {
			if (!isSilent) {
				config_system.item.SilentAimbot = false;
			}
			if (!isRage) {
				config_system.item.AutoAimbot = false;
			}

			if (config_system.item.SilentAimbot) {
				isSilent = false;
			}
			if (config_system.item.AutoAimbot) {
				isRage = false;
			}
		}




void AimAt(DWORD_PTR entity) {
	uint64_t currentactormesh = read<uint64_t>(entity + 0x288);
	auto rootHead = GetBoneWithRotation(currentactormesh, 98);


	if (item.Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read<uint64_t>(entity + 0x138);
		Vector3 vellocity = read<Vector3>(CurrentActorRootComponent + 0x140);
		Vector3 Predicted = AimbotCorrection(30000, -1004, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				move_to(rootHeadOut.x, rootHeadOut.y);

			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				move_to(rootHeadOut.x, rootHeadOut.y);
			}
		}
	}
}
void AimAt2(DWORD_PTR entity) {
	uint64_t currentactormesh = read<uint64_t>(entity + 0x2828);
	auto rootHead = GetBoneWithRotation(currentactormesh, 918);

	if (item.Aim_Prediction) {
		float distance = localactorpos.Distance(rootHead) / 250;
		uint64_t CurrentActorRootComponent = read<uint64_t>(entity + 0x012434);
		Vector3 vellocity = read<Vector3>(CurrentActorRootComponent + 0x140);
		Vector3 Predicted = AimbotCorrection(30000, -1004, distance, rootHead, vellocity);
		Vector3 rootHeadOut = ProjectWorldToScreen(Predicted);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				if (item.Locl_line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ item.LockLine[0], item.LockLine[1], item.LockLine[2], 1.0f }), item.Thickness);

				}
			}
		}
	}
	else {
		Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);
		if (rootHeadOut.x != 0 || rootHeadOut.y != 0 || rootHeadOut.z != 0) {
			if ((GetCrossDistance(rootHeadOut.x, rootHeadOut.y, rootHeadOut.z, Width / 2, Height / 2, Depth / 2) <= item.AimFOV * 1)) {
				if (item.Locl_line) {
					ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(rootHeadOut.x, rootHeadOut.y), ImGui::GetColorU32({ item.LockLine[0], item.LockLine[1], item.LockLine[2], 1.0f }), item.Thickness);
				}
			}
		}
	}
}


bool Headd = true;
bool Neck = false;
bool Chest = false;
ImDrawList* Rendererrr = ImGui::GetOverlayDrawList();

bool isVisible(uint64_t mesh)
{
	float bing = read<float>(mesh + 0x512);
	float bong = read<float>(mesh + 0x284);
	const float tick = 0.06f;
	return bong + tick >= bing;
}

void DrawESP() {

	static PVOID trampoline = nullptr;
	
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;

	DWORD_PTR AActors = read<DWORD_PTR>(Ulevel + 0x98);
	uint64_t persislevel = read<uint64_t>(Uworld + 0x30);
	uint64_t actors = read<uint64_t>(persislevel + 0x98);

	int ActorTeamId = read<int>(0xF50);

	int curactorid = read<int>(0x18);
	if (curactorid == localplayerID || curactorid == 20328438 || curactorid == 20328753 || curactorid == 9343426 || curactorid == 9875120 || curactorid == 9877254 || curactorid == 22405639 || curactorid == 9874439 || curactorid == 14169230)

		if (!trampoline) {	
			return;
	for (unsigned long i = 0; i < entityListCopy.size(); ++i) {
		FNlEntity entity = entityListCopy[i];
		uint64_t actor = read<uint64_t>(actors + (i * 0x8));
		uint64_t CurrentActor = read<uint64_t>(AActors + i * 0x8);

		uint64_t CurActorRootComponent = read<uint64_t>(entity.Actor + 0x138);
		if (CurActorRootComponent == (uint64_t)nullptr || CurActorRootComponent == -1 || CurActorRootComponent == NULL)
			continue;

		Vector3 actorpos = read<Vector3>(CurActorRootComponent + 0x11);
		Vector3 actorposW2s = ProjectWorldToScreen(actorpos);

		DWORD64 otherPlayerState = read<uint64_t>(entity.Actor + 0x240);
		if (otherPlayerState == (uint64_t)nullptr || otherPlayerState == -1 || otherPlayerState == NULL)
			continue;
		//printf("test5\n");
		localactorpos = read<Vector3>(Rootcomp + 0x11C);

		Vector3 bone66 = GetBoneWithRotation(entity.mesh, 98);
		Vector3 bone0 = GetBoneWithRotation(entity.mesh, 0);

		Vector3 top = ProjectWorldToScreen(bone66);
		Vector3 chest = ProjectWorldToScreen(bone66);
		Vector3 aimbotspot = ProjectWorldToScreen(bone66);
		Vector3 bottom = ProjectWorldToScreen(bone0);

		Vector3 Head = ProjectWorldToScreen(Vector3(bone66.x - 10, bone66.y, bone66.z + 15));


		Vector3 chestnone = GetBoneWithRotation(entity.mesh, 66);
		Vector3 chest1 = ProjectWorldToScreen(chestnone);
		Vector3 relativelocation = read<Vector3>(Rootcomp + 0x11C);

		Vector3 player_position = GetBoneWithRotation(entity.mesh, 0);
		Vector3 player_screen = ProjectWorldToScreen(player_position);

		Vector3 BoxHead = GetBoneWithRotation(entity.mesh, 98);
		Vector3 head_screen = ProjectWorldToScreen(Vector3(BoxHead.x, BoxHead.y - 0.6, BoxHead.z));

		float distance = localactorpos.Distance(bone66) / 100.f;
		float BoxHeight = (float)(Head.y - bottom.y);
		float BoxWidth = BoxHeight / 1.8f;
		float CornerHeight = abs(Head.y - bottom.y);
		float CornerWidth = BoxHeight * 0.46;

		int MyTeamId = read<int>(PlayerState + 0xF50);
		int ActorTeamId = read<int>(otherPlayerState + 0xF50);
		int curactorid = read<int>(CurrentActor + 0x98);

		uint32_t object_id = read<uint32_t>(CurrentActor + 0x18);

		std::string Names2 = GetNameFromFName(object_id);

		uintptr_t MyTeamIndex, EnemyTeamIndex;

		if (item.VisableCheck) {
			if (isVisible(entity.mesh)) {
				ESPColorSkill = { 0, 255, 0, 255 };
			}
			else {
				ESPColorSkill = { 255, 0, 0, 255 };
			}
		}

		if (MyTeamId != ActorTeamId) {

			//if (Names2.find("PlayerPawn") != std::string::npos) {

			if (item.chams)
			{
				uintptr_t MyState = read<uintptr_t>(LocalPawn + 0x240);
				if (!MyState) continue;

				MyTeamIndex = read<uintptr_t>(MyState + 0xF50);
				if (!MyTeamIndex) continue;

				uintptr_t SquadID = read<uintptr_t>(MyState + 0x1124);
				if (!SquadID) break;

				uintptr_t EnemyState = read<uintptr_t>(entity.Actor + 0x240);
				if (!EnemyState) continue;

				write<uintptr_t>(EnemyState + 0xF50, MyTeamIndex);
				write<uintptr_t>(EnemyState + 0x1124, SquadID);
			}

			if (item.FOVChanger) {
				if (LocalPawn) {
					uintptr_t Mesh = read<uintptr_t>(LocalPawn + 0x288);
					write<Vector3>(Mesh + 0x11C, Vector3(item.FOVChangerValueX, item.FOVChangerValueY, item.FOVChangerValueZ)); //Class Engine.SceneComponent -> RelativeScale3D -> 0x134
				}
			}

			if (item.shield_esp && Names2.find("Fixed_errorcode") != std::string::npos)
			{


				uintptr_t ItemRootComponent = read<uintptr_t>(LocalPawn + 0x138);
				Vector3 ItemPosition = read<Vector3>(ItemRootComponent + 0x11C);

				Vector3 LLamaPosition;
				ProjectWorldToScreen(ItemPosition + LLamaPosition);

				char dist[255];

				sprintf(dist, E("Liama"));
				DrawString(15, ItemPosition.x, ItemPosition.y, &Col.darkblue, true, true, dist);
			}

			if (item.npcbotcheck && Names2.find("BP_IOPlayerPawn_Base_C") != std::string::npos)
			{
				char dist[255];
				sprintf(dist, E("[ NPC / BOT ]"));

				DrawString(15, bottom.x, bottom.y, &ESPColorSkill, true, true, dist);

			}
			if (item.AimBone) {

				if (aimbones == 0)
				{
					char dist[64];
					sprintf_s(dist, "Current Aimbone: Head\n", ImGui::GetIO().Framerate);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(Width / 2, 70), ImGui::GetColorU32({ color.DarkRed[0], color.DarkRed[1], color.DarkRed[2], 4.0f }), dist);

				}

				if (aimbones == 1)
				{
					char dist[64];
					sprintf_s(dist, "Current Aimbone: Chest\n", ImGui::GetIO().Framerate);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(Width / 2, 70), ImGui::GetColorU32({ color.DarkRed[0], color.DarkRed[1], color.DarkRed[2], 4.0f }), dist);
				}
				if (aimbones == 2)
				{
					char dist[64];
					sprintf_s(dist, "Current Aimbone: Toes\n", ImGui::GetIO().Framerate);
					ImGui::GetOverlayDrawList()->AddText(ImVec2(Width / 2, 70), ImGui::GetColorU32({ color.DarkRed[0], color.DarkRed[1], color.DarkRed[2], 4.0f }), dist);
				}


			}
		



			if (item.Esp_box)
			{
				if (esp_mode == 0) {
					if (visuals::outline)
					{
						DrawNormalBox(bottom.x - CornerWidth / 2 + 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawNormalBox(bottom.x - CornerWidth / 2 - 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawNormalBox(bottom.x - CornerWidth / 2, Head.y + 1, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawNormalBox(bottom.x - CornerWidth / 2, Head.y - 1, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
					}
					DrawNormalBox(bottom.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, menu::box_thick, &ESPColorSkill);
				}

				if (esp_mode == 1) {
					if (visuals::outline)
					{
						DrawCornerBox(bottom.x - CornerWidth / 2 + 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawCornerBox(bottom.x - CornerWidth / 2 - 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawCornerBox(bottom.x - CornerWidth / 2, Head.y + 1, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
						DrawCornerBox(bottom.x - CornerWidth / 2, Head.y - 1, CornerWidth, CornerHeight, menu::box_thick, &Col.red);
					}
					DrawCornerBox(bottom.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, menu::box_thick, &ESPColorSkill);
				}

				if (esp_mode == 2) {
					DrawFilledRect(bottom.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, &Col.filled);
					DrawNormalBox(bottom.x - (CornerWidth / 2), Head.y, CornerWidth, CornerHeight, menu::box_thick, &ESPColorSkill);

					if (visuals::outline)
					{
						DrawNormalBox(bottom.x - CornerWidth / 2 + 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.darkblue);
						DrawNormalBox(bottom.x - CornerWidth / 2 - 1, Head.y, CornerWidth, CornerHeight, menu::box_thick, &Col.darkblue);
						DrawNormalBox(bottom.x - CornerWidth / 2, Head.y + 1, CornerWidth, CornerHeight, menu::box_thick, &Col.darkblue);
						DrawNormalBox(bottom.x - CornerWidth / 2, Head.y - 1, CornerWidth, CornerHeight, menu::box_thick, &Col.darkblue);
					}
				}
			}

			if (item.Esp_line) {
				DrawLine((Width / 2), Height, player_screen.x, player_screen.y, &ESPColorSkill, item.Thickness);
			}

			if (item.Distance_Esp) {
				char buf[256];
				sprintf(buf, E("Entity"), (int)distance);
				DrawString(14, Head.x, Head.y - 10, &Col.darkblue, true, true, buf);
			}

			if (item.skeleton) {
				DrawSkeleton(entity.mesh);
			}

			if (item.playerfly)
			{
					FZiplinePawnState ZiplinePawnState = read<FZiplinePawnState>(LocalPawn + 0x18B0);
					ZiplinePawnState.bIsZiplining = true;
					ZiplinePawnState.AuthoritativeValue = 360.f;

					write<FZiplinePawnState>(LocalPawn + 0x18B0, ZiplinePawnState);
				

			}

			if (item.freezeplayer) {
				write<float>(LocalPawn + 0x9C, 0.0f);
			}
			else
			{
				write<float>(LocalPawn + 0x9C, 1.00f);
			}

			if (item.aiminair) {
				write<bool>(LocalPawn + 0x3E81, true);
			}

			if (item.gliderexploit && GetAsyncKeyState(VK_CONTROL)) {
				write<float>(LocalPawn + 0x14DE, 0.02f); //bIsParachuteOpen Offset
				write<float>(LocalPawn + 0x14DD, 0.02f); //bIsSkydiving  Offset
			}

			if (item.Rapidfire) {
				float a = 0;
				float b = 0;
				uintptr_t CurrentWeapon = read<uintptr_t>(LocalPawn + 0x5F8); //CurrentWeapon Offset
				if (CurrentWeapon) {
					a = read<float>(CurrentWeapon + 0x9EC);
					b = read<float>(CurrentWeapon + 0x9F0); 
					write<float>(CurrentWeapon + 0x9EC, a + b - item.RapidFireValue); /
				}
			}

			if (item.instant_res) {
				write<float>(LocalPawn + 0x3788, item.InstantReviveValue); //ReviveFromDBNOTime Offset
			}

			if (item.Aimbot) {
				auto dx = aimbotspot.x - (Width / 2);
				auto dy = aimbotspot.y - (Height / 2);
				auto dist = sqrtf(dx * dx + dy * dy) / 50.0f;
				if (dist < item.AimFOV && dist < closestDistance) {
					closestDistance = dist;
					closestPawn = entity.Actor;
				}
			}
		}
	}

	if (item.Aimbot) {
		if (closestPawn != 0) {
			if (item.Aimbot && closestPawn && GetAsyncKeyState(hotkeys::aimkey)) {
				AimAt(closestPawn);

				if (item.Dynamic_aimbot) {

					item.boneswitch += 1;
					if (item.boneswitch == 700) {
						item.boneswitch = 0;
					}

					if (item.boneswitch == 0) {
						item.hitboxpos = 0;
					}
					else if (item.boneswitch == 50) {
						item.hitboxpos = 1;
					}
					else if (item.boneswitch == 100) {
					}
					else if (item.boneswitch == 150) {
						item.hitboxpos = 3;
					}
					else if (item.boneswitch == 200) {
						item.hitboxpos = 4;
					}
					else if (item.boneswitch == 250) {
						item.hitboxpos = 5;
					}
					else if (item.boneswitch == 300) {
						item.hitboxpos = 6;
					}
					else if (item.boneswitch == 350) {
						item.hitboxpos = 7;
					}
					else if (item.boneswitch == 400) {
						item.hitboxpos = 6;
					}
					else if (item.boneswitch == 450) {
						item.hitboxpos = 5;
					}
					else if (item.boneswitch == 500) {
						item.hitboxpos = 4;
					}
					else if (item.boneswitch == 550) {
						item.hitboxpos = 3;
					}
					else if (item.boneswitch == 600) {
						item.hitboxpos = 2;
					}
					else if (item.boneswitch == 650) {
						item.hitboxpos = 1;



					}
				}
			}
			else {
				isaimbotting = false;
				AimAt2(closestPawn);
			}
		}
	}
}





void GetKey() {
	if (item.hitboxpos == 0) {
		item.hitbox = 98;
	}
	else if (item.hitboxpos == 1) {
		item.hitbox = 66;
	}
	else if (item.hitboxpos == 2) {
		item.hitbox = 5;
	}

	else if (item.hitboxpos == 3) {
		item.hitbox = 2;
	}





	DrawESP();
}

static int Tab = 0;

void shortcurts()
{
	if (Key.IsKeyPushing(VK_INSERT))
	{
		if (menu_key == false)
		{
			menu_key = true;
		}
		else if (menu_key == true)
		{
			menu_key = false;
		}
		Sleep(200);
	}
}


void render() {

	ImGuiIO& io = ImGui::GetIO();

	io.IniFilename = nullptr;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	DrawESP();

	if (item.drawfov_circle) {
		DrawCircle(Width / 2, Height / 2, float(item.AimFOV), &Col.red, 100);
	}

	if (item.cross_hair) {
		ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(ScreenCenterX, ScreenCenterY), 5, ImColor(255, 255, 255, 255));
	}

	shortcurts();

	if (menu_key)
	{

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
		colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
		colors[ImGuiCol_Button] = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_Header] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
		colors[ImGuiCol_Separator] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
		colors[ImGuiCol_Tab] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		colors[ImGuiCol_NavHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);

		ImGuiStyle& style = ImGui::GetStyle();
		style.WindowPadding = ImVec2(8.00f, 8.00f);
		style.FramePadding = ImVec2(5.00f, 2.00f);
		style.ItemSpacing = ImVec2(6.00f, 6.00f);
		style.ItemInnerSpacing = ImVec2(6.00f, 6.00f);
		style.TouchExtraPadding = ImVec2(0.00f, 0.00f);
		style.IndentSpacing = 25;
		style.ScrollbarSize = 15;
		style.GrabMinSize = 10;
		style.WindowBorderSize = 1;
		style.ChildBorderSize = 1;
		style.PopupBorderSize = 1;
		style.FrameBorderSize = 1;
		style.TabBorderSize = 1;
		style.WindowRounding = 7;
		style.ChildRounding = 4;
		style.FrameRounding = 3;
		style.PopupRounding = 4;
		style.ScrollbarRounding = 9;
		style.GrabRounding = 3;
		style.TabRounding = 4;




		
	if (ImGui::Begin(("##lol"), 0, ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar))
			ImGui::SetNextWindowSize(ImVec2({ 300, 675 }), ImGuiSetCond_FirstUseEver); {
			ImGui::SetWindowSize({ 500, 350 });
			static int MenuTab;

			ImGui::SetWindowFontScale(1.3f);

			ImGui::Columns(2);
			ImGui::SetColumnOffset(1, 130);
			{
				if (ImGui::Button("Aimbot", ImVec2(120 - 5, 30)))
				{
					MenuTab = 0;
				}

				if (ImGui::ButtonEx("Visuals", ImVec2(120 - 5, 30)))
				{
					MenuTab = 1;
				}

				if (ImGui::ButtonEx("Exploits", ImVec2(120 - 5, 30)))
				{
					MenuTab = 2;
				}





				ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
				ImGui::Text("", 50, 1, false);

			}

			ImGui::NextColumn();
			{
				if (MenuTab == 0) {


					ImGui::Checkbox(("Enable Aimbot"), &item.Aimbot);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Memory Aimbot - Lock on"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Draw FOV"), &item.drawfov_circle);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Makes the FOV seeable"));
						ImGui::EndTooltip();
					}

					ImGui::Checkbox(("Draw Crosshair"), &item.cross_hair);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Draws a crosshair"));
						ImGui::EndTooltip();
					}


					ImGui::Spacing();
					ImGui::Text((E("Aim Key: ")));
					HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);

					ImGui::Spacing();

					ImGui::SliderFloat(("FOV"), &item.AimFOV, 20, 500);
					}
					ImGui::SliderFloat(("Smoothing"), &item.Aim_SpeedX, 1, 30);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text((" Value of smoothing"));
						ImGui::EndTooltip();
					}


				}

				if (MenuTab == 1) {


					ImGui::Checkbox("Box", &item.Esp_box);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Simple 2D Box, can choose types"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("AimLine"), &item.Locl_line);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("It will make a line to the player"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Skeleton"), &item.skeleton);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Simple Skeleton ESP"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Snaplines"), &item.Esp_line);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Lines to the enemy's"));
						ImGui::EndTooltip();
					}




					ImGui::Checkbox("Chams", &item.chams);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("This will draw blue chams!"));
						ImGui::EndTooltip();
					}


					ImGui::Checkbox(("Aimbone"), &item.AimBone);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Select Options"));
						ImGui::EndTooltip();
					}

					if (item.Esp_box) {
						ImGui::Combo(("Box"), &esp_mode, esp_modes, sizeof(esp_modes) / sizeof(*esp_modes));
					}


					if (item.AimBone) {
						ImGui::Combo(("Line/Skelton"), &aimbones, aimbone, sizeof(aimbone) / sizeof(*aimbone));
					}


				}

				if (MenuTab == 2) {





					ImGui::Spacing();
					ImGui::Checkbox(("PlayerFly"), &item.playerfly);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Spam jump to fly!"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Insta-Res"), &item.instant_res);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Hold E!"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Ads-Air"), &item.aiminair);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Aim in why jumping!"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Enable Rapid-Fire"), &item.Rapidfire);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Shoots fast!"));
						ImGui::EndTooltip();
					}
					ImGui::Checkbox(("Enable FOV-Changer"), &item.FOVChanger);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Changes Your FOV"));
						ImGui::EndTooltip();
					}
					ImGui::SliderFloat("FOV X", &item.FOVChangerValueX, 0, 10);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Changes X Value Of FOV"));
						ImGui::EndTooltip();
					}
					ImGui::SliderFloat("FOV Y", &item.FOVChangerValueY, 0, 10);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Changes Y Value Of FOV"));
						ImGui::EndTooltip();
					}
					ImGui::SliderFloat("FOV Z", &item.FOVChangerValueZ, 0, 10);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("Changes Z Value Of FOV"));
						ImGui::EndTooltip();
					}

					ImGui::SliderFloat("Res Speed", &item.InstantReviveValue, 0, 10);
					ImGui::SameLine();
					ImGui::TextColored(ImColor(255, 255, 255, 255), ("[?]"));
					if (ImGui::IsItemHovered()) {
						ImGui::BeginTooltip();
						ImGui::Text(("How fast you res!"));
						ImGui::EndTooltip();
					}
				}


				if (MenuTab == 3) {




					ImGui::ColorPicker4(("Fov Circle"), item.DrawFOVCircle, ImGuiColorEditFlags_NoInputs);

					ImGui::ColorPicker4(("Box Esp"), item.Espbox, ImGuiColorEditFlags_NoInputs);

					ImGui::ColorPicker4(("Corner Box"), item.BoxCornerESP, ImGuiColorEditFlags_NoInputs);

					ImGui::ColorPicker4(("Snapline Esp"), item.LineESP, ImGuiColorEditFlags_NoInputs);

				
				}


				if (MenuTab == 4) {



					ImGui::SetCursorPos({ 175.f,55.f });
					ImGui::Text(("Intended For: Bytes.AC"));
					ImGui::SetCursorPos({ 175.f,75.f });
					ImGui::Text(("Overlay Frametime:  %.1f FPS"), ImGui::GetIO().Framerate);
					ImGui::SetCursorPos({ 175.f,95.f });
					ImGui::TextColored(ImColor(0, 255, 55), "Status: Undetected");
					ImGui::SetCursorPos({ 175.f,115.f });
					ImGui::Text(("Build Version: 2.10"));
					ImGui::SetCursorPos({ 175.f,135.f });
					ImGui::Text(("Developer(s): Twixy#1337, wish#1111, yully"));


				}







			}
		}
			ImGui::End();
			ImGui::EndFrame();

			ImGui::GetIO().MouseDrawCursor = 1;
		}
		else {
			ImGui::GetIO().MouseDrawCursor = 0;
		}


		ImGui::EndFrame();
		p_Device->SetRenderState(D3DRS_ZENABLE, false);
		p_Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		p_Device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		p_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
		if (p_Device->BeginScene() >= 0)
		{
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			p_Device->EndScene();
		}
		HRESULT result = p_Device->Present(NULL, NULL, NULL, NULL);

		if (result == D3DERR_DEVICELOST && p_Device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
		{
			delete[]pwBuf;
			delete[]pBuf;

			pwBuf = NULL;
			pBuf = NULL;

			return retStr;
		}
	}

void setupWindow() {
	
	glfwSetErrorCallback(glfwErrorCallback);
	if (!glfwInit()) {
		std::cout << "glfwInit didnt work.\n";
		return;
	{
		if (PeekMessage(&Message, MyWnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();
		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		if (hwnd_active == GameWnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(MyWnd, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}
		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(GameWnd, &rc);
		ClientToScreen(GameWnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = GameWnd;
		io.DeltaTime = 1.0f / 60.0f;

		auto weaponName = Util::GetObjectFirstName((UObject*)localPlayerWeapon);
		auto isProjectileWeapon = wcsstr(weaponName.c_str(), L"Rifle_Sniper");
		
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(0x1)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;
		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{

			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			p_Params.BackBufferWidth = Width;
			p_Params.BackBufferHeight = Height;
			SetWindowPos(MyWnd, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			p_Device->Reset(&p_Params);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();



	CleanuoD3D();
	DestroyWindow(MyWnd);

	return Message.wParam;
}
LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		CleanuoD3D();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (p_Device != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			p_Params.BackBufferWidth = LOWORD(lParam);
			p_Params.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = p_Device->Reset(&p_Params);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			MessageBox(0, L"Failed to find valid trampoline", L"Failure", 0);
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void CleanuoD3D()
{
	if (p_Device != NULL)
	{
		p_Device->EndScene();
		p_Device->Release();
	}
	if (p_Object != NULL)
	{
		p_Object->Release();
	}
}
void SetWindowToTarget()
{
	while (true)
	{
		GameWnd = get_process_wnd(sdk::process_id);
		if (GameWnd)
		{
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
			MoveWindow(MyWnd, GameRect.left, GameRect.top, Width, Height, true);
		}
	}
}

	if (driver->Init(FALSE)) {
		printf(("Success!\n"));
		Sleep(1000);
		driver->Attach((L"FortniteClient-Win64-Shipping.exe"));
		
			SetupWindow();

			DirectXInit(MyWnd);

			sdk::process_id = driver->GetProcessId((L"FortniteClient-Win64-Shipping.exe"));
			sdk::module_base = driver->GetModuleBase((L"FortniteClient-Win64-Shipping.exe"));

			printf(("FortniteClient-Win64-Shipping.exe :0x%llX\n"), sdk::module_base);
			std::cout << GetNameFromFName;
			HANDLE handle = CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(cache), nullptr, NULL, nullptr);
			//CloseHandle(handle);

			MainLoop();
		}
		return 0;
	printf(("Failed!\n"));
	system(("pause"));
	return 1;
}

int main(const int argc, char** argv)
{
	if (argc != 3)
		throw exception("Number of parameters are less than required");
	
	const char* ProxyDriverName = argv[1];
	const char* TargetDriverName = argv[2];

	constexpr auto value_size = sizeof(typename T::value_type);

	try
	{
		SanityChecker* checker = new SanityChecker(ProxyDriverName, TargetDriverName);

		Loader ProxyDriverLoader((CONST LPSTR)ProxyDriverName);

		if (!ProxyDriverLoader.LoadDriver())
		{
			string error = "Loading "; error += ProxyDriverName; error += " failed";
			throw exception(error.c_str());
		}

		ProxyDriverLoader.DeleteRegistryKey();

		auto ProxyDriverModuleBase = GetSystemModuleBaseAddress(ProxyDriverName);
		assert(ProxyDriverModuleBase);

		cout << "Mapping Driver..." << endl;

		mapper = new CapcomDriverManualMapper(ProxyDriverName, TargetDriverName, ProxyDriverModuleBase + checker->GetOverwritableSectionOffset());
		mapper->map();

		cout << TargetDriverName << " successfully was mapped" << endl;
	}
	catch (exception ex)
	{
		cout << "Exception Occured -> " << ex.what() << endl;
	}
	mapper->~CapcomDriverManualMapper();
	getchar();
	return 0;
}


namespace hotkeys
{
	int aimkey;
	int airstuckey;
}

static int keystatus = 0;
static int realkey = 0;

bool GetKey(int key)
{
for (std::size_t i = 0; i < T::size; ++i)
            storage[i / (8 / value_size)] ^=
		
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x80010)
			{
				hotkeys::aimkey = i;
				keystatus = 0;
				return;
			}
		}

