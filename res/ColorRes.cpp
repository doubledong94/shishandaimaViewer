#include "util/util.h"
#include "imgui.h"
#include "threepp/threepp.hpp"
#include "res/ColorRes.h"

threepp::Color ColorRes::mainWindowBgColor = threepp::Color(0.1f, 0.1f, 0.12f);

ImVec4 ColorRes::controlPanelBgColor = { 0.18f, 0.18f, 0.19f, 1.0f };
ImVec4 ColorRes::noBgColor = { 0.0f, 0.0f, 0.0f, 0.0f };
ImVec4 ColorRes::normalTextColor = { 1.0f, 1.0f, 1.0f, 1.0f };
ImVec4 ColorRes::textColorDepLower = { 0.9f, 0.9f, 0.0f, 1.f };
ImVec4 ColorRes::textColorDepHigher = { 0.9f, 0.0f, 0.5f, 1.f };