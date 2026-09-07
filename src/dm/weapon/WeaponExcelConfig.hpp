#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct WeaponPropGrowCurve
{
    std::string type{};
    std::string propType{};
    double initValue{};
};

inline void from_json(
    const nlohmann::json &j,
    WeaponPropGrowCurve &curve)
{
    curve.type = j.value("type", "");
    curve.propType = j.value("propType", "");
    curve.initValue = j.value("initValue", 0.0);
};

struct WeaponExcelConfig
{
    int id{};

    uint64_t nameTextMapHash{};
    uint64_t descTextMapHash{};

    std::string weaponType{};

    int rankLevel{};

    std::string icon{};
    std::string awakenIcon{};

    uint64_t storyId{};

    uint64_t weaponPromoteId{};

    std::vector<WeaponPropGrowCurve> weaponProp;

    std::vector<int> skillAffix;
};

inline void from_json(
    const nlohmann::json &j,
    WeaponExcelConfig &weapon)
{
    weapon.id = j.value("id", 0);
    weapon.nameTextMapHash = j.value("nameTextMapHash", 0);
    weapon.descTextMapHash = j.value("descTextMapHash", 0);
    weapon.weaponType = j.value("weaponType", "");
    weapon.rankLevel = j.value("rankLevel", 0);
    weapon.icon = j.value("icon", "");
    weapon.awakenIcon = j.value("awakenIcon", "");
    weapon.storyId = j.value("storyId", 0);
    weapon.weaponPromoteId = j.value("weaponPromoteId", 0);
    weapon.weaponProp = j.value("weaponProp", std::vector<WeaponPropGrowCurve>{});
    weapon.skillAffix = j.value("skillAffix", std::vector<int>{});
};