#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "database/GameDatabase.hpp"
#include "util/EnumConverter.hpp"
#include "builder/character/CharacterBuilder.hpp"
#include "builder/weapon/WeaponBuilder.hpp"
#include "export/character/CharacterExporter.hpp"
#include "model/character/Character.hpp"
#include <nlohmann/json.hpp>

int main()
{
    const std::string dbPath = (std::filesystem::path(PROJECT_ROOT) / "data/animegamedata2").string();
    const std::string outputPath = (std::filesystem::path(PROJECT_ROOT) / "output").string();

    GameDatabase db;

    try
    {
        db.Load(dbPath);
    }
    catch (const std::exception &e)
    {
        std::cerr
            << "Failed loading database: "
            << e.what()
            << "\n";

        return 1;
    }

    CharacterBuilder charBuilder;
    CharacterExporter charExporter;
    std::vector<CharacterProfile> profiles;

    const auto& avatars = db.GetAvatars();

    for (const auto &[id, avatar] : avatars)
    {
        // Skip test characters
        if (avatar.useType != "AVATAR_FORMAL")
            continue;
        
        // There are some avatars that are malformed, so we need to skip them
        try
        {
            db.GetFetterInfo(avatar.id);
        }
        catch (const std::out_of_range &)
        {
            continue;
        }

        // Skipping manekins
        if (avatar.id == 10000117 || avatar.id == 10000118) 
        {
            continue;
        }

        const auto& character = charBuilder.Build(avatar, db);
        //charExporter.Export(character, outputPath + "/characters");
        profiles.push_back(character.profile);
    }

    //nlohmann::json profilesJson = profiles;

    //std::ofstream profilesFile(
    //    std::filesystem::path(outputPath) / "characters/profiles.json");

    //if (!profilesFile)
    //{
    //    std::cerr
    //        << "Failed writing profiles.json\n";

    //    return 1;
    //}

    //profilesFile << profilesJson.dump(4);

    WeaponBuilder weaponBuilder;

    const auto& weapons = db.GetWeapons();

    for (const auto& [id, weapon] : weapons)
    {
        try
        {
            if (id == 12514) {
                const auto builtWeapon =
                    weaponBuilder.Build(db, id);

                nlohmann::json json = builtWeapon;

                std::cout
                    << json.dump(4)
                    << "\n";
            }
        }
        catch (const std::exception& e)
        {
            std::cerr
                << "Failed weapon "
                << id
                << ": "
                << e.what()
                << "\n";
        }
    }

    return 0;
}