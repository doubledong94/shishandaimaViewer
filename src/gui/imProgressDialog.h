#include "imgui.h"
#include "imgui_internal.h"

static void showProgressDialog(const char* name, bool* open, int progress, int total, char* loadingName) {
    if (not *open) {
        return;
    }
    ImGuiIO& io = ImGui::GetIO();
    float mainWindowWidth = io.DisplaySize.x;
    float mainWindowHeight = io.DisplaySize.y;
    float fontSize = ImGui::GetFontSize();
    float dialogWidth = 30 * fontSize;
    float dialogHeight = 5 * fontSize;
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(dialogWidth, dialogHeight), ImGuiCond_Always);
    if (*open) {
        ImGui::OpenPopup(name);
    }
    if (ImGui::BeginPopupModal(name, open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {
        ImGui::TextWrapped(name);
        ImGui::ProgressBar(progress / (float)total, ImVec2(0.f, 0.f), (to_string(progress) + "/" + to_string(total)).data());
        ImGui::TextWrapped(loadingName);
        ImGui::EndPopup();
    }
}
