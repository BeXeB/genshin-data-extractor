#include "EnumConverter.hpp"

WeaponType WeaponTypeFromDM(
    const std::string &value)
{
    if (value == "WEAPON_SWORD_ONE_HAND")
        return WeaponType::Sword;

    if (value == "WEAPON_CLAYMORE")
        return WeaponType::Claymore;

    if (value == "WEAPON_POLE")
        return WeaponType::Polearm;

    if (value == "WEAPON_BOW")
        return WeaponType::Bow;

    if (value == "WEAPON_CATALYST")
        return WeaponType::Catalyst;

    return WeaponType::Unknown;
}

std::string WeaponTypeToDM(
    WeaponType type)
{
    switch (type)
    {
    case WeaponType::Sword:
        return "WEAPON_SWORD_ONE_HAND";

    case WeaponType::Claymore:
        return "WEAPON_CLAYMORE";

    case WeaponType::Polearm:
        return "WEAPON_POLE";

    case WeaponType::Bow:
        return "WEAPON_BOW";

    case WeaponType::Catalyst:
        return "WEAPON_CATALYST";

    default:
        return "UNKNOWN";
    }
}

std::string WeaponTypeToText(
    WeaponType type)
{
    switch (type)
    {
    case WeaponType::Sword:
        return "Sword";

    case WeaponType::Claymore:
        return "Claymore";

    case WeaponType::Polearm:
        return "Polearm";

    case WeaponType::Bow:
        return "Bow";

    case WeaponType::Catalyst:
        return "Catalyst";

    default:
        return "Unknown";
    }
}

QualityType QualityTypeFromDM(
    const std::string &value)
{
    if (value == "QUALITY_ORANGE")
        return QualityType::FiveStar;

    if (value == "QUALITY_PURPLE")
        return QualityType::FourStar;

    if (value == "QUALITY_BLUE")
        return QualityType::ThreeStar;

    if (value == "QUALITY_GREEN")
        return QualityType::TwoStar;

    if (value == "QUALITY_GREY")
        return QualityType::OneStar;

    return QualityType::Unknown;
}

std::string QualityTypeToDM(
    QualityType type)
{
    switch (type)
    {
    case QualityType::FiveStar:
        return "QUALITY_ORANGE";

    case QualityType::FourStar:
        return "QUALITY_PURPLE";

    case QualityType::ThreeStar:
        return "QUALITY_BLUE";

    case QualityType::TwoStar:
        return "QUALITY_GREEN";

    case QualityType::OneStar:
        return "QUALITY_GREY";

    default:
        return "UNKNOWN";
    }
}

int QualityTypeToRarity(
    QualityType type)
{
    switch (type)
    {
    case QualityType::FiveStar:
        return 5;
    case QualityType::FourStar:
        return 4;
    case QualityType::ThreeStar:
        return 3;
    case QualityType::TwoStar:
        return 2;
    case QualityType::OneStar:
        return 1;
    default:
        return 0;
    }
}

QualityType QualityTypeFromRarity(
    const int value) 
{
    switch (value)
    {
    case 5:
        return QualityType::FiveStar;
    case 4:
        return QualityType::FourStar;
    case 3:
        return QualityType::ThreeStar;
    case 2:
        return QualityType::TwoStar;
    case 1:
        return QualityType::OneStar;
    default:
        return QualityType::Unknown;
    }
}

ElementType ElementTypeFromDM(
    const std::string &value)
{
    if (value == "Pyro")
        return ElementType::Pyro;

    if (value == "Hydro")
        return ElementType::Hydro;

    if (value == "Anemo")
        return ElementType::Anemo;

    if (value == "Electro")
        return ElementType::Electro;

    if (value == "Cryo")
        return ElementType::Cryo;

    if (value == "Geo")
        return ElementType::Geo;

    if (value == "Dendro")
        return ElementType::Dendro;

    if (value == "None")
        return ElementType::None;

    return ElementType::Unknown;
}

