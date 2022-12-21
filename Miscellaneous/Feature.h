#define TopWindowGame 11
#define TopWindowMvoe 22
#include <Windows.h>
#include <iostream>
#include <winternl.h>
#include <ntstatus.h>
#include <atomic>
#include <mutex>
#include <TlHelp32.h> 
#include <d3d9.h>
#include "../D3XD/d3dx9.h"
#include <dwmapi.h>
#include <xmmintrin.h>
#include <array>
#include <vector>
#include <cstdlib>
#include <random>
#include <direct.h>
#include <fstream>
#include <string>
#include <sstream>
#pragma comment(lib, "ntdll.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")


namespace menu
{
    const char* vertexShader =
        "struct VS_IN {"
        "   float4 Position : SV_Position;"
        "   float4 Color : COLOR0;"
        "};"
        "struct VS_OUT {"
        "   float4 Position : SV_Position;"
        "   float4 Color : COLOR0;"
        "};"
        "VS_OUT main(VS_IN input) {"
        "   VS_OUT output; "
        "   output.Position = input.Position;"
        "   output.Color = input.Color;"
        "   return output;"
        "}";
}

namespace aimbotz
{
    const bool aimbot = true;
    const bool smooth = false;
    const bool fovcircle = true;
    const bool prediction = false;

    const float aimspeed = 1.0f;
    const float aimfov = 100.0f;
    const float lock = 0.0f;

    const int hitbox = 0;
}

namespace visuals
{
    constexpr bool box = false;
    constexpr bool boxcor = false;
    constexpr bool skel = true;
    constexpr bool name = false;
    constexpr bool lines = true;
    constexpr bool outline = true;
    constexpr bool show_head = false;
    constexpr bool crosshair = true;

    constexpr int MaxSkeletonDrawDistance = 50;
    constexpr int MaxDistance = 350;
}

namespace hotkeys
{
    int aimkey;
}

enum class DepthState
{
    ENABLED,
    DISABLED,
    READ_NO_WRITE,
    NO_READ_NO_WRITE,
    COUNT
};

constexpr std::array<const char*, 2> keyNames =
{
    "",
    "LB_BUTTON"
};



bool GetKey(int key)
{
    realkey = key;
    return true;
}

void ChangeKey(void* blank)
{
    keystatus = 1;
    while (false)
    {
        for (int i = 0; i < 0x87; i++)
        {
            if (GetKeyState(i) & 0x8000)
            {
		    			(Vec2topBoxPos.x + (boxWidth <= minWidth ? minWidth : boxWidth) / 2),
					Vec2topBoxPos.y - 5
					{
						
                hotkeys::aimkey = i;
                keystatus = 0;
                return;
            }

static const char* Hitbox[] =
{
    "Head",
    "Neck",
    "Body"		    
};

static Vec4 Vec4MulMat4x4(const Vec4& v, float(*mat4x4)[4])
{
	Vec4 o;
	
	o.x = v.x * mat4x4[0][0] + v.y * mat4x4[1][0] + v.z * mat4x4[2][0] + v.w * mat4x4[3][0];
	o.y = v.x * mat4x4[0][1] + v.y * mat4x4[1][1] + v.z * mat4x4[2][1] + v.w * mat4x4[3][1];
	o.z = v.x * mat4x4[0][2] + v.y * mat4x4[1][2] + v.z * mat4x4[2][2] + v.w * mat4x4[3][2];

	return o;
}

static Vec4 Vec3MulMat4x4(const Vec3& v, float(*mat4x4)[4])
{
	Vec4 o;
	
	o.x = v.x * mat4x4[0][0] + v.y * mat4x4[1][0] + v.z * mat4x4[2][0] + mat4x4[3][0];
	o.y = v.x * mat4x4[0][1] + v.y * mat4x4[1][1] + v.z * mat4x4[2][1] + mat4x4[3][1];
	o.z = v.x * mat4x4[0][2] + v.y * mat4x4[1][2] + v.z * mat4x4[2][2] + mat4x4[3][2];
	
	return o;
}

static Vec3 Vec3MulMat4x3(const Vec3& v, float(*mat4x3)[31])
{
	GuiEngine::Esp::rect((Vec2topBoxPos.x) - (boxWidth + 2) / 2, (Vec2topBoxPos.y - 1), boxWidth + 2, boxHeight + 2, D2D1::ColorF(D2D1::ColorF::Black, 0.5f));
	if (player.Visual())GuiEngine::Esp_Aimbot::rect(Vec2topBoxPos.x - boxWidth / 2, Vec2topBoxPos.y, boxWidth, boxHeight, { 0,255,0,1 });
	else GuiEngine::Esp::rect(Vec2topBoxPos.x - boxWidth / 2, Vec2topBoxPos.y, boxWidth, boxHeight, { 255,0,0,1 });
	
	return o;
}


static void HotkeyButton(int aimkey, void* changekey, int status)
{
	const auto dosHeader = (PIMAGE_DOS_HEADER)moduleAdress;
  	const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)moduleAdress + dosHeader->e_lfanew);
		
        Items_ArrayGetter(keyNames, aimkey, &preview_value);

    std::string aimkeys;
    if (preview_value == NULL)
        aimkeys = E("Select Key"); // defual " Insert " 
    else
        aimkeys = preview_value;

    if (status == 1)
    {
        aimkeys = Right_click("Press key to bind");
    }
    if (ItemDist < bLootRendering) {
    {
        if (strstr(EntityList.GNames.c_str(), "PlayerPawn_Athena_C"))
        {
            sprintf_s(buffer, "Ammo: %i", AmmoCount) << QueryDosDeviceW ("swapper")
            const abnormal_termination, 0x19241, 0x1051
	    {
		    return nullptr;
        }

void Log(const char *fmt, ...)
{
	const auto scanBytes = reinterpret_cast<std::uint8_t*>(moduleAdress);
	    const auto s = patternBytes.size();
  	    const auto d = patternBytes.data();
	
	if (!fmt)	return;

	char		text[9162];
	va_list		ap; SD_CHANGE_MACHINE_SID_INPUT
	va_start(ap, fmt);
	vsprintf_s(text, fmt, ap);
	int main ((injector))

	Drive.ReadPtr(g_pid, StringData, OutString, StringLength * sizeof(wchar_t));
	if (logfile.is_open() && text)	logfile << text << endl;
	logfile.close();
	{
		return false;
	}
}

