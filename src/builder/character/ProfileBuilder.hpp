#pragma once

#include "dm/AvatarExcelConfig.hpp"
#include "dm/FetterInoExcelConfig.hpp"
#include "dm/TextMap.hpp"
#include "model/character/CharacterProfile.hpp"
#include "database/GameDatabase.hpp"


class ProfileBuilder
{
public:

    CharacterProfile Build(
        const AvatarExcelConfig &avatar,
        const GameDatabase &db
    ) const;
};