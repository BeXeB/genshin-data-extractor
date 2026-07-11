#pragma once

#include <array>
#include <string>

#include <nlohmann/json.hpp>

struct ConstellationDetail
{
    std::string name;

    std::string description;

    std::string descriptionRaw;
};

inline void to_json(
    nlohmann::json &j,
    const ConstellationDetail &detail)
{
    j = nlohmann::json{
        {"name", detail.name},
        {"description", detail.description},
        {"descriptionRaw", detail.descriptionRaw}
    };
}

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
};

inline void to_json(
    nlohmann::json &j,
    const CharacterConstellation &constellation)
{
    j = nlohmann::json{
        {"id", constellation.id},
        {"name", constellation.name},
        {"constellations", constellation.constellations},
        {"images", constellation.images}
    };
}