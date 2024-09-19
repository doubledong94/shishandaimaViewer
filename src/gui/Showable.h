class ShowableStyle {
public:
    virtual void pushStyle() {};
    virtual void popStyle() {};
};

class Showable;
class LayoutAlgo {
public:
    virtual void applyLayout(Showable* parent, int index) {};
};

class PaddingLayoutAlgo : public LayoutAlgo {
    int padding;
public:
    PaddingLayoutAlgo(int padding);
    void applyLayout(Showable* parent, int index) override;
};

class SplitLayoutAlgo :public LayoutAlgo {
    bool horizontal = false;
    int splitCount = 0;
    vector<float> ratios;
    int padding = 0;
    int spacing = 0;
public:
    SplitLayoutAlgo(bool horizontal, const vector<float>& ratios, int padding, int spacing);
    void applyLayout(Showable* parent, int index) override;
};

class TransparentWindowStyle : public ShowableStyle {
public:
    static TransparentWindowStyle* instance;
    void pushStyle();
    void popStyle();
};

class TransparentChildStyle : public ShowableStyle {
public:
    static TransparentChildStyle* instance;
    void pushStyle();
    void popStyle();
};

class NormalStyle : public ShowableStyle {
public:
    static NormalStyle* instance;
    void pushStyle();
    void popStyle();
};

class ShowableEvent {

};

class ShowableMediator {
public:
    virtual void notify(Showable* sender, ShowableEvent* event) {};
};

/**
 * bridge mode:
 * the kind of showable: window childwindow
 * the style of showable
 * the layout of children of showable
 * the mediator of children of showable
 */
struct ShowableParam {
    char* label = NULL;
    bool shadow = false;
    Showable* showable;
    LayoutAlgo* layoutAlgo;
    ShowableMediator* mediator;
    list<ShowableStyle*> styleComb;
    vector<ShowableParam> childParams;
};

class Showable {
private:
public:
    ShowableParam* showableParam = NULL;
    int left = 0;
    int top = 0;
    int width = 0;
    int height = 0;
    virtual void render();
    virtual void applyPosAndSize();
    virtual void begin() {};
    void addShadow(float width, float height);
    virtual void renderContent();
    void renderChildren();
    virtual void end() {};
    virtual void onKeyEvent(const shishan::KeyEvent& event) {};
    virtual void onWindowResize();
    Showable();
    void setupParamRecur(ShowableParam* showableParam);
};

