static int loadingAddressableTotal = 0;
static int loadingAddressableIndex = 0;
static char loadingAddressableName[500];
static int loadingUnaddressableTotal = 0;
static int loadingUnaddressableIndex = 0;
static char loadingUnaddressableName[500];

static std::function<void(int, int, const char*)> loadingAddressableProgress = [](int progress, int total, const char* fileName) {
    loadingAddressableTotal = total;
    strcpy(loadingAddressableName, fileName);
    if (progress > total) {
        loadingAddressableIndex = 0;
    } else {
        loadingAddressableIndex = progress;
    }
    };

static std::function<void(int, int, const char*)> loadingUnaddressableProgress = [](int progress, int total, const char* fileName) {
    loadingUnaddressableTotal = total;
    strcpy(loadingUnaddressableName, fileName);
    if (progress > total) {
        loadingUnaddressableIndex = 0;
    } else {
        loadingUnaddressableIndex = progress;
    }
    };

namespace app {
    class Application {
    private:
        Parser* parser;
        ThreadPool* textLoaderThreadPool = NULL;
        vector<ReactiveMouseListener*> listeners;
        threepp::Raycaster raycaster;
        std::shared_ptr<BoundedIncrementalGraph> boundedGraph;
    public:
        Application(Parser* parser1);

        int ApplicationMain();

        static std::function<void(char*, vector<const char*>&)> searchNodeInGraph;
        static std::function<void(set<const char*>&, vector<const char*>&)> searchNodeByMethodOfRuntime;
        static std::function<void(set<const char*>&, vector<const char*>&)> searchNodeByAddressableKey;
        static std::function<void(map<string, map<string, set<string>>>&, vector<const char*>&)> searchNodeByPositionInRegex;
    };
};
