#include "util/util.h"
#include "imgui.h"
#include "hotkey/KeyEvent.h"
#include "gui/Showable.h"
#include "imgui_internal.h"
#include "error/ErrorManager.h"
#include "hotkey/HotkeyConfig.h"
#include "res/StringRes.h"
#include "file/FileManager.h"
#include "HotkeyWindow.h"

void HotkeyWindow::HotKeySPrintf(char* buffer, size_t bufferSize, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    ImFormatStringV(buffer, bufferSize, fmt, args);
    va_end(args);
}


void HotkeyWindow::GetHotKeyLib(unsigned int functionKeys, char* buffer, size_t bufferSize, const char* functionLib) {
    static const char* strLib[4] = { "%s (%s %s)", "%s (%s %s + %s)", "%s (%s %s + %s + %s)", "%s (%s %s + %s + %s + %s)" };
    static const char* lib[4];
    int orderCodeCount = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char orderCode = (unsigned char)(functionKeys >> i * 8);
        if (orderCode == 0xFF) {
            continue;
        }
        lib[orderCodeCount] = orderToKeyAlphabet[orderCode].name;
        orderCodeCount++;
    }
    if (!orderCodeCount) {
        buffer[0] = 0;
        return;
    }

    const char* fmt = strLib[orderCodeCount - 1];
    HotKeySPrintf(buffer, bufferSize, fmt, functionLib, "", lib[0], lib[1], lib[2], lib[3]);
}


void HotkeyWindow::addHotKeySelectable(HotKey& hotkey, int i) {
    char hotKeyLib[128];
    GetHotKeyLib(hotkey.functionKeys, hotKeyLib, sizeof(hotKeyLib), hotkey.functionName);
    if (ImGui::Selectable(hotKeyLib, editingHotkey == i)) {
        editingHotkey = i;
        setupKeyboard(hotkey);
    }
}

void HotkeyWindow::setupKeyboard(HotKey& hotkey) {
    memset(keyDown, 0, sizeof(keyDown));
    for (int j = 0; j < 4; j++) {
        int order = (hotkey.functionKeys >> (8 * j)) & 0xFF;
        if (order != 0xFF) {
            keyDown[order] = true;
        }
    }
}

void HotkeyWindow::render() {
    HotKey* hotkey = HotkeyConfig::hotkeys.data();
    size_t hotkeyCount = HotkeyConfig::hotkeys.size();
    const char* popupModal = StringRes::singleton->getHotkeyEditor();
    ImGui::OpenPopup(StringRes::singleton->getHotkeyEditor());

    ImGuiIO& io = ImGui::GetIO();
    float popupModalWidth = io.DisplaySize.x * 0.9;
    float popupModalHeight = io.DisplaySize.y * 0.5f;
    ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(popupModalWidth, popupModalHeight), ImGuiCond_Always);
    float scale = popupModalWidth / 920;
    float spacing = 4.0f * scale;
    if (!ImGui::BeginPopupModal(popupModal, NULL, ImGuiWindowFlags_NoResize))
        return;

    ImGui::BeginChildFrame(127, ImVec2(popupModalWidth * 0.3f, -1));
    for (size_t i = 0;i < hotkeyCount;i++) {
        if (i > 0) {
            if (i == 1) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_prepare1());
            }
            if (i == 2) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_prepare2());
            }
            if (i == 12) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_add_and_delete_node());
            }
            if (i == 16) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_select_node());
            }
            if (i == 39) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_layout());
            }
            if (i == 69) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_style());
            }
            if (i == 87) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_explore());
            }
            if (i == 89) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_next_round());
            }
            if (i == 90) {
                ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cat_saveAndRestoreGraph());
            }
            addHotKeySelectable(hotkey[i], i);
        }
    }
    ImGui::EndChildFrame();
    ImGui::SameLine();
    ImGui::BeginGroup();

    for (unsigned int y = 0; y < 5; y++) {
        int x = 0;
        ImGui::BeginGroup();
        while (KeyOrders[y][x] != 0xFF) {
            int order = KeyOrders[y][x];
            const Key& key = orderToKeyAlphabet[order];
            const float ofs = key.offset + (x ? spacing : 0.f);

            const float width = key.width * scale;
            if (x) {
                ImGui::SameLine(0.f, ofs);
            } else {
                if (ofs >= 1.f) {
                    ImGui::Indent(ofs);
                }
            }
            bool& butSwtch = keyDown[order];
            ImGui::PushStyleColor(ImGuiCol_Button, butSwtch ? 0xFF1040FF : 0x80000000);
            if (ImGui::Button(key.name, ImVec2(width, 40 * scale))) {
                butSwtch = !butSwtch;
            }
            ImGui::PopStyleColor();
            x++;
        }
        ImGui::EndGroup();
    }
    ImGui::InvisibleButton("space", ImVec2(10, 30 * scale));

    int keyDownCount = 0;
    for (auto d : keyDown) {
        keyDownCount += d ? 1 : 0;
    }
    if (ImGui::Button("Clear", ImVec2(80 * scale, 40 * scale))) {
        memset(keyDown, 0, sizeof(keyDown));
    }
    ImGui::SameLine();
    if (keyDownCount && keyDownCount < 5) {
        if (ImGui::Button("Set", ImVec2(80 * scale, 40 * scale))) {
            unsigned char order[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
            int scanCodeCount = 0;
            hotkey[editingHotkey].functionKeys = 0;
            for (int i = 1; i < keyAlphabetCount; i++) {
                if (keyDown[i]) {
                    order[scanCodeCount] = i;
                    scanCodeCount++;
                }
            }

            hotkey[editingHotkey].functionKeys = HotkeyConfig::GetOrderedScanCodes(order);
            spdlog::get(ErrorManager::DebugTag)->warn("{0:x}", hotkey[editingHotkey].functionKeys);
            edited = true;
        }
        ImGui::SameLine(0.f, 120.f * scale);
    } else {
        ImGui::SameLine(0.f, 200.f * scale);
    }

    ImGui::EndGroup();
    ImGui::EndPopup();
}

void HotkeyWindow::onExit() {
    if (edited) {
        HotkeyConfig::saveHotkeyConfig(FileManager::hotkeyConfig);
    }
}

void HotkeyWindow::onEnter() {
    editingHotkey = 1;
    setupKeyboard(HotkeyConfig::hotkeys[editingHotkey]);
    edited = false;
}

void HotkeyWindow::onKeyEvent(const shishan::KeyEvent& event) {
    if (event.isActionUp()) {
        for (auto& orderAndKey : orderToKeyAlphabet) {
            if (event.keyCodes.count(orderAndKey.second.imkey)) {
                keyDown[orderAndKey.first] = !keyDown[orderAndKey.first];
            }
        }
    }
}

HotkeyWindow::HotkeyWindow() {
}
