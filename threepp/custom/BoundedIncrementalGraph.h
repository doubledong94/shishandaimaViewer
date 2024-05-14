class PositionInRegex {
public:
    PositionInRegex(const string& graphName, const string& lineName, const string& regex);
    string graphName;
    string lineName;
    string regex;
};

class NodeInfo {
public:
    list<PositionInRegex*> positionInRegex;
    string methodOfRuntime;
    string runtimeKey;
    string key;
    int keyType;
    string simpleName;
    string uniKey;
    int nodeId = -1;
    PositionInRegex* getExistingPositionInRegex(const string& graphName, const string& lineName, const string& regex);
    static string makeUniKey(int keyType, string& methodOfRuntime, string& runtimeKey);
    void makeSimpleName();
    string& getSimpleName();
};

template<typename T>
struct NeedToBeUpdated {
    bool needUpdate = false;
    T data;
};

class GraphDragNodeMouseListener;

struct TextLoadingItem {
    int nodeId;
    string text;
};

class BoundedIncrementalGraph : public threepp::Group {
public:

    string searchingGraphName;
    std::mutex bufferLock;
    std::mutex graphGenerateAndConsumeLock;
    // push back and pop front by different thread
    list<Tail*> lineBuffer;
    void addBuffers(const vector<Tail*>& bufs);
    void popBuffers(int count, vector<Tail*>& ret);
    int bufferSize();

    map<string, NodeInfo*> uniKeyToNodeInfo;
    map<string, set<NodeInfo*>> methodOfRuntimeToNodeInfo;
    map<string, set<NodeInfo*>> addressableKeyToNodeInfo;
    map<string, map<string, map<string, set<NodeInfo*>>>> graphNameToLineNameToRegexToNodeInfo;
    void removeExistingNodeRecord(int index);
    NodeInfo* getExistingNodeInfo(string& uniKey);
    void saveNodeInfo(NodeInfo* nodeInfo);
    NodeInfo* convertTailToNodeInfo(Tail* tail);

    vector<NodeInfo*> nodesOrderedByNodeId;
    igraph_t* theOriginalGraph = NULL;
    igraph_matrix_t* layoutMatrix;
    igraph_vector_t* layoutBounds[6];
    igraph_vector_t* weights;
    vector<threepp::Vector3> points;
    vector<pair<int, int>> edgePairs;
    float temperature = 0.1f;
    bool layoutAnimating = true;
    ThreadPool* layoutThreadPool = NULL;
    ThreadPool* textLoaderThreadPool = NULL;
    bool showSimpleText = true;
    map<int, TextLoadingItem> textLoading;
    set<int> textLoaded;
    set<int> textAdded;
    vector<set<int>> groups;
    vector<std::shared_ptr<threepp::Mesh>> textMesh;
    threepp::Font font;
    void updateGraph();
    void reCreateLayout(int nodeCount, bool is2D, bool dimensionChanged = false, igraph_vector_int_t* mapFromNewToOldNodeId = NULL);
    void updateAnim(threepp::Camera& camera);

    void alterPosByGroup();

    void set2DLayout(bool use2DLayout);

    void increaseTemperature();

    void decreaseTemperature();

    void increaseNodeSize();

    void decreaseNodeSize();

    void increaseLineWidth();

    void decreaseLineWidth();

    void startOrStopLayoutAnimating();

    std::shared_ptr<Nodes> nodesObj;
    std::shared_ptr<FlowLine> linesObj;

    static std::shared_ptr<BoundedIncrementalGraph> create(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
        TwoDControls* twoDControls,
        threepp::ThreeDControls* threeDControls);

    BoundedIncrementalGraph(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
        TwoDControls* twoDControls,
        threepp::ThreeDControls* threeDControls);

    int getNodeCount();

    int getEdgeCount();

    float getNodeSize();

    float getEdgeWidth();

    float getAlphaForUnselected();

    float getAlphaForSelected();

    float getLayoutTemperature();

    void increaseDecreaseAlphaForUnselected(bool increase);

    void increaseDecreaseAlphaForSelected(bool increase);

    void startFlowFrom(int nodeInstanceId);

    void onNodeRightClicked(int nodeInstanceId);

    void onNodeLeftClicked(int nodeInstanceId);

    void onNodeHover(int nodeInstanceId);

    void onExitHover();

    void onDrag(int id, float deltaX, float deltaY, float deltaZ);

    void onNodeColorChanged();

    void selectAll();

    void unselectAll();

    void selectUpward();

    void selectDownward();

    void reverseSelect();

    void selectPathInBetween();

