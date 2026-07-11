#pragma once

#include <array>
#include <string>

struct ConstellationDetail
{
    std::string name;

    std::string description;

    std::string descriptionRaw;
};

struct CharacterConstellation
{
    int id{};

    std::string name;

    std::array<
        ConstellationDetail,
        6>
        constellations;

    std::array<
        std::string,
        6>
        images;

    std::string version;
};