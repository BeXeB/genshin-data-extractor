#pragma once

#include "database/GameDatabase.hpp"
#include "dm/weapon/WeaponExcelConfig.hpp"
#include "model/weapon/Weapon.hpp"

class WeaponStatBuilder
{
public:
    WeaponStats Build(
        const WeaponExcelConfig& weapon,
        const GameDatabase& db) const;

private:
    int GetAscension(
        int level) const;

    bool IsAscensionLevel(
        int level) const;

    WeaponStat BuildStat(
        const WeaponExcelConfig& weapon,
        int level,
        int ascension,
        const GameDatabase& db) const;

    double CalculateBaseStat(
        const WeaponPropGrowCurve& prop,
        int level,
        const GameDatabase& db) const;

    double GetCurveMultiplier(
        const WeaponPropGrowCurve& prop,
        int level,
        const GameDatabase& db) const;

    double GetAscensionBonus(
        const std::vector<WeaponPromoteExcelConfig>& promotes,
        int ascension,
        const std::string& propType) const;
};