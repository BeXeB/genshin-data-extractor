#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct CombineMaterialItem
{
    int id{};
    int count{};
};

struct CombineExcelConfig
{
    int resultItemId{};

    int resultItemCount{};

    int scoinCost{};

    std::vector<CombineMaterialItem> materialItems;
};

inline void from_json(
    const nlohmann::json &j,
    CombineMaterialItem &item)
{
    j.at("id")
        .get_to(item.id);

    j.at("count")
        .get_to(item.count);
}

inline void from_json(
    const nlohmann::json &j,
    CombineExcelConfig &combine)
{
    j.at("resultItemId")
        .get_to(combine.resultItemId);

    j.at("resultItemCount")
        .get_to(combine.resultItemCount);

    j.at("scoinCost")
        .get_to(combine.scoinCost);

    j.at("materialItems")
        .get_to(combine.materialItems);
}