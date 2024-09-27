class Window : public Showable {
public:
    int flag;
    int windowWidth;
    int windowHeight;
    float widthRatio = 0.99f;
    float heightRatio = 0.99f;
    ShowableParam uiStructure;
    Window(int flag);
    virtual void applyPosAndSize() override;
    void onWindowResize() override;
    void begin() override;
    void end() override;
};