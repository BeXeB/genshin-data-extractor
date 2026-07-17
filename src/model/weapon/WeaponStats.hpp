#pragma once

#include <optional>
#include <vector>

#include <nlohmann/json.hpp>


struct WeaponStat
{
    int level{};

    int ascension{};

    std::optional<double> attack;

    std::optional<double> specialized;
};


inline void to_json(
    nlohmann::json& j,
    const WeaponStat& stat)
{
    j = nlohmann::json{
        {"level", stat.level},
        {"ascension", stat.ascension}
    };

    if (stat.attack)
        j["attack"] = *stat.attack;

    if (stat.specialized)
        j["specialized"] = *stat.specialized;
}


using WeaponStats = std::map<std::string, WeaponStat>;

inline void to_json(
    nlohmann::json& j,
    const WeaponStats& stats)
{
    j = nlohmann::json::object();

    for (const auto& [key, value] : stats)
    {
        j[key] = value;
    }
}