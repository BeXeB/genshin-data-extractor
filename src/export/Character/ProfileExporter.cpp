#include "ProfileExporter.hpp"

#include <fstream>
#include <filesystem>
#include <iostream>

#include <nlohmann/json.hpp>

#include "util/Slug.hpp"

nlohmann::json ProfileExporter::Export(
    const CharacterProfile &profile) const
{
    nlohmann::json json = profile;

    nlohmann::json costs;

    for (size_t i = 0; i < profile.ascensionCosts.size(); i++)
    {
        costs["ascend" + std::to_string(i + 1)] =
            profile.ascensionCosts[i];
    }

    json["costs"] = costs;

    return json;
}