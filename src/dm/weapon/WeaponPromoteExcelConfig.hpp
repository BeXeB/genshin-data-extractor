#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

#include "dm/PromoteProp.hpp"

struct WeaponPromoteExcelConfig
{
    int weaponPromoteId{};

    int promoteLevel{};
    int unlockMaxLevel{};

    int coinCost{};

    std::vector<PromoteCostItem> costItems;

    std::vector<PromoteProp> addProps;
};

inline void from_json(
    const nlohmann::json &j,
    WeaponPromoteExcelConfig &promote)
{
    promote.weaponPromoteId = j.value("weaponPromoteId", 0);
    promote.promoteLevel = j.value("promoteLevel", 0);
    promote.unlockMaxLevel = j.value("unlockMaxLevel", 0);

    promote.coinCost = j.value("coinCost", 0);

    promote.costItems = j.value("costItems", std::vector<PromoteCostItem>{});
    promote.addProps = j.value("addProps", std::vector<PromoteProp>{});
}