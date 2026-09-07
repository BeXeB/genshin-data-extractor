#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct ProudSkillCostItem
{
    int id{};

    int count{};
};

inline void from_json(
    const nlohmann::json &j,
    ProudSkillCostItem &item)
{
    item.id = j.value("id", 0);
    item.count = j.value("count", 0);
}

struct ProudSkillExcelConfig
{
    int proudSkillId{};

    int proudSkillGroupId{};

    int level{};

    uint64_t nameTextMapHash{};

    uint64_t descTextMapHash{};

    std::vector<uint64_t> paramDescList;

    std::vector<double> paramList;

    std::vector<ProudSkillCostItem> costItems;

    int coinCost{};

    std::string icon{};
};

inline void from_json(
    const nlohmann::json &j,
    ProudSkillExcelConfig &skill)
{
    skill.proudSkillId = j.value("proudSkillId", 0);
    skill.proudSkillGroupId = j.value("proudSkillGroupId", 0);
    skill.level = j.value("level", 0);
    skill.nameTextMapHash = j.value("nameTextMapHash", 0);
    skill.descTextMapHash = j.value("descTextMapHash", 0);
    skill.paramDescList = j.value("paramDescList", std::vector<uint64_t>{});
    skill.paramList = j.value("paramList", std::vector<double>{});
    skill.costItems = j.value("costItems", std::vector<ProudSkillCostItem>{});
    skill.coinCost = j.value("coinCost", 0);
    skill.icon = j.value("icon", "");
}