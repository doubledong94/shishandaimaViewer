#pragma once
#include "imgui.h"
#include "imgui_internal.h"
namespace shishan {

    static set<string> chosenClass;
    static vector<const char*> searchResultsOfExclude;
    static float excludeClass_searchBarHeight;

    static void updateExcludeClassLayoutSpec(ImVec2& windowSize) {
        if (dimControlLastWindowSize.x != windowSize.x || dimControlLastWindowSize.y != windowSize.y) {
            dimControlLastWindowSize = windowSize;

            dimControlMainWindowWidth = windowSize.x;
            dimControlMainWindowHeight = windowSize.y;

            dimControlPanelWindowWidth = dimControlMainWindowWidth * 0.9;
            dimControlPanelWindowHeight = dimControlMainWindowHeight * 0.8;

            dimControlPadding = dimControlPanelWindowWidth * 0.01;
            dimControlSelectorWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3;
            dimControlEditWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3 * 2;
            excludeClass_searchBarHeight = ImGui::GetFontSize() * 1.2f;
        }
    }

    static void chosenClassToFile(ofstream& f) {
        f << chosenClass.size() << "\n";
        for (auto& p : chosenClass) {
            f << p << "\n";
        }
    }
    static void chosenClassFromFile(ifstream& f) {
        int count = getInt(f);
        for (int i = 0;i < count;i++) {
            string p;
            std::getline(f, p);
            chosenClass.insert(p);
        }
    }

    static void showChooseExcludeClassWindow(bool open) {
        if (not open) {
            return;
        }
        updateExcludeClassLayoutSpec(ImGui::GetIO().DisplaySize);
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
        ImGui::Begin("ChooseExcludeClass", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
        {
            ImGui::SetCursorPos({ 0,0 });
            ImGui::BeginChild("searchClass", ImVec2(dimControlSelectorWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                if (ImGui::InputTextEx("##searchbar", searchResultsOfExclude.empty() ? StringRes::singleton->getSearchClass() : StringRes::singleton->getSearchExisting(),
                    searchedStr, 1024, { dimControlSelectorWindowWidth,excludeClass_searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_EnterReturnsTrue)) {
                    ImGui::SetKeyboardFocusHere(-1);
                    if (searchResultsOfExclude.empty()) {
                        onSearchClass(searchResultsOfExclude);
                    } else {
                        filterSearchResults(searchResultsOfExclude);
                    }
                }
                for (int i = 0;i < searchResultsOfExclude.size();i++) {
                    if (ImGui::Selectable(searchResultsOfExclude[i], chosenClass.count(searchResultsOfExclude[i]))) {
                        if (chosenClass.count(searchResultsOfExclude[i])) {
                            chosenClass.erase(searchResultsOfExclude[i]);
                        } else {
                            chosenClass.insert(searchResultsOfExclude[i]);
                        }
                    }
                }
            }
            ImGui::EndChild();

            ImGui::SetCursorPos({ dimControlSelectorWindowWidth + dimControlPadding,0 });
            ImGui::BeginChild("excludeClass", ImVec2(dimControlEditWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                for (auto& c : chosenClass) {
                    ImGui::Selectable(c.data(), false);
                    ImGui::SetItemTooltip(c.data());
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
        ImGui::PopStyleColor(4);
        // ImGui::PopStyleColor();
        ImGui::PopStyleVar();
    }

    static std::function<void(set<string>&)> getExcludeClass = [](set<string>& excludeClass) {
        for (auto& p : chosenClass) {
            excludeClass.insert(p);
        }
        };
}
