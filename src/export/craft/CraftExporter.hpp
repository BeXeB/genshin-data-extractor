#pragma once

#include <string>
#include <vector>

#include "model/material/MaterialCraft.hpp"

class CraftExporter
{
public:
    void Export(
        const std::vector<MaterialCraft> &crafts,
        const std::string &outputDirectory) const;
};