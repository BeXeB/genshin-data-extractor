#include "MaterialExporter.hpp"

#include <filesystem>
#include <fstream>
#include <map>
#include <stdexcept>
#include <util/EnumConverter.hpp>

void MaterialExporter::Export(
    const std::vector<Material> &materials,
    const std::string &outputDirectory) const
{
    std::map<std::string, std::vector<Material>> grouped;

    for (const auto &material : materials)
    {
        if (material.type == MaterialType::Unknown)
            continue;

        grouped[MaterialTypeToText(material.type)]
            .push_back(material);
    }

    for (const auto &[type, entries] : grouped)
    {
        const auto folder =
            std::filesystem::path(outputDirectory) / type;

        std::filesystem::create_directories(folder);

        const auto filename =
            folder / "materials.json";

        std::ofstream file(filename);

        if (!file)
        {
            throw std::runtime_error(
                "Failed writing: " + filename.string());
        }

        nlohmann::json json =
            entries;

        file
            << json.dump(4);
    }
}