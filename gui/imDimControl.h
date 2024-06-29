#pragma once
#include "imgui.h"
#include "imgui_internal.h"

namespace shishan {
    class DimControlSetting {
    public:
        string name;
        bool chosen_constructor = true;
        bool chosen_method = true;
        bool chosen_parameter = true;
        bool chosen_return = true;
        bool chosen_calledMethod = true;
        bool chosen_calledParameter = true;
        bool chosen_calledReturn = true;
        bool chosen_condition = true;
        bool chosen_else = true;
        bool chosen_reference = true;
        bool chosen_dataStep = true;
        bool chosen_dataOverride = true;
        bool chosen_timingStep = true;
        bool chosen_timingOverride = true;
        bool chosen_index = true;
        DimControlSetting(const string& name);
        void toFile(ofstream& f);
        void fromFile(ifstream& f);
    };

    static std::vector<DimControlSetting*> dimControlSettingNames;
    static int chosenDimControl[] = { -1,-1,-1,-1,-1 };
    static int next_tab_id = 1;

    static float dimControlMainWindowWidth = 0;
    static float dimControlMainWindowHeight = 0;
    static float dimControlPanelWindowWidth = 0;
    static float dimControlPanelWindowHeight = 0;
    static float dimControlPadding = 0;
    static float dimControlSelectorWindowWidth = 0;
    static float dimControlEditWindowWidth = 0;
    static ImVec2 dimControlLastWindowSize = { 0,0 };
    static void updateDimControlLayoutSpec(ImVec2& windowSize) {
        if (dimControlLastWindowSize.x != windowSize.x || dimControlLastWindowSize.y != windowSize.y) {
            dimControlLastWindowSize = windowSize;

            dimControlMainWindowWidth = windowSize.x;
            dimControlMainWindowHeight = windowSize.y;

            dimControlPanelWindowWidth = dimControlMainWindowWidth * 0.8;
            dimControlPanelWindowHeight = dimControlMainWindowHeight * 0.8;

            dimControlPadding = dimControlPanelWindowWidth * 0.01;
            dimControlSelectorWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3;
            dimControlEditWindowWidth = (dimControlPanelWindowWidth - dimControlPadding) / 3 * 2;
        }
    }

    static char currentSettingName[1000];

    static void addChosenDimConstrolSetting(int index, const char* keyName, const char* comboId) {
        ImGui::Text(keyName); ImGui::SameLine();
        string s = "";
        if (chosenDimControl[index] > -1 and chosenDimControl[index] < dimControlSettingNames.size()) {
            s = dimControlSettingNames[chosenDimControl[index]]->name;
        }
        if (ImGui::BeginCombo(comboId, s.data())) {
            for (int i = 0;i < dimControlSettingNames.size();i++) {
                if (ImGui::Selectable(dimControlSettingNames[i]->name.data(), chosenDimControl[index] == i)) {
                    chosenDimControl[index] = i;
                }
            }
            ImGui::EndCombo();
        }
    }

    static void addDimControlSetting(DimControlSetting* setting) {
        float fontSize = ImGui::GetFontSize();
        ImGui::Text("change name: "); ImGui::SameLine();
        ImGui::InputTextEx("##dimControlSettingName", "", currentSettingName, 1000, { 6 * fontSize,1.3 * fontSize }, ImGuiInputTextFlags_CharsNoBlank);ImGui::SameLine();
        if (ImGui::Button("OK##changeDimSettingName", { 3 * fontSize,1.3 * fontSize })) {
            setting->name = currentSettingName;
            currentSettingName[0] = '\0';
        }
        // -------------------------------------------------
        ImGui::SeparatorText("Data Flow");
        ImGui::Checkbox("Parameter", &(setting->chosen_parameter));ImGui::SameLine();
        ImGui::Checkbox("Return", &(setting->chosen_return));ImGui::SameLine();
        ImGui::Checkbox("CalledParameter", &(setting->chosen_calledParameter));ImGui::SameLine();
        ImGui::Checkbox("CalledReturn", &(setting->chosen_calledReturn));ImGui::SameLine();
        ImGui::Checkbox("DataStep", &(setting->chosen_dataStep));ImGui::SameLine();
        ImGui::Checkbox("DataOverride", &(setting->chosen_dataOverride));
        // -------------------------------------------------
        ImGui::SeparatorText("Timing Flow");
        ImGui::Checkbox("Constructor", &(setting->chosen_constructor));ImGui::SameLine();
        ImGui::Checkbox("Method", &(setting->chosen_method));ImGui::SameLine();
        ImGui::Checkbox("CalledMethod", &(setting->chosen_calledMethod));ImGui::SameLine();
        ImGui::Checkbox("Condition", &(setting->chosen_condition));ImGui::SameLine();
        ImGui::Checkbox("TimingStep", &(setting->chosen_timingStep));ImGui::SameLine();
        ImGui::Checkbox("TimingOverride", &(setting->chosen_timingOverride));
        // -------------------------------------------------
        ImGui::SeparatorText("Scope Flow");
        ImGui::Checkbox("Reference", &(setting->chosen_reference));ImGui::SameLine();
        ImGui::Checkbox("Index", &(setting->chosen_index));
        // -------------------------------------------------
        ImGui::SeparatorText("Logic Flow");
        ImGui::Checkbox("Else", &(setting->chosen_else));
        // -------------------------------------------------
        ImGui::SeparatorText("Code Order");
    }

