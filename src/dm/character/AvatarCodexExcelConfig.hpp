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
    const nlohmann::json& j,
    AvatarCodexExcelConfig& codex)
{
    j.at("avatarId").get_to(codex.avatarId);
    j.at("sortFactor").get_to(codex.sortFactor);
    j.at("sortId").get_to(codex.sortId);
}