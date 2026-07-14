#include "GameDatabase.hpp"

#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

#include "model/Enums.hpp"
#include "util/EnumConverter.hpp"

void GameDatabase::Load(
    const std::string &path)
{
    textMap.entries.clear();
    avatars.clear();
    fetters.clear();
    avatarPromotes.clear();
    materials.clear();
    avatarCurves.clear();
    skillDepots.clear();
    talents.clear();
    skills.clear();
    proudSkills.clear();

    textMap = LoadJson(
                  path + "/TextMap/TextMap_MediumEN.json")
                  .get<TextMap>();

    LoadAvatars(
        path + "/ExcelBinOutput/AvatarExcelConfigData.json");
    LoadFetterInfo(
        path + "/ExcelBinOutput/FetterInfoExcelConfigData.json");
    LoadAvatarPromoteInfo(
        path + "/ExcelBinOutput/AvatarPromoteExcelConfigData.json");
    LoadMaterials(
        path + "/ExcelBinOutput/MaterialExcelConfigData.json");
    LoadAvatarCurves(
        path + "/ExcelBinOutput/AvatarCurveExcelConfigData.json");
    LoadSkillDepots(
        path + "/ExcelBinOutput/AvatarSkillDepotExcelConfigData.json");
    LoadTalents(
        path + "/ExcelBinOutput/AvatarTalentExcelConfigData.json");
    LoadSkills(
        path + "/ExcelBinOutput/AvatarSkillExcelConfigData.json");
    LoadProudSkills(
        path + "/ExcelBinOutput/ProudSkillExcelConfigData.json");

    std::cout << "Database loaded\n";
}

// Loaders

nlohmann::json GameDatabase::LoadJson(
    const std::string& path) const
{
    std::ifstream file(path);

    if (!file)
    {
        throw std::runtime_error(
            "Failed to open: " + path);
    }

    nlohmann::json json;
    file >> json;

    return json;
}

void GameDatabase::LoadAvatars(
    const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarExcelConfig avatar =
            entry.get<AvatarExcelConfig>();

        avatars.emplace(
            avatar.id,
            std::move(avatar));
    }
}

void GameDatabase::LoadFetterInfo(
    const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        FetterInoExcelConfig fetter =
            entry.get<FetterInoExcelConfig>();

        fetters.emplace(
            fetter.avatarId,
            std::move(fetter));
    }
}

void GameDatabase::LoadAvatarPromoteInfo(
    const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarPromoteExcelConfig promote =
            entry.get<AvatarPromoteExcelConfig>();

        avatarPromotes[promote.avatarPromoteId]
            .push_back(std::move(promote));
    }

    for (auto &[id, promotes] : avatarPromotes)
    {
        std::sort(
            promotes.begin(),
            promotes.end(),
            [](const auto &a, const auto &b)
            {
                return a.promoteLevel < b.promoteLevel;
            });
    }
}

void GameDatabase::LoadMaterials(
    const std::string &path) 
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        MaterialExcelConfig material =
            entry.get<MaterialExcelConfig>();

        materials.emplace(
            material.id,
            std::move(material));
    }
}

void GameDatabase::LoadAvatarCurves(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        AvatarCurveExcelConfig curve =
            entry.get<AvatarCurveExcelConfig>();

        avatarCurves.emplace(
            curve.level,
            std::move(curve));
    }
}

void GameDatabase::LoadSkillDepots(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        AvatarSkillDepotExcelConfig skillDepot =
            entry.get<AvatarSkillDepotExcelConfig>();

        skillDepots.emplace(
            skillDepot.id,
            std::move(skillDepot));
    }
}

void GameDatabase::LoadTalents(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        AvatarTalentExcelConfig talent =
            entry.get<AvatarTalentExcelConfig>();

        talents.emplace(
            talent.talentId,
            std::move(talent));
    }
}

void GameDatabase::LoadSkills(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        AvatarSkillExcelConfig skill =
            entry.get<AvatarSkillExcelConfig>();

        skills.emplace(
            skill.id,
            std::move(skill));
    }
}

void GameDatabase::LoadProudSkills(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        ProudSkillExcelConfig skill =
            entry.get<ProudSkillExcelConfig>();

        proudSkills[skill.proudSkillGroupId]
            .push_back(std::move(skill));
    }

    for (auto& [id, skills] : proudSkills)
    {
        std::sort(
            skills.begin(),
            skills.end(),
            [](const auto& a, const auto& b)
            {
                return a.level < b.level;
            });
    }
}

// Getters

std::string GameDatabase::GetText(uint64_t hash) const
{
    auto it = textMap.entries.find(hash);

    if (it == textMap.entries.end())
        return "";

    return it->second;
}

const AvatarExcelConfig &
GameDatabase::GetAvatar(int id) const
{
    return avatars.at(id);
}

const std::unordered_map<int, AvatarExcelConfig> &
GameDatabase::GetAvatars() const
{
    return avatars;
}

const FetterInoExcelConfig &
GameDatabase::GetFetterInfo(int avatarId) const
{
    return fetters.at(avatarId);
}

const std::vector<AvatarPromoteExcelConfig> &
GameDatabase::GetAvatarPromoteInfo(int promoteId) const
{
    return avatarPromotes.at(promoteId);
}

const MaterialExcelConfig &
GameDatabase::GetMaterial(int id) const
{
    return materials.at(id);
}

const AvatarCurveExcelConfig & 
GameDatabase::GetAvatarCurve(int level) const 
{
    return avatarCurves.at(level);
}

const AvatarSkillDepotExcelConfig&
GameDatabase::GetSkillDepot(int id) const
{
    return skillDepots.at(id);
}

const AvatarTalentExcelConfig &
GameDatabase::GetTalent(int id) const
{
    return talents.at(id);
}

const AvatarSkillExcelConfig&
GameDatabase::GetSkill(
    int id) const
{
    return skills.at(id);
}

const std::vector<ProudSkillExcelConfig>&
GameDatabase::GetProudSkills(
    int proudSkillGroupId) const
{
    return proudSkills.at(proudSkillGroupId);
}