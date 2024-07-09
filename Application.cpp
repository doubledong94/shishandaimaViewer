#include "threepp/extras/imgui/ImguiContext.hpp"
#include "threepp/threepp.hpp"
#include "threepp/scenes/Scene.hpp"
// #include <graphviz/gvc.h>
// #include <graphviz/cgraph.h>
#include "igraph.h"
#include "util/util.h"
#include "ReactiveMouseListener.h"
#include "util/Rect.h"
#include "threepp/geometries/ExtrudeGeometry.hpp"
#include "threepp/extras/core/Font.hpp"
#include "util/ThreadPool.h"
#include "threepp/materials/RawShaderMaterial.hpp"
#include "threepp/custom/FlowLine.h"
#include "threepp/custom/TwoDControls.h"
#include "threepp/custom/ThreeDControls.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "addressableInfo/GlobalInfo.h"
#include "SWI-cpp.h"
#include "prolog/PrologConstructor.h"
#include "prolog/PrologWrapper.h"
#include "threepp/custom/Nodes.h"
#include "util/timer.h"
#include "hotkey/DoubleClickStateMachine.h"
#include "threepp/custom/BoundFrame.h"
#include "threepp/custom/BoundedIncrementalGraph.h"
#include "antlr/javaParser/JavaParser.h"
#include "antlr/javaParser/JavaParserBaseVisitor.h"
#include "antlr/syntaxObject/AntlrNodeToSyntaxObjectConverter.h"
#include "antlr/visitor/HeaderEnterVisitor.h"
#include "antlr/visitor/ParseTreeToHeaderObjVisitor.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/codestructure/Sentence.h"
#include "runtime/codestructure/CodeBlock.h"
#include "runtime/ScopeAndEnv.h"
#include "antlr/visitor/RuntimeVisitor.h"
#include "Parser.h"
#include "glad/glad.h"
#include "error/ErrorManager.h"
#include "simpleView/SimpleViewLexer.h"
#include "simpleView/EasierSimpleView.h"

#include "res/StringRes.h"
#include "res/Images.h"
#include "res/ColorRes.h"
#include "gui/imfilebrowser.h"
#include "hotkey/LongPressStateMachine.h"
#include "hotkey/HotkeyConfig.h"
#include "gui/imHotKey.h"
#include "Application.h"
#include <thread>
#include <regex>
#include "simpleView/SimpleViewParser.h"
#include "simpleView/SimpleViewBaseVisitor.h"
#include "simpleView/visitor/SimpleViewToGraphConverter.h"
#include "gui/imDoubleCheckDialog.h"
#include "gui/imEditLineAndGraph.h"
#include "gui/imGraphSelector.h"
#include "gui/imDimControl.h"
#include "file/FileManager.h"
#include "threepp/helpers/AxesHelper.hpp"
#include "absl/time/clock.h"
#include "animation/AnimationUtil.h"

using namespace threepp;

app::Application::Application(app::Parser* parser1) {
    parser = parser1;
    textLoaderThreadPool = new ThreadPool(1);
}

static bool prologLoaded = false;

// this listener do things like dragging or picking
struct CanvasMouseListener : public ReactiveMouseListener {
public:
    vector<ReactiveMouseListener*>* listeners;

    CanvasMouseListener(vector<ReactiveMouseListener*>* listeners) {
        this->listeners = listeners;
    }

    void onMouseDown(int button, const Vector2& pos) override {
        for (auto* l : (*listeners)) {
            l->onMouseDown(button, pos);
        }
    }

    void onMouseUp(int button, const Vector2& pos) override {
        for (auto* l : (*listeners)) {
            l->onMouseUp(button, pos);
        }
    }

    void onMouseMove(const Vector2& pos) override {
        for (auto* l : (*listeners)) {
            l->onMouseMove(pos);
        }
    }

    void onMouseWheel(const Vector2& delta) override {
        for (auto* l : (*listeners)) {
            l->onMouseWheel(delta);
        }
    }

    void reactOnMouseEvent() override {
        for (auto* l : (*listeners)) {
            l->reactOnMouseEvent();
        }
    }
};

std::function<void(char*, vector<const char*>&)> app::Application::searchNodeInGraph;
std::function<void(set<const char*>&, vector<const char*>&)> app::Application::searchNodeByMethodOfRuntime;
std::function<void(set<const char*>&, vector<const char*>&)> app::Application::searchNodeByAddressableKey;
std::function<void(map<string, map<string, set<string>>>&, vector<const char*>&)> app::Application::searchNodeByPositionInRegex;


// double vm_usage = 0;
// double resident_set = 0;
// mem_usage(vm_usage, resident_set);
// ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ("vm usage: " + to_string(vm_usage)).data());
// ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ("resident set: " + to_string(resident_set)).data());
// ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ("total mem used: " + to_string(vm_usage + resident_set)).data());

static bool searchingInProgress = false;

