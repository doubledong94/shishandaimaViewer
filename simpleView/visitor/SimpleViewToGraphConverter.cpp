#include "../../util/util.h"
#include "../SimpleViewLexer.h"
#include "../SimpleViewBaseVisitor.h"
#include "SWI-cpp.h"
#include "../../addressableInfo/GlobalInfo.h"
#include "../../antlr/syntaxObject/JavaHeaderFile.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "../../prolog/PrologConstructor.h"
#include "../../prolog/PrologWrapper.h"
#include "../../error/ErrorManager.h"
#include "../EasierSimpleView.h"
#include "SimpleViewToGraphConverter.h"
#include "../../res/Images.h"
// #include <graphviz/gvc.h>
// #include <graphviz/cgraph.h>

void SimpleView::SimpleViewToGraphConverter::release() {
}

void SimpleView::SimpleViewToGraphConverter::addNode(const string& name, const list<pair<string, string>>& key) {
    if (name.empty()) {
        return;
    }
    if (key.empty()) {
        return;
    }
    if (valNameToNode.count(name)) {
        return;
    }
    Node* node = new Node();
    node->iconId = Images::listIconId;
    node->displayName = name;
    node->displayText = name;
    node->nodeType = Node::NODE_TYPE_LIST;
    for (auto& k : key) {
        node->nodeList.push_back({ k.first,k.second });
    }
    node->updateDisplayText();
    valNameToNode[name] = node;
    nodeNameOrder.insert(nodeNameOrder.begin(), name);
}

any SimpleView::SimpleViewToGraphConverter::visitCompilationUnit(SimpleViewParser::CompilationUnitContext* ctx) {
    SimpleViewBaseVisitor::visitCompilationUnit(ctx);
    return 0;
}


map<string, SimpleView::NodeStyle*> SimpleView::SimpleViewToGraphConverter::valNameToNodeStyle;
map<string, SimpleView::BasicStyle*> SimpleView::SimpleViewToGraphConverter::valNameToBasicNodeStyle;

vector<string> SimpleView::SimpleViewToGraphConverter::classScopeNameOrder;
vector<string> SimpleView::SimpleViewToGraphConverter::nodeNameOrder;
vector<string> SimpleView::SimpleViewToGraphConverter::lineNameOrder;
vector<string> SimpleView::SimpleViewToGraphConverter::graphNameOrder;
vector<string> SimpleView::SimpleViewToGraphConverter::lineInstanceNameOrder;
vector<string> SimpleView::SimpleViewToGraphConverter::graphInstanceNameOrder;
map<string, SimpleView::ClassScope*> SimpleView::SimpleViewToGraphConverter::valNameToClassScope;
map<string, SimpleView::Node*> SimpleView::SimpleViewToGraphConverter::valNameToNode;

map<string, SimpleView::LineTemplate*> SimpleView::SimpleViewToGraphConverter::valNameToLine;
map<string, SimpleView::GraphTemplate*> SimpleView::SimpleViewToGraphConverter::valNameToGraph;

map<string, SimpleView::LineInstance*> SimpleView::SimpleViewToGraphConverter::valNameToLineInstance;
map<string, SimpleView::GraphInstance*> SimpleView::SimpleViewToGraphConverter::valNameToGraphInstance;

any SimpleView::SimpleViewToGraphConverter::visitClassScopeExp(SimpleViewParser::ClassScopeExpContext* ctx) {
    if (ctx->refOtherScope != nullptr) {
        return valNameToClassScope[ctx->IDENTIFIER()->getText()];
    } else if (ctx->bracket != nullptr) {
        return visitClassScopeExp(ctx->bracket);
    } else {
        auto* classScope = new ClassScope();
        if (ctx->classKey != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_KEY;
            classScope->extraStr = REMOVE_QUOTATION(ctx->classKey->getText());
        }
        if (ctx->classKeyList != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_LIST;
            for (auto& s : ctx->STRING()) {
                classScope->classList.push_back(REMOVE_QUOTATION(s->getText()));
            }
        }
        if (ctx->IN_PACKAGE() != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_IN_PACKAGE;
            classScope->extraStr = REMOVE_QUOTATION(ctx->packageStr->getText());
        }
        if (ctx->USED_BY() != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_USED_BY;
            classScope->referenceClassScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        }
        if (ctx->USE() != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_USE;
            classScope->referenceClassScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        }
        if (ctx->SUPER() != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_SUPER;
            classScope->referenceClassScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        }
        if (ctx->SUB() != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_SUB;
            classScope->referenceClassScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        }
        if (ctx->intersection != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_INTERSECTION;
            classScope->operandForSetOperation =
            { any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0))),
             any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(1))) };
        }
        if (ctx->union_ != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_UNION;
            classScope->operandForSetOperation =
            { any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0))),
             any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(1))) };
        }
        if (ctx->difference != nullptr) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_DIFFERENCE;
            classScope->operandForSetOperation =
            { any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0))),
             any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(1))) };
        }
        if (ctx->varClass) {
            classScope->classScopeType = ClassScope::CLASS_SCOPE_TYPE_VAR;
            classScope->referenceClassScope = valNameToClassScope[ctx->IDENTIFIER()->getText()];
        }
        classScope->iconId = SimpleView::ClassScope::classTypeToIconId[classScope->classScopeType];
        return classScope;
    }
}

