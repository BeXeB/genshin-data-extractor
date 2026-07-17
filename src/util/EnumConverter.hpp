#pragma once

#include <string>

#include "model/Enums.hpp"

WeaponType WeaponTypeFromDM(
    const std::string &value);
std::string WeaponTypeToDM(
    WeaponType type);
std::string WeaponTypeToText(
    WeaponType type);

QualityType QualityTypeFromDM(
    const std::string &value);
std::string QualityTypeToDM(
    QualityType type);
int QualityTypeToRarity(
    QualityType type);
QualityType QualityTypeFromRarity(
    const int value);

ElementType ElementTypeFromDM(
    const std::string &value);
std::string ElementTypeToDM(
    ElementType type);
std::string ElementTypeToText(
    ElementType type);

StatType StatTypeFromDM(
    const std::string &value);
std::string StatTypeToDM(
    StatType type);
std::string StatTypeToText(
    StatType type);

MaterialType MaterialTypeFromDM(
    const std::string &value);
std::string StatTypeToDM(
    StatType type);
std::string StatTypeToText(
    StatType type);