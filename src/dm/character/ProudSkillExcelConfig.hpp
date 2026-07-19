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
    const nlohmann::json& j,
    ProudSkillCostItem& item)
{
    j.at("id")
        .get_to(item.id);

    j.at("count")
        .get_to(item.count);
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
    const nlohmann::json& j,
    ProudSkillExcelConfig& skill)
{
    j.at("proudSkillId")
        .get_to(skill.proudSkillId);

    j.at("proudSkillGroupId")
        .get_to(skill.proudSkillGroupId);

    j.at("level")
        .get_to(skill.level);

    j.at("nameTextMapHash")
        .get_to(skill.nameTextMapHash);

    j.at("descTextMapHash")
        .get_to(skill.descTextMapHash);

    j.at("paramDescList")
        .get_to(skill.paramDescList);

    j.at("paramList")
        .get_to(skill.paramList);

    j.at("costItems")
        .get_to(skill.costItems);
    
    j.at("coinCost")
        .get_to(skill.coinCost);

    j.at("icon")
        .get_to(skill.icon);
}