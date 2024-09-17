#pragma once
#include "imgui.h"
#include "imgui_internal.h"

#define ADD_IF(S, B, K) if (B) {S.insert(K);}

namespace shishan {
    static string selectedNodeText;
    static set<int> excludedTypes;

    static bool showType_CLASS = true;
    static bool showType_FIELD = true;
    static bool showType_CONSTRUCTOR = true;
    static bool showType_METHOD = true;
    static bool showType_METHOD_PARAMETER = true;
    static bool showType_METHOD_RETURN = true;
    static bool showType_CALLED_METHOD = true;
    static bool showType_CALLED_PARAMETER = true;
    static bool showType_CALLED_RETURN = true;
    static bool showType_CONDITION = true;
    static bool showType_ELSE = true;
    static bool showType_REFERENCE = true;
    static bool showType_DATA_STEP = true;
    static bool showType_TIMING_STEP = true;
    static bool showType_DATA_OVERRIDE = true;
    static bool showType_TIMING_OVERRIDE = true;
    static bool showType_INDEX = true;
    static bool showType_LOCAL_VARIABLE = true;
    static bool showType_FINAL = true;
    static bool showType_DEFAULT_VALUE = true;
    static bool showType_KEY_WORD_VALUE = true;
    static bool showType_ANONYMOUS_CLASS = true;
    static bool showType_ENUM_INSTANCE = true;
    static bool showType_ARRAY_INIT = true;
    static bool showType_OPTR = true;
    static bool showType_ERROR = true;

