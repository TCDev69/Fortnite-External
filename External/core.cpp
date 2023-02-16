#include "main.cpp"
#include "define.h"


namespace Core {
    constexpr float kPi = 3.14159265358979323846f;
    constexpr int kHeadOffset = 0x278;
    constexpr float kDegToRad = kPi / 180.0f;

    struct PlayerData {
        bool noSpread = true;
        PVOID localPlayerPawn = nullptr;
        PVOID localPlayerController = nullptr;
        PVOID targetPawn = nullptr;
    };

    float Normalize(float value) {
        // TODO: Implement Normalize function
        return value;
    }

    bool CalculateAngles(const FVector& source, const FVector& target, float* angles) {
        // Calculate the relative position of the target relative to the source
        FVector rel = target - source;

        // Calculate the distance and yaw angle between the two points
        float dist = sqrtf(rel[0] * rel[0] + rel[1] * rel[1] + rel[2] * rel[2]);
        float yaw = atan2f(rel[1], rel[0]) * (1.0f / kDegToRad);

        // Calculate the pitch and yaw angles and normalize them
        float pitch = -atan2f(rel[2], dist) * (1.0f / kDegToRad);
        angles[0] = Normalize(pitch);
        angles[1] = Normalize(yaw);

        return true;
    }

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


void SetDepthStencilState(eDepthState aState) {
  if (pContext) {
    pContext->OMSetDepthStencilState(myDepthStencilStates[aState], 1);
  }
}

if (Core::TargetPawn && Core::LocalPlayerController) {
  if (objectName.find(L"Injector") != std::wstring::npos && funcName == L"Injector") {
    ImVec2 centerTop(...);
    ImVec2 size(...);
    ImU32 color(...);
    std::wstring copy(...);

    ImGui::GetCurrentWindow()->DrawList->AddRectFilled(
        ImVec2(centerTop.x - size.x / 2.0f, centerTop.y - size.y + 3.0f),
        ImVec2(centerTop.x + size.x / 2.0f, centerTop.y),
        ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 0.4f }));
    ImGui::GetCurrentWindow()->DrawList->AddText(
        ImVec2(centerTop.x - size.x / 2.0f, centerTop.y - size.y), color, copy.c_str());
  }
}
