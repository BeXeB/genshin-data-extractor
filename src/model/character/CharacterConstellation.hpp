#pragma once

#include <string>

#include <optional>

#include <nlohmann/json.hpp>

struct ConstellationDetail
{
    std::string name;

    std::string descriptionRaw;
};

inline void to_json(
    nlohmann::json &j,
    const ConstellationDetail &detail)
{
    j = nlohmann::json{
        {"name", detail.name},
        {"descriptionRaw", detail.descriptionRaw}
    };
}

struct CharacterConstellation
{
    int id{};

    ConstellationDetail c1;
    ConstellationDetail c2;
    ConstellationDetail c3;
    ConstellationDetail c4;
    ConstellationDetail c5;
    ConstellationDetail c6;

    struct Images
    {
        std::optional<std::string> filename_c1;
        std::optional<std::string> filename_c2;
        std::optional<std::string> filename_c3;
        std::optional<std::string> filename_c4;
        std::optional<std::string> filename_c5;
        std::optional<std::string> filename_c6;
    } images;
};

inline void to_json(
    nlohmann::json &j,
    const CharacterConstellation &constellation)
{
    j = nlohmann::json{
        {"id", constellation.id},
        {"c1", constellation.c1},
        {"c2", constellation.c2},
        {"c3", constellation.c3},
        {"c4", constellation.c4},
        {"c5", constellation.c5},
        {"c6", constellation.c6}
    };

    j["images"] = nlohmann::json::object();

    if (constellation.images.filename_c1)
        j["images"]["filename_c1"] = *constellation.images.filename_c1;

    if (constellation.images.filename_c2)
        j["images"]["filename_c2"] = *constellation.images.filename_c2;

    if (constellation.images.filename_c3)
        j["images"]["filename_c3"] = *constellation.images.filename_c3;

    if (constellation.images.filename_c4)
        j["images"]["filename_c4"] = *constellation.images.filename_c4;

    if (constellation.images.filename_c5)
        j["images"]["filename_c5"] = *constellation.images.filename_c5;

    if (constellation.images.filename_c6)
        j["images"]["filename_c6"] = *constellation.images.filename_c6;
}