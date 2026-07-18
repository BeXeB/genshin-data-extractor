#include "WeaponStatBuilder.hpp"

#include <stdexcept>

WeaponStats WeaponStatBuilder::Build(
    const WeaponExcelConfig& weapon,
    const GameDatabase& db) const
{
    WeaponStats stats;

    for (int level = 1; level <= 90; level++)
    {
        const int ascension =
            GetAscension(level);

        stats.emplace(
            std::to_string(level),
            BuildStat(
                weapon,
                level,
                ascension,
                db));

        if (IsAscensionLevel(level))
        {
            stats.emplace(
                std::to_string(level) + "+",
                BuildStat(
                    weapon,
                    level,
                    ascension + 1,
                    db));
        }
    }

    return stats;
}

int WeaponStatBuilder::GetAscension(
    int level) const
{
    if (level <= 20)
        return 0;
    if (level <= 40)
        return 1;
    if (level <= 50)
        return 2;
    if (level <= 60)
        return 3;
    if (level <= 70)
        return 4;
    if (level <= 80)
        return 5;

    return 6;
}

bool WeaponStatBuilder::IsAscensionLevel(
    int level) const
{
    return level == 20 ||
        level == 40 ||
        level == 50 ||
        level == 60 ||
        level == 70 ||
        level == 80;
}

WeaponStat WeaponStatBuilder::BuildStat(
    const WeaponExcelConfig& weapon,
    int level,
    int ascension,
    const GameDatabase& db) const
{
    WeaponStat stat;

    stat.level = level;
    stat.ascension = ascension;

    const auto& promotes =
        db.GetWeaponPromoteInfo(
            weapon.weaponPromoteId);

    const WeaponPropGrowCurve* attackProp = nullptr;
    const WeaponPropGrowCurve* secondaryProp = nullptr;

    for (const auto& prop : weapon.weaponProp)
    {
        if (prop.propType == "FIGHT_PROP_BASE_ATTACK")
        {
            attackProp = &prop;
        }
        else if (prop.propType != "FIGHT_PROP_NONE")
        {
            secondaryProp = &prop;
        }
    }

    if (!attackProp)
    {
        throw std::runtime_error(
            "Weapon is missing base attack.");
    }

    stat.attack =
        CalculateBaseStat(
            *attackProp,
            level,
            db)
        + GetAscensionBonus(
            promotes,
            ascension,
            attackProp->propType);

    if (secondaryProp)
    {
        stat.specialized =
            CalculateBaseStat(
                *secondaryProp,
                level,
                db)
            + GetAscensionBonus(
                promotes,
                ascension,
                secondaryProp->propType);
    }

    return stat;
}

double WeaponStatBuilder::CalculateBaseStat(
    const WeaponPropGrowCurve& prop,
    int level,
    const GameDatabase& db) const
{
    return prop.initValue *
        GetCurveMultiplier(
            prop,
            level,
            db);
}

double WeaponStatBuilder::GetCurveMultiplier(
    const WeaponPropGrowCurve& prop,
    int level,
    const GameDatabase& db) const
{
    const auto& curve =
        db.GetWeaponCurve(level);

    for (const auto& info : curve.curveInfos)
    {
        if (info.type == prop.type)
        {
            return info.value;
        }
    }

    throw std::runtime_error(
        "Missing curve value for '" +
        prop.type +
        "' at level " +
        std::to_string(level));
}

double WeaponStatBuilder::GetAscensionBonus(
    const std::vector<WeaponPromoteExcelConfig>& promotes,
    int ascension,
    const std::string& propType) const
{
    if (ascension == 0)
    {
        return 0.0;
    }

    if (ascension < 0 ||
        static_cast<size_t>(ascension) >= promotes.size())
    {
        return 0.0;
    }

    const auto& promote =
        promotes.at(ascension);

    for (const auto& prop : promote.addProps)
    {
        if (prop.propType == propType)
        {
            return prop.value;
        }
    }

    return 0.0;
}