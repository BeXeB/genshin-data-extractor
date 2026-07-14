#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "dm/TextMap.hpp"
#include "model/Enums.hpp"

#include "dm/MaterialExcelConfig.hpp"
#include "dm/FetterInoExcelConfig.hpp"
#include "dm/AvatarExcelConfig.hpp"
#include "dm/AvatarPromoteExcelConfig.hpp"
#include "dm/AvatarCurveExcelConfig.hpp"
#include "dm/AvatarTalentExcelConfig.hpp"
#include "dm/AvatarSkillDepotExcelConfig.hpp"
#include "dm/AvatarSkillExcelConfig.hpp"
#include "dm/ProudSkillExcelConfig.hpp"

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

    const AvatarCurveExcelConfig &GetAvatarCurve(
        int level) const;

    const AvatarSkillDepotExcelConfig &GetSkillDepot(
        int id) const;

    const AvatarTalentExcelConfig &GetTalent(
        int id) const;

    const AvatarSkillExcelConfig& GetSkill(
        int id) const;

    const std::vector<ProudSkillExcelConfig>& GetProudSkills(
        int proudSkillGroupId) const;

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

    void LoadAvatarCurves(
        const std::string& path);

    void LoadSkillDepots(
        const std::string& path);

    void LoadTalents(
        const std::string& path);

    void LoadSkills(
        const std::string& path);

    void LoadProudSkills(
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

    std::unordered_map<
        int,
        AvatarCurveExcelConfig>
        avatarCurves;

    std::unordered_map<
        int,
        AvatarSkillDepotExcelConfig>
        skillDepots;

    std::unordered_map<
        int,
        AvatarTalentExcelConfig>
        talents;

    std::unordered_map<
        int,
        AvatarSkillExcelConfig>
        skills;

    std::unordered_map<
        int,
        std::vector<ProudSkillExcelConfig>>
        proudSkills;

    nlohmann::json LoadJson(
        const std::string &path) const;
};