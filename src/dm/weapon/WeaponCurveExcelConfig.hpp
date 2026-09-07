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
    curve.arith = j.value("arith", "");
    curve.type = j.value("type", "");
    curve.value = j.value("value", 0.0);
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
    curve.level = j.value("level", 0);
    curve.curveInfos = j.value("curveInfos", std::vector<CurveInfo>{});
}