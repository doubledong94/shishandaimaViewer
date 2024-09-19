#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "Window.h"

Window::Window(int flag) : flag(flag) {
    ImGui::GetStyle().WindowShadowSize = 0;
    ImGui::GetStyle().WindowBorderSize = 0;
}

void Window::applyPosAndSize() {
    ImGui::SetNextWindowPos(ImVec2(left, top), ImGuiCond_Always, ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Always);
}

void Window::onWindowResize() {
    this->width = windowWidth * widthRatio;
    this->height = windowHeight * heightRatio;
    this->left = windowWidth * (1 - widthRatio) / 2;
    this->top = windowHeight * (1 - heightRatio) / 2;
    Showable::onWindowResize();
}

void Window::begin() {
    ImGui::Begin(showableParam->label, NULL, flag);
}

void Window::end() {
    ImGui::End();
}


