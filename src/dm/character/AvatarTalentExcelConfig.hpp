#pragma once

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>


struct AvatarTalentExcelConfig
{
    int talentId{};

    uint64_t nameTextMapHash{};

    uint64_t descTextMapHash{};

    std::string icon;
};


inline void from_json(
    const nlohmann::json& j,
    AvatarTalentExcelConfig& talent)
{
    j.at("talentId")
        .get_to(talent.talentId);

    j.at("nameTextMapHash")
        .get_to(talent.nameTextMapHash);

    j.at("descTextMapHash")
        .get_to(talent.descTextMapHash);

    j.at("icon")
        .get_to(talent.icon);
}