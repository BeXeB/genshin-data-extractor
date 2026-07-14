#pragma once

#include <optional>
#include <vector>

#include <nlohmann/json.hpp>

struct CharacterStat
{
    int level{};

    int ascension{};

    double hp{};

    double attack{};

    double defense{};

    double specialized{};
};

inline void to_json(
    nlohmann::json &j,
    const CharacterStat &stat)
{
    j = nlohmann::json{
        {"level", stat.level},
        {"ascension", stat.ascension},
        {"hp", stat.hp},
        {"attack", stat.attack},
        {"defense", stat.defense},
        {"specialized", stat.specialized}};
}

using CharacterStats =
    std::unordered_map<std::string, CharacterStat>;

inline void to_json(
    nlohmann::json& j,
    const CharacterStats& stats)
{
    j = nlohmann::json::object();

    for (const auto& [key, value] : stats)
    {
        j[key] = value;
    }
}