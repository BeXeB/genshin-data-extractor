cmake_minimum_required(VERSION 3.20)

project(GenshinDataExtractor
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(json)


add_executable(
    GenshinDataExtractor
    src/main.cpp
)

target_include_directories(
    GenshinDataExtractor
    PRIVATE
    include
)

target_link_libraries(
    GenshinDataExtractor
    PRIVATE
    nlohmann_json::nlohmann_json
)