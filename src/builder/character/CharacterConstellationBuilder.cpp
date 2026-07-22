#include "CharacterConstellationBuilder.hpp"

CharacterConstellation CharacterConstellationBuilder::Build(
    const AvatarSkillDepotExcelConfig &skillDepot,
    const GameDatabase &db) const
{
    CharacterConstellation constellation;

    constellation.id = skillDepot.id;

    for (size_t i = 0; i < skillDepot.talents.size() && i < 6; i++)
    {
        if (skillDepot.talents[i] == 0)
        {
            continue;
        }

        const auto &talent =
            db.GetTalent(
                skillDepot.talents[i]);

        auto detail =
            BuildDetail(
                talent,
                db);

        switch (i)
        {
        case 0:
            constellation.c1 = detail;
            constellation.images.filename_c1 = talent.icon;
            break;
        case 1:
            constellation.c2 = detail;
            constellation.images.filename_c2 = talent.icon;
            break;
        case 2:
            constellation.c3 = detail;
            constellation.images.filename_c3 = talent.icon;
            break;
        case 3:
            constellation.c4 = detail;
            constellation.images.filename_c4 = talent.icon;
            break;
        case 4:
            constellation.c5 = detail;
            constellation.images.filename_c5 = talent.icon;
            break;
        case 5:
            constellation.c6 = detail;
            constellation.images.filename_c6 = talent.icon;
            break;
        default:
            break;
        }
    }

    return constellation;
}

ConstellationDetail CharacterConstellationBuilder::BuildDetail(
    const AvatarTalentExcelConfig &talent,
    const GameDatabase &db) const
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