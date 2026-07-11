#pragma once

#include <array>
#include <string>
#include <vector>

#include "Enums.hpp"
#include "Item.hpp"

struct CharacterImages
{
    std::string icon;
    std::string iconCard;
    std::string sideIcon;
    std::string gachaSplash;
    std::string gachaSlice;
};

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

    bool isTraveler = false;
};