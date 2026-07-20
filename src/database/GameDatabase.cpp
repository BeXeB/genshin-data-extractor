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
    weapons.clear();
    weaponPromotes.clear();
    weaponCurves.clear();
    equipAffixes.clear();
    reliquarySets.clear();
    reliquaries.clear();
    combines.clear();
    avatarCodexes.clear();
    weaponCodexes.clear();
    hyperlinks.clear();

    readableTextLoader.SetPath(path + "/Readable/EN");
    LoadTextMap(path);

    LoadAvatars(path + "/ExcelBinOutput/AvatarExcelConfigData.json");
    LoadFetterInfo(path + "/ExcelBinOutput/FetterInfoExcelConfigData.json");
    LoadAvatarPromoteInfo(path + "/ExcelBinOutput/AvatarPromoteExcelConfigData.json");
    LoadMaterials(path + "/ExcelBinOutput/MaterialExcelConfigData.json");
    LoadAvatarCurves(path + "/ExcelBinOutput/AvatarCurveExcelConfigData.json");
    LoadSkillDepots(path + "/ExcelBinOutput/AvatarSkillDepotExcelConfigData.json");
    LoadTalents(path + "/ExcelBinOutput/AvatarTalentExcelConfigData.json");
    LoadSkills(path + "/ExcelBinOutput/AvatarSkillExcelConfigData.json");
    LoadProudSkills(path + "/ExcelBinOutput/ProudSkillExcelConfigData.json");
    LoadWeapons(path + "/ExcelBinOutput/WeaponExcelConfigData.json");
    LoadEquipAffixes(path + "/ExcelBinOutput/EquipAffixExcelConfigData.json");
    LoadWeaponPromotes(path + "/ExcelBinOutput/WeaponPromoteExcelConfigData.json");
    LoadWeaponCurves(path + "/ExcelBinOutput/WeaponCurveExcelConfigData.json");
    LoadReliquarySets(path + "/ExcelBinOutput/ReliquarySetExcelConfigData.json");
    LoadReliquaries(path + "/ExcelBinOutput/ReliquaryExcelConfigData.json");
    LoadCombines(path + "/ExcelBinOutput/CombineExcelConfigData.json");
    LoadAvaterCodexes(path + "/ExcelBinOutput/AvatarCodexExcelConfigData.json");
    LoadWeaponCodexes(path + "/ExcelBinOutput/WeaponCodexExcelConfigData.json");
    LoadHyperlinks(path + "/ExcelBinOutput/HyperLinkNameExcelConifgData.json");

    std::cout << "Database loaded\n";
}

// Loaders

nlohmann::json GameDatabase::LoadJson(const std::string &path) const
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

void GameDatabase::LoadTextMap(const std::string& path)
{
    auto medium =
        LoadJson(path + "/TextMap/TextMap_MediumEN.json")
        .get<TextMap>();

    auto full =
        LoadJson(path + "/TextMap/TextMapEN.json")
        .get<TextMap>();

    textMap.entries.clear();

    // Medium first
    for (const auto& [hash, value] : medium.entries)
    {
        textMap.entries.emplace(hash, value);
    }

    // Full fills missing entries
    for (const auto& [hash, value] : full.entries)
    {
        textMap.entries.emplace(hash, value);
    }
}

void GameDatabase::LoadAvatars(const std::string &path)
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

void GameDatabase::LoadFetterInfo(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        FetterInfoExcelConfig fetter =
            entry.get<FetterInfoExcelConfig>();

        fetters.emplace(
            fetter.avatarId,
            std::move(fetter));
    }
}

void GameDatabase::LoadAvatarPromoteInfo(const std::string &path)
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

void GameDatabase::LoadMaterials(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        MaterialExcelConfig material =
            entry.get<MaterialExcelConfig>();

        materials.emplace(
            material.id,
            std::move(material));
    }
}

void GameDatabase::LoadAvatarCurves(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarCurveExcelConfig curve =
            entry.get<AvatarCurveExcelConfig>();

        avatarCurves.emplace(
            curve.level,
            std::move(curve));
    }
}

void GameDatabase::LoadSkillDepots(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarSkillDepotExcelConfig skillDepot =
            entry.get<AvatarSkillDepotExcelConfig>();

        skillDepots.emplace(
            skillDepot.id,
            std::move(skillDepot));
    }
}

void GameDatabase::LoadTalents(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarTalentExcelConfig talent =
            entry.get<AvatarTalentExcelConfig>();

        talents.emplace(
            talent.talentId,
            std::move(talent));
    }
}

void GameDatabase::LoadSkills(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        AvatarSkillExcelConfig skill =
            entry.get<AvatarSkillExcelConfig>();

        skills.emplace(
            skill.id,
            std::move(skill));
    }
}

void GameDatabase::LoadProudSkills(const std::string &path)
{
    auto json = LoadJson(path);

    for (const auto &entry : json)
    {
        ProudSkillExcelConfig skill =
            entry.get<ProudSkillExcelConfig>();

        proudSkills[skill.proudSkillGroupId]
            .push_back(std::move(skill));
    }

    for (auto &[id, skills] : proudSkills)
    {
        std::sort(
            skills.begin(),
            skills.end(),
            [](const auto &a, const auto &b)
            {
                return a.level < b.level;
            });
    }
}

void GameDatabase::LoadWeapons(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        WeaponExcelConfig weapon =
            entry.get<WeaponExcelConfig>();

        weapons.emplace(
            weapon.id,
            std::move(weapon));
    }
}

void GameDatabase::LoadEquipAffixes(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        EquipAffixExcelConfig affix =
            entry.get<EquipAffixExcelConfig>();

        equipAffixes[affix.id]
            .push_back(std::move(affix));
    }

    for (auto& [id, affixes] : equipAffixes)
    {
        std::sort(
            affixes.begin(),
            affixes.end(),
            [](const auto& a, const auto& b)
            {
                return a.level < b.level;
            });
    }
}