any SimpleView::SimpleViewToGraphConverter::visitClassScopeDeclaration(SimpleViewParser::ClassScopeDeclarationContext* ctx) {
    ClassScope* classScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp()));
    classScope->displayName = ctx->IDENTIFIER()->getText();
    classScope->updateDisplayText();
    valNameToClassScope[ctx->IDENTIFIER()->getText()] = classScope;
    classScopeNameOrder.push_back(ctx->IDENTIFIER()->getText());
    return 0;
}

any SimpleView::SimpleViewToGraphConverter::visitNodeDeclaration(SimpleViewParser::NodeDeclarationContext* ctx) {
    Node* node = any_cast<Node*>(visitNodeExp(ctx->nodeExp()));
    node->displayName = ctx->IDENTIFIER()->getText();
    node->updateDisplayText();
    valNameToNode[ctx->IDENTIFIER()->getText()] = node;
    nodeNameOrder.push_back(ctx->IDENTIFIER()->getText());
    return 0;
}

any SimpleView::SimpleViewToGraphConverter::visitNodeExp(SimpleViewParser::NodeExpContext* ctx) {
    if (ctx->refOtherNode != nullptr) {
        return valNameToNode[ctx->IDENTIFIER()->getText()];
    } else if (ctx->bracket != nullptr) {
        return visitNodeExp(ctx->bracket);
    } else {
        Node* ret = new Node();
        if (ctx->nodeKey != nullptr) {
            ret->nodeType = Node::NODE_TYPE_KEY;
            ret->nodeKey = { REMOVE_QUOTATION(ctx->nodeKey->getText()),REMOVE_QUOTATION(ctx->typeKey->getText()) };
        } else if (ctx->nodeKeyList != nullptr) {
            ret->nodeType = Node::NODE_TYPE_LIST;
            for (int i = 1;i < ctx->STRING().size();i++) {
                if (i % 2 == 1) {
                    ret->nodeList.push_back({ REMOVE_QUOTATION(ctx->STRING(i - 1)->getText()),REMOVE_QUOTATION(ctx->STRING(i)->getText()) });
                }
            }
        } else if (ctx->FIELD_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_FIELD_OF;
            ret->classScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        } else if (ctx->METHOD_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_METHOD_OF;
            ret->classScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        } else if (ctx->PARAMETER_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_PARAMETER_OF;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->methodNode));
        } else if (ctx->RETURN_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_RETURN_OF;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->methodNode));
        } else if (ctx->INSTANCE_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_INSTANCE_OF;
            ret->classScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
            ret->classScope2 = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(1)));
        } else if (ctx->CREATOR() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_CREATOR;
            ret->classScope = any_cast<ClassScope*>(visitClassScopeExp(ctx->classScopeExp(0)));
        } else if (ctx->SUPER() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_SUPER;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->node));
        } else if (ctx->SUB() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_SUB;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->node));
        } else if (ctx->CALLED_METHOD_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_CALLED_METHOD_OF;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->methodNode));
        } else if (ctx->CALLED_PARAM_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_CALLED_PARAMETER_OF;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->paramNode));
        } else if (ctx->CALLED_RETURN_OF() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_CALLED_RETURN_OF;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->returnNode));
        } else if (ctx->union_ != nullptr) {
            ret->nodeType = Node::NODE_TYPE_UNION;
            ret->operandForSetOperation = {
                    any_cast<Node*>(visitNodeExp(ctx->nodeExp(0))),
                    any_cast<Node*>(visitNodeExp(ctx->nodeExp(1)))
            };
        } else if (ctx->intersection != nullptr) {
            ret->nodeType = Node::NODE_TYPE_INTERSECTION;
            ret->operandForSetOperation = { any_cast<Node*>(visitNodeExp(ctx->nodeExp(0))),
                                           any_cast<Node*>(visitNodeExp(ctx->nodeExp(1))) };
        } else if (ctx->difference != nullptr) {
            ret->nodeType = Node::NODE_TYPE_DIFFERENCE;
            ret->operandForSetOperation = { any_cast<Node*>(visitNodeExp(ctx->nodeExp(0))),
                                           any_cast<Node*>(visitNodeExp(ctx->nodeExp(1))) };
        } else if (ctx->READ() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_READ;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->read));
        } else if (ctx->WRITE() != nullptr) {
            ret->nodeType = Node::NODE_TYPE_WRITE;
            ret->referenceNode = any_cast<Node*>(visitNodeExp(ctx->write));
        } else if (ctx->ANY() != nullptr) {
            ret = Node::NODE_ANY;
        } else if (ctx->FINAL() != nullptr) {
            ret = Node::NODE_FINAL;
        } else if (ctx->CLASS() != nullptr) {
            ret = Node::NODE_CLASS;
        } else if (ctx->REFERENCE() != nullptr) {
            ret = Node::NODE_REFERENCE;
        } else if (ctx->DATA_STEP() != nullptr) {
            ret = Node::NODE_DATA_STEP;
        } else if (ctx->TIMING_STEP() != nullptr) {
            ret = Node::NODE_TIMING_STEP;
        } else if (ctx->DATA_OVERRIDE() != nullptr) {
            ret = Node::NODE_DATA_OVERRIDE;
        } else if (ctx->TIMING_OVERRIDE() != nullptr) {
            ret = Node::NODE_TIMING_OVERRIDE;
        } else if (ctx->CONDITION() != nullptr) {
            ret = Node::NODE_CONDITION;
        } else if (ctx->ELSE()) {
            ret = Node::NODE_ELSE;
        } else if (ctx->FIELD()) {
            ret = Node::NODE_FIELD;
        } else if (ctx->METHOD()) {
            ret = Node::NODE_METHOD;
        } else if (ctx->CONSTRUCTOR()) {
            ret = Node::NODE_CONSTRUCTOR;
        } else if (ctx->CALLED_METHOD()) {
            ret = Node::NODE_CALLED_METHOD;
        } else if (ctx->PARAMETER()) {
            ret = Node::NODE_PARAMETER;
        } else if (ctx->CALLED_PARAMETER()) {
            ret = Node::NODE_CALLED_PARAMETER;
        } else if (ctx->RETURN()) {
            ret = Node::NODE_RETURN;
        } else if (ctx->CALLED_RETURN()) {
            ret = Node::NODE_CALLED_RETURN;
        } else if (ctx->INDEX()) {
            ret = Node::NODE_INDEX;
        } else if (ctx->ERROR()) {
            ret = Node::NODE_ERROR;
        } else if (ctx->varNode) {
            ret->nodeType = Node::NODE_TYPE_VAR;
            ret->referenceNode = valNameToNode[ctx->IDENTIFIER()->getText()];
        }
        ret->iconId = SimpleView::Node::nodeTypeToIconId[ret->nodeType];
        return ret;
    }
}

