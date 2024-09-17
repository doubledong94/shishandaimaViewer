#include "imgui.h"
#include "imgui_internal.h"

static void showRejectDialog(const char* name, bool* open) {
    if (not *open) {
        return;
    }
    ImGuiIO& io = ImGui::GetIO();
    float mainWindowWidth = io.DisplaySize.x;
    float mainWindowHeight = io.DisplaySize.y;
    float fontSize = ImGui::GetFontSize();
    float dialogWidth = 9 * fontSize;
    float dialogHeight = 5 * fontSize;
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(dialogWidth, dialogHeight), ImGuiCond_Always);
    if (*open) {
        ImGui::OpenPopup(name);
    }
    if (ImGui::BeginPopupModal(name, open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {
        ImGui::TextWrapped(name);
        float buttongHeight = 2 * fontSize;
        ImGui::SetCursorPosY(dialogHeight - buttongHeight);
        if (ImGui::Button("OK##rejectDialogOK", { dialogWidth, buttongHeight })) {
            ImGui::CloseCurrentPopup();
            (*open) = false;
        }
        ImGui::EndPopup();
    }
}