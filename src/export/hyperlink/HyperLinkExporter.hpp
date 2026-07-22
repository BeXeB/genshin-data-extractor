#pragma once

#include <string>
#include <vector>

#include "model/HyperLink.hpp"

class HyperLinkExporter
{
public:
    void Export(
        const std::vector<HyperLink> &hyperlinks,
        const std::string &outputPath) const;
};