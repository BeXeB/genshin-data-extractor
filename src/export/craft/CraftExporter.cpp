#include "CraftExporter.hpp"

#include <filesystem>
#include <fstream>
#include <stdexcept>

void CraftExporter::Export(
    const std::vector<MaterialCraft>& crafts,
    const std::string& outputDirectory) const
{
    std::filesystem::create_directories(
        outputDirectory);


    const auto filename =
        outputDirectory
        + "/crafts.json";


    std::ofstream file(filename);

    if (!file)
    {
        throw std::runtime_error(
            "Failed writing: " + filename);
    }


    nlohmann::json json = crafts;


    file
        << json.dump(4);
}