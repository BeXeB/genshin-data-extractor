#pragma once

#include "model/weapon/Weapon.hpp"

#include "database/GameDatabase.hpp"

class WeaponStatBuilder
{
public:
    static WeaponStats Build(
        const GameDatabase& database,
        const WeaponExcelConfig& weapon);
};