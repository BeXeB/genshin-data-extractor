#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct PromoteProp
{
    std::string propType{};
    double value{};
};

inline void from_json(
    const nlohmann::json &j,
    PromoteProp &prop)
{
    j.at("propType").get_to(prop.propType);
    j.at("value").get_to(prop.value);
}

struct PromoteCostItem
{
    int id;
    int count;
};

inline void from_json(
    const nlohmann::json &j,
    PromoteCostItem &item)
{
    j.at("id").get_to(item.id);
    j.at("count").get_to(item.count);
}

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