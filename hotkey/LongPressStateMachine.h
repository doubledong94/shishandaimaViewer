class LongPressStateMachine {
public:
    LongPressStateMachine(const long& timeoutMilli);
    void onPress(std::function<void(void)>& onLongPress);
    void onRelease();

private:
    const static int state_init = 0;
    const static int state_pressed = 1;
    const static int state_released_before_timeout = 2;
    const static int state_timeout_before_released = 3;

    const static int msg_press = 1;
    const static int msg_release = 2;
    const static int msg_timeout = 3;

    int currentState = state_init;
    int timeoutMilli;
    std::function<void(void)> onLongPress;
    Timer* timer;

    void handleMessage(int msg);
    void startTimeout();
    void cancelTimeout();
};