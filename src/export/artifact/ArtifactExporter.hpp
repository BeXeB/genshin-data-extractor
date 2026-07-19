#pragma once

#include <string>

#include "model/artifact/ArtifactSet.hpp"


class ArtifactExporter
{
public:
    void Export(
        const std::vector<ArtifactSet>& artifacts,
        const std::string& outputDirectory) const;
};