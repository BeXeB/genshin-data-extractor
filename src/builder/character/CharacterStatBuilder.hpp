#pragma once

#include "dm/character/AvatarExcelConfig.hpp"
#include "database/GameDatabase.hpp"
#include "model/character/CharacterStats.hpp"

class CharacterStatBuilder
{
public:
    CharacterStats Build(
        const AvatarExcelConfig& avatar,
        const GameDatabase& db
    ) const;

private:
    CharacterStat BuildStat(
        const AvatarExcelConfig& avatar,
        int level,
        int ascension,
        const GameDatabase& db
    ) const;

    int GetAscension(
        int level
    ) const;

    bool IsAscensionLevel(
        int level
    ) const;

    double CalculateBaseStat(
        const AvatarExcelConfig& avatar,
        int level,
        const GameDatabase& db,
        const std::string& propType
    ) const;

    double GetCurveMultiplier(
        const AvatarExcelConfig& avatar,
        int level,
        const GameDatabase& db,
        const std::string& propType
    ) const;

    double GetAscensionBonus(
        const std::vector<AvatarPromoteExcelConfig>& promotes,
        int ascension,
        const std::string& propType
    ) const;

    double GetSpecializedStat(
        const AvatarExcelConfig& avatar,
        const std::vector<AvatarPromoteExcelConfig>& promotes,
        int ascension
    ) const;
};