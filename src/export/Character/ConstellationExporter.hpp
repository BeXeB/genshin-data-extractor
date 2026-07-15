#pragma once

#include <nlohmann/json.hpp>

#include "model/character/CharacterConstellation.hpp"


class ConstellationExporter
{
public:

    nlohmann::json Export(
        const CharacterConstellation& constellation
    ) const;

};