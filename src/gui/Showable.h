class ShowableStyle {
public:
    virtual void pushStyle() {};
    virtual void popStyle() {};
};

class Showable;
class ShowableEvent {
public:
    virtual int getType() { return -1; };
};

class DragEvent : public ShowableEvent {
public:
    static int type;
    float xDiff;
    float yDiff;
    int getType() override;
};

class DragAdjustEvent : public ShowableEvent {
public:
    static int type;
    DragEvent* dragEvent = NULL;
    int childIndex = -1;
    int parentWidth;
    int parentHeight;
    DragAdjustEvent(DragEvent* dragEvent, int childIndex, int parentWidth, int parentHeight);
    int getType() override;
};

class LayoutAlgo {
public:
    virtual void applyLayout(Showable* parent, int index) {};
    virtual void onWindowResize(Showable* showable) {};
    virtual void adjust(ShowableEvent* event) {};
};

class PaddingLayoutAlgo : public LayoutAlgo {
    int padding;
public:
    PaddingLayoutAlgo(int padding);
    void applyLayout(Showable* parent, int index) override;
};

class SplitLayoutAlgo :public LayoutAlgo {
public:
    bool horizontal = false;
    int splitCount = 0;
    vector<float> ratios;
    int padding = 0;
    int spacing = 0;
    float paddingRatio = 0;
    float spacingRatio = 0;
    SplitLayoutAlgo(bool horizontal, const vector<float>& ratios, float paddingRatio, float spacingRatio);
    void applyLayout(Showable* parent, int index) override;
    void applyLayoutHor(Showable* parent, int index, float startRatio, float endRatio);
    void applyLayoutVer(Showable* parent, int index, float startRatio, float endRatio);
    void onWindowResize(Showable* showable) override;
    void adjust(ShowableEvent* event) override;
    void adjustHor(DragAdjustEvent* event);
    void adjustVer(DragAdjustEvent* event);
};

class TransparentWindowStyle : public ShowableStyle {
public:
    static TransparentWindowStyle* instance;
    void pushStyle();
    void popStyle();
};

class DebugWindowStyle : public ShowableStyle {
public:
    static DebugWindowStyle* instance;
    void pushStyle();
    void popStyle();
};

class DebugChildStyle : public ShowableStyle {
public:
    ImVec4& color;
    void pushStyle();
    void popStyle();
    DebugChildStyle(ImVec4& color);
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

class ShowableMediator {
public:
    Showable* showable = NULL;
    ShowableMediator* next = NULL;
    ShowableMediator() {};
    ShowableMediator(ShowableMediator* next) :next(next) {};
    void notify(Showable* sender, ShowableEvent* event);
    void setShowable(Showable* showable);
    virtual bool handle(Showable* sender, ShowableEvent* event) { return false; };
};

class AdjustMediator : public ShowableMediator {
public:
    bool handle(Showable* sender, ShowableEvent* event) override;
};

/**
 * bridge mode:
 * the kind of showable: window childwindow
 * the style of showable
 * the layout of children of showable
 * the mediator of children of showable
 */
struct ShowableParam {
    string label = "";
    bool shadow = false;
    Showable* showable;
    LayoutAlgo* layoutAlgo;
    ShowableMediator* mediator;
    list<ShowableStyle*> styleComb;
    list<ShowableStyle*> styleCombForChild;
    vector<ShowableParam> childParams;
};

class Showable {
private:
public:
    Showable* parent = NULL;
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
    int getChildIndex(Showable* child);
};

