#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"

struct Artifact
{
    int id{};

    std::string name;

    ArtifactType relicType{};

    std::string description;

    std::string story;

    std::string icon;
};

inline void to_json(
    nlohmann::json& j,
    const Artifact& artifact)
{
    j = nlohmann::json{
        {"id", artifact.id},
        {"name", artifact.name},
        {"relicType", artifact.relicType},
        {"description", artifact.description},
        {"story", artifact.story},
        {"icon", artifact.icon}
    };
}