#pragma once

#include "model/weapon/Weapon.hpp"

class GameDatabase;

class WeaponBuilder
{
public:
    static Weapon Build(
        const GameDatabase& database,
        int id);
};