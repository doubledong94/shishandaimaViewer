class Nodes : public threepp::InstancedMesh {
public:
    std::shared_ptr<threepp::RawShaderMaterial> shaderMaterial;
    Nodes(int capacity, float initNodeSize);

    bool setPointPositions(const vector<threepp::Vector3>& points);

    void setNodeSize();

    void setNodeSizeAt(int i, float size);

    void matrixNeedUpdate();

    void setCameraDir(const threepp::Vector3& cameraDir);

    void setCameraDirAti(int i, const threepp::Vector3& cameraDir);

    void increaseNodeSize();

    void decreaseNodeSize();

    void applyColor();

    void getColors(vector<threepp::Color>& colors);

    float encodeIntoRgb(float rgb, float info);

    void updateAlphaUnselected(float alpha);

    void updateAlphaSelected(float alpha);

    static std::shared_ptr<Nodes> create(int capacity, float initNodeSize);
    set<int> hovered;
    set<int> selected;

    void setSpecifiedColorAt(int index, const threepp::Color& color, bool overwrite);

    void mapNodeForDeletion(igraph_vector_int_t* mapForDeleteNodes);

    set<int> colorSpecified;

    set<int> positionFixed;

    set<int> styled;
    set<int> styled2;
    set<int> styled3;
    set<int> styled4;

    int nodeCount = 0;
    int nodeCapacity = 0;

    void toFile(ofstream& f);
    void fromFile(ifstream& f);
    vector<float> nodeSizes;
private:
    threepp::Matrix4 tmpMatrix;
    threepp::Matrix4 tmpMatrix2;
    float baseNodeSize = 0.0f;
    threepp::Color defaultColorForUnselected = { 0.5,0.5,0.5 };
    threepp::Color defaultColorForSelected = { 0.9,0.9,0.9 };
    vector<threepp::Color> specifiedColors;

    std::string vertexSource();

    std::string fragmentSource();
};