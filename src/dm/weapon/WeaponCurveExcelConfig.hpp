#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct CurveInfo
{
    std::string arith{};
    std::string type{};
    double value{};
};

inline void from_json(
    const nlohmann::json &j,
    CurveInfo &curve)
{
    j.at("arith").get_to(curve.arith);
    j.at("type").get_to(curve.type);
    j.at("value").get_to(curve.value);
}

struct WeaponCurveExcelConfig
{
    int level{};

    std::vector<CurveInfo> curveInfos;
};

inline void from_json(
    const nlohmann::json &j,
    WeaponCurveExcelConfig &curve)
{
    j.at("level").get_to(curve.level);
    j.at("curveInfos").get_to(curve.curveInfos);
}