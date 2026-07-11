#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include <nlohmann/json.hpp>

struct TextMap
{
    std::unordered_map<uint64_t, std::string> entries;
};

inline void from_json(
    const nlohmann::json &j,
    TextMap &textMap)
{
    for (auto &[key, value] : j.items())
    {
        uint64_t hash =
            std::stoull(key);

        textMap.entries[hash] =
            value.get<std::string>();
    }
}