#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "Child.h"

Child::Child() {
}

void Child::begin() {
    ImGui::BeginChild(showableParam->label.data(), ImVec2(width, height), ImGuiChildFlags_None,ImGuiWindowFlags_None);
}

void Child::end() {
    ImGui::EndChild();
}


