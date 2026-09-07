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
    prop.propType = j.value("propType", "");
    prop.value = j.value("value", 0.0);
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
    affix.id = j.value("id", 0);
    affix.level = j.value("level", 0);
    affix.descTextMapHash = j.value("descTextMapHash", 0);
    affix.nameTextMapHash = j.value("nameTextMapHash", 0);
    affix.paramList = j.value("paramList", std::vector<double>{});
    affix.addProps = j.value("addProps", std::vector<Prop>{});
};