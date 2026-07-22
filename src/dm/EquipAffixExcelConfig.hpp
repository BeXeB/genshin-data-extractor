#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct Prop
{
    std::string propType{};
    double value{};
};

inline void from_json(
    const nlohmann::json &j,
    Prop &prop)
{
    j.at("propType").get_to(prop.propType);
    j.at("value").get_to(prop.value);
};

struct EquipAffixExcelConfig
{
    int id{};

    int level{};

    uint64_t descTextMapHash{};
    uint64_t nameTextMapHash{};

    std::vector<double> paramList;

    std::vector<Prop> addProps;
};

inline void from_json(
    const nlohmann::json &j,
    EquipAffixExcelConfig &affix)
{
    j.at("id").get_to(affix.id);
    j.at("level").get_to(affix.level);
    j.at("descTextMapHash").get_to(affix.descTextMapHash);
    j.at("nameTextMapHash").get_to(affix.nameTextMapHash);
    j.at("paramList").get_to(affix.paramList);
    j.at("addProps").get_to(affix.addProps);
};