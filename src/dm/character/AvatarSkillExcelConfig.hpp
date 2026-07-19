#pragma once

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

struct AvatarSkillExcelConfig
{
    int id{};

    int proudSkillGroupId{};

    uint64_t nameTextMapHash{};

    uint64_t descTextMapHash{};

    std::string skillIcon;
};

inline void from_json(
    const nlohmann::json& j,
    AvatarSkillExcelConfig& skill)
{
    j.at("id")
        .get_to(skill.id);

    j.at("proudSkillGroupId")
        .get_to(skill.proudSkillGroupId);

    j.at("nameTextMapHash")
        .get_to(skill.nameTextMapHash);

    j.at("descTextMapHash")
        .get_to(skill.descTextMapHash);

    j.at("skillIcon")
        .get_to(skill.skillIcon);
}