#pragma once

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

struct AvatarCodexExcelConfig
{
    int64_t avatarId{};
    int sortFactor{};
    int sortId{};
};

inline void from_json(
    const nlohmann::json &j,
    AvatarCodexExcelConfig &codex)
{
    codex.avatarId = j.value("avatarId", 0);
    codex.sortFactor = j.value("sortFactor", 0);
    codex.sortId = j.value("sortId", 0);
}