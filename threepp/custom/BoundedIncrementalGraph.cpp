#include "igraph.h"
#include "threepp/canvas/Canvas.hpp"
#include "threepp/objects/InstancedMesh.hpp"
#include "threepp/objects/LineSegments.hpp"
#include "threepp/objects/Text.hpp"
#include "threepp/materials/MeshBasicMaterial.hpp"
#include "threepp/materials/LineBasicMaterial.hpp"
#include "threepp/materials/SpriteMaterial.hpp"
#include "threepp/geometries/CircleGeometry.hpp"
#include "threepp/geometries/TextGeometry.hpp"
#include "threepp/core/BufferGeometry.hpp"
#include "threepp/math/Vector3.hpp"
#include "threepp/math/Vector2.hpp"
#include "threepp/math/Plane.hpp"
#include "threepp/math/Color.hpp"
#include "threepp/threepp.hpp"
#include "threepp/extras/core/Font.hpp"
#include "threepp/loaders/FontLoader.hpp"
#include "../../util/ThreadPool.h"
#include "../../util/util.h"
#include "../../util/Rect.h"
#include <thread>
#include "cmath"
#include "threepp/materials/RawShaderMaterial.hpp"
#include "FlowLine.h"
#include "Nodes.h"
#include "TwoDControls.h"
#include "ThreeDControls.h"
#include "../../ReactiveMouseListener.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "SWI-cpp2.h"
#include "../../GraphAttributes.h"
#include "../../prolog/PrologConstructor.h"
#include "../../prolog/PrologWrapper.h"
#include "../../error/ErrorManager.h"
#include "../../util/ThreadPool.h"
#include <limits>
#include "../../util/timer.h"
#include "../../hotkey/DoubleClickStateMachine.h"
#include "BoundedIncrementalGraph.h"
#include <regex>
#include "../../file/FileManager.h"

const int mouse_left_button = 0;
const int mouse_right_button = 1;
const int mouse_middle_button = 2;

struct GraphShowTextMouseListener : ReactiveMouseListener {
    BoundedIncrementalGraph* scope;
    threepp::Camera* camera;
    threepp::Vector2 clickMouse{ -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity() };
    threepp::Vector2 hoverMouse{ -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity() };
    bool leftClicked = false;
    bool rightClicked = false;
    bool hasMoved;
    bool enableDrag;

    GraphShowTextMouseListener(BoundedIncrementalGraph* scope, threepp::Camera* camera) {
        this->scope = scope;
        this->camera = camera;
    }

    void onMouseDown(int button, const threepp::Vector2& pos) override {
        hasMoved = false;
    }

    void onMouseUp(int button, const threepp::Vector2& pos) override {
        auto size = scope->canvas->size();
        clickMouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        clickMouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
        leftClicked = button == mouse_left_button and not hasMoved;
        rightClicked = button == mouse_right_button and not hasMoved;
    }

    void onMouseMove(const threepp::Vector2& pos) override {
        hasMoved = true;
        auto size = scope->canvas->size();
        hoverMouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        hoverMouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
    }

    void onMouseWheel(const threepp::Vector2& delta) override {
    }

    void reactOnMouseEvent() override {
        if (leftClicked or rightClicked) {
            scope->raycaster->setFromCamera(clickMouse, *camera);
            auto clickedItem = scope->raycaster->intersectObjects({ scope });
            if (not clickedItem.empty()) {
                if (leftClicked) {
                    scope->onNodeLeftClicked(clickedItem.front().instanceId.value());
                }
                if (rightClicked) {
                    scope->onNodeRightClicked(clickedItem.front().instanceId.value());
                }
            }
            leftClicked = false;
            rightClicked = false;
        }
        scope->raycaster->setFromCamera(hoverMouse, *camera);
        auto hoveredItem = scope->raycaster->intersectObjects({ scope });
        if (not hoveredItem.empty()) {
            scope->onNodeHover(hoveredItem.front().instanceId.value());
        } else {
            scope->onExitHover();
        }
    }
};

struct GraphDragNodeMouseListener : ReactiveMouseListener {
    BoundedIncrementalGraph* scope;
    threepp::Camera* camera;
    threepp::Plane plane;
    bool dragConsumed = true;
    threepp::Vector3 intersectionWithPlane;
    threepp::Vector3 dragStart;
    threepp::Vector3 dragEnd;
    threepp::Vector3 dragDelta;
    set<int> draggingGroup;

    GraphDragNodeMouseListener(BoundedIncrementalGraph* scope, threepp::Camera* camera) {
        this->scope = scope;
        this->camera = camera;
    }

    void onMouseDown(int button, const threepp::Vector2& pos) override {
        if (not scope->layoutAnimating or button != mouse_left_button) {
            return;
        }
        auto size = scope->canvas->size();
        threepp::Vector2 downMouse{ -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity() };
        downMouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        downMouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
        scope->raycaster->setFromCamera(downMouse, *camera);
        auto clickedItem = scope->raycaster->intersectObjects({ scope });
        bool is2D = scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D or scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D_UNFINISHED;
        if (not clickedItem.empty()) {
            int draggingItemId = clickedItem.front().instanceId.value();
            scope->getGroupIfGrouped(draggingItemId, draggingGroup);
            if (is2D) {
                scope->twoDControls->enabled = false;
            } else {
                scope->threeDControls->enabled = false;
            }
            threepp::Vector3 dir;
            camera->getWorldDirection(dir);
            plane.set(dir, 0);
            threepp::Vector3 point = scope->points[draggingItemId];
            point.add(scope->position);
            float distance = -plane.distanceToPoint(point);
            plane.set(dir, distance);
        } else {
            draggingGroup.clear();
            if (is2D) {
                scope->twoDControls->enabled = true;
            } else {
                scope->threeDControls->enabled = true;
            }
        }
        scope->raycaster->ray.intersectPlane(plane, intersectionWithPlane);
        dragStart.copy(intersectionWithPlane);
    }

    void onMouseUp(int button, const threepp::Vector2& pos) override {
        draggingGroup.clear();
        bool is2D = scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D or scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D_UNFINISHED;
        if (is2D) {
            scope->twoDControls->enabled = true;
        } else {
            scope->threeDControls->enabled = true;
        }
        scope->resetLayoutBound(is2D);
    }

    void onMouseMove(const threepp::Vector2& pos) override {
        if (not draggingGroup.empty() and dragConsumed) {
            auto size = scope->canvas->size();
            threepp::Vector2 moveMouse{ -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity() };
            moveMouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
            moveMouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
            scope->raycaster->setFromCamera(moveMouse, *camera);
            scope->raycaster->ray.intersectPlane(plane, intersectionWithPlane);
            dragEnd.copy(intersectionWithPlane);
            dragDelta.subVectors(dragEnd, dragStart);
            dragStart.copy(dragEnd);
            dragConsumed = false;
        }
    }

    void reactOnMouseEvent() override {
        if (not draggingGroup.empty() and not dragConsumed) {
            scope->onDrag(draggingGroup, dragDelta.x, dragDelta.y, dragDelta.z);
            dragConsumed = true;
        }
    }
};

void BoundedIncrementalGraph::addBuffers(const vector<Tail*>& bufs) {
    bufferLock.lock();
    FOR_EACH_ITEM(bufs, lineBuffer.push_back(item););
    bufferLock.unlock();
}

void BoundedIncrementalGraph::popBuffers(int count, vector<Tail*>& ret) {
    bufferLock.lock();
    for (int i = 0;i < count;i++) {
        if (not lineBuffer.empty()) {
            ret.push_back(lineBuffer.front());
            lineBuffer.pop_front();
        }
    }
    bufferLock.unlock();
}

int BoundedIncrementalGraph::bufferSize() {
    int size = 0;
    bufferLock.lock();
    size = lineBuffer.size();
    bufferLock.unlock();
    return size;
}

PositionInRegex* NodeInfo::getExistingPositionInRegex(const string& graphName, const string& lineName, const string& regex) {
    for (auto& position : positionInRegex) {
        if (strcmp(position->graphName.data(), graphName.data()) == 0 and
            strcmp(position->lineName.data(), lineName.data()) == 0 and
            strcmp(position->regex.data(), regex.data()) == 0) {
            return position;
        }
    }
    return nullptr;
}

string NodeInfo::makeUniKey(int keyType, string& methodOfRuntime, string& runtimeKey) {
    if (keyType == GlobalInfo::KEY_TYPE_STEP) {
        return runtimeKey;
    } else {
        return runtimeKey + " <---> " + methodOfRuntime;
    }
}

