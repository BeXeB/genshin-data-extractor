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