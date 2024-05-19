// ImHotKey v1.0
// https://github.com/CedricGuillemet/ImHotKey
//
// The MIT License(MIT)
// 
// Copyright(c) 2019 Cedric Guillemet
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#pragma once
/*
How to use it?

// Get some hotkeys composed of:
// - hotkey name
// - hotkey comment/lib
// - hotkey scancodes. Computed by the editor. Store that value in your app.

static std::vector<ImHotKey::HotKey> hotkeys = { { "Layout", "Reorder nodes in a simpler layout", 0xFFFF261D}
        ,{"Save", "Save the current graph", 0xFFFF1F1D}
        ,{"Load", "Load an existing graph file", 0xFFFF181D}
        ,{"Play/Stop", "Play or stop the animation from the current graph", 0xFFFFFF3F}
        ,{"SetKey", "Make a new animation key with the current parameters values at the current time", 0xFFFFFF1F}
        };

// The editor is a modal window. bring it with something like that
 if (ImGui::Button("Edit Hotkeys"))
{
    ImGui::OpenPopup("HotKeys Editor");
}
ImHotKey::Edit(hotkeys.data(), hotkeys.size(), "HotKeys Editor");

// ImHotKey also provides a way to retrieve HotKey
int hotkey = ImHotKey::GetHotKey(hotkeys.data(), hotkeys.size());
if (hotkey != -1)
{
    // handle the hotkey index!
}

Awesome, you are done!
To help you integrate in your app, you can get a text (like "Ctrl + O") to integrate in your menu
static void GetHotKeyLib(unsigned int functionKeys, char* buffer, size_t bufferSize);

*/

#include "imgui.h"
#include "imgui_internal.h"

namespace ImHotKey {

    static const int KeyOrders[5][14] = {
        {
            81,
            82,
            83,
            84,
            85,
            86,
            87,
            88,
            89,
            90,
            101,
            102,
            0xFF,
            0xFF,
            },
        {
            41,
            42,
            43,
            44,
            45,
            46,
            47,
            48,
            49,
            50,
            103,
            104,
            105,
            0xFF,
            },
        {
            51,
            52,
            53,
            54,
            55,
            56,
            57,
            58,
            59,
            106,
            107,
            0xFF,
            0xFF,
            0xFF,
            },
        {
            3,
            60,
            61,
            62,
            63,
            64,
            65,
            66,
            108,
            109,
            110,
            // 4,
            0xFF,
            0xFF,
            },
        {
            1,
            5,
            7,
            // 6,
            // 2,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            0xFF,
            }
    };

    static const int keyAlphabetCount = 256;

    static void HotKeySPrintf(char* buffer, size_t bufferSize, const char* fmt, ...) {
        va_list args;
        va_start(args, fmt);
        ImFormatStringV(buffer, bufferSize, fmt, args);
        va_end(args);
    }

    static void GetHotKeyLib(unsigned int functionKeys, char* buffer, size_t bufferSize, const char* functionLib, const char* clickStyle) {
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
        HotKeySPrintf(buffer, bufferSize, fmt, functionLib, clickStyle, lib[0], lib[1], lib[2], lib[3]);
    }

    static int editingHotkey = -1;
    static bool keyDown[keyAlphabetCount] = {};

    static void addHotKeySelectable(HotKey& hotkey, int i) {
        char hotKeyLib[128];
        char clickStyle[3];
        switch (hotkey.clickStyle) {
        case SINGLE_CLICK:
            clickStyle[0] = '.';
            clickStyle[1] = 0;
            clickStyle[2] = 0;
            break;
        case DOUBLE_CLICK:
            clickStyle[0] = '.';
            clickStyle[1] = '.';
            clickStyle[2] = 0;
            break;
        case LONG_PRESS:
            clickStyle[0] = '_';
            clickStyle[1] = 0;
            clickStyle[2] = 0;
            break;
        }
        GetHotKeyLib(hotkey.functionKeys, hotKeyLib, sizeof(hotKeyLib), hotkey.functionName, clickStyle);
        if (ImGui::Selectable(hotKeyLib, editingHotkey == int(i)) || editingHotkey == -1) {
            editingHotkey = int(i);
            memset(keyDown, 0, sizeof(keyDown));
            for (int j = 0; j < 4; j++) {
                int order = (hotkey.functionKeys >> (8 * j)) & 0xFF;
                if (order != 0xFF) {
                    keyDown[order] = true;
                }
            }
        }
    }

    static void Edit(HotKey* hotkey, size_t hotkeyCount, const char* popupModal, bool open) {
        if (not open) {
            if (editingHotkey != -1) {
                editingHotkey = -1;
            }
            return;
        }
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
                if (i == 6) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_add_and_delete_node());
                }
                if (i == 10) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_select_node());
                }
                if (i == 23) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_layout());
                }
                if (i == 43) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_style());
                }
                if (i == 60) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_explore());
                }
                if (i == 62) {
                    ImGui::SeparatorText(StringRes::singleton->getHotKeyTitle_cate_next_round());
                }
                addHotKeySelectable(hotkey[i], i);
            }
        }
        ImGui::EndChildFrame();
        ImGui::SameLine();
        ImGui::BeginGroup();

        for (auto orderAndKey : orderToKeyAlphabet) {
            if (ImGui::IsKeyPressed(orderAndKey.second.imkey, false)) {
                int order = orderAndKey.first;
                keyDown[order] = !keyDown[order];
            }
        }
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

        ImGui::RadioButton(StringRes::singleton->getRadioText_SingleClick(), &(hotkey[editingHotkey].clickStyle), ClickStyle::SINGLE_CLICK);
        ImGui::SameLine();
        ImGui::RadioButton(StringRes::singleton->getRadioText_DoubleClick(), &(hotkey[editingHotkey].clickStyle), ClickStyle::DOUBLE_CLICK);
        ImGui::SameLine();
        ImGui::RadioButton(StringRes::singleton->getRadioText_LongPress(), &(hotkey[editingHotkey].clickStyle), ClickStyle::LONG_PRESS);

        ImGui::SameLine();
        ImGui::InvisibleButton("space", ImVec2(20 * scale, 10));
        ImGui::SameLine();

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
            }
            ImGui::SameLine(0.f, 120.f * scale);
        } else {
            ImGui::SameLine(0.f, 200.f * scale);
        }

        ImGui::EndGroup();
        ImGui::EndPopup();
    }


};
