class Nodes : public threepp::InstancedMesh {
public:
    std::shared_ptr<threepp::RawShaderMaterial> shaderMaterial;
    Nodes(int capacity, float initNodeSize);

    bool setPointPositions(const vector<threepp::Vector3>& points);

    void setNodeSize(float size);

    void setNodeSizeAt(int i, float size);

    void matrixNeedUpdate();

    void setCameraDir(const threepp::Vector3& cameraDir);

    void setCameraDirAti(int i, const threepp::Vector3& cameraDir);

    void increaseNodeSize();

    void decreaseNodeSize();

    void applyColor();

    void getColors(vector<threepp::Color>& colors);

    float encodeIntoRgb(float rgb, float info);

    float getNodeSize();

    void updateAlphaUnselected(float alpha);

    void updateAlphaSelected(float alpha);

    static std::shared_ptr<Nodes> create(int capacity, float initNodeSize);
    set<int> hovered;
    set<int> selected;

    void setSpecifiedColorAt(int index, const threepp::Color& color, bool overwrite);

    void mapNodeColorForDeletion(igraph_vector_int_t* mapForDeleteNodes);

    set<int> colorSpecified;

    set<int> positionFixed;
private:
    threepp::Matrix4 tmpMatrix;
    threepp::Matrix4 tmpMatrix2;
    float nodeSize = 0.0f;
    threepp::Color defaultColorForUnselected = { 0.5,0.5,0.5 };
    threepp::Color defaultColorForSelected = { 0.9,0.9,0.9 };
    vector<threepp::Color> specifiedColors;

    std::string vertexSource();

    std::string fragmentSource();
};