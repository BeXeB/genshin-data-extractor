#pragma once

#include <nlohmann/json.hpp>

#include "model/character/CharacterTalents.hpp"

class SkillsExporter
{
public:
    nlohmann::json Export(
        const CharacterTalents &skills) const;
};