#include <iostream>
#include <filesystem>

#include "database/GameDatabase.hpp"
#include "util/EnumConverter.hpp"
#include <builder/character/CharacterBuilder.hpp>

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

        if (avatar.id == 10000119) {

            const auto& character = charBuilder.Build(avatar, db);


            nlohmann::json json =
                character;


            std::cout
                << json.dump(4)
                << "\n";
        }

        
    }

    return 0;
}