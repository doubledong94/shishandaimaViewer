class DoubleClickStateMachine {
public:
    DoubleClickStateMachine(const long& timeoutMilli);
    void onClick(const std::function<void(void)>& onDoubleClick);
private:
    const static int state_init = 0;
    const static int state_first_click_down_and_time_counting = 1;
    const static int state_second_click_down_before_timeout = 2;
    const static int state_timeout_before_second_click = 3;

    const static int msg_click_down = 1;
    const static int msg_first_click_timeout = 2;

    int currentState = state_init;
    int timeoutMilli;
    std::function<void(void)> onDoubleClick;
    Timer* timer;

    void handleMessage(int msg);
    void startTimeout();
    void cancelTimeout();
};