#pragma once

#include <string>

#include "model/character/CharacterProfile.hpp"


class ProfileExporter
{
public:

    void Export(
        const CharacterProfile& profile,
        const std::string& outputDirectory
    ) const;

};