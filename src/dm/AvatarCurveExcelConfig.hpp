#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct AvatarCurveInfo
{
    std::string type;
    double value;
};

inline void from_json(
    const nlohmann::json& j,
    AvatarCurveInfo& info)
{
    j.at("type").get_to(info.type);
    j.at("value").get_to(info.value);
}


struct AvatarCurveExcelConfig
{
    int level;
    std::vector<AvatarCurveInfo> curveInfos;
};

inline void from_json(
    const nlohmann::json& j,
    AvatarCurveExcelConfig& curve)
{
    j.at("level").get_to(curve.level);
    j.at("curveInfos").get_to(curve.curveInfos);
}