void NodeInfo::makeSimpleName() {
    if (keyType == GlobalInfo::KEY_TYPE_FIELD or
        keyType == GlobalInfo::KEY_TYPE_METHOD or
        keyType == GlobalInfo::KEY_TYPE_CONSTRUCTOR or
        keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
        keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
        keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or
        keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or
        keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        CompoundTerm* simpleNameTerm = CompoundTerm::getSimpleNameTerm(Term::getStr(key), Term::getVar("S"));
        simpleName = PrologWrapper::query(simpleNameTerm)->atomOrVar;
    } else if (GlobalInfo::isOptrKeyType(keyType) or
        keyType == GlobalInfo::KEY_TYPE_CONDITION or
        keyType == GlobalInfo::KEY_TYPE_ELSE or
        keyType == GlobalInfo::KEY_TYPE_FINAL or
        keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE or
        keyType == GlobalInfo::KEY_TYPE_DEFAULT_VALUE or
        keyType == GlobalInfo::KEY_TYPE_KEY_WORD_VALUE or
        keyType == GlobalInfo::KEY_TYPE_ENUM_INSTANCE) {
        simpleName = key;
    } else if (keyType == GlobalInfo::KEY_TYPE_REFERENCE) {
        simpleName = "[reference]";
    } else if (keyType == GlobalInfo::KEY_TYPE_STEP) {
        simpleName = "[step]";
    } else if (keyType == GlobalInfo::KEY_TYPE_ERROR) {
        simpleName = "[error]";
    } else if (keyType == GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS) {
        simpleName = "[anonymous]";
    } else {
        simpleName = key;
    }
}

string& NodeInfo::getSimpleName() {
    if (simpleName.empty()) {
        makeSimpleName();
    }
    return simpleName;
}

void BoundedIncrementalGraph::removeExistingNodeRecord(int index) {
    auto& nodeInfo = nodesOrderedByNodeId[index];
    uniKeyToNodeInfo.erase(nodeInfo->uniKey);
    methodOfRuntimeToNodeInfo[nodeInfo->methodOfRuntime].erase(nodeInfo);
    if (methodOfRuntimeToNodeInfo[nodeInfo->methodOfRuntime].empty()) {
        methodOfRuntimeToNodeInfo.erase(nodeInfo->methodOfRuntime);
    }
    addressableKeyToNodeInfo.erase(nodeInfo->key);
    if (addressableKeyToNodeInfo[nodeInfo->key].empty()) {
        addressableKeyToNodeInfo.erase(nodeInfo->key);
    }
    for (auto& position : nodeInfo->positionInRegex) {
        graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName][position->regex].erase(nodeInfo);
        if (graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName][position->regex].empty()) {
            graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName].erase(position->regex);
        }
        if (graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName].empty()) {
            graphNameToLineNameToRegexToNodeInfo[position->graphName].erase(position->lineName);
        }
        if (graphNameToLineNameToRegexToNodeInfo[position->graphName].empty()) {
            graphNameToLineNameToRegexToNodeInfo.erase(position->graphName);
        }
        delete position;
    }
    delete nodeInfo;
}

NodeInfo* BoundedIncrementalGraph::getExistingNodeInfo(string& uniKey) {
    if (uniKeyToNodeInfo.count(uniKey)) {
        return uniKeyToNodeInfo[uniKey];
    }
    return nullptr;
}

void BoundedIncrementalGraph::saveNodeInfo(NodeInfo* nodeInfo) {
    uniKeyToNodeInfo[nodeInfo->uniKey] = nodeInfo;
    if (not methodOfRuntimeToNodeInfo.count(nodeInfo->methodOfRuntime)) {
        methodOfRuntimeToNodeInfo[nodeInfo->methodOfRuntime] = set<NodeInfo*>();
    }
    methodOfRuntimeToNodeInfo[nodeInfo->methodOfRuntime].insert(nodeInfo);
    if (not addressableKeyToNodeInfo.count(nodeInfo->key)) {
        addressableKeyToNodeInfo[nodeInfo->key] = set<NodeInfo*>();
    }
    addressableKeyToNodeInfo[nodeInfo->key].insert(nodeInfo);
    for (auto& position : nodeInfo->positionInRegex) {
        if (not graphNameToLineNameToRegexToNodeInfo.count(position->graphName)) {
            graphNameToLineNameToRegexToNodeInfo[position->graphName] = map<string, map<string, set<NodeInfo*>>>();
        }
        if (not graphNameToLineNameToRegexToNodeInfo[position->graphName].count(position->lineName)) {
            graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName] = map<string, set<NodeInfo*>>();
        }
        if (not graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName].count(position->regex)) {
            graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName][position->regex] = set<NodeInfo*>();
        }
        graphNameToLineNameToRegexToNodeInfo[position->graphName][position->lineName][position->regex].insert(nodeInfo);
    }
}

NodeInfo* BoundedIncrementalGraph::convertTailToNodeInfo(Tail* tail) {
    string& methodOfRuntime = tail->headElements[2]->atomOrVar;
    string& runtimeKey = tail->headElements[3]->atomOrVar;
    int keyType = tail->headElements[5]->integer;
    string uniKey = NodeInfo::makeUniKey(keyType, methodOfRuntime, runtimeKey);
    NodeInfo* nodeInfo = getExistingNodeInfo(uniKey);
    string& lineInstanceName = tail->headElements[0]->atomOrVar;
    string& regexChar = tail->headElements[1]->atomOrVar;
    if (not nodeInfo) {
        nodeInfo = new NodeInfo();
        nodeInfo->positionInRegex.push_back(new PositionInRegex(searchingGraphName, lineInstanceName, regexChar));
        nodeInfo->methodOfRuntime = methodOfRuntime;
        nodeInfo->runtimeKey = runtimeKey;
        nodeInfo->key = tail->headElements[4]->atomOrVar;
        nodeInfo->keyType = keyType;
        nodeInfo->uniKey = uniKey;
    } else {
        if (not nodeInfo->getExistingPositionInRegex(searchingGraphName, lineInstanceName, regexChar)) {
            nodeInfo->positionInRegex.push_back(new PositionInRegex(searchingGraphName, lineInstanceName, regexChar));
        }
    }
    saveNodeInfo(nodeInfo);
    return nodeInfo;
}

void BoundedIncrementalGraph::updateGraph() {
    if (bufferSize() == 0) {
        return;
    }
    // load from buffer
    int bufferCountToLoad = bufferSize();
    if (bufferCountToLoad == 0) {
        return;
    }
    vector<Tail*> bufLines;
    popBuffers(bufferCountToLoad, bufLines);
    int newNodeCount = 0;
    int existingNodeCount = nodesOrderedByNodeId.size();
    // the node count is limited
    if (existingNodeCount > 10000) {
        return;
    }
    map<int, set<int>> newEdges;
    int existingEdgeCount = edgePairs.size();
    for (auto& bufLine : bufLines) {
        vector<Tail*> buf;
        FOR_EACH_ITEM(bufLine->headElements, buf.push_back(dynamic_cast<Tail*>(item)););
        // convert loaded buffer to node info
        vector<NodeInfo*> nodes;
        FOR_EACH_ITEM(buf, nodes.push_back(convertTailToNodeInfo(item)););
        // give new node a node id, and collect all edges
        vector<pair<int, int>> edges;
        NodeInfo* lastNode = NULL;
        for (auto& nodeInfo : nodes) {
            // new node
            if (nodeInfo->nodeId < 0) {
                newNodeCount++;
                nodeInfo->nodeId = nodesOrderedByNodeId.size();
                nodesOrderedByNodeId.push_back(nodeInfo);
            }
            // all edge
            if (lastNode) {
                if (lastNode->nodeId >= existingNodeCount or nodeInfo->nodeId >= existingNodeCount) {
                    if (not newEdges.count(lastNode->nodeId)) {
                        newEdges[lastNode->nodeId] = set<int>();
                    }
                    if (not newEdges[lastNode->nodeId].count(nodeInfo->nodeId)) {
                        newEdges[lastNode->nodeId].insert(nodeInfo->nodeId);
                        edgePairs.push_back({ lastNode->nodeId,nodeInfo->nodeId });
                    }
                } else {
                    edges.push_back({ lastNode->nodeId,nodeInfo->nodeId });
                }
            }
            lastNode = nodeInfo;
        }
        // decide new edge
        igraph_bool_t conn;
        for (auto& edge : edges) {
            igraph_are_connected(theOriginalGraph, edge.first, edge.second, &conn);
            // new edge
            if (not conn) {
                if (not newEdges.count(edge.first)) {
                    newEdges[edge.first] = set<int>();
                }
                if (not newEdges[edge.first].count(edge.second)) {
                    newEdges[edge.first].insert(edge.second);
                    edgePairs.push_back({ edge.first,edge.second });
                }
            }
        }
    }
    if (newNodeCount > 0) {
        // update node of graph
        igraph_add_vertices(theOriginalGraph, newNodeCount, NULL);
        for (int i = 0;i < newNodeCount;i++) {
            points.push_back(threepp::Vector3(0, 0, 0));
            textMesh.push_back(NULL);
        }
    }
    int newEdgeCount = (edgePairs.size() - existingEdgeCount) * 2;
    if (newEdges.size() > 0) {
        // update edge of graph
        igraph_integer_t edgesArray[newEdgeCount];
        int i = 0;
        for (auto& edge : newEdges) {
            for (auto& endPointI : edge.second) {
                edgesArray[i * 2] = edge.first;
                edgesArray[i * 2 + 1] = endPointI;
                i++;
            }
        }
        igraph_vector_int_t newEdges_;
        igraph_vector_int_view(&newEdges_, edgesArray, newEdgeCount);
        igraph_add_edges(theOriginalGraph, &newEdges_, NULL);

        igraph_vector_t* oldWeights = weights;
        weights = new igraph_vector_t();
        igraph_vector_init(weights, igraph_ecount(theOriginalGraph));
        igraph_vector_fill(weights, 1);
        for (int i = 0;i < igraph_vector_size(oldWeights);i++) {
            VECTOR(*weights)[i] = VECTOR(*oldWeights)[i];
        }
        igraph_vector_destroy(oldWeights);
    }
}

