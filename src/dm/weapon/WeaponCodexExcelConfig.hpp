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
    codex.weaponId = j.value("weaponId", 0);
    codex.sortOrder = j.value("sortOrder", 0);
}