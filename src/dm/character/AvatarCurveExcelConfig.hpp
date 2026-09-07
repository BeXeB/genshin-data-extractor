#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct AvatarCurveInfo
{
    std::string type{};
    double value{};
};

inline void from_json(
    const nlohmann::json& j,
    AvatarCurveInfo& info)
{
    info.type = j.value("type", "");
    info.value = j.value("value", 0.0);
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
    curve.level = j.value("level", 0);
    curve.curveInfos = j.value("curveInfos", std::vector<AvatarCurveInfo>{});
}