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
    "src/main.cpp"
    "src/database/GameDatabase.cpp"

    "src/builder/character/CharacterProfileBuilder.cpp"
    "src/builder/character/CharacterStatBuilder.cpp"
    "src/builder/character/CharacterConstellationBuilder.cpp"
    "src/builder/character/CharacterTalentBuilder.cpp"
    "src/builder/character/CharacterBuilder.cpp"

    "src/builder/weapon/WeaponBuilder.cpp" 
    "src/builder/weapon/WeaponAffixBuilder.cpp" 
    "src/builder/weapon/WeaponStatBuilder.cpp" 
    "src/builder/weapon/WeaponPromoteBuilder.cpp"

    "src/export/character/ProfileExporter.cpp"
    "src/export/character/SkillsExporter.cpp"
    "src/export/character/StatsExporter.cpp"
    "src/export/character/ConstellationExporter.cpp"
    "src/export/character/CharacterExporter.cpp"

    "src/util/EnumConverter.cpp"
    "src/util/Slug.cpp" 
  "src/util/ReadableTextLoader.cpp" "src/builder/artifact/ArtifactBuilder.cpp" "src/builder/artifact/ArtifactPieceBuilder.cpp"  "src/builder/material/MaterialBuilder.cpp" "src/builder/material/MaterialCraftBuilder.cpp")

target_include_directories(
    GenshinDataExtractor
    PRIVATE
    src
)

target_link_libraries(
    GenshinDataExtractor
    PRIVATE
    nlohmann_json::nlohmann_json
)

target_compile_definitions(GenshinDataExtractor PRIVATE
    PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
)