any SimpleView::SimpleViewToGraphConverter::visitLineSegOrNodeExp(SimpleViewParser::LineSegOrNodeExpContext* ctx) {
    auto* nodeAndRepeatType = new NodeAndRepeatType();
    // repeat type
    int repeatType = -1;
    if (ctx->wildcard == nullptr) {
        repeatType = LineTemplate::REPEAT_TYPE_ONE;
    } else {
        if (ctx->wildcard->getText() == "?") {
            repeatType = LineTemplate::REPEAT_TYPE_ZERO_OR_ONE;
        } else if (ctx->wildcard->getText() == "*") {
            repeatType = LineTemplate::REPEAT_TYPE_ZERO_OR_MORE;
        } else if (ctx->wildcard->getText() == "+") {
            repeatType = LineTemplate::REPEAT_TYPE_ONE_OR_MORE;
        }
    }
    nodeAndRepeatType->repeatType = repeatType;
    if (ctx->segName != nullptr) {
        nodeAndRepeatType->seg = valNameToLine[ctx->segName->getText()];
    } else if (ctx->nodeExp() != nullptr) {
        nodeAndRepeatType->node = any_cast<Node*>(visitNodeExp(ctx->nodeExp()));
    }
    return nodeAndRepeatType;
}

any SimpleView::SimpleViewToGraphConverter::visitLineDeclaration(SimpleViewParser::LineDeclarationContext* ctx) {
    int lineType = -1;
    bool isAlt = false;
    if (ctx->LINE() != NULL) {
        lineType = SimpleView::LineTemplate::LINE_TYPE_DATA_FLOW;
    } else if (ctx->CODE_ORDER() != NULL) {
        lineType = SimpleView::LineTemplate::LINE_TYPE_CODE_ORDER;
    } else if (ctx->SEGMENT() != NULL) {
        lineType = SimpleView::LineTemplate::LINE_TYPE_SEGMENT;
        isAlt = ctx->lineExp()->alt != NULL;
    }
    LineTemplate* pLine = new LineTemplate(ctx->IDENTIFIER()->getText(), lineType);
    pLine->isAlternation = isAlt;
    // line param
    vector<string> orderedParamInnerName;
    pLine->orderedParamName.clear();
    if (ctx->paramList() != nullptr) {
        for (auto* lineParam : ctx->paramList()->IDENTIFIER()) {
            const string& paramName = lineParam->getText();
            if (not valNameToNode.count(paramName)) {
                valNameToNode[paramName] = new Node();
            }
            Node* paramNode = valNameToNode[paramName];
            paramNode->iconId = Images::parameterIconId;
            paramNode->displayName = paramName;
            paramNode->nodeType = Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
            paramNode->extraStr = paramName;
            pLine->orderedParamName.push_back(paramName);
            orderedParamInnerName.push_back(paramNode->innerValName);
        }
    }
    // line body
    for (auto* lineSeg : ctx->lineExp()->lineSegOrNodeExp()) {
        auto* nodeAndRepeatType = any_cast<NodeAndRepeatType*>(visitLineSegOrNodeExp(lineSeg));
        pLine->nodeAndRepeatType.push_back(nodeAndRepeatType);
    }
    pLine->displayName = ctx->IDENTIFIER()->getText() + (pLine->orderedParamName.empty() ? "" : "(" + joinVector(pLine->orderedParamName, ",") + ")");
    pLine->updateDisplayText();
    pLine->updateIconId();
    pLine->encode();
    valNameToLine[ctx->IDENTIFIER()->getText()] = pLine;
    lineNameOrder.push_back(ctx->IDENTIFIER()->getText());
    return 0;
}