std::string ElementTypeToDM(
    ElementType type)
{
    switch (type)
    {
    case ElementType::Pyro:
        return "ELEMENT_PYRO";
    case ElementType::Hydro:
        return "ELEMENT_HYDRO";
    case ElementType::Anemo:
        return "ELEMENT_ANEMO";
    case ElementType::Electro:
        return "ELEMENT_ELECTRO";
    case ElementType::Cryo:
        return "ELEMENT_CRYO";
    case ElementType::Geo:
        return "ELEMENT_GEO";
    case ElementType::Dendro:
        return "ELEMENT_DENDRO";
    case ElementType::None:
        return "ELEMENT_NONE";
    default:
        return "ELEMENT_NONE";
    }
}

std::string ElementTypeToText(
    ElementType type)
{
    switch (type)
    {
    case ElementType::Pyro:
        return "Pyro";
    case ElementType::Hydro:
        return "Hydro";
    case ElementType::Anemo:
        return "Anemo";
    case ElementType::Electro:
        return "Electro";
    case ElementType::Cryo:
        return "Cryo";
    case ElementType::Geo:
        return "Geo";
    case ElementType::Dendro:
        return "Dendro";
    case ElementType::None:
        return "None";
    default:
        return "Unknown";
    }
}

StatType StatTypeFromDM(
    const std::string &value)
{
    if (value == "FIGHT_PROP_BASE_HP")
        return StatType::BaseHp;
    if (value == "FIGHT_PROP_BASE_ATTACK")
        return StatType::BaseAttack;
    if (value == "FIGHT_PROP_BASE_DEFENSE")
        return StatType::BaseDefense;

    if (value == "FIGHT_PROP_HP")
        return StatType::HpFlat;
    if (value == "FIGHT_PROP_HP_PERCENT")
        return StatType::HpPercent;

    if (value == "FIGHT_PROP_ATTACK")
        return StatType::AttackFlat;
    if (value == "FIGHT_PROP_ATTACK_PERCENT")
        return StatType::AttackPercent;

    if (value == "FIGHT_PROP_DEFENSE")
        return StatType::DefenseFlat;
    if (value == "FIGHT_PROP_DEFENSE_PERCENT")
        return StatType::DefensePercent;

    if (value == "FIGHT_PROP_CRITICAL")
        return StatType::CritRate;
    if (value == "FIGHT_PROP_CRITICAL_HURT")
        return StatType::CritDamage;

    if (value == "FIGHT_PROP_HEAL_ADD")
        return StatType::HealingBonus;
    if (value == "FIGHT_PROP_ELEMENT_MASTERY")
        return StatType::ElementalMastery;
    if (value == "FIGHT_PROP_CHARGE_EFFICIENCY")
        return StatType::EnergyRecharge;

    if (value == "FIGHT_PROP_FIRE_ADD_HURT")
        return StatType::PyroDamageBonus;
    if (value == "FIGHT_PROP_WATER_ADD_HURT")
        return StatType::HydroDamageBonus;
    if (value == "FIGHT_PROP_WIND_ADD_HURT")
        return StatType::AnemoDamageBonus;
    if (value == "FIGHT_PROP_ELEC_ADD_HURT")
        return StatType::ElectroDamageBonus;
    if (value == "FIGHT_PROP_ICE_ADD_HURT")
        return StatType::CryoDamageBonus;
    if (value == "FIGHT_PROP_ROCK_ADD_HURT")
        return StatType::GeoDamageBonus;
    if (value == "FIGHT_PROP_PHYSICAL_ADD_HURT")
        return StatType::PhysicalDamageBonus;
    if (value == "FIGHT_PROP_GRASS_ADD_HURT")
        return StatType::DendroDamageBonus;

    return StatType::Unknown;
}

