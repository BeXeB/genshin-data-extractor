#pragma once

#include <nlohmann/json.hpp>

#include "model/character/CharacterStats.hpp"


class StatsExporter
{
public:

    nlohmann::json Export(
        const CharacterStats& stats
    ) const;

};