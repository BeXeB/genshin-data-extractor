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


    nlohmann::json json =
        profile;

    std::cout << json;

    file
        << json.dump(4);
}