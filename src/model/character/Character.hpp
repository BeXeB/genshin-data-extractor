#pragma once

#include <map>
#include <optional>

#include "CharacterProfile.hpp"
#include "CharacterTalents.hpp"
#include "CharacterStats.hpp"
#include "CharacterConstellation.hpp"

struct CharacterVariant
{
    CharacterTalents talents;

    CharacterConstellation constellation;
};

struct Character
{
    CharacterProfile profile;

    std::optional<CharacterTalents>
        talents;

    CharacterStats stats;

    std::optional<CharacterConstellation>
        constellation;

    std::map<
        ElementType,
        CharacterVariant>
        variants;
};