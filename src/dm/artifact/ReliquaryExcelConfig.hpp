#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct ReliquaryExcelConfig
{
    int id{};

    int setId{};

    uint64_t nameTextMapHash{};
    uint64_t descTextMapHash{};

    std::string equipType{};

    std::string icon{};

    int rankLevel{};

    int storyId{};
};

inline void from_json(
    const nlohmann::json &j,
    ReliquaryExcelConfig &reliquary)
{
    reliquary.id = j.value("id", 0);
    reliquary.setId = j.value("setId", 0);
    reliquary.nameTextMapHash = j.value("nameTextMapHash", 0);
    reliquary.descTextMapHash = j.value("descTextMapHash", 0);
    reliquary.equipType = j.value("equipType", "");
    reliquary.icon = j.value("icon", "");
    reliquary.rankLevel = j.value("rankLevel", 0);
    reliquary.storyId = j.value("storyId", 0);
}