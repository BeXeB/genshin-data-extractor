#include "MaterialBuilder.hpp"

#include <stdexcept>

#include "util/EnumConverter.hpp"
#include <util/Slug.hpp>

Material MaterialBuilder::Build(
    const MaterialExcelConfig &dmMaterial,
    const GameDatabase &database) const
{
    Material material;

    material.id =
        dmMaterial.id;

    material.name =
        database.GetText(
            dmMaterial.nameTextMapHash);

    material.normalizedName =
        Normalize(material.name);

    material.description =
        database.GetText(
            dmMaterial.descTextMapHash);

    material.sortRank =
        dmMaterial.rank;

    if (dmMaterial.rankLevel > 0)
    {
        material.rarity =
            dmMaterial.rankLevel;
    }

    material.images.filename_icon =
        dmMaterial.icon;

    material.type =
        DetermineType(
            dmMaterial,
            database);

    material.images.filename_icon =
        dmMaterial.icon;

    return material;
}

MaterialType MaterialBuilder::DetermineType(
    const MaterialExcelConfig &material,
    const GameDatabase &database) const
{
    const std::string typeText =
        database.GetText(
            material.typeDescTextMapHash);

    if (typeText == "Character Talent Material")
        return MaterialType::TalentMaterial;

    if (typeText == "Character Level-Up Material")
        return MaterialType::Boss;

    if (typeText == "Character Ascension Material")
        return MaterialType::Gemstone;

    if (typeText.find("Local Specialty") != std::string::npos)
        return MaterialType::LocalSpecialty;

    if (typeText == "Weapon Ascension Material")
        return MaterialType::WeaponMaterial;

    if (typeText == "Character and Weapon Enhancement Material")
        return MaterialType::GenericMaterial;

    if (typeText == "Common Currency")
        return MaterialType::XpAndMora;

    if (typeText == "Character EXP Material")
        return MaterialType::XpAndMora;

    if (typeText == "Weapon Enhancement Material")
        return MaterialType::XpAndMora;

    return MaterialType::Unknown;
}