#pragma once

#include <string>
#include <cstdint>

#include <nlohmann/json.hpp>

struct FetterInoExcelConfig
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
    FetterInoExcelConfig &fetter)
{
    j.at("avatarId")
        .get_to(fetter.avatarId);
    j.at("avatarConstellationBeforTextMapHash")
        .get_to(fetter.avatarConstellationBeforTextMapHash);
    j.at("avatarDetailTextMapHash")
        .get_to(fetter.avatarDetailTextMapHash);
    j.at("avatarNativeTextMapHash")
        .get_to(fetter.avatarNativeTextMapHash);
    j.at("avatarTitleTextMapHash")
        .get_to(fetter.avatarTitleTextMapHash);
    j.at("avatarVisionBeforTextMapHash")
        .get_to(fetter.avatarVisionBeforTextMapHash);
    j.at("infoBirthDay")
        .get_to(fetter.infoBirthDay);
    j.at("infoBirthMonth")
        .get_to(fetter.infoBirthMonth);
}