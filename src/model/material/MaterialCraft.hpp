#pragma once

#include <vector>

#include <nlohmann/json.hpp>

#include "model/Item.hpp"

struct MaterialCraft
{
    int id{};

    int resultCount{};

    int moraCost{};

    std::vector<Item> recipe;
};

inline void to_json(
    nlohmann::json &j,
    const MaterialCraft &craft)
{
    j =
        {
            {"id", craft.id},
            {"resultCount", craft.resultCount},
            {"moraCost", craft.moraCost},
            {"recipe", craft.recipe}};
}