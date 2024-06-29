#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "imRejectDialog.h"
#include "imProgressDialog.h"
namespace shishan {

    static list<string> createdString;
    static char searchedStr[1024];
    static vector<const char*> searchResults;

    static void shadow(float width, float height) {
        ImVec2 p = ImGui::GetCursorScreenPos();
        ImVec2 r(p.x + width, p.y + height);
        ImGui::GetWindowDrawList()->AddShadowRect(p, r, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 1.0f }), 40.0f, { 0.f,0.f }, ImDrawFlags_ShadowCutOutShapeBackground, 0.f);
    }

    // layout spec
    static bool showGraphList = false;
    static ImVec2 lastWindowSize = { 0,0 };

    static float classScopeWindowRatio = 0.3f;
    static float nodeWindowRatio = 0.3f;
    static float lineWindowRatio = 0.4f;
    static float searchBarRatio = 0.4f;

    static float mainWindowWidth = 0;
    static float mainWindowHeight = 0;
    static float searchWindowWidth = 0;
    static float searchWindowHeight = 0;
    static float mainWindowPadding = 0;
    static float spacingHor = 0;
    static float editWindowWidth = 0;
    static float displayWindowWidth = 0;
    static float childWindowHeight = 0;
    static float childWindowPadding = 0;
    static float childWindowSpacing = 0;
    static float heigthRemovingPadding = 0;
    static float classWindowWidth = 0;
    static float classWindowHeight = 0;
    static float nodeWindowTop = 0;
    static float nodeWindowHeight = 0;
    static float lineWindowTop = 0;
    static float lineWindowHeight = 0;
    static float dividerWidth = 0;
    static float graphItem1Width = 0;
    static float graphItem2Width = 0;
    static float graphItem3Width = 0;
    static float graphWindowTop = 0;
    static float graphWindowHeight = 0;
    static float searchBarWidth = 0;
    static float searchBarLeft = 0;
    static float searchBarHeight = 0;
    static float searchResultHeight = 0;
    static float adjustButton2Top = 0;

    static void forceRelayout() {
        lastWindowSize = { 0,0 };
    }

    static void updateLayoutSpec(ImVec2& windowSize) {
        if (lastWindowSize.x != windowSize.x || lastWindowSize.y != windowSize.y) {
            lastWindowSize = windowSize;
            mainWindowWidth = windowSize.x;
            mainWindowHeight = windowSize.y;
            searchWindowWidth = mainWindowWidth * 0.95f;
            searchWindowHeight = mainWindowHeight * 0.95f;
            mainWindowPadding = 0.01f * mainWindowHeight;
            spacingHor = 0.0f; //0.01f * mainWindowWidth;
            editWindowWidth = (searchWindowWidth - mainWindowPadding * 2 - spacingHor) * (1 - searchBarRatio);
            displayWindowWidth = (searchWindowWidth - mainWindowPadding * 2 - spacingHor) * searchBarRatio;
            childWindowHeight = searchWindowHeight - mainWindowPadding * 2;
            childWindowPadding = 0.01f * searchWindowWidth;
            childWindowSpacing = 0.01f * searchWindowWidth;
            heigthRemovingPadding = childWindowHeight - 2 * childWindowPadding - 2 * childWindowSpacing;
            classWindowWidth = editWindowWidth - 2 * childWindowPadding;
            classWindowHeight = heigthRemovingPadding * classScopeWindowRatio;
            nodeWindowTop = showGraphList ? childWindowPadding : classWindowHeight + childWindowPadding + childWindowSpacing;
            nodeWindowHeight = heigthRemovingPadding * (showGraphList ? classScopeWindowRatio : nodeWindowRatio);
            lineWindowTop = showGraphList ? nodeWindowHeight + childWindowPadding + childWindowSpacing : classWindowHeight + nodeWindowHeight + childWindowPadding + 2 * childWindowSpacing;
            lineWindowHeight = heigthRemovingPadding * (showGraphList ? nodeWindowRatio : lineWindowRatio);
            dividerWidth = childWindowPadding / 2;
            graphItem1Width = (classWindowWidth - dividerWidth * 2) * 0.3f;
            graphItem2Width = (classWindowWidth - dividerWidth * 2) * 0.4f;
            graphItem3Width = (classWindowWidth - dividerWidth * 2) * 0.3f;
            graphWindowTop = nodeWindowHeight + lineWindowHeight + childWindowPadding + 2 * childWindowSpacing;
            graphWindowHeight = heigthRemovingPadding * lineWindowRatio;
            searchBarWidth = displayWindowWidth - 2 * childWindowPadding;
            searchBarLeft = (displayWindowWidth - searchBarWidth) / 2;
            searchBarHeight = 1.2f * ImGui::GetFontSize();
            searchResultHeight = childWindowHeight - searchBarHeight - 2 * childWindowPadding - childWindowSpacing;
            adjustButton2Top = showGraphList ? nodeWindowHeight + childWindowPadding + lineWindowHeight + childWindowSpacing
                : classWindowHeight + childWindowPadding + nodeWindowHeight + childWindowSpacing;
        }
    }

    // class scope
    static int classScopeSelectedIndex = -1;
    static int classScopeKeyDownIndex = -1;
    static int classScopeEditingIndex = -1;
    static char classScopeEditingName[1000];
    static int classScopeEditingTypeIndex = -1;
    const static char* classScopeTypes[] = { "full path","list","in package","used by","use","super","sub","intersection","union","difference","var" };
    static vector<const char*> classScopeEditValues;
    static int classScopeEditValueSelectedIndex = 0;

    // node
    static int nodeSelectedIndex = -1;
    static int nodeKeyDownIndex = -1;
    static int nodeEditingIndex = -1;
    static char nodeEditingName[1000];
    static int nodeEditingTypeIndex = -1;
    const static char* nodeTypes[] = { "full path","list","fieldOf","instanceOf","methodOf","constructorOf","parameterOf","returnOf","calledMethod","calledParameter","calledReturn","intersection","union","difference","var" };
    static vector<const char*> nodeEditValues;
    static vector<const char*> typeKeyForNodeKey;
    static char* openedTypeKey;
    static int nodeEditValueSelectedIndex = 0;

    // line
    static int lineSelectedIndex = -1;
    static int lineKeyDownIndex = -1;
    static int lineEditingIndex = -1;
    static SimpleView::LineInstance* lineNewFinalInstance = NULL;
    static char lineEditingName[1000];
    static int lineEditingTypeIndex = -1;
    static bool lineIsAlternation = false;
    // todo ,"code order"
    const static char* lineTypes[] = { "segment","line" };
    static vector<const char*> lineEditValues;
    static map<int, int> nodeInLineIdMap;
    static vector<int> lineEditRepeatTypes;
    static int lineEditValueSelectedIndex = 0;

    // graph
    static int graphSelectedIndex = 0;
    static int graphKeyDownIndex = -1;
    static int graphEditingIndex = -1;
    static SimpleView::GraphInstance* graphNewInstance = NULL;
    static char graphEditingName[1000];
    static map<int, int> lineInGraphIdMap;

    // line instance in graph
    static int lineInstanceSelectedIndex = 0;
    static int lineInstanceEditingIndex = -1;
    static int lineInstanceNewIndex = -1;
    static SimpleView::LineInstance* editingLineInstance = NULL;
    static vector<const char*> lineInstanceArgEditValues;
    static int lineInstanceArgSelectedIndex = 0;
    static char lineInstanceArgParaName[1000];

    // intersection point editing
    static int intersectionPointEditingIndex = -1;

    // line instance
    static int lineFinalInstanceSelectedIndex = -1;
    static int lineFinalInstanceKeyDownIndex = -1;
    static int lineFinalInstanceEditingIndex = -1;
    static int lineFinalInstanceArgSelectedIndex = 0;
    static int lineFinalInstanceNameEditingIndex = -1;
    static char lineFinalInstanceEditingName[1000];
    static char lineNewFinalInstanceName[1000];

    // graph instance
    static int graphInstanceSelectedIndex = -1;
    static int graphInstanceKeyDownIndex = -1;
    static int graphInstanceEditingIndex = -1;
    static int graphInstanceArgSelectedIndex = 0;
    static int graphInstanceNameEditingIndex = -1;
    static char graphInstanceEditingName[1000];
    static char graphNewInstanceName[1000];

    // edit constraints
    class DependencyConstraint {
    public:
        list<int> dependencyLower;
        list<int> dependencyHigher;

        void clear() {
            dependencyLower.clear();
            dependencyHigher.clear();
        }
        bool findInLowerBound(int i) {
            return std::find(dependencyLower.begin(), dependencyLower.end(), i) != dependencyLower.end();
        }
        bool findInHigherBound(int i) {
            return std::find(dependencyHigher.begin(), dependencyHigher.end(), i) != dependencyHigher.end();
        }
        bool isInBound(int i) {
            return (dependencyLower.empty() or i > dependencyLower.back())
                && (dependencyHigher.empty() or i < dependencyHigher.front());
        }
        bool hasNoHigherDependency() {
            return dependencyHigher.empty();
        }
    };

    static DependencyConstraint classScopeDependencyConstraint;
    static DependencyConstraint nodeDependencyConstraint;
    static DependencyConstraint lineDependencyConstraint;
    static DependencyConstraint graphDependencyConstraint;
    static DependencyConstraint lineInstanceDependencyConstraint;
    static DependencyConstraint graphInstanceDependencyConstraint;

    static void clearAllDependency() {
        classScopeDependencyConstraint.clear();
        nodeDependencyConstraint.clear();
        lineDependencyConstraint.clear();
        graphDependencyConstraint.clear();
        lineInstanceDependencyConstraint.clear();
        graphInstanceDependencyConstraint.clear();
    }

    static bool isNothingEditing() {
        return classScopeEditingIndex < 0
            and nodeEditingIndex < 0
            and lineEditingIndex < 0
            and graphEditingIndex < 0
            and lineInstanceEditingIndex < 0
            and intersectionPointEditingIndex < 0
            and lineInstanceNewIndex < 0
            and lineFinalInstanceEditingIndex < 0
            and graphInstanceEditingIndex < 0
            and lineNewFinalInstance == NULL
            and graphNewInstance == NULL
            and lineFinalInstanceNameEditingIndex < 0
            and graphInstanceNameEditingIndex < 0;
    }

    /** type:
     *  1 for class scope | _ -> [class scope] -> node
     *  2 for node   |  class scope -> [node] -> line / line argument
     *  3 for line   |  node -> [line] -> graph / line final instance
     *  4 for graph  |  line -> [graph] -> graph instance
     *                  node -> [line argument] -> _
     *  5 for line final instance
     *               |  node / line -> line instance -> _
     *  6 for graph instance
     *               | node / graph -> graph instance -> _
    */
    static void updateDependencyLowerAndHigher(int downElementIndex, int type) {
        if (not isNothingEditing()) {
            return;
        }
        clearAllDependency();
        switch (type) {
        case 1:
            EasierSimpleView::getDependencyBoundsForClassScope(downElementIndex,
                classScopeDependencyConstraint.dependencyLower,
                classScopeDependencyConstraint.dependencyHigher,
                nodeDependencyConstraint.dependencyHigher
            );
            break;
        case 2:
            EasierSimpleView::getDependencyBoundsForNode(downElementIndex,
                classScopeDependencyConstraint.dependencyLower,
                nodeDependencyConstraint.dependencyLower,
                nodeDependencyConstraint.dependencyHigher,
                lineDependencyConstraint.dependencyHigher,
                graphDependencyConstraint.dependencyHigher,
                lineInstanceDependencyConstraint.dependencyHigher,
                graphInstanceDependencyConstraint.dependencyHigher
            );
            break;
        case 3:
            EasierSimpleView::getDependencyBoundsForLine(downElementIndex,
                nodeDependencyConstraint.dependencyLower,
                lineDependencyConstraint.dependencyLower,
                lineDependencyConstraint.dependencyHigher,
                graphDependencyConstraint.dependencyHigher,
                lineInstanceDependencyConstraint.dependencyHigher
            );
            break;
        case 4:
            EasierSimpleView::getDependencyBoundsForGraph(downElementIndex,
                nodeDependencyConstraint.dependencyLower,
                lineDependencyConstraint.dependencyLower,
                graphInstanceDependencyConstraint.dependencyHigher
            );
            break;
        case 5:
            EasierSimpleView::getDependencyBoundsForLineInstance(downElementIndex,
                nodeDependencyConstraint.dependencyLower,
                lineDependencyConstraint.dependencyLower
            );
            break;
        case 6:
            EasierSimpleView::getDependencyBoundsForGraphInstance(downElementIndex,
                nodeDependencyConstraint.dependencyLower,
                graphDependencyConstraint.dependencyLower
            );
            break;
        }
    }

    void onExitEditMode() {
        classScopeEditValueSelectedIndex = 0;
        nodeEditValueSelectedIndex = 0;
        lineEditValueSelectedIndex = 0;
        nodeInLineIdMap.clear();
        lineEditRepeatTypes.clear();
        lineInGraphIdMap.clear();
        editingLineInstance = NULL;
        lineInstanceArgEditValues.clear();
    }

    static bool isEditValueIsActuallyHint(vector<const char*>& editValues) {
        for (auto& v : editValues) {
            int i = 0;
            while (v[i] != '\0') {
                if (v[i] == ' ') {
                    return true;
                }
                i++;
            }
        }
        return false;
    }

    static bool checkValNameCommon(const char* name) {
        // check for alphabet
        if (not isalpha(name[0])) {
            return false;
        }
        int i = 1;
        while (name[i] != '\0') {
            if (not isalpha(name[i]) and not isdigit(name[i]) and not (name[i] == '_')) {
                return false;
            }
            i++;
        }
        // check for keywords
        for (auto& v : EasierSimpleView::vocabularySymbolToLiteral) {
            if (strcmp(name, v.second.data()) == 0) {
                return false;
            }
        }
        if (strcmp(name, "unnamed") == 0) {
            return false;
        }
        return true;
    }

    // type: 
    // 1 for class name
    // 2 for node name
    // 3 for line name
    // 4 for graph name
    // 5 for line parameter name or graph parameter name
    // 6 for line final instance argument
    // 7 for graph instance argument
    static bool checkValName(const char* name, int editingIndex, int type) {
        if (not checkValNameCommon(name)) {
            return false;
        }
        // check for duplicate name
        switch (type) {
        case 1:
            // 1 for class name
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        case 2:
            // 2 for node name
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            for (auto& v : SimpleView::SimpleViewToGraphConverter::valNameToNode) {
                if (v.second->nodeType == SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH and strcmp(name, v.first.data()) == 0) {
                    return false;
                }
            }
            break;
        case 3:
            // 3 for line name
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::lineNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size();i++) {
                if (strcmp(name, SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        case 4:
            // 4 for graph name
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::graphNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size();i++) {
                if (strcmp(name, SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        case 5:
            // 5 for line parameter name or graph parameter name
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size();i++) {
                if (strcmp(name, SimpleView::SimpleViewToGraphConverter::nodeNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        case 6:
            // 6 for line final instance argument
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size();i++) {
                if (strcmp(name, SimpleView::SimpleViewToGraphConverter::lineNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        case 7:
            // 7 for graph instance argument
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size();i++) {
                if (i != editingIndex and strcmp(name, SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            for (int i = 0;i < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size();i++) {
                if (strcmp(name, SimpleView::SimpleViewToGraphConverter::graphNameOrder[i].data()) == 0) {
                    return false;
                }
            }
            break;
        }
        return true;
    }

    void static deleteClassScopeAtIndex(int index) {
        auto classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[
            SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index]
        ];
        SimpleView::SimpleViewToGraphConverter::valNameToClassScope.erase(
            SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index]
        );
        SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.erase(SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.begin() + index);
        delete classScope;
    }

    void static deleteNodeAtIndex(int index) {
        auto node = SimpleView::SimpleViewToGraphConverter::valNameToNode[
            SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index]
        ];
        SimpleView::SimpleViewToGraphConverter::valNameToNode.erase(
            SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index]
        );
        SimpleView::SimpleViewToGraphConverter::nodeNameOrder.erase(SimpleView::SimpleViewToGraphConverter::nodeNameOrder.begin() + index);
        delete node;
    }

    void static deleteLineAtIndex(int index) {
        auto line = SimpleView::SimpleViewToGraphConverter::valNameToLine[
            SimpleView::SimpleViewToGraphConverter::lineNameOrder[index]
        ];
        SimpleView::SimpleViewToGraphConverter::valNameToLine.erase(
            SimpleView::SimpleViewToGraphConverter::lineNameOrder[index]
        );
        SimpleView::SimpleViewToGraphConverter::lineNameOrder.erase(SimpleView::SimpleViewToGraphConverter::lineNameOrder.begin() + index);
        delete line;
    }

    void static deleteLineInstanceAtIndex(int index) {
        auto lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[index]
        ];
        SimpleView::SimpleViewToGraphConverter::valNameToLineInstance.erase(
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[index]
        );
        SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.erase(SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.begin() + index);
        delete lineInstance;
    }

    void static deleteGraphInstanceAtIndex(int index) {
        auto graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[index]
        ];
        SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance.erase(
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[index]
        );
        SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.erase(SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.begin() + index);
        delete graphInstance;
    }

    template<typename T>
    static T changeNameOfNameOrderAndValNameTo(vector<string>& orderedName, map<string, T>& valNameTo, int index, char* newName) {
        T item = valNameTo[orderedName[index]];
        valNameTo.erase(orderedName[index]);
        orderedName[index] = newName;
        valNameTo[orderedName[index]] = item;
        return item;
    }

    static void addClassEditItem(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##editingClassScopName", "", classScopeEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);ImGui::SameLine();
        ImGui::Text("type: "); ImGui::SameLine();
        ImGui::SetNextItemWidth(6 * fontSize);
        if (ImGui::Combo("##editingClassScopType", &classScopeEditingTypeIndex, classScopeTypes, IM_ARRAYSIZE(classScopeTypes))) {
            classScopeEditValues.clear();
            switch (classScopeEditingTypeIndex) {
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_KEY:
                classScopeEditValues.push_back("Click class on the right to choose");
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_LIST:
                classScopeEditValues.push_back("Click class on the right to add, double click me to delete");
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_IN_PACKAGE:
                classScopeEditValues.push_back("Click class on the right to choose package");
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_USED_BY:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_USE:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUPER:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUB:
                classScopeEditValues.push_back("Click class you created above to choose");
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_INTERSECTION:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_UNION:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_DIFFERENCE:
                classScopeEditValues.push_back("Click me first, then click class you created above to replace,");
                classScopeEditValues.push_back("Click me first, then click class you created above to replace.");
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_VAR:
                classScopeEditValues.push_back("Click class you created above to choose");
                break;
            }
        }
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2 * fontSize);
        // will be set to false when the rejecting dialog is closed;
        static bool classScopeNameIsWrong = false;
        static bool classScopeValueIsWrong = false;
        if (ImGui::Button("OK##classScopeEditOK", { fontSize * 3,searchBarHeight })) {
            classScopeNameIsWrong = not checkValName(classScopeEditingName, classScopeEditingIndex, 1);
            if (isEditValueIsActuallyHint(classScopeEditValues)) {
                classScopeValueIsWrong = true;
            }
            if (not classScopeNameIsWrong and not classScopeValueIsWrong) {
                // commit change
                auto classScope = changeNameOfNameOrderAndValNameTo<SimpleView::ClassScope*>(
                    SimpleView::SimpleViewToGraphConverter::classScopeNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToClassScope, classScopeEditingIndex, classScopeEditingName
                );
                classScope->resetValue(classScopeEditingName, classScopeEditingTypeIndex, classScopeEditValues);
                if (classScope->editingNew) {
                    classScope->editingNew = false;
                }
                classScopeEditingIndex = -1;
                classScopeEditValues.clear();
                onExitEditMode();
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##classScopeEditCancel", { fontSize * 3,searchBarHeight })) {
            auto classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[
                SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[classScopeEditingIndex]
            ];
            if (classScope->editingNew) {
                deleteClassScopeAtIndex(classScopeEditingIndex);
            }
            classScopeEditingIndex = -1;
            classScopeEditValues.clear();
            onExitEditMode();
        } else {
            for (int i = 0;i < classScopeEditValues.size();i++) {
                ImGui::PushID(i);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                ImGui::Text("value: ");
                ImGui::SameLine();
                if (ImGui::Selectable(classScopeEditValues[i], classScopeEditValueSelectedIndex == i)) {
                    classScopeEditValueSelectedIndex = i;
                }
                if (classScopeEditingTypeIndex == SimpleView::ClassScope::CLASS_SCOPE_TYPE_LIST) {
                    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                        classScopeEditValues.erase(classScopeEditValues.begin() + classScopeEditValueSelectedIndex);
                    }
                }
                ImGui::PopID();
            }
        }
        if (classScopeNameIsWrong) {
            classScopeValueIsWrong = false;
            showRejectDialog("wrong name or duplicate name or it is a keyword", &classScopeNameIsWrong);
        } else {
            if (classScopeValueIsWrong) {
                showRejectDialog("wrong value", &classScopeValueIsWrong);
            }
        }
    }

    static void addNodeEditItem(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##editingNodeName", "", nodeEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);ImGui::SameLine();
        ImGui::Text("type: "); ImGui::SameLine();
        ImGui::SetNextItemWidth(8 * fontSize);
        if (ImGui::Combo("##editingNodeType", &nodeEditingTypeIndex, nodeTypes, IM_ARRAYSIZE(nodeTypes))) {
            nodeEditValues.clear();
            switch (nodeEditingTypeIndex) {
            case SimpleView::Node::NODE_TYPE_KEY:
                nodeEditValues.push_back("Click field/method/param/return on the right");
                typeKeyForNodeKey.push_back(NULL);
                break;
            case SimpleView::Node::NODE_TYPE_LIST:
                nodeEditValues.push_back("Click field/method/param/return on the right to add, double click me to delete");
                typeKeyForNodeKey.push_back(NULL);
                break;
            case SimpleView::Node::NODE_TYPE_FIELD_OF:
            case SimpleView::Node::NODE_TYPE_METHOD_OF:
            case SimpleView::Node::NODE_TYPE_CREATOR:
                nodeEditValues.push_back("Click class you created above");
                break;
            case SimpleView::Node::NODE_TYPE_PARAMETER_OF:
            case SimpleView::Node::NODE_TYPE_RETURN_OF:
                nodeEditValues.push_back("Click method you created above");
                break;
            case SimpleView::Node::NODE_TYPE_INSTANCE_OF:
                nodeEditValues.push_back("Click me first, then click class you created above");
                nodeEditValues.push_back("Click me first, then click class you created above");
                break;
            case SimpleView::Node::NODE_TYPE_CALLED_METHOD_OF:
                nodeEditValues.push_back("Click method you created above");
                break;
            case SimpleView::Node::NODE_TYPE_CALLED_PARAMETER_OF:
                nodeEditValues.push_back("Click parameter you created above");
                break;
            case SimpleView::Node::NODE_TYPE_CALLED_RETURN_OF:
                nodeEditValues.push_back("Click return you created above");
                break;
            case SimpleView::Node::NODE_TYPE_INTERSECTION:
            case SimpleView::Node::NODE_TYPE_UNION:
            case SimpleView::Node::NODE_TYPE_DIFFERENCE:
                nodeEditValues.push_back("Click me first, then click field/method/param/return you created above");
                nodeEditValues.push_back("Click me first, then click field/method/param/return you created above");
                break;
            case SimpleView::Node::NODE_TYPE_VAR:
                nodeEditValues.push_back("Click node you created above");
                break;
            }
        }
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2 * fontSize);
        static bool nodeNameIsWrong = false;
        static bool nodeValueIsWrong = false;
        if (ImGui::Button("OK##nodeEditOK", { fontSize * 3,searchBarHeight })) {
            nodeNameIsWrong = not checkValName(nodeEditingName, nodeEditingIndex, 2);
            if (isEditValueIsActuallyHint(nodeEditValues)) {
                nodeValueIsWrong = true;
            }
            if (not nodeNameIsWrong and not nodeValueIsWrong) {
                auto node = changeNameOfNameOrderAndValNameTo<SimpleView::Node*>(
                    SimpleView::SimpleViewToGraphConverter::nodeNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToNode, nodeEditingIndex, nodeEditingName
                );
                node->resetValue(nodeEditingName, nodeEditingTypeIndex, nodeEditValues, typeKeyForNodeKey);
                if (node->editingNew) {
                    node->editingNew = false;
                }
                nodeEditingIndex = -1;
                nodeEditValues.clear();
                typeKeyForNodeKey.clear();
                onExitEditMode();
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##nodeEditCancel", { fontSize * 3,searchBarHeight })) {
            auto node = SimpleView::SimpleViewToGraphConverter::valNameToNode[
                SimpleView::SimpleViewToGraphConverter::nodeNameOrder[nodeEditingIndex]
            ];
            if (node->editingNew) {
                deleteNodeAtIndex(nodeEditingIndex);
            }
            nodeEditingIndex = -1;
            nodeEditValues.clear();
            typeKeyForNodeKey.clear();
            onExitEditMode();
        } else {
            for (int i = 0;i < nodeEditValues.size();i++) {
                ImGui::PushID(i);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                ImGui::Text("value: ");
                ImGui::SameLine();
                if (ImGui::Selectable(nodeEditValues[i], nodeEditValueSelectedIndex == i)) {
                    nodeEditValueSelectedIndex = i;
                }
                if (nodeEditingTypeIndex == SimpleView::Node::NODE_TYPE_LIST) {
                    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                        nodeEditValues.erase(nodeEditValues.begin() + nodeEditValueSelectedIndex);
                        typeKeyForNodeKey.erase(typeKeyForNodeKey.begin() + nodeEditValueSelectedIndex);
                    }
                }
                ImGui::PopID();
            }
        }
        if (nodeNameIsWrong) {
            nodeValueIsWrong = false;
            showRejectDialog("wrong name or duplicate name or it is a keyword", &nodeNameIsWrong);
        } else {
            if (nodeValueIsWrong) {
                showRejectDialog("wrong value", &nodeValueIsWrong);
            }
        }
    }

    static void cleanLineEditIfItIsHint() {
        if (isEditValueIsActuallyHint(lineEditValues)) {
            lineEditValues.clear();
            lineEditRepeatTypes.clear();
            lineEditValueSelectedIndex = -1;
        }
        if (lineEditValueSelectedIndex >= lineEditValues.size()) {
            lineEditValueSelectedIndex = lineEditValues.size() - 1;
        }
    }

    static void insertIntersectionPointInLineTemplate(const char* insertedName, bool isInsertedSeg, int i) {
        auto& editedLineTemplate = SimpleView::SimpleViewToGraphConverter::valNameToLine[
            SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineEditingIndex]
        ];
        for (auto& graphInstanceName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
            auto& depHighGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphInstanceName];
            depHighGraph->insertPointInLineTemplate(editedLineTemplate->name.data(), insertedName, isInsertedSeg, i);
        }
    }

    static bool deleteIntersectionPointInLineTemplate(int i) {
        bool ret = true;
        for (auto& graphInstanceName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
            auto& depHighGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphInstanceName];
            ret = ret and depHighGraph->removePointInLineTemplate(SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineEditingIndex].data(), i);
        }
        return ret;
    }

    static void addSpecialKeyButton(const char* buttonText, SimpleView::Node* specialNode) {
        if (ImGui::Button(buttonText)) {
            cleanLineEditIfItIsHint();
            lineEditValues.insert(lineEditValues.begin() + lineEditValueSelectedIndex + 1, specialNode->displayName.data());
            lineEditRepeatTypes.insert(lineEditRepeatTypes.begin() + lineEditValueSelectedIndex + 1, 0);
            insertIntersectionPointInLineTemplate(specialNode->displayName.data(), false, lineEditValueSelectedIndex + 1);
            lineEditValueSelectedIndex++;
        };
    }

    static void addLineEditItem(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##editingLineName", "", lineEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);ImGui::SameLine();
        ImGui::Text("type: "); ImGui::SameLine();
        ImGui::SetNextItemWidth(6 * fontSize);
        if (ImGui::Combo("##linegNodeType", &lineEditingTypeIndex, lineTypes, IM_ARRAYSIZE(lineTypes))) {
            lineEditValues.clear();
            lineEditRepeatTypes.clear();
            switch (lineEditingTypeIndex) {
            case SimpleView::LineTemplate::LINE_TYPE_SEGMENT:
                lineEditValues.push_back("Click field/method/param/return you created above");
                lineEditRepeatTypes.push_back(0);
                break;
            case SimpleView::LineTemplate::LINE_TYPE_DATA_FLOW:
                lineEditValues.push_back("Click field/method/param/return you created above");
                lineEditRepeatTypes.push_back(0);
                break;
            case SimpleView::LineTemplate::LINE_TYPE_CODE_ORDER:
                lineEditValues.push_back("Click field/method/param/return you created above");
                lineEditRepeatTypes.push_back(0);
                break;
            }
        }
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2 * fontSize);
        static bool lineNameIsWrong = false;
        static bool lineValueIsWrong = false;
        static bool parameterNameIsWrong = false;
        static bool lineInvalid = false;
        if (ImGui::Button("OK##lineEditOK", { fontSize * 3,searchBarHeight })) {
            // todo check node count must be greater than 2
            lineNameIsWrong = not checkValName(lineEditingName, lineEditingIndex, 3);
            if (isEditValueIsActuallyHint(lineEditValues) or lineEditValues.size() < 2) {
                lineValueIsWrong = true;
            }
            if (not lineNameIsWrong and not lineValueIsWrong) {
                auto line = changeNameOfNameOrderAndValNameTo<SimpleView::LineTemplate*>(
                    SimpleView::SimpleViewToGraphConverter::lineNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToLine, lineEditingIndex, lineEditingName
                );
                if (line->resetValue(lineEditingName, lineEditingTypeIndex, lineEditValues, lineEditRepeatTypes, lineIsAlternation)) {
                    if (line->editingNew) {
                        line->editingNew = false;
                    }
                    FOR_EACH_ITEM(lineInstanceDependencyConstraint.dependencyHigher,
                        SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[
                            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[item]
                        ]->updateDisplayName();
                                );
                    lineEditingIndex = -1;
                    lineEditValues.clear();
                    lineEditRepeatTypes.clear();
                    onExitEditMode();
                } else {
                    lineInvalid = true;
                }
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##lineEditCancel", { fontSize * 3,searchBarHeight })) {
            auto line = SimpleView::SimpleViewToGraphConverter::valNameToLine[
                SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineEditingIndex]
            ];
            if (line->editingNew) {
                deleteLineAtIndex(lineEditingIndex);
            }
            lineEditingIndex = -1;
            lineEditValues.clear();
            lineEditRepeatTypes.clear();
            onExitEditMode();
        } else {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
            static char paraName[1000] = "";
            // restriction: cannot add a param node if this line is instantiated
            if (lineEditingTypeIndex != SimpleView::LineTemplate::LINE_TYPE_SEGMENT) {
                // add parameter node
                if (ImGui::Button("Parameter##lineParameterNameEditor")) {
                    if (graphDependencyConstraint.dependencyHigher.empty() and lineInstanceDependencyConstraint.dependencyHigher.empty()) {
                        parameterNameIsWrong = not checkValName(paraName, -1, 5);
                        if (not parameterNameIsWrong) {
                            cleanLineEditIfItIsHint();
                            createdString.push_back(paraName);
                            lineEditValues.insert(lineEditValues.begin() + lineEditValueSelectedIndex + 1, createdString.back().data());
                            lineEditRepeatTypes.insert(lineEditRepeatTypes.begin() + lineEditValueSelectedIndex + 1, 0);
                            insertIntersectionPointInLineTemplate(createdString.back().data(), false, lineEditValueSelectedIndex + 1);
                            lineEditValueSelectedIndex++;
                        }
                    } else {
                        // todo show reject dialog to explain to user
                    }
                }
                ImGui::SameLine();
                ImGui::InputTextEx("##addParameterNameInput", "parameter name", paraName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);ImGui::SameLine();
            } else {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
                ImGui::Checkbox("Alternation", &(lineIsAlternation));
                ImGui::SameLine();
            }
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Any##specialNodeAny", SimpleView::Node::NODE_ANY);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Field##specialNodeField", SimpleView::Node::NODE_FIELD);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Parameter##specialNodeParameter", SimpleView::Node::NODE_PARAMETER);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Return##specialNodeReturn", SimpleView::Node::NODE_RETURN);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Method##specialNodeMethod", SimpleView::Node::NODE_METHOD);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Constructor##specialNodeConstructor", SimpleView::Node::NODE_CONSTRUCTOR);

            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("CalledParameter##specialNodeCalledParameter", SimpleView::Node::NODE_CALLED_PARAMETER);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("CalledReturn##specialNodeCalledReturn", SimpleView::Node::NODE_CALLED_RETURN);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("CalledMethod##specialNodeCalled", SimpleView::Node::NODE_CALLED_METHOD);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Condition##specialNodeConndition", SimpleView::Node::NODE_CONDITION);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Else##specialNodeElse", SimpleView::Node::NODE_ELSE);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Reference##specialNodeReference", SimpleView::Node::NODE_REFERENCE);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("Index##specialNodeIndex", SimpleView::Node::NODE_INDEX);

            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("DataStep##specialNodeDataStep", SimpleView::Node::NODE_DATA_STEP);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("DataOverride##specialNodeDataOverride", SimpleView::Node::NODE_DATA_OVERRIDE);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("TimingStep##specialNodeTimingStep", SimpleView::Node::NODE_TIMING_STEP);
            ImGui::SameLine();
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 10);
            addSpecialKeyButton("TimingOverride##specialNodeTimingOverride", SimpleView::Node::NODE_TIMING_OVERRIDE);

            for (int i = 0;i < lineEditValues.size();i++) {
                if (not nodeInLineIdMap.count(i)) {
                    nodeInLineIdMap[i] = i;
                }
                ImGui::PushID(nodeInLineIdMap[i]);
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                ImGui::Text("value: ");
                ImGui::SameLine();
                string repeatTypeStr = " ";
                switch (lineEditRepeatTypes[i]) {
                case SimpleView::LineTemplate::REPEAT_TYPE_ZERO_OR_ONE:
                    repeatTypeStr.push_back('?');
                    break;
                case SimpleView::LineTemplate::REPEAT_TYPE_ZERO_OR_MORE:
                    repeatTypeStr.push_back('*');
                    break;
                case SimpleView::LineTemplate::REPEAT_TYPE_ONE_OR_MORE:
                    repeatTypeStr.push_back('+');
                    break;
                }
                if (ImGui::Selectable((lineEditValues[i] + repeatTypeStr).data(), lineEditValueSelectedIndex == i)) {
                    lineEditValueSelectedIndex = i;
                }
                // delete node in line
                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                    // restriction: cannot delete a param node if this line is instantiated
                    if (SimpleView::SimpleViewToGraphConverter::valNameToNode.count(lineEditValues[lineEditValueSelectedIndex]) == 0 or
                        SimpleView::SimpleViewToGraphConverter::valNameToNode[lineEditValues[lineEditValueSelectedIndex]]->nodeType != SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH
                        or (graphDependencyConstraint.dependencyHigher.empty() and lineInstanceDependencyConstraint.dependencyHigher.empty())) {
                        // restriction: cannot delete if the node is a intersection point
                        if (deleteIntersectionPointInLineTemplate(lineEditValueSelectedIndex)) {
                            lineEditValues.erase(lineEditValues.begin() + lineEditValueSelectedIndex);
                            lineEditRepeatTypes.erase(lineEditRepeatTypes.begin() + lineEditValueSelectedIndex);
                        }
                    }
                }

                ImGui::SetItemTooltip("right click to change repeat type, double click to delete");

                if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(1)) {
                    lineEditRepeatTypes[i] = (lineEditRepeatTypes[i] + 1) % 4;
                }

                // reorder
                if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                    int n_next = i + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                    if (n_next >= 0 && n_next < lineEditValues.size()) {
                        SWAP_ELEMENT(lineEditValues, i, n_next);
                        SWAP_ELEMENT(nodeInLineIdMap, i, n_next);
                        SWAP_ELEMENT(lineEditRepeatTypes, i, n_next);
                        for (auto& graphTemplateName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
                            auto& depHighGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphTemplateName];
                            depHighGraph->swapIntersectionForLineTemplate(SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineEditingIndex].data(), i, n_next);
                        }
                        ImGui::ResetMouseDragDelta();
                    }
                }
                ImGui::PopID();
            }
        }
        if (lineInvalid) {
            showRejectDialog("invalid line setting", &lineInvalid);
            parameterNameIsWrong = false;
            lineNameIsWrong = false;
            lineValueIsWrong = false;
        }
        if (parameterNameIsWrong) {
            showRejectDialog("wrong name or duplicate name or it is a keyword", &parameterNameIsWrong);
            lineNameIsWrong = false;
            lineValueIsWrong = false;
        }
        if (lineNameIsWrong) {
            showRejectDialog("wrong name or duplicate name or it is a keyword", &lineNameIsWrong);
            lineValueIsWrong = false;
        }
        if (lineValueIsWrong) {
            showRejectDialog("wrong value or node in line is less than 2", &lineValueIsWrong);
        }
    }

    static void addGraphNameEditItem(float fontSize) {
        static bool graphNameIsWrong = false;
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##editingGraphName", "", graphEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
        if (ImGui::Button("OK##graphEditOK", { fontSize * 3,searchBarHeight })) {
            graphNameIsWrong = not checkValName(graphEditingName, graphEditingIndex, 4);
            if (not graphNameIsWrong) {
                auto graph = changeNameOfNameOrderAndValNameTo<SimpleView::GraphTemplate*>(
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToGraph, graphEditingIndex, graphEditingName
                );
                graph->valName = graphEditingName;
                graph->updateDisplayName();
                FOR_EACH_ITEM(graphInstanceDependencyConstraint.dependencyHigher,
                    SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[
                        SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[item]
                    ]->updateDisplayName();
                            );
                graphEditingIndex = -1;
                onExitEditMode();
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##graphEditCancel", { fontSize * 3,searchBarHeight })) {
            graphEditingIndex = -1;
            onExitEditMode();
        }
        if (graphNameIsWrong) {
            showRejectDialog("wrong name or duplicate name or it is a keyword", &graphNameIsWrong);
        }
    }

    static void addLineInstanceArgEditItem(float fontSize) {
        static bool lineInstanceArgParamNameIsWrong = false;
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
        // add param as argument
        if (ImGui::Button("Parameter##lineInstanceArgParam")) {
            // restriction: cannot add param node if this graph is instantiated
            if (graphInstanceDependencyConstraint.dependencyHigher.empty()) {
                if (not checkValName(lineInstanceArgParaName, -1, 5)) {
                    lineInstanceArgParamNameIsWrong = true;
                } else {
                    createdString.push_back(lineInstanceArgParaName);
                    lineInstanceArgEditValues[lineInstanceArgSelectedIndex] = createdString.back().data();
                }
            }
        }
        ImGui::SameLine();
        ImGui::InputTextEx("##editingLineInstanceArgParamName", "", lineInstanceArgParaName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        int lineInstanceArgSelectableCount = 0;
        for (int i = 0; i < lineInstanceArgEditValues.size();i++) {
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
            string& paramName = editingLineInstance->lineTemplate->orderedParamName[i];
            ImGui::Text("%s = ", paramName.data()); ImGui::SameLine();
            if (ImGui::Selectable((string(lineInstanceArgEditValues[i]) + "##" + paramName).data(), lineInstanceArgSelectedIndex == lineInstanceArgSelectableCount)) {
                lineInstanceArgSelectedIndex = lineInstanceArgSelectableCount;
            }
            lineInstanceArgSelectableCount++;
        }
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
        if (ImGui::Button("OK##lineInstanceArgEditOK", { fontSize * 3,searchBarHeight })) {
            SimpleView::SimpleViewToGraphConverter::valNameToGraph[SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]]->resetLineInstanceArgument(lineInstanceEditingIndex, lineInstanceArgEditValues);
            lineInstanceEditingIndex = -1;
            onExitEditMode();
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##lineInstanceArgEditCancel", { fontSize * 3,searchBarHeight })) {
            lineInstanceEditingIndex = -1;
            onExitEditMode();
        }
        if (lineInstanceArgParamNameIsWrong) {
            showRejectDialog("wrong name or duplicate name or it is a keyword", &lineInstanceArgParamNameIsWrong);
        }
    }

    static void addNewLineFinalInstance(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##lineNewFinalInstanceName", "", lineNewFinalInstanceName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2 * fontSize);
        static bool lineNewFinalInstanceNameIsWrong = false;
        static bool lineNewFinalInstanceArgNameIsWrong = false;
        if (ImGui::Button("OK##lineNewFinalInstanceOK", { fontSize * 3,searchBarHeight })) {
            lineNewFinalInstanceNameIsWrong = not checkValName(lineNewFinalInstanceName, 0, 6);
            if (not lineNewFinalInstanceNameIsWrong) {
                FOR_EACH_ITEM(lineNewFinalInstance->paramNameToArgName,
                    lineNewFinalInstanceArgNameIsWrong = lineNewFinalInstanceArgNameIsWrong or not checkValNameCommon(item.second.data());
                    );
                if (not lineNewFinalInstanceArgNameIsWrong) {
                    changeNameOfNameOrderAndValNameTo<SimpleView::LineInstance*>(
                        SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToLineInstance, 0, lineNewFinalInstanceName
                    );
                    lineNewFinalInstance->valName = lineNewFinalInstanceName;
                    lineNewFinalInstance->editingNew = false;
                    lineNewFinalInstance->updateDisplayName();
                    lineNewFinalInstance = NULL;
                }
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##lineNewFinalInstanceCancel", { fontSize * 3,searchBarHeight })) {
            SimpleView::SimpleViewToGraphConverter::valNameToLineInstance.erase(lineNewFinalInstance->valName);
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.erase(SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.begin());
            delete lineNewFinalInstance;
            lineNewFinalInstance = NULL;
        }
        if (lineNewFinalInstance) {
            int lineInstanceArgSelectableCount = 0;
            for (int i = 0; i < lineNewFinalInstance->lineTemplate->orderedParamName.size();i++) {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                string& paramName = lineNewFinalInstance->lineTemplate->orderedParamName[i];
                ImGui::Text("%s = ", paramName.data()); ImGui::SameLine();
                if (ImGui::Selectable((lineNewFinalInstance->paramNameToArgName[paramName] + "##" + paramName).data(), lineFinalInstanceArgSelectedIndex == lineInstanceArgSelectableCount)) {
                    lineFinalInstanceArgSelectedIndex = lineInstanceArgSelectableCount;
                }
                lineInstanceArgSelectableCount++;
            }
        }
        if (lineNewFinalInstanceNameIsWrong) {
            showRejectDialog("wrong name", &lineNewFinalInstanceNameIsWrong);
        }
        if (lineNewFinalInstanceArgNameIsWrong) {
            showRejectDialog("wrong arg name", &lineNewFinalInstanceArgNameIsWrong);
        }
    }

    static void addLineFinalInstanceNameEdit(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##lineFinalInstanceNameEdit", "", lineFinalInstanceEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        ImGui::SameLine();
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 2 * fontSize);
        static bool lineFinalInstanceNameIsWrong = false;
        if (ImGui::Button("OK##lineFinalInstanceNameEditOK", { fontSize * 3,searchBarHeight })) {
            lineFinalInstanceNameIsWrong = not checkValName(lineFinalInstanceEditingName, lineFinalInstanceNameEditingIndex, 6);
            if (not lineFinalInstanceNameIsWrong) {
                auto lineInstance = changeNameOfNameOrderAndValNameTo<SimpleView::LineInstance*>(
                    SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToLineInstance, lineFinalInstanceNameEditingIndex, lineFinalInstanceEditingName
                );
                lineInstance->valName = lineFinalInstanceEditingName;
                lineInstance->updateDisplayName();
                lineFinalInstanceNameEditingIndex = -1;
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##lineFinalInstanceNameEditCancel", { fontSize * 3,searchBarHeight })) {
            lineFinalInstanceNameEditingIndex = -1;
        }
        if (lineFinalInstanceNameIsWrong) {
            showRejectDialog("wrong name", &lineFinalInstanceNameIsWrong);
        }
    }

    static void addNewGraphInstance(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##graphNewInstanceName", "", graphNewInstanceName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
        static bool graphNewInstanceNameIsWrong = false;
        static bool graphNewInstanceArgNameIsWrong = false;
        if (ImGui::Button("OK##graphNewInstanceOK", { fontSize * 3,searchBarHeight })) {
            graphNewInstanceNameIsWrong = not checkValName(graphNewInstanceName, 0, 7);
            if (not graphNewInstanceNameIsWrong) {
                FOR_EACH_ITEM(graphNewInstance->paramNameToArgName,
                    graphNewInstanceArgNameIsWrong = graphNewInstanceArgNameIsWrong or not checkValNameCommon(item.second.data());
                    );
                if (not graphNewInstanceArgNameIsWrong) {
                    changeNameOfNameOrderAndValNameTo<SimpleView::GraphInstance*>(
                        SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance, 0, graphNewInstanceName
                    );
                    graphNewInstance->valName = graphNewInstanceName;
                    graphNewInstance->editingNew = false;
                    graphNewInstance->updateDisplayName();
                    graphNewInstance = NULL;
                }
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##graphNewInstanceCancel", { fontSize * 3,searchBarHeight })) {
            SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance.erase(graphNewInstance->valName);
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.erase(SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.begin());
            delete graphNewInstance;
            graphNewInstance = NULL;
        }
        if (graphNewInstance) {
            int graphInstanceArgSelectableCount = 0;
            for (int i = 0; i < graphNewInstance->graphTemplate->orderedParamName.size();i++) {
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                string& paramName = graphNewInstance->graphTemplate->orderedParamName[i];
                ImGui::Text("%s = ", paramName.data()); ImGui::SameLine();
                if (ImGui::Selectable((graphNewInstance->paramNameToArgName[paramName] + "##" + paramName).data(), graphInstanceArgSelectedIndex == graphInstanceArgSelectableCount)) {
                    graphInstanceArgSelectedIndex = graphInstanceArgSelectableCount;
                }
                graphInstanceArgSelectableCount++;
            }
        }
        if (graphNewInstanceNameIsWrong) {
            showRejectDialog("wrong name", &graphNewInstanceNameIsWrong);
        }
        if (graphNewInstanceArgNameIsWrong) {
            showRejectDialog("wrong arg name", &graphNewInstanceArgNameIsWrong);
        }
    }

    static void addGraphInstanceNameEdit(float fontSize) {
        ImGui::Text("name: "); ImGui::SameLine();
        ImGui::InputTextEx("##graphInstanceNameEdit", "", graphInstanceEditingName, 1000, { 6 * fontSize,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank);
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
        static bool graphInstanceNameIsWrong = false;
        if (ImGui::Button("OK##graphInstanceNameEditOK", { fontSize * 3,searchBarHeight })) {
            graphInstanceNameIsWrong = not checkValName(graphInstanceEditingName, graphInstanceNameEditingIndex, 7);
            if (not graphInstanceNameIsWrong) {
                auto graphInstance = changeNameOfNameOrderAndValNameTo<SimpleView::GraphInstance*>(
                    SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder, SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance, graphInstanceNameEditingIndex, graphInstanceEditingName
                );
                graphInstance->valName = graphInstanceEditingName;
                graphInstance->updateDisplayName();
                graphInstanceNameEditingIndex = -1;
            }
        }
        ImGui::SameLine();
        if (ImGui::Button("Cancel##graphInstanceNameEditCancel", { fontSize * 3,searchBarHeight })) {
            graphInstanceNameEditingIndex = -1;
        }
        if (graphInstanceNameIsWrong) {
            showRejectDialog("wrong name", &graphInstanceNameIsWrong);
        }
    }


    // type: 
    // 1 for class key or node key choose
    // 2 for class scope name choose
    // 3 for node name choose
    // 4 for line name choose
    // 5 for line instance name choose
    static void handleClassScopeOrNodeOrSegChoose(int index, int type) {
        if (classScopeEditingIndex > -1) {
            if (type == 3) {
                return;
            }
            if (type == 2 and index >= classScopeEditingIndex) {
                return;
            }
            switch (classScopeEditingTypeIndex) {
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_KEY:
                if (type == 1) {
                    if (EasierSimpleView::typeToPackage.count(searchResults[index])) {
                        classScopeEditValues[0] = searchResults[index];
                    }
                }
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_LIST:
                if (type == 1) {
                    if (EasierSimpleView::typeToPackage.count(searchResults[index])) {
                        if (isEditValueIsActuallyHint(classScopeEditValues)) {
                            classScopeEditValues.clear();
                        }
                        if (classScopeEditValueSelectedIndex >= classScopeEditValues.size()) {
                            classScopeEditValueSelectedIndex = classScopeEditValues.size() - 1;
                        }
                        if (std::find(classScopeEditValues.begin(), classScopeEditValues.end(), searchResults[index]) == classScopeEditValues.end()) {
                            classScopeEditValues.insert(classScopeEditValues.begin() + classScopeEditValueSelectedIndex + 1, searchResults[index]);
                            classScopeEditValueSelectedIndex++;
                        }
                    }
                }
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_IN_PACKAGE:
                if (type == 1) {
                    if (EasierSimpleView::typeToPackage.count(searchResults[index])) {
                        classScopeEditValues[0] = EasierSimpleView::typeToPackage[searchResults[index]].data();
                    }
                }
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_USED_BY:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_USE:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUPER:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_SUB:
                if (type == 2) {
                    classScopeEditValues[0] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index].data();
                }
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_INTERSECTION:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_UNION:
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_DIFFERENCE:
                if (type == 2) {
                    classScopeEditValues[classScopeEditValueSelectedIndex] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index].data();
                }
                break;
            case SimpleView::ClassScope::CLASS_SCOPE_TYPE_VAR:
                if (type == 2) {
                    classScopeEditValues[classScopeEditValueSelectedIndex] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index].data();
                }
                break;
            }
        }
        if (nodeEditingIndex > -1) {
            if (type == 3 and index >= nodeEditingIndex) {
                return;
            }
            switch (nodeEditingTypeIndex) {
            case SimpleView::Node::NODE_TYPE_KEY:
                if (type == 1) {
                    if (openedTypeKey) {
                        nodeEditValues[0] = searchResults[index];
                        typeKeyForNodeKey[0] = openedTypeKey;
                    }
                }
                break;
            case SimpleView::Node::NODE_TYPE_LIST:
                if (type == 1) {
                    if (openedTypeKey) {
                        if (isEditValueIsActuallyHint(nodeEditValues)) {
                            nodeEditValues.clear();
                            typeKeyForNodeKey.clear();
                        }
                        if (nodeEditValueSelectedIndex >= nodeEditValues.size()) {
                            nodeEditValueSelectedIndex = nodeEditValues.size() - 1;
                        }
                        bool duplicate = std::find(nodeEditValues.begin(), nodeEditValues.end(), searchResults[index]) != nodeEditValues.end();
                        if (not duplicate) {
                            nodeEditValues.insert(nodeEditValues.begin() + nodeEditValueSelectedIndex + 1, searchResults[index]);
                            typeKeyForNodeKey.insert(typeKeyForNodeKey.begin() + nodeEditValueSelectedIndex + 1, openedTypeKey);
                            nodeEditValueSelectedIndex++;
                        }
                    }
                }
                break;
            case SimpleView::Node::NODE_TYPE_FIELD_OF:// class
            case SimpleView::Node::NODE_TYPE_METHOD_OF:// class
            case SimpleView::Node::NODE_TYPE_CREATOR:// class
                if (type == 2) {
                    nodeEditValues[0] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index].data();
                }
                break;
            case SimpleView::Node::NODE_TYPE_PARAMETER_OF: // method
            case SimpleView::Node::NODE_TYPE_RETURN_OF: // method
            case SimpleView::Node::NODE_TYPE_CALLED_METHOD_OF: // method
            case SimpleView::Node::NODE_TYPE_CALLED_PARAMETER_OF: // parameter
            case SimpleView::Node::NODE_TYPE_CALLED_RETURN_OF: // return
                if (type == 3) {
                    int choosenNodeType = SimpleView::SimpleViewToGraphConverter::valNameToNode[
                        SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index]
                    ]->nodeType;
                    if (choosenNodeType != SimpleView::Node::NODE_TYPE_CALLED_METHOD_OF
                        and choosenNodeType != SimpleView::Node::NODE_TYPE_CALLED_PARAMETER_OF
                        and choosenNodeType != SimpleView::Node::NODE_TYPE_CALLED_RETURN_OF
                        and choosenNodeType != SimpleView::Node::NODE_TYPE_READ
                        and choosenNodeType != SimpleView::Node::NODE_TYPE_WRITE
                        ) {
                        nodeEditValues[0] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
                    }
                }
                break;
            case SimpleView::Node::NODE_TYPE_INSTANCE_OF:
                if (type == 2) {
                    nodeEditValues[nodeEditValueSelectedIndex] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[index].data();
                }
                break;
            case SimpleView::Node::NODE_TYPE_INTERSECTION:
            case SimpleView::Node::NODE_TYPE_UNION:
            case SimpleView::Node::NODE_TYPE_DIFFERENCE:
                if (type == 3) {
                    nodeEditValues[nodeEditValueSelectedIndex] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
                }
                break;
            case SimpleView::Node::NODE_TYPE_VAR:
                if (type == 3) {
                    nodeEditValues[nodeEditValueSelectedIndex] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
                }
                break;
            }
        }
        if (lineEditingIndex > -1) {
            if (type == 4 and index >= lineEditingIndex) {
                return;
            }
            if (type == 3 or (type == 4 and SimpleView::SimpleViewToGraphConverter::valNameToLine[
                SimpleView::SimpleViewToGraphConverter::lineNameOrder[index]]->lineType == SimpleView::LineTemplate::LINE_TYPE_SEGMENT)) {
                cleanLineEditIfItIsHint();
                if (type == 3) {
                    lineEditValues.insert(lineEditValues.begin() + lineEditValueSelectedIndex + 1,
                        SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data());
                    insertIntersectionPointInLineTemplate(SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data(), false, lineEditValueSelectedIndex + 1);
                } else {
                    lineEditValues.insert(lineEditValues.begin() + lineEditValueSelectedIndex + 1,
                        SimpleView::SimpleViewToGraphConverter::lineNameOrder[index].data());
                    insertIntersectionPointInLineTemplate(SimpleView::SimpleViewToGraphConverter::lineNameOrder[index].data(), true, lineEditValueSelectedIndex + 1);
                }
                lineEditRepeatTypes.insert(lineEditRepeatTypes.begin() + lineEditValueSelectedIndex + 1, 0);
                lineEditValueSelectedIndex++;
            }
        }
        if (lineInstanceEditingIndex > -1) {
            // use node as argument for line instance in graph
            if (type == 3) {
                // restrictions: cannot replace if the replaced arg is a parameter of graph, and the graph is instantiated
                if (graphInstanceDependencyConstraint.dependencyHigher.empty() or
                    SimpleView::SimpleViewToGraphConverter::valNameToNode[lineInstanceArgEditValues[lineInstanceArgSelectedIndex]]->nodeType != SimpleView::Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH) {
                    lineInstanceArgEditValues[lineInstanceArgSelectedIndex] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
                } else {
                    // todo use status bar to remind user this constrain
                }
            }
        }
        if (lineInstanceNewIndex > -1) {
            if (type == 4) {
                auto& lineTemplate = SimpleView::SimpleViewToGraphConverter::valNameToLine[SimpleView::SimpleViewToGraphConverter::lineNameOrder[index]];
                if (lineTemplate->lineType != SimpleView::LineTemplate::LINE_TYPE_SEGMENT) {
                    auto& pGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]];
                    if (not pGraph->hasLineAsLineInstance(lineTemplate->name)) {
                        pGraph->addNewLine(lineTemplate, lineInstanceNewIndex + 1);
                        lineInstanceNewIndex = -1;
                    }
                }
            }
            if (type == 5) {
                auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[index]];
                auto& pGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]];
                if (not pGraph->hasLineAsLineInstance(lineInstance->valName)) {
                    pGraph->addNewLine(lineInstance, lineInstanceNewIndex + 1);
                    lineInstanceNewIndex = -1;
                }
            }
        }
        if (lineNewFinalInstance) {
            if (type == 3) {
                lineNewFinalInstance->paramNameToArgName[
                    lineNewFinalInstance->lineTemplate->orderedParamName[lineFinalInstanceArgSelectedIndex]
                ] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
            }
        }
        if (graphNewInstance) {
            if (type == 3) {
                graphNewInstance->paramNameToArgName[
                    graphNewInstance->graphTemplate->orderedParamName[graphInstanceArgSelectedIndex]
                ] = SimpleView::SimpleViewToGraphConverter::nodeNameOrder[index].data();
            }
        }
    }

    // delete constraints
    // will be set false when dialog is closed
    static bool showDoubleCheckToDeleteClassScope = false;
    static bool showDoubleCheckToDeleteNode = false;
    static bool showDoubleCheckToDeleteLine = false;
    static bool showDoubleCheckToDeleteGraph = false;
    static bool showDoubleCheckToDeleteLineInstanceInGraph = false;
    static bool showDoubleCheckToDeleteIntersectinPoint = false;
    static bool showDoubleCheckToDeleteLineInstance = false;
    static bool showDoubleCheckToDeleteGraphInstance = false;

    static int deletedIntersectinPointIndex = -1;

    // ToThink: which reject dialog should be replaced by a status bar text blinking animation
    static bool showRejectDeleteClassScopeBecauseEmpty = false;
    static bool showRejectDeleteClassScopeBecauseDependency = false;
    static bool showRejectDeleteNodeBecauseEmpty = false;
    static bool showRejectDeleteNodeBecauseDependency = false;
    static bool showRejectDeleteLineBecauseEmpty = false;
    static bool showRejectDeleteLineBecauseDependency = false;
    static bool showRejectDeleteGraphBecauseDependency = false;

    // react on menu
    class ClassScopeMenuReaction {
    public:
        void onNewItem() {
            classScopeEditingIndex = classScopeSelectedIndex + 1;
            strcpy(classScopeEditingName, "unnamed");
            classScopeEditingTypeIndex = SimpleView::ClassScope::CLASS_SCOPE_TYPE_KEY;
            classScopeEditValues.push_back("Click class on the right to choose");
            SimpleView::ClassScope* newClassScope = new SimpleView::ClassScope();
            newClassScope->editingNew = true;
            newClassScope->iconId = Images::keyIconId;
            SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.insert(
                SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.begin() + classScopeEditingIndex,
                string(classScopeEditingName));
            SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeEditingName] = newClassScope;
            clearAllDependency();
        }
        void onDeleteItem() {
            if (SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size() == 1) {
                showRejectDeleteClassScopeBecauseEmpty = true;
            }
            if (not showRejectDeleteClassScopeBecauseEmpty) {
                if (not classScopeDependencyConstraint.hasNoHigherDependency() or not nodeDependencyConstraint.hasNoHigherDependency()) {
                    showRejectDeleteClassScopeBecauseDependency = true;
                }
                if (not showRejectDeleteClassScopeBecauseDependency) {
                    showDoubleCheckToDeleteClassScope = true;
                }
            }
        }
        void onEditItem(SimpleView::ClassScope* classScope) {
            classScopeEditingIndex = classScopeSelectedIndex;
            strcpy(classScopeEditingName, classScope->displayName.data());
            classScopeEditingTypeIndex = classScope->classScopeType;
            classScopeEditValues.clear();
            classScope->loadValueToUI(classScopeEditValues);
        }
        void onShowList(SimpleView::ClassScope* classScope) {
            std::thread worker([&](SimpleView::ClassScope* classScope) {
                PL_thread_attach_engine(NULL);
                classScope->resolve(&loadingAddressableProgress);
                classScope->listTerm(searchResults);
                PL_thread_destroy_engine();
                }, classScope);
            worker.detach();

        }
    };

    class NodeMenuReaction {
    public:
        void onNewItem() {
            nodeEditingIndex = nodeSelectedIndex + 1;
            strcpy(nodeEditingName, "unnamed");
            nodeEditingTypeIndex = SimpleView::Node::NODE_TYPE_KEY;
            nodeEditValues.push_back("Click field/method/param/return on the right");
            typeKeyForNodeKey.push_back(NULL);
            auto* newNode = new SimpleView::Node();
            newNode->editingNew = true;
            newNode->iconId = Images::keyIconId;
            SimpleView::SimpleViewToGraphConverter::nodeNameOrder.insert(
                SimpleView::SimpleViewToGraphConverter::nodeNameOrder.begin() + nodeEditingIndex,
                string(nodeEditingName));
            SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeEditingName] = newNode;
            clearAllDependency();
        }
        void onDeleteItem() {
            if (SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size() == 1) {
                showRejectDeleteNodeBecauseEmpty = true;
            }
            if (not showRejectDeleteNodeBecauseEmpty) {
                if (not nodeDependencyConstraint.hasNoHigherDependency()
                    or not lineDependencyConstraint.hasNoHigherDependency()
                    or not graphDependencyConstraint.hasNoHigherDependency()
                    or not lineInstanceDependencyConstraint.hasNoHigherDependency()
                    or not graphInstanceDependencyConstraint.hasNoHigherDependency()) {
                    showRejectDeleteNodeBecauseDependency = true;
                }
                if (not showRejectDeleteNodeBecauseDependency) {
                    showDoubleCheckToDeleteNode = true;
                }
            }
        }
        void onEditItem(SimpleView::Node* node) {
            nodeEditingIndex = nodeSelectedIndex;
            strcpy(nodeEditingName, node->displayName.data());
            nodeEditingTypeIndex = node->nodeType;
            nodeEditValues.clear();
            typeKeyForNodeKey.clear();
            node->loadValueToUI(nodeEditValues, typeKeyForNodeKey);
        }
        void onShowList(SimpleView::Node* node) {
            std::thread worker([&](SimpleView::Node* node) {
                PL_thread_attach_engine(NULL);
                node->resolve(&loadingAddressableProgress);
                node->listTerm(searchResults);
                PL_thread_destroy_engine();
                }, node);
            worker.detach();
        }
    };

    class LineMenuReaction {
    public:
        void onNewItem() {
            lineEditingIndex = lineSelectedIndex + 1;
            strcpy(lineEditingName, "unnamed");
            lineEditingTypeIndex = SimpleView::LineTemplate::LINE_TYPE_DATA_FLOW;
            lineIsAlternation = false;
            lineEditValues.push_back("Click field/method/param/return above");
            lineEditRepeatTypes.push_back(0);
            auto* newLine = new SimpleView::LineTemplate(lineEditingName, lineEditingTypeIndex);
            newLine->editingNew = true;
            newLine->iconId = Images::lineIconId;
            SimpleView::SimpleViewToGraphConverter::lineNameOrder.insert(
                SimpleView::SimpleViewToGraphConverter::lineNameOrder.begin() + lineEditingIndex,
                string(lineEditingName));
            SimpleView::SimpleViewToGraphConverter::valNameToLine[lineEditingName] = newLine;
            clearAllDependency();
        }
        void onNewInstance() {
            auto& lineTemplate = SimpleView::SimpleViewToGraphConverter::valNameToLine[
                SimpleView::SimpleViewToGraphConverter::lineNameOrder[lineSelectedIndex]
            ];
            string newInstanceName = "";
            for (int i = 1;i < 1000;i++) {
                newInstanceName = lineTemplate->name + "_" + to_string(i);
                if (std::find(SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.begin(), SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.end(), newInstanceName) == SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.end()) {
                    break;
                }
            }
            vector<string> args;
            FOR_EACH_ITEM(lineTemplate->orderedParamName, args.push_back("click node above"););
            auto lineInstance = new SimpleView::LineInstance(lineTemplate, args);
            lineInstance->editingNew = true;
            lineInstance->valName = newInstanceName;
            strcpy(lineNewFinalInstanceName, newInstanceName.data());
            SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.insert(
                SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.begin(), newInstanceName
            );
            SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[newInstanceName] = lineInstance;
            lineNewFinalInstance = lineInstance;
            clearAllDependency();
        }
        void onDeleteItem() {
            if (SimpleView::SimpleViewToGraphConverter::lineNameOrder.size() == 1) {
                showRejectDeleteLineBecauseEmpty = true;
            }
            if (not showRejectDeleteLineBecauseEmpty) {
                if (not lineDependencyConstraint.hasNoHigherDependency()
                    or not graphDependencyConstraint.hasNoHigherDependency()
                    or not lineInstanceDependencyConstraint.hasNoHigherDependency()) {
                    showRejectDeleteLineBecauseDependency = true;
                }
                if (not showRejectDeleteLineBecauseDependency) {
                    showDoubleCheckToDeleteLine = true;
                }
            }
        }
        void onEditItem(SimpleView::LineTemplate* line) {
            lineEditingIndex = lineSelectedIndex;
            strcpy(lineEditingName, line->name.data());
            lineEditingTypeIndex = line->lineType;
            lineIsAlternation = line->isAlternation;
            lineEditValues.clear();
            lineEditRepeatTypes.clear();
            line->loadValueToUI(lineEditValues, lineEditRepeatTypes);
            for (int depHighGraphIndex : graphDependencyConstraint.dependencyHigher) {
                SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder[depHighGraphIndex]
                ]->clearIntersectionEditing();
            }
        }
    };

    class GraphMenuReaction {
    public:
        void onNewItem() {
            auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
            ];
            string selectedName = selectedGraph->valName;
            string newItemName = "";
            for (int copyIndex = 1;copyIndex < 1000;copyIndex++) {
                newItemName = selectedName + "_copy_" + to_string(copyIndex);
                if (std::find(SimpleView::SimpleViewToGraphConverter::graphNameOrder.begin(), SimpleView::SimpleViewToGraphConverter::graphNameOrder.end(), newItemName) == SimpleView::SimpleViewToGraphConverter::graphNameOrder.end()) {
                    break;
                }
            }
            SimpleView::SimpleViewToGraphConverter::graphNameOrder.insert(SimpleView::SimpleViewToGraphConverter::graphNameOrder.begin() + graphSelectedIndex + 1, newItemName);
            SimpleView::SimpleViewToGraphConverter::valNameToGraph[newItemName] = selectedGraph->copy(newItemName);
            clearAllDependency();
        }
        void onNewInstance() {
            auto& graphTemplate = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
            ];
            string newInstanceName = "";
            for (int i = 1;i < 1000;i++) {
                newInstanceName = graphTemplate->valName + "_" + to_string(i);
                if (std::find(SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.begin(), SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.end(), newInstanceName) == SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.end()) {
                    break;
                }
            }
            vector<string> args;
            FOR_EACH_ITEM(graphTemplate->orderedParamName, args.push_back("click node above"););
            auto graphInstance = new SimpleView::GraphInstance(graphTemplate, args);
            graphInstance->editingNew = true;
            graphInstance->valName = newInstanceName;
            strcpy(graphNewInstanceName, newInstanceName.data());
            SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.insert(
                SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.begin(), newInstanceName
            );
            SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[newInstanceName] = graphInstance;
            graphNewInstance = graphInstance;
            clearAllDependency();
        }
        void onDeleteItem() {
            if (not graphInstanceDependencyConstraint.hasNoHigherDependency()) {
                showRejectDeleteGraphBecauseDependency = true;
            } else {
                if (SimpleView::SimpleViewToGraphConverter::graphNameOrder.size() > 1) {
                    showDoubleCheckToDeleteGraph = true;
                }
            }
        }
        void onEditItem(SimpleView::GraphTemplate* graph) {
            graphEditingIndex = graphSelectedIndex;
            strcpy(graphEditingName, graph->valName.data());
        }
    };

    class LineInstanceMenuReaction {
    public:
        void onNewItem() {
            lineInstanceNewIndex = lineInstanceSelectedIndex;
        }
        void onDeleteItem() {
            auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
            ];
            if (selectedGraph->lineInstances.size() > 1) {
                showDoubleCheckToDeleteLineInstanceInGraph = true;
            }
        }
        void onEditItem(SimpleView::LineInstance* lineInstance) {
            if (not lineInstance->lineTemplate->orderedParamName.empty()) {
                lineInstanceEditingIndex = lineInstanceSelectedIndex;
                lineInstanceArgEditValues.clear();
                for (auto& paramName : lineInstance->lineTemplate->orderedParamName) {
                    lineInstanceArgEditValues.push_back(lineInstance->paramNameToArgName[paramName].data());
                }
                editingLineInstance = lineInstance;
            }
        }
    };

    class IntersectionPointMenuReaction {
    public:
        void onNewItem(int index) {
            auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
            ];
            vector<SimpleView::IntersectionPointInLine*> newItem;
            for (auto& p : selectedGraph->intersectionPointsInLine[index]) {
                newItem.push_back(p->copy());
            }
            selectedGraph->intersectionPointsInLine.insert(selectedGraph->intersectionPointsInLine.begin() + index + 1, newItem);
        }
        void onDeleteItem(int index) {
            auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
            ];
            if (selectedGraph->intersectionPointsInLine.size() > 1) {
                showDoubleCheckToDeleteIntersectinPoint = true;
                deletedIntersectinPointIndex = index;
            }
        }
        void onEditItem(int index) {
            intersectionPointEditingIndex = index;
        }
    };

    static ClassScopeMenuReaction classScopeMenuReaction;
    static NodeMenuReaction nodeMenuReaction;
    static LineMenuReaction lineMenuReaction;
    static GraphMenuReaction graphMenuReaction;
    static LineInstanceMenuReaction lineInstanceMenuReaction;
    static IntersectionPointMenuReaction intersectionPointMenuReaction;

    static void unselectAll() {
        classScopeSelectedIndex = -1;
        nodeSelectedIndex = -1;
        lineSelectedIndex = -1;
        lineInstanceSelectedIndex = -1;
        classScopeKeyDownIndex = -1;
        nodeKeyDownIndex = -1;
        lineKeyDownIndex = -1;
        graphKeyDownIndex = -1;
        lineFinalInstanceSelectedIndex = -1;
        graphInstanceSelectedIndex = -1;
        lineFinalInstanceKeyDownIndex = -1;
        graphInstanceKeyDownIndex = -1;
    }

    static void onSearchClass() {
        openedTypeKey = NULL;
        EasierSimpleView::searchClass(searchedStr, searchResults);
    }

    static void onSearchNode(int index) {
        if (openedTypeKey == NULL) {
            openedTypeKey = const_cast<char*>(searchResults[index]);
        }
        EasierSimpleView::searchNode(searchResults[index], searchResults);
    }

    static void filterSearchResults(vector<const char*>& searchResult) {
        EasierSimpleView::filterSearchResults(searchedStr, searchResult);
    }

    void showDialogForDeletion() {
        if (showRejectDeleteClassScopeBecauseEmpty) {
            showRejectDialog("class list cannot be empty", &showRejectDeleteClassScopeBecauseEmpty);
        }
        if (showRejectDeleteClassScopeBecauseDependency) {
            showRejectDialog("cannot delete due to dependency", &showRejectDeleteClassScopeBecauseDependency);
        }
        if (showDoubleCheckToDeleteClassScope) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteClassScope, [&]() {
                deleteClassScopeAtIndex(classScopeSelectedIndex);
                });
        }
        if (showRejectDeleteNodeBecauseEmpty) {
            showRejectDialog("node list cannot be empty", &showRejectDeleteNodeBecauseEmpty);
        }
        if (showRejectDeleteNodeBecauseDependency) {
            showRejectDialog("cannot delete due to dependency", &showRejectDeleteNodeBecauseDependency);
        }
        if (showDoubleCheckToDeleteNode) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteNode, [&]() {
                deleteNodeAtIndex(nodeSelectedIndex);
                });
        }
        if (showRejectDeleteLineBecauseEmpty) {
            showRejectDialog("line list cannot be empty", &showRejectDeleteLineBecauseEmpty);
        }
        if (showRejectDeleteLineBecauseDependency) {
            showRejectDialog("cannot delete due to dependency", &showRejectDeleteLineBecauseDependency);
        }
        if (showRejectDeleteGraphBecauseDependency) {
            showRejectDialog("cannot delete due to dependency", &showRejectDeleteGraphBecauseDependency);
        }
        if (showDoubleCheckToDeleteLine) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteLine, [&]() {
                deleteLineAtIndex(lineSelectedIndex);
                });
        }
        if (showDoubleCheckToDeleteGraph) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteGraph, [&]() {
                SimpleView::SimpleViewToGraphConverter::valNameToGraph.erase(
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
                );
                SimpleView::SimpleViewToGraphConverter::graphNameOrder.erase(
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder.begin() + graphSelectedIndex
                );
                if (graphSelectedIndex >= SimpleView::SimpleViewToGraphConverter::graphNameOrder.size()) {
                    graphSelectedIndex--;
                }
                });
        }

        if (showDoubleCheckToDeleteLineInstanceInGraph) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteLineInstanceInGraph, [&]() {
                auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
                ];
                selectedGraph->lineInstances.erase(selectedGraph->lineInstances.begin() + lineInstanceSelectedIndex);
                FOR_EACH_ITEM(selectedGraph->intersectionPointsInLine, item.erase(item.begin() + lineInstanceSelectedIndex););
                selectedGraph->updateOrderedParam();
                selectedGraph->updateDisplayName();
                });
        }
        if (showDoubleCheckToDeleteIntersectinPoint) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteIntersectinPoint, [&]() {
                auto& selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]
                ];
                selectedGraph->intersectionPointsInLine.erase(selectedGraph->intersectionPointsInLine.begin() + deletedIntersectinPointIndex);
                });
        }
        if (showDoubleCheckToDeleteLineInstance) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteLineInstance, [&]() {
                deleteLineInstanceAtIndex(lineFinalInstanceSelectedIndex);
                });
        }
        if (showDoubleCheckToDeleteGraphInstance) {
            showDoubleCheckDialog("are you sure to delete?", &showDoubleCheckToDeleteGraphInstance, [&]() {
                deleteGraphInstanceAtIndex(graphInstanceSelectedIndex);
                });
        }
    }

    static void putIcon(int id, int size) {
        if (id) {
            ImGui::Image((void*)(intptr_t)id, ImVec2(size, size));
            ImGui::SameLine();
        }
    }

    static void addIntersectPointRecursively(SimpleView::LineInstance* lineInstance, SimpleView::LineTemplate* lineTemplate, SimpleView::IntersectionPointInLine* pointsInLine, bool expand) {
        for (int pointCount = 0;pointCount < pointsInLine->seg.size();pointCount++) {
            auto& pI = pointsInLine->seg[pointCount];
            auto& nodeAndRepeatTypeI = lineTemplate->nodeAndRepeatType[pointCount];
            if (pI->findIntersection()) {
                if (nodeAndRepeatTypeI->seg) {
                    if (expand) {
                        ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                    }
                    if (ImGui::TreeNodeEx((to_string(pointCount + 1) + ". " + nodeAndRepeatTypeI->seg->name).data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                        addIntersectPointRecursively(lineInstance, nodeAndRepeatTypeI->seg, pI, expand);
                        ImGui::TreePop();
                    }
                } else {
                    // todo use different color for leaf node
                    if (nodeAndRepeatTypeI->isParamNode()) {
                        if (ImGui::TreeNodeEx((to_string(pointCount + 1) + ". " + lineInstance->paramNameToArgName[nodeAndRepeatTypeI->node->displayName]).data(), ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth)) {
                            ImGui::TreePop();
                        }
                    } else {
                        if (ImGui::TreeNodeEx((to_string(pointCount + 1) + ". " + nodeAndRepeatTypeI->node->displayName).data(), ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth)) {
                            ImGui::TreePop();
                        }
                    }
                }
            }
        }
    }

    static void addNodeInLineRecursively(SimpleView::LineInstance* lineInstance, SimpleView::LineTemplate* lineTemplate, SimpleView::IntersectionPointInLine* pointsInLine, bool disabled) {
        for (int pointCount = 0;pointCount < lineTemplate->nodeAndRepeatType.size();pointCount++) {
            auto& pI = pointsInLine->seg[pointCount];
            auto& nodeAndRepeatTypeI = lineTemplate->nodeAndRepeatType[pointCount];
            bool disalbedI = disabled or lineTemplate->isAlternation or (nodeAndRepeatTypeI->repeatType != SimpleView::LineTemplate::REPEAT_TYPE_ONE);
            string repeatTypeStr = " ";
            switch (nodeAndRepeatTypeI->repeatType) {
            case SimpleView::LineTemplate::REPEAT_TYPE_ZERO_OR_ONE:
                repeatTypeStr.push_back('?');
                break;
            case SimpleView::LineTemplate::REPEAT_TYPE_ZERO_OR_MORE:
                repeatTypeStr.push_back('*');
                break;
            case SimpleView::LineTemplate::REPEAT_TYPE_ONE_OR_MORE:
                repeatTypeStr.push_back('+');
                break;
            }
            if (disalbedI) {
                ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(180, 180, 180, 100));
            }
            if (nodeAndRepeatTypeI->seg) {
                ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                if (ImGui::TreeNodeEx((nodeAndRepeatTypeI->seg->name + repeatTypeStr).data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                    addNodeInLineRecursively(lineInstance, nodeAndRepeatTypeI->seg, pI, disalbedI);
                    ImGui::TreePop();
                }
            } else {
                int selectedFlag = 0;
                if (pI->isIntersection) {
                    selectedFlag = ImGuiTreeNodeFlags_Selected;
                }
                if (nodeAndRepeatTypeI->isParamNode()) {
                    ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                    if (ImGui::TreeNodeEx((lineInstance->paramNameToArgName[nodeAndRepeatTypeI->node->displayName] + repeatTypeStr).data(), ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth | selectedFlag)) {
                        ImGui::TreePop();
                    }
                } else {
                    ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                    if (ImGui::TreeNodeEx((nodeAndRepeatTypeI->node->displayName + repeatTypeStr).data(), ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_SpanAvailWidth | selectedFlag)) {
                        ImGui::TreePop();
                    }
                }
                if (not disalbedI) {
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(0)) {
                        pI->isIntersection = not pI->isIntersection;
                    }
                }
            }
            if (disalbedI) {
                ImGui::PopStyleColor();
            }
        }
    }

    static void editLineAndGraph(bool open) {
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
        ImGui::Begin("search", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);

        // edit window start
        ImGui::SetCursorPos({ mainWindowPadding,mainWindowPadding });
        ImGui::BeginChild("editWindow", ImVec2(editWindowWidth, childWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, panelBgColor);

        // class window start
        if (not showGraphList) {
            ImGui::SetCursorPos({ childWindowPadding,childWindowPadding });
            shadow(classWindowWidth, classWindowHeight);
            ImGui::BeginChild("classWindow", ImVec2(classWindowWidth, classWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

            int classScopeSelectableCount = 0;

            for (auto classScopeName : SimpleView::SimpleViewToGraphConverter::classScopeNameOrder) {
                if (classScopeSelectableCount >= SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size()) {
                    continue;
                }
                if (classScopeName.empty()) {
                    continue;
                }
                auto* classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeName];
                bool foundDependencyLower = classScopeDependencyConstraint.findInLowerBound(classScopeSelectableCount);
                bool foundDependencyHigher = classScopeDependencyConstraint.findInHigherBound(classScopeSelectableCount);
                if (foundDependencyLower) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
                }
                if (foundDependencyHigher) {
                    ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
                }
                if (classScopeEditingIndex == classScopeSelectableCount) {
                    putIcon(SimpleView::ClassScope::classTypeToIconId[classScopeEditingTypeIndex], fontSize);
                    addClassEditItem(fontSize);
                } else {
                    putIcon(classScope->iconId, fontSize);
                    if (ImGui::Selectable(classScope->displayText.data(), classScopeSelectedIndex == classScopeSelectableCount)) {
                        unselectAll();
                        classScopeSelectedIndex = classScopeSelectableCount;
                        handleClassScopeOrNodeOrSegChoose(classScopeSelectedIndex, 2);
                    }
                }
                if (foundDependencyLower) {
                    ImGui::PopStyleColor();
                }
                if (foundDependencyHigher) {
                    ImGui::PopStyleColor();
                }
                // mouse left key down on different item
                if (ImGui::IsItemActive() and classScopeKeyDownIndex != classScopeSelectableCount) {
                    classScopeKeyDownIndex = classScopeSelectableCount;
                    updateDependencyLowerAndHigher(classScopeKeyDownIndex, 1);
                }
                if (isNothingEditing()) {
                    // reorder
                    if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                        int n_next = classScopeSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                        if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size() && classScopeDependencyConstraint.isInBound(n_next)) {
                            SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::classScopeNameOrder, classScopeSelectableCount, n_next);
                            ImGui::ResetMouseDragDelta();
                        }
                    }
                    // right click menu
                    if (ImGui::BeginPopupContextItem()) {
                        unselectAll();
                        classScopeSelectedIndex = classScopeSelectableCount;
                        classScopeKeyDownIndex = classScopeSelectableCount;
                        updateDependencyLowerAndHigher(classScopeKeyDownIndex, 1);
                        if (ImGui::Selectable("new", false)) {
                            classScopeMenuReaction.onNewItem();
                        }
                        if (ImGui::Selectable("delete", false)) {
                            classScopeMenuReaction.onDeleteItem();
                        }
                        if (ImGui::Selectable("edit", false)) {
                            classScopeMenuReaction.onEditItem(classScope);
                        }
                        if (ImGui::Selectable("showList", false)) {
                            classScopeMenuReaction.onShowList(classScope);
                        }
                        ImGui::EndPopup();
                    }
                    if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                        classScopeMenuReaction.onEditItem(classScope);
                    }
                }
                classScopeSelectableCount++;
            }
            ImGui::EndChild();
            // class window end
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

        // node window start
        ImGui::SetCursorPos({ childWindowPadding,nodeWindowTop });
        shadow(classWindowWidth, nodeWindowHeight);
        ImGui::BeginChild("nodeWindow", ImVec2(classWindowWidth, nodeWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

        int nodeSelectableCount = 0;

        for (auto nodeName : SimpleView::SimpleViewToGraphConverter::nodeNameOrder) {
            if (nodeSelectableCount >= SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size()) {
                continue;
            }
            if (nodeName.empty()) {
                continue;
            }
            auto* node = SimpleView::SimpleViewToGraphConverter::valNameToNode[nodeName];
            bool foundDependencyLower = nodeDependencyConstraint.findInLowerBound(nodeSelectableCount);
            bool foundDependencyHigher = nodeDependencyConstraint.findInHigherBound(nodeSelectableCount);
            if (foundDependencyLower) {
                ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
            }
            if (foundDependencyHigher) {
                ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
            }
            if (nodeEditingIndex == nodeSelectableCount) {
                putIcon(SimpleView::Node::nodeTypeToIconId[nodeEditingTypeIndex], fontSize);
                addNodeEditItem(fontSize);
            } else {
                putIcon(node->iconId, fontSize);
                // mouse left key up on different item
                if (ImGui::Selectable(node->displayText.data(), nodeSelectedIndex == nodeSelectableCount)) {
                    unselectAll();
                    nodeSelectedIndex = nodeSelectableCount;
                    handleClassScopeOrNodeOrSegChoose(nodeSelectedIndex, 3);
                }
            }
            if (foundDependencyLower) {
                ImGui::PopStyleColor();
            }
            if (foundDependencyHigher) {
                ImGui::PopStyleColor();
            }
            // mouse left key down on different item
            if (ImGui::IsItemActive() and nodeKeyDownIndex != nodeSelectableCount) {
                nodeKeyDownIndex = nodeSelectableCount;
                updateDependencyLowerAndHigher(nodeKeyDownIndex, 2);
            }
            if (isNothingEditing()) {
                // reorder
                if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                    int n_next = nodeSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                    if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::nodeNameOrder.size() && nodeDependencyConstraint.isInBound(n_next)) {
                        SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::nodeNameOrder, nodeSelectableCount, n_next);
                        ImGui::ResetMouseDragDelta();
                    }
                }
                // right click menu for each item
                if (ImGui::BeginPopupContextItem()) {
                    unselectAll();
                    nodeSelectedIndex = nodeSelectableCount;
                    nodeKeyDownIndex = nodeSelectableCount;
                    updateDependencyLowerAndHigher(nodeKeyDownIndex, 2);
                    if (ImGui::Selectable("new", false)) {
                        nodeMenuReaction.onNewItem();
                    }
                    if (ImGui::Selectable("delete", false)) {
                        nodeMenuReaction.onDeleteItem();
                    }
                    if (ImGui::Selectable("edit", false)) {
                        nodeMenuReaction.onEditItem(node);
                    }
                    if (ImGui::Selectable("showList", false)) {
                        nodeMenuReaction.onShowList(node);
                    }
                    ImGui::EndPopup();
                }
                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                    nodeMenuReaction.onEditItem(node);
                }
            }
            nodeSelectableCount++;
        }
        ImGui::EndChild();
        // node window end

        // line window start
        ImGui::SetCursorPos({ childWindowPadding, lineWindowTop });
        shadow(classWindowWidth, lineWindowHeight);
        ImGui::BeginChild("lineWindow", ImVec2(classWindowWidth, lineWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

        static bool openLineInstanceTab = false;
        if (ImGui::BeginTabBar("LineTab", ImGuiTabBarFlags_None)) {
            if (ImGui::BeginTabItem("Line Template")) {
                int lineSelectableCount = 0;
                for (auto lineName : SimpleView::SimpleViewToGraphConverter::lineNameOrder) {
                    if (lineSelectableCount >= SimpleView::SimpleViewToGraphConverter::lineNameOrder.size()) {
                        continue;
                    }
                    if (lineName.empty()) {
                        continue;
                    }
                    auto*& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName];
                    bool foundDependencyLower = lineDependencyConstraint.findInLowerBound(lineSelectableCount);
                    bool foundDependencyHigher = lineDependencyConstraint.findInHigherBound(lineSelectableCount);
                    if (foundDependencyLower) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
                    }
                    if (foundDependencyHigher) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
                    }
                    if (lineEditingIndex == lineSelectableCount) {
                        putIcon(SimpleView::LineTemplate::getIconId(lineEditingTypeIndex), fontSize);
                        addLineEditItem(fontSize);
                    } else {
                        putIcon(line->iconId, fontSize);
                        // mouse left key up on different item
                        if (ImGui::Selectable(line->displayText.data(), lineSelectedIndex == lineSelectableCount)) {
                            unselectAll();
                            lineSelectedIndex = lineSelectableCount;
                            handleClassScopeOrNodeOrSegChoose(lineSelectedIndex, 4);
                        }
                    }
                    if (foundDependencyLower) {
                        ImGui::PopStyleColor();
                    }
                    if (foundDependencyHigher) {
                        ImGui::PopStyleColor();
                    }
                    // mouse left key down on different item
                    if (ImGui::IsItemActive() and lineKeyDownIndex != lineSelectableCount) {
                        lineKeyDownIndex = lineSelectableCount;
                        updateDependencyLowerAndHigher(lineKeyDownIndex, 3);
                    }
                    if (isNothingEditing()) {
                        // reorder
                        if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                            int n_next = lineSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                            if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::lineNameOrder.size() && lineDependencyConstraint.isInBound(n_next)) {
                                SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::lineNameOrder, lineSelectableCount, n_next);
                                ImGui::ResetMouseDragDelta();
                            }
                        }
                        // right click menu for each item
                        if (ImGui::BeginPopupContextItem()) {
                            unselectAll();
                            lineSelectedIndex = lineSelectableCount;
                            lineKeyDownIndex = lineSelectableCount;
                            updateDependencyLowerAndHigher(lineKeyDownIndex, 3);
                            if (ImGui::Selectable("new", false)) {
                                lineMenuReaction.onNewItem();
                            }
                            if (not line->orderedParamName.empty()) {
                                if (ImGui::Selectable("new instance", false)) {
                                    openLineInstanceTab = true;
                                    lineMenuReaction.onNewInstance();
                                }
                            }
                            if (ImGui::Selectable("delete", false)) {
                                lineMenuReaction.onDeleteItem();
                            }
                            if (ImGui::Selectable("edit", false)) {
                                lineMenuReaction.onEditItem(line);
                            }
                            ImGui::EndPopup();
                        }
                        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                            lineMenuReaction.onEditItem(line);
                        }
                    }
                    lineSelectableCount++;
                }
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Line Instance", NULL, openLineInstanceTab ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None)) {
                openLineInstanceTab = false;
                int lineInstanceSelectableCount = 0;
                for (auto lineInstanceName : SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder) {
                    if (lineInstanceSelectableCount >= SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size()) {
                        continue;
                    }
                    if (lineInstanceName.empty()) {
                        continue;
                    }
                    auto& lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[lineInstanceName];
                    bool foundDependencyLower = lineInstanceDependencyConstraint.findInLowerBound(lineInstanceSelectableCount);
                    bool foundDependencyHigher = lineInstanceDependencyConstraint.findInHigherBound(lineInstanceSelectableCount);
                    if (foundDependencyLower) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
                    }
                    if (foundDependencyHigher) {
                        ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
                    }
                    putIcon(Images::instanceIconId, fontSize);
                    if (lineNewFinalInstance and lineInstanceSelectableCount == 0) {
                        addNewLineFinalInstance(fontSize);
                    } else if (lineFinalInstanceNameEditingIndex == lineInstanceSelectableCount) {
                        addLineFinalInstanceNameEdit(fontSize);
                    } else {
                        if (ImGui::Selectable(lineInstance->valName.data(), lineFinalInstanceSelectedIndex == lineInstanceSelectableCount)) {
                            unselectAll();
                            lineFinalInstanceSelectedIndex = lineInstanceSelectableCount;
                            handleClassScopeOrNodeOrSegChoose(lineFinalInstanceSelectedIndex, 5);
                        }
                        ImGui::SetItemTooltip(lineInstance->displayName.data());
                    }
                    if (foundDependencyLower) {
                        ImGui::PopStyleColor();
                    }
                    if (foundDependencyHigher) {
                        ImGui::PopStyleColor();
                    }
                    if (ImGui::IsItemActive() and lineFinalInstanceKeyDownIndex != lineInstanceSelectableCount) {
                        lineFinalInstanceKeyDownIndex = lineInstanceSelectableCount;
                        updateDependencyLowerAndHigher(lineFinalInstanceKeyDownIndex, 5);
                    }
                    if (isNothingEditing()) {
                        // reorder
                        if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                            int n_next = lineInstanceSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                            if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size()) {
                                SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder, lineInstanceSelectableCount, n_next);
                                ImGui::ResetMouseDragDelta();
                            }
                        }

                        // right click menu for each item
                        if (ImGui::BeginPopupContextItem()) {
                            unselectAll();
                            lineFinalInstanceSelectedIndex = lineInstanceSelectableCount;
                            lineFinalInstanceKeyDownIndex = lineInstanceSelectableCount;
                            updateDependencyLowerAndHigher(lineFinalInstanceKeyDownIndex, 5);
                            if (ImGui::Selectable("delete", false)) {
                                showDoubleCheckToDeleteLineInstance = true;
                            }
                            if (ImGui::Selectable("edit", false)) {
                                lineFinalInstanceNameEditingIndex = lineInstanceSelectableCount;
                                strcpy(lineFinalInstanceEditingName, lineInstanceName.data());
                            }
                            ImGui::EndPopup();
                        }
                        if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                            lineFinalInstanceNameEditingIndex = lineInstanceSelectableCount;
                            strcpy(lineFinalInstanceEditingName, lineInstanceName.data());
                        }
                    }
                    lineInstanceSelectableCount++;
                }
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        // todo style line instance differently
        ImGui::EndChild();
        // line window end

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

        // graph window start
        if (showGraphList) {
            ImGui::SetCursorPos({ childWindowPadding, graphWindowTop });
            shadow(classWindowWidth, graphWindowHeight);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, ColorRes::noBgColor);
            ImGui::BeginChild("graphWindow", ImVec2(classWindowWidth, graphWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);
            ImGui::PushStyleColor(ImGuiCol_ChildBg, panelBgColor);
            // graph list start
            ImGui::SetCursorPos({ 0, 0 });
            ImGui::BeginChild("graphList", ImVec2(graphItem1Width, graphWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

            static bool graphTemplateTabOpen = true;
            static bool openGraphInstanceTab = false;
            if (ImGui::BeginTabBar("GraphTab", ImGuiTabBarFlags_None)) {
                if (ImGui::BeginTabItem("Graph Template")) {
                    graphTemplateTabOpen = true;
                    int graphSelectableCount = 0;
                    for (auto graphName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
                        if (graphSelectableCount >= SimpleView::SimpleViewToGraphConverter::graphNameOrder.size()) {
                            continue;
                        }
                        if (graphName.empty()) {
                            continue;
                        }
                        auto& graph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
                        bool foundDependencyLower = graphDependencyConstraint.findInLowerBound(graphSelectableCount);
                        bool foundDependencyHigher = graphDependencyConstraint.findInHigherBound(graphSelectableCount);
                        if (foundDependencyLower) {
                            ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
                        }
                        if (foundDependencyHigher) {
                            ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
                        }
                        putIcon(Images::graphIconId, fontSize);
                        if (graphEditingIndex == graphSelectableCount) {
                            addGraphNameEditItem(fontSize);
                        } else {
                            if (ImGui::Selectable(graph->displayName.data(), graphSelectedIndex == graphSelectableCount)) {
                                if (graphEditingIndex < 0 and lineInstanceEditingIndex < 0 and intersectionPointEditingIndex < 0) {
                                    unselectAll();
                                    graphSelectedIndex = graphSelectableCount;
                                }
                            }
                        }

                        if (foundDependencyLower) {
                            ImGui::PopStyleColor();
                        }
                        if (foundDependencyHigher) {
                            ImGui::PopStyleColor();
                        }

                        if (ImGui::IsItemActive() and graphKeyDownIndex != graphSelectableCount) {
                            graphKeyDownIndex = graphSelectableCount;
                            updateDependencyLowerAndHigher(graphKeyDownIndex, 4);
                        }
                        if (isNothingEditing()) {
                            // reorder
                            if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                                int n_next = graphSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                                if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::graphNameOrder.size()) {
                                    SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::graphNameOrder, graphSelectableCount, n_next);
                                    ImGui::ResetMouseDragDelta();
                                }
                            }
                            // right click menu for each item
                            if (ImGui::BeginPopupContextItem()) {
                                unselectAll();
                                graphSelectedIndex = graphSelectableCount;
                                graphKeyDownIndex = graphSelectableCount;
                                updateDependencyLowerAndHigher(graphKeyDownIndex, 4);
                                if (ImGui::Selectable("new", false)) {
                                    graphMenuReaction.onNewItem();
                                }
                                if (not graph->orderedParamName.empty()) {
                                    if (ImGui::Selectable("new instance", false)) {
                                        openGraphInstanceTab = true;
                                        graphMenuReaction.onNewInstance();
                                    }
                                }
                                if (ImGui::Selectable("delete", false)) {
                                    graphMenuReaction.onDeleteItem();
                                }
                                if (ImGui::Selectable("edit", false)) {
                                    graphMenuReaction.onEditItem(graph);
                                }
                                ImGui::EndPopup();
                            }
                            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                                graphMenuReaction.onEditItem(graph);
                            }
                        }
                        graphSelectableCount++;
                    }
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Graph Instance", NULL, openGraphInstanceTab ? ImGuiTabItemFlags_SetSelected : ImGuiTabItemFlags_None)) {
                    openGraphInstanceTab = false;
                    graphTemplateTabOpen = false;
                    int graphInstanceSelectableCount = 0;
                    for (auto graphInstanceName : SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder) {
                        if (graphInstanceSelectableCount >= SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size()) {
                            continue;
                        }
                        if (graphInstanceName.empty()) {
                            continue;
                        }
                        auto& graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[graphInstanceName];
                        bool foundDependencyLower = graphInstanceDependencyConstraint.findInLowerBound(graphInstanceSelectableCount);
                        bool foundDependencyHigher = graphInstanceDependencyConstraint.findInHigherBound(graphInstanceSelectableCount);
                        if (foundDependencyLower) {
                            ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepLower);
                        }
                        if (foundDependencyHigher) {
                            ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::textColorDepHigher);
                        }
                        putIcon(Images::instanceIconId, fontSize);
                        if (graphNewInstance and graphInstanceSelectableCount == 0) {
                            addNewGraphInstance(fontSize);
                        } else if (graphInstanceNameEditingIndex == graphInstanceSelectableCount) {
                            addGraphInstanceNameEdit(fontSize);
                        } else {
                            if (ImGui::Selectable(graphInstance->valName.data(), graphInstanceSelectedIndex == graphInstanceSelectableCount)) {
                                unselectAll();
                                graphInstanceSelectedIndex = graphInstanceSelectableCount;
                            }
                            ImGui::SetItemTooltip(graphInstance->displayName.data());
                        }
                        if (foundDependencyLower) {
                            ImGui::PopStyleColor();
                        }
                        if (foundDependencyHigher) {
                            ImGui::PopStyleColor();
                        }
                        if (ImGui::IsItemActive() and graphInstanceKeyDownIndex != graphInstanceSelectableCount) {
                            graphInstanceKeyDownIndex = graphInstanceSelectableCount;
                            updateDependencyLowerAndHigher(graphInstanceKeyDownIndex, 6);
                        }
                        if (isNothingEditing()) {
                            // reorder
                            if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                                int n_next = graphInstanceSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                                if (n_next >= 0 && n_next < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size()) {
                                    SWAP_ELEMENT(SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder, graphInstanceSelectableCount, n_next);
                                    ImGui::ResetMouseDragDelta();
                                }
                            }

                            // right click menu for each item
                            if (ImGui::BeginPopupContextItem()) {
                                unselectAll();
                                graphInstanceSelectedIndex = graphInstanceSelectableCount;
                                graphInstanceKeyDownIndex = graphInstanceSelectableCount;
                                updateDependencyLowerAndHigher(graphInstanceKeyDownIndex, 6);
                                if (ImGui::Selectable("delete", false)) {
                                    showDoubleCheckToDeleteGraphInstance = true;
                                }
                                if (ImGui::Selectable("edit", false)) {
                                    graphInstanceNameEditingIndex = graphInstanceSelectableCount;
                                    strcpy(graphInstanceEditingName, graphInstanceName.data());
                                }
                                ImGui::EndPopup();
                            }
                            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                                graphInstanceNameEditingIndex = graphInstanceSelectableCount;
                                strcpy(graphInstanceEditingName, graphInstanceName.data());
                            }
                        }
                        graphInstanceSelectableCount++;
                    }
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }
            ImGui::EndChild();
            // graph list end
            if (graphTemplateTabOpen) {
                // lineinstance window start
                ImGui::SetCursorPos({ graphItem1Width + dividerWidth, 0 });
                ImGui::BeginChild("linesInGraphs", ImVec2(graphItem2Width, graphWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);

                auto selectedGraph = SimpleView::SimpleViewToGraphConverter::valNameToGraph[
                    SimpleView::SimpleViewToGraphConverter::graphNameOrder[graphSelectedIndex]];
                int lineInstanceSelectableCount = 0;
                for (auto& lineInstance : selectedGraph->lineInstances) {
                    if (intersectionPointEditingIndex < 0) {
                        putIcon(lineInstance->lineTemplate->iconId, fontSize);
                        if (ImGui::Selectable(lineInstance->displayName.data(), lineInstanceSelectedIndex == lineInstanceSelectableCount)) {
                            unselectAll();
                            lineInstanceSelectedIndex = lineInstanceSelectableCount;
                        }
                        if (lineInstanceEditingIndex == lineInstanceSelectableCount) {
                            addLineInstanceArgEditItem(fontSize);
                        }
                        if (lineInstanceNewIndex == lineInstanceSelectableCount) {
                            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + fontSize);
                            ImGui::Text("choose line above");
                        }
                        if (isNothingEditing()) {
                            // reorder
                            if (ImGui::IsItemActive() && !ImGui::IsItemHovered()) {
                                int n_next = lineInstanceSelectableCount + (ImGui::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                                if (n_next >= 0 && n_next < selectedGraph->lineInstances.size()) {
                                    selectedGraph->reorderLineInstance(lineInstanceSelectableCount, n_next);
                                    ImGui::ResetMouseDragDelta();
                                }
                            }
                            // right click menu for each item
                            if (ImGui::BeginPopupContextItem()) {
                                unselectAll();
                                lineInstanceSelectedIndex = lineInstanceSelectableCount;
                                lineKeyDownIndex = lineInstanceSelectableCount;
                                if (ImGui::Selectable("new", false)) {
                                    lineInstanceMenuReaction.onNewItem();
                                }
                                if (ImGui::Selectable("delete", false)) {
                                    lineInstanceMenuReaction.onDeleteItem();
                                }
                                if (ImGui::Selectable("edit", false)) {
                                    lineInstanceMenuReaction.onEditItem(lineInstance);
                                }
                                ImGui::EndPopup();
                            }
                            if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                                lineInstanceMenuReaction.onEditItem(lineInstance);
                            }
                        }
                    } else {
                        ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                        if (ImGui::TreeNodeEx(lineInstance->lineTemplate->name.data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                            addNodeInLineRecursively(lineInstance, lineInstance->lineTemplate, selectedGraph->intersectionPointsInLine[intersectionPointEditingIndex][lineInstanceSelectableCount], false);
                            ImGui::TreePop();
                        }
                    }
                    lineInstanceSelectableCount++;
                }

                ImGui::EndChild();
                // lineinstance window end
                // intersection in lines start
                ImGui::SetCursorPos({ graphItem1Width + graphItem2Width + dividerWidth * 2, 0 });
                ImGui::BeginChild("intersectionInLines", ImVec2(graphItem3Width, graphWindowHeight), ImGuiChildFlags_None, ImGuiWindowFlags_None);
                int intersectionPointCount = 0;
                static bool intersectionPointInLineNumberIsWrong = false;
                for (auto& point : selectedGraph->intersectionPointsInLine) {
                    bool isItemEditing = intersectionPointEditingIndex == intersectionPointCount;
                    if (isItemEditing) {
                        ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                    }
                    bool intersectionPointIOpen = ImGui::TreeNodeEx(("intersecton" + to_string(intersectionPointCount + 1)).data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen);
                    bool skipExpandTree = false;
                    if (isNothingEditing()) {
                        if (ImGui::BeginPopupContextItem()) {
                            unselectAll();
                            if (ImGui::Selectable("new", false)) {
                                skipExpandTree = true;
                                intersectionPointMenuReaction.onNewItem(intersectionPointCount);
                            }
                            if (ImGui::Selectable("delete", false)) {
                                skipExpandTree = true;
                                intersectionPointMenuReaction.onDeleteItem(intersectionPointCount);
                            }
                            if (ImGui::Selectable("edit", false)) {
                                intersectionPointMenuReaction.onEditItem(intersectionPointCount);
                            }
                            ImGui::EndPopup();
                        }
                    }
                    if (intersectionPointIOpen) {
                        if (not skipExpandTree) {
                            for (int lineCount = 0;lineCount < point.size();lineCount++) {
                                auto& lineInstance = selectedGraph->lineInstances[lineCount];
                                auto& lineTemplate = lineInstance->lineTemplate;
                                if (isItemEditing) {
                                    ImGui::SetNextItemOpen(true, ImGuiCond_Always);
                                }
                                if (ImGui::TreeNodeEx(lineTemplate->name.data(), ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_DefaultOpen)) {
                                    addIntersectPointRecursively(lineInstance, lineTemplate, point[lineCount], isItemEditing);
                                    ImGui::TreePop();
                                }
                            }
                        }
                        ImGui::TreePop();
                    }
                    if (intersectionPointEditingIndex == intersectionPointCount) {
                        if (ImGui::Button("Done##intersectionEditDone", { 3 * fontSize,searchBarHeight })) {
                            if (selectedGraph->countPointInLineOfIntersection(intersectionPointEditingIndex) < 2) {
                                intersectionPointInLineNumberIsWrong = true;
                            } else {
                                intersectionPointEditingIndex = -1;
                            }
                        }
                    }
                    intersectionPointCount++;
                }
                if (intersectionPointInLineNumberIsWrong) {
                    showRejectDialog("number of intersection points should be greater than one", &intersectionPointInLineNumberIsWrong);
                }
                ImGui::EndChild();
                // intersection in lines end
            }
            ImGui::PopStyleColor();
            ImGui::EndChild();
            ImGui::PopStyleColor(1);
        }
        // graph window end

        // show/hide graph list button start
        bool localShowGraphList = showGraphList;
        if (not localShowGraphList) {
            ImGui::PushStyleColor(ImGuiCol_Button, { 0,0,0,1 });
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0,0,0,1 });
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 0,0,0,1 });
        }
        ImGui::SetCursorPos({ childWindowPadding + classWindowWidth,childWindowPadding });
        if (ImGui::Button("##hideGraphList", { childWindowPadding,5 * childWindowPadding })) {
            showGraphList = false;
            forceRelayout();
        }
        if (not localShowGraphList) {
            ImGui::PopStyleColor(3);
        }
        if (localShowGraphList) {
            ImGui::PushStyleColor(ImGuiCol_Button, { 0,0,0,1 });
            ImGui::PushStyleColor(ImGuiCol_ButtonHovered, { 0,0,0,1 });
            ImGui::PushStyleColor(ImGuiCol_ButtonActive, { 0,0,0,1 });
        }
        ImGui::SetCursorPos({ childWindowPadding + classWindowWidth, childWindowHeight - 6 * childWindowPadding });
        if (ImGui::Button("##showGraphList", { childWindowPadding,5 * childWindowPadding })) {
            showGraphList = true;
            forceRelayout();
        }
        if (localShowGraphList) {
            ImGui::PopStyleColor(3);
        }
        // show/hide graph list button end

        ImGui::PopStyleColor(1);

        ImGui::EndChild();
        // edit window end

        // dispaly window start
        ImGui::SetCursorPos({ editWindowWidth + mainWindowPadding + spacingHor,mainWindowPadding });
        ImGui::BeginChild("displayWindow", ImVec2(displayWindowWidth, childWindowHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);
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

        // search bar start
        ImGui::SetCursorPos({ searchBarLeft,childWindowPadding });
        shadow(searchBarWidth, searchBarHeight);
        if (ImGui::InputTextEx("##searchbar", searchResults.empty() ? StringRes::singleton->getSearchClass() : StringRes::singleton->getSearchExisting(),
            searchedStr, 1024, { searchBarWidth,searchBarHeight }, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_EnterReturnsTrue)) {
            ImGui::SetKeyboardFocusHere(-1);
            if (searchResults.empty()) {
                onSearchClass();
            } else {
                filterSearchResults(searchResults);
            }
        }
        // search bar end

        // search result start
        ImGui::SetCursorPos({ searchBarLeft, childWindowPadding + searchBarHeight + childWindowSpacing });
        shadow(searchBarWidth, searchResultHeight);
        ImGui::BeginChild("searchResult", ImVec2(searchBarWidth, searchResultHeight), ImGuiChildFlags_AlwaysUseWindowPadding, ImGuiWindowFlags_None);

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
        ImGuiListClipper clipper;
        clipper.Begin(searchResults.size());
        static int searched_item_selected_index = -1;
        while (clipper.Step()) {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++) {
                if (ImGui::Selectable(searchResults[i], searched_item_selected_index == i)) {
                    searched_item_selected_index = i;
                    handleClassScopeOrNodeOrSegChoose(i, 1);
                }
                if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(0)) {
                    onSearchNode(searched_item_selected_index);
                }
                ImGui::SetItemTooltip(searchResults[i]);
            }
        }
        ImGui::PopStyleVar();

        ImGui::EndChild();
        // search result end

        ImGui::PopStyleColor(1);
        ImGui::EndChild();
        // dispaly window end

        showDialogForDeletion();

        ImGui::End();
        ImGui::PopStyleColor(5);
        ImGui::PopStyleVar();

    }
}
