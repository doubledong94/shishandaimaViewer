struct AnimValue {
    float x;
    float y;
    float z;
    void set(float x, float y, float z);
};

class AnimationInstace {
public:
    int token;
    vector<float> progress = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1, };
    int currentProgress = -1;
    AnimValue startValue = { 0,0,0 };
    AnimValue endValue = { 1,1,1 };
    AnimValue currentValue = { 0,0,0 };
    AnimValue lastValue = { 0,0,0 };
    void upadteAnim();
    bool animFinished();
    void start();
    AnimationInstace();
};

class AnimationUtil {
public:
    static int tokenCount;
    static map<int, AnimationInstace*> runningAnim;
    static map<int, function<void(AnimValue)>> endListener;
    static void upadteAnim();
    static bool isAnimRunning(int token);
    static AnimValue getCurrentAnimValue(int token);
    static AnimValue getLastAnimValue(int token);
    static void saveCurrentValueAsLastValue(int token);
    static int addAnimation(AnimValue start, AnimValue end);
    static void applyAnimAction(int token, const function<void(AnimValue, AnimValue)>& action);
    static void addEndListener(int token, const function<void(AnimValue)>& listener);
};