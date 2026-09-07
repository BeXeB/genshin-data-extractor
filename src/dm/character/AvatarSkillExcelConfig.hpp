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
    const nlohmann::json &j,
    AvatarSkillExcelConfig &skill)
{
    skill.id = j.value("id", 0);
    skill.proudSkillGroupId = j.value("proudSkillGroupId", 0);
    skill.nameTextMapHash = j.value("nameTextMapHash", 0);
    skill.descTextMapHash = j.value("descTextMapHash", 0);
    skill.skillIcon = j.value("skillIcon", "");
}