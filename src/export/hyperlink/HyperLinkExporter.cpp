#include "HyperLinkExporter.hpp"

#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

void HyperLinkExporter::Export(
    const std::vector<HyperLink> &hyperlinks,
    const std::string &outputPath) const
{
    nlohmann::json json =
        hyperlinks;

    std::filesystem::create_directories(
        outputPath);

    std::ofstream file(
        std::filesystem::path(outputPath) /
        "hyperlinks.json");

    if (!file)
    {
        throw std::runtime_error(
            "Failed writing hyperlinks.json");
    }

    file
        << json.dump(4);
}