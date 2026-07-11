#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "model/Item.hpp"

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

inline void to_json(
    nlohmann::json &j,
    const CombatTalent &talent)
{
    j = nlohmann::json{
        {"name", talent.name},
        {"description", talent.description},
        {"descriptionRaw", talent.descriptionRaw},
        {"labels", talent.labels},
        {"parameters", talent.parameters}};
}

struct PassiveTalent
{
    std::string name;

    std::string description;
    std::string descriptionRaw;
};

inline void to_json(
    nlohmann::json &j,
    const PassiveTalent &talent)
{
    j = nlohmann::json{
        {"name", talent.name},
        {"description", talent.description},
        {"descriptionRaw", talent.descriptionRaw}};
}

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
};

inline void to_json(
    nlohmann::json &j,
    const CharacterTalents &talents)
{
    j = nlohmann::json{
        {"id", talents.id},
        {"name", talents.name},
        {"combat1", talents.combat1},
        {"combat2", talents.combat2},
        {"combat3", talents.combat3},
        {"passive1", talents.passive1},
        {"passive2", talents.passive2},
        {"passiveExtra", talents.passiveExtra},
        {"levelCosts", talents.levelCosts}};
}