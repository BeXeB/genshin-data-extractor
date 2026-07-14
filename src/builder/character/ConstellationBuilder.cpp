#include "ConstellationBuilder.hpp"


CharacterConstellation ConstellationBuilder::Build(
    const AvatarSkillDepotExcelConfig& skillDepot,
    const GameDatabase& db
) const
{
    CharacterConstellation constellation;

    constellation.id = skillDepot.id;

    for (size_t i = 0; i < skillDepot.talents.size() && i < 6; i++)
    {
        const auto& talent =
            db.GetTalent(
                skillDepot.talents[i]);

        constellation.constellations[i] =
            BuildDetail(
                talent,
                db);

        constellation.images[i] =
            talent.icon;
    }

    return constellation;
}


ConstellationDetail ConstellationBuilder::BuildDetail(
    const AvatarTalentExcelConfig& talent,
    const GameDatabase& db
) const
{
    ConstellationDetail detail;

    detail.name =
        db.GetText(
            talent.nameTextMapHash);

    detail.descriptionRaw =
        db.GetText(
            talent.descTextMapHash);

    return detail;
}