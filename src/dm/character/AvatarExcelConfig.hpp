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
    curve.type = j.value("type", "");
    curve.growCurve = j.value("growCurve", "");
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
    avatar.id = j.value("id", 0);
    avatar.nameTextMapHash = j.value("nameTextMapHash", 0);
    avatar.iconName = j.value("iconName", "");
    avatar.sideIconName = j.value("sideIconName", "");
    avatar.weaponType = j.value("weaponType", "");
    avatar.qualityType = j.value("qualityType", "");
    avatar.useType = j.value("useType", "AVATAR_ABANDON");
    avatar.avatarPromoteId = j.value("avatarPromoteId", 0);
    avatar.skillDepotId = j.value("skillDepotId", 0);
    avatar.hpBase = j.value("hpBase", 0.0);
    avatar.attackBase = j.value("attackBase", 0.0);
    avatar.defenseBase = j.value("defenseBase", 0.0);
    avatar.elementMastery = j.value("elementMastery", 0.0);
    avatar.critical = j.value("critical", 0.05);
    avatar.criticalHurt = j.value("criticalHurt", 0.5);
    avatar.propGrowCurves = j.value("propGrowCurves", std::vector<PropGrowCurve>{});
    avatar.candSkillDepotIds = j.value("candSkillDepotIds", std::vector<int>{});
}