void GameDatabase::LoadWeaponPromotes(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        WeaponPromoteExcelConfig promote =
            entry.get<WeaponPromoteExcelConfig>();

        weaponPromotes[promote.weaponPromoteId]
            .push_back(std::move(promote));
    }

    for (auto& [id, promotes] : weaponPromotes)
    {
        std::sort(
            promotes.begin(),
            promotes.end(),
            [](const auto& a, const auto& b)
            {
                return a.promoteLevel < b.promoteLevel;
            });
    }
}

void GameDatabase::LoadWeaponCurves(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        WeaponCurveExcelConfig curve =
            entry.get<WeaponCurveExcelConfig>();

        weaponCurves.emplace(
            curve.level,
            std::move(curve));
    }
}

void GameDatabase::LoadReliquarySets(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        ReliquarySetExcelConfig set =
            entry.get<ReliquarySetExcelConfig>();

        reliquarySets.emplace(
            set.setId,
            std::move(set));
    }
}

void GameDatabase::LoadReliquaries(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        ReliquaryExcelConfig reliquary =
            entry.get<ReliquaryExcelConfig>();

        reliquaries[reliquary.setId]
            .push_back(std::move(reliquary));
    }
}

void GameDatabase::LoadCombines(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        CombineExcelConfig combine =
            entry.get<CombineExcelConfig>();

        combines.emplace(
            combine.resultItemId,
            std::move(combine));
    }
}

void GameDatabase::LoadAvaterCodexes(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        AvatarCodexExcelConfig codex =
            entry.get<AvatarCodexExcelConfig>();

        avatarCodexes.emplace(
            codex.avatarId,
            std::move(codex));
    }
}

void GameDatabase::LoadWeaponCodexes(const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        WeaponCodexExcelConfig codex =
            entry.get<WeaponCodexExcelConfig>();

        weaponCodexes.emplace(
            codex.weaponId,
            std::move(codex));
    }
}

void GameDatabase::LoadHyperlinks(
    const std::string& path)
{
    auto json = LoadJson(path);

    for (const auto& entry : json)
    {
        HyperLinkNameExcelConfig hyperlink =
            entry.get<HyperLinkNameExcelConfig>();

        hyperlinks.emplace(
            hyperlink.id,
            std::move(hyperlink));
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

const ReadableTextLoader&
GameDatabase::GetReadableTextLoader() const
{
    return readableTextLoader;
}

const AvatarExcelConfig &GameDatabase::GetAvatar(int id) const
{
    return avatars.at(id);
}

const std::unordered_map<int, AvatarExcelConfig> &GameDatabase::GetAvatars() const
{
    return avatars;
}

const FetterInfoExcelConfig &GameDatabase::GetFetterInfo(int avatarId) const
{
    return fetters.at(avatarId);
}

const std::vector<AvatarPromoteExcelConfig> &GameDatabase::GetAvatarPromoteInfo(int promoteId) const
{
    return avatarPromotes.at(promoteId);
}

const MaterialExcelConfig &GameDatabase::GetMaterial(int id) const
{
    return materials.at(id);
}

const std::unordered_map<int, MaterialExcelConfig>& GameDatabase::GetMaterials() const
{
    return materials;
}

const AvatarCurveExcelConfig &GameDatabase::GetAvatarCurve(int level) const
{
    return avatarCurves.at(level);
}

const AvatarSkillDepotExcelConfig &GameDatabase::GetSkillDepot(int id) const
{
    return skillDepots.at(id);
}

const AvatarTalentExcelConfig &GameDatabase::GetTalent(int id) const
{
    return talents.at(id);
}

const AvatarSkillExcelConfig &GameDatabase::GetSkill(int id) const
{
    return skills.at(id);
}

const std::vector<ProudSkillExcelConfig> &GameDatabase::GetProudSkills(int proudSkillGroupId) const
{
    return proudSkills.at(proudSkillGroupId);
}

const WeaponExcelConfig&GameDatabase::GetWeapon(int id) const
{
    return weapons.at(id);
}

const std::unordered_map<int, WeaponExcelConfig> &GameDatabase::GetWeapons() const
{
    return weapons;
}

const std::vector<EquipAffixExcelConfig> &GameDatabase::GetEquipAffixes(int id) const
{
    return equipAffixes.at(id);
}

const std::vector<WeaponPromoteExcelConfig> &GameDatabase::GetWeaponPromoteInfo(int id) const
{
    return weaponPromotes.at(id);
}

const WeaponCurveExcelConfig &GameDatabase::GetWeaponCurve(int level) const
{
    return weaponCurves.at(level);
}

const ReliquarySetExcelConfig &GameDatabase::GetReliquarySet(int setId) const
{
    return reliquarySets.at(setId);
}

const std::vector<ReliquaryExcelConfig> &GameDatabase::GetReliquaries(int setId) const
{
    return reliquaries.at(setId);
}

const std::unordered_map<int, ReliquarySetExcelConfig> &GameDatabase::GetReliquarySets() const
{
    return reliquarySets;
}

const std::unordered_map<int, CombineExcelConfig> &GameDatabase::GetCombines() const
{
    return combines;
}

const WeaponCodexExcelConfig &GameDatabase::GetWeaponCodex(int weaponId) const
{
    return weaponCodexes.at(weaponId);
}

const AvatarCodexExcelConfig& GameDatabase::GetAvatarCodex(int avatarId) const
{
    return avatarCodexes.at(avatarId);
}

const std::unordered_map<int64_t, HyperLinkNameExcelConfig>& GameDatabase::GetHyperlinks() const
{
    return hyperlinks;
}