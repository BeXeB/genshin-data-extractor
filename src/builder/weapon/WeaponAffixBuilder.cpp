#include "WeaponAffixBuilder.hpp"

#include "database/GameDatabase.hpp"

std::vector<std::optional<WeaponRefine>>
WeaponAffixBuilder::Build(
    const GameDatabase& database,
    const std::vector<int>& skillAffix)
{
    std::vector<std::optional<WeaponRefine>> refinements;

    if (skillAffix.empty() || skillAffix[0] == 0)
    {
        return refinements;
    }

    const auto& affixes =
        database.GetEquipAffixes(skillAffix[0]);

    for (const auto& affix : affixes)
    {
        WeaponRefine refine;

        refine.description =
            database.GetText(
                affix.descTextMapHash);

        for (double value : affix.paramList)
        {
            if (value == 0)
                continue;

            refine.values.push_back(
                std::to_string(value));
        }

        refinements.push_back(
            std::move(refine));
    }

    return refinements;
}