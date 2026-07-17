#pragma once

#include <map>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

#include <nlohmann/json.hpp>

#include "model/Item.hpp"
#include "WeaponRefines.hpp"
#include "WeaponStats.hpp"

struct WeaponImages
{
    std::string filename_icon;

    std::optional<std::string> filename_awakenIcon;

    std::optional<std::string> filename_gacha;
};


inline void to_json(
    nlohmann::json& j,
    const WeaponImages& images)
{
    j = nlohmann::json{
        {"filename_icon", images.filename_icon}
    };

    if (images.filename_awakenIcon)
        j["filename_awakenIcon"] = *images.filename_awakenIcon;

    if (images.filename_gacha)
        j["filename_gacha"] = *images.filename_gacha;
}


struct Weapon
{
    int id{};

    std::string name;

    std::string normalizedName;

    std::string description;

    std::string weaponType;

    std::string qualityType;

    int rarity{};

    std::string story;

    std::optional<std::string> mainStatType;

    std::optional<std::string> effectName;

    std::optional<std::string> effectTemplateRaw;

    std::optional<WeaponRefine> r1;
    std::optional<WeaponRefine> r2;
    std::optional<WeaponRefine> r3;
    std::optional<WeaponRefine> r4;
    std::optional<WeaponRefine> r5;

    std::map<std::string, std::vector<Item>> costs;

    WeaponImages images;

    std::string version;

    WeaponStats stats;
};


inline void to_json(
    nlohmann::json& j,
    const Weapon& weapon)
{
    j = nlohmann::json{
        {"id", weapon.id},
        {"name", weapon.name},
        {"normalizedName", weapon.normalizedName},

        {"description", weapon.description},
        {"weaponType", weapon.weaponType},

        {"qualityType", weapon.qualityType},
        {"rarity", weapon.rarity},

        {"story", weapon.story},

        {"costs", weapon.costs},

        {"images", weapon.images},

        {"version", weapon.version},

        {"stats", weapon.stats}
    };

    if (weapon.mainStatType)
        j["mainStatType"] = *weapon.mainStatType;

    if (weapon.effectName)
        j["effectName"] = *weapon.effectName;

    if (weapon.effectTemplateRaw)
        j["effectTemplateRaw"] = *weapon.effectTemplateRaw;


    if (weapon.r1)
        j["r1"] = *weapon.r1;

    if (weapon.r2)
        j["r2"] = *weapon.r2;

    if (weapon.r3)
        j["r3"] = *weapon.r3;

    if (weapon.r4)
        j["r4"] = *weapon.r4;

    if (weapon.r5)
        j["r5"] = *weapon.r5;
}