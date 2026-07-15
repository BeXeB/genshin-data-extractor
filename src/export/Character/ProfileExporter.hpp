#pragma once

#include <nlohmann/json.hpp>

#include "model/character/CharacterProfile.hpp"


class ProfileExporter
{
public:

    nlohmann::json Export(
        const CharacterProfile& profile
    ) const;

};