void BoundedIncrementalGraph::reCreateLayout(int nodeCount, bool is2D, bool dimensionChanged, igraph_vector_int_t* mapFromNewToOldNodeId) {
    spdlog::get(ErrorManager::DebugTag)->info("node count {}", nodeCount);
    igraph_matrix_t* newLayout = new igraph_matrix_t;
    igraph_matrix_init(newLayout, nodeCount, is2D ? 2 : 3);
    igraph_matrix_fill(newLayout, 0.0);
    int i, j;
    int col = dimensionChanged ? 2 : layoutMatrix->ncol;
    int row = mapFromNewToOldNodeId ? newLayout->nrow : layoutMatrix->nrow;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (mapFromNewToOldNodeId) {
                MATRIX(*newLayout, i, j) = MATRIX(*layoutMatrix, VECTOR(*mapFromNewToOldNodeId)[i], j);
            } else {
                MATRIX(*newLayout, i, j) = MATRIX(*layoutMatrix, i, j);
            }
        }
    }
    igraph_matrix_destroy(layoutMatrix);
    delete layoutMatrix;
    layoutMatrix = newLayout;

    int countToDestroy = is2D ^ dimensionChanged ? 4 : 6;
    for (int i = 0; i < countToDestroy; i++) {
        igraph_vector_destroy(layoutBounds[i]);
    }
    int countToCreate = is2D ? 4 : 6;
    for (int i = 0; i < countToCreate; i++) {
        layoutBounds[i] = new igraph_vector_t();
        igraph_vector_init(layoutBounds[i], nodeCount);
    }
    resetLayoutBound(is2D);
}

void BoundedIncrementalGraph::updateAnim(threepp::Camera& camera) {
    if (nodesOrderedByNodeId.empty() and bufferSize() == 0) {
        return;
    }
    if (layoutAnimating and layoutThreadPool->empty()) {
        layoutThreadPool->submit([this]()->void {
            bool dimensionChanged = layoutState == LAYOUT_STATE_2D_UNFINISHED or layoutState == LAYOUT_STATE_3D_UNFINISHED;
            bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
            graphGenerateAndConsumeLock.lock();
            // prepare theOriginalGraph
            updateGraph();
            // prepare layout
            if (nodesOrderedByNodeId.size() != layoutMatrix->nrow or dimensionChanged) {
                // recreate layout matrix
                reCreateLayout(nodesOrderedByNodeId.size(), is2D, dimensionChanged);
                invalidateAllGraphInfo();
            }
            if (removeNodeType) {
                removeSelectedNodesImpl();
                removeNodeType = 0;
            }
            for (auto& group : groups) {
                for (int i : group) {
                    MATRIX(*layoutMatrix, i, 0) = points[i].x;
                    MATRIX(*layoutMatrix, i, 1) = points[i].y;
                    if (not is2D) {
                        MATRIX(*layoutMatrix, i, 2) = points[i].z;
                    }
                }
            }
            // return sentence must not appear before unlock
            if (nodesOrderedByNodeId.empty()) {
                nodesObj->setPointPositions({});
                linesObj->setEdges({}, {});
                graphGenerateAndConsumeLock.unlock();
                return;
            }
            graphGenerateAndConsumeLock.unlock();
            // time consumeing layout algorithm
            if (is2D) {
                igraph_layout_fruchterman_reingold(theOriginalGraph, layoutMatrix, true, 1, temperature, IGRAPH_LAYOUT_NOGRID, weights, layoutBounds[0], layoutBounds[1], layoutBounds[2], layoutBounds[3]);
            } else {
                igraph_layout_fruchterman_reingold_3d(theOriginalGraph, layoutMatrix, true, 1, temperature, weights, layoutBounds[0], layoutBounds[1], layoutBounds[2], layoutBounds[3], layoutBounds[4], layoutBounds[5]);
            }
            if (dimensionChanged) {
                if (is2D) {
                    layoutState = LAYOUT_STATE_2D;
                } else {
                    layoutState = LAYOUT_STATE_3D;
                }
            }
            });
    }
    if (layoutAnimating) {
        graphGenerateAndConsumeLock.lock();
        if (layoutState == LAYOUT_STATE_2D) {
            for (igraph_integer_t node_id_iter = 0; node_id_iter < nodesOrderedByNodeId.size(); node_id_iter++) {
                if (not dragMouseListener->draggingGroup.count(node_id_iter)) {
                    points[node_id_iter].set(MATRIX(*layoutMatrix, node_id_iter, 0), MATRIX(*layoutMatrix, node_id_iter, 1), 0);
                }
            }
        }
        if (layoutState == LAYOUT_STATE_3D) {
            for (igraph_integer_t node_id_iter = 0; node_id_iter < nodesOrderedByNodeId.size(); node_id_iter++) {
                if (not dragMouseListener->draggingGroup.count(node_id_iter)) {
                    points[node_id_iter].set(MATRIX(*layoutMatrix, node_id_iter, 0), MATRIX(*layoutMatrix, node_id_iter, 1), MATRIX(*layoutMatrix, node_id_iter, 2));
                }
            }
        }
        alterPosByGroup();
        bool nodeCountChanged = nodesObj->setPointPositions(points);
        if (nodeCountChanged) {
            onNodeColorChanged();
        }
        linesObj->setEdges(points, edgePairs);
        graphGenerateAndConsumeLock.unlock();
    }
    threepp::Vector3 worldDir;
    camera.getWorldDirection(worldDir);
    nodesObj->setCameraDir(worldDir);
    nodesObj->matrixNeedUpdate();
    linesObj->setCameraDir(worldDir);
    linesObj->updateFlow([&](int endNode) {
        startFlowFrom(endNode);
        });
    graphGenerateAndConsumeLock.lock();
    refreshSimpleText();
    graphGenerateAndConsumeLock.unlock();
}

void BoundedIncrementalGraph::alterPosByGroup() {
    for (auto& group : groups) {
        if (group.empty()) {
            continue;
        }
        threepp::Vector3 middlePos = { 0,0,0 };
        for (int i : group) {
            middlePos.add(points[i]);
        }
        middlePos.divideScalar(group.size());
        for (int i : group) {
            threepp::Vector3 dir;
            dir.subVectors(middlePos, points[i]).divideScalar(2);
            if (not dragMouseListener->draggingGroup.count(i)) {
                points[i].add(dir);
            }
        }
    }
}

void BoundedIncrementalGraph::set2DLayout(bool use2DLayout) {
    if (use2DLayout) {
        if (layoutState == LAYOUT_STATE_3D) {
            layoutState = LAYOUT_STATE_2D_UNFINISHED;
        }
    } else {
        if (layoutState == LAYOUT_STATE_2D) {
            layoutState = LAYOUT_STATE_3D_UNFINISHED;
        }
    }
}

void BoundedIncrementalGraph::increaseTemperature() {
    temperature *= 1.5f;
}

void BoundedIncrementalGraph::decreaseTemperature() {
    temperature /= 1.5f;
}

void BoundedIncrementalGraph::startOrStopLayoutAnimating() {
    layoutAnimating = not layoutAnimating;
}

std::shared_ptr<BoundedIncrementalGraph> BoundedIncrementalGraph::create(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
    TwoDControls* twoDControls,
    threepp::ThreeDControls* threeDControls) {
    return std::shared_ptr<BoundedIncrementalGraph>(new BoundedIncrementalGraph(canvas, camera, raycaster, enabledListeners, twoDControls, threeDControls));
}

