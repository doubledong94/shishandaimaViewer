class PositionInRegex {
public:
    PositionInRegex(const string& graphName, const string& lineName, const string& regex);
    PositionInRegex();
    string graphName;
    string lineName;
    string regex;
    void toFile(ofstream& f);
    void fromFile(ifstream& f);
};

class NodeInfo {
public:
    list<PositionInRegex*> positionInRegex;
    string runtimeClass;
    string methodOfRuntime;
    string runtimeKey;
    string key;
    string typeKey;
    string declaredInType;
    int keyType;
    string simpleName;
    string uniKey;
    int methodStackSize = 0;
    int nodeId = -1;
    bool isWritten = false;
    bool isOverride = false;
    PositionInRegex* getExistingPositionInRegex(const string& graphName, const string& lineName, const string& regex);
    static string makeUniKey(int keyType, string& methodOfRuntime, string& runtimeKey);
    void makeSimpleName();
    void makeTypeKey();
    void makeRuntimeClass();
    void makeDeclaredInType();
    string& getSimpleName();
    string& getTypeKey();
    string& getRuntimeClass();
    string& getDeclaredInType();
    void toFile(ofstream& f);
    void fromFile(ifstream& f);
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

    bool graphIncreasing = false;
    vector<pair<int, std::function<void()>>> doOnNextFrame;
    void clearDoOnNextFrame();
    string searchingGraphName;
    std::mutex bufferLock;
    std::mutex graphGenerateAndConsumeLock;
    // push back and pop front by different thread
    list<Tail*> lineBuffer;
    // lineBuffer is created in prolog thread, so it should be returned by prolog thread, otherwise, no memory is reused
    list<Tail*> doneBuffer;
    void addBuffers(const vector<Tail*>& bufs);
    void popBuffers(int count, vector<Tail*>& ret);
    void returnDoneBufferToPool();
    int bufferSize();

    map<string, NodeInfo*> uniKeyToNodeInfo;
    map<string, set<NodeInfo*>> methodOfRuntimeToNodeInfo;
    map<string, set<NodeInfo*>> addressableKeyToNodeInfo;
    map<string, map<string, map<string, set<NodeInfo*>>>> graphNameToLineNameToRegexToNodeInfo;
    void removeExistingNodeRecord(int index);
    NodeInfo* getExistingNodeInfo(string& uniKey);
    void saveNodeInfo(NodeInfo* nodeInfo);
    void saveNodePosition(PositionInRegex* position, NodeInfo* nodeInfo);
    NodeInfo* convertTailToNodeInfo(Tail* tail);

    vector<NodeInfo*> nodesOrderedByNodeId;
    igraph_t* theOriginalGraph = NULL;
    igraph_matrix_t* layoutMatrix;
    igraph_vector_t* layoutBounds[6];
    igraph_vector_t* weights;
    threepp::Vector3 srcPos = { 0,0,0 };
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
    vector<set<int>> xCoordFixed;
    vector<set<int>> yCoordFixed;
    vector<set<int>> bounds;
    bool selectedFromAll = true;
    bool treeUpAndDownCircle = false;
    void groupToFile(ofstream& f, set<int>& group);
    void groupFromFile(ifstream& f, set<int>& group);
    vector<std::shared_ptr<threepp::Mesh>> textMesh;
    threepp::Font font;
    void updateGraph();
    void reCreateLayout(int nodeCount, bool is2D, bool dimensionChanged = false, igraph_vector_int_t* mapFromNewToOldNodeId = NULL);
    void reCreateLayoutWithNoOldLayoutInfo(int nodeCount, bool is2D, bool dimensionChanged = false);
    void updateAnim(threepp::Camera& camera);

    bool updatePosByGroup(vector<set<int>>& groups, int which);

    void applyPosByGroup(vector<set<int>>& groups);

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
    vector<std::shared_ptr<BoundFrame>> boundFrames;
    bool raycastByDrag = false;
    bool raycastOnFrame = false;

    static std::shared_ptr<BoundedIncrementalGraph> create(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
        TwoDControls* twoDControls,
        threepp::ThreeDControls* threeDControls);

    BoundedIncrementalGraph(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
        TwoDControls* twoDControls,
        threepp::ThreeDControls* threeDControls);

    int getNodeCount();

    int getEdgeCount();

    float getAlphaForUnselected();

    float getAlphaForSelected();

    float getLayoutTemperature();

    void increaseDecreaseAlphaForUnselected(bool increase);

    void increaseDecreaseAlphaForSelected(bool increase);

    void startFlowFrom(int nodeInstanceId, bool backward);

    void onNodeRightClicked(int nodeInstanceId);

    void onNodeLeftClicked(int nodeInstanceId);

    void onBoundDragIconClicked(int id);

    void onNodeHover(int nodeInstanceId);

    void onExitHover();

    void onDrag(set<int>& ids, float deltaX, float deltaY, float deltaZ);

    void onDragX(set<int>& ids, float deltaX);

    void onDragY(set<int>& ids, float deltaY);

    void getGroupIfGrouped(int id, set<int>& ids, vector<set<int>>& groups);

    void onNodeColorChanged();

    void resetStyledNodes();

    void selectByKeyType(int keyType);

    void selectAll();

    void unselectAll();

    void selectUpward();

    void selectUpwardToTheTop();

    void selectDownward();

    void selectDownwardToTheBottom();

    void reverseSelect();

    void selectShortestPathInBetween();

    void selectPathInBetween();

