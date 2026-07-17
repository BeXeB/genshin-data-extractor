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