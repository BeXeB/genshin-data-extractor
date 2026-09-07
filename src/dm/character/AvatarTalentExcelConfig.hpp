#pragma once

#include <cstdint>
#include <string>

#include <nlohmann/json.hpp>

struct AvatarTalentExcelConfig
{
    int talentId{};

    uint64_t nameTextMapHash{};

    uint64_t descTextMapHash{};

    std::string icon;
};

inline void from_json(
    const nlohmann::json &j,
    AvatarTalentExcelConfig &talent)
{
    talent.talentId = j.value("talentId", 0);
    talent.nameTextMapHash = j.value("nameTextMapHash", 0ULL);
    talent.descTextMapHash = j.value("descTextMapHash", 0ULL);
    talent.icon = j.value("icon", "");
}