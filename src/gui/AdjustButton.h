class AdjustButton : public Button {
    bool draging = false;
    float lastPosX = 0;
    float lastPosY = 0;
    DragEvent* event = new DragEvent();
    void renderContent() override;
};