#include "WeaponStatBuilder.hpp"

#include "database/GameDatabase.hpp"


WeaponStats WeaponStatBuilder::Build(
    const GameDatabase& database,
    const WeaponExcelConfig& weapon)
{
    WeaponStats stats;

    for (const auto& prop : weapon.weaponProp)
    {
        WeaponStat stat;

        stat.level = 1;
        stat.ascension = 0;

        const auto& curve =
            database.GetWeaponCurve(1);

        double multiplier = 1.0;

        for (const auto& info : curve.curveInfos)
        {
            if (info.type == prop.type)
            {
                multiplier = info.value;
                break;
            }
        }

        double value =
            prop.initValue * multiplier;

        if (prop.propType == "FIGHT_PROP_BASE_ATTACK")
        {
            stat.attack = value;
        }
        else
        {
            stat.specialized = value;
        }

        stats[prop.propType] = stat;
    }

    return stats;
}