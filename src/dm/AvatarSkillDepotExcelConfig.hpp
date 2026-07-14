#pragma once

#include <vector>

#include <nlohmann/json.hpp>

struct PassiveSkillGroup
{
    int level{};
    int passiveSkillGroupId{};
};

inline void from_json(
    const nlohmann::json& j,
    PassiveSkillGroup& skill)
{
    j.at("CCHNLJKDDKI")
        .get_to(skill.level);

    j.at("proudSkillGroupId")
        .get_to(skill.passiveSkillGroupId);
}

struct AvatarSkillDepotExcelConfig
{
    int id{};

    std::vector<int> skills;

    std::vector<int> talents;

    std::vector<PassiveSkillGroup> passiveSkills;

    int energySkill{};
};

inline void from_json(
    const nlohmann::json& j,
    AvatarSkillDepotExcelConfig& depot)
{
    j.at("id")
        .get_to(depot.id);

    j.at("skills")
        .get_to(depot.skills);

    j.at("talents")
        .get_to(depot.talents);

    j.at("energySkill")
        .get_to(depot.energySkill);

    j.at("BOIOJNENKHP")
        .get_to(depot.passiveSkills);
}