#pragma once

#include <optional>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "model/artifact/ArtifactPiece.hpp"


struct ArtifactImages
{
    std::optional<std::string> filename_flower;
    std::optional<std::string> filename_plume;
    std::optional<std::string> filename_sands;
    std::optional<std::string> filename_goblet;
    std::optional<std::string> filename_circlet;
};


inline void to_json(
    nlohmann::json& j,
    const ArtifactImages& images)
{
    j = nlohmann::json::object();

    if (images.filename_flower)
        j["filename_flower"] = *images.filename_flower;

    if (images.filename_plume)
        j["filename_plume"] = *images.filename_plume;

    if (images.filename_sands)
        j["filename_sands"] = *images.filename_sands;

    if (images.filename_goblet)
        j["filename_goblet"] = *images.filename_goblet;

    if (images.filename_circlet)
        j["filename_circlet"] = *images.filename_circlet;
}


struct ArtifactSet
{
    int id{};

    std::string name;

    std::string normalizedName;

    std::vector<int> rarityList;

    std::optional<std::string> effect1Pc;
    std::optional<std::string> effect2Pc;
    std::optional<std::string> effect4Pc;

    std::optional<ArtifactPiece> flower;
    std::optional<ArtifactPiece> plume;
    std::optional<ArtifactPiece> sands;
    std::optional<ArtifactPiece> goblet;
    std::optional<ArtifactPiece> circlet;

    ArtifactImages images;
};


inline void to_json(
    nlohmann::json& j,
    const ArtifactSet& artifact)
{
    j = nlohmann::json{
        {"id", artifact.id},
        {"name", artifact.name},
        {"normalizedName", artifact.normalizedName},
        {"rarityList", artifact.rarityList},
        {"images", artifact.images}
    };

    if (artifact.effect1Pc)
        j["effect1Pc"] = *artifact.effect1Pc;

    if (artifact.effect2Pc)
        j["effect2Pc"] = *artifact.effect2Pc;

    if (artifact.effect4Pc)
        j["effect4Pc"] = *artifact.effect4Pc;

    if (artifact.flower)
        j["flower"] = *artifact.flower;

    if (artifact.plume)
        j["plume"] = *artifact.plume;

    if (artifact.sands)
        j["sands"] = *artifact.sands;

    if (artifact.goblet)
        j["goblet"] = *artifact.goblet;

    if (artifact.circlet)
        j["circlet"] = *artifact.circlet;
}