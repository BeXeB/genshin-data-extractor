#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"

struct MaterialExcelConfig
{
    int id;

    std::string icon;

    uint64_t interactionTitleTextMapHash;

    uint64_t nameTextMapHash;

    uint64_t typeDescTextMapHash;

    int sortRank;

    std::string materialType;
};

inline void from_json(
    const nlohmann::json &j,
    MaterialExcelConfig &material)
{
    j.at("id")
        .get_to(material.id);
    j.at("icon")
        .get_to(material.icon);
    j.at("interactionTitleTextMapHash")
        .get_to(material.interactionTitleTextMapHash);
    j.at("nameTextMapHash")
        .get_to(material.nameTextMapHash);
    j.at("typeDescTextMapHash")
        .get_to(material.typeDescTextMapHash);
    j.at("rank")
        .get_to(material.sortRank);
    j.at("materialType")
        .get_to(material.materialType);
}