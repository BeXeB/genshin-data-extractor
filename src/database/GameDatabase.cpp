#include "GameDatabase.hpp"

#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

#include "Enums.hpp"
#include "EnumConverter.hpp"

void GameDatabase::Load(
    const std::string &path)
{
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

    std::cout << "Database loaded\n";
}

std::string GameDatabase::GetText(uint64_t hash) const
{
    auto it = textMap.entries.find(hash);

    if (it == textMap.entries.end())
        return "[Missing:" + std::to_string(hash) + "]";

    return it->second;
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

nlohmann::json GameDatabase::LoadJson(
    const std::string &path) const
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