#pragma once

#include "dm/character/AvatarExcelConfig.hpp"
#include "dm/character/FetterInfoExcelConfig.hpp"
#include "dm/TextMap.hpp"
#include "model/character/CharacterProfile.hpp"
#include "model/Item.hpp"
#include "database/GameDatabase.hpp"


class CharacterProfileBuilder
{
public:

    CharacterProfile Build(
        const AvatarExcelConfig &avatar,
        const GameDatabase &db
    ) const;

private:

    StatType GetCharacterSubstat(
        const std::vector<AvatarPromoteExcelConfig>& promotes
    ) const;

    std::array<std::vector<Item>, 6> GetCharacterAscensionCosts(
        const std::vector<AvatarPromoteExcelConfig>& promotes,
        const GameDatabase& db
    ) const;
};