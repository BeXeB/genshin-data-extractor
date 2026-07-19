#pragma once

#include "dm/HyperLinkNameExcelConfig.hpp"
#include "database/GameDatabase.hpp"

#include "model/HyperLink.hpp"


class HyperLinkBuilder
{
public:

    HyperLink Build(
        const HyperLinkNameExcelConfig& hyperlink,
        const GameDatabase& database) const;
};