any SimpleView::SimpleViewToGraphConverter::visitGraphDeclaration(SimpleViewParser::GraphDeclarationContext* ctx) {
    string valName = ctx->graphName->getText();
    auto* pGraph = new GraphTemplate(valName);
    // graph param
    vector<string> orderedParamInnerName;
    if (ctx->paramList() != nullptr) {
        for (auto* lineParam : ctx->paramList()->IDENTIFIER()) {
            const string& paramName = lineParam->getText();
            if (not valNameToNode.count(paramName)) {
                valNameToNode[paramName] = new Node();
            }
            Node* paramNode = valNameToNode[paramName];
            paramNode->iconId = Images::parameterIconId;
            paramNode->displayName = paramName;
            paramNode->nodeType = Node::NODE_TYPE_PARAM_OF_LINE_AND_GRAPH;
            paramNode->extraStr = paramName;
            pGraph->orderedParamName.push_back(paramName);
            orderedParamInnerName.push_back(paramNode->innerValName);
        }
    }

    // graph body
    for (auto* graphElementCtx : ctx->graphBody()->graphElement()) {
        LineInstance* pLineInstance = nullptr;
        vector<string> argumentNames;
        if (graphElementCtx->lineName != nullptr) {
            if (graphElementCtx->lineArgumentList() != nullptr) {
                FOR_EACH_ITEM(graphElementCtx->lineArgumentList()->IDENTIFIER(),
                    argumentNames.push_back(item->getText());
                    );
            }
            pLineInstance = new LineInstance(valNameToLine[graphElementCtx->IDENTIFIER()->getText()], argumentNames);
            pLineInstance->valName = graphElementCtx->IDENTIFIER()->getText();
        }
        pGraph->lineInstances.push_back(pLineInstance);
    }
    for (auto& point : ctx->intersectionPoint()) {
        vector<IntersectionPointInLine*> p;
        FOR_EACH_ITEM(point->pointInLine(), p.push_back(any_cast<IntersectionPointInLine*>(visitPointInLine(item))););
        pGraph->intersectionPointsInLine.push_back(p);
    }
    pGraph->updateDisplayName();
    valNameToGraph[valName] = pGraph;
    graphNameOrder.push_back(valName);
    return 0;
}

