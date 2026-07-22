#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct HyperLinkNameExcelConfig
{
    int64_t id{};
    int64_t descTextMapHash{};
    int64_t nameTextMapHash{};
};

inline void from_json(
    const nlohmann::json &j,
    HyperLinkNameExcelConfig &hyperlink)
{
    j.at("id").get_to(hyperlink.id);
    j.at("descTextMapHash").get_to(hyperlink.descTextMapHash);
    j.at("nameTextMapHash").get_to(hyperlink.nameTextMapHash);
};