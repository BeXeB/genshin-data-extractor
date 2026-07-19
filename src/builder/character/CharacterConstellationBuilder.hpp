#pragma once

#include "model/character/CharacterConstellation.hpp"
#include "database/GameDatabase.hpp"
#include "dm/character/AvatarSkillDepotExcelConfig.hpp"
#include "dm/character/AvatarTalentExcelConfig.hpp"


class CharacterConstellationBuilder
{
public:
    CharacterConstellation Build(
        const AvatarSkillDepotExcelConfig& skillDepot,
        const GameDatabase& db
    ) const;

private:
    ConstellationDetail BuildDetail(
        const AvatarTalentExcelConfig& talent,
        const GameDatabase& db
    ) const;
};