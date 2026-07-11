#include "ProfileExporter.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

#include "Slug.hpp"
#include <iostream>


void ProfileExporter::Export(
    const CharacterProfile& profile,
    const std::string& outputDirectory
) const
{
    std::filesystem::create_directories(
        outputDirectory
    );


    std::string filename =
        outputDirectory
        + "/"
        + profile.normalizedName
        + ".json";


    std::ofstream file(filename);


    if (!file)
    {
        throw std::runtime_error(
            "Failed writing: " + filename
        );
    }


    nlohmann::json json = profile;

    nlohmann::json costs;

    for (size_t i = 0; i < profile.ascensionCosts.size(); i++)
    {
        costs["ascend" + std::to_string(i + 1)] =
            profile.ascensionCosts[i];
    }

    json["costs"] = costs;

    file
        << json.dump(4);
}