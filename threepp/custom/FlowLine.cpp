
#include "../../util/util.h"
#include "threepp/math/MathUtils.hpp"
#include "threepp/materials/RawShaderMaterial.hpp"
#include "threepp/core/BufferGeometry.hpp"
#include "threepp/objects/Mesh.hpp"
#include "../../error/ErrorManager.h"
#include "FlowLine.h"

void FlowLine::createGeometry() {
    spdlog::get(ErrorManager::DebugTag)->warn("create edge geo for edge capacity : {}", edgeCapacity);
    geometry_ = threepp::BufferGeometry::create();

    geometry_->setAttribute("position", threepp::FloatBufferAttribute::create(std::vector<float>(edgeCapacity * 12), 3));
    geometry_->getAttribute<float>("position")->setUsage(threepp::DrawUsage::Dynamic);

    geometry_->setAttribute("color", threepp::FloatBufferAttribute::create(std::vector<float>(edgeCapacity * 12), 3));
    geometry_->getAttribute<float>("color")->setUsage(threepp::DrawUsage::Dynamic);

    geometry_->setAttribute("dir", threepp::FloatBufferAttribute::create(std::vector<float>(edgeCapacity * 12), 3));
    geometry_->getAttribute<float>("dir")->setUsage(threepp::DrawUsage::Dynamic);

    geometry_->setAttribute("uv", threepp::FloatBufferAttribute::create(std::vector<float>(edgeCapacity * 8), 2));
    geometry_->getAttribute<float>("uv")->setUsage(threepp::DrawUsage::Static);

    geometry_->setAttribute("flow", threepp::FloatBufferAttribute::create(std::vector<float>(edgeCapacity * 4), 1));
    geometry_->getAttribute<float>("flow")->setUsage(threepp::DrawUsage::Static);

    auto uvAttr = geometry_->getAttribute<float>("uv");
    for (int i = 0;i < edgeCapacity;i++) {
        int startingIndex = i * 4;
        uvAttr->setXY(startingIndex + 0, -1, -1);
        uvAttr->setXY(startingIndex + 1, -1, 1);
        uvAttr->setXY(startingIndex + 2, 1, 1);
        uvAttr->setXY(startingIndex + 3, 1, -1);
    }
    auto flowAttr = geometry_->getAttribute<float>("flow");
    for (int i = 0;i < edgeCapacity;i++) {
        int startingIndex = i * 4;
        flowAttr->setX(startingIndex + 0, -2);
        flowAttr->setX(startingIndex + 1, -2);
        flowAttr->setX(startingIndex + 2, -2);
        flowAttr->setX(startingIndex + 3, -2);
    }

    std::vector<int> indices;
    indices.reserve(edgeCapacity * 6);
    for (int i = 0;i < edgeCapacity;i++) {
        int startingIndex = i * 4;
        indices.push_back(startingIndex + 0);
        indices.push_back(startingIndex + 1);
        indices.push_back(startingIndex + 2);
        indices.push_back(startingIndex + 2);
        indices.push_back(startingIndex + 3);
        indices.push_back(startingIndex + 0);
    }
    geometry_->setIndex(indices);
}

FlowLine::FlowLine(float initLineWidth) : threepp::Mesh(nullptr, nullptr) {
    lineWidth = initLineWidth;
    createGeometry();
    shaderMaterial = threepp::RawShaderMaterial::create();
    shaderMaterial->uniforms["alphaUnselected"] = threepp::Uniform();
    shaderMaterial->uniforms["alphaSelected"] = threepp::Uniform();
    shaderMaterial->uniforms["lineHalfWidth"] = threepp::Uniform();
    shaderMaterial->uniforms["cameraDir"] = threepp::Uniform();
    updateLineWidth(lineWidth);
    setCameraDir({ 0,0,1 });
    shaderMaterial->vertexShader = vertexSource();
    shaderMaterial->fragmentShader = fragmentSource();
    shaderMaterial->side = threepp::Side::Double;
    shaderMaterial->transparent = true;
    shaderMaterial->alphaTest = true;
    shaderMaterial->depthTest = false;
    materials_ = { shaderMaterial };
}

