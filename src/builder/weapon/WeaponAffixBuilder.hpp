#pragma once

#include <optional>
#include <vector>

#include "model/weapon/Weapon.hpp"

class GameDatabase;

class WeaponAffixBuilder
{
public:
    std::vector<std::optional<WeaponRefine>> Build(
        const GameDatabase& database,
        const std::vector<int>& skillAffix);
};