BoundedIncrementalGraph::BoundedIncrementalGraph(threepp::Canvas* canvas, threepp::Camera* camera, threepp::Raycaster* raycaster, vector<ReactiveMouseListener*>* enabledListeners,
    TwoDControls* twoDControls,
    threepp::ThreeDControls* threeDControls) {
    this->canvas = canvas;
    this->raycaster = raycaster;
    this->showTextMouseListener = new GraphShowTextMouseListener(this, camera);
    this->dragMouseListener = new GraphDragNodeMouseListener(this, camera);
    this->enabledListeners = enabledListeners;
    this->twoDControls = twoDControls;
    this->threeDControls = threeDControls;
    this->doubleClickStateMachine = new DoubleClickStateMachine(500);
    threepp::FontLoader loader;
    this->font = loader.load(FileManager::fontFilePath).value();
    igraph_matrix_init(&(distanceFromTop.data), 0, 0);
    igraph_matrix_init(&(distanceToBottom.data), 0, 0);
    igraph_matrix_init(&(distance.data), 0, 0);
    enabledListeners->push_back(this->showTextMouseListener);
    enabledListeners->push_back(this->dragMouseListener);
    layoutState = LAYOUT_STATE_2D;
    layoutThreadPool = new ThreadPool(1);
    textLoaderThreadPool = new ThreadPool(1);
    linesObj = FlowLine::create(0.1);
    linesObj->updateAlphaUnselected(alphaForUnselected);
    linesObj->updateAlphaSelected(alphaForSelected);
    add(linesObj);
    nodesObj = Nodes::create(10000, 0.5f);
    nodesObj->updateAlphaUnselected(alphaForUnselected);
    nodesObj->updateAlphaSelected(alphaForSelected);
    add(nodesObj);
    theOriginalGraph = new igraph_t;
    igraph_empty(theOriginalGraph, 0, IGRAPH_DIRECTED);
    layoutMatrix = new igraph_matrix_t;
    igraph_matrix_init(layoutMatrix, 0, 2);
    for (int i = 0; i < 4;i++) {
        layoutBounds[i] = new igraph_vector_t();
        igraph_vector_init(layoutBounds[i], 0);
    }
    weights = new igraph_vector_t();
    igraph_vector_init(weights, 0);
}

int BoundedIncrementalGraph::getNodeCount() {
    return igraph_vcount(theOriginalGraph);
}

int BoundedIncrementalGraph::getEdgeCount() {
    return igraph_ecount(theOriginalGraph);
}

float BoundedIncrementalGraph::getNodeSize() {
    return nodesObj->getNodeSize();
}

float BoundedIncrementalGraph::getEdgeWidth() {
    return linesObj->getLineWidth();
}

float BoundedIncrementalGraph::getAlphaForUnselected() {
    return alphaForUnselected;
}

float BoundedIncrementalGraph::getAlphaForSelected() {
    return alphaForSelected;
}

float BoundedIncrementalGraph::getLayoutTemperature() {
    return temperature;
}

void BoundedIncrementalGraph::increaseDecreaseAlphaForUnselected(bool increase) {
    if (increase) {
        if (alphaForUnselected < 0.95f) {
            alphaForUnselected += 0.1;
        }
    } else {
        if (alphaForUnselected > 0.05) {
            alphaForUnselected -= 0.1;
        }
    }
    linesObj->updateAlphaUnselected(alphaForUnselected);
    nodesObj->updateAlphaUnselected(alphaForUnselected);
}

void BoundedIncrementalGraph::increaseDecreaseAlphaForSelected(bool increase) {
    if (increase) {
        if (alphaForSelected < 0.95f) {
            alphaForSelected += 0.1;
        }
    } else {
        if (alphaForSelected > 0.05f) {
            alphaForSelected -= 0.1;
        }
    }
    linesObj->updateAlphaSelected(alphaForSelected);
    nodesObj->updateAlphaSelected(alphaForSelected);
}

void BoundedIncrementalGraph::startFlowFrom(int nodeInstanceId) {
    igraph_vector_int_t neighbors;
    igraph_vector_int_init(&neighbors, 0);
    igraph_neighbors(theOriginalGraph, &neighbors, nodeInstanceId, IGRAPH_OUT);
    for (int parentIndex = 0; parentIndex < igraph_vector_int_size(&neighbors); ++parentIndex) {
        igraph_integer_t neighbor = VECTOR(neighbors)[parentIndex];
        if (nodesObj->selected.count(neighbor)) {
            linesObj->startFlowingEdge(nodeInstanceId, neighbor);
        }
    }
}

void BoundedIncrementalGraph::onNodeRightClicked(int nodeInstanceId) {
    startFlowFrom(nodeInstanceId);
}

void BoundedIncrementalGraph::onNodeLeftClicked(int nodeInstanceId) {
    if (nodesObj->selected.count(nodeInstanceId)) {
        nodesObj->selected.erase(nodeInstanceId);
    } else {
        nodesObj->selected.insert(nodeInstanceId);
    }
    if (lastClickedNodeId == nodeInstanceId) {
        nodeClickedForTheFirstTime = false;
    } else {
        nodeClickedForTheFirstTime = true;
    }
    lastClickedNodeId = nodeInstanceId;
    doubleClickStateMachine->onClick([&, nodeInstanceId]() {
        if (not nodeClickedForTheFirstTime) {
            nodesObj->selected.insert(nodeInstanceId);
            onFocusOn(points[nodeInstanceId]);
        }
        });
    onNodeColorChanged();
}

void BoundedIncrementalGraph::onNodeHover(int nodeInstanceId) {
    if (nodeInstanceId < nodesOrderedByNodeId.size() and not nodesObj->hovered.count(nodeInstanceId)) {
        nodesObj->hovered.clear();
        nodesObj->hovered.insert(nodeInstanceId);
        onNodeColorChanged();
        auto& nodeInfo = nodesOrderedByNodeId[nodeInstanceId];
        string info;
        info += "simpleName:  " + nodeInfo->getSimpleName() + "\n";
        info += "key:  " + nodeInfo->key + "\n";
        info += "runtime:  " + nodeInfo->methodOfRuntime + "\n";
        info += "regex: "  "\n";
        for (auto& pos : nodeInfo->positionInRegex) {
            info += "        ";
            info += pos->graphName + " | ";
            info += pos->lineName + " | ";
            info += pos->regex + "\n";
        }
        showTooltip(info);
    }
}

void BoundedIncrementalGraph::onExitHover() {
    if (not nodesObj->hovered.empty()) {
        nodesObj->hovered.clear();
        onNodeColorChanged();
        hideTooltip();
    }
}

void BoundedIncrementalGraph::resetLayoutBound(bool is2D) {
    if (points.empty()) {
        return;
    }
    int countToFill = is2D ? 4 : 6;
    for (int i = 0; i < countToFill; i++) {
        float bound = i % 2 == 0 ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();
        igraph_vector_fill(layoutBounds[i], bound);
    }
    for (int i : nodesObj->positionFixed) {
        auto& pos = points[i];
        VECTOR(*layoutBounds[0])[i] = pos.x;
        VECTOR(*layoutBounds[1])[i] = pos.x;
        VECTOR(*layoutBounds[2])[i] = pos.y;
        VECTOR(*layoutBounds[3])[i] = pos.y;
        if (not is2D) {
            VECTOR(*layoutBounds[4])[i] = pos.z;
            VECTOR(*layoutBounds[5])[i] = pos.z;
        }
    }
}

void BoundedIncrementalGraph::onDrag(set<int>& ids, float deltaX, float deltaY, float deltaZ) {
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    for (int id : ids) {
        points[id].x += deltaX;
        points[id].y += deltaY;
        VECTOR(*layoutBounds[0])[id] = points[id].x;
        VECTOR(*layoutBounds[1])[id] = points[id].x;
        VECTOR(*layoutBounds[2])[id] = points[id].y;
        VECTOR(*layoutBounds[3])[id] = points[id].y;
        if (not is2D) {
            points[id].z += deltaZ;
            VECTOR(*layoutBounds[4])[id] = points[id].z;
            VECTOR(*layoutBounds[5])[id] = points[id].z;
        }
    }
}

void BoundedIncrementalGraph::getGroupIfGrouped(int id, set<int>& ids) {
    ids.clear();
    ids.insert(id);
    for (auto& group : groups) {
        if (group.count(id)) {
            FOR_EACH_ITEM(group, ids.insert(item););
        }
    }
}

void BoundedIncrementalGraph::onNodeColorChanged() {
    nodesObj->applyColor();
    vector<threepp::Color> colors;
    nodesObj->getColors(colors);
    linesObj->setColors(colors, edgePairs);
}

