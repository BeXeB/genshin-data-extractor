#pragma once

#include <string>

#include "model/weapon/Weapon.hpp"

class WeaponExporter
{
public:
    void Export(
        const std::vector<Weapon> &weapons,
        const std::string &outputDirectory) const;
};