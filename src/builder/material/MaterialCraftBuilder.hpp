#pragma once

#include "dm/CombineExcelConfig.hpp"
#include "database/GameDatabase.hpp"

#include "model/material/MaterialCraft.hpp"


class MaterialCraftBuilder
{
public:

    MaterialCraft Build(
        const CombineExcelConfig& combine,
        const GameDatabase& database) const;
};