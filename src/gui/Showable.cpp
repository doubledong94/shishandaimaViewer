#include "util/util.h"
#include "imgui.h"
#include "hotkey/KeyEvent.h"
#include "threepp/threepp.hpp"
#include "res/ColorRes.h"
#include "Showable.h"

SplitLayoutAlgo::SplitLayoutAlgo(bool horizontal, const vector<float>& ratios, float paddingRatio, float spacingRatio) :
    horizontal(horizontal),
    ratios(ratios),
    paddingRatio(paddingRatio),
    spacingRatio(spacingRatio) {
    splitCount = ratios.size();
}

void SplitLayoutAlgo::applyLayout(Showable* parent, int index) {
    float startRatio = 0;
    float endRatio = ratios[0];
    for (int i = 1;i <= index;i++) {
        if (i % 2 == 0) {
            int j = i / 2;
            startRatio = endRatio;
            endRatio += ratios[j];
        }
    }
    if (horizontal) {
        applyLayoutHor(parent, index, startRatio, endRatio);
    } else {
        applyLayoutVer(parent, index, startRatio, endRatio);
    }
}

void SplitLayoutAlgo::applyLayoutHor(Showable* parent, int index, float startRatio, float endRatio) {
    int height = parent->height - 2 * padding;
    int width = parent->width - 2 * padding - (splitCount - 1) * spacing;
    auto& child = parent->showableParam->childParams[index].showable;
    int i = index / 2;
    // even index, it is a normal child
    if (index % 2 == 0) {
        child->left = padding + width * startRatio + i * spacing;
        child->top = padding;
        child->width = width * ratios[i];
        child->height = height;
    } else {
        // odd index, it is a child for adjusting layout
        child->left = padding + width * endRatio + i * spacing + spacing / 4;
        child->top = padding;
        child->width = spacing / 2;
        child->height = height;
    }
}

void SplitLayoutAlgo::applyLayoutVer(Showable* parent, int index, float startRatio, float endRatio) {
    int height = parent->height - 2 * padding - (splitCount - 1) * spacing;
    int width = parent->width - 2 * padding;
    auto& child = parent->showableParam->childParams[index].showable;
    int i = index / 2;
    // even index, it is a normal child
    if (index % 2 == 0) {
        child->left = padding;
        child->top = padding + height * startRatio + i * spacing;
        child->width = width;
        child->height = height * ratios[i];
    } else {
        // odd index, it is a child for adjusting layout
        child->left = padding;
        child->top = padding + height * endRatio + i * spacing + spacing / 4;
        child->width = width;
        child->height = spacing / 2;
    }
}

void SplitLayoutAlgo::onWindowResize(Showable* showable) {
    padding = paddingRatio * (horizontal ? showable->width : showable->height);
    spacing = spacingRatio * (horizontal ? showable->width : showable->height);
}

void SplitLayoutAlgo::adjust(ShowableEvent* event) {
    if (event->getType() == DragAdjustEvent::type) {
        if (horizontal) {
            adjustHor(dynamic_cast<DragAdjustEvent*>(event));
        } else {
            adjustVer(dynamic_cast<DragAdjustEvent*>(event));
        }
    }
}

void SplitLayoutAlgo::adjustHor(DragAdjustEvent* event) {
    float ratioDiff = event->dragEvent->xDiff / (event->parentWidth - 2 * padding - (splitCount - 1) * spacing);
    int i = event->childIndex / 2;
    if ((ratios[i] > 0.01f or ratioDiff > 0) and (ratios[i + 1] > 0.01f or ratioDiff < 0)) {
        ratios[i] += ratioDiff;
        ratios[i + 1] -= ratioDiff;
    }
}

void SplitLayoutAlgo::adjustVer(DragAdjustEvent* event) {
    float ratioDiff = event->dragEvent->yDiff / (event->parentHeight - 2 * padding - (splitCount - 1) * spacing);
    int i = event->childIndex / 2;
    if ((ratios[i] > 0.01f or ratioDiff > 0) and (ratios[i + 1] > 0.01f or ratioDiff < 0)) {
        ratios[i] += ratioDiff;
        ratios[i + 1] -= ratioDiff;
    }
}

PaddingLayoutAlgo::PaddingLayoutAlgo(int padding) :padding(padding) {

}

void PaddingLayoutAlgo::applyLayout(Showable* parent, int index) {
    switch (index) {
    case 0:
        auto & child = parent->showableParam->childParams[index].showable;
        child->left = padding;
        child->top = padding;
        child->width = parent->width - 2 * padding;
        child->height = parent->height - 2 * padding;
        break;
    }
}

