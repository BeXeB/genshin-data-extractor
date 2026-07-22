#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"
#include <util/EnumConverter.hpp>

struct ArtifactPiece
{
    std::string name;

    ArtifactType relicType{};

    std::string description;

    std::string story;
};

inline void to_json(
    nlohmann::json &j,
    const ArtifactPiece &piece)
{
    j = nlohmann::json{
        {"name", piece.name},
        {"relicType", ArtifactTypeToDM(piece.relicType)},
        {"description", piece.description},
        {"story", piece.story}};
}