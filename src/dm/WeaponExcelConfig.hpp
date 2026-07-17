#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct PropGrowCurve
{
    std::string type{};
    std::string propType{};
    double initValue{};
};


inline void from_json(
    const nlohmann::json &j,
    PropGrowCurve &curve)
{
    j.at("type").get_to(curve.type);
    j.at("propType").get_to(curve.propType);
    j.at("initValue").get_to(curve.initValue);
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

    std::vector<PropGrowCurve> weaponProp;

    std::vector<int> awakenCosts;

    std::vector<int> skillAffix;
};


inline void from_json(
    const nlohmann::json &j,
    WeaponExcelConfig &weapon)
{
    j.at("id").get_to(weapon.id);
    j.at("nameTextMapHash").get_to(weapon.nameTextMapHash);
    j.at("descTextMapHash").get_to(weapon.descTextMapHash);
    j.at("weaponType").get_to(weapon.weaponType);
    j.at("rankLevel").get_to(weapon.rankLevel);
    j.at("icon").get_to(weapon.icon);
    j.at("awakenIcon").get_to(weapon.awakenIcon);
    j.at("storyId").get_to(weapon.storyId);
    j.at("weaponPromoteId").get_to(weapon.weaponPromoteId);
    j.at("weaponProp").get_to(weapon.weaponProp);
    j.at("awakenCosts").get_to(weapon.awakenCosts);
    j.at("skillAffix").get_to(weapon.skillAffix);
};