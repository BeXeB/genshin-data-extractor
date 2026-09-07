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
    prop.propType = j.value("propType", "");
    prop.value = j.value("value", 0.0);
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
    item.id = j.value("id", 0);
    item.count = j.value("count", 0);
}