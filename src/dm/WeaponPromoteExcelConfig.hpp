#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>


struct PromoteProp
{
    std::string propType{};
    double value{};
};


inline void from_json(
    const nlohmann::json& j,
    PromoteProp& prop)
{
    j.at("propType").get_to(prop.propType);
    j.at("value").get_to(prop.value);
}


struct PromoteCostItem
{
    int id{};
    int count{};
};


inline void from_json(
    const nlohmann::json& j,
    PromoteCostItem& item)
{
    j.at("id").get_to(item.id);
    j.at("count").get_to(item.count);
}


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
    const nlohmann::json& j,
    WeaponPromoteExcelConfig& promote)
{
    j.at("weaponPromoteId").get_to(promote.weaponPromoteId);
    j.at("promoteLevel").get_to(promote.promoteLevel);
    j.at("unlockMaxLevel").get_to(promote.unlockMaxLevel);

    j.at("coinCost").get_to(promote.coinCost);

    j.at("costItems").get_to(promote.costItems);
    j.at("addProps").get_to(promote.addProps);
}