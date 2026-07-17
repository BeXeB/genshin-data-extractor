#pragma once

#include "model/character/CharacterConstellation.hpp"
#include "database/GameDatabase.hpp"
#include "dm/AvatarSkillDepotExcelConfig.hpp"
#include "dm/AvatarTalentExcelConfig.hpp"


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