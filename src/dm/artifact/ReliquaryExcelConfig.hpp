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
    j.at("id")
        .get_to(reliquary.id);

    j.at("setId")
        .get_to(reliquary.setId);

    j.at("nameTextMapHash")
        .get_to(reliquary.nameTextMapHash);

    j.at("descTextMapHash")
        .get_to(reliquary.descTextMapHash);

    j.at("equipType")
        .get_to(reliquary.equipType);

    j.at("icon")
        .get_to(reliquary.icon);

    j.at("rankLevel")
        .get_to(reliquary.rankLevel);

    j.at("storyId")
        .get_to(reliquary.storyId);
}