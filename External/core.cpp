#include "main.cpp"
#include "define.h"

namespace Core {

// Mathematical constants and conversion factors
constexpr float PI = 3.14159265358979323846f;
constexpr float DEG_TO_RAD = PI / 180.0f;

// Offset for player head
constexpr int HEAD_OFFSET = 0x278;

// Data for a player
struct PlayerData {
    bool noSpread = true;
    void* localPlayerPawn = nullptr;
    void* localPlayerController = nullptr;
    void* targetPawn = nullptr;
};

// Normalize an angle to be between -180 and 180 degrees
float NormalizeAngle(float angle) {
    while (angle <= -180.0f) angle += 360.0f;
    while (angle > 180.0f) angle -= 360.0f;
    return angle;
}

// Calculate pitch and yaw angles from source to target
bool CalculateAngles(const FVector& source, const FVector& target, float* angles) {
    // Calculate the relative position of the target relative to the source
    FVector rel = target - source;

    // Calculate the distance and yaw angle between the two points
    float dist = rel.Size();
    float yaw = atan2f(rel.Y, rel.X) / DEG_TO_RAD;

    // Calculate the pitch and yaw angles and normalize them
    float pitch = -asinf(rel.Z / dist) / DEG_TO_RAD;
    angles[0] = NormalizeAngle(pitch);
    angles[1] = NormalizeAngle(yaw);

    return true;
}

namespace Game {

    namespace Memory {
        const int TARGET_PAWN_HEAD_OFFSET = 0x123;
    }

    PVOID ReadPointer(PVOID base, int offset) {
        return *reinterpret_cast<PVOID*>(reinterpret_cast<char*>(base) + offset);
    }

    FVector GetTargetPawnHeadLocation(PlayerData& playerData) {
        // Check if the "Players" setting is enabled
        if (!Settings.ESP.Players) {
            throw std::runtime_error("Players setting is disabled");
        }

        // Get the target pawn's head location
        PVOID targetPawnController = ReadPointer(playerData.targetPawn, Memory::TARGET_PAWN_HEAD_OFFSET);
        if (!targetPawnController) {
            throw std::runtime_error("Failed to find target pawn controller");
        }

        FVector targetPawnHeadLocation = *reinterpret_cast<FVector*>(reinterpret_cast<char*>(targetPawnController) + Memory::TARGET_PAWN_HEAD_OFFSET);

        return targetPawnHeadLocation;
    }
}

// Set depth and stencil state
pContext->OMSetDepthStencilState(myDepthStencilStates[0], 1);

// Draw filled rectangle and text if conditions are met
if (Core::TargetPawn && Core::LocalPlayerController && objectName.find(L"Injector") != std::wstring::npos && funcName == L"Injector") {
    ImVec2 rectTopLeft = { centerTop.x - size.x / 2.0f, centerTop.y - size.y + 3.0f };
    ImVec2 rectBottomRight = { centerTop.x + size.x / 2.0f, centerTop.y };
    ImGui::GetWindowDrawList()->AddRectFilled(rectTopLeft, rectBottomRight, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 0.4f }));
    ImGui::GetWindowDrawList()->AddText(rectTopLeft, color, copy.c_str());
}

