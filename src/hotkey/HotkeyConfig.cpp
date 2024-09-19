#include "imgui.h"
#include "imgui_internal.h"
#include "util/util.h"
#include "hotkey/HotkeyConfig.h"
#include "res/StringRes.h"
#include "error/ErrorManager.h"

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

vector<HotKey> HotkeyConfig::hotkeys = {
    {SHOW_EDIT_HOTKEY,"show/edit hotkey",0xffffff51},
    // prepare 1
    {PARSE_FILE,"parse files",0xff320501},
    // prepare 2
    {SHOW_EDIT_LINE_AND_GRAPH,"edit line and graph",0xffffff2b},
    {CHANGE_MAX_SEARCH_DEPTH,"change max search depth",0xffffff37},
    {CHOOOSE_CLASS_SCOPE,"choose class scope",0xffffff33},
    {UNCHOOOSE_CLASS_SCOPE,"unchoose class scope",0xffff3303},
    {CHOOSE_LINE_INSTANCE_TO_SEARCH,"search line instance",0xffffff34},
    {UNCHOOSE_LINE_INSTANCE_TO_SEARCH,"unsearch line instance",0xffff3403},
    {CHOOSE_GRAPH_INSTANCE_TO_SEARCH,"search graph instance",0xffffff35},
    {UNCHOOSE_GRAPH_INSTANCE_TO_SEARCH,"unsearch graph instance",0xffff3503},
    {EXCLUDE_PACKAGE,"exclude package",0xffff6e32},
    {EXCLUDE_CLASS,"exclude class",0xffff6e3e},
    // add and remove node
    {START_SEARCHING,"start searching",0xffff3601},
    {REMOVE_SELECTED_NODES, "remove selected node", 0xffff6e01},
    {REMOVE_ALL_NODES, "remove all node", 0xff6e0501},
    {TRANSITIVE_REDUCTION, "transitive reduction", 0xffff2c01},
    // select node
    {SELECT_ALL_NODE, "select all node", 0xffff3301},
    {UNSELECT_ALL, "unselect all node", 0xffffff3e},
    {REVERSE_SELECT, "reverse selection", 0xffff6e03},
    {SELECT_LOOP, "select loop", 0xffff3b01},
    {SELECT_UPWARD, "select upward", 0xffffff6c},
    {SELECT_UPWARD_TO_THE_TOP, "select upward", 0xffff6c03},
    {SELECT_DOWNWARD, "select downward", 0xffffff6d},
    {SELECT_DOWNWARD_TO_THE_BOTTOM, "select downward", 0xffff6d03},
    {SELECT_PATH_IN_BETWEEN, "select path in between", 0xffff403b},
    {SELECT_SHORTEST_PATH_IN_BETWEEN, "select shortest path in between", 0xffff3b34},
    {SELECT_PATH_UPWARD, "select path upward", 0xffff3b2f},
    {SELECT_PATH_DOWNWARD, "select path downward", 0xffff3b35},
    {SHOW_SEARCHED_LINE_AND_GRAPH,"show searched line and graph",0xffffff2c},
    {SELECT_BY_KEY_TYPE,"select by key type",0xffff3a01},
    {SELECT_BY_DEGREE, "select by degree", 0xffff6a01},
    {SELECT_BY_IN_DEGREE, "select by in degree", 0xffff6c01},
    {SELECT_BY_OUT_DEGREE, "select by out degree", 0xffff6d01},
    {SELECT_BY_METHOD_SATCK_SIZE, "select by method stack size", 0xffff4201},
    {SELECT_BY_COMPONENT, "select by component", 0xffffff32},
    {SELECT_BY_GROUP, "select by group", 0xffff3201},
    {SELECT_FROM_ALL, "select from all or from selected", 0xffffff36},
    {DIM_CONTROL_EDITOR, "dim control editor", 0xffffff2f},
    {SHOW_SELECTED_NODE_TEXT, "show selected node text", 0xffffff6b},
    // layout
    {START_OR_STOP_LAYOUT_ANIM, "start/stop layout animiation", 0xffffff3c},
    {TO_2D_LAYOUT,"2D layout",0xffffff52},
    {TO_3D_LAYOUT,"3D layout",0xffffff53},
    {INCREASE_TEMPERATURE, "increase temperature", 0xffff662d},
    {DECREASE_TEMPERATURE, "decrease temperature", 0xffff652d},
    {INCREASE_WEIGHT, "increase graph weight", 0xffff662a},
    {DECREASE_WEIGHT, "decrease graph weight", 0xffff652a},
    {RESET_WEIGHT, "reset graph weight", 0xff2a0501},
    {FIX_POSITION, "fix position", 0xffff3f01},
    {RELEASE_POSITION, "unfix position", 0xffff3f03},
    {UNFIX_ALL_NODE, "unfix all position", 0xff3f0501},
    {FIX_X_COORD, "fix x coord", 0xffff3d01},
    {RELEASE_X_COORD, "fix x coord", 0xffff3d03},
    {RELEASE_ALL_X_COORD, "fix x coord", 0xff3d0501},
    {FIX_Y_COORD, "fix y coord", 0xffff2e01},
    {RELEASE_Y_COORD, "fix y coord", 0xffff2e03},
    {RELEASE_ALL_Y_COORD, "fix y coord", 0xff2e0501},
    {BOUND_SELECTED_NODE, "bound selected node", 0xffff4001},
    {UNBOUND_SELECTED_NODE, "unbound selected node", 0xffff4003},
    {UNBOUND_UNSELECTED_NODE, "unbound unselected node", 0xff400501},
    {GROUP, "group selected nodes", 0xffff3901},
    {UNGROUP, "ungroup selected nodes", 0xffff3903},
    {UNGROUP_ALL_NODE, "ungroup all nodes", 0xff390501},
    {AUTO_GROUP_X, "auto group x", 0xffff3d3b},
    {AUTO_GROUP_Y, "auto group y", 0xffff3b2e},
    {AUTO_GROUP_XY, "auto group x and y", 0xffff3b39},
    {BOUND_BY_CLASS, "bound by class", 0xffff403e},
    {BOUND_BY_METHOD, "bound by method", 0xffff4240},
    {TREE_UP, "tree up", 0xffff2f2d},
    {TREE_DOWN, "tree down", 0xffff352d},
    // style
    {SHOW_AND_HIDE_TEXT, "show and hide text", 0xffff3a03},
    {SHOW_AND_HIDE_TOOLTIP, "show and hide tooltip", 0xffff2d03},
    {SHOW_AND_HIDE_BOUND_FRAME, "show and hide bound frame", 0xff400301},
    {INCREASE_NODE_TEXT_SIZE, "increase node text size", 0xffff663a},
    {DECREASE_NODE_TEXT_SIZE, "decrease node text size", 0xffff653a},
    {INCREASE_GUI_TEXT_SIZE, "increase GUI text size", 0xffff6601},
    {DECREASE_GUI_TEXT_SIZE, "decrease GUI text size", 0xffff6501},
    {BIGGER_NODE, "bigger node", 0xffff6631},
    {SMALLER_NODE, "smaller node", 0xffff6531},
    {WIDER_LINE, "wider line", 0xffff6630},
    {THINNER_LINE, "thinner line", 0xffff6530},
    {INCREASE_ALPHA_FOR_UNSELECTED, "less transparency for unselected", 0xffff6641},
    {DECREASE_ALPHA_FOR_UNSELECTED, "more transparency for unselected", 0xffff6541},
    {INCREASE_ALPHA_FOR_SELECTED, "less transparency for selected", 0xffff6642},
    {DECREASE_ALPHA_FOR_SELECTED, "more transparency for selected", 0xffff6542},
    {SET_COLOR, "set color", 0xffffff38},
    {FLOW_COLOR_MAP, "color by flow", 0xffff3801},
    {CLEAR_ALL_COLOR, "clear all color", 0xff380501},
    // explore mode
    {SEARCH_DOWNWARD, "search downward", 0xffff6d05},
    {SEARCH_UPWARD, "search upward", 0xffff6c05},

    // for next round
    {SAVE_SELECTED_NODE, "save selected node", 0xffff3501},

    // save and restore graph
    {SAVE_GRAPH, "save graph", 0xffff3401},
    {RESTORE_GRAPH, "restore graph", 0xffff3101},
    {DELETE_SAVED_GRAPH, "delete saved graph", 0xffff3103},
};

