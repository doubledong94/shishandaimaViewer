#include "imgui.h"
#include "imgui_internal.h"
#include "../util/util.h"
#include "../error/ErrorManager.h"
#include "../util/timer.h"
#include "LongPressStateMachine.h"
#include "DoubleClickStateMachine.h"
#include "HotkeyConfig.h"
#include "../file/FileManager.h"
#include "../res/StringRes.h"

unsigned int HotkeyConfig::GetOrderedScanCodes(unsigned char order[4]) {
    for (int pass = 0; pass < 2; pass++) {
        for (int o = 0; o < 3; o++) {
            if (order[o] > order[o + 1]) {
                ImSwap(order[o], order[o + 1]);
            }
        }
    }
    return (order[3] << 24) + (order[2] << 16) + (order[1] << 8) + order[0];
}

static bool isKeyAlphabetDown(Key& k) {
    bool rightShiftDown = k.imkey == ImGuiKey_LeftShift and ImGui::IsKeyDown(ImGuiKey_RightShift);
    bool rightCtrlDown = k.imkey == ImGuiKey_LeftCtrl and ImGui::IsKeyDown(ImGuiKey_RightCtrl);
    bool rightAltDown = k.imkey == ImGuiKey_LeftAlt and ImGui::IsKeyDown(ImGuiKey_RightAlt);
    return rightShiftDown or rightCtrlDown or rightAltDown or ImGui::IsKeyDown(k.imkey);
}

