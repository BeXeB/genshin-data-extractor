#include "ProfileBuilder.hpp"

#include <algorithm>
#include <cctype>
#include "../../util/Slug.hpp"
#include "../../util/EnumConverter.hpp"
#include "../../model/Enums.hpp"

CharacterProfile ProfileBuilder::Build(const AvatarExcelConfig &avatar,
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

    profile.elementType =
        ElementTypeFromDM(
            db.GetText(
                fetter.avatarVisionBeforTextMapHash));

    profile.affiliation =
        db.GetText(
            fetter.avatarNativeTextMapHash);

    profile.substatType =
        db.GetCharacterSubstat(
            avatar.id);

    profile.constellation =
        db.GetText(
            fetter.avatarConstellationBeforTextMapHash);

    // ascensionCosts

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

    // Couldn't find a way to get the version, so just set it to unknown for now.
    // Will need to be set manually in the future.
    profile.version =
        "unknown";

    profile.isTraveler =
        profile.id == 10000005 || profile.id == 10000007;

    return profile;
}
