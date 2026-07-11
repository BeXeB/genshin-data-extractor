#pragma once

#include <array>
#include <string>
#include <vector>

#include "Enums.hpp"
#include "EnumConverter.hpp"
#include "Item.hpp"

#include <nlohmann/json.hpp>

struct CharacterImages
{
    std::string icon;
    std::string iconCard;
    std::string sideIcon;
    std::string gachaSplash;
    std::string gachaSlice;
};

inline void to_json(
    nlohmann::json &j,
    const CharacterImages &images)
{
    j = nlohmann::json{
        {"icon", images.icon},
        {"iconCard", images.iconCard},
        {"sideIcon", images.sideIcon},
        {"gachaSplash", images.gachaSplash},
        {"gachaSlice", images.gachaSlice}};
}

struct CharacterProfile
{
    int id{};
    std::string name;
    std::string normalizedName;

    std::string title;
    std::string description;

    WeaponType weaponType{
        WeaponType::Unknown};

    QualityType qualityType{
        QualityType::Unknown};
    int rarity{};

    std::string birthdayMMDD;

    ElementType elementType{
        ElementType::Unknown};

    std::string affiliation;

    StatType substatType{
        StatType::Unknown};

    std::string constellation;

    std::array<std::vector<Item>, 6>
        ascensionCosts;

    CharacterImages images;

    std::string version;
};

inline void to_json(
    nlohmann::json &j,
    const CharacterProfile &profile)
{
    j = nlohmann::json{
        {"id", profile.id},
        {"name", profile.name},
        {"normalizedName", profile.normalizedName},
        {"title", profile.title},
        {"description", profile.description},
        {"weaponType", WeaponTypeToDM(profile.weaponType)},
        {"qualityType", QualityTypeToDM(profile.qualityType)},
        {"rarity", profile.rarity},
        {"birthdaymmdd", profile.birthdayMMDD},
        {"elementType", ElementTypeToDM(profile.elementType)},
        {"affiliation", profile.affiliation},
        {"substatType", StatTypeToDM(profile.substatType)},
        {"constellation", profile.constellation},
        {"images", profile.images},
        {"version", profile.version},
}