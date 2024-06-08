
struct Key {
    ImGuiKey imkey;
    const char* name = nullptr;
    float offset = 0;
    float width = 40;
};

static unordered_map<int, Key> orderToKeyAlphabet = {
        {81,{ImGuiKey_1, "1", 40}},
        {82,{ImGuiKey_2, "2"}},
        {83,{ImGuiKey_3, "3"}},
        {84,{ImGuiKey_4, "4"}},
        {85,{ImGuiKey_5, "5"}},
        {86,{ImGuiKey_6, "6"}},
        {87,{ImGuiKey_7, "7"}},
        {88,{ImGuiKey_8, "8"}},
        {89,{ImGuiKey_9, "9"}},
        {90,{ImGuiKey_0, "0"}},
        {101,{ImGuiKey_Minus, "-"}},
        {102,{ImGuiKey_Equal, "+"}},

        {41,{ImGuiKey_Q, "Q", 60}},
        {42,{ImGuiKey_W, "W"}},
        {43,{ImGuiKey_E, "E"}},
        {44,{ImGuiKey_R, "R"}},
        {45,{ImGuiKey_T, "T"}},
        {46,{ImGuiKey_Y, "Y"}},
        {47,{ImGuiKey_U, "U"}},
        {48,{ImGuiKey_I, "I"}},
        {49,{ImGuiKey_O, "O"}},
        {50,{ImGuiKey_P, "P"}},
        {103,{ImGuiKey_LeftBracket, "["}},
        {104,{ImGuiKey_RightBracket, "]"}},
        {105,{ImGuiKey_Backslash, "\\", 0, 60}},

        {51,{ImGuiKey_A, "A", 80}},
        {52,{ImGuiKey_S, "S"}},
        {53,{ImGuiKey_D, "D"}},
        {54,{ImGuiKey_F, "F"}},
        {55,{ImGuiKey_G, "G"}},
        {56,{ImGuiKey_H, "H"}},
        {57,{ImGuiKey_J, "J"}},
        {58,{ImGuiKey_K, "K"}},
        {59,{ImGuiKey_L, "L"}},
        {106,{ImGuiKey_Semicolon, ";"}},
        {107,{ImGuiKey_Apostrophe, "'"}},

        {3,{ImGuiKey_LeftShift, "Shift", 0, 104}},
        {60,{ImGuiKey_Z, "Z"}},
        {61,{ImGuiKey_X, "X"}},
        {62,{ImGuiKey_C, "C"}},
        {63,{ImGuiKey_V, "V"}},
        {64,{ImGuiKey_B, "B"}},
        {65,{ImGuiKey_N, "N"}},
        {66,{ImGuiKey_M, "M"}},
        {108,{ImGuiKey_Comma, ","}},
        {109,{ImGuiKey_Period, "."}},
        {110,{ImGuiKey_Slash, "/"}},
        // {4,{ImGuiKey_RightShift, "Shift", 0, 104}},

        {1,{ImGuiKey_LeftCtrl, "Ctrl", 0, 60}},
        {5,{ImGuiKey_LeftAlt, "Alt", 68, 60}},
        {7,{ImGuiKey_Space, "Space", 0, 260}},
        // {6,{ImGuiKey_RightAlt, "Alt", 0, 60}},
        // {2,{ImGuiKey_RightCtrl, "Ctrl", 68, 60}},
};

enum HotkeyFunction {
    SHOW_EDIT_HOTKEY,
    CHOOOSE_CLASS_SCOPE,
    CHOOSE_LINE_INSTANCE_TO_SEARCH,
    CHOOSE_GRAPH_INSTANCE_TO_SEARCH,
    START_SEARCHING,
    SHOW_SEARCHED_LINE_AND_GRAPH,
    SHOW_EDIT_LINE_AND_GRAPH,
    PARSE_FILE,
    TO_2D_LAYOUT,
    TO_3D_LAYOUT,
    INCREASE_TEMPERATURE,
    DECREASE_TEMPERATURE,
    START_OR_STOP_LAYOUT_ANIM,
    BIGGER_NODE,
    SMALLER_NODE,
    WIDER_LINE,
    THINNER_LINE,
    INCREASE_ALPHA_FOR_UNSELECTED,
    DECREASE_ALPHA_FOR_UNSELECTED,
    INCREASE_ALPHA_FOR_SELECTED,
    DECREASE_ALPHA_FOR_SELECTED,
    SELECT_ALL_NODE,
    UNSELECT_ALL,
    REMOVE_SELECTED_NODES,
    REMOVE_ALL_NODES,
    SELECT_UPWARD,
    SELECT_DOWNWARD,
    REVERSE_SELECT,
    SELECT_PATH_IN_BETWEEN,
    SELECT_PATH_UPWARD,
    SELECT_PATH_DOWNWARD,
    SELECT_BY_IN_DEGREE,
    SELECT_BY_OUT_DEGREE,
    SELECT_BY_DEGREE,
    SELECT_BY_COMPONENT,
    FLOW_COLOR_MAP,
    CLEAR_ALL_COLOR,
    FIX_POSITION,
    RELEASE_POSITION,
    SET_COLOR,
    SHOW_AND_HIDE_TEXT,
    INCREASE_NODE_TEXT_SIZE,
    DECREASE_NODE_TEXT_SIZE,
    INCREASE_GUI_TEXT_SIZE,
    DECREASE_GUI_TEXT_SIZE,
    INCREASE_WEIGHT,
    DECREASE_WEIGHT,
    RESET_WEIGHT,
    GROUP,
    UNGROUP,
    SELECT_BY_GROUP,
    SELECT_BY_KEY_TYPE,
    SAVE_SELECTED_NODE,
    UNFIX_ALL_NODE,
    UNGROUP_ALL_NODE,
    SEARCH_UPWARD,
    SEARCH_DOWNWARD,
    SHOW_AND_HIDE_TOOLTIP,
    TRANSITIVE_REDUCTION,
    FIX_X_COORD,
    RELEASE_X_COORD,
    RELEASE_ALL_X_COORD,
    FIX_Y_COORD,
    RELEASE_Y_COORD,
    RELEASE_ALL_Y_COORD,
    BOUND_SELECTED_NODE,
    UNBOUND_SELECTED_NODE,
    UNBOUND_UNSELECTED_NODE,
    AUTO_GROUP_X,
    AUTO_GROUP_Y,
    AUTO_GROUP_XY,
    SAVE_GRAPH,
    RESTORE_GRAPH,
    DELETE_SAVED_GRAPH,
    BOUND_BY_CLASS,
    BOUND_BY_METHOD,
};

enum ClickStyle {
    SINGLE_CLICK,
    DOUBLE_CLICK,
    LONG_PRESS
};

struct HotKey {
    int hotkeyFunction;
    const char* functionName;
    unsigned int functionKeys;
    int clickStyle;
};

class ClickStyleHandler {
public:
    LongPressStateMachine* longPressStateMachine = NULL;
    DoubleClickStateMachine* doubleClickStateMachine = NULL;
    ClickStyleHandler();
    void donw(HotKey& hotkey);
    void up(HotKey& hotkey);
};

class HotkeyConfig {
public:
    static vector<HotKey> hotkeys;
    static map<int, HotKey*> hotkeyMap;

    static map<int, ClickStyleHandler> keyToClickHandler;

    static map<int, function<void(void)>> functionEnumToFunction;

    static unsigned int GetOrderedScanCodes(unsigned char order[4]);

    static void onFrame();

    static void loadHotkeyConfig(const string& filePath);

    static void init();

    static void saveHotkeyConfig(const string& filePath);
};