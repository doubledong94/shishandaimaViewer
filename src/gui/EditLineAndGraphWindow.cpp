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
#include "gui/Button.h"
#include "gui/AdjustButton.h"
#include "gui/Child.h"

EditLineAndGraphWindow::EditLineAndGraphWindow() :Window(ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize) {
    uiStructure = {
            "Window_EditLineAndGraph",
            false,
            NULL,
            new SplitLayoutAlgo(true,{0.7f,0.3f},0.005,0.015),
            new AdjustMediator(),
            {
                // TransparentWindowStyle::instance,
                // TransparentChildStyle::instance,
                DebugWindowStyle::instance,
                new DebugChildStyle(ColorRes::colorBlue4),
                NormalStyle::instance
            },
            {

            },
            {
                {
                    "editWindow",
                    false,
                    new Child(),
                    new SplitLayoutAlgo(false,{0.25f,0.25f,0.25f,0.25},0.01,0.02),
                    new AdjustMediator(),
                    {},
                    {
                        new DebugChildStyle(ColorRes::colorBlue1),
                    },
                    {
                        {
                            "classWindow",
                            true,
                            new Child(),
                            NULL,
                            NULL,
                        },
                        {
                            "##heightAdjust1",
                            false,
                            new AdjustButton(),
                            NULL,
                            NULL,
                        },
                        {
                            "nodeWindow",
                            true,
                            new Child(),
                            NULL,
                            NULL,
                            {}
                        },
                        {
                            "##heightAdjust2",
                            false,
                            new AdjustButton(),
                            NULL,
                            NULL,
                        },
                        {
                            "lineWindow",
                            true,
                            new Child(),
                            NULL,
                            NULL,
                            {}
                        },
                        {
                            "##heightAdjust3",
                            false,
                            new AdjustButton(),
                            NULL,
                            NULL,
                        },
                        {
                            "graphWindow",
                            true,
                            new Child(),
                            NULL,
                            NULL,
                            {}
                        }
                    }
                },
                {
                    "##widthAdjust",
                    false,
                    new AdjustButton(),
                    NULL,
                    NULL,
                    {},
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
                    {},
                    {}
                }
            }
    };
    setupParamRecur(&uiStructure);
}


