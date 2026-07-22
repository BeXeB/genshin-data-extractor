#include "CharacterExporter.hpp"

#include <filesystem>
#include <fstream>

void CharacterExporter::Export(
    const std::vector<Character> &characters,
    const std::string &outputDirectory) const
{
    std::filesystem::create_directories(outputDirectory);

    nlohmann::json profiles =
        nlohmann::json::array();

    nlohmann::json index = nlohmann::json::array();

    for (const auto &character : characters)
    {
        const std::string filename =
            outputDirectory + "/" + character.profile.normalizedName + ".json";

        std::ofstream file(filename);

        if (!file)
        {
            throw std::runtime_error(
                "Failed writing: " + filename);
        }

        nlohmann::json json;

        json["profile"] =
            profileExporter.Export(
                character.profile);

        json["stats"] =
            statsExporter.Export(
                character.stats);

        if (character.variants.empty())
        {
            json["skills"] =
                skillsExporter.Export(
                    character.talents);

            json["constellation"] =
                constellationExporter.Export(
                    character.constellation);
        }

        if (!character.variants.empty())
        {
            nlohmann::json variantsJson;

            for (const auto &[element, variant] : character.variants)
            {
                variantsJson[ElementTypeToDM(element)] =
                    {
                        {"skills",
                         skillsExporter.Export(
                             variant.talents)},

                        {"constellation",
                         constellationExporter.Export(
                             variant.constellation)}};
            }

            json["variants"] = variantsJson;
        }

        file << json.dump(4);

        profiles.push_back(
            character.profile);

        index.push_back(
            character.profile.normalizedName);
    }

    std::ofstream profileFile(
        outputDirectory + "/profiles.json");

    std::ofstream indexFile(
        outputDirectory + "/index.json");

    profileFile << profiles.dump(4);
}