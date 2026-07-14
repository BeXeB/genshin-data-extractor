#pragma once

#include "database/GameDatabase.hpp"

#include "dm/AvatarSkillDepotExcelConfig.hpp"
#include "dm/AvatarSkillExcelConfig.hpp"
#include "dm/ProudSkillExcelConfig.hpp"

#include "model/character/CharacterTalents.hpp"

class TalentBuilder
{
public:
    CharacterTalents Build(
        const AvatarSkillDepotExcelConfig& skillDepot,
        const GameDatabase& db
    ) const;

private:
    CombatTalent BuildCombatTalent(
        const AvatarSkillExcelConfig& skill,
        const std::vector<ProudSkillExcelConfig>& proudSkills,
        const GameDatabase& db
    ) const;

    PassiveTalent BuildPassiveTalent(
        const std::vector<ProudSkillExcelConfig>& proudSkills,
        const GameDatabase& db
    ) const;

    std::unordered_map<std::string, std::vector<Item>> GetTalentCosts(
        const std::vector<ProudSkillExcelConfig>& proudSkills,
        const GameDatabase& db
    ) const;
};