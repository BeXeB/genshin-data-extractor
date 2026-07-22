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
    j.at("setId")
        .get_to(set.setId);

    j.at("equipAffixId")
        .get_to(set.equipAffixId);

    j.at("setNeedNum")
        .get_to(set.setNeedNum);

    j.at("textList")
        .get_to(set.textList);

    j.at("disableFilter")
        .get_to(set.disableFilter);
}