int app::Application::ApplicationMain() {

    static bool hotkeyPopupOpen = false;
    static bool editLineAndGraphOpen = false;
    static bool editDimControlOpen = false;
    static bool searchedLineAndGraphOpen = false;
    static bool chooseClassScopePopupOpen = false;
    static bool chooseLineInstancePopupOpen = false;
    static bool chooseGraphInstancePopupOpen = false;
    static bool chooseLineDownPopupOpen = false;
    static bool chooseLineUpPopupOpen = false;
    static bool aboutToParseFile = false;
    static bool aboutToDeleteGraph = false;
    static bool selectByInDegreePopupOpen = false;
    static bool selectByOutDegreePopupOpen = false;
    static bool selectByDegreePopupOpen = false;
    static bool selectByMethodStackSize = false;
    static bool selectByComponentPopupOpen = false;
    static bool selectByGroupPopupOpen = false;
    static bool selectByKeyTypePopupOpen = false;
    static bool showColorSelectorWindow = false;
    static bool openParsingProgress = false;
    static bool openPopupForSaveNodes = false;
    static bool openPopupForSaveGraph = false;
    static bool showTooltip = false;
    static bool showTooltipSwitchOn = true;
    static bool showBoundFrameSwitchOn = true;
    static bool restoreGraphPopupOpen = false;
    static bool deleteGraphPopupOpen = false;

    static list<bool*> openedWindows;

    static int selected_class_scope = -1;
    static char* classScopeNames[500];
    static char* lineDownAndUp[500];
    static int lineDownAndUpCount = 0;

    static int selected_line_instance = -1;
    static int line_instance_starting_count = -1;
    static char* lineAndLineInstanceNames[500];

    static int selected_graph_instance = -1;
    static int graph_instance_starting_count = -1;
    static char* graphAndGraphInstanceNames[500];
    static char saveNodeOrGraphName[100];
    static char* nodeType[] = { "Class",
    "Field",
    "Constructor",
    "Method",
    "Parameter",
    "Return",
    "CalledMethod",
    "CalledParameter",
    "CalledReturn",
    "Condition",
    "Else",
    "Reference",
    "DataStep",
    "TimingStep",
    "DataOverride",
    "TimingOverride",
    "Index",
    "Local Variable",
    "Final Value",
    "Default Value",
    "null/true/false",
    };
    static int64_t startSearchTime = 0;
    static int searchTime = 0;

    static list<string> graphsTeBeRestored;
    static string graphToBeDeleted;

    // all hotkey functions
    HotkeyConfig::functionEnumToFunction[SHOW_EDIT_HOTKEY] = [&]() {
        showTooltip = false;
        hotkeyPopupOpen = !hotkeyPopupOpen;
        };
    HotkeyConfig::functionEnumToFunction[CHOOOSE_CLASS_SCOPE] = [&]() {
        showTooltip = false;
        chooseClassScopePopupOpen = true;
        for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size(); i++) {
            classScopeNames[i] = SimpleView::SimpleViewToGraphConverter::classScopeNameOrder[i].data();
        }
        };
    HotkeyConfig::functionEnumToFunction[UNCHOOOSE_CLASS_SCOPE] = [&]() {
        selected_class_scope = -1;
        };
    HotkeyConfig::functionEnumToFunction[CHOOSE_LINE_INSTANCE_TO_SEARCH] = [&]() {
        showTooltip = false;
        chooseLineInstancePopupOpen = true;
        line_instance_starting_count = 0;
        for (auto& lineTempalteName : SimpleView::SimpleViewToGraphConverter::lineNameOrder) {
            auto& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineTempalteName];
            if (line->lineType == SimpleView::LineTemplate::LINE_TYPE_DATA_FLOW and line->orderedParamName.empty()) {
                lineAndLineInstanceNames[line_instance_starting_count] = lineTempalteName.data();
                line_instance_starting_count++;
            }
        }
        for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size(); i++) {
            lineAndLineInstanceNames[line_instance_starting_count + i] = SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder[i].data();
        }
        };
    HotkeyConfig::functionEnumToFunction[UNCHOOSE_LINE_INSTANCE_TO_SEARCH] = [&]() {
        selected_line_instance = -1;
        };
    HotkeyConfig::functionEnumToFunction[CHOOSE_GRAPH_INSTANCE_TO_SEARCH] = [&]() {
        showTooltip = false;
        chooseGraphInstancePopupOpen = true;
        graph_instance_starting_count = 0;
        for (auto& graphTemplateName : SimpleView::SimpleViewToGraphConverter::graphNameOrder) {
            if (SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphTemplateName]->orderedParamName.empty()) {
                graphAndGraphInstanceNames[graph_instance_starting_count] = graphTemplateName.data();
                graph_instance_starting_count++;
            }
        }
        for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size(); i++) {
            graphAndGraphInstanceNames[graph_instance_starting_count + i] = SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder[i].data();
        }
        };
    HotkeyConfig::functionEnumToFunction[UNCHOOSE_GRAPH_INSTANCE_TO_SEARCH] = [&]() {
        selected_graph_instance = -1;
        };
    PL_engine_t pl_engine_for_earching = PL_create_engine(NULL);
    HotkeyConfig::functionEnumToFunction[START_SEARCHING] = [&]() {
        // search line instance
        if (searchingInProgress) {
            return;
        }
        if (selected_line_instance > -1) {
            bool isTemplate = selected_line_instance < line_instance_starting_count;
            char* lineName = lineAndLineInstanceNames[selected_line_instance];
            SimpleView::LineInstance* lineInstance = NULL;
            if (isTemplate) {
                auto& lineTemplate = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName];
                lineInstance = lineTemplate->getNoneParamInstance();
            } else {
                lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLineInstance[lineName];
            }
            spdlog::get(ErrorManager::DebugTag)->info("search line: {}; {}", lineInstance->valName.data(), lineInstance->innerValName.data());
            boundedGraph->searchingGraphName = "single lines";
            SimpleView::ClassScope* classScope = NULL;
            if (selected_class_scope > -1) {
                classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeNames[selected_class_scope]];
            }
            std::thread worker([&](SimpleView::LineInstance* lineInstance, SimpleView::ClassScope* classScope) {
                if (searchingInProgress) {
                    return;
                }
                boundedGraph->srcPos.copy(boundedGraph->getMidPosOfSelectedNodes());
                startSearchTime = absl::GetCurrentTimeNanos();
                searchingInProgress = true;
                printf("PL_set_engine: %d\n", PL_set_engine(pl_engine_for_earching, NULL));
                lineInstance->startSearching(classScope, &loadingAddressableProgress, &loadingUnaddressableProgress);
                vector<Tail*> result = lineInstance->queryNext(classScope);
                int count = 0;
                boundedGraph->layoutAnimating = true;
                while (not result.empty()) {
                    boundedGraph->addBuffers(result);
                    count++;
                    result.clear();
                    result = lineInstance->queryNext(classScope);
                    boundedGraph->returnDoneBufferToPool();
                }
                while (boundedGraph->bufferSize()) {
                    boundedGraph->returnDoneBufferToPool();
                }
                lineInstance->endSearching(classScope);
                spdlog::get(ErrorManager::DebugTag)->info("prolog result count: {}", count);
                printf("PL_set_engine: %d\n", PL_set_engine(NULL, NULL));
                searchingInProgress = false;
                }, lineInstance, classScope);
            worker.detach();
        }
        // search graph instance
        if (selected_graph_instance > -1) {
            bool isTemplate = selected_graph_instance < graph_instance_starting_count;
            char* graphName = graphAndGraphInstanceNames[selected_graph_instance];
            SimpleView::GraphInstance* graphInstance = NULL;
            if (isTemplate) {
                auto& graphTemplate = SimpleView::SimpleViewToGraphConverter::valNameToGraph[graphName];
                graphInstance = graphTemplate->getNoneParamInstance();
                spdlog::get(ErrorManager::DebugTag)->info("search graph template: {}; {}", graphTemplate->valName.data(), graphTemplate->innerValName.data());
            } else {
                graphInstance = SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance[graphName];
                spdlog::get(ErrorManager::DebugTag)->info("search line instance: {}; {}", graphInstance->valName.data(), graphInstance->innerValName.data());
            }
            boundedGraph->searchingGraphName = graphInstance->valName;
            SimpleView::ClassScope* classScope = NULL;
            if (selected_class_scope > -1) {
                classScope = SimpleView::SimpleViewToGraphConverter::valNameToClassScope[classScopeNames[selected_class_scope]];
            }
            std::thread worker([&](SimpleView::GraphInstance* graphInstance, SimpleView::ClassScope* classScope) {
                if (searchingInProgress) {
                    return;
                }
                boundedGraph->srcPos.copy(boundedGraph->getMidPosOfSelectedNodes());
                startSearchTime = absl::GetCurrentTimeNanos();
                searchingInProgress = true;
                printf("PL_set_engine: %d\n", PL_set_engine(pl_engine_for_earching, NULL));
                graphInstance->startSearching(classScope, &loadingAddressableProgress, &loadingUnaddressableProgress);
                vector<Tail*> result = graphInstance->queryNext(classScope);
                int count = 0;
                boundedGraph->layoutAnimating = true;
                while (not result.empty()) {
                    boundedGraph->addBuffers(result);
                    count++;
                    result.clear();
                    result = graphInstance->queryNext(classScope);
                    boundedGraph->returnDoneBufferToPool();
                }
                while (boundedGraph->bufferSize()) {
                    boundedGraph->returnDoneBufferToPool();
                }
                graphInstance->endSearching(classScope);
                spdlog::get(ErrorManager::DebugTag)->info("prolog result count: {}", count);
                printf("PL_set_engine: %d\n", PL_set_engine(NULL, NULL));
                searchingInProgress = false;
                }, graphInstance, classScope);
            worker.detach();
        }
        };
    static vector<const char*> methodOfRuntimeForNodeSelection;
    static map<string, map<string, list<string>>> graphNameToLineNameToRegex;
    HotkeyConfig::functionEnumToFunction[SHOW_SEARCHED_LINE_AND_GRAPH] = [&]() {
        showTooltip = false;
        shishan::showGraphList = false;
        shishan::forceRelayout();
        shishan::clearSelectedNode();
        methodOfRuntimeForNodeSelection.clear();
        graphNameToLineNameToRegex.clear();
        FOR_EACH_ITEM(boundedGraph->methodOfRuntimeToNodeInfo, methodOfRuntimeForNodeSelection.push_back(item.first.data()););
        for (auto& graphName : boundedGraph->graphNameToLineNameToRegexToNodeInfo) {
            graphNameToLineNameToRegex[graphName.first] = map<string, list<string>>();
            for (auto& lineName : graphName.second) {
                graphNameToLineNameToRegex[graphName.first][lineName.first] = list<string>();
                for (auto& regex : lineName.second) {
                    graphNameToLineNameToRegex[graphName.first][lineName.first].push_back(regex.first);
                }
            }
        }
        searchedLineAndGraphOpen = !searchedLineAndGraphOpen;};
    HotkeyConfig::functionEnumToFunction[SHOW_EDIT_LINE_AND_GRAPH] = [&]() {
        showTooltip = false;
        shishan::showGraphList = false;
        shishan::forceRelayout();
        editLineAndGraphOpen = !editLineAndGraphOpen;};
    HotkeyConfig::functionEnumToFunction[CHANGE_MAX_SEARCH_DEPTH] = [&]() {
        SimpleView::RegexTree::changeMaxRecurDepth();
        };
    HotkeyConfig::functionEnumToFunction[PARSE_FILE] = [&]() {
        if (not parser->parsing and not FileManager::srcPath.empty() and not openParsingProgress) {
            showTooltip = false;
            aboutToParseFile = true;
        }
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_KEY_TYPE] = [&]() {
        showTooltip = false;
        selectByKeyTypePopupOpen = true;
        };

    Canvas canvas(StringRes::singleton->getAppName(), { {"antialiasing", 4} ,{"exitOnKeyEscape", false} });
    GLRenderer renderer(canvas.size());
    static float colorWidgetWidth = 0.f;

    auto scene = Scene::create();
    scene->background = ColorRes::mainWindowBgColor;
    auto camera = PerspectiveCamera::create(60, canvas.aspect(), 0.001f, 100000);
    camera->position.z = 50;
    TwoDControls twoDControls(*camera, canvas);
    twoDControls.enabled = true;
    ThreeDControls threeDControls(*camera, canvas);
    threeDControls.enableKeys = false;
    threeDControls.enabled = false;

    HotkeyConfig::functionEnumToFunction[TO_2D_LAYOUT] = [&]() {
        twoDControls.enabled = true;
        threeDControls.enabled = false;
        twoDControls.reset();
        camera->up.set(0, 1, 0);
        camera->position.set(0, 0, camera->position.length());
        camera.get()->lookAt({ 0,0,0 });
        boundedGraph->set2DLayout(true);
        boundedGraph->position.set(0, 0, 0);
        boundedGraph->layoutAnimating = true;
        };
    HotkeyConfig::functionEnumToFunction[TO_3D_LAYOUT] = [&]() {
        twoDControls.enabled = false;
        threeDControls.enabled = true;
        threeDControls.reset();
        camera->up.set(0, 1, 0);
        camera->position.set(0, 0, camera->position.length());
        camera.get()->lookAt({ 0,0,0 });
        boundedGraph->set2DLayout(false);
        boundedGraph->position.set(0, 0, 0);
        boundedGraph->layoutAnimating = true;
        };
    HotkeyConfig::functionEnumToFunction[INCREASE_TEMPERATURE] = [&]() {
        boundedGraph->increaseTemperature();
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_TEMPERATURE] = [&]() {
        boundedGraph->decreaseTemperature();
        };
    HotkeyConfig::functionEnumToFunction[START_OR_STOP_LAYOUT_ANIM] = [&]() {
        boundedGraph->startOrStopLayoutAnimating();
        };
    HotkeyConfig::functionEnumToFunction[BIGGER_NODE] = [&]() {
        boundedGraph->increaseNodeSize();
        };
    HotkeyConfig::functionEnumToFunction[SMALLER_NODE] = [&]() {
        boundedGraph->decreaseNodeSize();
        };
    HotkeyConfig::functionEnumToFunction[WIDER_LINE] = [&]() {
        boundedGraph->increaseLineWidth();
        };
    HotkeyConfig::functionEnumToFunction[THINNER_LINE] = [&]() {
        boundedGraph->decreaseLineWidth();
        };
    HotkeyConfig::functionEnumToFunction[INCREASE_ALPHA_FOR_UNSELECTED] = [&]() {
        boundedGraph->increaseDecreaseAlphaForUnselected(true);
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_ALPHA_FOR_UNSELECTED] = [&]() {
        boundedGraph->increaseDecreaseAlphaForUnselected(false);
        };
    HotkeyConfig::functionEnumToFunction[INCREASE_ALPHA_FOR_SELECTED] = [&]() {
        boundedGraph->increaseDecreaseAlphaForSelected(true);
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_ALPHA_FOR_SELECTED] = [&]() {
        boundedGraph->increaseDecreaseAlphaForSelected(false);
        };
    HotkeyConfig::functionEnumToFunction[SELECT_FROM_ALL] = [&]() {
        if (boundedGraph->selectedFromAll) {
            boundedGraph->selectedFromAll = false;
        } else {
            boundedGraph->selectedFromAll = true;
        }
        };
    HotkeyConfig::functionEnumToFunction[DIM_CONTROL_EDITOR] = [&]() {
        showTooltip = false;
        shishan::dimControlLastWindowSize = { 0,0 };
        editDimControlOpen = !editDimControlOpen;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_ALL_NODE] = [&]() {
        boundedGraph->selectAll();
        };
    HotkeyConfig::functionEnumToFunction[UNSELECT_ALL] = [&]() {
        boundedGraph->unselectAll();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_UPWARD] = [&]() {
        boundedGraph->selectUpward();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_DOWNWARD] = [&]() {
        boundedGraph->selectDownward();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_UPWARD_TO_THE_TOP] = [&]() {
        boundedGraph->selectUpwardToTheTop();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_DOWNWARD_TO_THE_BOTTOM] = [&]() {
        boundedGraph->selectDownwardToTheBottom();
        };
    HotkeyConfig::functionEnumToFunction[REVERSE_SELECT] = [&]() {
        boundedGraph->reverseSelect();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_PATH_IN_BETWEEN] = [&]() {
        boundedGraph->selectPathInBetween();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_PATH_UPWARD] = [&]() {
        boundedGraph->selectPathUpward();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_PATH_DOWNWARD] = [&]() {
        boundedGraph->selectPathDownward();
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_IN_DEGREE] = [&]() {
        boundedGraph->prepareInDegreeMap();
        showTooltip = false;
        selectByInDegreePopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_OUT_DEGREE] = [&]() {
        boundedGraph->prepareOutDegreeMap();
        showTooltip = false;
        selectByOutDegreePopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_DEGREE] = [&]() {
        boundedGraph->prepareDegreeMap();
        showTooltip = false;
        selectByDegreePopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_METHOD_SATCK_SIZE] = [&]() {
        boundedGraph->prepareSelectByMethodStackSize();
        showTooltip = false;
        selectByMethodStackSize = true;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_COMPONENT] = [&]() {
        boundedGraph->prepareComponent();
        showTooltip = false;
        selectByComponentPopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[SELECT_BY_GROUP] = [&]() {
        showTooltip = false;
        selectByGroupPopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[FLOW_COLOR_MAP] = [&]() {
        boundedGraph->flowColor();
        };
    HotkeyConfig::functionEnumToFunction[CLEAR_ALL_COLOR] = [&]() {
        boundedGraph->clearSpecifiedColor();
        };
    HotkeyConfig::functionEnumToFunction[REMOVE_SELECTED_NODES] = [&]() {
        boundedGraph->removeSelectedNodes();
        shishan::searchResults2.clear();
        };
    HotkeyConfig::functionEnumToFunction[REMOVE_ALL_NODES] = [&]() {
        boundedGraph->removeAllNodes();
        shishan::searchResults2.clear();
        };
    HotkeyConfig::functionEnumToFunction[FIX_POSITION] = [&]() {
        boundedGraph->fixPosition();
        };
    HotkeyConfig::functionEnumToFunction[RELEASE_POSITION] = [&]() {
        boundedGraph->releasePosition();
        };
    HotkeyConfig::functionEnumToFunction[UNFIX_ALL_NODE] = [&]() {
        boundedGraph->releaseAllPosition();
        };
    HotkeyConfig::functionEnumToFunction[SET_COLOR] = [&]() {
        showColorSelectorWindow = !showColorSelectorWindow;
        };
    HotkeyConfig::functionEnumToFunction[SHOW_AND_HIDE_TEXT] = [&]() {
        boundedGraph->toggleShowSimpleText();
        };
    HotkeyConfig::functionEnumToFunction[INCREASE_NODE_TEXT_SIZE] = [&]() {
        boundedGraph->changeTextSize(true);
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_NODE_TEXT_SIZE] = [&]() {
        boundedGraph->changeTextSize(false);
        };
    HotkeyConfig::functionEnumToFunction[INCREASE_WEIGHT] = [&]() {
        boundedGraph->changeWeightForSelectedNode(true);
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_WEIGHT] = [&]() {
        boundedGraph->changeWeightForSelectedNode(false);
        };
    HotkeyConfig::functionEnumToFunction[RESET_WEIGHT] = [&]() {
        boundedGraph->resetWeight();
        };
    HotkeyConfig::functionEnumToFunction[GROUP] = [&]() {
        boundedGraph->groupSelectedNodes(boundedGraph->groups);
        };
    HotkeyConfig::functionEnumToFunction[UNGROUP] = [&]() {
        boundedGraph->ungroupSelectedNodes(boundedGraph->groups);
        };
    HotkeyConfig::functionEnumToFunction[UNGROUP_ALL_NODE] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->groups);
        };
    HotkeyConfig::functionEnumToFunction[SAVE_SELECTED_NODE] = [&]() {
        showTooltip = false;
        openPopupForSaveNodes = true;
        };
    HotkeyConfig::functionEnumToFunction[SAVE_GRAPH] = [&]() {
        showTooltip = false;
        openPopupForSaveGraph = true;
        };
    HotkeyConfig::functionEnumToFunction[RESTORE_GRAPH] = [&]() {
        showTooltip = false;
        restoreGraphPopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[DELETE_SAVED_GRAPH] = [&]() {
        showTooltip = false;
        deleteGraphPopupOpen = true;
        };
    HotkeyConfig::functionEnumToFunction[SHOW_AND_HIDE_TOOLTIP] = [&]() {
        showTooltipSwitchOn = !showTooltipSwitchOn;
        };
    HotkeyConfig::functionEnumToFunction[SEARCH_DOWNWARD] = [&]() {
        showTooltip = false;
        chooseLineDownPopupOpen = true;
        lineDownAndUpCount = 0;
        for (auto& lineTempalteName : SimpleView::SimpleViewToGraphConverter::lineNameOrder) {
            auto& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineTempalteName];
            if (line->orderedParamName.empty()) {
                lineDownAndUp[lineDownAndUpCount] = lineTempalteName.data();
                lineDownAndUpCount++;
            }
        }
        };
    HotkeyConfig::functionEnumToFunction[SEARCH_UPWARD] = [&]() {
        showTooltip = false;
        chooseLineUpPopupOpen = true;
        lineDownAndUpCount = 0;
        for (auto& lineTempalteName : SimpleView::SimpleViewToGraphConverter::lineNameOrder) {
            auto& line = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineTempalteName];
            if (line->orderedParamName.empty()) {
                lineDownAndUp[lineDownAndUpCount] = lineTempalteName.data();
                lineDownAndUpCount++;
            }
        }
        };
    HotkeyConfig::functionEnumToFunction[TRANSITIVE_REDUCTION] = [&]() {
        boundedGraph->transitiveReduction();
        };
    HotkeyConfig::functionEnumToFunction[FIX_X_COORD] = [&]() {
        boundedGraph->groupSelectedNodes(boundedGraph->xCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[RELEASE_X_COORD] = [&]() {
        boundedGraph->ungroupSelectedNodes(boundedGraph->xCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[RELEASE_ALL_X_COORD] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->xCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[FIX_Y_COORD] = [&]() {
        boundedGraph->groupSelectedNodes(boundedGraph->yCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[RELEASE_Y_COORD] = [&]() {
        boundedGraph->ungroupSelectedNodes(boundedGraph->yCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[RELEASE_ALL_Y_COORD] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->yCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[BOUND_SELECTED_NODE] = [&]() {
        boundedGraph->groupSelectedNodes(boundedGraph->bounds);
        boundedGraph->resetBounds();
        };
    HotkeyConfig::functionEnumToFunction[UNBOUND_SELECTED_NODE] = [&]() {
        boundedGraph->ungroupSelectedNodes(boundedGraph->bounds);
        boundedGraph->resetBounds();
        };
    HotkeyConfig::functionEnumToFunction[UNBOUND_UNSELECTED_NODE] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->bounds);
        boundedGraph->resetBounds();
        };
    HotkeyConfig::functionEnumToFunction[BOUND_BY_CLASS] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->bounds);
        boundedGraph->boundByClass();
        boundedGraph->resetBounds();
        };
    HotkeyConfig::functionEnumToFunction[BOUND_BY_METHOD] = [&]() {
        boundedGraph->ungroupAllNodes(boundedGraph->bounds);
        boundedGraph->boundByMethod();
        boundedGraph->resetBounds();
        };
    HotkeyConfig::functionEnumToFunction[AUTO_GROUP_X] = [&]() {
        boundedGraph->grid(boundedGraph->xCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[AUTO_GROUP_Y] = [&]() {
        boundedGraph->grid(boundedGraph->yCoordFixed);
        };
    HotkeyConfig::functionEnumToFunction[AUTO_GROUP_XY] = [&]() {
        boundedGraph->grid(boundedGraph->groups);
        };

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
        colorWidgetWidth = size.width / 5;
        });
    colorWidgetWidth = canvas.size().width / 5;

    CanvasMouseListener canvasMouseListener(&listeners);
    canvas.addMouseListener(canvasMouseListener);
    raycaster.params.lineThreshold = 0.1f;

    static int cameraAnimToken = -1;

    boundedGraph = BoundedIncrementalGraph::create(&canvas, camera.get(), &raycaster, &listeners, &twoDControls, &threeDControls);
    boundedGraph->onFocusOn = [&](threepp::Vector2 offset) {
        cameraAnimToken = AnimationUtil::addAnimation({ 0,0,0 }, { offset.x,offset.y,0 });
        };
    static string tip;
    boundedGraph->showTooltip = [&](string& s) {
        tip = s;
        showTooltip = showTooltipSwitchOn;
        };
    boundedGraph->hideTooltip = [&]() {
        showTooltip = false;
        };
    scene->add(boundedGraph);

    HotkeyConfig::functionEnumToFunction[SHOW_AND_HIDE_BOUND_FRAME] = [&]() {
        showBoundFrameSwitchOn = !showBoundFrameSwitchOn;
        boundedGraph->showAndHideBoundFrame(showBoundFrameSwitchOn);
        };

    std::function<void()> restoreGraph = []() {};

    bool show_demo_window = false;
    auto ui = ImguiFunctionalContext(canvas.windowPtr(), [&] {
        if (show_demo_window) {
            ImGui::ShowDemoWindow(&show_demo_window);
        }
        ImGuiIO& io = ImGui::GetIO();

        if (!hotkeyPopupOpen and
            !editLineAndGraphOpen and
            !editDimControlOpen and
            !searchedLineAndGraphOpen and
            !aboutToParseFile and
            !aboutToDeleteGraph and
            !parser->parsing and
            !openPopupForSaveNodes and
            !openPopupForSaveGraph) {
            HotkeyConfig::onFrame();
        }

        if (showTooltip) {
            showTooltip = not (
                ImGui::IsPopupOpen("selectByInDegreePopupOpen") or
                ImGui::IsPopupOpen("selectByOutDegreePopupOpen") or
                ImGui::IsPopupOpen("selectByDegreePopupOpen") or
                ImGui::IsPopupOpen("selectByMethodStackSize") or
                ImGui::IsPopupOpen("selectByComponentPopupOpen") or
                ImGui::IsPopupOpen("selectByGroupPopupOpen") or
                ImGui::IsPopupOpen("selectByKeyTypePopupOpen") or
                ImGui::IsPopupOpen("chooseLineDownAndUpPopupOpen") or
                ImGui::IsPopupOpen("chooseClassScopePopup") or
                ImGui::IsPopupOpen("chooseLineInstancePopup") or
                ImGui::IsPopupOpen("chooseGraphInstancePopup") or
                ImGui::IsPopupOpen("parsingProgress") or
                ImGui::IsPopupOpen("saveNodeNameInput") or
                ImGui::IsPopupOpen("saveGraphNameInput") or
                ImGui::IsPopupOpen("restoreGraphPopupOpen") or
                ImGui::IsPopupOpen("deleteGraphPopupOpen")
                );
        }
        if (showTooltip) {
            ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always, ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y), ImGuiCond_Always);
            ImGui::Begin("foTooltips", NULL, ImGuiWindowFlags_NoTitleBar
                | ImGuiWindowFlags_NoResize
                | ImGuiWindowFlags_NoMove
                | ImGuiWindowFlags_NoScrollbar
                | ImGuiWindowFlags_NoScrollWithMouse
                | ImGuiWindowFlags_NoCollapse
                | ImGuiWindowFlags_NoBackground
                | ImGuiWindowFlags_NoSavedSettings
                | ImGuiWindowFlags_NoMouseInputs
                | ImGuiWindowFlags_NoFocusOnAppearing
                | ImGuiWindowFlags_NoBringToFrontOnFocus
                | ImGuiWindowFlags_NoNavInputs
                | ImGuiWindowFlags_NoNavFocus
                | ImGuiWindowFlags_NoNav
                | ImGuiWindowFlags_NoDecoration
                | ImGuiWindowFlags_NoInputs
            );
            ImGui::SetTooltip(tip.data());
            ImGui::End();
        }

        if (ImGui::IsKeyReleased(ImGuiKey::ImGuiKey_Escape)) {
            if (editLineAndGraphOpen) {
                // exit from line and graph editor
                if (prologLoaded and not searchingInProgress) {
                    EasierSimpleView::saveToFile();
                }
            }
            if (searchedLineAndGraphOpen) {
                // exit from selector
                set<const char*> uniKeys;
                for (int i : shishan::nodeKeySelectedIndex) {
                    uniKeys.insert(shishan::searchResults2[i]);
                }
                boundedGraph->select(uniKeys);
            }
            if (editDimControlOpen) {
                // exit form dim control
                ofstream f;
                f.open(FileManager::dimControlConfig);
                shishan::dimControlToFile(f);
                f.close();
            }
            hotkeyPopupOpen = false;
            editLineAndGraphOpen = false;
            editDimControlOpen = false;
            searchedLineAndGraphOpen = false;
            showColorSelectorWindow = false;
            aboutToParseFile = false;
            aboutToDeleteGraph = false;
            openPopupForSaveNodes = false;
            openPopupForSaveGraph = false;
        }

        if (aboutToParseFile) {
            showDoubleCheckDialog("are you sure to parse src", &aboutToParseFile, [&]() {
                if (!parser->parsing) {
                    std::thread parserWorker([](Application* app, char* dir) { app->parser->parse(dir); }, this, FileManager::srcPath.data());
                    parserWorker.detach();
                    openParsingProgress = true;
                }
                });
        }
        if (aboutToDeleteGraph) {
            showDoubleCheckDialog("are you sure to delete graph", &aboutToDeleteGraph, [&]() {
                FileManager::deleteFile(FileManager::graphSaveAndRestorePath + graphToBeDeleted);
                });
        }

        shishan::editLineAndGraph(editLineAndGraphOpen);
        shishan::showGraphSelectorWindow(searchedLineAndGraphOpen, methodOfRuntimeForNodeSelection, graphNameToLineNameToRegex);
        shishan::showDimControlWindow(editDimControlOpen);

        if (selectByInDegreePopupOpen) {
            ImGui::OpenPopup("selectByInDegreePopupOpen");
            selectByInDegreePopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByInDegreePopupOpen")) {
            ImGui::SeparatorText("select by in degree");
            for (auto& degreeAndNodes : boundedGraph->inDegreeToNodes.data) {
                string s = to_string(degreeAndNodes.first) + "  [" + to_string(degreeAndNodes.second.size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(degreeAndNodes.second);
                }
            }
            ImGui::EndPopup();
        }
        if (selectByOutDegreePopupOpen) {
            ImGui::OpenPopup("selectByOutDegreePopupOpen");
            selectByOutDegreePopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByOutDegreePopupOpen")) {
            ImGui::SeparatorText("select by out degree");
            for (auto& degreeAndNodes : boundedGraph->outDegreeToNodes.data) {
                string s = to_string(degreeAndNodes.first) + "  [" + to_string(degreeAndNodes.second.size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(degreeAndNodes.second);
                }
            }
            ImGui::EndPopup();
        }
        if (selectByDegreePopupOpen) {
            ImGui::OpenPopup("selectByDegreePopupOpen");
            selectByDegreePopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByDegreePopupOpen")) {
            ImGui::SeparatorText("select by in degree");
            for (auto& degreeAndNodes : boundedGraph->degreeToNodes.data) {
                string s = to_string(degreeAndNodes.first) + "  [" + to_string(degreeAndNodes.second.size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(degreeAndNodes.second);
                }
            }
            ImGui::EndPopup();
        }
        if (selectByMethodStackSize) {
            ImGui::OpenPopup("selectByMethodStackSize");
            selectByMethodStackSize = false;
        }
        if (ImGui::BeginPopup("selectByMethodStackSize")) {
            ImGui::SeparatorText("select by method stack size");
            for (auto& stackSizeAndNodes : boundedGraph->methodStackSizeToNodes.data) {
                string s = to_string(stackSizeAndNodes.first) + "  [" + to_string(stackSizeAndNodes.second.size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(stackSizeAndNodes.second);
                }
            }
            ImGui::EndPopup();
        }
        if (restoreGraphPopupOpen) {
            ImGui::OpenPopup("restoreGraphPopupOpen");
            FileManager::getFileNameInDir(FileManager::graphSaveAndRestorePath, graphsTeBeRestored);
            restoreGraphPopupOpen = false;
        }
        if (ImGui::BeginPopup("restoreGraphPopupOpen")) {
            ImGui::SeparatorText("select graph to restore");
            for (auto& g : graphsTeBeRestored) {
                if (ImGui::Selectable(g.data())) {
                    restoreGraph = [&, g]() {
                        ifstream* f = new ifstream;
                        f->open(FileManager::graphSaveAndRestorePath + g);
                        boundedGraph->fromFile(*f);
                        };
                };
            }
            ImGui::EndPopup();
        }
        if (deleteGraphPopupOpen) {
            ImGui::OpenPopup("deleteGraphPopupOpen");
            FileManager::getFileNameInDir(FileManager::graphSaveAndRestorePath, graphsTeBeRestored);
            deleteGraphPopupOpen = false;
        }
        if (ImGui::BeginPopup("deleteGraphPopupOpen")) {
            ImGui::SeparatorText("select graph to delete");
            for (auto& g : graphsTeBeRestored) {
                if (ImGui::Selectable(g.data())) {
                    graphToBeDeleted = g;
                    aboutToDeleteGraph = true;
                };
            }
            ImGui::EndPopup();
        }
        if (selectByComponentPopupOpen) {
            ImGui::OpenPopup("selectByComponentPopupOpen");
            selectByComponentPopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByComponentPopupOpen")) {
            ImGui::SeparatorText("select by component");
            for (int i = 0;i < boundedGraph->orderedByComponentSize.size();i++) {
                set<int>* component = boundedGraph->orderedByComponentSize[i];
                string s = to_string(i) + "  [" + to_string((*component).size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(*component);
                }
            }
            ImGui::EndPopup();
        }
        if (selectByGroupPopupOpen) {
            ImGui::OpenPopup("selectByGroupPopupOpen");
            selectByGroupPopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByGroupPopupOpen")) {
            ImGui::SeparatorText("select by group");
            int i = 0;
            int lastGroupCount = i;
            for (;i < boundedGraph->groups.size() + lastGroupCount;i++) {
                string s = to_string(i) + "  [" + to_string(boundedGraph->groups[i].size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(boundedGraph->groups[i]);
                }
            }
            lastGroupCount = i;
            for (;i < boundedGraph->xCoordFixed.size() + lastGroupCount;i++) {
                string s = to_string(i) + "  [" + to_string(boundedGraph->xCoordFixed[i].size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(boundedGraph->xCoordFixed[i]);
                }
            }
            lastGroupCount = i;
            for (;i < boundedGraph->yCoordFixed.size() + lastGroupCount;i++) {
                string s = to_string(i) + "  [" + to_string(boundedGraph->yCoordFixed[i].size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(boundedGraph->yCoordFixed[i]);
                }
            }
            lastGroupCount = i;
            for (;i < boundedGraph->bounds.size() + lastGroupCount;i++) {
                string s = to_string(i) + "  [" + to_string(boundedGraph->bounds[i].size()) + "]";
                if (ImGui::Selectable(s.data())) {
                    boundedGraph->select(boundedGraph->bounds[i]);
                }
            }
            ImGui::EndPopup();
        }
        if (selectByKeyTypePopupOpen) {
            ImGui::OpenPopup("selectByKeyTypePopupOpen");
            selectByKeyTypePopupOpen = false;
        }
        if (ImGui::BeginPopup("selectByKeyTypePopupOpen")) {
            ImGui::SeparatorText("select by key type");
            for (int i = 0;i < 20;i++) {
                if (ImGui::Selectable(nodeType[i])) {
                    boundedGraph->selectByKeyType(i);
                }
            }
            ImGui::EndPopup();
        }
        static bool lineDown = false;
        if (chooseLineDownPopupOpen or chooseLineUpPopupOpen) {
            lineDown = chooseLineDownPopupOpen;
            ImGui::OpenPopup("chooseLineDownAndUpPopupOpen");
            chooseLineDownPopupOpen = false;
            chooseLineUpPopupOpen = false;
        }
        if (ImGui::BeginPopup("chooseLineDownAndUpPopupOpen")) {
            if (lineDown) {
                ImGui::SeparatorText("choose a line down");
            } else {
                ImGui::SeparatorText("choose a line up");
            }
            for (int i = 0;i < lineDownAndUpCount;i++) {
                shishan::putIcon(SimpleView::SimpleViewToGraphConverter::valNameToLine[lineDownAndUp[i]]->iconId, ImGui::GetFontSize());
                if (ImGui::Selectable(lineDownAndUp[i])) {
                    list<tuple<string, string, string, int, string>> runtimeNodes = boundedGraph->getSelectedRuntime();
                    if (runtimeNodes.empty()) {
                        continue;
                    }
                    char* lineName = lineDownAndUp[i];
                    SimpleView::LineInstance* lineInstance = SimpleView::SimpleViewToGraphConverter::valNameToLine[lineName]->getNoneParamInstance()->copy();
                    lineInstance->addRuntimeNode(runtimeNodes, lineDown);
                    spdlog::get(ErrorManager::DebugTag)->info("search line: {}; {}", lineInstance->valName.data(), lineInstance->innerValName.data());
                    boundedGraph->searchingGraphName = "single lines";
                    std::thread worker([&](SimpleView::LineInstance* lineInstance, bool lineDown) {
                        if (searchingInProgress) {
                            return;
                        }
                        boundedGraph->srcPos.copy(boundedGraph->getMidPosOfSelectedNodes());
                        startSearchTime = absl::GetCurrentTimeNanos();
                        searchingInProgress = true;
                        printf("PL_set_engine: %d\n", PL_set_engine(pl_engine_for_earching, NULL));
                        lineInstance->startSearching(NULL, &loadingAddressableProgress, &loadingUnaddressableProgress);
                        vector<Tail*> result = lineInstance->queryNext(NULL);
                        int count = 0;
                        boundedGraph->layoutAnimating = true;
                        while (not result.empty()) {
                            boundedGraph->addBuffers(result);
                            count++;
                            result.clear();
                            result = lineInstance->queryNext(NULL);
                            boundedGraph->returnDoneBufferToPool();
                        }
                        while (boundedGraph->bufferSize()) {
                            boundedGraph->returnDoneBufferToPool();
                        }
                        lineInstance->endSearching(NULL);
                        spdlog::get(ErrorManager::DebugTag)->info("prolog result count: {}", count);
                        printf("PL_set_engine: %d\n", PL_set_engine(NULL, NULL));
                        searchingInProgress = false;
                        lineInstance->removeRuntimeNode(lineDown);
                        }, lineInstance, lineDown);
                    worker.detach();
                }
            }
            ImGui::EndPopup();
        }

        if (chooseClassScopePopupOpen) {
            ImGui::OpenPopup("chooseClassScopePopup");
            chooseClassScopePopupOpen = false;
        }
        if (ImGui::BeginPopup("chooseClassScopePopup")) {
            ImGui::SeparatorText("choose a class scope");
            for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::classScopeNameOrder.size(); i++) {
                shishan::putIcon(Images::classScopeIconId, ImGui::GetFontSize());
                if (ImGui::Selectable(classScopeNames[i])) {
                    selected_class_scope = i;
                }
            }
            ImGui::EndPopup();
        }
        if (chooseLineInstancePopupOpen) {
            ImGui::OpenPopup("chooseLineInstancePopup");
            chooseLineInstancePopupOpen = false;
        }
        if (ImGui::BeginPopup("chooseLineInstancePopup")) {
            ImGui::SeparatorText("choose a line");
            for (int i = 0; i < line_instance_starting_count; i++) {
                shishan::putIcon(Images::lineIconId, ImGui::GetFontSize());
                if (ImGui::Selectable(lineAndLineInstanceNames[i])) {
                    selected_line_instance = i;
                    selected_graph_instance = -1;
                }
            }
            for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder.size(); i++) {
                shishan::putIcon(Images::instanceIconId, ImGui::GetFontSize());
                if (ImGui::Selectable(lineAndLineInstanceNames[line_instance_starting_count + i])) {
                    selected_line_instance = line_instance_starting_count + i;
                    selected_graph_instance = -1;
                }
            }
            ImGui::EndPopup();
        }

        if (chooseGraphInstancePopupOpen) {
            ImGui::OpenPopup("chooseGraphInstancePopup");
            chooseGraphInstancePopupOpen = false;
        }
        if (ImGui::BeginPopup("chooseGraphInstancePopup")) {
            ImGui::SeparatorText("choose a graph");
            for (int i = 0; i < graph_instance_starting_count; i++) {
                shishan::putIcon(Images::graphIconId, ImGui::GetFontSize());
                if (ImGui::Selectable(graphAndGraphInstanceNames[i])) {
                    selected_graph_instance = i;
                    selected_line_instance = -1;
                }
            }
            for (int i = 0; i < SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder.size(); i++) {
                shishan::putIcon(Images::instanceIconId, ImGui::GetFontSize());
                if (ImGui::Selectable(graphAndGraphInstanceNames[graph_instance_starting_count + i])) {
                    selected_graph_instance = graph_instance_starting_count + i;
                    selected_line_instance = -1;
                }
            }
            ImGui::EndPopup();
        }

        ImHotKey::Edit(HotkeyConfig::hotkeys.data(), HotkeyConfig::hotkeys.size(), StringRes::singleton->getHotkeyEditor(), hotkeyPopupOpen);

        bool showStatusBar = not hotkeyPopupOpen and not searchedLineAndGraphOpen;

        if (showStatusBar) {
            ImGui::SetNextWindowBgAlpha(0.3f);
            ImGui::SetNextWindowPos({ io.DisplaySize.x - 10,io.DisplaySize.y - 10 }, ImGuiCond_Always, { 1.0f,1.0f });
            if (ImGui::Begin("status bar", &showStatusBar, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove)) {
                ImGui::Text("node count %d", boundedGraph->getNodeCount());
                ImGui::Text("edge count  %d", boundedGraph->getEdgeCount());
                ImGui::Text("layout animation %s", boundedGraph->layoutAnimating ? "on" : "off");
                ImGui::Text("layout temperature %.3f", boundedGraph->getLayoutTemperature());
                if (boundedGraph->selectedFromAll) {
                    ImGui::Text("select from all");
                } else {
                    ImGui::Text("select from selected");
                }
                ImGui::Text("search depth %s", SimpleView::RegexTree::maxRecurDepthStr.data());
                ImGui::Text(StringRes::singleton->getHint_press1ToShowHotkey());
            }
            ImGui::End();
        }

        if (showStatusBar) {
            ImGui::SetNextWindowBgAlpha(0.3f);
            ImGui::SetNextWindowPos({ 10,io.DisplaySize.y - 10 }, ImGuiCond_Always, { 0.0f,1.0f });
            if (ImGui::Begin("status bar2", &showStatusBar, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove)) {
                if (selected_class_scope > -1) {
                    ImGui::Text("class scope: %s", classScopeNames[selected_class_scope]);
                }
                if (selected_line_instance > -1) {
                    ImGui::Text("current search: %s", lineAndLineInstanceNames[selected_line_instance]);
                }
                if (selected_graph_instance > -1) {
                    ImGui::Text("current search: %s", graphAndGraphInstanceNames[selected_graph_instance]);
                }
                if (searchingInProgress) {
                    searchTime = (absl::GetCurrentTimeNanos() - startSearchTime) / 1000000000;
                    int minute = searchTime / 60;
                    int seconds = searchTime % 60;
                    ImGui::Text(("search in progress: " + to_string(minute) + "m " + to_string(seconds) + "s").data());
                }
            }
            ImGui::End();
        }

        static ImVec4 color = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
        if (showColorSelectorWindow) {
            ImGui::SetNextWindowBgAlpha(0.3f);
            ImGui::SetNextWindowPos({ io.DisplaySize.x - 10, 10 }, ImGuiCond_Always, { 1.0f,0.0f });
            if (ImGui::Begin("color selector", &showColorSelectorWindow, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoMove)) {
                ImGui::SetNextItemWidth(colorWidgetWidth);
                if (ImGui::ColorPicker3("##colorSelector", (float*)&color, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoAlpha)) {
                    boundedGraph->setColorForSeletedNode(color.x, color.y, color.z);
                }
            }
            ImGui::End();
        }

        float fontSize = ImGui::GetFontSize();
        if (openParsingProgress) {
            float dialogWidth = 30 * fontSize;
            float dialogHeight = 10 * fontSize;
            ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
            ImGui::SetNextWindowSize(ImVec2(dialogWidth, dialogHeight), ImGuiCond_Always);
            ImGui::OpenPopup("parsingProgress");
            openParsingProgress = false;
        }
        if (ImGui::BeginPopupModal("parsingProgress")) {
            ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), "\"done\" will be shown on progress bar when parsing is done, restart app after pasing is done");
            ImGui::ProgressBar(parser->getProgressPass1(), ImVec2(0.f, 0.f), parser->getProgressTextPass1().data());
            ImGui::ProgressBar(parser->getProgressPass2(), ImVec2(0.f, 0.f), parser->getProgressTextPass2().data());
            ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 1.0f), parser->getParseTime().data());
            ImGui::EndPopup();
        }
        if (openPopupForSaveNodes) {
            float dialogWidth = 15 * fontSize;
            float dialogHeight = 5 * fontSize;
            ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
            ImGui::SetNextWindowSize(ImVec2(dialogWidth, dialogHeight), ImGuiCond_Always);
            ImGui::OpenPopup("saveNodeNameInput");
        }
        if (ImGui::BeginPopupModal("saveNodeNameInput", &openPopupForSaveNodes, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {
            ImGui::Text("input node name and press enter");
            if (ImGui::InputTextEx("##saveNodeName", "", saveNodeOrGraphName, 100, { 15 * fontSize,fontSize * 1.5 }, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_EnterReturnsTrue)) {
                string s = saveNodeOrGraphName;
                if (not s.empty() and shishan::checkValNameCommon(saveNodeOrGraphName)) {
                    SimpleView::SimpleViewToGraphConverter::addNode(s, boundedGraph->getSelectedKey());
                    saveNodeOrGraphName[0] = '\0';
                }
                openPopupForSaveNodes = false;
            }
            ImGui::SetKeyboardFocusHere(-1);
            ImGui::EndPopup();
        }
        if (openPopupForSaveGraph) {
            float dialogWidth = 15 * fontSize;
            float dialogHeight = 5 * fontSize;
            ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
            ImGui::SetNextWindowSize(ImVec2(dialogWidth, dialogHeight), ImGuiCond_Always);
            ImGui::OpenPopup("saveGraphNameInput");
        }
        if (ImGui::BeginPopupModal("saveGraphNameInput", &openPopupForSaveGraph, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize)) {
            ImGui::Text("input graph name and press enter");
            if (ImGui::InputTextEx("##saveGraphName", "", saveNodeOrGraphName, 100, { 15 * fontSize,fontSize * 1.5 }, ImGuiInputTextFlags_CharsNoBlank | ImGuiInputTextFlags_EnterReturnsTrue)) {
                string s = saveNodeOrGraphName;
                if (not s.empty() and shishan::checkValNameCommon(saveNodeOrGraphName)) {
                    ofstream f;
                    f.open(FileManager::graphSaveAndRestorePath + s);
                    boundedGraph->toFile(f);
                    f.close();
                    saveNodeOrGraphName[0] = '\0';
                }
                openPopupForSaveGraph = false;
            }
            ImGui::SetKeyboardFocusHere(-1);
            ImGui::EndPopup();
        }
        bool isShowLoadingAddressableDialog = loadingAddressableIndex > 0;
        if (isShowLoadingAddressableDialog) {
            showProgressDialog("loading addressable", &isShowLoadingAddressableDialog, loadingAddressableIndex, loadingAddressableTotal, loadingAddressableName);
        }
        bool isShowLoadingUnaddressableDialog = loadingUnaddressableIndex > 0;
        if (isShowLoadingUnaddressableDialog) {
            showProgressDialog("loading runtime", &isShowLoadingUnaddressableDialog, loadingUnaddressableIndex, loadingUnaddressableTotal, loadingUnaddressableName);
        }
        });

    Images::init();
    if (prologLoaded) {
        EasierSimpleView::init();
    }

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.Fonts->AddFontFromFileTTF(FileManager::fontFileOTFPath.data(), 45.0f, NULL, io.Fonts->GetGlyphRangesChineseSimplifiedCommon());
    // change font size dynamically
    // io.FontGlobalScale = 2;
    // change ui size dynamically
    // ImGui::GetStyle().ScaleAllSizes(3.f);
    ImGui::GetStyle().ScrollbarSize = 30.f;
    io.IniFilename = FileManager::imguiIniFile.data();

    HotkeyConfig::functionEnumToFunction[INCREASE_GUI_TEXT_SIZE] = [&]() {
        io.FontGlobalScale += 0.05f;
        };
    HotkeyConfig::functionEnumToFunction[DECREASE_GUI_TEXT_SIZE] = [&]() {
        io.FontGlobalScale -= 0.05f;
        };

    IOCapture capture{};
    capture.preventMouseEvent = [] {
        return ImGui::GetIO().WantCaptureMouse;
        };
    capture.preventScrollEvent = [] {
        return ImGui::GetIO().WantCaptureMouse;
        };
    capture.preventKeyboardEvent = [] {
        return ImGui::GetIO().WantCaptureKeyboard;
        };
    canvas.setIOCapture(&capture);


    auto f = [&]() {
        restoreGraph();
        restoreGraph = []() {};
        for (auto* l : listeners) {
            l->reactOnMouseEvent();
        }
        AnimationUtil::upadteAnim();
        AnimationUtil::applyAnimAction(cameraAnimToken, [&](AnimValue currentValue,AnimValue lastValue) {
            if (twoDControls.enabled) {
                twoDControls.pan(currentValue.x - lastValue.x, currentValue.y - lastValue.y);
            }
            if (threeDControls.enabled) {
                threeDControls.pan(currentValue.x - lastValue.x, currentValue.y - lastValue.y);
            }
            });
        boundedGraph->updateAnim(*camera);
        glClear(GL_COLOR_BUFFER_BIT);
        renderer.render(*scene, *camera);
        ui.render();
        };

    searchNodeInGraph = [&](char* searchStr, vector<const char*>& searchResult) {
        boundedGraph->searchNodeInGraph(searchStr, searchResult);
        };
    searchNodeByMethodOfRuntime = [&](set<const char*>& methodOfRuntime, vector<const char*>& searchResult) {
        boundedGraph->searchNodeByMethodOfRuntime(methodOfRuntime, searchResult);
        };
    searchNodeByAddressableKey = [&](set<const char*>& addressableKey, vector<const char*>& searchResult) {
        boundedGraph->searchNodeByAddressableKey(addressableKey, searchResult);
        };
    searchNodeByPositionInRegex = [&](map<string, map<string, set<string>>>& positionInRegex, vector<const char*>& searchResult) {
        boundedGraph->searchNodeByPositionInRegex(positionInRegex, searchResult);
        };

    // const auto axes = AxesHelper::create(10);
    // scene->add(axes);

    bool continueAnim = true;
    while (continueAnim) {
        try {
            continueAnim = canvas.animateOnce(f);
            if (threeDControls.enableDamping and threeDControls.enabled) {
                threeDControls.update();
            }
        } catch (const std::bad_function_call& e) {
            std::cout << e.what() << '\n';
            continueAnim = true;
        }
    }

    PL_destroy_engine(pl_engine_for_earching);
    boundedGraph->dispose();
    return 0;
}