void Showable::applyPosAndSize() {
    ImGui::SetCursorPos({ left,top });
}

void Showable::render() {
    for (auto& style : showableParam->styleComb) {
        style->pushStyle();
    }
    applyPosAndSize();
    if (showableParam->shadow) {
        addShadow(width, height);
    }
    begin();
    renderContent();
    end();
    for (auto& style : showableParam->styleComb) {
        style->popStyle();
    }
}

void Showable::addShadow(float width, float height) {
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImVec2 r(p.x + width, p.y + height);
    ImGui::GetWindowDrawList()->AddShadowRect(p, r, ImGui::GetColorU32({ 0.0f, 0.0f, 0.0f, 1.0f }), 40.0f, { 0.f,0.f }, ImDrawFlags_ShadowCutOutShapeBackground, 0.f);
}

void Showable::renderContent() {
    renderChildren();
}

void Showable::renderChildren() {
    for (auto& style : showableParam->styleCombForChild) {
        style->pushStyle();
    }
    for (auto& child : showableParam->childParams) {
        child.showable->render();
    }
    for (auto& style : showableParam->styleCombForChild) {
        style->popStyle();
    }
}

void Showable::onWindowResize() {
    if (showableParam->layoutAlgo) {
        showableParam->layoutAlgo->onWindowResize(this);
        int i = 0;
        for (auto& child : showableParam->childParams) {
            showableParam->layoutAlgo->applyLayout(this, i);
            child.showable->onWindowResize();
            i++;
        }
    }
}

Showable::Showable() {
}

void Showable::setupParamRecur(ShowableParam* showableParam) {
    this->showableParam = showableParam;
    if (this->showableParam->mediator) {
        this->showableParam->mediator->setShowable(this);
    }
    for (auto& childParam : showableParam->childParams) {
        childParam.showable->setupParamRecur(&childParam);
        childParam.showable->parent = this;
    }
}

int Showable::getChildIndex(Showable* child) {
    for (int i = 0;i < showableParam->childParams.size();i++) {
        if (child == showableParam->childParams[i].showable)
            return i;
    }
    return -1;
}

TransparentWindowStyle* TransparentWindowStyle::instance = new TransparentWindowStyle();
TransparentChildStyle* TransparentChildStyle::instance = new TransparentChildStyle();
DebugWindowStyle* DebugWindowStyle::instance = new DebugWindowStyle();
NormalStyle* NormalStyle::instance = new NormalStyle();

void TransparentWindowStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ColorRes::noBgColor);
}

void TransparentWindowStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

void DebugWindowStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ColorRes::colorRed);
}

void DebugWindowStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

void TransparentChildStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ColorRes::noBgColor);
}

void TransparentChildStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

void DebugChildStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_ChildBg, color);
}

void DebugChildStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

DebugChildStyle::DebugChildStyle(ImVec4& color) :color(color) {
}

void NormalStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ColorRes::controlPanelBgColor);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ColorRes::controlPanelBgColor);
    ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::normalTextColor);
}

void NormalStyle::popStyle() {
    ImGui::PopStyleColor(3);
}

bool AdjustMediator::handle(Showable* sender, ShowableEvent* event) {
    if (event->getType() != DragEvent::type) {
        return false;
    }
    showable->showableParam->layoutAlgo->adjust(
        new DragAdjustEvent(
            dynamic_cast<DragEvent*>(event),
            showable->getChildIndex(sender),
            showable->width,
            showable->height));
    showable->onWindowResize();
    return true;
}

void ShowableMediator::notify(Showable* sender, ShowableEvent* event) {
    if (not handle(sender, event) and next) {
        next->notify(sender, event);
    }
}

void ShowableMediator::setShowable(Showable* showable) {
    this->showable = showable;
    if (next) {
        next->setShowable(showable);
    }
}

int DragEvent::type = 1;
int DragAdjustEvent::type = 2;

int DragEvent::getType() {
    return type;
}

DragAdjustEvent::DragAdjustEvent(DragEvent* dragEvent, int childIndex, int parentWidth, int parentHeight) :
    dragEvent(dragEvent),
    childIndex(childIndex),
    parentWidth(parentWidth),
    parentHeight(parentHeight) {
}

int DragAdjustEvent::getType() {
    return type;
}
