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
    item.id = j.value("id", 0);
    item.count = j.value("count", 0);
}

inline void from_json(
    const nlohmann::json &j,
    CombineExcelConfig &combine)
{
    combine.resultItemId = j.value("resultItemId", 0);
    combine.resultItemCount = j.value("resultItemCount", 0);
    combine.scoinCost = j.value("scoinCost", 0);
    combine.materialItems = j.value("materialItems", std::vector<CombineMaterialItem>{});
}