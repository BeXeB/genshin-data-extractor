#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct MaterialExcelConfig
{
    int id{};

    std::string icon;

    uint64_t nameTextMapHash{};
    uint64_t descTextMapHash{};
    uint64_t typeDescTextMapHash{};

    int rank{};
    int rankLevel{};

    std::string materialType;
};


inline void from_json(
    const nlohmann::json& j,
    MaterialExcelConfig& material)
{
    j.at("id")
        .get_to(material.id);

    j.at("icon")
        .get_to(material.icon);

    j.at("nameTextMapHash")
        .get_to(material.nameTextMapHash);

    j.at("descTextMapHash")
        .get_to(material.descTextMapHash);

    j.at("typeDescTextMapHash")
        .get_to(material.typeDescTextMapHash);

    j.at("rank")
        .get_to(material.rank);

    j.at("rankLevel")
        .get_to(material.rankLevel);

    j.at("materialType")
        .get_to(material.materialType);
}