void FlowLine::setEdges(const vector<threepp::Vector3>& points, const vector<pair<int, int>>& edges) {
    pointToEdge.clear();
    int edgeCount = std::min(edgeCapacity, (int)edges.size());
    auto positionAttr = geometry_->getAttribute<float>("position");
    auto dirAttr = geometry_->getAttribute<float>("dir");
    threepp::Vector3 dir;
    for (int i = 0;i < edgeCount;i++) {
        int startPoint = edges[i].first;
        int endPoint = edges[i].second;
        auto& startPos = points[startPoint];
        auto& endPos = points[endPoint];
        int startingIndex = i * 4;
        positionAttr->setXYZ(startingIndex + 0, startPos.x, startPos.y, startPos.z);
        positionAttr->setXYZ(startingIndex + 1, endPos.x, endPos.y, endPos.z);
        positionAttr->setXYZ(startingIndex + 2, endPos.x, endPos.y, endPos.z);
        positionAttr->setXYZ(startingIndex + 3, startPos.x, startPos.y, startPos.z);

        dir.subVectors(endPos, startPos);
        dirAttr->setXYZ(startingIndex + 0, dir.x, dir.y, dir.z);
        dirAttr->setXYZ(startingIndex + 1, dir.x, dir.y, dir.z);
        dirAttr->setXYZ(startingIndex + 2, -dir.x, -dir.y, -dir.z);
        dirAttr->setXYZ(startingIndex + 3, -dir.x, -dir.y, -dir.z);

        if (not pointToEdge.count(startPoint)) {
            pointToEdge[startPoint] = map<int, int>();
        }
        pointToEdge[startPoint][endPoint] = i;
    }
    dirAttr->needsUpdate();
    positionAttr->needsUpdate();
    geometry_->computeBoundingBox();
    geometry_->computeBoundingSphere();
    geometry_->setDrawRange(0, edgeCount * 6);
}

void FlowLine::setColors(vector<threepp::Color>& colors, const vector<pair<int, int>>& edges) {
    auto colorAttr = geometry_->getAttribute<float>("color");
    int edgeCount = std::min(edgeCapacity, (int)edges.size());
    for (int i = 0;i < edgeCount;i++) {
        auto& startColor = colors[edges[i].first];
        auto& endColor = colors[edges[i].second];
        int startingIndex = i * 4;
        colorAttr->setXYZ(startingIndex + 0, startColor.r, startColor.g, startColor.b);
        colorAttr->setXYZ(startingIndex + 1, endColor.r, endColor.g, endColor.b);
        colorAttr->setXYZ(startingIndex + 2, endColor.r, endColor.g, endColor.b);
        colorAttr->setXYZ(startingIndex + 3, startColor.r, startColor.g, startColor.b);
    }
    colorAttr->needsUpdate();
}

void FlowLine::startFlowingEdge(int startPoint, int endPoint, bool backward) {
    if (backward) {
        startFlowingEdgeImpl(startPoint, endPoint, backwardFlowingEdges, backward);
    } else {
        startFlowingEdgeImpl(startPoint, endPoint, flowingEdges, backward);
    }
}

void FlowLine::startFlowingEdgeImpl(int startPoint, int endPoint, map<int, map<int, float>>& flowingEdges, bool backward) {
    if (not flowingEdges.count(startPoint)) {
        flowingEdges[startPoint] = map<int, float>();
    }
    if (flowingEdges[startPoint].count(endPoint)) {
        // the edge is flowing now, ignore 
        return;
    }
    flowingEdges[startPoint][endPoint] = backward ? 1 : 0;
}

void FlowLine::stopFlowing() {
    if (flowingEdges.empty() and backwardFlowingEdges.empty()) {
        return;
    }
    flowingEdges.clear();
    backwardFlowingEdges.clear();
    auto flowAttr = geometry_->getAttribute<float>("flow");
    for (int i = 0;i < edgeCapacity;i++) {
        int startingIndex = i * 4;
        flowAttr->setX(startingIndex + 0, -2);
        flowAttr->setX(startingIndex + 1, -2);
        flowAttr->setX(startingIndex + 2, -2);
        flowAttr->setX(startingIndex + 3, -2);
    }
    onFlowChanged(true);
    onFlowChanged(false);
}

void FlowLine::updateFlow(const std::function<void(int, bool)>& onAnimationFinished) {
    updateFlowImpl(onAnimationFinished, backwardFlowingEdges, true);
    updateFlowImpl(onAnimationFinished, flowingEdges, false);
}

void FlowLine::updateFlowImpl(const std::function<void(int, bool)>& onAnimationFinished, map<int, map<int, float>>& flowingEdges, bool backward) {
    if (flowingEdges.empty()) {
        return;
    }
    auto flowAttr = geometry_->getAttribute<float>("flow");
    map<int, map<int, float>> flowingEdges_copy = flowingEdges;
    for (auto& startAndEndPoint : flowingEdges_copy) {
        int startPoint = startAndEndPoint.first;
        for (auto& endPointAndFlow : startAndEndPoint.second) {
            int endPoint = endPointAndFlow.first;
            flowingEdges[startPoint][endPoint] += backward ? -0.03 : 0.03;

            if ((not backward and flowingEdges[startPoint][endPoint] > 1) or
                (backward and flowingEdges[startPoint][endPoint] < 0)) {
                // animation finished
                flowingEdges[startPoint].erase(endPoint);
                if (flowingEdges[startPoint].empty()) {
                    flowingEdges.erase(startPoint);
                }

                // trigger next animation
                onAnimationFinished(backward ? startPoint : endPoint, backward);

                // restore glsl variable value, maybe not neccessary
                int edgeIndex = pointToEdge[startPoint][endPoint];
                int startingIndex = edgeIndex * 4;
                flowAttr->setX(startingIndex + 0, -2);
                flowAttr->setX(startingIndex + 1, -2);
                flowAttr->setX(startingIndex + 2, -2);
                flowAttr->setX(startingIndex + 3, -2);
            }
        }
    }
    onFlowChanged(backward);
}