    void selectPathUpward();

    void selectPathDownward();

    void lookUpForCommonAncestor(int i, int j, set<int>& visited, set<int>& path, set<int>& selected);

    void lookUpForCommonAncestor(int i, set<int>& otherNodes, set<int>& selected);

    void lookDownForCommonChild(int i, int j, set<int>& visited, set<int>& path, set<int>& selected);

    void lookDownForCommonChild(int i, set<int>& otherNodes, set<int>& selected);

    void lookEachOtherForPath(int i, int j, set<int>& visited, set<int>& selected);

    void lookEachOtherForPath(int i, set<int>& otherNodes, set<int>& selected);

    void lookEachOtherForShortestPath(int i, int j, set<int>& visited, set<int>& selected);

    void lookEachOtherForShortestPath(int i, set<int>& otherNodes, set<int>& selected);

    void select(set<int>& s);

    void select(set<const char*>& uniKeys);

    void selectLoop();

    void prepareInDegreeMap();

    void prepareOutDegreeMap();

    void prepareDegreeMap();

    void prepareComponent();

    void prepareSelectByMethodStackSize();

    void clearEmptyGroup(vector<set<int>>& groups);

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

    void mapGroupForDeletion(vector<set<int>>& groups, igraph_vector_int_t* mapFromNewToOldNodeId);

    void mapNodeIdFromOldToNew(set<int>& oldIds, igraph_vector_int_t* mapFromOldToNewNodeId);

    void searchNodeInGraph(char* searchStr, vector<const char*>& searchResult);

    void searchNodeByMethodOfRuntime(set<const char*>& methodOfRuntime, vector<const char*>& searchResult);

    void searchNodeByAddressableKey(set<const char*>& addressableKey, vector<const char*>& searchResult);

    void searchNodeByPositionInRegex(map<string, map<string, set<string>>>& positionInRegex, vector<const char*>& searchResult);

    void resetLayoutBound(bool is2D);

    void resetBounds();

    void applyBounds();

    void boundByClass();

    void boundByMethod();

    void fixPosition();

    void releasePosition();

    void releaseAllPosition();

    void setColorForSeletedNode(float r, float g, float b);

    void toggleShowSimpleText();

    void refreshSimpleText();

    void updateTextPos();

    void updateTextPosAt(int i);

    void changeTextSize(bool increase);

    void changeWeightForSelectedNode(bool increase);

    void resetWeight();

    void groupSelectedNodes(vector<set<int>>& groups);

    void groupNodes(set<int>& newGroup, vector<set<int>>& groups);

    void ungroupSelectedNodes(vector<set<int>>& groups);

    void ungroupNodes(set<int>& ungroup, vector<set<int>>& groups);

    void ungroupAllNodes(vector<set<int>>& groups);

    void removeCircle();

    void transitiveReduction();

    void transitiveReductionImpl();

    void grid(vector<set<int>>& toBeGruped);

    void groupByMethod();

    list<pair<string, string>> getSelectedKey();

    list<tuple<string, string, string, int, string>> getSelectedRuntime();

    threepp::Vector3 getMidPosOfSelectedNodes();

    bool is2DLayout();

    void scaleByDistance(bool force = false);

    void applyLayoutPosition();

    void showAndHideBoundFrame(bool show);

    void getConnectedNodesByDim(int nodeId, set<int>& nodeTypes, set<int>& connected, bool dir);

    void focusHoverd();

    void applyLayoutTreeUpAndDown(bool up);

    void applyLayout(bool force = false);

    void printSelectedNode(const set<int>& excludeTypes, string& ret);

    static std::function<void(int, set<int>&)> getDimControl;
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
    std::function<void(threepp::Vector2)> onFocusOn;
    std::function<void(string&)> showTooltip;
    std::function<void()> hideTooltip;
    void invalidateAllGraphInfo();
    NeedToBeUpdated<map<int, set<int>>> inDegreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> outDegreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> degreeToNodes;
    NeedToBeUpdated<map<int, set<int>>> componentToNodes;
    NeedToBeUpdated<map<int, set<int>>> methodStackSizeToNodes;
    vector<set<int>*> orderedByComponentSize;
    NeedToBeUpdated<igraph_matrix_t> distanceFromTop;
    NeedToBeUpdated<igraph_matrix_t> distanceToBottom;
    NeedToBeUpdated<igraph_matrix_t> distance;

    // 0 for remove nothing
    // 1 for remove selected node
    // 2 for remove unselected node
    int removeNodeType = 0;
    bool shouldTransitiveReduction = false;
    int lastClickedNodeId = -1;
    bool nodeClickedForTheFirstTime = true;

    enum {
        LAYOUT_STATE_2D,
        LAYOUT_STATE_3D,
        LAYOUT_STATE_2D_UNFINISHED,
        LAYOUT_STATE_3D_UNFINISHED,
    };
    int layoutState = -1;

    void toFile(ofstream& f);

    void fromFile(ifstream& f);

    static map<string, string> classKeyToFilePath;

    static void deserializeFilePath();

private:

    float alphaForUnselected = 0.3f;
    float alphaForSelected = 1.0f;
    float baseTextSize = 1;
    vector<float> textSizes;

    ReactiveMouseListener* showTextMouseListener = nullptr;
    GraphDragNodeMouseListener* dragMouseListener = nullptr;

    vector<ReactiveMouseListener*>* enabledListeners;

    DoubleClickStateMachine* doubleClickStateMachine = NULL;

};