map<int, HotKey*> HotkeyConfig::hotkeyMap;

map<int, function<void(void)>> HotkeyConfig::functionEnumToFunction;

void HotkeyConfig::loadHotkeyConfig(const string& filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        int lineCount = 0;
        while (std::getline(file, line)) {
            if (line.size() > 5 and lineCount < hotkeys.size()) {
                hotkeys[lineCount].functionKeys = stoul(line.substr(0, 10));
            }
            lineCount++;
        }
        file.close();
    }
    init();
}

void HotkeyConfig::saveHotkeyConfig(const string& filePath) {
    ofstream f;
    f.open(filePath);
    if (f.is_open()) {
        for (auto& hotkey : hotkeys) {
            f << hotkey.functionKeys << "\n";
        }
        f.close();
    } else {
        spdlog::get(ErrorManager::FileManagerTag)->critical("save hotkey failed");
    }
}

void HotkeyConfig::init() {
    for (auto& hotKey : hotkeys) {
        hotkeyMap[hotKey.hotkeyFunction] = &hotKey;
    }
    hotkeyMap[CHOOOSE_CLASS_SCOPE]->functionName = StringRes::singleton->getHotKeyTitle_chooseClass();
    hotkeyMap[CHOOSE_LINE_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_chooseLine();
    hotkeyMap[CHOOSE_GRAPH_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_chooseGraph();
    hotkeyMap[UNCHOOOSE_CLASS_SCOPE]->functionName = StringRes::singleton->getHotKeyTitle_unchooseClass();
    hotkeyMap[UNCHOOSE_LINE_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_unchooseLine();
    hotkeyMap[UNCHOOSE_GRAPH_INSTANCE_TO_SEARCH]->functionName = StringRes::singleton->getHotKeyTitle_unchooseGraph();
    hotkeyMap[EXCLUDE_PACKAGE]->functionName = StringRes::singleton->getHotKeyTitle_excludePackage();
    hotkeyMap[EXCLUDE_CLASS]->functionName = StringRes::singleton->getHotKeyTitle_excludeClass();
    hotkeyMap[START_SEARCHING]->functionName = StringRes::singleton->getHotKeyTitle_startSearch();
    hotkeyMap[SHOW_SEARCHED_LINE_AND_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByPosition();
    hotkeyMap[SELECT_BY_KEY_TYPE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByKeyType();
    hotkeyMap[SHOW_EDIT_LINE_AND_GRAPH]->functionName = StringRes::singleton->getHotKeyTitle_editLineAndGraph();
    hotkeyMap[CHANGE_MAX_SEARCH_DEPTH]->functionName = StringRes::singleton->getHotKeyTitle_changeMaxSearchDepth();
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
    hotkeyMap[SELECT_FROM_ALL]->functionName = StringRes::singleton->getHotKeyTitle_selectFromAll();
    hotkeyMap[DIM_CONTROL_EDITOR]->functionName = StringRes::singleton->getHotKeyTitle_dimControlEditor();
    hotkeyMap[SHOW_SELECTED_NODE_TEXT]->functionName = StringRes::singleton->getHotKeyTitle_showSelectedNodeText();
    hotkeyMap[SELECT_ALL_NODE]->functionName = StringRes::singleton->getHotKeyTitle_selectAllNode();
    hotkeyMap[UNSELECT_ALL]->functionName = StringRes::singleton->getHotKeyTitle_unselectAllNode();
    hotkeyMap[REMOVE_SELECTED_NODES]->functionName = StringRes::singleton->getHotKeyTitle_deleteNode();
    hotkeyMap[REMOVE_ALL_NODES]->functionName = StringRes::singleton->getHotKeyTitle_deleteAllNode();
    hotkeyMap[TRANSITIVE_REDUCTION]->functionName = StringRes::singleton->getHotKeyTitle_transitiveReduction();
    hotkeyMap[SELECT_UPWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeUpward();
    hotkeyMap[SELECT_DOWNWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeDownward();
    hotkeyMap[SELECT_UPWARD_TO_THE_TOP]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeUpwardToTheTop();
    hotkeyMap[SELECT_DOWNWARD_TO_THE_BOTTOM]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeDownwardToTheBottom();
    hotkeyMap[REVERSE_SELECT]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeBackward();
    hotkeyMap[SELECT_LOOP]->functionName = StringRes::singleton->getHotKeyTitle_selectLoop();
    hotkeyMap[SELECT_PATH_IN_BETWEEN]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeInBetween();
    hotkeyMap[SELECT_SHORTEST_PATH_IN_BETWEEN]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeShortestInBetween();
    hotkeyMap[SELECT_PATH_UPWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectPathUpward();
    hotkeyMap[SELECT_PATH_DOWNWARD]->functionName = StringRes::singleton->getHotKeyTitle_selectPathDownward();
    hotkeyMap[SELECT_BY_IN_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByInDegree();
    hotkeyMap[SELECT_BY_OUT_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByOutDegree();
    hotkeyMap[SELECT_BY_METHOD_SATCK_SIZE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByMethodStackSize();
    hotkeyMap[SELECT_BY_DEGREE]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByDegree();
    hotkeyMap[SELECT_BY_COMPONENT]->functionName = StringRes::singleton->getHotKeyTitle_selectNodeByComponent();
    hotkeyMap[FLOW_COLOR_MAP]->functionName = StringRes::singleton->getHotKeyTitle_ColorNodeByFlow();
    hotkeyMap[CLEAR_ALL_COLOR]->functionName = StringRes::singleton->getHotKeyTitle_ClearAllNodeColor();
    hotkeyMap[SHOW_AND_HIDE_TOOLTIP]->functionName = StringRes::singleton->getHotKeyTitle_ShowAndHideTooltip();
    hotkeyMap[SHOW_AND_HIDE_BOUND_FRAME]->functionName = StringRes::singleton->getHotKeyTitle_ShowAndHideBoundFrame();
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
    hotkeyMap[TREE_UP]->functionName = StringRes::singleton->getHotKeyTitle_treeUp();
    hotkeyMap[TREE_DOWN]->functionName = StringRes::singleton->getHotKeyTitle_treeDown();
}

