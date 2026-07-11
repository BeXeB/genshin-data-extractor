#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "dm/AvatarExcelConfig.hpp"
#include "dm/FetterInoExcelConfig.hpp"
#include "dm/AvatarPromoteExcelConfig.hpp"
#include "dm/MaterialExcelConfig.hpp"
#include "dm/TextMap.hpp"
#include "model/Enums.hpp"

class GameDatabase
{
public:
    void Load(
        const std::string &path);

    const AvatarExcelConfig &GetAvatar(
        int id) const;

    const std::unordered_map<int, AvatarExcelConfig> &GetAvatars() const;

    const FetterInoExcelConfig &GetFetterInfo(
        int avatarId) const;

    const std::vector<AvatarPromoteExcelConfig> &GetAvatarPromoteInfo(
        int promoteId) const;

    const MaterialExcelConfig &GetMaterial(
        int id) const;


    std::string GetText(
        uint64_t hash) const;

private:
    void LoadAvatars(
        const std::string &path);

    void LoadFetterInfo(
        const std::string &path);

    void LoadAvatarPromoteInfo(
        const std::string &path);

    void LoadMaterials(
        const std::string& path);

    TextMap textMap;

    std::unordered_map<
        int,
        AvatarExcelConfig>
        avatars;

    std::unordered_map<
        int,
        FetterInoExcelConfig>
        fetters;

    std::unordered_map<
        int,
        std::vector<AvatarPromoteExcelConfig>>
        avatarPromotes;

    std::unordered_map<
        int,
        MaterialExcelConfig>
        materials;

    nlohmann::json LoadJson(
        const std::string &path) const;
};