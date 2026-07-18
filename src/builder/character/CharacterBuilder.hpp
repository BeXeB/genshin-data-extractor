#pragma once

#include "dm/AvatarExcelConfig.hpp"
#include "model/character/Character.hpp"

#include "CharacterProfileBuilder.hpp"
#include "CharacterTalentBuilder.hpp"
#include "CharacterStatBuilder.hpp"
#include "CharacterConstellationBuilder.hpp"

#include "database/GameDatabase.hpp"


class CharacterBuilder
{
public:
    Character Build(
        const AvatarExcelConfig& avatar,
        const GameDatabase& db
    ) const;

private:
    CharacterProfileBuilder profileBuilder;
    CharacterTalentBuilder talentBuilder;
    CharacterStatBuilder statsBuilder;
    CharacterConstellationBuilder constellationBuilder;

    ElementType GetTravelerElement(int depotId) const;
};