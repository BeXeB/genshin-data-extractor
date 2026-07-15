#include "CharacterExporter.hpp"

#include <filesystem>
#include <fstream>

void CharacterExporter::Export(
    const Character& character,
    const std::string& outputDirectory
) const
{
    std::filesystem::create_directories(outputDirectory);

    const std::string filename =
        outputDirectory
        + "/"
        + character.profile.normalizedName
        + ".json";

    std::ofstream file(filename);

    if (!file)
    {
        throw std::runtime_error(
            "Failed writing: " + filename);
    }

    nlohmann::json json;
    json["profile"] = profileExporter.Export(character.profile);
    json["skills"] = skillsExporter.Export(character.talents);
    json["stats"] = statsExporter.Export(character.stats);
    json["constellation"] = constellationExporter.Export(character.constellation);

    if (!character.variants.empty())
    {
        nlohmann::json variantsJson;

        for (const auto& [element, variant] : character.variants)
        {
            nlohmann::json variantJson;
            variantJson["skills"] = skillsExporter.Export(variant.talents);
            variantJson["constellation"] = constellationExporter.Export(variant.constellation);

            variantsJson[ElementTypeToDM(element)] = variantJson;
        }

        json["variants"] = variantsJson;
    }

    file << json.dump(4);
}