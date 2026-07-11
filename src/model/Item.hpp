#pragma once

#include <string>

#include <nlohmann/json.hpp>

struct Item
{
    int id{};

    std::string name;

    int count{};
};

inline void to_json(
    nlohmann::json &j,
    const Item &item)
{
    j = nlohmann::json{
        {"id", item.id},
        {"name", item.name},
        {"count", item.count}};
}
