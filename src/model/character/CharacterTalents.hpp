#pragma once

#include <array>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "model/Item.hpp"

struct CombatTalent
{
    std::string name;

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
        {"descriptionRaw", talent.descriptionRaw},
        {"labels", talent.labels},
        {"parameters", talent.parameters}};
}

struct PassiveTalent
{
    std::string name;

    std::string descriptionRaw;
};

inline void to_json(
    nlohmann::json &j,
    const PassiveTalent &talent)
{
    j = nlohmann::json{
        {"name", talent.name},
        {"descriptionRaw", talent.descriptionRaw}};
}

struct CharacterTalents
{
    int id{};

    CombatTalent combat1;
    CombatTalent combat2;
    CombatTalent combat3;

    PassiveTalent passive1;
    PassiveTalent passive2;

    std::optional<PassiveTalent> passive3;
    std::optional<PassiveTalent> passive4;

    std::unordered_map<std::string, std::vector<Item>> costs;
};

inline void to_json(
    nlohmann::json& j,
    const CharacterTalents& talents)
{
    j = nlohmann::json{
        {"id", talents.id},
        {"combat1", talents.combat1},
        {"combat2", talents.combat2},
        {"combat3", talents.combat3},
        {"passive1", talents.passive1},
        {"passive2", talents.passive2},
        {"costs", talents.costs}
    };

    if (talents.passive3)
        j["passive3"] = *talents.passive3;

    if (talents.passive4)
        j["passive4"] = *talents.passive4;
}