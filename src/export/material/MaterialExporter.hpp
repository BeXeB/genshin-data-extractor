#pragma once

#include <string>
#include <vector>

#include "model/material/Material.hpp"

class MaterialExporter
{
public:
    void Export(
        const std::vector<Material> &materials,
        const std::string &outputDirectory) const;
};