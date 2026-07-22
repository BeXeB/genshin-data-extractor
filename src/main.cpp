#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <map>
#include <set>

#include "database/GameDatabase.hpp"
#include "util/EnumConverter.hpp"
#include "builder/character/CharacterBuilder.hpp"
#include "builder/weapon/WeaponBuilder.hpp"
#include "export/character/CharacterExporter.hpp"
#include "model/character/Character.hpp"
#include <nlohmann/json.hpp>
#include <builder/artifact/ArtifactBuilder.hpp>
#include <builder/material/MaterialBuilder.hpp>
#include <builder/material/MaterialCraftBuilder.hpp>
#include <builder/hyperlink/HyperLinkBuilder.hpp>
#include <export/hyperlink/HyperLinkExporter.hpp>
#include <export/craft/CraftExporter.hpp>
#include <export/material/MaterialExporter.hpp>
#include <export/artifact/ArtifactExporter.hpp>
#include <export/weapon/WeaponExporter.hpp>

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

    {
        CharacterBuilder charBuilder;
        CharacterExporter charExporter;

        std::vector<Character> characters;


        const auto& avatars = db.GetAvatars();

        for (const auto& [id, avatar] : avatars)
        {
            // Skip test characters
            if (avatar.useType != "AVATAR_FORMAL")
                continue;


            // Skip malformed characters
            try
            {
                db.GetFetterInfo(avatar.id);
            }
            catch (const std::out_of_range&)
            {
                continue;
            }


            // Skip mannequins
            if (avatar.id == 10000117 ||
                avatar.id == 10000118)
            {
                continue;
            }

            try
            {
                characters.push_back(
                    charBuilder.Build(
                        avatar,
                        db));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Character "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }

        charExporter.Export(
            characters,
            outputPath + "/characters");
    }

    {
        WeaponBuilder builder;
        WeaponExporter exporter;

        std::vector<Weapon> weapons;

        for (const auto& [id, config] : db.GetWeapons())
        {
            try
            {
                if (id == 15504 || id == 12505 || id == 15505) 
                {
                    continue;
                }

                weapons.push_back(
                    builder.Build(
                        db,
                        config.id));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Weapon "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }

        exporter.Export(
            weapons,
            outputPath + "/weapons");
    }

    {
        ArtifactBuilder builder;
        ArtifactExporter exporter;

        std::vector<ArtifactSet> artifacts;


        for (const auto& [id, set] : db.GetReliquarySets())
        {
            try
            {
                if (set.disableFilter == 1) 
                {
                    continue;
                }

                artifacts.push_back(
                    builder.Build(
                        id,
                        db));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Artifact "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }


        exporter.Export(
            artifacts,
            outputPath + "/artifacts");
    }

    {
        MaterialBuilder builder;
        MaterialExporter exporter;

        std::vector<Material> materials;


        for (const auto& [id, config] : db.GetMaterials())
        {
            try
            {
                materials.push_back(
                    builder.Build(
                        config,
                        db));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Material "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }


        exporter.Export(
            materials,
            outputPath + "/materials");
    }

    {
        MaterialCraftBuilder builder;
        CraftExporter exporter;


        std::vector<MaterialCraft> crafts;


        for (const auto& [id, config] : db.GetCombines())
        {
            try
            {
                crafts.push_back(
                    builder.Build(
                        config,
                        db));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Craft "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }


        exporter.Export(
            crafts,
            outputPath + "/materials");
    }

    {
        HyperLinkBuilder builder;
        HyperLinkExporter exporter;


        std::vector<HyperLink> links;


        for (const auto& [id, config] : db.GetHyperlinks())
        {
            try
            {
                links.push_back(
                    builder.Build(
                        config,
                        db));
            }
            catch (const std::exception& e)
            {
                std::cerr
                    << "Hyperlink "
                    << id
                    << " failed: "
                    << e.what()
                    << "\n";
            }
        }


        exporter.Export(
            links,
            outputPath);
    }


    std::cout
        << "Export complete\n";

    return 0;
}