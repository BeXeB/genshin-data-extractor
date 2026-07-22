#pragma once

#include "model/weapon/Weapon.hpp"
#include "WeaponAffixBuilder.hpp"
#include "WeaponPromoteBuilder.hpp"
#include "WeaponStatBuilder.hpp"

class GameDatabase;

class WeaponBuilder
{
public:
    Weapon Build(
        const GameDatabase &database,
        int id);

private:
    WeaponAffixBuilder affixBuilder;
    WeaponPromoteBuilder promoteBuilder;
    WeaponStatBuilder statBuilder;
};