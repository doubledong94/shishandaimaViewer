#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "SWI-cpp.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "prolog/PrologConstructor.h"
#include "prolog/PrologWrapper.h"
#include "error/ErrorManager.h"
#include "simpleView/SimpleViewLexer.h"
#include "simpleView/EasierSimpleView.h"
#include "simpleView/SimpleViewParser.h"
#include "simpleView/SimpleViewBaseVisitor.h"
#include "simpleView/visitor/SimpleViewToGraphConverter.h"
#include "res/StringRes.h"
#include "res/Images.h"
#include "res/ColorRes.h"
#include "gui/imDoubleCheckDialog.h"
#include "gui/imEditLineAndGraph.h"
#include "gui/Window.h"
#include "EditLineAndGraphWindow.h"
#include "gui/Child.h"


ShowableParam EditLineAndGraphWindow::uiStructure = {
        "Window_EditLineAndGraph",
        false,
        NULL,
        new SplitLayoutAlgo(true,{0.5f,0.5f},10,10),
        NULL,
        {
            TransparentWindowStyle::instance,
            TransparentChildStyle::instance,
            NormalStyle::instance
        },
        {
            {
                "editWindow",
                false,
                new Child(),
                NULL,
                NULL,
                {},
                {}
            },
            {
                "displayWindow",
                false,
                new Child(),
                NULL,
                NULL,
                {},
                {}
            }
        }
};

EditLineAndGraphWindow::EditLineAndGraphWindow() :Window(ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize) {
    setupParamRecur(&uiStructure);
}

void EditLineAndGraphWindow::renderContent() {
    shishan::editLineAndGraph();
}

