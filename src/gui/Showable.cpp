#include "util/util.h"
#include "imgui.h"
#include "hotkey/KeyEvent.h"
#include "threepp/threepp.hpp"
#include "res/ColorRes.h"
#include "Showable.h"

SplitLayoutAlgo::SplitLayoutAlgo(bool horizontal, const vector<float>& ratios, int padding, int spacing) : horizontal(horizontal), ratios(ratios), padding(padding), spacing(spacing) {
    splitCount = ratios.size();
}

void SplitLayoutAlgo::applyLayout(Showable* parent, int index) {
    
}

PaddingLayoutAlgo::PaddingLayoutAlgo(int padding) :padding(padding) {

}

void PaddingLayoutAlgo::applyLayout(Showable* parent, int index) {
    switch (index) {
    case 0:
        auto & showable = parent->showableParam[index].showable;
        showable->left = padding;
        showable->top = padding;
        showable->width = parent->width - 2 * padding;
        showable->height = parent->height - 2 * padding;
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
    for (auto& child : showableParam->childParams) {
        child.showable->render();
    }
}

void Showable::onWindowResize() {
    if (showableParam->layoutAlgo) {
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
    for (auto& childParam : showableParam->childParams) {
        childParam.showable->setupParamRecur(&childParam);
    }
}

TransparentWindowStyle* TransparentWindowStyle::instance = new TransparentWindowStyle();
TransparentChildStyle* TransparentChildStyle::instance = new TransparentChildStyle();
NormalStyle* NormalStyle::instance = new NormalStyle();

void TransparentWindowStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ColorRes::noBgColor);
}

void TransparentWindowStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

void TransparentChildStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ColorRes::noBgColor);
}

void TransparentChildStyle::popStyle() {
    ImGui::PopStyleColor(1);
}

void NormalStyle::pushStyle() {
    ImGui::PushStyleColor(ImGuiCol_PopupBg, ColorRes::controlPanelBgColor);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ColorRes::controlPanelBgColor);
    ImGui::PushStyleColor(ImGuiCol_Text, ColorRes::normalTextColor);
}

void NormalStyle::popStyle() {
    ImGui::PopStyleColor(3);
}