any SimpleView::SimpleViewToGraphConverter::visitPointInLine(SimpleViewParser::PointInLineContext* ctx) {
    auto* p = new IntersectionPointInLine();
    if (ctx->INT()) {
        p->isIntersection = ctx->INT()->getText() == "1";
        p->isSeg = false;
    } else {
        for (auto& pi : ctx->pointInLine()) {
            p->seg.push_back(any_cast<IntersectionPointInLine*>(visitPointInLine(pi)));
        }
        p->isSeg = true;
    }
    return p;
}

any SimpleView::SimpleViewToGraphConverter::visitLineAndGraphInstance(SimpleViewParser::LineAndGraphInstanceContext* ctx) {
    string valName = ctx->IDENTIFIER(0)->getText();
    vector<string> args;
    for (auto& argCtx : ctx->lineArgumentList()->IDENTIFIER()) {
        args.push_back(argCtx->getText());
    }
    if (ctx->LINE_INSTANCE()) {
        auto lineInstance = new LineInstance(SimpleView::SimpleViewToGraphConverter::valNameToLine[ctx->IDENTIFIER(1)->getText()], args);
        lineInstance->valName = valName;
        lineInstance->updateDisplayName();
        SimpleViewToGraphConverter::valNameToLineInstance[valName] = lineInstance;
        SimpleViewToGraphConverter::lineInstanceNameOrder.push_back(valName);
    } else {
        auto graphInstance = new GraphInstance(SimpleView::SimpleViewToGraphConverter::valNameToGraph[ctx->IDENTIFIER(1)->getText()], args);
        graphInstance->valName = valName;
        graphInstance->updateDisplayName();
        SimpleViewToGraphConverter::valNameToGraphInstance[valName] = graphInstance;
        SimpleViewToGraphConverter::graphInstanceNameOrder.push_back(valName);
    }
    return 0;
}

any SimpleView::SimpleViewToGraphConverter::visitShowCommand(SimpleViewParser::ShowCommandContext* ctx) {
    string graphValName = ctx->graphName->getText();
    GraphTemplate* pGraph = valNameToGraph[graphValName];
    pGraph->setDefaultAndBasicStyle(valNameToNodeStyle[ctx->defaultStyleName->getText()], valNameToBasicNodeStyle[ctx->basicStyleName->getText()]);
    showingGraph.push_back(graphValName);
    return 0;
}

void SimpleView::SimpleViewErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const string& msg, std::exception_ptr e) {
    easyPrint("xxxxxx line:", to_string(line));
    easyPrint("xxxxxx pos:", to_string(charPositionInLine));
    easyPrint("xxxxxx msg:", msg);

}

void SimpleView::clearAllAddedFacts() {
    PrologWrapper::retractAllFact(HEAD_RESOLVE->toString(), 2);
}

void SimpleView::clearAllAddedRules() {
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_USED_BY->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_USE->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_SUPER->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_SUB->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_UNION->toString(), 3);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_INTERSECTION->toString(), 3);
    PrologWrapper::retractAllRule(HEAD_CLASS_SCOPE_DIFFERENCE->toString(), 3);

    PrologWrapper::retractAllRule(HEAD_NODE_FIELD_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_METHOD_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_INSTANCE_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_PARAMETER_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_RETURN_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_CALLED_METHOD_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_CALLED_PARAMETER_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_CALLED_RETURN_OF->toString(), 2);
    PrologWrapper::retractAllRule(HEAD_NODE_UNION->toString(), 3);
    PrologWrapper::retractAllRule(HEAD_NODE_INTERSECTION->toString(), 3);
    PrologWrapper::retractAllRule(HEAD_NODE_DIFFERENCE->toString(), 3);

    PrologWrapper::retractAllRule(HEAD_RESOLVE_RUNTIME->toString(), 4);
    PrologWrapper::retractAllRule(HEAD_RESOLVE_RUNTIME_CHECK->toString(), 4);

    PrologWrapper::retractAllRule(HEAD_RESOLVE->toString(), 2);
}