    static void resetExcludedType() {
        excludedTypes.clear();
        ADD_IF(excludedTypes, !showType_CLASS, GlobalInfo::KEY_TYPE_CLASS);
        ADD_IF(excludedTypes, !showType_FIELD, GlobalInfo::KEY_TYPE_FIELD);
        ADD_IF(excludedTypes, !showType_CONSTRUCTOR, GlobalInfo::KEY_TYPE_CONSTRUCTOR);
        ADD_IF(excludedTypes, !showType_METHOD, GlobalInfo::KEY_TYPE_METHOD);
        ADD_IF(excludedTypes, !showType_METHOD_PARAMETER, GlobalInfo::KEY_TYPE_METHOD_PARAMETER);
        ADD_IF(excludedTypes, !showType_METHOD_RETURN, GlobalInfo::KEY_TYPE_METHOD_RETURN);
        ADD_IF(excludedTypes, !showType_CALLED_METHOD, GlobalInfo::KEY_TYPE_CALLED_METHOD);
        ADD_IF(excludedTypes, !showType_CALLED_PARAMETER, GlobalInfo::KEY_TYPE_CALLED_PARAMETER);
        ADD_IF(excludedTypes, !showType_CALLED_RETURN, GlobalInfo::KEY_TYPE_CALLED_RETURN);
        ADD_IF(excludedTypes, !showType_CONDITION, GlobalInfo::KEY_TYPE_CONDITION);
        ADD_IF(excludedTypes, !showType_ELSE, GlobalInfo::KEY_TYPE_ELSE);
        ADD_IF(excludedTypes, !showType_REFERENCE, GlobalInfo::KEY_TYPE_REFERENCE);
        ADD_IF(excludedTypes, !showType_DATA_STEP, GlobalInfo::KEY_TYPE_DATA_STEP);
        ADD_IF(excludedTypes, !showType_TIMING_STEP, GlobalInfo::KEY_TYPE_TIMING_STEP);
        ADD_IF(excludedTypes, !showType_DATA_OVERRIDE, GlobalInfo::KEY_TYPE_DATA_OVERRIDE);
        ADD_IF(excludedTypes, !showType_TIMING_OVERRIDE, GlobalInfo::KEY_TYPE_TIMING_OVERRIDE);
        ADD_IF(excludedTypes, !showType_INDEX, GlobalInfo::KEY_TYPE_INDEX);
        ADD_IF(excludedTypes, !showType_LOCAL_VARIABLE, GlobalInfo::KEY_TYPE_LOCAL_VARIABLE);
        ADD_IF(excludedTypes, !showType_FINAL, GlobalInfo::KEY_TYPE_FINAL);
        ADD_IF(excludedTypes, !showType_DEFAULT_VALUE, GlobalInfo::KEY_TYPE_DEFAULT_VALUE);
        ADD_IF(excludedTypes, !showType_KEY_WORD_VALUE, GlobalInfo::KEY_TYPE_KEY_WORD_VALUE);
        ADD_IF(excludedTypes, !showType_ANONYMOUS_CLASS, GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS);
        ADD_IF(excludedTypes, !showType_ENUM_INSTANCE, GlobalInfo::KEY_TYPE_ENUM_INSTANCE);
        ADD_IF(excludedTypes, !showType_ARRAY_INIT, GlobalInfo::KEY_TYPE_ARRAY_INIT);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_START);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER2);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_UNARY_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_UNARY_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_LOGIC_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_LOGIC_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_LOGIC_PARAMETER2);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_RELATION_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER2);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER2);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER3);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_RETURN);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER1);
        ADD_IF(excludedTypes, !showType_OPTR, GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER2);
        ADD_IF(excludedTypes, !showType_ERROR, GlobalInfo::KEY_TYPE_ERROR);

    }

    static void resetShowType() {
        showType_CLASS = true;
        showType_FIELD = true;
        showType_CONSTRUCTOR = true;
        showType_METHOD = true;
        showType_METHOD_PARAMETER = true;
        showType_METHOD_RETURN = true;
        showType_CALLED_METHOD = true;
        showType_CALLED_PARAMETER = true;
        showType_CALLED_RETURN = true;
        showType_CONDITION = true;
        showType_ELSE = true;
        showType_REFERENCE = true;
        showType_DATA_STEP = true;
        showType_TIMING_STEP = true;
        showType_DATA_OVERRIDE = true;
        showType_TIMING_OVERRIDE = true;
        showType_INDEX = true;
        showType_LOCAL_VARIABLE = true;
        showType_FINAL = true;
        showType_DEFAULT_VALUE = true;
        showType_KEY_WORD_VALUE = true;
        showType_ANONYMOUS_CLASS = true;
        showType_ENUM_INSTANCE = true;
        showType_ARRAY_INIT = true;
        showType_OPTR = true;
        showType_ERROR = true;
    }

    static void showSelectedNodeTextWindow(bool open) {
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
        ImGui::Begin("SelectedNodeTextWindow", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

        ImGui::SetCursorPos({ 0,0 });
        ImGui::BeginChild("SelectedNodeTypeWindow", ImVec2(dimControlSelectorWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);

        {
            bool changed = false;
            changed = changed | ImGui::Checkbox("CLASS", &showType_CLASS);
            changed = changed | ImGui::Checkbox("FIELD", &showType_FIELD);
            changed = changed | ImGui::Checkbox("CONSTRUCTOR", &showType_CONSTRUCTOR);
            changed = changed | ImGui::Checkbox("METHOD", &showType_METHOD);
            changed = changed | ImGui::Checkbox("METHOD_PARAMETER", &showType_METHOD_PARAMETER);
            changed = changed | ImGui::Checkbox("METHOD_RETURN", &showType_METHOD_RETURN);
            changed = changed | ImGui::Checkbox("CALLED_METHOD", &showType_CALLED_METHOD);
            changed = changed | ImGui::Checkbox("CALLED_PARAMETER", &showType_CALLED_PARAMETER);
            changed = changed | ImGui::Checkbox("CALLED_RETURN", &showType_CALLED_RETURN);
            changed = changed | ImGui::Checkbox("CONDITION", &showType_CONDITION);
            changed = changed | ImGui::Checkbox("ELSE", &showType_ELSE);
            changed = changed | ImGui::Checkbox("REFERENCE", &showType_REFERENCE);
            changed = changed | ImGui::Checkbox("DATA_STEP", &showType_DATA_STEP);
            changed = changed | ImGui::Checkbox("TIMING_STEP", &showType_TIMING_STEP);
            changed = changed | ImGui::Checkbox("DATA_OVERRIDE", &showType_DATA_OVERRIDE);
            changed = changed | ImGui::Checkbox("TIMING_OVERRIDE", &showType_TIMING_OVERRIDE);
            changed = changed | ImGui::Checkbox("INDEX", &showType_INDEX);
            changed = changed | ImGui::Checkbox("LOCAL_VARIABLE", &showType_LOCAL_VARIABLE);
            changed = changed | ImGui::Checkbox("FINAL", &showType_FINAL);
            changed = changed | ImGui::Checkbox("DEFAULT_VALUE", &showType_DEFAULT_VALUE);
            changed = changed | ImGui::Checkbox("KEY_WORD_VALUE", &showType_KEY_WORD_VALUE);
            changed = changed | ImGui::Checkbox("ANONYMOUS_CLASS", &showType_ANONYMOUS_CLASS);
            changed = changed | ImGui::Checkbox("ENUM_INSTANCE", &showType_ENUM_INSTANCE);
            changed = changed | ImGui::Checkbox("ARRAY_INIT", &showType_ARRAY_INIT);
            changed = changed | ImGui::Checkbox("OPTR", &showType_OPTR);
            changed = changed | ImGui::Checkbox("ERROR", &showType_ERROR);
            if (changed) {
                resetExcludedType();
                app::appPtr->boundedGraph->printSelectedNode(excludedTypes, selectedNodeText);
            }
        }

        ImGui::EndChild();

        ImGui::SetCursorPos({ dimControlSelectorWindowWidth + dimControlPadding,0 });
        ImGui::BeginChild("SelectedNodeText", ImVec2(dimControlEditWindowWidth, dimControlPanelWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_HorizontalScrollbar);

        {
            ImGui::SetCursorPos({ 0,0 });
            ImGui::InputTextMultiline("##selectedNodeTxtMultiline", selectedNodeText.data(), selectedNodeText.size(), ImVec2(dimControlEditWindowWidth * 3, dimControlPanelWindowHeight), ImGuiInputTextFlags_ReadOnly);
        }

        ImGui::EndChild();

        ImGui::End();
        ImGui::PopStyleColor(4);
        // ImGui::PopStyleColor();
        ImGui::PopStyleVar();
    }
}