std::string StatTypeToDM(
    StatType type)
{
    switch (type)
    {
    case StatType::BaseHp:
        return "FIGHT_PROP_BASE_HP";
    case StatType::BaseAttack:
        return "FIGHT_PROP_BASE_ATTACK";
    case StatType::BaseDefense:
        return "FIGHT_PROP_BASE_DEFENSE";

    case StatType::HpFlat:
        return "FIGHT_PROP_HP";
    case StatType::HpPercent:
        return "FIGHT_PROP_HP_PERCENT";

    case StatType::AttackFlat:
        return "FIGHT_PROP_ATTACK";
    case StatType::AttackPercent:
        return "FIGHT_PROP_ATTACK_PERCENT";

    case StatType::DefenseFlat:
        return "FIGHT_PROP_DEFENSE";
    case StatType::DefensePercent:
        return "FIGHT_PROP_DEFENSE_PERCENT";

    case StatType::CritRate:
        return "FIGHT_PROP_CRITICAL";
    case StatType::CritDamage:
        return "FIGHT_PROP_CRITICAL_HURT";

    case StatType::HealingBonus:
        return "FIGHT_PROP_HEAL_ADD";
    case StatType::ElementalMastery:
        return "FIGHT_PROP_ELEMENT_MASTERY";
    case StatType::EnergyRecharge:
        return "FIGHT_PROP_CHARGE_EFFICIENCY";

    case StatType::PyroDamageBonus:
        return "FIGHT_PROP_FIRE_ADD_HURT";
    case StatType::HydroDamageBonus:
        return "FIGHT_PROP_WATER_ADD_HURT";
    case StatType::AnemoDamageBonus:
        return "FIGHT_PROP_WIND_ADD_HURT";
    case StatType::ElectroDamageBonus:
        return "FIGHT_PROP_ELEC_ADD_HURT";
    case StatType::CryoDamageBonus:
        return "FIGHT_PROP_ICE_ADD_HURT";
    case StatType::GeoDamageBonus:
        return "FIGHT_PROP_ROCK_ADD_HURT";
    case StatType::PhysicalDamageBonus:
        return "FIGHT_PROP_PHYSICAL_ADD_HURT";
    case StatType::DendroDamageBonus:
        return "FIGHT_PROP_GRASS_ADD_HURT";

    default:
        return "UNKNOWN";
    }
}

std::string StatTypeToText(
    StatType type)
{
    switch (type)
    {
    case StatType::BaseHp:
        return "Base HP";
    case StatType::BaseAttack:
        return "Base ATK";
    case StatType::BaseDefense:
        return "Base DEF";

    case StatType::HpFlat:
        return "HP";
    case StatType::HpPercent:
        return "HP%";

    case StatType::AttackFlat:
        return "ATK";
    case StatType::AttackPercent:
        return "ATK%";

    case StatType::DefenseFlat:
        return "DEF";
    case StatType::DefensePercent:
        return "DEF%";

    case StatType::CritRate:
        return "CRIT Rate";
    case StatType::CritDamage:
        return "CRIT DMG";

    case StatType::HealingBonus:
        return "Healing Bonus";

    case StatType::ElementalMastery:
        return "Elemental Mastery";
    case StatType::EnergyRecharge:
        return "Energy Recharge";

    case StatType::PyroDamageBonus:
        return "Pyro DMG Bonus";
    case StatType::HydroDamageBonus:
        return "Hydro DMG Bonus";
    case StatType::AnemoDamageBonus:
        return "Anemo DMG Bonus";
    case StatType::ElectroDamageBonus:
        return "Electro DMG Bonus";
    case StatType::CryoDamageBonus:
        return "Cryo DMG Bonus";
    case StatType::GeoDamageBonus:
        return "Geo DMG Bonus";
    case StatType::DendroDamageBonus:
        return "Dendro DMG Bonus";
    case StatType::PhysicalDamageBonus:
        return "Physical DMG Bonus";

    default:
        return "Unknown";
    }
}

ArtifactType ArtifactTypeFromDM(
    const std::string &value)
{
    if (value == "EQUIP_BRACER")
        return ArtifactType::Flower;

    if (value == "EQUIP_NECKLACE")
        return ArtifactType::Plume;

    if (value == "EQUIP_SHOES")
        return ArtifactType::Sands;

    if (value == "EQUIP_RING")
        return ArtifactType::Goblet;

    if (value == "EQUIP_DRESS")
        return ArtifactType::Circlet;

    return ArtifactType::Unknown;
}

