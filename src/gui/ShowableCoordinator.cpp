#include "util/util.h"
#include "imgui.h"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "imgui_internal.h"
#include "hotkey/HotkeyConfig.h"
#include "gui/HotkeyWindow.h"
#include "gui/Window.h"
#include "gui/EditLineAndGraphWindow.h"
#include "gui/ShowableCoordinator.h"
#include "res/StringRes.h"

void ShowableCoordinator::render() {
    for (auto& state : currentStates) {
        state->render();
    }
}

bool ShowableCoordinator::toState(GuiState* state) {
    if (allowedTransition.count(currentStates.back()) and allowedTransition[currentStates.back()].count(state)) {
        currentStates.push_back(state);
        currentStates.back()->onWindowResize(windowWidth, windowHeight);
        currentStates.back()->onEnter();
        return true;
    }
    return false;
}

void ShowableCoordinator::stateBack() {
    if (currentStates.size() > 1) {
        currentStates.back()->onExit();
        currentStates.pop_back();
    }
}

ShowableCoordinator::ShowableCoordinator() {
    editHotkeyState->mediator = this;
    readingState->mediator = this;
    currentStates.push_back(readingState);
    allowedTransition[readingState] = set<GuiState*>();
    allowedTransition[editHotkeyState] = set<GuiState*>();
    allowedTransition[editLineAndGraphState] = set<GuiState*>();
    allowedTransition[readingState].insert(editHotkeyState);
    allowedTransition[readingState].insert(editLineAndGraphState);
}

void ShowableCoordinator::onKeyEvent(const shishan::KeyEvent& event) {
    currentStates.back()->onKeyEvent(event);
}

void ShowableCoordinator::onWindowResize(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    for (auto& state : currentStates) {
        state->onWindowResize(width, height);
    }
}

EditHotkeyState* ShowableCoordinator::editHotkeyState = NULL;
ReadingState* ShowableCoordinator::readingState = NULL;
EditLineAndGraphState* ShowableCoordinator::editLineAndGraphState = NULL;
map<GuiState*, set<GuiState*>> ShowableCoordinator::allowedTransition;
map<GuiState*, set<GuiState*>> ShowableCoordinator::allowedStack;

void ShowableCoordinator::staticInit() {
    editHotkeyState = new EditHotkeyState(new HotkeyWindow());
    readingState = new ReadingState();
    editLineAndGraphState = new EditLineAndGraphState(new EditLineAndGraphWindow());
}

EditLineAndGraphState::EditLineAndGraphState(EditLineAndGraphWindow* window) :window(window) {
}

void EditLineAndGraphState::render() {
    window->render();
}

void EditLineAndGraphState::onWindowResize(int width, int height) {
    window->windowWidth = width;
    window->windowHeight = height;
    window->onWindowResize();
}

EditHotkeyState::EditHotkeyState(HotkeyWindow* window) :window(window) {
}
void EditHotkeyState::render() {
    window->render();
}

void EditHotkeyState::onExit() {
    window->onExit();
}

void EditHotkeyState::onEnter() {
    window->onEnter();
}

void EditHotkeyState::onKeyEvent(const shishan::KeyEvent& event) {
    window->onKeyEvent(event);
}

void ReadingState::onKeyEvent(const shishan::KeyEvent& event) {
    int hotkey = getHotkeyIndex(event);
    if (hotkey > -1) {
        if (HotkeyConfig::hotkeys[hotkey].canLasting) {
            if (not event.isActionUp()) {
                HotkeyConfig::functionEnumToFunction[HotkeyConfig::hotkeys[hotkey].hotkeyFunction]();
            }
        } else {
            if (event.isActionUp()) {
                HotkeyConfig::functionEnumToFunction[HotkeyConfig::hotkeys[hotkey].hotkeyFunction]();
            }
        }
    }
}

int ReadingState::getHotkeyIndex(const shishan::KeyEvent& event) {
    HotKey* hotkey = HotkeyConfig::hotkeys.data();
    size_t hotkeyCount = HotkeyConfig::hotkeys.size();
    unsigned char order[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
    int scanCodeCount = 0;
    for (auto orderAndKey : orderToKeyAlphabet) {
        if (event.keyCodes.count(orderAndKey.second.imkey)) {
            order[scanCodeCount] = orderAndKey.first;
            scanCodeCount++;
            if (scanCodeCount == 4)
                break;
        }
    }
    unsigned int newHotKey = HotkeyConfig::GetOrderedScanCodes(order);
    if (scanCodeCount) {
        for (size_t i = 0; i < hotkeyCount; i++) {
            if (hotkey[i].functionKeys == newHotKey) {
                return int(i);
            }
        }
    }
    return -1;
}