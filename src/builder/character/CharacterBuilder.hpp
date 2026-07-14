#pragma once

#include "dm/AvatarExcelConfig.hpp"
#include "model/character/Character.hpp"

#include "ProfileBuilder.hpp"
#include "TalentBuilder.hpp"
#include "StatBuilder.hpp"
#include "ConstellationBuilder.hpp"

#include "database/GameDatabase.hpp"


class CharacterBuilder
{
public:

    Character Build(
        const AvatarExcelConfig& avatar,
        const GameDatabase& db
    ) const;


private:

    ProfileBuilder profileBuilder;

    TalentBuilder talentBuilder;

    StatBuilder statsBuilder;

    ConstellationBuilder constellationBuilder;
};