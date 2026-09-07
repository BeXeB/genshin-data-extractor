#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct FetterInfoExcelConfig
{
    int avatarId;

    // Const Name
    uint64_t avatarConstellationBeforTextMapHash;
    // Detail
    uint64_t avatarDetailTextMapHash;
    // Faction
    uint64_t avatarNativeTextMapHash;
    // Title
    uint64_t avatarTitleTextMapHash;
    // Element
    uint64_t avatarVisionBeforTextMapHash;

    int infoBirthDay;
    int infoBirthMonth;
};

inline void from_json(
    const nlohmann::json &j,
    FetterInfoExcelConfig &fetter)
{
    fetter.avatarId = j.value("avatarId", 0);
    fetter.avatarConstellationBeforTextMapHash = j.value("avatarConstellationBeforTextMapHash", 0ULL);
    fetter.avatarDetailTextMapHash = j.value("avatarDetailTextMapHash", 0ULL);
    fetter.avatarNativeTextMapHash = j.value("avatarNativeTextMapHash", 0ULL);
    fetter.avatarTitleTextMapHash = j.value("avatarTitleTextMapHash", 0ULL);
    fetter.avatarVisionBeforTextMapHash = j.value("avatarVisionBeforTextMapHash", 0ULL);
	fetter.infoBirthDay = j.value("infoBirthDay", 0);
	fetter.infoBirthMonth = j.value("infoBirthMonth", 0);
}