void BoundedIncrementalGraph::selectByKeyType(int keyType) {
    for (auto& nodeInfo : nodesOrderedByNodeId) {
        if (nodeInfo->keyType == keyType) {
            nodesObj->selected.insert(nodeInfo->nodeId);
        }
    }
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectAll() {
    for (int i = 0;i < points.size();i++) {
        nodesObj->selected.insert(i);
    }
    onNodeColorChanged();
}

void BoundedIncrementalGraph::unselectAll() {
    nodesObj->selected.clear();
    // stop loading
    textLoading.clear();
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectUpward() {
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        igraph_vector_int_t inedges;
        igraph_vector_int_init(&inedges, 0);
        igraph_incident(theOriginalGraph, &inedges, i, IGRAPH_IN);
        igraph_integer_t n = igraph_vector_int_size(&inedges);
        for (igraph_integer_t i = 0; i < n; i++) {
            igraph_integer_t edge = VECTOR(inedges)[i];
            igraph_integer_t from = IGRAPH_FROM(theOriginalGraph, edge);
            newNodes.insert(from);
        }
        igraph_vector_int_destroy(&inedges);
    }
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectDownward() {
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        igraph_vector_int_t outedges;
        igraph_vector_int_init(&outedges, 0);
        igraph_incident(theOriginalGraph, &outedges, i, IGRAPH_OUT);
        igraph_integer_t n = igraph_vector_int_size(&outedges);
        for (igraph_integer_t i = 0; i < n; i++) {
            igraph_integer_t edge = VECTOR(outedges)[i];
            igraph_integer_t to = IGRAPH_TO(theOriginalGraph, edge);
            newNodes.insert(to);
        }
        igraph_vector_int_destroy(&outedges);
    }
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::reverseSelect() {
    set<int> newNodes;
    for (int i = 0;i < points.size();i++) {
        if (not nodesObj->selected.count(i)) {
            newNodes.insert(i);
        }
    }
    nodesObj->selected.clear();
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectPathInBetween() {
    prepareDistance();
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        set<int> otherNodes;
        otherNodes.insert(nodesObj->selected.begin(), nodesObj->selected.end());
        otherNodes.erase(i);
        lookUpForCommonAncestor(i, otherNodes, newNodes);
        lookDownForCommonChild(i, otherNodes, newNodes);
        lookEachOtherForPath(i, otherNodes, newNodes);
    }
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::lookUpForCommonAncestor(int i, int j, set<int>& visited, set<int>& path, set<int>& selected) {
    visited.insert(i);
    path.insert(i);

    if (std::isinf(MATRIX(distance.data, i, j))) {
        // no path in between, continue to search upward
        igraph_vector_int_t neighbors;
        igraph_vector_int_init(&neighbors, 0);
        igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_IN);
        for (int parentIndex = 0; parentIndex < igraph_vector_int_size(&neighbors); ++parentIndex) {
            igraph_integer_t neighbor = VECTOR(neighbors)[parentIndex];
            if (visited.find(neighbor) == visited.end()) {
                lookUpForCommonAncestor(neighbor, j, visited, path, selected);
            }
        }
        igraph_vector_int_destroy(&neighbors);
    } else if (i != j) {
        // there is a path in between, stop searching and add path to selected
        // when i==j, it is not a CommonAncestor result
        selected.insert(path.begin(), path.end());
        set<int> eachOtherVisited;
        lookEachOtherForPath(i, j, eachOtherVisited, selected);
    }

    path.erase(i);
}

void BoundedIncrementalGraph::lookUpForCommonAncestor(int i, set<int>& otherNodes, set<int>& selected) {
    for (int j : otherNodes) {
        set<int> visited;
        set<int> path;
        lookUpForCommonAncestor(i, j, visited, path, selected);
    }
}

void BoundedIncrementalGraph::lookDownForCommonChild(int i, int j, set<int>& visited, set<int>& path, set<int>& selected) {
    visited.insert(i);
    path.insert(i);

    if (std::isinf(MATRIX(distance.data, j, i))) {
        // no path in between, continue to search downward
        igraph_vector_int_t neighbors;
        igraph_vector_int_init(&neighbors, 0);
        igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_OUT);
        for (int childIndex = 0; childIndex < igraph_vector_int_size(&neighbors); ++childIndex) {
            igraph_integer_t neighbor = VECTOR(neighbors)[childIndex];
            if (visited.find(neighbor) == visited.end()) {
                lookDownForCommonChild(neighbor, j, visited, path, selected);
            }
        }
        igraph_vector_int_destroy(&neighbors);
    } else if (i != j) {
        // there is a path in between, stop searching and add path to selected
        // when i==j, it is not a CommonChild result
        selected.insert(path.begin(), path.end());
        set<int> eachOtherVisited;
        lookEachOtherForPath(j, i, eachOtherVisited, selected);
    }

    path.erase(i);
}

void BoundedIncrementalGraph::lookDownForCommonChild(int i, set<int>& otherNodes, set<int>& selected) {
    for (int j : otherNodes) {
        set<int> visited;
        set<int> path;
        lookDownForCommonChild(i, j, visited, path, selected);
    }
}

void BoundedIncrementalGraph::lookEachOtherForPath(int i, int j, set<int>& visited, set<int>& selected) {
    visited.insert(i);

    if (not std::isinf(MATRIX(distance.data, i, j)) and i != j) {
        selected.insert(i);
        igraph_vector_int_t neighbors;
        igraph_vector_int_init(&neighbors, 0);
        igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_OUT);
        for (int childIndex = 0; childIndex < igraph_vector_int_size(&neighbors); ++childIndex) {
            igraph_integer_t neighbor = VECTOR(neighbors)[childIndex];
            if (visited.find(neighbor) == visited.end()) {
                lookEachOtherForPath(neighbor, j, visited, selected);
            }
        }
    }

}

void BoundedIncrementalGraph::lookEachOtherForPath(int i, set<int>& otherNodes, set<int>& selected) {
    for (int j : otherNodes) {
        set<int> visited;
        lookEachOtherForPath(i, j, visited, selected);
    }
}

void BoundedIncrementalGraph::select(set<int>& s) {
    nodesObj->selected.insert(s.begin(), s.end());
    onNodeColorChanged();
}
void BoundedIncrementalGraph::select(set<const char*>& uniKeys) {
    for (auto& uniKey : uniKeys) {
        nodesObj->selected.insert(uniKeyToNodeInfo[uniKey]->nodeId);
    }
    onNodeColorChanged();
}

void BoundedIncrementalGraph::prepareInDegreeMap() {
    if (not inDegreeToNodes.needUpdate) {
        return;
    }
    inDegreeToNodes.needUpdate = false;

    inDegreeToNodes.data.clear();
    igraph_vector_int_t degree;
    igraph_vector_int_init(&degree, points.size());
    igraph_degree(theOriginalGraph, &degree, igraph_vss_all(), IGRAPH_IN, IGRAPH_NO_LOOPS);
    for (int i = 0;i < points.size();i++) {
        int degreeI = VECTOR(degree)[i];
        if (not inDegreeToNodes.data.count(degreeI)) {
            inDegreeToNodes.data[degreeI] = set<int>();
        }
        inDegreeToNodes.data[degreeI].insert(i);
    }
}

void BoundedIncrementalGraph::prepareOutDegreeMap() {
    if (not outDegreeToNodes.needUpdate) {
        return;
    }
    outDegreeToNodes.needUpdate = false;

    outDegreeToNodes.data.clear();
    igraph_vector_int_t degree;
    igraph_vector_int_init(&degree, points.size());
    igraph_degree(theOriginalGraph, &degree, igraph_vss_all(), IGRAPH_OUT, IGRAPH_NO_LOOPS);
    for (int i = 0;i < points.size();i++) {
        int degreeI = VECTOR(degree)[i];
        if (not outDegreeToNodes.data.count(degreeI)) {
            outDegreeToNodes.data[degreeI] = set<int>();
        }
        outDegreeToNodes.data[degreeI].insert(i);
    }
}

void BoundedIncrementalGraph::prepareDegreeMap() {
    if (not degreeToNodes.needUpdate) {
        return;
    }
    degreeToNodes.needUpdate = false;

    degreeToNodes.data.clear();
    igraph_vector_int_t degree;
    igraph_vector_int_init(&degree, points.size());
    igraph_degree(theOriginalGraph, &degree, igraph_vss_all(), IGRAPH_ALL, IGRAPH_NO_LOOPS);
    for (int i = 0;i < points.size();i++) {
        int degreeI = VECTOR(degree)[i];
        if (not degreeToNodes.data.count(degreeI)) {
            degreeToNodes.data[degreeI] = set<int>();
        }
        degreeToNodes.data[degreeI].insert(i);
    }
}

