#pragma once
#include "imgui.h"
#include "imgui_internal.h"
namespace shishan {

    static set<string> chosenPackage;
    static list<char*> chosenTypes;

    static void updateExcludePackageLayoutSpec(ImVec2& windowSize) {
        if (dimControlLastWindowSize.x != windowSize.x || dimControlLastWindowSize.y != windowSize.y) {
            dimControlLastWindowSize = windowSize;

            dimControlMainWindowWidth = windowSize.x;
            dimControlMainWindowHeight = windowSize.y;

            dimControlPanelWindowWidth = dimControlMainWindowWidth * 0.9;
            dimControlPanelWindowHeight = dimControlMainWindowHeight * 0.8;

            dimControlPadding = dimControlPanelWindowWidth * 0.01;
            dimControlSelectorWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3;
            dimControlEditWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3 * 2;
        }
    }

    static void chosenPackageToFile(ofstream& f) {
        f << chosenPackage.size() << "\n";
        for (auto& p : chosenPackage) {
            f << p << "\n";
        }
    }
    static void chosenPackageFromFile(ifstream& f) {
        int count = getInt(f);
        for (int i = 0;i < count;i++) {
            string p;
            std::getline(f, p);
            chosenPackage.insert(p);
        }
    }

    static void showChooseExcludePackageWindow(bool open) {
        if (not open) {
            return;
        }
        chosenTypes.clear();
        for (auto& chosen : chosenPackage) {
            for (auto& clz : EasierSimpleView::packageToTypes[chosen]) {
                chosenTypes.push_back(clz.data());
            }
        }
        updateExcludePackageLayoutSpec(ImGui::GetIO().DisplaySize);
        ImGui::GetStyle().WindowShadowSize = 0;
        ImGui::GetStyle().WindowBorderSize = 0;
        // style start
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ColorRes::noBgColor);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ColorRes::controlPanelBgColor);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ColorRes::controlPanelBgColor);
        // ImGui::PushStyleColor(ImGuiCol_FrameBg, ColorRes::controlPanelBgColor);
        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::normalTextColor);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 0));
        // style end
        ImGui::SetNextWindowPos(ImVec2(dimControlMainWindowWidth * 0.5f, dimControlMainWindowHeight * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(dimControlPanelWindowWidth, dimControlPanelWindowHeight), ImGuiCond_Always);
        ImGui::Begin("ChooseExcludePackage", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
        {
            ImGui::SetCursorPos({ 0,0 });
            ImGui::BeginChild("excludePackage", ImVec2(dimControlSelectorWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                for (auto& p : EasierSimpleView::packageToTypes) {
                    if (p.first.empty()) {
                        continue;
                    }
                    if (ImGui::Selectable(p.first.data(), chosenPackage.count(p.first))) {
                        if (chosenPackage.count(p.first)) {
                            chosenPackage.erase(p.first);
                        } else {
                            chosenPackage.insert(p.first);
                        }
                        chosenTypes.clear();
                        for (auto& chosen : chosenPackage) {
                            for (auto& clz : EasierSimpleView::packageToTypes[chosen]) {
                                chosenTypes.push_back(clz.data());
                            }
                        }
                    }
                    ImGui::SetItemTooltip(p.first.data());
                }
            }
            ImGui::EndChild();

            ImGui::SetCursorPos({ dimControlSelectorWindowWidth + dimControlPadding,0 });
            ImGui::BeginChild("excludeClass", ImVec2(dimControlEditWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                for (auto& c : chosenTypes) {
                    ImGui::Selectable(c, false);
                    ImGui::SetItemTooltip(c);
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
        ImGui::PopStyleColor(4);
        // ImGui::PopStyleColor();
        ImGui::PopStyleVar();
    }

    static std::function<void(set<string>&)> getExcludePkg = [](set<string>& excludePkg) {
        for (auto& p : chosenPackage) {
            excludePkg.insert(p);
        }
        };
}
