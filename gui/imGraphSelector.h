
#pragma once
#include "imgui.h"
#include "imgui_internal.h"
namespace shishan {
    static vector<const char*> searchResults2;
    static set<int> nodeKeySelectedIndex;
    static int lastSelectedNodeKey = -1;
    static set<int> methodOfRuntimeSelectedIndex;
    static set<const char*> nodeNameSelectedIndex;
    static map<string, map<string, set<string>>> positionInRegexSelectedIndex;

    static void clearSelectedNode() {
        nodeKeySelectedIndex.clear();
        lastSelectedNodeKey = -1;
    }

    static void showGraphSelectorWindow(bool open, const vector<const char*>& methodOfRuntime,
        map<string, map<string, list<string>>>& graphNameToLineNameToRegex) {
        if (not open) {
            return;
        }
        updateLayoutSpec(ImGui::GetIO().DisplaySize);
        float fontSize = ImGui::GetFontSize();
        ImGui::GetStyle().WindowShadowSize = 0;
        ImGui::GetStyle().WindowBorderSize = 0;
        ImVec4 panelBgColor = ColorRes::controlPanelBgColor;

        // style start
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ColorRes::noBgColor);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ColorRes::noBgColor);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, ColorRes::controlPanelBgColor);
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ColorRes::controlPanelBgColor);
        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::normalTextColor);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 0));
        // style end

        ImGui::SetNextWindowPos(ImVec2(mainWindowWidth * 0.5f, mainWindowHeight * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(searchWindowWidth, searchWindowHeight), ImGuiCond_Always);
        ImGui::Begin("graphSelector", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

        // selector window start
        ImGui::SetCursorPos({ mainWindowPadding,mainWindowPadding });
        ImGui::BeginChild("selectorWindow", ImVec2(editWindowWidth, childWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, panelBgColor);
        {
            ImGui::SetCursorPos({ childWindowPadding,childWindowPadding });
            shadow(classWindowWidth, classWindowHeight);
            ImGui::BeginChild("lineRegexFilterWindow", ImVec2(classWindowWidth, classWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

            for (auto& graphName : graphNameToLineNameToRegex) {
                if (ImGui::TreeNodeEx(graphName.first.data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                    for (auto& lineName : graphName.second) {
                        if (ImGui::TreeNodeEx(lineName.first.data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                            for (auto& regex : lineName.second) {
                                int selectedFlag = 0;
                                if (positionInRegexSelectedIndex.count(graphName.first) and
                                    positionInRegexSelectedIndex[graphName.first].count(lineName.first) and
                                    positionInRegexSelectedIndex[graphName.first][lineName.first].count(regex)) {
                                    selectedFlag = ImGuiTreeNodeFlags_Selected;
                                }
                                if (ImGui::TreeNodeEx(regex.data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_Leaf | selectedFlag)) {
                                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0)) {
                                        if (not positionInRegexSelectedIndex.count(graphName.first)) {
                                            positionInRegexSelectedIndex[graphName.first] = map<string, set<string>>();
                                        }
                                        if (not positionInRegexSelectedIndex[graphName.first].count(lineName.first)) {
                                            positionInRegexSelectedIndex[graphName.first][lineName.first] = set<string>();
                                        }
                                        if (not positionInRegexSelectedIndex[graphName.first][lineName.first].count(regex)) {
                                            positionInRegexSelectedIndex[graphName.first][lineName.first].insert(regex);
                                        } else {
                                            positionInRegexSelectedIndex[graphName.first][lineName.first].erase(regex);
                                        }
                                        if (positionInRegexSelectedIndex[graphName.first][lineName.first].empty()) {
                                            positionInRegexSelectedIndex[graphName.first].erase(lineName.first);
                                        }
                                        if (positionInRegexSelectedIndex[graphName.first].empty()) {
                                            positionInRegexSelectedIndex.erase(graphName.first);
                                        }
                                        app::Application::searchNodeByPositionInRegex(positionInRegexSelectedIndex,searchResults2);
                                    }
                                    ImGui::TreePop();
                                }
                            }
                            ImGui::TreePop();
                        }
                    }
                    ImGui::TreePop();
                }
            }

            ImGui::EndChild();
        }
        // adjust start
        ImGui::SetCursorPos({ childWindowPadding,classWindowHeight + childWindowPadding });
        ImGui::Button("##heightAdjust1", { classWindowWidth,childWindowSpacing / 2 });
        static bool adjustWindowDragFirst = false;
        if (ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowDragFirst = true;
        }
        if (adjustWindowDragFirst and ImGui::IsKeyReleased(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowDragFirst = false;
        }
        if (adjustWindowDragFirst) {
            float mousePosRelative = ImGui::GetMousePos().y - (mainWindowHeight - (childWindowHeight - 2 * childWindowPadding)) / 2;
            float ratio1 = mousePosRelative / (childWindowHeight - 2 * childWindowPadding);
            float ratio2 = 1 - lineWindowRatio - ratio1;
            if ((classScopeWindowRatio > 0.1f or ratio1 > classScopeWindowRatio) and (nodeWindowRatio > 0.1f or ratio2 > nodeWindowRatio)) {
                classScopeWindowRatio = ratio1;
                nodeWindowRatio = ratio2;
                forceRelayout();
            }
        }
        // adjust end
        {
            ImGui::SetCursorPos({ childWindowPadding,nodeWindowTop });
            shadow(classWindowWidth, nodeWindowHeight);
            ImGui::BeginChild("nodeFilterWindow", ImVec2(classWindowWidth, nodeWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

            for (auto& nodeName : SimpleView::SimpleViewToGraphConverter::nodeNameOrder) {
                if (ImGui::Selectable(nodeName.data(), nodeNameSelectedIndex.count(nodeName.data()))) {
                    if (nodeNameSelectedIndex.count(nodeName.data())) {
                        nodeNameSelectedIndex.erase(nodeName.data());
                    } else {
                        nodeNameSelectedIndex.insert(nodeName.data());
                    }
                    std::thread worker([&]() {
                        PL_thread_attach_engine(NULL);

                        set<const char*> addressableKey;
                        for (auto& nodeNameI : nodeNameSelectedIndex) {
                            auto& node = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeNameI];
                            node->resolve(&loadingAddressableProgress);
                            FOR_EACH_ITEM(node->resolvedList, addressableKey.insert(item.data()););
                        }
                        app::Application::searchNodeByAddressableKey(addressableKey, searchResults2);

                        PL_thread_destroy_engine();
                        });
                    worker.detach();
                }
            }

            ImGui::EndChild();
        }
        // adjust start
        ImGui::SetCursorPos({ childWindowPadding, adjustButton2Top });
        ImGui::Button("##heightAdjust2", { classWindowWidth,childWindowSpacing / 2 });
        static bool adjustWindowDragSecond = false;
        if (ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowDragSecond = true;
        }
        if (adjustWindowDragSecond and ImGui::IsKeyReleased(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowDragSecond = false;
        }
        if (adjustWindowDragSecond) {
            float mousePosRelative = ImGui::GetMousePos().y - (mainWindowHeight - (childWindowHeight - 2 * childWindowPadding)) / 2;
            float ratio1 = mousePosRelative / (childWindowHeight - 2 * childWindowPadding) - classScopeWindowRatio;
            float ratio2 = 1 - classScopeWindowRatio - ratio1;
            if ((nodeWindowRatio > 0.1f or ratio1 > nodeWindowRatio) and (lineWindowRatio > 0.1f or ratio2 > lineWindowRatio)) {
                nodeWindowRatio = ratio1;
                lineWindowRatio = ratio2;
                forceRelayout();
            }
        }
        // adjust end
        {
            ImGui::SetCursorPos({ childWindowPadding, lineWindowTop });
            shadow(classWindowWidth, lineWindowHeight);
            ImGui::BeginChild("runtimeFilterWindow", ImVec2(classWindowWidth, lineWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);
            ImGuiListClipper clipper;
            clipper.Begin(methodOfRuntime.size());
            while (clipper.Step()) {
                for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
                    if (ImGui::Selectable(methodOfRuntime[i], methodOfRuntimeSelectedIndex.count(i))) {
                        if (methodOfRuntimeSelectedIndex.count(i)) {
                            methodOfRuntimeSelectedIndex.erase(i);
                        } else {
                            methodOfRuntimeSelectedIndex.insert(i);
                        }
                        set<const char*> methods;
                        FOR_EACH_ITEM(methodOfRuntimeSelectedIndex, methods.insert(methodOfRuntime[item]););
                        app::Application::searchNodeByMethodOfRuntime(methods, searchResults2);
                        clearSelectedNode();
                    }
                    ImGui::SetItemTooltip(methodOfRuntime[i]);
                }
            }

            ImGui::EndChild();
        }

        ImGui::PopStyleColor(1);
        ImGui::EndChild();
        // selector window end

        // result window start
        ImGui::SetCursorPos({ editWindowWidth + mainWindowPadding + spacingHor,mainWindowPadding });
        ImGui::BeginChild("filteredResultWindow", ImVec2(displayWindowWidth, childWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, panelBgColor);

        // adjust window start
        ImGui::SetCursorPos({ searchBarLeft - childWindowPadding,childWindowPadding });
        ImGui::Button("##widthAdjust3", { childWindowPadding,childWindowHeight - 2 * childWindowPadding });
        static bool adjustWindowWidthDrag = false;
        if (ImGui::IsItemHovered() && ImGui::IsKeyPressed(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowWidthDrag = true;
        }
        if (adjustWindowWidthDrag and ImGui::IsKeyReleased(ImGuiKey::ImGuiKey_MouseLeft)) {
            adjustWindowWidthDrag = false;
        }
        if (adjustWindowWidthDrag) {
            float mousePosRelative = ImGui::GetMousePos().x - (mainWindowWidth - (searchWindowWidth - mainWindowPadding * 2 - spacingHor)) / 2;
            float ratio1 = 1 - mousePosRelative / (searchWindowWidth - mainWindowPadding * 2 - spacingHor);
            if ((searchBarRatio > 0.1f or ratio1 > searchBarRatio) and ((1 - searchBarRatio) > 0.1f or (1 - ratio1) > (1 - searchBarRatio))) {
                searchBarRatio = ratio1;
                forceRelayout();
            }
        }
        // adjust window end

        {
            ImGui::SetCursorPos({ searchBarLeft,childWindowPadding });
            shadow(searchBarWidth, searchBarHeight);
            if (ImGui::InputTextEx("##searchNodeInGraph", searchResults2.empty() ? StringRes::singleton->getSearchNodeInGraph() : StringRes::singleton->getSearchExisting(),
                searchedStr, 1024, { searchBarWidth,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_EnterReturnsTrue)) {
                ImGui::SetKeyboardFocusHere(-1);
                if (searchResults2.empty()) {
                    app::Application::searchNodeInGraph(searchedStr, searchResults2);
                } else {
                    filterSearchResults(searchResults2);
                }
                clearSelectedNode();
            }

        }
        {
            ImGui::SetCursorPos({ searchBarLeft, childWindowPadding + searchBarHeight + childWindowSpacing });
            shadow(searchBarWidth, searchResultHeight);
            ImGui::BeginChild("filteredResultPanel", ImVec2(searchBarWidth, searchResultHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
            ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));

            ImGuiListClipper clipper;
            clipper.Begin(searchResults2.size());
            while (clipper.Step()) {
                for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
                    if (ImGui::Selectable(searchResults2[i], nodeKeySelectedIndex.count(i))) {
                        if (lastSelectedNodeKey > -1 and (ImGui::IsKeyDown(ImGuiKey::ImGuiKey_LeftShift) or ImGui::IsKeyDown(ImGuiKey::ImGuiKey_RightShift))) {
                            int min;
                            int max;
                            if (lastSelectedNodeKey < i) {
                                min = lastSelectedNodeKey;
                                max = i;
                            } else {
                                max = lastSelectedNodeKey;
                                min = i;
                            }
                            for (int j = min;j <= max;j++) {
                                nodeKeySelectedIndex.insert(j);
                            }
                        } else {
                            if (nodeKeySelectedIndex.count(i)) {
                                nodeKeySelectedIndex.erase(i);
                            } else {
                                nodeKeySelectedIndex.insert(i);
                            }
                        }
                        lastSelectedNodeKey = i;
                    }
                    ImGui::SetItemTooltip(searchResults2[i]);
                }
            }


            ImGui::PopStyleVar();
            ImGui::EndChild();
        }
        ImGui::PopStyleColor(1);
        ImGui::EndChild();

        // result window end
        ImGui::End();
        ImGui::PopStyleColor(5);
        ImGui::PopStyleVar();
    }
}