void BoundedIncrementalGraph::prepareComponent() {
    if (not componentToNodes.needUpdate) {
        return;
    }
    componentToNodes.needUpdate = false;

    componentToNodes.data.clear();
    igraph_vector_int_t membership;
    igraph_vector_int_init(&membership, points.size());
    igraph_connected_components(theOriginalGraph, &membership, NULL, NULL, IGRAPH_WEAK);

    for (int i = 0; i < points.size(); i++) {
        int componentId = VECTOR(membership)[i];
        if (not componentToNodes.data.count(componentId)) {
            componentToNodes.data[componentId] = set<int>();
        }
        componentToNodes.data[componentId].insert(i);
    }
    igraph_vector_int_destroy(&membership);
    orderedByComponentSize.clear();
    for (auto& componentAndNodes : componentToNodes.data) {
        int count = componentAndNodes.second.size();
        if (orderedByComponentSize.empty()) {
            orderedByComponentSize.push_back(&(componentAndNodes.second));
        } else {
            auto iter = orderedByComponentSize.begin();
            while (iter != orderedByComponentSize.end()) {
                if ((**iter).size() < count) {
                    break;
                }
                iter++;
            }
            orderedByComponentSize.insert(iter, &(componentAndNodes.second));
        }
    }
}

void BoundedIncrementalGraph::prepareGroup() {
    list<int> toBeRemoved;
    for (int i = 0;i < groups.size();i++) {
        if (groups[i].size() < 2) {
            toBeRemoved.push_front(i);
        }
    }
    for (int i : toBeRemoved) {
        groups.erase(groups.begin() + i);
    }
}

void BoundedIncrementalGraph::flowColor() {
    prepareInDegreeMap();
    prepareOutDegreeMap();
    threepp::Color startColor = threepp::Color(1, 1, 0);
    threepp::Color endColor = threepp::Color(1, 0, 1);
    threepp::Color color;
    for (int i = 0;i < points.size();i++) {
        float ratio = getNodeRelativePosition(i);
        color.lerpColors(startColor, endColor, ratio);
        nodesObj->setSpecifiedColorAt(i, color, false);
    }
    onNodeColorChanged();
}

float BoundedIncrementalGraph::getNodeRelativePosition(int nodeId) {
    prepareDistanceFromTop();
    prepareDistanceToBottom();
    float distanceFromTop = maxDistanceFromTop(nodeId);
    float distanceToBottom = maxDistanceToBottom(nodeId);
    float length = distanceFromTop + distanceToBottom;
    if (length == 0.f) {
        return 0.f;
    } else {
        return distanceFromTop / (distanceFromTop + distanceToBottom);
    }
}

float BoundedIncrementalGraph::maxDistanceFromTop(int nodeId) {
    igraph_vector_t col;
    igraph_vector_init(&col, 0);
    igraph_matrix_get_col(&(distanceFromTop.data), &col, nodeId);
    for (int i = 0; i < igraph_vector_size(&col);i++) {
        float j = VECTOR(col)[i];
        if (std::isinf(j)) {
            VECTOR(col)[i] = -1;
        }
    }
    float maxDistance = igraph_vector_max(&col);
    igraph_vector_destroy(&col);
    return maxDistance;
}

float BoundedIncrementalGraph::maxDistanceToBottom(int nodeId) {
    igraph_vector_t row;
    igraph_vector_init(&row, 0);
    igraph_matrix_get_row(&(distanceToBottom.data), &row, nodeId);
    for (int i = 0; i < igraph_vector_size(&row);i++) {
        float j = VECTOR(row)[i];
        if (std::isinf(j)) {
            VECTOR(row)[i] = -1;
        }
    }
    float maxDistance = igraph_vector_max(&row);
    igraph_vector_destroy(&row);
    return maxDistance;
}

bool BoundedIncrementalGraph::isNodeGrouped(int nodeId) {
    for (auto& group : groups) {
        if (group.size() > 1 and group.count(nodeId)) {
            return true;
        }
    }
    return false;
}

void BoundedIncrementalGraph::prepareDistanceFromTop() {
    if (not distanceFromTop.needUpdate) {
        return;
    }
    distanceFromTop.needUpdate = false;
    if (inDegreeToNodes.data.count(0)) {
        set<int>& topNodes = inDegreeToNodes.data[0];
        igraph_vs_t from;
        igraph_vector_int_t from_;
        igraph_vector_int_init(&from_, topNodes.size());
        int c = 0;
        for (int t : topNodes) {
            VECTOR(from_)[c] = t;
            c++;
        }
        igraph_vs_vector(&from, &from_);
        igraph_distances(theOriginalGraph, &(distanceFromTop.data), from, igraph_vss_all(), IGRAPH_OUT);
        igraph_vector_int_destroy(&from_);
        igraph_vs_destroy(&from);
    } else {
        spdlog::get(ErrorManager::DebugTag)->warn("the whole graph is a circle! no distance from top!");
    }
}

void BoundedIncrementalGraph::prepareDistanceToBottom() {
    if (not distanceToBottom.needUpdate) {
        return;
    }
    distanceToBottom.needUpdate = false;
    if (outDegreeToNodes.data.count(0)) {
        set<int>& bottomNode = outDegreeToNodes.data[0];
        igraph_vs_t to;
        igraph_vector_int_t to_;
        igraph_vector_int_init(&to_, bottomNode.size());
        int c = 0;
        for (int t : bottomNode) {
            VECTOR(to_)[c] = t;
            c++;
        }
        igraph_vs_vector(&to, &to_);
        igraph_distances(theOriginalGraph, &(distanceToBottom.data), igraph_vss_all(), to, IGRAPH_OUT);
        igraph_vector_int_destroy(&to_);
        igraph_vs_destroy(&to);
    } else {
        spdlog::get(ErrorManager::DebugTag)->warn("the whole graph is a circle! no distance from bottom!");
    }
}

void BoundedIncrementalGraph::prepareDistance() {
    if (not distance.needUpdate) {
        return;
    }
    distance.needUpdate = false;
    igraph_distances(theOriginalGraph, &(distance.data), igraph_vss_all(), igraph_vss_all(), IGRAPH_OUT);
}

void BoundedIncrementalGraph::clearSpecifiedColor() {
    set<int> tobeCleard;
    for (auto i : nodesObj->colorSpecified) {
        if (not nodesObj->selected.count(i)) {
            tobeCleard.insert(i);
        }
    }
    FOR_EACH_ITEM(tobeCleard, nodesObj->colorSpecified.erase(item););
    onNodeColorChanged();
}

void BoundedIncrementalGraph::removeSelectedNodes() {
    removeNodeType = 1;
    layoutAnimating = true;
}

void BoundedIncrementalGraph::removeAllNodes() {
    removeNodeType = 2;
    layoutAnimating = true;
}

void BoundedIncrementalGraph::removeSelectedNodesImpl() {
    // stop loading text
    textLoading.clear();
    bool removeSelected = removeNodeType == 1;
    set<int> tobeRemoved;
    for (int i = 0;i < points.size();i++) {
        bool selected = nodesObj->selected.count(i);
        if (not (removeSelected ^ selected)) {
            tobeRemoved.insert(i);
        }
    }
    if (tobeRemoved.empty()) {
        return;
    }
    igraph_vs_t vertices;
    igraph_vector_int_t vertices_;
    igraph_vector_int_init(&vertices_, tobeRemoved.size());
    // when node count is over 4000, delete all nodes will crash this app
    // malloc_consolidate(): unaligned fastbin chunk detected
    // I can not solve this problem, so I'm not allowing delete all nodes
    if (tobeRemoved.size() == points.size()) {
        tobeRemoved.erase(1);
    }
    int c = 0;
    for (int i : tobeRemoved) {
        VECTOR(vertices_)[c] = i;
        c++;
    }
    igraph_vs_vector(&vertices, &vertices_);
    igraph_vector_int_t mapFromOldToNewNodeId;
    igraph_vector_int_init(&mapFromOldToNewNodeId, 0);
    igraph_vector_int_t mapFromNewToOldNodeId;
    igraph_vector_int_init(&mapFromNewToOldNodeId, 0);
    igraph_delete_vertices_idx(theOriginalGraph, vertices, &mapFromOldToNewNodeId, &mapFromNewToOldNodeId);

    // less node
    for (int i : tobeRemoved) {
        points.pop_back();
    }
    // remove existing node record
    for (int i : tobeRemoved) {
        removeExistingNodeRecord(i);
    }
    // remove added text
    for (int i : textAdded) {
        if (tobeRemoved.count(i)) {
            remove(*textMesh[i]);
        }
    }
    mapNodeIdFromOldToNew(textLoaded, &mapFromOldToNewNodeId);
    // update node id in node info
    // remove node info
    mapNodeInfoForDeletion(&mapFromNewToOldNodeId);
    mapGroupForDeletion(&mapFromNewToOldNodeId);

    // save old node to edge
    map<int, map<int, int>> oldPointIDToOldEdge;
    for (int i = 0;i < edgePairs.size();i++) {
        int startPoint = edgePairs[i].first;
        int endPoint = edgePairs[i].second;
        if (not oldPointIDToOldEdge.count(startPoint)) {
            oldPointIDToOldEdge[startPoint] = map<int, int>();
        }
        oldPointIDToOldEdge[startPoint][endPoint] = i;
    }

    // get edge list
    edgePairs.clear();
    igraph_vector_int_t result_edges;
    igraph_vector_int_init(&result_edges, 0);
    igraph_get_edgelist(theOriginalGraph, &result_edges, 0);
    for (int i = 0; i < igraph_vector_int_size(&result_edges); i += 2) {
        igraph_integer_t source = VECTOR(result_edges)[i];
        igraph_integer_t target = VECTOR(result_edges)[i + 1];
        edgePairs.push_back({ source,target });
    }

    // recreate weights and save part of weights
    igraph_vector_t* oldWeights = weights;
    weights = new igraph_vector_t();
    igraph_vector_init(weights, igraph_ecount(theOriginalGraph));
    igraph_vector_fill(weights, 1);
    for (int newEdgeId = 0;newEdgeId < igraph_ecount(theOriginalGraph);newEdgeId++) {
        int newEdgeFrom = edgePairs[newEdgeId].first;
        int newEdgeTo = edgePairs[newEdgeId].second;
        int oldEdgeFrom = VECTOR(mapFromNewToOldNodeId)[newEdgeFrom];
        int oldEdgeTo = VECTOR(mapFromNewToOldNodeId)[newEdgeTo];
        int oldEdgeId = oldPointIDToOldEdge[oldEdgeFrom][oldEdgeTo];
        VECTOR(*weights)[newEdgeId] = VECTOR(*oldWeights)[oldEdgeId];
    }
    igraph_vector_destroy(oldWeights);

    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    reCreateLayout(nodesOrderedByNodeId.size(), is2D, false, &mapFromNewToOldNodeId);
    invalidateAllGraphInfo();
    nodesObj->mapNodeColorForDeletion(&mapFromNewToOldNodeId);
    // selected and textAdded must be clear at the same time
    mapNodeIdFromOldToNew(textAdded, &mapFromOldToNewNodeId);
    mapNodeIdFromOldToNew(nodesObj->selected, &mapFromOldToNewNodeId);
    onNodeColorChanged();
    resetLayoutBound(is2D);

    linesObj->stopFlowing();

    igraph_vector_int_destroy(&vertices_);
    igraph_vs_destroy(&vertices);
    igraph_vector_int_destroy(&mapFromOldToNewNodeId);
    igraph_vector_int_destroy(&mapFromNewToOldNodeId);
    igraph_vector_int_destroy(&result_edges);
}

