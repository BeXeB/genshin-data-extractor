#pragma once

#include <cstdint>
#include <vector>

#include <nlohmann/json.hpp>

struct ReliquarySetExcelConfig
{
    int setId{};

    int equipAffixId{};

    std::vector<int> setNeedNum;

    std::vector<uint64_t> textList;

    int disableFilter{};
};

inline void from_json(
    const nlohmann::json &j,
    ReliquarySetExcelConfig &set)
{
    set.setId = j.value("setId", 0);
    set.equipAffixId = j.value("equipAffixId", 0);
    set.setNeedNum = j.value("setNeedNum", std::vector<int>{});
    set.textList = j.value("textList", std::vector<uint64_t>{});
    set.disableFilter = j.value("disableFilter", 0);
}