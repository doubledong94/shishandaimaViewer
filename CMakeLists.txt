cmake_minimum_required(VERSION 3.22)

project(shishandaimaViewer VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PCL 1.8 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(external/imgui)
include_directories(external/imgui/backends)
include_directories(src)

file(GLOB addressableInfo "src/addressableInfo/*.cpp" "src/addressableInfo/*.h")
file(GLOB animation "src/animation/*.h" "src/animation/*.cpp")
file(GLOB antlr "src/antlr/*.h" "src/antlr/*.cpp" "src/antlr/*/*.h" "src/antlr/*/*.cpp")
file(GLOB error "src/error/*.cpp" "src/error/*.h")
file(GLOB fileManager "src/file/*.cpp" "src/file/*.h")
file(GLOB hotkey "src/hotkey/*.cpp" "src/hotkey/*.h")
file(GLOB ikdtree "src/ikdTree/*.h" "src/ikdTree/*.cpp")
file(GLOB prologUtil "src/prolog/*.cpp" "src/prolog/*.h")
file(GLOB resource "src/res/*.h" "src/res/*.cpp")
file(GLOB runtime "src/runtime/*.h" "src/runtime/*.cpp" "src/runtime/*/*.h" "src/runtime/*/*.cpp")
file(GLOB simpleView "src/simpleView/*.h" "src/simpleView/*.cpp" "src/simpleView/*/*.h" "src/simpleView/*/*.cpp")
file(GLOB customThree "src/threepp/custom/*.h" "src/threepp/custom/*.cpp")
file(GLOB util "src/util/*.h" "src/util/*.cpp")
file(GLOB otherFile "src/*.cpp" "src/*.h")
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