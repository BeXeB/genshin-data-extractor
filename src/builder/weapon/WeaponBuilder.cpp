#include "WeaponBuilder.hpp"

#include "database/GameDatabase.hpp"

#include "builder/weapon/WeaponAffixBuilder.hpp"
#include "builder/weapon/WeaponPromoteBuilder.hpp"
#include "builder/weapon/WeaponStatBuilder.hpp"
#include "util/Slug.hpp"
#include "util/EnumConverter.hpp"


Weapon WeaponBuilder::Build(
    const GameDatabase& database,
    int id)
{
    const auto& dmWeapon =
        database.GetWeapon(id);

    Weapon weapon;

    weapon.id = dmWeapon.id;

    weapon.name =
        database.GetText(
            dmWeapon.nameTextMapHash);

    weapon.normalizedName =
        Normalize(weapon.name);

    weapon.description =
        database.GetText(
            dmWeapon.descTextMapHash);

    weapon.weaponType =
        dmWeapon.weaponType;

    weapon.rarity =
        dmWeapon.rankLevel;

    weapon.qualityType = 
        QualityTypeToDM(QualityTypeFromRarity(weapon.rarity));

    weapon.images.filename_icon =
        dmWeapon.icon;

    if (!dmWeapon.awakenIcon.empty())
    {
        weapon.images.filename_awakenIcon =
            dmWeapon.awakenIcon;
    }

    weapon.story =
        database.GetReadableTextLoader()
        .Get("Weapon", dmWeapon.id);


    for (const auto& prop : dmWeapon.weaponProp)
    {
        if (prop.propType == "FIGHT_PROP_BASE_ATTACK")
        {
            continue;
        }

        if (prop.propType == "FIGHT_PROP_NONE")
        {
            weapon.mainStatType = std::nullopt;
        }
        else
        {
            weapon.mainStatType = prop.propType;
        }
    }

    if (dmWeapon.skillAffix[0] != 0)
    {
        const auto dmEquipAffixes = database.GetEquipAffixes(dmWeapon.skillAffix[0]);
        const auto dmEquipAffix = dmEquipAffixes[0];

        weapon.effectName = database.GetText(dmEquipAffix.nameTextMapHash);
        weapon.effectTemplateRaw = "";
    }



    auto refinements =
        WeaponAffixBuilder::Build(
            database,
            dmWeapon.skillAffix);

    if (refinements.size() > 0)
        weapon.r1 = refinements[0];

    if (refinements.size() > 1)
        weapon.r2 = refinements[1];

    if (refinements.size() > 2)
        weapon.r3 = refinements[2];

    if (refinements.size() > 3)
        weapon.r4 = refinements[3];

    if (refinements.size() > 4)
        weapon.r5 = refinements[4];


    weapon.costs =
        WeaponPromoteBuilder::Build(
            database,
            dmWeapon.weaponPromoteId);


    weapon.stats =
        WeaponStatBuilder::Build(
            database,
            dmWeapon);

    // Couldn't find a way to get the version, so just set it to unknown for now.
    // Will need to be set manually in the future.
    weapon.version =
        "unknown";

    return weapon;
}