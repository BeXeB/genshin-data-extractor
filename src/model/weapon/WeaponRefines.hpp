#pragma once

#include <optional>
#include <vector>

#include <nlohmann/json.hpp>

struct WeaponRefine
{
    std::string description;

    std::vector<std::string> values;
};


inline void to_json(
    nlohmann::json& j,
    const WeaponRefine& refine)
{
    j = nlohmann::json{
        {"description", refine.description},
        {"values", refine.values}
    };
}