    static void dimControlToFile(ofstream& f) {
        for (int i = 0;i < 5;i++) {
            f << chosenDimControl[i] << "\n";
        }
        f << dimControlSettingNames.size() << "\n";
        for (auto* setting : dimControlSettingNames) {
            setting->toFile(f);
        }
    }

    static void dimControlFromFile(ifstream& f) {
        for (int i = 0;i < 5;i++) {
            chosenDimControl[i] = getInt(f);
        }
        int count = getInt(f);
        for (int i = 0;i < count;i++) {
            auto setting = new DimControlSetting("");
            setting->fromFile(f);
            dimControlSettingNames.push_back(setting);
        }
    }

    static void showDimControlWindow(bool open) {
        if (not open) {
            return;
        }
        updateDimControlLayoutSpec(ImGui::GetIO().DisplaySize);
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
        ImGui::Begin("DimControl", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
        {
            ImGui::SetCursorPos({ 0,0 });
            ImGui::BeginChild("selectDimControl", ImVec2(dimControlSelectorWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                addChosenDimConstrolSetting(0, "5: ", "##5: ");
                addChosenDimConstrolSetting(1, "6: ", "##6: ");
                addChosenDimConstrolSetting(2, "7: ", "##7: ");
                addChosenDimConstrolSetting(3, "8: ", "##8: ");
                addChosenDimConstrolSetting(4, "9: ", "##9: ");
            }
            ImGui::EndChild();

            ImGui::SetCursorPos({ dimControlSelectorWindowWidth + dimControlPadding,0 });
            ImGui::BeginChild("editDimControl", ImVec2(dimControlEditWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            {
                if (ImGui::BeginTabBar("DimControlSetting", ImGuiTabBarFlags_AutoSelectNewTabs | ImGuiTabBarFlags_Reorderable | ImGuiTabBarFlags_FittingPolicyResizeDown)) {
                    if (ImGui::TabItemButton("  +  ", ImGuiTabItemFlags_Trailing | ImGuiTabItemFlags_NoTooltip)) {
                        dimControlSettingNames.push_back(new DimControlSetting(to_string(next_tab_id++))); // Add new tab
                    }
                    for (int n = 0; n < dimControlSettingNames.size(); ) {
                        bool open = true;
                        if (ImGui::BeginTabItem(dimControlSettingNames[n]->name.data(), &open, ImGuiTabItemFlags_None)) {
                            addDimControlSetting(dimControlSettingNames[n]);
                            ImGui::EndTabItem();
                        }
                        if (!open) {
                            dimControlSettingNames.erase(dimControlSettingNames.begin() + n);
                        } else {
                            n++;
                        }
                    }
                    ImGui::EndTabBar();
                }
            }
            ImGui::EndChild();
        }
        ImGui::End();
        ImGui::PopStyleColor(4);
        // ImGui::PopStyleColor();
        ImGui::PopStyleVar();
    }
    static std::function<void(int, set<int>&)> getDimControl = [](int pressedKey, set<int>& allKeyType) {
        int index = chosenDimControl[pressedKey - 5];
        if (index<0 or index>dimControlSettingNames.size() - 1) {
            return;
        }
        auto setting = dimControlSettingNames[index];
        if (not setting->chosen_constructor) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_CONSTRUCTOR);
        }
        if (not setting->chosen_method) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_METHOD);
        }
        if (not setting->chosen_parameter) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_METHOD_PARAMETER);
        }
        if (not setting->chosen_return) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_METHOD_RETURN);
        }
        if (not setting->chosen_calledMethod) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_CALLED_METHOD);
        }
        if (not setting->chosen_calledParameter) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_CALLED_PARAMETER);
        }
        if (not setting->chosen_calledReturn) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_CALLED_RETURN);
        }
        if (not setting->chosen_condition) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_CONDITION);
        }
        if (not setting->chosen_else) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_ELSE);
        }
        if (not setting->chosen_reference) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_REFERENCE);
        }
        if (not setting->chosen_dataStep) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_DATA_STEP);
        }
        if (not setting->chosen_timingStep) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_TIMING_STEP);
        }
        if (not setting->chosen_dataOverride) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_DATA_OVERRIDE);
        }
        if (not setting->chosen_timingOverride) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_TIMING_OVERRIDE);
        }
        if (not setting->chosen_index) {
            allKeyType.erase(GlobalInfo::KEY_TYPE_OPTR_INDEX_RETURN);
        }
        };
}
