#pragma once

#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

struct PassiveSkillGroup
{
    int passiveSkillGroupId{};
};

inline void from_json(
    const nlohmann::json &j,
    PassiveSkillGroup &skill)
{
    skill.passiveSkillGroupId = j.value("proudSkillGroupId", 0);
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
    const nlohmann::json &j,
    AvatarSkillDepotExcelConfig &depot)
{
    depot.id = j.value("id", 0);
    depot.skills = j.value("skills", std::vector<int>{});
    depot.talents = j.value("talents", std::vector<int>{});
    depot.energySkill = j.value("energySkill", 0);

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
        for (const auto &entry : *it)
        {
            if (!entry.is_object())
            {
                matchesPassiveSkillGroupShape = false;
                break;
            }

            // Skip empty objects (trailing placeholders in the array)
            if (entry.empty())
            {
                continue;
            }

            if (!entry.contains("proudSkillGroupId"))
            {
                matchesPassiveSkillGroupShape = false;
                break;
            }

            // Exclude arrays like EIBOFEEGGID that carry structured open-condition metadata.
            for (const auto &[key, value] : entry.items())
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
            auto &target =
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