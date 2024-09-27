#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "Button.h"

Button::Button() {

}

void Button::begin() {
    ImGui::Button(showableParam->label.data(), { width,height });
}
