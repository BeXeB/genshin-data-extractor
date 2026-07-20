#pragma once

#include <optional>
#include <string>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"
#include "util/EnumConverter.hpp"

struct MaterialImages
{
    std::string filename_icon;
};

inline void to_json(
    nlohmann::json& j,
    const MaterialImages& images)
{
    j = nlohmann::json{
        {"filename_icon", images.filename_icon}
    };
}


struct Material
{
    int id{};

    std::string name;
    std::string normalizedName;

    std::optional<int> rarity;

    int sortRank{};

    std::string description;

    MaterialType type;

    std::optional<std::string> dropDomainName;

    std::optional<std::vector<std::string>> daysOfWeek;

    MaterialImages images;
};


inline void to_json(
    nlohmann::json& j,
    const Material& material)
{
    j = nlohmann::json{
        {"id", material.id},
        {"name", material.name},
        {"normalizedName", material.normalizedName},
        {"sortRank", material.sortRank},
        {"description", material.description},
        {"type", MaterialTypeToText(material.type)},
        {"images", material.images}
    };

    if (material.rarity)
        j["rarity"] = *material.rarity;

    if (material.dropDomainName)
        j["dropDomainName"] = *material.dropDomainName;

    if (material.daysOfWeek)
        j["daysOfWeek"] = *material.daysOfWeek;
}