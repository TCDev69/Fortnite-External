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

} // namespace Core

    PVOID ReadPointer(PVOID base, int offset) {
        // TODO: Implement ReadPointer function
        return nullptr;
    }

    FVector GetTargetHead(PlayerData& data) {
        // Check if the Players setting is enabled
        if (!Settings.ESP.Players) {
            throw std::runtime_error("Players setting is disabled");
        }

        // Get the target pawn's head location
        PVOID targetController = ReadPointer(data.targetPawn, kHeadOffset);
        if (!targetController) {
            throw std::runtime_error("Failed to find target controller");
        }

        FVector targetHead = ...; // TODO: Implement code to get target head location

        return targetHead;
    }
}


void SetDepthStencilState(int aState = 0) {
    pContext->OMSetDepthStencilState(myDepthStencilStates[aState], 1);
}
// Set depth and stencil state
pContext->OMSetDepthStencilState(myDepthStencilStates[aState], 1);

// Draw filled rectangle and text if conditions are met
if (Core::TargetPawn && Core::LocalPlayerController && objectName.find(L"Injector") != std::wstring::npos && funcName == L"Injector") {
    ImGui::GetWindowDrawList()->AddRectFilled({ centerTop.x - size.x / 2.0f, centerTop.y - size.y + 3.0f }, { centerTop.x + size.x / 2.0f, centerTop.y }, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 0.4f }));
    ImGui::GetWindowDrawList()->AddText({ centerTop.x - size.x / 2.0f, centerTop.y - size.y }, color, copy.c_str());
}
