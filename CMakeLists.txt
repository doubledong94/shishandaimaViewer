cmake_minimum_required(VERSION 3.22)

project(shishandaimaViewer VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(external/imgui)
include_directories(external/imgui/backends)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB util "util/*.h" "util/*.cpp")
file(GLOB antlr "antlr/*.h" "antlr/*.cpp" "antlr/*/*.h" "antlr/*/*.cpp")
file(GLOB runtime "runtime/*.h" "runtime/*.cpp" "runtime/*/*.h" "runtime/*/*.cpp")
file(GLOB simpleView "simpleView/*.h" "simpleView/*.cpp" "simpleView/*/*.h" "simpleView/*/*.cpp")
file(GLOB customThree "threepp/custom/*.h" "threepp/custom/*.cpp")
file(GLOB error "error/*.cpp" "error/*.h")
file(GLOB prologUtil "prolog/*.cpp" "prolog/*.h")
file(GLOB addressableInfo "addressableInfo/*.cpp" "addressableInfo/*.h")
file(GLOB fileManager "file/*.cpp" "file/*.h")
file(GLOB otherFile "*.cpp" "*.h")
file(GLOB hotkey "hotkey/*.cpp" "hotkey/*.h")
file(GLOB resource "res/*.h" "res/*.cpp")
file(GLOB animation "animation/*.h" "animation/*.cpp")
file(GLOB ikdtree "ikdTree/*.h" "ikdTree/*.cpp")
file(GLOB imgui 
        "external/imgui/*.h" 
        "external/imgui/*.cpp"
        "external/imgui/backends/imgui_impl_glfw.h"
        "external/imgui/backends/imgui_impl_glfw.cpp"
        "external/imgui/backends/imgui_impl_opengl3.h"
        "external/imgui/backends/imgui_impl_opengl3.cpp")

add_executable(${PROJECT_NAME}
    ${error}
    ${fileManager}
    ${addressableInfo}
    ${prologUtil}
    ${util}
    ${imgui}
    ${runtime}
    ${antlr}
    ${customThree}
    ${simpleView}
    ${otherFile}
    ${hotkey}
    ${resource}
    ${animation}
    ${ikdtree}
)

add_subdirectory(external/antlr4/runtime/Cpp)
add_subdirectory(external/swipl)
add_subdirectory(external/threepp)
add_subdirectory(external/re2)
add_subdirectory(external/igraph)
add_subdirectory(external/spdlog)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/antlr4/runtime/Cpp/runtime/src
    PUBLIC external/swipl/packages/cpp
    PUBLIC external/threepp/include
    PUBLIC external/re2
    PUBLIC external/igraph/include
    PUBLIC external/spdlog/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE external/antlr4/runtime/Cpp/runtime
    PRIVATE external/swipl/src
    PRIVATE external/threepp/src
    PRIVATE external/re2
    PRIVATE external/igraph/src
    PRIVATE external/spdlog
)

target_link_libraries(${PROJECT_NAME}
    antlr4_static
    libswipl
    threepp
    re2
    igraph
    spdlog
    ${PCL_LIBRARIES}
)

add_dependencies(${PROJECT_NAME}      
    antlr4_static
    libswipl
    threepp
    re2
    igraph
    spdlog
)

add_custom_target(delete_data
    COMMAND rm -fr data
    COMMAND mkdir data 
    COMMAND mkdir data/prolog 
    COMMAND mkdir data/prolog/addressable 
    COMMAND mkdir data/prolog/unaddressable
)