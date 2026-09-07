#include "CharacterProfileBuilder.hpp"

#include <algorithm>
#include <cctype>

#include <fstream>
#include <iostream>

#include "util/Slug.hpp"
#include "util/EnumConverter.hpp"
#include "model/Enums.hpp"

CharacterProfile CharacterProfileBuilder::Build(const AvatarExcelConfig &avatar,
                                                const GameDatabase &db) const
{
    CharacterProfile profile;

    const auto &fetter =
        db.GetFetterInfo(avatar.id);

    profile.id =
        avatar.id;
    profile.name =
        db.GetText(
            avatar.nameTextMapHash);

    switch (avatar.id)
    {
    case 10000005: // Aether
        profile.name = "Aether";
        break;
    case 10000007: // Lumine
        profile.name = "Lumine";
        break;
    }

    profile.normalizedName =
        Normalize(profile.name);

    profile.title =
        db.GetText(
            fetter.avatarTitleTextMapHash);
    profile.description =
        db.GetText(
            fetter.avatarDetailTextMapHash);

    profile.weaponType =
        WeaponTypeFromDM(avatar.weaponType);

    profile.qualityType =
        QualityTypeFromDM(avatar.qualityType);
    profile.rarity =
        QualityTypeToRarity(profile.qualityType);

    profile.birthdayMMDD =
        std::to_string(fetter.infoBirthMonth) + "/" + std::to_string(fetter.infoBirthDay);

    if (profile.birthdayMMDD == "0/0")
    {
        profile.birthdayMMDD = "";
    }

    profile.elementType =
        ElementTypeFromDM(
            db.GetText(
                fetter.avatarVisionBeforTextMapHash));

    profile.affiliation =
        db.GetText(
            fetter.avatarNativeTextMapHash);

    if (profile.affiliation == "-")
    {
        profile.affiliation = "";
    }

    const auto &promotes =
        db.GetAvatarPromoteInfo(
            avatar.avatarPromoteId);

    profile.substatType = GetCharacterSubstat(promotes);

    profile.constellation =
        db.GetText(
            fetter.avatarConstellationBeforTextMapHash);

    profile.ascensionCosts = GetCharacterAscensionCosts(promotes, db);

    // to get the rest of the images we need to get the suffix of the icon,
    // then we can build the rest of the image names from that suffix.
    // We need to do this as I cant find the rest in the dm
    std::string iconSuffix =
        avatar.iconName.substr(
            avatar.iconName.find_last_of('_') + 1);
    profile.images.icon =
        avatar.iconName;
    profile.images.iconCard = "UI_AvatarIcon_" + iconSuffix + "_Card";
    profile.images.sideIcon =
        avatar.sideIconName;
    profile.images.gachaSplash = "UI_Gacha_AvatarImg_" + iconSuffix;
    profile.images.gachaSlice = "UI_Gacha_AvatarIcon_" + iconSuffix;

    if (avatar.id == 10000005 || avatar.id == 10000007)
    {
        profile.sortId = 0;
    }
    else
    {
        const auto codex = db.GetAvatarCodex(avatar.id);
        if (codex.sortFactor != codex.sortId)
        {
            profile.sortId = codex.sortFactor;
        }
        else
        {
            profile.sortId = codex.sortId;
        }
    }

    return profile;
}

StatType CharacterProfileBuilder::GetCharacterSubstat(
    const std::vector<AvatarPromoteExcelConfig> &promotes) const
{
    if (promotes.empty())
    {
        return StatType::Unknown;
    }

    const auto &first = promotes.front();
    for (const auto &prop : first.addProps)
    {
        if (prop.propType == StatTypeToDM(StatType::BaseHp))
            continue;
        if (prop.propType == StatTypeToDM(StatType::BaseAttack))
            continue;
        if (prop.propType == StatTypeToDM(StatType::BaseDefense))
            continue;

        return StatTypeFromDM(
            prop.propType);
    }

    return StatType::Unknown;
}

std::array<std::vector<Item>, 6>
CharacterProfileBuilder::GetCharacterAscensionCosts(
    const std::vector<AvatarPromoteExcelConfig> &promotes,
    const GameDatabase &db) const
{
    std::array<std::vector<Item>, 6> result;

    auto &moraMaterial =
        db.GetMaterial(202);
    std::string moraName =
        db.GetText(moraMaterial.nameTextMapHash);

    for (const auto &promote : promotes)
    {
        if (promote.promoteLevel == 0)
        {
            continue;
        }

        if (promote.promoteLevel < 1 ||
            static_cast<size_t>(promote.promoteLevel) > result.size())
        {
            continue;
        }

        const size_t ascensionIndex =
            static_cast<size_t>(promote.promoteLevel - 1);

        Item mora;
        mora.id = 202;
        mora.name = moraName;
        mora.count = promote.scoinCost;
        result[ascensionIndex].push_back(mora);

        for (const auto &cost : promote.costItems)
        {
            if (cost.id == 0)
            {
                continue;
            }

            auto &material =
                db.GetMaterial(cost.id);

            Item item;

            item.id = material.id;
            item.name =
                db.GetText(material.nameTextMapHash);
            item.count = cost.count;

            result[ascensionIndex].push_back(item);
        }
    }

    return result;
}