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
    src/database/GameDatabase.cpp

    src/builder/character/ProfileBuilder.cpp
    
    src/util/EnumConverter.cpp
    src/util/Slug.cpp
)

target_include_directories(
    GenshinDataExtractor
    PRIVATE
    src
    src/database
    src/builder
    src/builder/character
    src/model
    src/util
)

target_link_libraries(
    GenshinDataExtractor
    PRIVATE
    nlohmann_json::nlohmann_json
)

set_property(TARGET GenshinDataExtractor PROPERTY
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)