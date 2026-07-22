#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct PropGrowCurve
{
    std::string type;
    std::string growCurve;
};

inline void from_json(
    const nlohmann::json &j,
    PropGrowCurve &curve)
{
    j.at("type").get_to(curve.type);
    j.at("growCurve").get_to(curve.growCurve);
}

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

    double hpBase;
    double attackBase;
    double defenseBase;

    double elementMastery;
    double critical;
    double criticalHurt;

    std::vector<PropGrowCurve> propGrowCurves;

    std::vector<int> candSkillDepotIds;
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
    j.at("hpBase")
        .get_to(avatar.hpBase);
    j.at("attackBase")
        .get_to(avatar.attackBase);
    j.at("defenseBase")
        .get_to(avatar.defenseBase);
    j.at("elementMastery")
        .get_to(avatar.elementMastery);
    j.at("critical")
        .get_to(avatar.critical);
    j.at("criticalHurt")
        .get_to(avatar.criticalHurt);
    j.at("propGrowCurves")
        .get_to(avatar.propGrowCurves);
    j.at("candSkillDepotIds")
        .get_to(avatar.candSkillDepotIds);
}