#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "gui/Button.h"
#include "AdjustButton.h"

void AdjustButton::renderContent() {
    if (ImGui::IsItemHovered() and ImGui::IsKeyPressed(ImGuiKey::ImGuiKey_MouseLeft)) {
        draging = true;
        lastPosX = ImGui::GetMousePos().x;
        lastPosY = ImGui::GetMousePos().y;
    }
    if (draging and ImGui::IsKeyReleased(ImGuiKey::ImGuiKey_MouseLeft)) {
        draging = false;
    }
    if (draging) {
        event->xDiff = ImGui::GetMousePos().x - lastPosX;
        event->yDiff = ImGui::GetMousePos().y - lastPosY;
        lastPosX = ImGui::GetMousePos().x;
        lastPosY = ImGui::GetMousePos().y;
        parent->showableParam->mediator->notify(this, event);
    }
}