    void lookUpForCommonAncestor(int i, int j, set<int>& visited, set<int>& path, set<int>& selected);

    void lookUpForCommonAncestor(int i, set<int>& otherNodes, set<int>& selected);

    void lookDownForCommonChild(int i, int j, set<int>& visited, set<int>& path, set<int>& selected);

    void lookDownForCommonChild(int i, set<int>& otherNodes, set<int>& selected);

    void lookEachOtherForPath(int i, int j, set<int>& visited, set<int>& selected);

    void lookEachOtherForPath(int i, set<int>& otherNodes, set<int>& selected);

    void select(set<int>& s);

    void select(set<const char*>& uniKeys);

    void prepareInDegreeMap();

    void prepareOutDegreeMap();

    void prepareDegreeMap();

    void prepareComponent();

    void prepareGroup();

    void flowColor();

    float getNodeRelativePosition(int nodeId);

    float maxDistanceFromTop(int nodeId);

    float maxDistanceToBottom(int nodeId);

    bool isNodeGrouped(int nodeId);

    void prepareDistanceFromTop();

    void prepareDistanceToBottom();

    void prepareDistance();

    void clearSpecifiedColor();

    void removeSelectedNodes();

    void removeSelectedNodesImpl();

    void removeAllNodes();

    void mapNodeInfoForDeletion(igraph_vector_int_t* mapFromNewToOldNodeId);

    void mapGroupForDeletion(igraph_vector_int_t* mapFromNewToOldNodeId);

    void mapNodeIdFromOldToNew(set<int>& oldIds, igraph_vector_int_t* mapFromOldToNewNodeId);

    void searchNodeInGraph(char* searchStr, vector<const char*>& searchResult);

    void searchNodeByMethodOfRuntime(set<const char*>& methodOfRuntime, vector<const char*>& searchResult);

    void searchNodeByAddressableKey(set<const char*>& addressableKey, vector<const char*>& searchResult);

    void searchNodeByPositionInRegex(map<string, map<string, set<string>>>& positionInRegex, vector<const char*>& searchResult);

    void resetLayoutBound(bool is2D);

    void fixPosition();

    void releasePosition();

    void releaseAllPosition();

    void setColorForSeletedNode(float r, float g, float b);

    void toggleShowSimpleText();

    void refreshSimpleText();

    void updateTextPosAt(int i);

    void changeTextSize(bool increase);

    void changeWeightForSelectedNode(bool increase);

    void resetWeight();

    void groupSelectedNodes();

    void ungroupSelectedNodes();

    void ungroupAllNodes();

    list<pair<string, string>> getSelectedKey();

    list<tuple<string, string, string, int>> getSelectedRuntime();

    // tested property start
    bool isDag();

    float diameter();
    // tested property end

    void dispose();
    void raycast(const threepp::Raycaster& raycaster, std::vector<threepp::Intersection>& intersects) override;
    threepp::Raycaster* raycaster = nullptr;
    threepp::Canvas* canvas = nullptr;
    TwoDControls* twoDControls = NULL;
    threepp::ThreeDControls* threeDControls = NULL;
    std::function<void(threepp::Vector3)> onFocusOn;
    std::function<void(string&)> showTooltip;
    std::function<void()> hideTooltip;
    void invalidateAllGraphInfo();
    NeedToBeUpdated<map<int, set<int>>> inDegreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> outDegreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> degreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> componentToNodes;
    vector<set<int>*> orderedByComponentSize;
    NeedToBeUpdated<igraph_matrix_t> distanceFromTop;
    NeedToBeUpdated<igraph_matrix_t> distanceToBottom;
    NeedToBeUpdated<igraph_matrix_t> distance;

    // 0 for remove nothing
    // 1 for remove selected node
    // 2 for remove unselected node
    int removeNodeType = 0;
    int lastClickedNodeId = -1;
    bool nodeClickedForTheFirstTime = true;

    enum {
        LAYOUT_STATE_2D,
        LAYOUT_STATE_3D,
        LAYOUT_STATE_2D_UNFINISHED,
        LAYOUT_STATE_3D_UNFINISHED,
    };
    int layoutState = -1;
private:

    float alphaForUnselected = 0.3f;
    float alphaForSelected = 1.0f;
    float textSize = 1;

    ReactiveMouseListener* showTextMouseListener = nullptr;
    GraphDragNodeMouseListener* dragMouseListener = nullptr;

    vector<ReactiveMouseListener*>* enabledListeners;

    DoubleClickStateMachine* doubleClickStateMachine = NULL;

};