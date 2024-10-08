#include "ikdTree/ikd_Tree.h"
#include "imgui.h"
#include "igraph.h"
#include <thread>
#include "cmath"
#include "SWI-cpp2.h"
#include <limits>
#include <regex>
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
#include "threepp/materials/RawShaderMaterial.hpp"
#include "util/ThreadPool.h"
#include "util/util.h"
#include "util/Rect.h"
#include "util/ThreadPool.h"
#include "util/timer.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "addressableInfo/GlobalInfo.h"
#include "prolog/PrologConstructor.h"
#include "prolog/PrologWrapper.h"
#include "hotkey/DoubleClickStateMachine.h"
#include "ReactiveMouseListener.h"
#include "threepp/custom/FlowLine.h"
#include "threepp/custom/Nodes.h"
#include "threepp/custom/TwoDControls.h"
#include "threepp/custom/ThreeDControls.h"
#include "threepp/custom/BoundFrame.h"
#include "threepp/custom/BoundedIncrementalGraph.h"
#include "error/ErrorManager.h"
#include "file/FileManager.h"

const int mouse_left_button = 0;
const int mouse_right_button = 1;
const int mouse_middle_button = 2;

static set<int> AllKeyTypes = {
        GlobalInfo::KEY_TYPE_CLASS,
        GlobalInfo::KEY_TYPE_FIELD,
        GlobalInfo::KEY_TYPE_CONSTRUCTOR,
        GlobalInfo::KEY_TYPE_METHOD,
        GlobalInfo::KEY_TYPE_METHOD_PARAMETER,
        GlobalInfo::KEY_TYPE_METHOD_RETURN,
        GlobalInfo::KEY_TYPE_CALLED_METHOD,
        GlobalInfo::KEY_TYPE_CALLED_PARAMETER,
        GlobalInfo::KEY_TYPE_CALLED_RETURN,
        GlobalInfo::KEY_TYPE_CONDITION,
        GlobalInfo::KEY_TYPE_ELSE,
        GlobalInfo::KEY_TYPE_REFERENCE,
        GlobalInfo::KEY_TYPE_DATA_STEP,
        GlobalInfo::KEY_TYPE_TIMING_STEP,
        GlobalInfo::KEY_TYPE_DATA_OVERRIDE,
        GlobalInfo::KEY_TYPE_TIMING_OVERRIDE,
        GlobalInfo::KEY_TYPE_INDEX,
        GlobalInfo::KEY_TYPE_LOCAL_VARIABLE,
        GlobalInfo::KEY_TYPE_FINAL,
        GlobalInfo::KEY_TYPE_DEFAULT_VALUE,
        GlobalInfo::KEY_TYPE_KEY_WORD_VALUE,
        GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS,
        GlobalInfo::KEY_TYPE_ENUM_INSTANCE,
        GlobalInfo::KEY_TYPE_ARRAY_INIT,
        GlobalInfo::KEY_TYPE_OPTR_START,
        GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_ARITHMETIC_PARAMETER2,
        GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_SELF_ASSIGN_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_UNARY_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_UNARY_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_LOGIC_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_LOGIC_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_LOGIC_PARAMETER2,
        GlobalInfo::KEY_TYPE_OPTR_RELATION_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_RELATION_PARAMETER2,
        GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER2,
        GlobalInfo::KEY_TYPE_OPTR_CONDITIONAL_PARAMETER3,
        GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_RETURN,
        GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER1,
        GlobalInfo::KEY_TYPE_OPTR_INSTANCE_OF_PARAMETER2,
        GlobalInfo::KEY_TYPE_OPTR_END,
        GlobalInfo::KEY_TYPE_ERROR,
};

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
    set<int> draggingGroupX;
    set<int> draggingGroupY;
    bool hasMoved;
    int clickedId = -1;

    GraphDragNodeMouseListener(BoundedIncrementalGraph* scope, threepp::Camera* camera) {
        this->scope = scope;
        this->camera = camera;
    }

    void onMouseDown(int button, const threepp::Vector2& pos) override {
        hasMoved = false;
        if (button != mouse_left_button) {
            return;
        }
        auto size = scope->canvas->size();
        threepp::Vector2 downMouse{ -std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity() };
        downMouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        downMouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
        scope->raycaster->setFromCamera(downMouse, *camera);
        scope->raycastByDrag = true;
        auto clickedItem = scope->raycaster->intersectObjects({ scope });
        scope->raycastByDrag = false;
        bool is2D = scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D or scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D_UNFINISHED;
        if (not clickedItem.empty()) {
            int draggingItemId = clickedItem.front().instanceId.value();
            scope->getGroupIfGrouped(draggingItemId, draggingGroup, scope->groups);
            scope->getGroupIfGrouped(draggingItemId, draggingGroupX, scope->xCoordFixed);
            scope->getGroupIfGrouped(draggingItemId, draggingGroupY, scope->yCoordFixed);
            if (is2D) {
                scope->twoDControls->enabled = false;
            } else {
                scope->threeDControls->enabled = false;
            }
            threepp::Vector3 dir;
            camera->getWorldDirection(dir);
            plane.set(dir, 0);
            threepp::Vector3 point = scope->raycastOnFrame ? scope->boundFrames[draggingItemId]->start : scope->points[draggingItemId];
            point.add(scope->position);
            float distance = -plane.distanceToPoint(point);
            plane.set(dir, distance);
        } else {
            draggingGroup.clear();
            draggingGroupX.clear();
            draggingGroupY.clear();
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
        if (button == mouse_left_button and not hasMoved and scope->raycastOnFrame) {
            clickedId = *(draggingGroup.begin());
        }
        draggingGroup.clear();
        draggingGroupX.clear();
        draggingGroupY.clear();
        bool is2D = scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D or scope->layoutState == BoundedIncrementalGraph::LAYOUT_STATE_2D_UNFINISHED;
        if (is2D) {
            scope->twoDControls->enabled = true;
        } else {
            scope->threeDControls->enabled = true;
        }
        scope->resetLayoutBound(is2D);
    }

    void onMouseMove(const threepp::Vector2& pos) override {
        hasMoved = true;
        if (not (draggingGroup.empty() and draggingGroupX.empty() and draggingGroupY.empty()) and dragConsumed) {
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
        if (clickedId > -1) {
            scope->onBoundDragIconClicked(clickedId);
            clickedId = -1;
        }
        if (draggingGroupX.size() > 1 and not dragConsumed) {
            scope->onDragX(draggingGroupX, dragDelta.x);
            dragConsumed = true;
        }
        if (draggingGroupY.size() > 1 and not dragConsumed) {
            scope->onDragY(draggingGroupY, dragDelta.y);
            dragConsumed = true;
        }
        if (not draggingGroup.empty() and not dragConsumed) {
            scope->onDrag(draggingGroup, dragDelta.x, dragDelta.y, dragDelta.z);
            dragConsumed = true;
        }
    }

    threepp::Vector3 getCurrentFocus(threepp::Vector3& distanceTo) {
        threepp::Vector3 dir;
        camera->getWorldDirection(dir);
        plane.set(dir, 0);
        float distance = -plane.distanceToPoint(distanceTo);
        plane.set(dir, distance);
        scope->raycaster->setFromCamera({ 0,0 }, *camera);
        scope->raycaster->ray.intersectPlane(plane, intersectionWithPlane);
        return intersectionWithPlane;
    }

    threepp::Vector3 convertPosToPanPos(threepp::Vector3 pos) {
        threepp::Vector3 dir;
        camera->getWorldDirection(dir);
        plane.set(dir, 0);
        float distance = -plane.distanceToPoint(pos);
        plane.set(dir, distance);
        scope->raycaster->set(pos, dir);
        scope->raycaster->ray.intersectPlane(plane, intersectionWithPlane);
        if (isnan(intersectionWithPlane.x)) {
            scope->raycaster->set(pos, dir.negate());
            scope->raycaster->ray.intersectPlane(plane, intersectionWithPlane);
        }
        return intersectionWithPlane;
    }

    threepp::Vector3 rotateAccordingToCamera(threepp::Vector3 v) {
        threepp::Matrix4 mat;
        mat.extractRotation(*camera->matrix);
        v.applyMatrix4(mat.invert());
        return v;
    }

};

void BoundedIncrementalGraph::addBuffers(const vector<Tail*>& bufs) {
    while (bufferSize() > 50) {
        // wait until buffer size is under a specific value
    }
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

void BoundedIncrementalGraph::returnDoneBufferToPool() {
    bufferLock.lock();
    for (auto& done : doneBuffer) {
        done->returnThisToPool();
    }
    doneBuffer.clear();
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
    if (keyType == GlobalInfo::KEY_TYPE_DATA_STEP or keyType == GlobalInfo::KEY_TYPE_TIMING_STEP or
        keyType == GlobalInfo::KEY_TYPE_DATA_OVERRIDE or keyType == GlobalInfo::KEY_TYPE_TIMING_OVERRIDE or
        keyType == GlobalInfo::KEY_TYPE_FIELD_CONNECTION) {
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
        keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN or
        keyType == GlobalInfo::KEY_TYPE_FIELD_CONNECTION) {
        CompoundTerm* simpleNameTerm = CompoundTerm::getSimpleNameTerm(Term::getStr(key), Term::getVar("S"));
        auto* result = PrologWrapper::query(simpleNameTerm);
        if (result) {
            simpleName = result->atomOrVar;
        }
    } else if (GlobalInfo::isOptrKeyType(keyType) or
        keyType == GlobalInfo::KEY_TYPE_CONDITION or
        keyType == GlobalInfo::KEY_TYPE_ELSE or
        keyType == GlobalInfo::KEY_TYPE_FINAL or
        keyType == GlobalInfo::KEY_TYPE_DEFAULT_VALUE or
        keyType == GlobalInfo::KEY_TYPE_KEY_WORD_VALUE or
        keyType == GlobalInfo::KEY_TYPE_ENUM_INSTANCE) {
        simpleName = key;
    } else if (keyType == GlobalInfo::KEY_TYPE_REFERENCE) {
        simpleName = "[reference]";
    } else if (keyType == GlobalInfo::KEY_TYPE_VOID_REF) {
        simpleName = "[voidRef]";
    } else if (keyType == GlobalInfo::KEY_TYPE_INDEX) {
        simpleName = "[i]";
    } else if (keyType == GlobalInfo::KEY_TYPE_DATA_STEP or keyType == GlobalInfo::KEY_TYPE_TIMING_STEP) {
        simpleName = "[step]";
    } else if (keyType == GlobalInfo::KEY_TYPE_DATA_OVERRIDE or keyType == GlobalInfo::KEY_TYPE_TIMING_OVERRIDE) {
        simpleName = "[override]";
    } else if (keyType == GlobalInfo::KEY_TYPE_ERROR) {
        simpleName = key;
    } else if (keyType == GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS) {
        simpleName = "[anonymous]";
    } else if (keyType == GlobalInfo::KEY_TYPE_LOCAL_VARIABLE) {
        int pos = key.rfind('-');
        simpleName = key.substr(pos + 1);
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

string& NodeInfo::getTypeKey() {
    if (typeKey.empty()) {
        makeTypeKey();
    }
    return typeKey;
}

string& NodeInfo::getRuntimeClass() {
    if (runtimeClass.empty()) {
        makeRuntimeClass();
    }
    return runtimeClass;
}

string& NodeInfo::getDeclaredInType() {
    if (declaredInType.empty()) {
        makeDeclaredInType();
    }
    return declaredInType;
}

void NodeInfo::makeTypeKey() {
    if (keyType == GlobalInfo::KEY_TYPE_FIELD or
        keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
        keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
        keyType == GlobalInfo::KEY_TYPE_FIELD_CONNECTION) {
        auto* instanceOfTerm = CompoundTerm::getInstanceOfTerm(Term::getStr(key), Term::getVar("T"));
        auto* result = PrologWrapper::query(instanceOfTerm);
        if (result) {
            typeKey = result->atomOrVar;
        }
    } else if (keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
        string originKey = key.substr(0, key.size() - 1);
        auto* instanceOfTerm = CompoundTerm::getInstanceOfTerm(Term::getStr(originKey), Term::getVar("T"));
        auto* result = PrologWrapper::query(instanceOfTerm);
        if (result) {
            typeKey = result->atomOrVar;
        }
    }
}

void NodeInfo::makeRuntimeClass() {
    runtimeClass = PrologWrapper::query(CompoundTerm::getMethodTerm(Term::getVar("Class"), Term::getStr(methodOfRuntime)))->atomOrVar;
}

void NodeInfo::makeDeclaredInType() {
    CompoundTerm* findTypeTerm = NULL;
    switch (keyType) {
    case GlobalInfo::KEY_TYPE_FIELD:
        findTypeTerm = CompoundTerm::getFieldTerm(Term::getVar("T"), Term::getStr(key));
        declaredInType = PrologWrapper::query(findTypeTerm)->atomOrVar;
        break;
    case GlobalInfo::KEY_TYPE_METHOD:
        findTypeTerm = CompoundTerm::getMethodTerm(Term::getVar("T"), Term::getStr(key));
        declaredInType = PrologWrapper::query(findTypeTerm)->atomOrVar;
        break;
    case GlobalInfo::KEY_TYPE_CONSTRUCTOR:
        findTypeTerm = CompoundTerm::getConstructorTerm(Term::getVar("T"), Term::getStr(key));
        declaredInType = PrologWrapper::query(findTypeTerm)->atomOrVar;
        break;
    case GlobalInfo::KEY_TYPE_METHOD_PARAMETER:
    case GlobalInfo::KEY_TYPE_METHOD_RETURN:
    case GlobalInfo::KEY_TYPE_CALLED_METHOD:
    case GlobalInfo::KEY_TYPE_CALLED_PARAMETER:
    case GlobalInfo::KEY_TYPE_CALLED_RETURN:
        int pos = key.rfind(':');
        string mk = key.substr(0, pos + 1);
        findTypeTerm = CompoundTerm::getMethodTerm(Term::getVar("T"), Term::getStr(mk));
        declaredInType = PrologWrapper::query(findTypeTerm)->atomOrVar;
        break;
    }
}

void NodeInfo::toFile(ofstream& f) {
    f << positionInRegex.size() << "\n";
    FOR_EACH_ITEM(positionInRegex, item->toFile(f););
    f << methodOfRuntime << "\n";
    f << runtimeKey << "\n";
    f << key << "\n";
    f << keyType << "\n";
    f << uniKey << "\n";
    f << nodeId << "\n";
    f << typeKey << "\n";
    f << declaredInType << "\n";
    f << simpleName << "\n";
    f << runtimeClass << "\n";
    f << methodStackSize << "\n";
    f << (isWritten ? 1 : 0) << "\n";
    f << (isOverride ? 1 : 0) << "\n";
}

void NodeInfo::fromFile(ifstream& f) {
    int c = getInt(f);
    for (int i = 0;i < c;i++) {
        PositionInRegex* p = new PositionInRegex();
        p->fromFile(f);
        positionInRegex.push_back(p);
    }
    getline(f, methodOfRuntime);
    getline(f, runtimeKey);
    getline(f, key);
    keyType = getInt(f);
    getline(f, uniKey);
    nodeId = getInt(f);
    getline(f, typeKey);
    getline(f, declaredInType);
    getline(f, simpleName);
    getline(f, runtimeClass);
    methodStackSize = getInt(f);
    isWritten = getInt(f);
    isOverride = getInt(f);
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
}

void BoundedIncrementalGraph::saveNodePosition(PositionInRegex* position, NodeInfo* nodeInfo) {
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

NodeInfo* BoundedIncrementalGraph::convertTailToNodeInfo(Tail* tail) {
    string& methodOfRuntime = tail->headElements[2]->atomOrVar;
    string& runtimeKey = tail->headElements[3]->atomOrVar;
    string& key = tail->headElements[4]->atomOrVar;
    int keyType = tail->headElements[5]->integer;
    if (keyType == GlobalInfo::KEY_TYPE_DATA_STEP or keyType == GlobalInfo::KEY_TYPE_TIMING_STEP or
        keyType == GlobalInfo::KEY_TYPE_DATA_OVERRIDE or keyType == GlobalInfo::KEY_TYPE_TIMING_OVERRIDE or
        keyType == GlobalInfo::KEY_TYPE_FIELD_CONNECTION) {
        runtimeKey = key;
    }
    string uniKey = NodeInfo::makeUniKey(keyType, methodOfRuntime, runtimeKey);
    NodeInfo* nodeInfo = getExistingNodeInfo(uniKey);
    string& lineInstanceName = tail->headElements[0]->atomOrVar;
    string& regexChar = tail->headElements[1]->atomOrVar;
    if (not nodeInfo) {
        nodeInfo = new NodeInfo();
        nodeInfo->positionInRegex.push_back(new PositionInRegex(searchingGraphName, lineInstanceName, regexChar));
        nodeInfo->methodOfRuntime = methodOfRuntime;
        nodeInfo->runtimeKey = runtimeKey;
        nodeInfo->key = key;
        nodeInfo->keyType = keyType;
        nodeInfo->uniKey = uniKey;
        nodeInfo->methodStackSize = tail->headElements[6]->integer;
        nodeInfo->isWritten = PrologWrapper::queryCount(CompoundTerm::getCountTerm(
            CompoundTerm::getIsWriteTerm(Term::getStr(methodOfRuntime), Term::getStr(runtimeKey)), Term::getVar("C")));
        if (keyType == GlobalInfo::KEY_TYPE_METHOD or
            keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
            keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN) {
            nodeInfo->isOverride = PrologWrapper::queryCount(CompoundTerm::getCountTerm(CompoundTerm::getOverrideOutRecurTerm(Term::getIgnoredVar(), Term::getStr(key)), Term::getVar("C")));
        }
        if (
            keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or
            keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or
            keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN) {
            nodeInfo->isOverride = PrologWrapper::queryCount(CompoundTerm::getCountTerm(CompoundTerm::getOverrideInRecurTerm(Term::getStr(key.substr(0, key.size() - 1)), Term::getIgnoredVar()), Term::getVar("C")));
        }
        saveNodeInfo(nodeInfo);
        saveNodePosition(nodeInfo->positionInRegex.back(), nodeInfo);
    } else {
        if (not nodeInfo->getExistingPositionInRegex(searchingGraphName, lineInstanceName, regexChar)) {
            nodeInfo->positionInRegex.push_back(new PositionInRegex(searchingGraphName, lineInstanceName, regexChar));
            saveNodePosition(nodeInfo->positionInRegex.back(), nodeInfo);
        }
    }
    return nodeInfo;
}

void BoundedIncrementalGraph::updateGraph() {
    if (bufferSize() == 0) {
        graphIncreasing = false;
        return;
    }
    graphIncreasing = true;
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
        for (auto& b : buf) {
            NodeInfo* node = convertTailToNodeInfo(b);
            if (node) {
                nodes.push_back(node);
            }
        }
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
            if (lastNode and (lastNode->nodeId != nodeInfo->nodeId)) {
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
    bufferLock.lock();
    for (auto& done : bufLines) {
        doneBuffer.push_back(done);
    }
    bufferLock.unlock();
    if (newNodeCount > 0) {
        // update node of graph
        igraph_add_vertices(theOriginalGraph, newNodeCount, NULL);
        for (int i = 0;i < newNodeCount;i++) {
            points.push_back(srcPos);
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
    if (newLayout->nrow > layoutMatrix->nrow) {
        for (int i = layoutMatrix->nrow;i < newLayout->nrow;i++) {
            MATRIX(*newLayout, i, 0) = srcPos.x;
            MATRIX(*newLayout, i, 1) = srcPos.y;
            if (not is2D) {
                MATRIX(*newLayout, i, 2) = srcPos.z;
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
        igraph_vector_init(layoutBounds[i], nodeCount);
    }
    if (mapFromNewToOldNodeId) {
        applyLayoutPosition();
        resetBounds();
    }
    resetLayoutBound(is2D);
    resetStyledNodes();
}

void BoundedIncrementalGraph::reCreateLayoutWithNoOldLayoutInfo(int nodeCount, bool is2D, bool dimensionChanged) {
    spdlog::get(ErrorManager::DebugTag)->info("node count {}", nodeCount);
    igraph_matrix_destroy(layoutMatrix);
    igraph_matrix_init(layoutMatrix, nodeCount, is2D ? 2 : 3);
    igraph_matrix_fill(layoutMatrix, 0.0);

    int countToDestroy = is2D ^ dimensionChanged ? 4 : 6;
    for (int i = 0; i < countToDestroy; i++) {
        igraph_vector_destroy(layoutBounds[i]);
    }
    int countToCreate = is2D ? 4 : 6;
    for (int i = 0; i < countToCreate; i++) {
        igraph_vector_init(layoutBounds[i], nodeCount);
    }
    resetLayoutBound(is2D);
    resetStyledNodes();
}

void BoundedIncrementalGraph::applyLayout(bool force) {
    graphGenerateAndConsumeLock.lock();
    applyLayoutPosition();
    bool groupAnimating = false;
    groupAnimating |= updatePosByGroup(groups, 0);
    groupAnimating |= updatePosByGroup(xCoordFixed, 1);
    groupAnimating |= updatePosByGroup(yCoordFixed, 2);
    if (groupAnimating or force) {
        resetLayoutBound(is2DLayout());
    }
    bool nodeCountChanged = nodesObj->setPointPositions(points);
    if (nodeCountChanged) {
        onNodeColorChanged();
    }
    linesObj->setEdges(points, edgePairs);
    scaleByDistance(force);
    graphGenerateAndConsumeLock.unlock();
}

void BoundedIncrementalGraph::applyLayoutTreeUpAndDown(bool up) {
    if (up) {
        prepareOutDegreeMap();
        if (not outDegreeToNodes.data.count(0)) {
            return;
        }
    } else {
        prepareInDegreeMap();
        if (not inDegreeToNodes.data.count(0)) {
            return;
        }
    }
    layoutAnimating = false;
    // wait until layout animation finish
    while (!layoutThreadPool->empty()) {
    }
    groups.clear();
    xCoordFixed.clear();
    yCoordFixed.clear();
    for (auto& b : bounds) {
        b.clear();
    }
    clearEmptyGroup(bounds);
    igraph_vector_int_t roots;
    set<int>& rootIDs = up ? outDegreeToNodes.data[0] : inDegreeToNodes.data[0];
    igraph_vector_int_init(&roots, rootIDs.size());
    int count = 0;
    for (int rootId : rootIDs) {
        VECTOR(roots)[count] = rootId;
        count++;
    }
    if (treeUpAndDownCircle) {
        igraph_layout_reingold_tilford_circular(theOriginalGraph, layoutMatrix, IGRAPH_ALL, &roots, NULL);
    } else {
        igraph_layout_reingold_tilford(theOriginalGraph, layoutMatrix, IGRAPH_ALL, &roots, NULL);
    }
    applyLayout(true);
    updateTextPos();
    treeUpAndDownCircle = not treeUpAndDownCircle;
}

void BoundedIncrementalGraph::updateAnim(threepp::Camera& camera) {
    for (auto& countAndDo : doOnNextFrame) {
        if (countAndDo.first > 0) {
            countAndDo.second();
            countAndDo.first--;
        }
    }
    clearDoOnNextFrame();
    graphGenerateAndConsumeLock.lock();
    refreshSimpleText();
    graphGenerateAndConsumeLock.unlock();
    if (nodesOrderedByNodeId.empty() and bufferSize() == 0) {
        graphIncreasing = false;
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
            if (shouldTransitiveReduction) {
                transitiveReductionImpl();
                shouldTransitiveReduction = false;
            }
            applyPosByGroup(groups);
            applyPosByGroup(xCoordFixed);
            applyPosByGroup(yCoordFixed);
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
        applyLayout();
    }
    threepp::Vector3 worldDir;
    camera.getWorldDirection(worldDir);
    nodesObj->setCameraDir(worldDir);
    nodesObj->matrixNeedUpdate();
    linesObj->setCameraDir(worldDir);
    linesObj->updateFlow([&](int endNode, bool backward) {
        startFlowFrom(endNode, backward);
        });
}

// 0 for groups
// 1 for x fixed
// 2 for y fixed
bool BoundedIncrementalGraph::updatePosByGroup(vector<set<int>>& groups, int which) {
    bool animating = false;
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
            if (which == 0) {
                if (not dragMouseListener->draggingGroup.count(i)) {
                    points[i].add(dir);
                    animating |= dir.length() > 0.0001;
                }
            }
            if (which == 1) {
                if (not dragMouseListener->draggingGroupX.count(i)) {
                    points[i].x += dir.x;
                    animating |= dir.x > 0.0001;
                    igraph_vector_int_t neighbors;
                    igraph_vector_int_init(&neighbors, 0);
                    igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_ALL);
                    if (igraph_vector_int_size(&neighbors)) {
                        float posY = 0;
                        float posZ = 0;
                        for (int index = 0; index < igraph_vector_int_size(&neighbors); ++index) {
                            posY += points[VECTOR(neighbors)[index]].y;
                            posZ += points[VECTOR(neighbors)[index]].z;
                        }
                        posY /= igraph_vector_int_size(&neighbors);
                        posZ /= igraph_vector_int_size(&neighbors);
                        points[i].y = posY;
                        points[i].z = posZ;
                    }
                    igraph_vector_int_destroy(&neighbors);
                }
            }
            if (which == 2) {
                if (not dragMouseListener->draggingGroupY.count(i)) {
                    points[i].y += dir.y;
                    animating |= dir.y > 0.0001;
                    igraph_vector_int_t neighbors;
                    igraph_vector_int_init(&neighbors, 0);
                    igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_ALL);
                    if (igraph_vector_int_size(&neighbors)) {
                        float posX = 0;
                        float posZ = 0;
                        for (int index = 0; index < igraph_vector_int_size(&neighbors); ++index) {
                            posX += points[VECTOR(neighbors)[index]].x;
                            posZ += points[VECTOR(neighbors)[index]].z;
                        }
                        posX /= igraph_vector_int_size(&neighbors);
                        posZ /= igraph_vector_int_size(&neighbors);
                        points[i].x = posX;
                        points[i].z = posZ;
                    }
                    igraph_vector_int_destroy(&neighbors);
                }
            }
        }
    }
    return animating;
}

void BoundedIncrementalGraph::applyPosByGroup(vector<set<int>>& groups) {
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    for (auto& group : groups) {
        for (int i : group) {
            MATRIX(*layoutMatrix, i, 0) = points[i].x;
            MATRIX(*layoutMatrix, i, 1) = points[i].y;
            if (not is2D) {
                MATRIX(*layoutMatrix, i, 2) = points[i].z;
            }
        }
    }
}

void BoundedIncrementalGraph::set2DLayout(bool use2DLayout) {
    if (use2DLayout) {
        if (layoutState == LAYOUT_STATE_3D) {
            layoutState = LAYOUT_STATE_2D_UNFINISHED;
            for (int i = 0;i < bounds.size();i++) {
                boundFrames[i]->setDim(true);
            }
            layoutAnimating = true;
        }
    } else {
        if (layoutState == LAYOUT_STATE_2D) {
            layoutState = LAYOUT_STATE_3D_UNFINISHED;
            for (int i = 0;i < bounds.size();i++) {
                boundFrames[i]->setDim(false);
            }
            layoutAnimating = true;
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
    layoutThreadPool->submit([&] {
        PL_thread_attach_engine(NULL);
        });
    textLoaderThreadPool = new ThreadPool(1);
    linesObj = FlowLine::create(0.1);
    linesObj->updateAlphaUnselected(alphaForUnselected);
    linesObj->updateAlphaSelected(alphaForSelected);
    add(linesObj);
    int nodeCapacity = 10000;
    nodesObj = Nodes::create(nodeCapacity, 0.3f);
    nodesObj->updateAlphaUnselected(alphaForUnselected);
    nodesObj->updateAlphaSelected(alphaForSelected);
    add(nodesObj);
    textSizes = vector<float>(nodeCapacity);
    fill(textSizes.begin(), textSizes.end(), 1);
    theOriginalGraph = new igraph_t;
    igraph_empty(theOriginalGraph, 0, IGRAPH_DIRECTED);
    layoutMatrix = new igraph_matrix_t;
    igraph_matrix_init(layoutMatrix, 0, 2);
    for (int i = 0; i < 6;i++) {
        layoutBounds[i] = new igraph_vector_t();
        igraph_vector_init(layoutBounds[i], 0);
    }
    weights = new igraph_vector_t();
    igraph_vector_init(weights, 0);
    for (int i = 0; i < 500; i++) {
        boundFrames.push_back(BoundFrame::create());
    }
}

int BoundedIncrementalGraph::getNodeCount() {
    return igraph_vcount(theOriginalGraph);
}

int BoundedIncrementalGraph::getEdgeCount() {
    return igraph_ecount(theOriginalGraph);
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

void BoundedIncrementalGraph::startFlowFrom(int nodeInstanceId, bool backward) {
    igraph_vector_int_t neighbors;
    igraph_vector_int_init(&neighbors, 0);
    igraph_neighbors(theOriginalGraph, &neighbors, nodeInstanceId, backward ? IGRAPH_IN : IGRAPH_OUT);
    for (int index = 0; index < igraph_vector_int_size(&neighbors); index++) {
        igraph_integer_t neighbor = VECTOR(neighbors)[index];
        if (nodesObj->selected.count(neighbor)) {
            if (backward) {
                linesObj->startFlowingEdge(neighbor, nodeInstanceId, backward);
            } else {
                linesObj->startFlowingEdge(nodeInstanceId, neighbor, backward);
            }
        }
    }
}

void BoundedIncrementalGraph::onNodeRightClicked(int nodeInstanceId) {
    bool shiftPressed = ImGui::IsKeyDown(ImGuiKey_LeftShift) or ImGui::IsKeyDown(ImGuiKey_RightShift);
    startFlowFrom(nodeInstanceId, shiftPressed);
}

void BoundedIncrementalGraph::onBoundDragIconClicked(int id) {
    if (lastClickedNodeId == id) {
        nodeClickedForTheFirstTime = false;
    } else {
        nodeClickedForTheFirstTime = true;
    }
    lastClickedNodeId = id;
    doubleClickStateMachine->onClick([&, id]() {
        if (not nodeClickedForTheFirstTime) {
            select(bounds[id]);
        }
        });
}

void BoundedIncrementalGraph::onNodeLeftClicked(int nodeInstanceId) {
    bool controlPressed = ImGui::IsKeyDown(ImGuiKey_LeftCtrl) or ImGui::IsKeyDown(ImGuiKey_RightCtrl);
    bool shiftPressed = ImGui::IsKeyDown(ImGuiKey_LeftShift) or ImGui::IsKeyDown(ImGuiKey_RightShift);
    bool key4pressed = ImGui::IsKeyDown(ImGuiKey_4);
    bool key5pressed = ImGui::IsKeyDown(ImGuiKey_5);
    bool key6pressed = ImGui::IsKeyDown(ImGuiKey_6);
    bool key7pressed = ImGui::IsKeyDown(ImGuiKey_7);
    bool key8pressed = ImGui::IsKeyDown(ImGuiKey_8);
    bool key9pressed = ImGui::IsKeyDown(ImGuiKey_9);
    if (controlPressed) {
        set<int> g;
        getGroupIfGrouped(nodeInstanceId, g, groups);
        if (g.size() > 1) {
            select(g);
        }
        getGroupIfGrouped(nodeInstanceId, g, xCoordFixed);
        if (g.size() > 1) {
            select(g);
        }
        getGroupIfGrouped(nodeInstanceId, g, yCoordFixed);
        if (g.size() > 1) {
            select(g);
        }
        getGroupIfGrouped(nodeInstanceId, g, bounds);
        if (g.size() > 1) {
            select(g);
        }
    } else if (key5pressed or key6pressed or key7pressed or key8pressed or key9pressed) {
        int keyPressed = 0;
        if (key5pressed) {
            keyPressed = 5;
        }
        if (key6pressed) {
            keyPressed = 6;
        }
        if (key7pressed) {
            keyPressed = 7;
        }
        if (key8pressed) {
            keyPressed = 8;
        }
        if (key9pressed) {
            keyPressed = 9;
        }
        set<int> dimKeyTypes;
        dimKeyTypes.insert(AllKeyTypes.begin(), AllKeyTypes.end());
        getDimControl(keyPressed, dimKeyTypes);
        set<int> selectedNodes;
        getConnectedNodesByDim(nodeInstanceId, dimKeyTypes, selectedNodes, key4pressed);
        select(selectedNodes);
    } else if (shiftPressed) {
        if (classKeyToFilePath.count(nodesOrderedByNodeId[nodeInstanceId]->getRuntimeClass())) {
            string filePath = classKeyToFilePath[nodesOrderedByNodeId[nodeInstanceId]->getRuntimeClass()];
            std::thread worker([&](string filePath) {
                std::system(("google-chrome file://" + filePath).data());
                }, filePath);
            worker.detach();
        }
    } else {
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
                auto p1 = dragMouseListener->rotateAccordingToCamera(dragMouseListener->getCurrentFocus(points[nodeInstanceId]));
                auto p2 = dragMouseListener->rotateAccordingToCamera(dragMouseListener->convertPosToPanPos(points[nodeInstanceId]));
                onFocusOn({ p2.x - p1.x, p2.y - p1.y });
            }
            });
    }
    onNodeColorChanged();
}

void BoundedIncrementalGraph::onNodeHover(int nodeInstanceId) {
    if (graphIncreasing) {
        return;
    }
    if (nodeInstanceId < nodesOrderedByNodeId.size() and not nodesObj->hovered.count(nodeInstanceId)) {
        nodesObj->hovered.clear();
        nodesObj->hovered.insert(nodeInstanceId);
        onNodeColorChanged();
        auto& nodeInfo = nodesOrderedByNodeId[nodeInstanceId];
        string info;
        if (nodeInfo->keyType != GlobalInfo::KEY_TYPE_FIELD_CONNECTION) {
            info += "method:  " + nodeInfo->methodOfRuntime + "\n";
        }
        if (not nodeInfo->getTypeKey().empty()) {
            info += "type:         " + nodeInfo->getTypeKey() + "\n";
        }
        info += "key:           " + nodeInfo->key + "\n";
        // info += "regex: "  "\n";
        // for (auto& pos : nodeInfo->positionInRegex) {
        //     info += "        ";
        //     info += pos->graphName + " | ";
        //     info += pos->lineName + " | ";
        //     info += pos->regex + "\n";
        // }
        showTooltip(info);
    }
}

void BoundedIncrementalGraph::onExitHover() {
    if (graphIncreasing) {
        return;
    }
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
    for (auto& group : groups) {
        for (int i : group) {
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
    for (auto& xFixGroup : xCoordFixed) {
        for (int i : xFixGroup) {
            VECTOR(*layoutBounds[0])[i] = points[i].x;
            VECTOR(*layoutBounds[1])[i] = points[i].x;
        }
    }
    for (auto& yFixGroup : yCoordFixed) {
        for (int i : yFixGroup) {
            VECTOR(*layoutBounds[2])[i] = points[i].y;
            VECTOR(*layoutBounds[3])[i] = points[i].y;
        }
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
    applyBounds();
}

void BoundedIncrementalGraph::onDrag(set<int>& ids, float deltaX, float deltaY, float deltaZ) {
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    if (raycastOnFrame) {
        for (int id : ids) {
            boundFrames[id]->onDrag(deltaX, deltaY, deltaZ);
            applyBounds();
        }
    } else {
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
    if (not layoutAnimating) {
        applyLayout();
        updateTextPos();
    }
}

void BoundedIncrementalGraph::onDragX(set<int>& ids, float deltaX) {
    if (not layoutAnimating) {
        return;
    }
    for (int id : ids) {
        points[id].x += deltaX;
        VECTOR(*layoutBounds[0])[id] = points[id].x;
        VECTOR(*layoutBounds[1])[id] = points[id].x;
    }
}

void BoundedIncrementalGraph::onDragY(set<int>& ids, float deltaY) {
    if (not layoutAnimating) {
        return;
    }
    for (int id : ids) {
        points[id].y += deltaY;
        VECTOR(*layoutBounds[2])[id] = points[id].y;
        VECTOR(*layoutBounds[3])[id] = points[id].y;
    }
}

void BoundedIncrementalGraph::getGroupIfGrouped(int id, set<int>& ids, vector<set<int>>& groups) {
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

void BoundedIncrementalGraph::resetStyledNodes() {
    nodesObj->styled.clear();
    nodesObj->styled2.clear();
    nodesObj->styled3.clear();
    nodesObj->styled4.clear();
    nodesObj->styled5.clear();
    nodesObj->styled6.clear();
    nodesObj->styled7.clear();
    nodesObj->styled8.clear();
    for (auto nodeInfo : nodesOrderedByNodeId) {
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_CALLED_METHOD or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_TIMING_STEP or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_DATA_STEP
            ) {
            nodesObj->styled.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_METHOD or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_CONDITION or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_ELSE
            ) {
            nodesObj->styled2.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_REFERENCE or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_VOID_REF) {
            nodesObj->styled3.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_ERROR) {
            nodesObj->styled4.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_METHOD_RETURN or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_CALLED_RETURN or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_METHOD_PARAMETER or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_CALLED_PARAMETER) {
            nodesObj->styled5.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->isWritten) {
            nodesObj->styled6.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->isOverride or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_TIMING_OVERRIDE or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_DATA_OVERRIDE) {
            nodesObj->styled7.insert(nodeInfo->nodeId);
        }
        if (nodeInfo->keyType == GlobalInfo::KEY_TYPE_FIELD_CONNECTION or
            nodeInfo->keyType == GlobalInfo::KEY_TYPE_ANONYMOUS_CLASS) {
            nodesObj->styled8.insert(nodeInfo->nodeId);
        }
    }
}

void BoundedIncrementalGraph::selectByKeyType(int keyType) {
    set<int> s;
    for (auto& nodeInfo : nodesOrderedByNodeId) {
        if (nodeInfo->keyType == keyType) {
            s.insert(nodeInfo->nodeId);
        }
    }
    select(s);
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

void BoundedIncrementalGraph::selectUpwardToTheTop() {
    int oldSelectedCount = -1;
    while (oldSelectedCount != nodesObj->selected.size()) {
        oldSelectedCount = nodesObj->selected.size();
        selectUpward();
    }
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

void BoundedIncrementalGraph::selectDownwardToTheBottom() {
    int oldSelectedCount = -1;
    while (oldSelectedCount != nodesObj->selected.size()) {
        oldSelectedCount = nodesObj->selected.size();
        selectDownward();
    }
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

void BoundedIncrementalGraph::selectShortestPathInBetween() {
    prepareDistance();
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        set<int> otherNodes;
        otherNodes.insert(nodesObj->selected.begin(), nodesObj->selected.end());
        otherNodes.erase(i);
        lookEachOtherForShortestPath(i, otherNodes, newNodes);
    }
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
        lookEachOtherForPath(i, otherNodes, newNodes);
    }
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectPathUpward() {
    prepareDistance();
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        set<int> otherNodes;
        otherNodes.insert(nodesObj->selected.begin(), nodesObj->selected.end());
        otherNodes.erase(i);
        lookUpForCommonAncestor(i, otherNodes, newNodes);
    }
    nodesObj->selected.insert(newNodes.begin(), newNodes.end());
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectPathDownward() {
    prepareDistance();
    set<int> newNodes;
    for (int i : nodesObj->selected) {
        set<int> otherNodes;
        otherNodes.insert(nodesObj->selected.begin(), nodesObj->selected.end());
        otherNodes.erase(i);
        lookDownForCommonChild(i, otherNodes, newNodes);
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
        for (int index = 0; index < igraph_vector_int_size(&neighbors); index++) {
            igraph_integer_t neighbor = VECTOR(neighbors)[index];
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
        for (int index = 0; index < igraph_vector_int_size(&neighbors); index++) {
            igraph_integer_t neighbor = VECTOR(neighbors)[index];
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
        for (int index = 0; index < igraph_vector_int_size(&neighbors); index++) {
            igraph_integer_t neighbor = VECTOR(neighbors)[index];
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

void BoundedIncrementalGraph::lookEachOtherForShortestPath(int i, int j, set<int>& visited, set<int>& selected) {
    visited.insert(i);

    if (not std::isinf(MATRIX(distance.data, i, j)) and i != j) {
        selected.insert(i);
        igraph_vector_int_t neighbors;
        igraph_vector_int_init(&neighbors, 0);
        igraph_neighbors(theOriginalGraph, &neighbors, i, IGRAPH_OUT);
        int minDistance = std::numeric_limits<float>::infinity();
        int minDistanceNeighbor = -1;
        for (int index = 0; index < igraph_vector_int_size(&neighbors); index++) {
            igraph_integer_t neighbor = VECTOR(neighbors)[index];
            int neighborDistance = MATRIX(distance.data, neighbor, j);
            if (not std::isinf(neighborDistance) and neighborDistance < minDistance) {
                minDistance = neighborDistance;
                minDistanceNeighbor = neighbor;
            }
        }
        if (minDistanceNeighbor > -1 and visited.find(minDistanceNeighbor) == visited.end()) {
            lookEachOtherForShortestPath(minDistanceNeighbor, j, visited, selected);
        }
    }
}

void BoundedIncrementalGraph::lookEachOtherForShortestPath(int i, set<int>& otherNodes, set<int>& selected) {
    for (int j : otherNodes) {
        set<int> visited;
        lookEachOtherForShortestPath(i, j, visited, selected);
    }
}

void BoundedIncrementalGraph::select(set<int>& s) {
    if (selectedFromAll or nodesObj->selected.empty()) {
        nodesObj->selected.insert(s.begin(), s.end());
    } else {
        set<int> oldSelected;
        oldSelected.insert(nodesObj->selected.begin(), nodesObj->selected.end());
        nodesObj->selected.clear();
        for (int i : s) {
            if (oldSelected.count(i)) {
                nodesObj->selected.insert(i);
            }
        }
    }
    onNodeColorChanged();
}
void BoundedIncrementalGraph::select(set<const char*>& uniKeys) {
    set<int> s;
    for (auto& uniKey : uniKeys) {
        s.insert(uniKeyToNodeInfo[uniKey]->nodeId);
    }
    select(s);
    onNodeColorChanged();
}

void BoundedIncrementalGraph::selectLoop() {
    prepareDistance();
    set<int> s;
    for (int nodeId = 0;nodeId < nodesOrderedByNodeId.size();nodeId++) {
        if (s.count(nodeId)) {
            continue;
        }
        igraph_vector_int_t nextIds;
        igraph_vector_int_init(&nextIds, 0);
        igraph_neighbors(theOriginalGraph, &nextIds, nodeId, IGRAPH_OUT);
        for (int i = 0; i < igraph_vector_int_size(&nextIds); i++) {
            igraph_integer_t nextId = VECTOR(nextIds)[i];
            if (not std::isinf(MATRIX(distance.data, nextId, nodeId))) {
                s.insert(nodeId);
                s.insert(nextId);
            }
        }
    }
    select(s);
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

void BoundedIncrementalGraph::clearDoOnNextFrame() {
    list<int> toBeRemoved;
    for (int i = 0;i < doOnNextFrame.size();i++) {
        if (doOnNextFrame[i].first < 1) {
            toBeRemoved.push_front(i);
        }
    }
    for (int i : toBeRemoved) {
        doOnNextFrame.erase(doOnNextFrame.begin() + i);
    }
}

void BoundedIncrementalGraph::clearEmptyGroup(vector<set<int>>& groups) {
    list<int> toBeRemoved;
    for (int i = 0;i < groups.size();i++) {
        if (groups[i].size() < 2) {
            toBeRemoved.push_front(i);
        }
    }
    for (int i : toBeRemoved) {
        groups.erase(groups.begin() + i);
    }
    if ((&groups) == (&bounds)) {
        for (int i = 0;i < toBeRemoved.size();i++) {
            boundFrames[groups.size() + i]->clearFrame();
            remove(*boundFrames[groups.size() + i]);
        }
    }
}

void BoundedIncrementalGraph::flowColor() {
    prepareInDegreeMap();
    prepareOutDegreeMap();
    threepp::Color startColor = threepp::Color(0.85, 0.85, 0);
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
    if (distanceFromTop < 0) {
        return 0.f;
    }
    if (distanceToBottom < 0) {
        return 1.0f;
    }
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
    for (auto& group : xCoordFixed) {
        if (group.size() > 1 and group.count(nodeId)) {
            return true;
        }
    }
    for (auto& group : yCoordFixed) {
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
    set<int> topNodes;
    if (inDegreeToNodes.data.count(0)) {
        topNodes.insert(inDegreeToNodes.data[0].begin(), inDegreeToNodes.data[0].end());
    } else {
        // the graph contains circle
        igraph_vector_int_t feedbackArcs;
        igraph_vector_int_init(&feedbackArcs, 0);
        igraph_feedback_arc_set(theOriginalGraph, &feedbackArcs, NULL, IGRAPH_FAS_APPROX_EADES);
        for (int edgeIndex = 0;edgeIndex < igraph_vector_int_size(&feedbackArcs);edgeIndex++) {
            int from = IGRAPH_FROM(theOriginalGraph, VECTOR(feedbackArcs)[edgeIndex]);
            int to = IGRAPH_TO(theOriginalGraph, VECTOR(feedbackArcs)[edgeIndex]);
            topNodes.insert(from);
            topNodes.insert(to);
        }
    }
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
}

void BoundedIncrementalGraph::prepareDistanceToBottom() {
    if (not distanceToBottom.needUpdate) {
        return;
    }
    distanceToBottom.needUpdate = false;
    set<int> bottomNode;
    if (outDegreeToNodes.data.count(0)) {
        bottomNode.insert(outDegreeToNodes.data[0].begin(), outDegreeToNodes.data[0].end());
    } else {
        // the graph contains circle
        igraph_vector_int_t feedbackArcs;
        igraph_vector_int_init(&feedbackArcs, 0);
        igraph_feedback_arc_set(theOriginalGraph, &feedbackArcs, NULL, IGRAPH_FAS_APPROX_EADES);
        for (int edgeIndex = 0;edgeIndex < igraph_vector_int_size(&feedbackArcs);edgeIndex++) {
            int from = IGRAPH_FROM(theOriginalGraph, VECTOR(feedbackArcs)[edgeIndex]);
            int to = IGRAPH_TO(theOriginalGraph, VECTOR(feedbackArcs)[edgeIndex]);
            bottomNode.insert(from);
            bottomNode.insert(to);
        }
    }
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
    // if (tobeRemoved.size() == points.size()) {
    //     tobeRemoved.erase(1);
    // }
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
    mapGroupForDeletion(groups, &mapFromNewToOldNodeId);
    mapGroupForDeletion(xCoordFixed, &mapFromNewToOldNodeId);
    mapGroupForDeletion(yCoordFixed, &mapFromNewToOldNodeId);
    mapGroupForDeletion(bounds, &mapFromNewToOldNodeId);

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
    delete oldWeights;

    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    reCreateLayout(nodesOrderedByNodeId.size(), is2D, false, &mapFromNewToOldNodeId);
    invalidateAllGraphInfo();
    nodesObj->mapNodeForDeletion(&mapFromNewToOldNodeId);
    // selected and textAdded must be clear at the same time
    mapNodeIdFromOldToNew(textAdded, &mapFromOldToNewNodeId);
    mapNodeIdFromOldToNew(nodesObj->selected, &mapFromOldToNewNodeId);
    onNodeColorChanged();

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
    vector<float> newTextSizes;
    for (int newIndex = 0; newIndex < igraph_vector_int_size(mapFromNewToOldNodeId); newIndex++) {
        int oldIndex = VECTOR(*mapFromNewToOldNodeId)[newIndex];
        auto& nodeInfo = nodesOrderedByNodeId[oldIndex];
        nodeInfo->nodeId = newIndex;
        nodesOrderedByNodeId_left.push_back(nodeInfo);
        textMesh_left.push_back(textMesh[oldIndex]);
        newTextSizes.push_back(textSizes[oldIndex]);
    }
    nodesOrderedByNodeId = nodesOrderedByNodeId_left;
    textMesh = textMesh_left;
    textSizes = newTextSizes;
}

void BoundedIncrementalGraph::mapGroupForDeletion(vector<set<int>>& groups, igraph_vector_int_t* mapFromNewToOldNodeId) {
    vector<set<int>> groups_left;
    for (auto& group : groups) {
        set<int> group_left;
        for (int newIndex = 0; newIndex < igraph_vector_int_size(mapFromNewToOldNodeId); ++newIndex) {
            int oldIndex = VECTOR(*mapFromNewToOldNodeId)[newIndex];
            if (group.count(oldIndex)) {
                group_left.insert(newIndex);
            }
        }
        groups_left.push_back(group_left);
    }
    groups = groups_left;
    clearEmptyGroup(groups);
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

void BoundedIncrementalGraph::updateTextPos() {
    for (int i : textAdded) {
        updateTextPosAt(i);
    }
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
                                textMaterial->color = { 1,1,1 };
                                textMesh[item.nodeId] = threepp::Text2D::create(threepp::TextGeometry::Options(font, 0.4), item.text, textMaterial);
                                textMesh[item.nodeId]->geometry()->center();
                                if (nodesObj->nodeSizes[item.nodeId] > 0.001) {
                                    textSizes[item.nodeId] = nodesObj->nodeSizes[item.nodeId];
                                } else {
                                    textSizes[item.nodeId] = 0.001;
                                }
                                float textSize = baseTextSize * textSizes[item.nodeId] / sqrt(item.text.size() + 0.2);
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
    if (raycastByDrag) {
        for (int i = 0;i < bounds.size();i++) {
            boundFrames[i]->raycast(raycaster, intersects);
            if (not intersects.empty()) {
                raycastOnFrame = true;
                intersects.front().instanceId = i;
                break;
            }
        }
    }
    if (intersects.empty()) {
        nodesObj->raycast(raycaster, intersects);
        if (raycastByDrag) {
            raycastOnFrame = false;
        }
    }
}

void BoundedIncrementalGraph::invalidateAllGraphInfo() {
    inDegreeToNodes.needUpdate = true;
    outDegreeToNodes.needUpdate = true;
    degreeToNodes.needUpdate = true;
    componentToNodes.needUpdate = true;
    distanceFromTop.needUpdate = true;
    distanceToBottom.needUpdate = true;
    distance.needUpdate = true;
    methodStackSizeToNodes.needUpdate = true;
}

void BoundedIncrementalGraph::groupToFile(ofstream& f, set<int>& group) {
    f << group.size() << "\n";
    for (int i : group) {
        f << i << "\n";
    }
}

void BoundedIncrementalGraph::groupFromFile(ifstream& f, set<int>& group) {
    int groupSize = getInt(f);
    for (int i = 0;i < groupSize;i++) {
        group.insert(getInt(f));
    }
}

void BoundedIncrementalGraph::toFile(ofstream& f) {
    for (auto& nodeInfo : nodesOrderedByNodeId) {
        nodeInfo->getSimpleName();
        nodeInfo->getTypeKey();
        nodeInfo->getRuntimeClass();
        nodeInfo->getDeclaredInType();
    }
    f << searchingGraphName << "\n";
    // dimension
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    if (is2D) {
        f << 2 << "\n";
    } else {
        f << 3 << "\n";
    }
    // node info
    f << nodesOrderedByNodeId.size() << "\n";
    FOR_EACH_ITEM(nodesOrderedByNodeId, item->toFile(f););
    // edge pair
    f << edgePairs.size() << "\n";
    for (auto& edge : edgePairs) {
        f << edge.first << "\n";
        f << edge.second << "\n";
    }
    // position
    for (auto& p : points) {
        f << p.x << "\n";
        f << p.y << "\n";
        f << p.z << "\n";
    }
    // weight
    for (int i = 0;i < igraph_vector_size(weights);i++) {
        float w = VECTOR(*weights)[i];
        f << w << "\n";
    }
    // group
    f << groups.size() << "\n";
    FOR_EACH_ITEM(groups, groupToFile(f, item););
    f << xCoordFixed.size() << "\n";
    FOR_EACH_ITEM(xCoordFixed, groupToFile(f, item););
    f << yCoordFixed.size() << "\n";
    FOR_EACH_ITEM(yCoordFixed, groupToFile(f, item););
    f << bounds.size() << "\n";
    FOR_EACH_ITEM(bounds, groupToFile(f, item););
    // node obj
    nodesObj->toFile(f);
    // edge obj
    linesObj->toFile(f);
}

void BoundedIncrementalGraph::fromFile(ifstream& f) {
    layoutThreadPool->submit([&]() {
        graphGenerateAndConsumeLock.lock();
        uniKeyToNodeInfo.clear();
        nodesOrderedByNodeId.clear();
        methodOfRuntimeToNodeInfo.clear();
        addressableKeyToNodeInfo.clear();
        graphNameToLineNameToRegexToNodeInfo.clear();
        textLoaded.clear();
        textLoading.clear();
        for (int i : textAdded) {
            remove(*textMesh[i]);
        }
        textAdded.clear();
        edgePairs.clear();
        points.clear();
        groups.clear();
        xCoordFixed.clear();
        yCoordFixed.clear();
        textMesh.clear();
        nodesObj->selected.clear();
        ungroupAllNodes(bounds);

        getline(f, searchingGraphName);
        // dimension
        int dim = getInt(f);
        bool is2D = dim == 2;
        if (is2D) {
            layoutState = LAYOUT_STATE_2D;
        } else {
            layoutState = LAYOUT_STATE_3D;
        }
        // node info
        int nodeCount = getInt(f);
        for (int i = 0;i < nodeCount;i++) {
            textMesh.push_back(NULL);
        }
        for (int i = 0;i < nodeCount;i++) {
            NodeInfo* nodeInfo = new NodeInfo();
            nodeInfo->fromFile(f);
            nodesOrderedByNodeId.push_back(nodeInfo);
            saveNodeInfo(nodeInfo);
            for (auto& position : nodeInfo->positionInRegex) {
                saveNodePosition(position, nodeInfo);
            }
        }
        // edge pair
        int edgeCount = getInt(f);
        for (int i = 0;i < edgeCount;i++) {
            int from = getInt(f);
            int to = getInt(f);
            edgePairs.push_back({ from,to });
        }
        // position
        for (int i = 0; i < nodeCount;i++) {
            float x = getFloat(f);
            float y = getFloat(f);
            float z = getFloat(f);
            points.push_back(threepp::Vector3(x, y, z));
        }
        // weight
        igraph_vector_destroy(weights);
        igraph_vector_init(weights, edgeCount);
        igraph_vector_fill(weights, 1);
        for (int i = 0;i < edgeCount;i++) {
            VECTOR(*weights)[i] = getFloat(f);
        }
        // group
        int groupCount = getInt(f);
        for (int i = 0; i < groupCount;i++) {
            set<int> g;
            groupFromFile(f, g);
            if (not g.empty()) {
                groups.push_back(g);
            }
        }
        groupCount = getInt(f);
        for (int i = 0; i < groupCount;i++) {
            set<int> g;
            groupFromFile(f, g);
            if (not g.empty()) {
                xCoordFixed.push_back(g);
            }
        }
        groupCount = getInt(f);
        for (int i = 0; i < groupCount;i++) {
            set<int> g;
            groupFromFile(f, g);
            if (not g.empty()) {
                yCoordFixed.push_back(g);
            }
        }
        groupCount = getInt(f);
        for (int i = 0; i < groupCount;i++) {
            set<int> g;
            groupFromFile(f, g);
            if (not g.empty()) {
                bounds.push_back(g);
            }
        }
        // node obj
        nodesObj->fromFile(f);
        nodesObj->setPointPositions(points);
        // edge obj
        linesObj->fromFile(f);
        linesObj->setEdges(points, edgePairs);
        // graph
        igraph_destroy(theOriginalGraph);
        igraph_empty(theOriginalGraph, nodeCount, IGRAPH_DIRECTED);
        igraph_integer_t edgesArray[edgeCount * 2];
        int i = 0;
        for (auto& edge : edgePairs) {
            edgesArray[i * 2] = edge.first;
            edgesArray[i * 2 + 1] = edge.second;
            i++;
        }
        igraph_vector_int_t newEdges_;
        igraph_vector_int_view(&newEdges_, edgesArray, edgeCount * 2);
        igraph_add_edges(theOriginalGraph, &newEdges_, NULL);
        // layout
        reCreateLayoutWithNoOldLayoutInfo(nodeCount, is2D, false);
        resetBounds();
        for (int i = 0;i < nodeCount;i++) {
            MATRIX(*layoutMatrix, i, 0) = points[i].x;
            MATRIX(*layoutMatrix, i, 1) = points[i].y;
            if (not is2D) {
                MATRIX(*layoutMatrix, i, 2) = points[i].z;
            }
        }
        invalidateAllGraphInfo();
        graphGenerateAndConsumeLock.unlock();
        f.close();
        doOnNextFrame.push_back({ 10,[&]() {
            onNodeColorChanged();
        } });
        });
}

map<string, string> BoundedIncrementalGraph::classKeyToFilePath;

void BoundedIncrementalGraph::deserializeFilePath() {
    ifstream f;
    f.open(FileManager::NAME_SERIALIZE(typeKey2filePath));
    if (not f.is_open()) {
        return;
    }
    int fileCount = Serializable::getInt(f);
    for (int fileIndex = 0;fileIndex < fileCount;fileIndex++) {
        string filePath;
        getline(f, filePath);
        int typeCount = Serializable::getInt(f);
        for (int typeIndex = 0;typeIndex < typeCount;typeIndex++) {
            string typeKey;
            getline(f, typeKey);
            string filePath;
            getline(f, filePath);
            classKeyToFilePath[typeKey] = filePath;
        }
    }
}

void BoundedIncrementalGraph::changeTextSize(bool increase) {
    float s = 0;
    if (increase) {
        s = 1.1f;
    } else {
        s = 1 / 1.1f;
    }
    baseTextSize *= s;
    for (int i : textLoaded) {
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

PositionInRegex::PositionInRegex() {
}

void PositionInRegex::toFile(ofstream& f) {
    f << graphName << "\n";
    f << lineName << "\n";
    f << regex << "\n";
}

void PositionInRegex::fromFile(ifstream& f) {
    getline(f, graphName);
    getline(f, lineName);
    getline(f, regex);
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
            ret.push_back({ nodeInfo->key, nodeInfo->getDeclaredInType() });
        }
    }
    return ret;
}

list<tuple<string, string, string, int, string>> BoundedIncrementalGraph::getSelectedRuntime() {
    auto ret = list<tuple<string, string, string, int, string>>();
    for (int i : nodesObj->selected) {
        auto& nodeInfo = nodesOrderedByNodeId[i];
        ret.push_back({ nodeInfo->methodOfRuntime,nodeInfo->runtimeKey,nodeInfo->key,nodeInfo->keyType, nodeInfo->getRuntimeClass() });
    }
    return ret;
}

threepp::Vector3 BoundedIncrementalGraph::getMidPosOfSelectedNodes() {
    threepp::Vector3 ret = { 0,0,0 };
    if (not nodesObj->selected.size()) {
        return ret;
    }
    for (int i : nodesObj->selected) {
        ret.add(points[i]);
    }
    ret.divideScalar(nodesObj->selected.size()).add({ 1,1,0 });
    return ret;
}

bool BoundedIncrementalGraph::is2DLayout() {
    return layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
}

using PointType = ikdTree_PointType;
using PointVector = KD_TREE<PointType>::PointVector;
KD_TREE<ikdTree_PointType> ikd_Tree(0.3, 0.6, 0.2);

static int scaleByDistanceCount = 0;

void BoundedIncrementalGraph::scaleByDistance(bool force) {
    scaleByDistanceCount = (scaleByDistanceCount + 1) % 2;
    if (scaleByDistanceCount and not force) {
        return;
    }
    PointVector point_cloud;
    PointType new_point;
    for (auto& p : points) {
        new_point.x = p.x;
        new_point.y = p.y;
        new_point.z = p.z;
        point_cloud.push_back(new_point);
    }
    ikd_Tree.Build(point_cloud);
    PointType target;
    vector<float> PointDist;
    PointVector search_result;
    set<int> doneNode;
    for (int i = 0;i < points.size();i++) {
        if (doneNode.count(i)) {
            continue;
        }
        auto& p = points[i];
        PointVector().swap(search_result);
        target.x = p.x;
        target.y = p.y;
        target.z = p.z;
        set<int> group;
        getGroupIfGrouped(i, group, groups);
        int queryCount = group.size() + 1;
        ikd_Tree.Nearest_Search(target, queryCount, search_result, PointDist);
        if (PointDist.size() < queryCount) {
            for (int j : group) {
                nodesObj->setNodeSizeAt(j, 10);
            }
        } else {
            float nodeSize = sqrt(PointDist[group.size()]);
            for (int j : group) {
                nodesObj->setNodeSizeAt(j, nodeSize);
            }
        }
        doneNode.insert(group.begin(), group.end());
    }
    nodesObj->matrixNeedUpdate();
    textLoaderThreadPool->submit([this]() {
        graphGenerateAndConsumeLock.lock();
        for (int i : textAdded) {
            float size = nodesObj->nodeSizes[i];
            if (size < 0.001) {
                size = 0.001;
            }
            float scale = size / textSizes[i];
            textMesh[i]->geometry()->scale(scale, scale, scale);
            textSizes[i] = size;
        }
        graphGenerateAndConsumeLock.unlock();
        });
}

void BoundedIncrementalGraph::applyLayoutPosition() {
    if (layoutState == LAYOUT_STATE_2D) {
        for (igraph_integer_t node_id_iter = 0; node_id_iter < nodesOrderedByNodeId.size(); node_id_iter++) {
            if (not (dragMouseListener->draggingGroup.count(node_id_iter) or
                dragMouseListener->draggingGroupX.count(node_id_iter) or
                dragMouseListener->draggingGroupY.count(node_id_iter))) {
                points[node_id_iter].set(MATRIX(*layoutMatrix, node_id_iter, 0), MATRIX(*layoutMatrix, node_id_iter, 1), 0);
            }
        }
    }
    if (layoutState == LAYOUT_STATE_3D) {
        for (igraph_integer_t node_id_iter = 0; node_id_iter < nodesOrderedByNodeId.size(); node_id_iter++) {
            if (not (dragMouseListener->draggingGroup.count(node_id_iter) or
                dragMouseListener->draggingGroupX.count(node_id_iter) or
                dragMouseListener->draggingGroupY.count(node_id_iter))) {
                points[node_id_iter].set(MATRIX(*layoutMatrix, node_id_iter, 0), MATRIX(*layoutMatrix, node_id_iter, 1), MATRIX(*layoutMatrix, node_id_iter, 2));
            }
        }
    }
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

void BoundedIncrementalGraph::groupSelectedNodes(vector<set<int>>& groups) {
    ungroupNodes(nodesObj->selected, xCoordFixed);
    ungroupNodes(nodesObj->selected, yCoordFixed);
    groupNodes(nodesObj->selected, groups);
}

void BoundedIncrementalGraph::groupNodes(set<int>& newGroup, vector<set<int>>& groups) {
    if (newGroup.size() < 2) {
        return;
    }
    // release selected position
    for (int i : newGroup) {
        nodesObj->positionFixed.erase(i);
    }
    set<int>* reusedGroup = NULL;
    for (auto& group : groups) {
        for (int i : newGroup) {
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
    reusedGroup->insert(newGroup.begin(), newGroup.end());
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
    layoutAnimating = true;
}

void BoundedIncrementalGraph::ungroupSelectedNodes(vector<set<int>>& groups) {
    ungroupNodes(nodesObj->selected, groups);
}

void BoundedIncrementalGraph::ungroupNodes(set<int>& ungroup, vector<set<int>>& groups) {
    for (auto& group : groups) {
        for (int i : ungroup) {
            group.erase(i);
        }
        if (group.size() == 1) {
            group.clear();
        }
    }
    clearEmptyGroup(groups);
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
    layoutAnimating = true;
}

void BoundedIncrementalGraph::ungroupAllNodes(vector<set<int>>& groups) {
    for (auto& group : groups) {
        set<int> tobeUngrouped;
        for (auto i : group) {
            if (not nodesObj->selected.count(i)) {
                tobeUngrouped.insert(i);
            }
        }
        FOR_EACH_ITEM(tobeUngrouped, group.erase(item););
    }
    clearEmptyGroup(groups);
    bool is2D = layoutState == LAYOUT_STATE_2D or layoutState == LAYOUT_STATE_2D_UNFINISHED;
    resetLayoutBound(is2D);
    onNodeColorChanged();
    layoutAnimating = true;
}

void BoundedIncrementalGraph::removeCircle() {
    igraph_vector_int_t feedbackArcs;
    igraph_vector_int_init(&feedbackArcs, 0);
    igraph_feedback_arc_set(theOriginalGraph, &feedbackArcs, NULL, IGRAPH_FAS_APPROX_EADES);
    igraph_es_t es;
    igraph_es_vector(&es, &feedbackArcs);
    igraph_delete_edges(theOriginalGraph, es);
}

void BoundedIncrementalGraph::transitiveReduction() {
    shouldTransitiveReduction = true;
    layoutAnimating = true;
}

void BoundedIncrementalGraph::transitiveReductionImpl() {
    prepareDistance();
    list<pair<int, int>> toBeRemovedEdges;
    for (int nodeId = 0; nodeId < nodesOrderedByNodeId.size();nodeId++) {
        auto& srcNode = nodesOrderedByNodeId[nodeId];
        if (srcNode->keyType != GlobalInfo::KEY_TYPE_CONDITION and
            srcNode->keyType != GlobalInfo::KEY_TYPE_METHOD and
            srcNode->keyType != GlobalInfo::KEY_TYPE_CONSTRUCTOR) {
            continue;
        }
        igraph_vector_int_t nextIds;
        igraph_vector_int_init(&nextIds, 0);
        igraph_neighbors(theOriginalGraph, &nextIds, nodeId, IGRAPH_OUT);
        for (int i = 0; i < igraph_vector_int_size(&nextIds); i++) {
            igraph_integer_t nextId = VECTOR(nextIds)[i];
            for (int j = 0; j < igraph_vector_int_size(&nextIds); j++) {
                igraph_integer_t reachableNodeId = VECTOR(nextIds)[j];
                if (reachableNodeId != nodeId and reachableNodeId != nextId and
                    not std::isinf(MATRIX(distance.data, nextId, reachableNodeId))) {
                    toBeRemovedEdges.push_back({ nodeId,reachableNodeId });
                }
            }
        }
        igraph_vector_int_destroy(&nextIds);
    }
    igraph_integer_t edgesArray[toBeRemovedEdges.size() * 2];
    int i = 0;
    for (auto& edge : toBeRemovedEdges) {
        edgesArray[i * 2] = edge.first;
        edgesArray[i * 2 + 1] = edge.second;
        i++;
    }
    igraph_vector_int_t toBeRemovedEdges_;
    igraph_vector_int_view(&toBeRemovedEdges_, edgesArray, toBeRemovedEdges.size() * 2);
    igraph_es_t es;
    igraph_es_pairs(&es, &toBeRemovedEdges_, true);
    igraph_delete_edges(theOriginalGraph, es);

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
    // recreate weights
    igraph_vector_destroy(weights);
    igraph_vector_init(weights, igraph_ecount(theOriginalGraph));
    igraph_vector_fill(weights, 1);
    invalidateAllGraphInfo();
}

void BoundedIncrementalGraph::grid(vector<set<int>>& toBeGruped) {
    map<int, set<int>*> groups;
    for (int nodeId = 0;nodeId < points.size();nodeId++) {
        igraph_vector_int_t neighborsIn;
        igraph_vector_int_init(&neighborsIn, 0);
        igraph_neighbors(theOriginalGraph, &neighborsIn, nodeId, IGRAPH_IN);
        igraph_vector_int_t neighborsOut;
        igraph_vector_int_init(&neighborsOut, 0);
        igraph_neighbors(theOriginalGraph, &neighborsOut, nodeId, IGRAPH_OUT);
        if (igraph_vector_int_size(&neighborsIn) == 1 and igraph_vector_int_size(&neighborsOut) == 1) {
            int nodeIdIn = VECTOR(neighborsIn)[0];
            int nodeIdOut = VECTOR(neighborsOut)[0];
            bool nodeIdInGrouped = groups.count(nodeIdIn);
            bool nodeIdOutGrouped = groups.count(nodeIdOut);
            if (nodeIdInGrouped and nodeIdOutGrouped) {
                // merge group
                set<int>* outGroup = groups[nodeIdOut];
                groups[nodeIdIn]->insert(outGroup->begin(), outGroup->end());
                groups[nodeIdIn]->insert(nodeId);
                groups[nodeIdOut] = groups[nodeIdIn];
                groups[nodeId] = groups[nodeIdIn];
            } else if (nodeIdInGrouped or nodeIdOutGrouped) {
                if (nodeIdInGrouped) {
                    groups[nodeIdIn]->insert(nodeId);
                    groups[nodeId] = groups[nodeIdIn];
                } else {
                    groups[nodeIdOut]->insert(nodeId);
                    groups[nodeId] = groups[nodeIdOut];
                }
            } else {
                groups[nodeId] = new set<int>();
                groups[nodeId]->insert(nodeId);
            }
        }
        igraph_vector_int_destroy(&neighborsIn);
        igraph_vector_int_destroy(&neighborsOut);
    }
    set<set<int>*> uniqueGroups;
    for (auto& group : groups) {
        uniqueGroups.insert(group.second);
    }

    for (auto& group : uniqueGroups) {
        groupNodes(*group, toBeGruped);
    }
    for (auto& group : uniqueGroups) {
        delete group;
    }
}

void BoundedIncrementalGraph::groupByMethod() {
    map<string, set<int>> methodToGroup;
    for (int nodeId = 0;nodeId < points.size();nodeId++) {
        auto& nodeInfo = nodesOrderedByNodeId[nodeId];
        if (not methodToGroup.count(nodeInfo->methodOfRuntime)) {
            methodToGroup[nodeInfo->methodOfRuntime] = set<int>();
        }
        methodToGroup[nodeInfo->methodOfRuntime].insert(nodeId);
    }
    yCoordFixed.clear();
    for (auto& methodAndGroup : methodToGroup) {
        yCoordFixed.push_back(methodAndGroup.second);
    }
}

void BoundedIncrementalGraph::resetBounds() {
    clearEmptyGroup(bounds);
    bool is2D = is2DLayout();
    for (int boundIndex = 0; boundIndex < bounds.size(); boundIndex++) {
        auto& b = bounds[boundIndex];
        float minX = std::numeric_limits<float>::infinity();
        float minY = std::numeric_limits<float>::infinity();
        float minZ = std::numeric_limits<float>::infinity();
        float maxX = -std::numeric_limits<float>::infinity();
        float maxY = -std::numeric_limits<float>::infinity();
        float maxZ = -std::numeric_limits<float>::infinity();
        for (int i : b) {
            auto& pos = points[i];
            if (pos.x < minX) {
                minX = pos.x;
            }
            if (pos.x > maxX) {
                maxX = pos.x;
            }
            if (pos.y < minY) {
                minY = pos.y;
            }
            if (pos.y > maxY) {
                maxY = pos.y;
            }
            if (is2D) {
                if (pos.z < minZ) {
                    minZ = pos.z;
                }
                if (pos.z > maxZ) {
                    maxZ = pos.z;
                }
            }
        }
        for (int i : b) {
            VECTOR(*layoutBounds[0])[i] = minX;
            VECTOR(*layoutBounds[1])[i] = maxX;
            VECTOR(*layoutBounds[2])[i] = minY;
            VECTOR(*layoutBounds[3])[i] = maxY;
            if (not is2D) {
                VECTOR(*layoutBounds[4])[i] = minZ;
                VECTOR(*layoutBounds[5])[i] = maxY;
            }
        }
        boundFrames[boundIndex]->setDim(is2D);
        if (is2D) {
            boundFrames[boundIndex]->start.set(minX, maxY, 0);
            boundFrames[boundIndex]->end.set(maxX, minY, 0);
        } else {
            boundFrames[boundIndex]->start.set(minX, maxY, minZ);
            boundFrames[boundIndex]->end.set(maxX, minY, maxZ);
        }
        boundFrames[boundIndex]->scaleIcon();
        boundFrames[boundIndex]->applyPosAndSize();
        add(boundFrames[boundIndex]);
    }
}

void BoundedIncrementalGraph::applyBounds() {
    bool is2D = is2DLayout();
    for (int id = 0;id < bounds.size();id++) {
        float minX = min(boundFrames[id]->start.x, boundFrames[id]->end.x);
        float minY = min(boundFrames[id]->start.y, boundFrames[id]->end.y);
        float minZ = min(boundFrames[id]->start.z, boundFrames[id]->end.z);
        float maxX = max(boundFrames[id]->start.x, boundFrames[id]->end.x);
        float maxY = max(boundFrames[id]->start.y, boundFrames[id]->end.y);
        float maxZ = max(boundFrames[id]->start.z, boundFrames[id]->end.z);
        for (int i : bounds[id]) {
            VECTOR(*layoutBounds[0])[i] = minX;
            VECTOR(*layoutBounds[1])[i] = maxX;
            VECTOR(*layoutBounds[2])[i] = minY;
            VECTOR(*layoutBounds[3])[i] = maxY;
            if (not is2D) {
                VECTOR(*layoutBounds[4])[i] = minZ;
                VECTOR(*layoutBounds[5])[i] = maxZ;
            }
        }
    }
}

void BoundedIncrementalGraph::boundByClass() {
    map<string, set<int>> classToNodes;
    for (int i = 0;i < nodesOrderedByNodeId.size();i++) {
        string& runtimeClass = nodesOrderedByNodeId[i]->getRuntimeClass();
        if (not classToNodes.count(runtimeClass)) {
            classToNodes[runtimeClass] = set<int>();
        }
        classToNodes[runtimeClass].insert(i);
    }
    for (auto& classAndNodes : classToNodes) {
        if (classAndNodes.second.size() > 1) {
            bounds.push_back(classAndNodes.second);
        }
    }
}

void BoundedIncrementalGraph::boundByMethod() {
    map<string, set<int>> methodToNodes;
    for (int i = 0;i < nodesOrderedByNodeId.size();i++) {
        string& runtimeMethod = nodesOrderedByNodeId[i]->methodOfRuntime;
        if (not methodToNodes.count(runtimeMethod)) {
            methodToNodes[runtimeMethod] = set<int>();
        }
        methodToNodes[runtimeMethod].insert(i);
    }
    for (auto& methodAndNodes : methodToNodes) {
        if (methodAndNodes.second.size() > 1) {
            bounds.push_back(methodAndNodes.second);
        }
    }
}

void BoundedIncrementalGraph::showAndHideBoundFrame(bool show) {
    for (auto& boundFrame : boundFrames) {
        boundFrame->visible = show;
    }
}

void BoundedIncrementalGraph::getConnectedNodesByDim(int nodeId, set<int>& nodeTypes, set<int>& connected, bool dir) {
    if (connected.count(nodeId)) {
        return;
    }
    connected.insert(nodeId);
    igraph_vector_int_t neighbors;
    igraph_vector_int_init(&neighbors, 0);
    if (dir) {
        igraph_neighbors(theOriginalGraph, &neighbors, nodeId, IGRAPH_IN);
    } else {
        igraph_neighbors(theOriginalGraph, &neighbors, nodeId, IGRAPH_OUT);
    }
    for (int index = 0; index < igraph_vector_int_size(&neighbors); ++index) {
        int neighborId = VECTOR(neighbors)[index];
        if (nodeTypes.count(nodesOrderedByNodeId[neighborId]->keyType)) {
            getConnectedNodesByDim(neighborId, nodeTypes, connected, dir);
        }
    }
    igraph_vector_int_destroy(&neighbors);
}

void BoundedIncrementalGraph::focusHoverd() {
    if (not nodesObj->hovered.empty()) {
        int nodeInstanceId = *nodesObj->hovered.begin();
        auto p1 = dragMouseListener->rotateAccordingToCamera(dragMouseListener->getCurrentFocus(points[nodeInstanceId]));
        auto p2 = dragMouseListener->rotateAccordingToCamera(dragMouseListener->convertPosToPanPos(points[nodeInstanceId]));
        onFocusOn({ p2.x - p1.x, p2.y - p1.y });
    }
}

void BoundedIncrementalGraph::prepareSelectByMethodStackSize() {
    if (not methodStackSizeToNodes.needUpdate) {
        return;
    }
    methodStackSizeToNodes.needUpdate = false;
    methodStackSizeToNodes.data.clear();
    for (auto& nodeInfo : nodesOrderedByNodeId) {
        if (not methodStackSizeToNodes.data.count(nodeInfo->methodStackSize)) {
            methodStackSizeToNodes.data[nodeInfo->methodStackSize] = set<int>();
        }
        methodStackSizeToNodes.data[nodeInfo->methodStackSize].insert(nodeInfo->nodeId);
    }
}

std::function<void(int, set<int>&)> BoundedIncrementalGraph::getDimControl;

void BoundedIncrementalGraph::printSelectedNode(const set<int>& excludeTypes, string& ret) {
    ret.clear();
    prepareInDegreeMap();
    prepareOutDegreeMap();
    vector<int> orderNode;
    FOR_EACH_ITEM(nodesObj->selected,
        if (not excludeTypes.count(nodesOrderedByNodeId[item]->keyType)) {
            orderNode.push_back(item);
        });
    std::sort(orderNode.begin(), orderNode.end(), [&](int a, int b) {
        return getNodeRelativePosition(a) < getNodeRelativePosition(b);
        });
    for (auto& node : orderNode) {
        ret.append(nodesOrderedByNodeId[node]->key);
        ret.push_back('\n');
    }
}
