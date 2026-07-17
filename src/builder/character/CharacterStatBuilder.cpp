#include "CharacterStatBuilder.hpp"
#include <iostream>

CharacterStats CharacterStatBuilder::Build(
    const AvatarExcelConfig& avatar,
    const GameDatabase& db
) const
{
    CharacterStats stats;

    for (int level = 1; level <= 90; level++)
    {
        const int ascension = GetAscension(level);

        stats.emplace(
            std::to_string(level),
            BuildStat(
                avatar,
                level,
                ascension,
                db));

        if (IsAscensionLevel(level))
        {
            stats.emplace(
                std::to_string(level) + "+",
                BuildStat(
                    avatar,
                    level,
                    ascension + 1,
                    db));
        }
    }

    stats["95"] =
        BuildStat(
            avatar,
            95,
            6,
            db);

    stats["100"] =
        BuildStat(
            avatar,
            100,
            6,
            db);

    return stats;
}

int CharacterStatBuilder::GetAscension(
    int level
) const
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

bool CharacterStatBuilder::IsAscensionLevel(
    int level
) const
{
    return level == 20 ||
        level == 40 ||
        level == 50 ||
        level == 60 ||
        level == 70 ||
        level == 80;
}

CharacterStat CharacterStatBuilder::BuildStat(
    const AvatarExcelConfig& avatar,
    int level,
    int ascension,
    const GameDatabase& db
) const
{
    CharacterStat stat;

    stat.level = level;
    stat.ascension = ascension;

    const auto& promotes =
        db.GetAvatarPromoteInfo(
            avatar.avatarPromoteId);

    stat.hp =
        CalculateBaseStat(
            avatar,
            level,
            db,
            "FIGHT_PROP_BASE_HP")
        + GetAscensionBonus(
            promotes,
            ascension,
            "FIGHT_PROP_BASE_HP");

    stat.attack =
        CalculateBaseStat(
            avatar,
            level,
            db,
            "FIGHT_PROP_BASE_ATTACK")
        + GetAscensionBonus(
            promotes,
            ascension,
            "FIGHT_PROP_BASE_ATTACK");

    stat.defense =
        CalculateBaseStat(
            avatar,
            level,
            db,
            "FIGHT_PROP_BASE_DEFENSE")
        + GetAscensionBonus(
            promotes,
            ascension,
            "FIGHT_PROP_BASE_DEFENSE");

    stat.specialized =
        GetSpecializedStat(
            avatar,
            promotes, 
            ascension);

    return stat;
}

double CharacterStatBuilder::GetCurveMultiplier(
    const AvatarExcelConfig& avatar,
    int level,
    const GameDatabase& db,
    const std::string& propType
) const
{
    // Find the growth curve used by this stat.
    std::string curveType;

    for (const auto& curve : avatar.propGrowCurves)
    {
        if (curve.type == propType)
        {
            curveType = curve.growCurve;
            break;
        }
    }

    if (curveType.empty())
    {
        throw std::runtime_error(
            "Missing growth curve for prop: " + propType);
    }

    // Look up the curve data for this level.
    const auto& avatarCurve =
        db.GetAvatarCurve(level);

    for (const auto& curveInfo : avatarCurve.curveInfos)
    {
        if (curveInfo.type == curveType)
        {
            return curveInfo.value;
        }
    }

    throw std::runtime_error(
        "Missing curve value for '" +
        curveType +
        "' at level " +
        std::to_string(level));
}

double CharacterStatBuilder::CalculateBaseStat(
    const AvatarExcelConfig& avatar,
    int level,
    const GameDatabase& db,
    const std::string& propType
) const
{
    double baseStat = 0.0;

    if (propType == "FIGHT_PROP_BASE_HP")
    {
        baseStat = avatar.hpBase;
    }
    else if (propType == "FIGHT_PROP_BASE_ATTACK")
    {
        baseStat = avatar.attackBase;
    }
    else if (propType == "FIGHT_PROP_BASE_DEFENSE")
    {
        baseStat = avatar.defenseBase;
    }
    else
    {
        throw std::runtime_error("Unknown base stat: " + propType);
    }

    return baseStat *
        GetCurveMultiplier(
            avatar,
            level,
            db,
            propType);
}

double CharacterStatBuilder::GetAscensionBonus(
    const std::vector<AvatarPromoteExcelConfig>& promotes,
    int ascension,
    const std::string& propType
) const
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

    const auto& promote = promotes.at(ascension);

    for (const auto& prop : promote.addProps)
    {
        if (prop.propType == propType)
        {
            return prop.value;
        }
    }

    return 0.0;
}

double CharacterStatBuilder::GetSpecializedStat(
    const AvatarExcelConfig& avatar,
    const std::vector<AvatarPromoteExcelConfig>& promotes,
    int ascension
) const
{
    std::string propType;
    double result = 0.0;

    if (
        static_cast<size_t>(ascension) < promotes.size())
    {
        const auto& promote =
            promotes.at(ascension);

        for (const auto& prop : promote.addProps)
        {
            if (prop.propType == "FIGHT_PROP_BASE_HP")
                continue;

            if (prop.propType == "FIGHT_PROP_BASE_ATTACK")
                continue;

            if (prop.propType == "FIGHT_PROP_BASE_DEFENSE")
                continue;

            propType = prop.propType;

            if (propType == "FIGHT_PROP_ELEMENT_MASTERY")
            {
                result = avatar.elementMastery + prop.value;
            }
            else if (propType == "FIGHT_PROP_CRITICAL")
            {
                result = avatar.critical + prop.value;
            }
            else if (propType == "FIGHT_PROP_CRITICAL_HURT")
            {
                result = avatar.criticalHurt + prop.value;
            }
            else
            {
                result = prop.value;
            }
            break;
        }
    }
    return result;
}