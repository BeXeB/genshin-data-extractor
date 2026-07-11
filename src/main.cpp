#include <iostream>
#include <filesystem>

#include "database/GameDatabase.hpp"
#include "builder/character/ProfileBuilder.hpp"
#include "export/character/ProfileExporter.hpp"
#include "util/EnumConverter.hpp"

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

    ProfileBuilder builder;

    ProfileExporter exporter;

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

        auto profile = builder.Build(avatar, db);

        exporter.Export(
            profile,
            outputPath + "/characters"
        );
    }

    return 0;
}