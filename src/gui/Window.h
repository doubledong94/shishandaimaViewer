class Window : public Showable {
public:
    int flag;
    int windowWidth;
    int windowHeight;
    float widthRatio = 0.8f;
    float heightRatio = 0.8f;
    Window(int flag);
    virtual void applyPosAndSize() override;
    void onWindowResize() override;
    void begin() override;
    void end() override;
};