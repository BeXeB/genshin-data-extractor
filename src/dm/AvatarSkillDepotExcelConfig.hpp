#pragma once

#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

struct PassiveSkillGroup
{
    int passiveSkillGroupId{};
};

inline void from_json(
    const nlohmann::json& j,
    PassiveSkillGroup& skill)
{
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

    // Datamine keys are obfuscated and can change, so detect passive arrays by shape.
    std::vector<PassiveSkillGroup> normalPassiveGroups;
    std::vector<PassiveSkillGroup> specialPassiveGroups;

    for (auto it = j.begin(); it != j.end(); ++it)
    {
        if (!it->is_array() || it->empty())
        {
            continue;
        }

        bool matchesPassiveSkillGroupShape = true;
        // Structured metadata marks special passive entries (quest-gated/open-condition passives).
        bool hasStructuredMetadata = false;
        for (const auto& entry : *it)
        {
            if (!entry.is_object())
            {
                matchesPassiveSkillGroupShape = false;
                break;
            }

            if (!entry.contains("proudSkillGroupId"))
            {
                matchesPassiveSkillGroupShape = false;
                break;
            }

            // Exclude arrays like EIBOFEEGGID that carry structured open-condition metadata.
            for (const auto& [key, value] : entry.items())
            {
                if (key == "proudSkillGroupId")
                {
                    continue;
                }

                if (!value.is_number_integer() &&
                    !value.is_number_unsigned() &&
                    !value.is_boolean() &&
                    !value.is_null())
                {
                    hasStructuredMetadata = true;
                }
            }

            if (!matchesPassiveSkillGroupShape)
            {
                break;
            }
        }

        if (matchesPassiveSkillGroupShape)
        {
            std::vector<PassiveSkillGroup> parsedGroups;
            it->get_to(parsedGroups);

            // Keep base passives first and append special passives after them.
            auto& target =
                hasStructuredMetadata
                ? specialPassiveGroups
                : normalPassiveGroups;

            target.insert(
                target.end(),
                parsedGroups.begin(),
                parsedGroups.end());
        }
    }

    // TalentBuilder maps passive1..passive4 by index, so final ordering matters.
    depot.passiveSkills = std::move(normalPassiveGroups);
    depot.passiveSkills.insert(
        depot.passiveSkills.end(),
        specialPassiveGroups.begin(),
        specialPassiveGroups.end());
}