static int GetHotKeyDown(HotKey* hotkey, size_t hotkeyCount) {
    static unsigned int lastHotKey = 0xFFFFFFFF;
    unsigned char order[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
    int scanCodeCount = 0;
    for (auto orderAndKey : orderToKeyAlphabet) {
        if (isKeyAlphabetDown(orderAndKey.second)) {
            order[scanCodeCount] = orderAndKey.first;
            scanCodeCount++;
            if (scanCodeCount == 4)
                break;
        }
    }

    unsigned int newHotKey = HotkeyConfig::GetOrderedScanCodes(order);

    if (scanCodeCount) {
        if (newHotKey != lastHotKey) {
            for (size_t i = 0; i < hotkeyCount; i++) {
                if (hotkey[i].functionKeys == newHotKey) {
                    lastHotKey = newHotKey;
                    return int(i);
                }
            }
            lastHotKey = 0xFFFFFFFF;
        }
        return -1;
    }
    lastHotKey = 0xFFFFFFFF;
    return -1;
}

static bool isKeyStillPressed(HotKey& hotkey) {
    unsigned char order[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
    int scanCodeCount = 0;
    for (auto orderAndKey : orderToKeyAlphabet) {
        if (isKeyAlphabetDown(orderAndKey.second)) {
            order[scanCodeCount] = orderAndKey.first;
            scanCodeCount++;
            if (scanCodeCount == 4) {
                break;
            }
        }
    }
    unsigned int newHotKey = HotkeyConfig::GetOrderedScanCodes(order);
    return hotkey.functionKeys == newHotKey;
}

vector<HotKey> HotkeyConfig::hotkeys = {
    {SHOW_EDIT_HOTKEY,"show/edit hotkey",0xffffff51, SINGLE_CLICK},
    // prepare 1
    {PARSE_FILE,"parse files",0xff320501, SINGLE_CLICK},
    // prepare 2
    {SHOW_EDIT_LINE_AND_GRAPH,"edit line and graph",0xffffff2b, SINGLE_CLICK},
    {CHOOOSE_CLASS_SCOPE,"choose class scope",0xffffff33,SINGLE_CLICK},
    {CHOOSE_LINE_INSTANCE_TO_SEARCH,"search line instance",0xffffff34,SINGLE_CLICK},
    {CHOOSE_GRAPH_INSTANCE_TO_SEARCH,"search graph instance",0xffffff35,SINGLE_CLICK},
    // add and remove node
    {START_SEARCHING,"start searching",0xffff3601,SINGLE_CLICK},
    {REMOVE_SELECTED_NODES, "remove selected node", 0xffff6e01,SINGLE_CLICK},
    {REMOVE_ALL_NODES, "remove all node", 0xff6e0501,SINGLE_CLICK},
    {TRANSITIVE_REDUCTION, "transitive reduction", 0xffff2c01,SINGLE_CLICK},
    // select node
    {SELECT_ALL_NODE, "select all node", 0xffff3301,SINGLE_CLICK},
    {UNSELECT_ALL, "unselect all node", 0xffffff3e,SINGLE_CLICK},
    {REVERSE_SELECT, "reverse selection", 0xffff6e03,SINGLE_CLICK},
    {SHOW_SEARCHED_LINE_AND_GRAPH,"show searched line and graph",0xffffff2c,SINGLE_CLICK},
    {SELECT_BY_KEY_TYPE,"select by key type",0xffff3a01,SINGLE_CLICK},
    {SELECT_PATH_IN_BETWEEN, "select path in between", 0xffff403b,SINGLE_CLICK},
    {SELECT_PATH_UPWARD, "select path upward", 0xffff3b2f,SINGLE_CLICK},
    {SELECT_PATH_DOWNWARD, "select path downward", 0xffff3b35,SINGLE_CLICK},
    {SELECT_BY_DEGREE, "select by degree", 0xffff6a01,SINGLE_CLICK},
    {SELECT_BY_IN_DEGREE, "select by in degree", 0xffff6c01,SINGLE_CLICK},
    {SELECT_BY_OUT_DEGREE, "select by out degree", 0xffff6d01,SINGLE_CLICK},
    {SELECT_UPWARD, "select upward", 0xffffff6c,SINGLE_CLICK},
    {SELECT_DOWNWARD, "select downward", 0xffffff6d,SINGLE_CLICK},
    {SELECT_BY_COMPONENT, "select by component", 0xffffff32,SINGLE_CLICK},
    {SELECT_BY_GROUP, "select by group", 0xffff3201,SINGLE_CLICK},
    // layout
    {START_OR_STOP_LAYOUT_ANIM, "start/stop layout animiation", 0xffffff3c,SINGLE_CLICK},
    {TO_2D_LAYOUT,"2D layout",0xffffff52, SINGLE_CLICK},
    {TO_3D_LAYOUT,"3D layout",0xffffff53, SINGLE_CLICK},
    {INCREASE_TEMPERATURE, "increase temperature", 0xffff662d,SINGLE_CLICK},
    {DECREASE_TEMPERATURE, "decrease temperature", 0xffff652d,SINGLE_CLICK},
    {INCREASE_WEIGHT, "increase graph weight", 0xffff662a,SINGLE_CLICK},
    {DECREASE_WEIGHT, "decrease graph weight", 0xffff652a,SINGLE_CLICK},
    {RESET_WEIGHT, "reset graph weight", 0xff2a0501,SINGLE_CLICK},
    {FIX_POSITION, "fix position", 0xffff3f01,SINGLE_CLICK},
    {RELEASE_POSITION, "unfix position", 0xffff3f03,SINGLE_CLICK},
    {UNFIX_ALL_NODE, "unfix all position", 0xff3f0501,SINGLE_CLICK},
    {FIX_X_COORD, "fix x coord", 0xffff3d01,SINGLE_CLICK},
    {RELEASE_X_COORD, "fix x coord", 0xffff3d03,SINGLE_CLICK},
    {RELEASE_ALL_X_COORD, "fix x coord", 0xff3d0501,SINGLE_CLICK},
    {FIX_Y_COORD, "fix y coord", 0xffff2e01,SINGLE_CLICK},
    {RELEASE_Y_COORD, "fix y coord", 0xffff2e03,SINGLE_CLICK},
    {RELEASE_ALL_Y_COORD, "fix y coord", 0xff2e0501,SINGLE_CLICK},
    {BOUND_SELECTED_NODE, "bound selected node", 0xffff4001,SINGLE_CLICK},
    {UNBOUND_SELECTED_NODE, "unbound selected node", 0xffff4003,SINGLE_CLICK},
    {UNBOUND_UNSELECTED_NODE, "unbound unselected node", 0xff400501,SINGLE_CLICK},
    {GROUP, "group selected nodes", 0xffff3901,SINGLE_CLICK},
    {UNGROUP, "ungroup selected nodes", 0xffff3903,SINGLE_CLICK},
    {UNGROUP_ALL_NODE, "ungroup all nodes", 0xff390501,SINGLE_CLICK},
    {AUTO_GROUP_X, "auto group x", 0xffff3d3b,SINGLE_CLICK},
    {AUTO_GROUP_Y, "auto group y", 0xffff3b2e,SINGLE_CLICK},
    {AUTO_GROUP_XY, "auto group x and y", 0xffff3b39,SINGLE_CLICK},
    {BOUND_BY_CLASS, "bound by class", 0xffff403e,SINGLE_CLICK},
    {BOUND_BY_METHOD, "bound by method", 0xffff4240,SINGLE_CLICK},
    // style
    {SHOW_AND_HIDE_TEXT, "show and hide text", 0xffff3a03,SINGLE_CLICK},
    {SHOW_AND_HIDE_TOOLTIP, "show and hide tooltip", 0xffff2d03,SINGLE_CLICK},
    {INCREASE_NODE_TEXT_SIZE, "increase node text size", 0xffff663a,SINGLE_CLICK},
    {DECREASE_NODE_TEXT_SIZE, "decrease node text size", 0xffff653a,SINGLE_CLICK},
    {INCREASE_GUI_TEXT_SIZE, "increase GUI text size", 0xffff6601,SINGLE_CLICK},
    {DECREASE_GUI_TEXT_SIZE, "decrease GUI text size", 0xffff6501,SINGLE_CLICK},
    {BIGGER_NODE, "bigger node", 0xffff6631,SINGLE_CLICK},
    {SMALLER_NODE, "smaller node", 0xffff6531,SINGLE_CLICK},
    {WIDER_LINE, "wider line", 0xffff6630,SINGLE_CLICK},
    {THINNER_LINE, "thinner line", 0xffff6530,SINGLE_CLICK},
    {INCREASE_ALPHA_FOR_UNSELECTED, "less transparency for unselected", 0xffff6641,SINGLE_CLICK},
    {DECREASE_ALPHA_FOR_UNSELECTED, "more transparency for unselected", 0xffff6541,SINGLE_CLICK},
    {INCREASE_ALPHA_FOR_SELECTED, "less transparency for selected", 0xffff6642,SINGLE_CLICK},
    {DECREASE_ALPHA_FOR_SELECTED, "more transparency for selected", 0xffff6542,SINGLE_CLICK},
    {SET_COLOR, "set color", 0xffffff38,SINGLE_CLICK},
    {FLOW_COLOR_MAP, "color by flow", 0xffff3801,SINGLE_CLICK},
    {CLEAR_ALL_COLOR, "clear all color", 0xff380501,SINGLE_CLICK},
    // explore mode
    {SEARCH_DOWNWARD, "search downward", 0xffff6d03,SINGLE_CLICK},
    {SEARCH_UPWARD, "search upward", 0xffff6c03,SINGLE_CLICK},
    
    // for next round
    {SAVE_SELECTED_NODE, "save selected node", 0xffff3501,SINGLE_CLICK},

    // save and restore graph
    {SAVE_GRAPH, "save graph", 0xffff3401,SINGLE_CLICK},
    {RESTORE_GRAPH, "restore graph", 0xffff3101,SINGLE_CLICK},
    {DELETE_SAVED_GRAPH, "delete saved graph", 0xffff3103,SINGLE_CLICK},
};

map<int, ClickStyleHandler> HotkeyConfig::keyToClickHandler;

map<int, HotKey*> HotkeyConfig::hotkeyMap;

map<int, function<void(void)>> HotkeyConfig::functionEnumToFunction;

void HotkeyConfig::onFrame() {
    static int currentDownKeyIndex = -1;
    int downHotkeyIndex = GetHotKeyDown(hotkeys.data(), hotkeys.size());

    if (downHotkeyIndex != -1) {
        currentDownKeyIndex = downHotkeyIndex;
        HotKey& hotkey = hotkeys[downHotkeyIndex];
        if (keyToClickHandler.count(hotkey.functionKeys) == 0) {
            keyToClickHandler[hotkey.functionKeys] = ClickStyleHandler();
        }
        keyToClickHandler[hotkey.functionKeys].donw(hotkey);
    }
    if (currentDownKeyIndex != -1) {
        if (not isKeyStillPressed(hotkeys[currentDownKeyIndex])) {
            HotKey& hotkey = hotkeys[currentDownKeyIndex];
            if (keyToClickHandler.count(hotkey.functionKeys) == 0) {
                keyToClickHandler[hotkey.functionKeys] = ClickStyleHandler();
            }
            keyToClickHandler[hotkey.functionKeys].up(hotkey);
            currentDownKeyIndex = -1;
        }
    }
}

void HotkeyConfig::loadHotkeyConfig(const string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        int lineCount = 0;
        while (std::getline(file, line)) {
            if (line.size() > 5 and lineCount < hotkeys.size()) {
                hotkeys[lineCount].functionKeys = stoul(line.substr(0, 10));
                hotkeys[lineCount].clickStyle = stoi(line.substr(11));
            }
            lineCount++;
        }
        file.close();
    }
    init();
}

void HotkeyConfig::init() {
    for (auto& hotKey : hotkeys) {
        hotkeyMap[hotKey.hotkeyFunction] = &hotKey;
    }
    hotkeyMap[CHOOOSE_CLASS_SCOPE]->functionName = StringRes::singleton->getHotKeyTitle_chooseClass();
    hotkeyMap[CHOOSE_LINE_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_chooseLine();
    hotkeyMap[CHOOSE_GRAPH_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_chooseGraph();
    hotkeyMap[START_SEARCHING]->functionName = StringRes::singleton->getHotKeyTitle_startSearch();
    hotkeyMap[SHOW_SEARCHED_LINE_AND_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByPosition();
    hotkeyMap[SELECT_BY_KEY_TYPE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByKeyType();
    hotkeyMap[SHOW_EDIT_LINE_AND_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_editLineAndGraph();
    hotkeyMap[PARSE_FILE]->functionName = StringRes::singleton->getHotKeyTitle_parseSrc();
    hotkeyMap[TO_2D_LAYOUT]->functionName = StringRes::singleton->getHotKeyTitle_2DLayout();
    hotkeyMap[TO_3D_LAYOUT]->functionName = StringRes::singleton->getHotKeyTitle_3DLayout();
    hotkeyMap[INCREASE_TEMPERATURE]->functionName = StringRes::singleton->getHotKeyTitle_LayoutTempIncr();
    hotkeyMap[DECREASE_TEMPERATURE]->functionName = StringRes::singleton->getHotKeyTitle_LayoutTempDecr();
    hotkeyMap[START_OR_STOP_LAYOUT_ANIM]->functionName = StringRes::singleton->getHotKeyTitle_LayoutOnAndOff();
    hotkeyMap[BIGGER_NODE]->functionName = StringRes::singleton->getHotKeyTitle_NodeSizeIncr();
    hotkeyMap[SMALLER_NODE]->functionName = StringRes::singleton->getHotKeyTitle_NodeSizeDecr();
    hotkeyMap[WIDER_LINE]->functionName = StringRes::singleton->getHotKeyTitle_LineWidthIncr();
    hotkeyMap[THINNER_LINE]->functionName = StringRes::singleton->getHotKeyTitle_LineWidthDecr();
    hotkeyMap[INCREASE_ALPHA_FOR_UNSELECTED]->functionName = StringRes::singleton->getHotKeyTitle_UnselectedNodeAlphaIncr();
    hotkeyMap[DECREASE_ALPHA_FOR_UNSELECTED]->functionName = StringRes::singleton->getHotKeyTitle_UnselectedNodeAlphaDecr();
    hotkeyMap[INCREASE_ALPHA_FOR_SELECTED]->functionName = StringRes::singleton->getHotKeyTitle_SelectedNodeAlphaIncr();
    hotkeyMap[DECREASE_ALPHA_FOR_SELECTED]->functionName = StringRes::singleton->getHotKeyTitle_SelectedNodeAlphaDecr();
    hotkeyMap[SELECT_ALL_NODE]->functionName = StringRes::singleton->getHotKeyTitle_selectAllNode();
    hotkeyMap[UNSELECT_ALL]->functionName = StringRes::singleton->getHotKeyTitle_unselectAllNode();
    hotkeyMap[REMOVE_SELECTED_NODES]->functionName = StringRes::singleton->getHotKeyTitle_deleteNode();
    hotkeyMap[REMOVE_ALL_NODES]->functionName = StringRes::singleton->getHotKeyTitle_deleteAllNode();
    hotkeyMap[TRANSITIVE_REDUCTION]->functionName = StringRes::singleton->getHotKeyTitle_transitiveReduction();
    hotkeyMap[SELECT_UPWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeUpward();
    hotkeyMap[SELECT_DOWNWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeDownward();
    hotkeyMap[REVERSE_SELECT]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeBackward();
    hotkeyMap[SELECT_PATH_IN_BETWEEN]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeInBetween();
    hotkeyMap[SELECT_PATH_UPWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectPathUpward();
    hotkeyMap[SELECT_PATH_DOWNWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectPathDownward();
    hotkeyMap[SELECT_BY_IN_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByInDegree();
    hotkeyMap[SELECT_BY_OUT_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByOutDegree();
    hotkeyMap[SELECT_BY_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByDegree();
    hotkeyMap[SELECT_BY_COMPONENT]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByComponent();
    hotkeyMap[FLOW_COLOR_MAP]->functionName = StringRes::singleton->getHotKeyTitle_ColorNodeByFlow();
    hotkeyMap[CLEAR_ALL_COLOR]->functionName = StringRes::singleton->getHotKeyTitle_ClearAllNodeColor();
    hotkeyMap[SHOW_AND_HIDE_TOOLTIP]->functionName = StringRes::singleton->getHotKeyTitle_ShowAndHideTooltip();
    hotkeyMap[FIX_POSITION]->functionName = StringRes::singleton->getHotKeyTitle_FixedPositionOfSelected();
    hotkeyMap[RELEASE_POSITION]->functionName = StringRes::singleton->getHotKeyTitle_unFixedPositionOfSelected();
    hotkeyMap[SET_COLOR]->functionName = StringRes::singleton->getHotKeyTitle_ChooseColorForSelectedNode();
    hotkeyMap[SHOW_AND_HIDE_TEXT]->functionName = StringRes::singleton->getHotKeyTitle_NodeTextOnAndOff();
    hotkeyMap[INCREASE_NODE_TEXT_SIZE]->functionName = StringRes::singleton->getHotKeyTitle_NodeTextSizeIncr();
    hotkeyMap[DECREASE_NODE_TEXT_SIZE]->functionName = StringRes::singleton->getHotKeyTitle_NodeTextSizeDecr();
    hotkeyMap[INCREASE_GUI_TEXT_SIZE]->functionName = StringRes::singleton->getHotKeyTitle_GUITextSizeIncr();
    hotkeyMap[DECREASE_GUI_TEXT_SIZE]->functionName = StringRes::singleton->getHotKeyTitle_GUITextSizeDecr();
    hotkeyMap[INCREASE_WEIGHT]->functionName = StringRes::singleton->getHotKeyTitle_LayoutWeightOfSelectedIncr();
    hotkeyMap[DECREASE_WEIGHT]->functionName = StringRes::singleton->getHotKeyTitle_LayoutWeightOfSelectedDecr();
    hotkeyMap[RESET_WEIGHT]->functionName = StringRes::singleton->getHotKeyTitle_ResetLayoutWeightOfAllNode();
    hotkeyMap[GROUP]->functionName = StringRes::singleton->getHotKeyTitle_GroupSelected();
    hotkeyMap[UNGROUP]->functionName = StringRes::singleton->getHotKeyTitle_unGroupSelected();
    hotkeyMap[SELECT_BY_GROUP]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByGroup();
    hotkeyMap[SAVE_SELECTED_NODE]->functionName = StringRes::singleton->getHotKeyTitle_SaveSelectedNode();
    hotkeyMap[UNFIX_ALL_NODE]->functionName = StringRes::singleton->getHotKeyTitle_unFixedPositionOfAllNode();
    hotkeyMap[UNGROUP_ALL_NODE]->functionName = StringRes::singleton->getHotKeyTitle_unGroupAllNode();
    hotkeyMap[SEARCH_UPWARD]->functionName = StringRes::singleton->getHotKeyTitle_searchUpward();
    hotkeyMap[SEARCH_DOWNWARD]->functionName = StringRes::singleton->getHotKeyTitle_searchDownward();
    hotkeyMap[FIX_X_COORD]->functionName = StringRes::singleton->getHotKeyTitle_FixedXCoordOfSelected();
    hotkeyMap[RELEASE_X_COORD]->functionName = StringRes::singleton->getHotKeyTitle_unFixedXCoordOfSelected();
    hotkeyMap[RELEASE_ALL_X_COORD]->functionName = StringRes::singleton->getHotKeyTitle_unFixedXCoordOfAllNode();
    hotkeyMap[FIX_Y_COORD]->functionName = StringRes::singleton->getHotKeyTitle_FixedYCoordOfSelected();
    hotkeyMap[RELEASE_Y_COORD]->functionName = StringRes::singleton->getHotKeyTitle_unFixedYCoordOfOfSelected();
    hotkeyMap[RELEASE_ALL_Y_COORD]->functionName = StringRes::singleton->getHotKeyTitle_unFixedYCoordOfOfAllNode();
    hotkeyMap[AUTO_GROUP_X]->functionName = StringRes::singleton->getHotKeyTitle_autoGroupX();
    hotkeyMap[AUTO_GROUP_Y]->functionName = StringRes::singleton->getHotKeyTitle_autoGroupY();
    hotkeyMap[AUTO_GROUP_XY]->functionName = StringRes::singleton->getHotKeyTitle_autoGroupXY();
    hotkeyMap[SAVE_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_saveGraph();
    hotkeyMap[RESTORE_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_restoreGraph();
    hotkeyMap[DELETE_SAVED_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_deleteSavedGraph();
    hotkeyMap[BOUND_SELECTED_NODE]->functionName = StringRes::singleton->getHotKeyTitle_boundSelected();
    hotkeyMap[UNBOUND_SELECTED_NODE]->functionName = StringRes::singleton->getHotKeyTitle_unboundSelected();
    hotkeyMap[UNBOUND_UNSELECTED_NODE]->functionName = StringRes::singleton->getHotKeyTitle_unboundUnselected();
    hotkeyMap[BOUND_BY_CLASS]->functionName = StringRes::singleton->getHotKeyTitle_boundByClass();
    hotkeyMap[BOUND_BY_METHOD]->functionName = StringRes::singleton->getHotKeyTitle_boundByMethod();
}

void HotkeyConfig::saveHotkeyConfig(const string& filePath) {
    ofstream f;
    f.open(filePath);
    if (f.is_open()) {
        for (auto& hotkey : hotkeys) {
            f << hotkey.functionKeys << " " << hotkey.clickStyle << "\n";
        }
        f.close();
    } else {
        spdlog::get(ErrorManager::FileManagerTag)->critical("save hotkey failed");
    }
}

ClickStyleHandler::ClickStyleHandler() {
    longPressStateMachine = new LongPressStateMachine(500);
    doubleClickStateMachine = new DoubleClickStateMachine(500);
}

void ClickStyleHandler::donw(HotKey& hotkey) {
    switch (hotkey.clickStyle) {
    case LONG_PRESS:
        longPressStateMachine->onPress(HotkeyConfig::functionEnumToFunction[hotkey.hotkeyFunction]);
        break;
    case DOUBLE_CLICK:
        break;
    case SINGLE_CLICK:
        break;
    default:
        break;
    }
}

void ClickStyleHandler::up(HotKey& hotkey) {
    switch (hotkey.clickStyle) {
    case LONG_PRESS:
        longPressStateMachine->onRelease();
        break;
    case DOUBLE_CLICK:
        doubleClickStateMachine->onClick(HotkeyConfig::functionEnumToFunction[hotkey.hotkeyFunction]);
        break;
    case SINGLE_CLICK:
        HotkeyConfig::functionEnumToFunction[hotkey.hotkeyFunction]();
        break;
    default:
        break;
    }
}