void FlowLine::onFlowChanged(bool backward) {
    if (backward) {
        onFlowChangedImpl(backwardFlowingEdges);
    } else {
        onFlowChangedImpl(flowingEdges);
    }
}

void FlowLine::onFlowChangedImpl(map<int, map<int, float>>& flowingEdges) {
    auto flowAttr = geometry_->getAttribute<float>("flow");

    for (auto& startAndEndPoint : flowingEdges) {
        int startPoint = startAndEndPoint.first;
        for (auto& endPointAndFlow : startAndEndPoint.second) {
            int endPoint = endPointAndFlow.first;
            float flow = endPointAndFlow.second;
            int edgeIndex = pointToEdge[startPoint][endPoint];
            int startingIndex = edgeIndex * 4;
            flowAttr->setX(startingIndex + 0, flow);
            flowAttr->setX(startingIndex + 1, flow - 1);
            flowAttr->setX(startingIndex + 2, flow - 1);
            flowAttr->setX(startingIndex + 3, flow);
        }
    }

    flowAttr->needsUpdate();
}

std::shared_ptr<FlowLine> FlowLine::create(float initLineWidth) {
    return std::shared_ptr<FlowLine>(new FlowLine(initLineWidth));
}

void FlowLine::toFile(ofstream& f) {
}

void FlowLine::fromFile(ifstream& f) {
}

void FlowLine::updateLineWidth(float lineWidth) {
    shaderMaterial->uniforms.at("lineHalfWidth").setValue(lineWidth);
}

void FlowLine::updateAlphaUnselected(float alpha) {
    shaderMaterial->uniforms.at("alphaUnselected").setValue(alpha);
}

void FlowLine::updateAlphaSelected(float alpha) {
    shaderMaterial->uniforms.at("alphaSelected").setValue(alpha);
}

void FlowLine::setCameraDir(const threepp::Vector3& cameraDir) {
    cameraDirVec.set(cameraDir.x, cameraDir.y, cameraDir.z);
    shaderMaterial->uniforms.at("cameraDir").setValue(cameraDirVec);
}

void FlowLine::increaseLineWidth() {
    lineWidth *= 1.1f;
    updateLineWidth(lineWidth);
}

void FlowLine::decreaseLineWidth() {
    lineWidth /= 1.1f;
    updateLineWidth(lineWidth);
}

std::string FlowLine::vertexSource() {
    return R"(
               #version 330 core
               uniform mat4 modelViewMatrix; 
               uniform mat4 projectionMatrix; 
               uniform float lineHalfWidth;
               uniform vec3 cameraDir;
               uniform float alphaUnselected;
               uniform float alphaSelected;
               in vec3 position;
               in vec3 color;
               in vec3 dir;
               in vec2 uv;
               in float flow;
               out vec2 uv_frag;
               out vec3 vColor;
               out float vAlpha;
               out float vHovered;
               out float vFlow;
               void main() {
                    uv_frag = uv;
                    vColor = color;

                    float statePartR = fract(fract(color.r) * 100);
                    bool selected = statePartR > 0.1 && statePartR < 0.3;
                    vAlpha = selected ? alphaSelected : alphaUnselected;

                    float statePartG = fract(fract(color.g) * 100);
                    vHovered = statePartG > 0.1 && statePartG < 0.3 ? 1 : 0;

                    vFlow = flow;

                    vec3 normalizedDir = normalize(cross(dir,cameraDir));
                    gl_Position = projectionMatrix * modelViewMatrix * vec4( position+normalizedDir * lineHalfWidth, 1.0 );
               })";
}

std::string FlowLine::fragmentSource() {
    return R"(
                #version 330 core
                in vec2 uv_frag;
                in vec3 vColor;
                in float vAlpha;
                in float vHovered;
                in float vFlow;
                out vec4 pc_fragColor;
                void main() {
                    vec3 color = vColor;
                    float alpha = vAlpha;
                    color += vHovered*vec3(0.2);
                    alpha += vHovered*0.2;
                    if (vFlow > -1.5) {
                        float f = 0.8*smoothstep(0.2,0,abs(vFlow));
                        color -= vec3(f);
                    }
                    pc_fragColor = vec4( color, alpha * (1-smoothstep(0.7,1,abs(uv_frag.y))) );
                })";
}
