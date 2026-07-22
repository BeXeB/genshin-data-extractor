#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

#include "dm/TextMap.hpp"
#include "model/Enums.hpp"
#include "util/ReadableTextLoader.hpp"

#include "dm/MaterialExcelConfig.hpp"
#include "dm/EquipAffixExcelConfig.hpp"
#include "dm/character/FetterInfoExcelConfig.hpp"
#include "dm/character/AvatarExcelConfig.hpp"
#include "dm/character/AvatarPromoteExcelConfig.hpp"
#include "dm/character/AvatarCurveExcelConfig.hpp"
#include "dm/character/AvatarTalentExcelConfig.hpp"
#include "dm/character/AvatarSkillDepotExcelConfig.hpp"
#include "dm/character/AvatarSkillExcelConfig.hpp"
#include "dm/character/ProudSkillExcelConfig.hpp"
#include "dm/weapon/WeaponCurveExcelConfig.hpp"
#include "dm/weapon/WeaponExcelConfig.hpp"
#include "dm/weapon/WeaponPromoteExcelConfig.hpp"
#include "dm/artifact/ReliquarySetExcelConfig.hpp"
#include "dm/artifact/ReliquaryExcelConfig.hpp"
#include "dm/CombineExcelConfig.hpp"
#include "dm/weapon/WeaponCodexExcelConfig.hpp"
#include "dm/character/AvatarCodexExcelConfig.hpp"
#include "dm/HyperLinkNameExcelConfig.hpp"

class GameDatabase
{
public:
    void Load(const std::string &path);

    const AvatarExcelConfig &GetAvatar(int id) const;
    const std::unordered_map<int, AvatarExcelConfig> &GetAvatars() const;
    const FetterInfoExcelConfig &GetFetterInfo(int avatarId) const;
    const std::vector<AvatarPromoteExcelConfig> &GetAvatarPromoteInfo(int promoteId) const;
    const AvatarCurveExcelConfig &GetAvatarCurve(int level) const;
    const AvatarSkillDepotExcelConfig &GetSkillDepot(int id) const;
    const AvatarTalentExcelConfig &GetTalent(int id) const;
    const AvatarSkillExcelConfig &GetSkill(int id) const;
    const std::vector<ProudSkillExcelConfig> &GetProudSkills(int proudSkillGroupId) const;
    const AvatarCodexExcelConfig &GetAvatarCodex(int avatarId) const;

    const WeaponExcelConfig &GetWeapon(int id) const;
    const std::unordered_map<int, WeaponExcelConfig> &GetWeapons() const;
    const std::vector<EquipAffixExcelConfig> &GetEquipAffixes(int id) const;
    const std::vector<WeaponPromoteExcelConfig> &GetWeaponPromoteInfo(int id) const;
    const WeaponCurveExcelConfig &GetWeaponCurve(int level) const;
    const WeaponCodexExcelConfig &GetWeaponCodex(int weaponId) const;

    const ReliquarySetExcelConfig &GetReliquarySet(int setId) const;
    const std::vector<ReliquaryExcelConfig> &GetReliquaries(int setId) const;
    const std::unordered_map<int, ReliquarySetExcelConfig> &GetReliquarySets() const;

    const MaterialExcelConfig &GetMaterial(int id) const;
    const std::unordered_map<int, MaterialExcelConfig> &GetMaterials() const;
    const std::unordered_map<int, CombineExcelConfig> &GetCombines() const;

    const std::unordered_map<int64_t, HyperLinkNameExcelConfig> &GetHyperlinks() const;

    std::string GetText(uint64_t hash) const;
    const ReadableTextLoader &GetReadableTextLoader() const;

private:
    void LoadTextMap(const std::string &path);
    void LoadAvatars(const std::string &path);
    void LoadFetterInfo(const std::string &path);
    void LoadAvatarPromoteInfo(const std::string &path);
    void LoadMaterials(const std::string &path);
    void LoadAvatarCurves(const std::string &path);
    void LoadSkillDepots(const std::string &path);
    void LoadTalents(const std::string &path);
    void LoadSkills(const std::string &path);
    void LoadProudSkills(const std::string &path);
    void LoadWeapons(const std::string &path);
    void LoadEquipAffixes(const std::string &path);
    void LoadWeaponPromotes(const std::string &path);
    void LoadWeaponCurves(const std::string &path);
    void LoadReliquarySets(const std::string &path);
    void LoadReliquaries(const std::string &path);
    void LoadCombines(const std::string &path);
    void LoadAvaterCodexes(const std::string &path);
    void LoadWeaponCodexes(const std::string &path);
    void LoadHyperlinks(const std::string &path);

    TextMap textMap;
    ReadableTextLoader readableTextLoader;

    std::unordered_map<int, AvatarExcelConfig> avatars;
    std::unordered_map<int, FetterInfoExcelConfig> fetters;
    std::unordered_map<int, std::vector<AvatarPromoteExcelConfig>> avatarPromotes;
    std::unordered_map<int, MaterialExcelConfig> materials;
    std::unordered_map<int, AvatarCurveExcelConfig> avatarCurves;
    std::unordered_map<int, AvatarSkillDepotExcelConfig> skillDepots;
    std::unordered_map<int, AvatarTalentExcelConfig> talents;
    std::unordered_map<int, AvatarSkillExcelConfig> skills;
    std::unordered_map<int, std::vector<ProudSkillExcelConfig>> proudSkills;
    std::unordered_map<int, WeaponExcelConfig> weapons;
    std::unordered_map<int, std::vector<EquipAffixExcelConfig>> equipAffixes;
    std::unordered_map<int, std::vector<WeaponPromoteExcelConfig>> weaponPromotes;
    std::unordered_map<int, WeaponCurveExcelConfig> weaponCurves;
    std::unordered_map<int, ReliquarySetExcelConfig> reliquarySets;
    std::unordered_map<int, std::vector<ReliquaryExcelConfig>> reliquaries;
    std::unordered_map<int, CombineExcelConfig> combines;
    std::unordered_map<int, AvatarCodexExcelConfig> avatarCodexes;
    std::unordered_map<int, WeaponCodexExcelConfig> weaponCodexes;
    std::unordered_map<int64_t, HyperLinkNameExcelConfig> hyperlinks;

    nlohmann::json LoadJson(const std::string &path) const;
};