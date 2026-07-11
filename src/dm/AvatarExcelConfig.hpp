#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct AvatarExcelConfig
{
    int id;

    uint64_t nameTextMapHash;

    std::string iconName;

    std::string sideIconName;

    std::string weaponType;

    std::string qualityType;

    std::string useType;

    int avatarPromoteId;

    int skillDepotId;
};

inline void from_json(
    const nlohmann::json &j,
    AvatarExcelConfig &avatar)
{
    j.at("id")
        .get_to(avatar.id);
    j.at("nameTextMapHash")
        .get_to(avatar.nameTextMapHash);
    j.at("iconName")
        .get_to(avatar.iconName);
    j.at("sideIconName")
        .get_to(avatar.sideIconName);
    j.at("weaponType")
        .get_to(avatar.weaponType);
    j.at("qualityType")
        .get_to(avatar.qualityType);
    j.at("useType")
        .get_to(avatar.useType);
    j.at("avatarPromoteId")
        .get_to(avatar.avatarPromoteId);
    j.at("skillDepotId")
        .get_to(avatar.skillDepotId);
}