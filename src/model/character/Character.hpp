#pragma once

#include <map>
#include <optional>

#include <nlohmann/json.hpp>

#include "CharacterProfile.hpp"
#include "CharacterTalents.hpp"
#include "CharacterStats.hpp"
#include "CharacterConstellation.hpp"

struct CharacterVariant
{
    CharacterTalents talents;

    CharacterConstellation constellation;
};

inline void to_json(
    nlohmann::json &j,
    const CharacterVariant &variant)
{
    j = nlohmann::json{
        {"skills", variant.talents},
        {"constellation", variant.constellation}};
}

struct Character
{
    CharacterProfile profile;

    CharacterTalents talents;

    CharacterStats stats;

    CharacterConstellation constellation;

    std::map<
        ElementType,
        CharacterVariant>
        variants;
};

inline void to_json(
    nlohmann::json &j,
    const Character &character)
{
    j = nlohmann::json{
        {"profile", character.profile},
        {"skills", character.talents},
        {"stats", character.stats},
        {"constellation", character.constellation},
        {"variants", character.variants}};
}