void BoundedIncrementalGraph::mapNodeInfoForDeletion(igraph_vector_int_t* mapFromNewToOldNodeId) {
    vector<NodeInfo*> nodesOrderedByNodeId_left;
    vector<std::shared_ptr<threepp::Mesh>> textMesh_left;
    for (int newIndex = 0; newIndex < igraph_vector_int_size(mapFromNewToOldNodeId); newIndex++) {
        int oldIndex = VECTOR(*mapFromNewToOldNodeId)[newIndex];
        auto& nodeInfo = nodesOrderedByNodeId[oldIndex];
        nodeInfo->nodeId = newIndex;
        nodesOrderedByNodeId_left.push_back(nodeInfo);
        textMesh_left.push_back(textMesh[oldIndex]);
    }
    nodesOrderedByNodeId = nodesOrderedByNodeId_left;
    textMesh = textMesh_left;
}

void BoundedIncrementalGraph::mapGroupForDeletion(igraph_vector_int_t* mapFromNewToOldNodeId) {
    vector<set<int>> groups_left;
    for (auto& group : groups) {
        set<int> group_left;
        for (int newIndex = 0; newIndex < igraph_vector_int_size(mapFromNewToOldNodeId); ++newIndex) {
            int oldIndex = VECTOR(*mapFromNewToOldNodeId)[newIndex];
            if (group.count(oldIndex)) {
                group_left.insert(newIndex);
            }
        }
        if (group_left.size() > 1) {
            groups_left.push_back(group_left);
        }
    }
    groups = groups_left;
}

void BoundedIncrementalGraph::mapNodeIdFromOldToNew(set<int>& oldIds, igraph_vector_int_t* mapFromOldToNewNodeId) {
    set<int> newIds;
    for (auto i : oldIds) {
        if (VECTOR(*mapFromOldToNewNodeId)[i]) {
            newIds.insert(VECTOR(*mapFromOldToNewNodeId)[i] - 1);
        }
    }
    oldIds.clear();
    oldIds.insert(newIds.begin(), newIds.end());
}

void BoundedIncrementalGraph::searchNodeInGraph(char* searchStr, vector<const char*>& searchResult) {
    searchResult.clear();
    if (searchStr[0] == 0) {
        return;
    }
    try {
        std::regex reg(searchStr, std::regex_constants::icase);
        for (auto& nodeInfo : nodesOrderedByNodeId) {
            if (std::regex_search(nodeInfo->key, reg)) {
                searchResult.push_back(nodeInfo->uniKey.data());
            }
        }
    } catch (std::regex_error e) {
        spdlog::get(ErrorManager::DebugTag)->error("wrong regex: {}!", searchStr);
    }
}

void BoundedIncrementalGraph::searchNodeByMethodOfRuntime(set<const char*>& methodOfRuntime, vector<const char*>& searchResult) {
    searchResult.clear();
    for (auto& m : methodOfRuntime) {
        for (auto& nodeInfo : methodOfRuntimeToNodeInfo[m]) {
            searchResult.push_back(nodeInfo->uniKey.data());
        }
    }
}

void BoundedIncrementalGraph::searchNodeByAddressableKey(set<const char*>& addressableKey, vector<const char*>& searchResult) {
    searchResult.clear();
    for (auto& a : addressableKey) {
        for (auto& nodeInfo : addressableKeyToNodeInfo[a]) {
            searchResult.push_back(nodeInfo->uniKey.data());
        }
    }
}

void BoundedIncrementalGraph::searchNodeByPositionInRegex(map<string, map<string, set<string>>>& positionInRegex, vector<const char*>& searchResult) {
    searchResult.clear();
    for (auto& graphName : positionInRegex) {
        for (auto& lineName : graphName.second) {
            for (auto& regex : lineName.second) {
                for (auto& nodeInfo : graphNameToLineNameToRegexToNodeInfo[graphName.first][lineName.first][regex]) {
                    searchResult.push_back(nodeInfo->uniKey.data());
                }
            }
        }
    }
}

bool BoundedIncrementalGraph::isDag() {
    igraph_bool_t res;
    igraph_is_dag(theOriginalGraph, &res);
    return res;
}

void BoundedIncrementalGraph::toggleShowSimpleText() {
    showSimpleText = !showSimpleText;
}

float BoundedIncrementalGraph::diameter() {
    igraph_real_t diameter;
    igraph_diameter(
        theOriginalGraph, &diameter,
        /* from = */ NULL, /* to = */ NULL,
        /* vertex_path = */ NULL, /* edge_path = */ NULL,
        IGRAPH_UNDIRECTED, /* unconn= */ true
    );
    return diameter;
}

void BoundedIncrementalGraph::refreshSimpleText() {
    if (showSimpleText) {
        // remove unselected text
        set<int> removed;
        for (int i : textAdded) {
            if (not nodesObj->selected.count(i)) {
                remove(*textMesh[i]);
                removed.insert(i);
            }
        }
        for (int i : removed) {
            textAdded.erase(i);
        }
        // add selected text or load selected text
        for (int i : nodesObj->selected) {
            if (textAdded.count(i)) {
                if (layoutAnimating) {
                    updateTextPosAt(i);
                }
            } else {
                if (textLoaded.count(i)) {
                    if (textMesh[i].get()) {
                        add(textMesh[i]);
                        textAdded.insert(i);
                        updateTextPosAt(i);
                    } else {
                        textLoaded.erase(i);
                    }
                } else {
                    if (not textLoading.count(i)) {
                        textLoading[i] = { i, nodesOrderedByNodeId[i]->getSimpleName() };
                    }
                    if (not textLoading.empty() and textLoaderThreadPool->empty()) {
                        layoutThreadPool->clearTaskList();
                        textLoaderThreadPool->submit([this]() {
                            if (not textLoading.empty()) {
                                TextLoadingItem& item = textLoading.begin()->second;
                                std::shared_ptr<threepp::SpriteMaterial> textMaterial = threepp::SpriteMaterial::create();
                                textMaterial->color = { 0.6f,0.6f,0.6f };
                                textMesh[item.nodeId] = threepp::Text2D::create(threepp::TextGeometry::Options(font, 0.4), item.text, textMaterial);
                                textMesh[item.nodeId]->geometry()->center();
                                textMesh[item.nodeId]->geometry()->scale(textSize, textSize, textSize);
                                this->textLoaded.insert(item.nodeId);
                                this->textLoading.erase(item.nodeId);
                            }
                            });
                    }
                }
            }
        }
    } else {
        for (int i : textAdded) {
            remove(*textMesh[i]);
        }
        textAdded.clear();
    }
}

