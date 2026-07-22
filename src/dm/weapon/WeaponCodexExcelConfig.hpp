#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct WeaponCodexExcelConfig
{
    int64_t weaponId{};
    int sortOrder{};
};

inline void from_json(
    const nlohmann::json &j,
    WeaponCodexExcelConfig &codex)
{
    j.at("weaponId").get_to(codex.weaponId);
    j.at("sortOrder").get_to(codex.sortOrder);
}