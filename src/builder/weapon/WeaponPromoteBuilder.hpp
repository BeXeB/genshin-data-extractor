#pragma once

#include <map>
#include <string>
#include <vector>

#include "model/Item.hpp"

class GameDatabase;

class WeaponPromoteBuilder
{
public:
    std::map<std::string, std::vector<Item>> Build(
        const GameDatabase& database,
        int weaponPromoteId);
};