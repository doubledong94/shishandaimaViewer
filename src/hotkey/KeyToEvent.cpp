#include "imgui.h"
#include "imgui_internal.h"
#include "util/util.h"
#include <chrono>
#include "hotkey/KeyEvent.h"
#include "hotkey/KeyToEvent.h"

void KeyToEvent::update() {
    updateCurrentKeyCodes();
    if (lastKeyCodes.empty() and currentKeyCodes.empty()) {
        return;
    }
    if (isSubsetOfBefore()) {
        if (lastKeyCodes.size() == currentKeyCodes.size()) {
            // handle long pressing of key comb
            if (isTimeOut()) {
                eventReceiver({ lastKeyCodes,3 });
                lastAction = 3;
            }
        } else {
            // some key of comb up
            resetTimer();
            if (lastAction != 2) {
                eventReceiver({ lastKeyCodes,2 });
                lastAction = 2;
            }
        }
    } else {
        // new key comb
        resetTimer();
        eventReceiver({ currentKeyCodes,1 });
        lastAction = 1;
    }
    copyToLast();
}

void KeyToEvent::updateCurrentKeyCodes() {
    currentKeyCodes.clear();
    for (ImGuiKey k : allowedKeys) {
        if (ImGui::IsKeyDown(k)) {
            if (k == ImGuiKey_RightAlt) {
                k = ImGuiKey_LeftAlt;
            }
            if (k == ImGuiKey_RightCtrl) {
                k = ImGuiKey_LeftCtrl;
            }
            if (k == ImGuiKey_RightShift) {
                k = ImGuiKey_LeftShift;
            }
            currentKeyCodes.insert(k);
        }
    }
}

bool KeyToEvent::isSubsetOfBefore() {
    for (const ImGuiKey& k : currentKeyCodes) {
        if (not lastKeyCodes.count(k)) {
            return false;
        }
    }
    return true;
}

void KeyToEvent::copyToLast() {
    lastKeyCodes.clear();
    lastKeyCodes.merge(currentKeyCodes);
}

void KeyToEvent::resetTimer() {
    timer = std::chrono::steady_clock::now();
}

bool KeyToEvent::isTimeOut() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - timer) > std::chrono::milliseconds(800);
}

KeyToEvent::KeyToEvent(function<void(const shishan::KeyEvent&)>& eventReceiver) :eventReceiver(eventReceiver) {
    allowedKeys = {
            ImGuiKey_1,
            ImGuiKey_2,
            ImGuiKey_3,
            ImGuiKey_4,
            ImGuiKey_5,
            ImGuiKey_6,
            ImGuiKey_7,
            ImGuiKey_8,
            ImGuiKey_9,
            ImGuiKey_0,
            ImGuiKey_Minus,
            ImGuiKey_Equal,
            ImGuiKey_Q,
            ImGuiKey_W,
            ImGuiKey_E,
            ImGuiKey_R,
            ImGuiKey_T,
            ImGuiKey_Y,
            ImGuiKey_U,
            ImGuiKey_I,
            ImGuiKey_O,
            ImGuiKey_P,
            ImGuiKey_LeftBracket,
            ImGuiKey_RightBracket,
            ImGuiKey_Backslash,
            ImGuiKey_A,
            ImGuiKey_S,
            ImGuiKey_D,
            ImGuiKey_F,
            ImGuiKey_G,
            ImGuiKey_H,
            ImGuiKey_J,
            ImGuiKey_K,
            ImGuiKey_L,
            ImGuiKey_Semicolon,
            ImGuiKey_Apostrophe,
            ImGuiKey_LeftShift,
            ImGuiKey_Z,
            ImGuiKey_X,
            ImGuiKey_C,
            ImGuiKey_V,
            ImGuiKey_B,
            ImGuiKey_N,
            ImGuiKey_M,
            ImGuiKey_Comma,
            ImGuiKey_Period,
            ImGuiKey_Slash,
            ImGuiKey_LeftCtrl,
            ImGuiKey_LeftAlt,
            ImGuiKey_Space,
            ImGuiKey_RightAlt,
            ImGuiKey_RightCtrl,
            ImGuiKey_RightShift,
    };
}

