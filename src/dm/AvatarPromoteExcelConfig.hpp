#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

#include "PromoteProp.hpp"

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
    j.at("avatarPromoteId").get_to(promote.avatarPromoteId);
    j.at("promoteLevel").get_to(promote.promoteLevel);

    j.at("addProps").get_to(promote.addProps);
    j.at("costItems").get_to(promote.costItems);

    j.at("scoinCost").get_to(promote.scoinCost);
}