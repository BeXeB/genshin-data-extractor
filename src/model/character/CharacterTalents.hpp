#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>

#include "Item.hpp"

struct CombatTalent
{
    std::string name;

    std::string description;
    std::string descriptionRaw;

    std::vector<std::string> labels;

    std::map<
        std::string,
        std::vector<double>>
        parameters;
};

struct PassiveTalent
{
    std::string name;

    std::string description;
    std::string descriptionRaw;
};

struct CharacterTalents
{
    int id{};

    std::string name;

    CombatTalent combat1;
    CombatTalent combat2;
    CombatTalent combat3;

    PassiveTalent passive1;
    PassiveTalent passive2;

    std::vector<PassiveTalent> passiveExtra;

    std::array<std::vector<Item>, 9>
        levelCosts;

    std::string version;
};