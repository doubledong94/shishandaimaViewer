#ifndef JPARSER_FLOWLINE_H
#define JPARSER_FLOWLINE_H


class FlowLine : public threepp::Mesh {
public:
    int edgeCapacity = 10000;

    std::shared_ptr<threepp::RawShaderMaterial> shaderMaterial;

    void createGeometry();

    FlowLine(float initLineWidth);

    void setEdges(const vector<threepp::Vector3>& points, const vector<pair<int, int>>& edges);

    void setColors(vector<threepp::Color>& colors, const vector<pair<int, int>>& edges);

    void startFlowingEdge(int startPoint, int endPoint, bool backward);

    void startFlowingEdgeImpl(int startPoint, int endPoint, map<int, map<int, float>>& flowingEdges, bool backward);

    void stopFlowing();

    void updateFlow(const std::function<void(int, bool)>& onAnimationFinished);

    void updateFlowImpl(const std::function<void(int, bool)>& onAnimationFinished, map<int, map<int, float>>& flowingEdges, bool backward);

    void onFlowChanged(bool backward);
    void onFlowChangedImpl(map<int, map<int, float>>& flowingEdges);

    void updateLineWidth(float lineWidth);

    void updateAlphaUnselected(float alpha);

    void updateAlphaSelected(float alpha);

    void setCameraDir(const threepp::Vector3& cameraDir);

    void increaseLineWidth();

    void decreaseLineWidth();

    float getLineWidth();

    static std::shared_ptr<FlowLine> create(float initLineWidth);

    void toFile(ofstream& f);
    void fromFile(ifstream& f);
private:
    threepp::Matrix4 tmpMatrix;
    threepp::Vector3 cameraDirVec;
    float lineWidth = 0.0f;

    map<int, map<int, int>> pointToEdge;
    map<int, map<int, float>> flowingEdges;
    map<int, map<int, float>> backwardFlowingEdges;

    std::string vertexSource();

    std::string fragmentSource();
};


#endif //JPARSER_FLOWLINE_H
