#pragma once

enum class WeaponType
{
    Sword,
    Claymore,
    Polearm,
    Bow,
    Catalyst,
    Unknown
};

enum class ElementType
{
    Pyro,
    Hydro,
    Anemo,
    Electro,
    Cryo,
    Geo,
    Dendro,
    None,
    Unknown
};

enum class QualityType
{
    OneStar = 1,
    TwoStar = 2,
    ThreeStar = 3,
    FourStar = 4,
    FiveStar = 5,
    Unknown = 0
};

enum class StatType
{
    BaseHp,
    BaseAttack,
    BaseDefense,

    HpFlat,
    HpPercent,
    AttackFlat,
    AttackPercent,
    DefenseFlat,
    DefensePercent,
    EnergyRecharge,
    ElementalMastery,
    CritRate,
    CritDamage,
    HealingBonus,

    PyroDamageBonus,
    HydroDamageBonus,
    AnemoDamageBonus,
    ElectroDamageBonus,
    CryoDamageBonus,
    GeoDamageBonus,
    DendroDamageBonus,
    PhysicalDamageBonus,

    Unknown
};

enum class MaterialType
{
    // These are the ingame types, will need to map these to custom ones
    // Will also need to ignore ones we dont care about
    // ADSORBATE,
    // AVATAR_MATERIAL,
    // CONSUME,
    // ELEM_CRYSTAL,
    // EXCHANGE,
    // EXP_FRUIT,
    // FISH_BAIT,
    // FISH_ROD,
    // NONE,
    // NOTICE_ADD_HP,
    // WEAPON_EXP_STONE,
    // WOOD
    Talent,
    Boss,
    Gemstone,
    LocalSpecialty,
    WeaponMaterial,
    GenericMaterial,
    XpAndMora
};