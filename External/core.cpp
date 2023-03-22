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

bool CalculateAngles(const FVector& source, const FVector& target, float* angles) {
    FVector rel = target - source;
    angles[0] = -asinf(rel.Z / rel.Size()) * (180 / PI);
    angles[1] = atan2f(rel.Y, rel.X) * (180 / PI);
    return true;
}


namespace Game::Memory {
    const int TARGET_PAWN_HEAD_OFFSET = 0x123;
}

PVOID ReadPointer(PVOID base, int offset) {
    return *reinterpret_cast<PVOID*>(reinterpret_cast<char*>(base) + offset);
}

FVector GetTargetPawnHeadLocation(PlayerData& playerData) {
    if (!Settings.ESP.Players) throw std::runtime_error("Players setting is disabled");
    PVOID targetPawnController = ReadPointer(playerData.targetPawn, Game::Memory::TARGET_PAWN_HEAD_OFFSET);
    if (!targetPawnController) throw std::runtime_error("Failed to find target pawn controller");
    return *reinterpret_cast<FVector*>(reinterpret_cast<char*>(targetPawnController) + Game::Memory::TARGET_PAWN_HEAD_OFFSET);
}

