#pragma once

#include "dm/MaterialExcelConfig.hpp"
#include "database/GameDatabase.hpp"

#include "model/material/Material.hpp"

class MaterialBuilder
{
public:
    Material Build(
        const MaterialExcelConfig &material,
        const GameDatabase &database) const;

private:
    MaterialType DetermineType(
        const MaterialExcelConfig &material,
        const GameDatabase &database) const;
};