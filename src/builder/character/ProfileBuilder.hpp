#pragma once

#include "dm/AvatarExcelConfig.hpp"
#include "dm/FetterInoExcelConfig.hpp"
#include "dm/TextMap.hpp"
#include "model/character/CharacterProfile.hpp"
#include "model/Item.hpp"
#include "database/GameDatabase.hpp"


class ProfileBuilder
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