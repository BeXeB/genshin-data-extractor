#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

#include "dm/PromoteProp.hpp"

struct AvatarPromoteExcelConfig
{
    // Type
    int avatarPromoteId;
    // Ascension Level
    int promoteLevel;

    // Stats
    std::vector<PromoteProp> addProps;
    // Materials
    std::vector<PromoteCostItem> costItems;

    // Mora
    int scoinCost;
};

inline void from_json(
    const nlohmann::json &j,
    AvatarPromoteExcelConfig &promote)
{
    promote.avatarPromoteId = j.value("avatarPromoteId", 0);
    promote.promoteLevel = j.value("promoteLevel", 0);

    promote.addProps = j.value("addProps", std::vector<PromoteProp>{});
    promote.costItems = j.value("costItems", std::vector<PromoteCostItem>{});

    promote.scoinCost = j.value("scoinCost", 0);
}