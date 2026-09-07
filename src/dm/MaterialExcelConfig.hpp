#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"
#include "util/EnumConverter.hpp"

struct MaterialExcelConfig
{
    int id{};

    std::string icon;

    uint64_t nameTextMapHash{};
    uint64_t descTextMapHash{};
    uint64_t typeDescTextMapHash{};

    int rank{};
    int rankLevel{};
};

inline void from_json(
    const nlohmann::json &j,
    MaterialExcelConfig &material)
{
    material.id = j.value("id", 0);
    material.icon = j.value("icon", "");
    material.nameTextMapHash = j.value("nameTextMapHash", 0ULL);
    material.descTextMapHash = j.value("descTextMapHash", 0ULL);
    material.typeDescTextMapHash = j.value("typeDescTextMapHash", 0ULL);
    material.rank = j.value("rank", 0);
    material.rankLevel = j.value("rankLevel", 0);
}