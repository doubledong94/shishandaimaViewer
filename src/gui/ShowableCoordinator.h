class GuiState {
public:
    GuiState* mediator = NULL;
    virtual void render() {};
    virtual void onExit() {};
    virtual void onEnter() {};
    virtual void onKeyEvent(const shishan::KeyEvent& event) {};
    virtual bool showHint() { return false; };
    virtual void onWindowResize(int width, int height) {};
};

class LoadingState :public GuiState {

};

class ReadingState :public GuiState {
    void onKeyEvent(const shishan::KeyEvent& event) override;
    int getHotkeyIndex(const shishan::KeyEvent& event);
};

class ParsingState :public GuiState {

};

class EditingPanelState :public GuiState {

};

class ParsingReadState :public ParsingState {

};

class ParsingDoneState :public ParsingState {

};

class EditLineAndGraphState : public EditingPanelState {
public:
    EditLineAndGraphWindow* window = NULL;
    EditLineAndGraphState(EditLineAndGraphWindow* window);
    void render();
    void onWindowResize(int width, int height);

};

class SelectNodeState :public EditingPanelState {

};

class EditHotkeyState : public EditingPanelState {
public:
    HotkeyWindow* window = NULL;
    EditHotkeyState(HotkeyWindow* window);
    void render() override;
    void onExit() override;
    void onEnter() override;
    void onKeyEvent(const shishan::KeyEvent& event);
};


class ShowableCoordinator :public GuiState {
private:
public:
    static EditHotkeyState* editHotkeyState;
    static ReadingState* readingState;
    static EditLineAndGraphState* editLineAndGraphState;
    static map<GuiState*, set<GuiState*>> allowedTransition;
    static map<GuiState*, set<GuiState*>> allowedStack;
    static void staticInit();
    list<GuiState*> currentStates;
    void render() override;
    bool toState(GuiState* state);
    void stateBack();
    ShowableCoordinator();
    int windowWidth = 0;
    int windowHeight = 0;
    void onKeyEvent(const shishan::KeyEvent& event) override;
    void onWindowResize(int width, int height) override;
};

