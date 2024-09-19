/**
 * action: down up pressing
 */
namespace shishan {
    struct KeyEvent {
        set<ImGuiKey> keyCodes;
        int action;
        bool isActionDown() const {
            return action == 1;
        }
        bool isActionUp() const {
            return action == 2;
        }
        bool isActionLongPressing() const {
            return action == 3;
        }
    };
}

