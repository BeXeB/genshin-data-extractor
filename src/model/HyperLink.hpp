#pragma once

#include <string>

#include <nlohmann/json.hpp>


struct HyperLink
{
    int64_t id{};

    std::string name;

    std::string description;
};


inline void to_json(
    nlohmann::json& j,
    const HyperLink& hyperlink)
{
    j =
    {
        {"id", hyperlink.id},
        {"name", hyperlink.name},
        {"description", hyperlink.description}
    };
}