void BoundedIncrementalGraph::updateTextPosAt(int i) {
    if (textAdded.count(i)) {
        auto& pos = points[i];
        textMesh[i]->position.x = pos.x;
        textMesh[i]->position.y = pos.y;
        textMesh[i]->position.z = pos.z;
    }
}

void BoundedIncrementalGraph::dispose() {
    layoutAnimating = false;
    nodesObj->dispose();
    layoutThreadPool->clearTaskList();
    textLoaderThreadPool->clearTaskList();
}

void BoundedIncrementalGraph::raycast(const threepp::Raycaster& raycaster, std::vector<threepp::Intersection>& intersects) {
    nodesObj->raycast(raycaster, intersects);
}

void BoundedIncrementalGraph::invalidateAllGraphInfo() {
    inDegreeToNodes.needUpdate = true;
    outDegreeToNodes.needUpdate = true;
    degreeToNodes.needUpdate = true;
    componentToNodes.needUpdate = true;
    distanceFromTop.needUpdate = true;
    distanceToBottom.needUpdate = true;
    distance.needUpdate = true;
}

void BoundedIncrementalGraph::changeTextSize(bool increase) {
    float s = 0;
    if (increase) {
        s = 1.1f;
    } else {
        s = 1 / 1.1f;
    }
    textSize *= s;
    for (int i : textAdded) {
        textMesh[i]->geometry()->scale(s, s, s);
    }
}

void BoundedIncrementalGraph::increaseNodeSize() {
    nodesObj->increaseNodeSize();
}

void BoundedIncrementalGraph::decreaseNodeSize() {
    nodesObj->decreaseNodeSize();
}

void BoundedIncrementalGraph::increaseLineWidth() {
    linesObj->increaseLineWidth();
}

void BoundedIncrementalGraph::decreaseLineWidth() {
    linesObj->decreaseLineWidth();
}

PositionInRegex::PositionInRegex(const string& graphName, const string& lineName, const string& regex) {
    this->graphName = graphName;
    this->lineName = lineName;
    this->regex = regex;
}

void BoundedIncrementalGraph::fixPosition() {
    for (int i : nodesObj->selected) {
        if (not isNodeGrouped(i)) {
            nodesObj->positionFixed.insert(i);
        }
    }
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
}

void BoundedIncrementalGraph::releasePosition() {
    for (int i : nodesObj->selected) {
        nodesObj->positionFixed.erase(i);
    }
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
    layoutAnimating = true;
}

void BoundedIncrementalGraph::releaseAllPosition() {
    set<int> tobeReleased;
    for (auto& i : nodesObj->positionFixed) {
        if (not nodesObj->selected.count(i)) {
            tobeReleased.insert(i);
        }
    }
    FOR_EACH_ITEM(tobeReleased, nodesObj->positionFixed.erase(item););
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
    layoutAnimating = true;
}

void BoundedIncrementalGraph::setColorForSeletedNode(float r, float g, float b) {
    for (int i : nodesObj->selected) {
        nodesObj->colorSpecified.insert(i);
        nodesObj->setSpecifiedColorAt(i, { r,g,b }, true);
    }
    onNodeColorChanged();
}

list<pair<string, string>> BoundedIncrementalGraph::getSelectedKey() {
    auto ret = list<pair<string, string>>();
    for (int nodeId : nodesObj->selected) {
        auto& nodeInfo = nodesOrderedByNodeId[nodeId];
        int keyType = nodeInfo->keyType;
        if (keyType == GlobalInfo::KEY_TYPE_FIELD or
            keyType == GlobalInfo::KEY_TYPE_METHOD or
            keyType == GlobalInfo::KEY_TYPE_CONSTRUCTOR or
            keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
            keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
            keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or
            keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or
            keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
            string type;
            CompoundTerm* findTypeTerm = NULL;
            switch (keyType) {
            case GlobalInfo::KEY_TYPE_FIELD:
                findTypeTerm = CompoundTerm::getFieldTerm(Term::getVar("T"), Term::getStr(nodeInfo->key));
                type = PrologWrapper::query(findTypeTerm)->atomOrVar;
                ret.push_back({ nodeInfo->key, type });
                break;
            case GlobalInfo::KEY_TYPE_METHOD:
                findTypeTerm = CompoundTerm::getMethodTerm(Term::getVar("T"), Term::getStr(nodeInfo->key));
                type = PrologWrapper::query(findTypeTerm)->atomOrVar;
                ret.push_back({ nodeInfo->key, type });
                break;
            case GlobalInfo::KEY_TYPE_CONSTRUCTOR:
                findTypeTerm = CompoundTerm::getConstructorTerm(Term::getVar("T"), Term::getStr(nodeInfo->key));
                type = PrologWrapper::query(findTypeTerm)->atomOrVar;
                ret.push_back({ nodeInfo->key, type });
                break;
            case GlobalInfo::KEY_TYPE_METHOD_PARAMETER:
            case GlobalInfo::KEY_TYPE_METHOD_RETURN:
            case GlobalInfo::KEY_TYPE_CALLED_METHOD:
            case GlobalInfo::KEY_TYPE_CALLED_PARAMETER:
            case GlobalInfo::KEY_TYPE_CALLED_RETURN:
                int pos = nodeInfo->key.rfind(':');
                string mk = nodeInfo->key.substr(0, pos + 1);
                findTypeTerm = CompoundTerm::getMethodTerm(Term::getVar("T"), Term::getStr(mk));
                auto result = PrologWrapper::query(findTypeTerm);
                if (result) {
                    type = result->atomOrVar;
                    ret.push_back({ nodeInfo->key, type });
                } else {
                    findTypeTerm = CompoundTerm::getConstructorTerm(Term::getVar("T"), Term::getStr(mk));
                    type = PrologWrapper::query(findTypeTerm)->atomOrVar;
                    ret.push_back({ nodeInfo->key, type });
                }
                break;
            }
        }
    }
    return ret;
}

list<tuple<string, string, string, int>> BoundedIncrementalGraph::getSelectedRuntime() {
    auto ret = list<tuple<string, string, string, int>>();
    for (int i : nodesObj->selected) {
        auto& nodeInfo = nodesOrderedByNodeId[i];
        ret.push_back({ nodeInfo->methodOfRuntime,nodeInfo->runtimeKey,nodeInfo->key,nodeInfo->keyType });
    }
    return ret;
}

void BoundedIncrementalGraph::changeWeightForSelectedNode(bool increase) {
    int edgeCount = igraph_ecount(theOriginalGraph);
    for (int edgeId = 0;edgeId < edgeCount;edgeId++) {
        int from = IGRAPH_FROM(theOriginalGraph, edgeId);
        int to = IGRAPH_TO(theOriginalGraph, edgeId);
        if (nodesObj->selected.count(from) and nodesObj->selected.count(to)) {
            VECTOR(*weights)[edgeId] *= increase ? 1.1f : (1 / 1.1f);
        }
    }
    layoutAnimating = true;
}

void BoundedIncrementalGraph::resetWeight() {
    int edgeCount = igraph_ecount(theOriginalGraph);
    for (int edgeId = 0;edgeId < edgeCount;edgeId++) {
        int from = IGRAPH_FROM(theOriginalGraph, edgeId);
        int to = IGRAPH_TO(theOriginalGraph, edgeId);
        if (not nodesObj->selected.count(from) or not nodesObj->selected.count(to)) {
            VECTOR(*weights)[edgeId] = 1;
        }
    }
    layoutAnimating = true;
}

void BoundedIncrementalGraph::groupSelectedNodes() {
    if (nodesObj->selected.size() < 2) {
        return;
    }
    set<int>* reusedGroup = NULL;
    for (auto& group : groups) {
        for (int i : nodesObj->selected) {
            group.erase(i);
        }
        if (group.empty()) {
            reusedGroup = &group;
        }
    }
    if (not reusedGroup) {
        set<int> newGroup;
        groups.push_back(newGroup);
        reusedGroup = &(groups.back());
    }
    reusedGroup->insert(nodesObj->selected.begin(), nodesObj->selected.end());
    layoutAnimating = true;
}

void BoundedIncrementalGraph::ungroupSelectedNodes() {
    for (auto& group : groups) {
        for (int i : nodesObj->selected) {
            group.erase(i);
        }
        if (group.size() == 1) {
            group.clear();
        }
    }
    layoutAnimating = true;
}

void BoundedIncrementalGraph::ungroupAllNodes() {
    for (auto& group : groups) {
        set<int> tobeUngrouped;
        for (auto i : group) {
            if (not nodesObj->selected.count(i)) {
                tobeUngrouped.insert(i);
            }
        }
        FOR_EACH_ITEM(tobeUngrouped, group.erase(item););
    }
    layoutAnimating = true;
}