int main(int argc, char** argv) {
    FileManager::initCurrentDir();
    StringRes::singleton = new EnglishStringRes();
    string swi_env = "SWI_HOME_DIR=" + FileManager::baseFolder + "external/swipl/home";
    putenv(swi_env.data());
    ErrorManager::init();
    prologLoaded = PrologWrapper::init();
    PrologConstructor::init();
    app::Parser parser;
    HotkeyConfig::loadHotkeyConfig(FileManager::hotkeyConfig);
    ifstream ifs;
    ifs.open(FileManager::dimControlConfig);
    shishan::dimControlFromFile(ifs);
    ifs.close();
    BoundedIncrementalGraph::getDimControl = shishan::getDimControl;
    BoundedIncrementalGraph::deserializeFilePath();
    app::Application app(&parser);
    app.ApplicationMain();
    if (prologLoaded and not searchingInProgress) {
        EasierSimpleView::saveToFile();
    }
    ofstream ofs;
    ofs.open(FileManager::dimControlConfig);
    shishan::dimControlToFile(ofs);
    ofs.close();
    HotkeyConfig::saveHotkeyConfig(FileManager::hotkeyConfig);
}

shishan::DimControlSetting::DimControlSetting(const string& name) {
    this->name = name;
}

void shishan::DimControlSetting::toFile(ofstream& f) {
    f << name << "\n";
    f << (chosen_constructor ? 1 : 0) << "\n";
    f << (chosen_method ? 1 : 0) << "\n";
    f << (chosen_parameter ? 1 : 0) << "\n";
    f << (chosen_return ? 1 : 0) << "\n";
    f << (chosen_calledMethod ? 1 : 0) << "\n";
    f << (chosen_calledParameter ? 1 : 0) << "\n";
    f << (chosen_calledReturn ? 1 : 0) << "\n";
    f << (chosen_condition ? 1 : 0) << "\n";
    f << (chosen_else ? 1 : 0) << "\n";
    f << (chosen_reference ? 1 : 0) << "\n";
    f << (chosen_dataStep ? 1 : 0) << "\n";
    f << (chosen_dataOverride ? 1 : 0) << "\n";
    f << (chosen_timingStep ? 1 : 0) << "\n";
    f << (chosen_timingOverride ? 1 : 0) << "\n";
    f << (chosen_index ? 1 : 0) << "\n";
}

void shishan::DimControlSetting::fromFile(ifstream& f) {
    getline(f, name);
    chosen_constructor = getInt(f);
    chosen_method = getInt(f);
    chosen_parameter = getInt(f);
    chosen_return = getInt(f);
    chosen_calledMethod = getInt(f);
    chosen_calledParameter = getInt(f);
    chosen_calledReturn = getInt(f);
    chosen_condition = getInt(f);
    chosen_else = getInt(f);
    chosen_reference = getInt(f);
    chosen_dataStep = getInt(f);
    chosen_dataOverride = getInt(f);
    chosen_timingStep = getInt(f);
    chosen_timingOverride = getInt(f);
    chosen_index = getInt(f);
}




