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
    hyperlink.id = j.value("id", 0LL);
    hyperlink.descTextMapHash = j.value("descTextMapHash", 0LL);
    hyperlink.nameTextMapHash = j.value("nameTextMapHash", 0LL);
};