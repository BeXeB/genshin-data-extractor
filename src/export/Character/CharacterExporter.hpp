#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "model/character/Character.hpp"
#include "ProfileExporter.hpp"
#include "SkillsExporter.hpp"
#include "StatsExporter.hpp"
#include "ConstellationExporter.hpp"


class CharacterExporter
{
public:

    void Export(
        const std::vector<Character>& characters,
        const std::string& outputDirectory
    ) const;

private:

    ProfileExporter profileExporter;
    SkillsExporter skillsExporter;
    StatsExporter statsExporter;
    ConstellationExporter constellationExporter;

};