std::string ArtifactTypeToDM(
    ArtifactType type)
{
    switch (type)
    {
    case ArtifactType::Flower:
        return "EQUIP_BRACER";
    case ArtifactType::Plume:
        return "EQUIP_NECKLACE";
    case ArtifactType::Sands:
        return "EQUIP_SHOES";
    case ArtifactType::Goblet:
        return "EQUIP_RING";
    case ArtifactType::Circlet:
        return "EQUIP_DRESS";
    default:
        return "UNKNOWN";
    }
}

std::string ArtifactTypeToText(
    ArtifactType type)
{
    switch (type)
    {
    case ArtifactType::Flower:
        return "Flower";
    case ArtifactType::Plume:
        return "Plume";
    case ArtifactType::Sands:
        return "Sands";
    case ArtifactType::Goblet:
        return "Goblet";
    case ArtifactType::Circlet:
        return "Circlet";
    default:
        return "Unknown";
    }
}

DmMaterialType DmMaterialTypeFromDM(
    const std::string& value)
{
    if (value == "MATERIAL_ADSORBATE")
        return DmMaterialType::Adsorbate;

    if (value == "MATERIAL_AVATAR_MATERIAL")
        return DmMaterialType::AvatarMaterial;

    if (value == "MATERIAL_CONSUME")
        return DmMaterialType::Consume;

    if (value == "MATERIAL_ELEM_CRYSTAL")
        return DmMaterialType::ElemCrystal;

    if (value == "MATERIAL_EXCHANGE")
        return DmMaterialType::Exchange;

    if (value == "MATERIAL_EXP_FRUIT")
        return DmMaterialType::ExpFruit;

    if (value == "MATERIAL_FISH_BAIT")
        return DmMaterialType::FishBait;

    if (value == "MATERIAL_FISH_ROD")
        return DmMaterialType::FishRod;

    if (value == "MATERIAL_NONE")
        return DmMaterialType::None;

    if (value == "MATERIAL_NOTICE_ADD_HP")
        return DmMaterialType::NoticeAddHp;

    if (value == "MATERIAL_WEAPON_EXP_STONE")
        return DmMaterialType::WeaponExpStone;

    if (value == "MATERIAL_WEAPON_MATERIAL")
        return DmMaterialType::WeaponMaterial;

    if (value == "MATERIAL_WOOD")
        return DmMaterialType::Wood;

    return DmMaterialType::Unknown;
}

std::string DmMaterialTypeToDM(
    DmMaterialType type)
{
    switch (type)
    {
    case DmMaterialType::Adsorbate:
        return "MATERIAL_ADSORBATE";

    case DmMaterialType::AvatarMaterial:
        return "MATERIAL_AVATAR_MATERIAL";

    case DmMaterialType::Consume:
        return "MATERIAL_CONSUME";

    case DmMaterialType::ElemCrystal:
        return "MATERIAL_ELEM_CRYSTAL";

    case DmMaterialType::Exchange:
        return "MATERIAL_EXCHANGE";

    case DmMaterialType::ExpFruit:
        return "MATERIAL_EXP_FRUIT";

    case DmMaterialType::FishBait:
        return "MATERIAL_FISH_BAIT";

    case DmMaterialType::FishRod:
        return "MATERIAL_FISH_ROD";

    case DmMaterialType::None:
        return "MATERIAL_NONE";

    case DmMaterialType::NoticeAddHp:
        return "MATERIAL_NOTICE_ADD_HP";

    case DmMaterialType::WeaponExpStone:
        return "MATERIAL_WEAPON_EXP_STONE";

    case DmMaterialType::WeaponMaterial:
        return "MATERIAL_WEAPON_MATERIAL";

    case DmMaterialType::Wood:
        return "MATERIAL_WOOD";

    default:
        return "UNKNOWN";
    }
}