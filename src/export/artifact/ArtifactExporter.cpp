#include "ArtifactExporter.hpp"

#include <filesystem>
#include <fstream>

void ArtifactExporter::Export(
    const std::vector<ArtifactSet> &artifacts,
    const std::string &outputDirectory) const
{
    std::filesystem::create_directories(
        outputDirectory);

    nlohmann::json index =
        nlohmann::json::array();

    for (const auto &artifact : artifacts)
    {
        const std::string filename =
            outputDirectory + "/" + artifact.normalizedName + ".json";

        std::ofstream file(filename);

        if (!file)
        {
            throw std::runtime_error(
                "Failed writing: " + filename);
        }

        file << nlohmann::json(artifact).dump(4);

        index.push_back(
            artifact.normalizedName);
    }

    std::ofstream indexFile(
        outputDirectory + "/index.json");

    if (!indexFile)
    {
        throw std::runtime_error(
            "Failed writing artifact index");
    }

    indexFile << index.dump(4);
}