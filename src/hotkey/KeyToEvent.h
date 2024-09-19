
class KeyToEvent {
public:
    list<ImGuiKey> allowedKeys;
    set<ImGuiKey> lastKeyCodes;
    set<ImGuiKey> currentKeyCodes;
    function<void(const shishan::KeyEvent&)>& eventReceiver;
    std::chrono::time_point<std::chrono::steady_clock> timer;

    KeyToEvent(function<void(const shishan::KeyEvent&)>& eventReceiver);
    void update();
private:
    int lastAction = -1;
    void updateCurrentKeyCodes();
    bool isSubsetOfBefore();
    void copyToLast();
    void resetTimer();
    bool isTimeOut();
};

