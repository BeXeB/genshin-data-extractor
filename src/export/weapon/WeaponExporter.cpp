#include "WeaponExporter.hpp"

#include <filesystem>
#include <fstream>
#include <stdexcept>

void WeaponExporter::Export(
    const std::vector<Weapon> &weapons,
    const std::string &outputDirectory) const
{
    std::filesystem::create_directories(outputDirectory);

    nlohmann::json index = nlohmann::json::array();

    for (const auto &weapon : weapons)
    {
        const auto filename =
            outputDirectory + "/" + weapon.normalizedName + ".json";

        std::ofstream file(filename);

        if (!file)
        {
            throw std::runtime_error(
                "Failed writing: " + filename);
        }

        file << nlohmann::json(weapon).dump(4);

        index.push_back(
            weapon.normalizedName);
    }

    std::ofstream indexFile(
        outputDirectory + "/index.json");

    indexFile << index.dump(4);
}