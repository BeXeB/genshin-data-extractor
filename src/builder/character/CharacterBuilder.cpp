#include "CharacterBuilder.hpp"

Character CharacterBuilder::Build(
    const AvatarExcelConfig &avatar,
    const GameDatabase &db) const
{
    Character character;

    character.profile =
        profileBuilder.Build(
            avatar,
            db);

    //
    // Stats
    //
    character.stats =
        statsBuilder.Build(
            avatar,
            db);

    if (avatar.candSkillDepotIds.empty())
    {
        //
        // Talents
        //
        const auto &skillDepot =
            db.GetSkillDepot(avatar.skillDepotId);

        character.talents =
            talentBuilder.Build(
                skillDepot,
                db);

        //
        // Constellations
        //

        character.constellation =
            constellationBuilder.Build(
                skillDepot,
                db);
    }
    else
    {
        for (int depotId : avatar.candSkillDepotIds)
        {
            const auto &depot =
                db.GetSkillDepot(depotId);

            CharacterVariant variant;

            variant.talents =
                talentBuilder.Build(depot, db);

            variant.constellation =
                constellationBuilder.Build(depot, db);

            if (variant.constellation.c1.name.empty())
            {
                continue;
            }

            character.variants[GetTravelerElement(depotId)] =
                std::move(variant);
        }
    }

    return character;
}

ElementType CharacterBuilder::GetTravelerElement(int depotId) const
{
    switch (depotId % 100)
    {
    case 1:
        return ElementType::None; // NA Only
    case 2:
        return ElementType::Pyro;
    case 3:
        return ElementType::Hydro;
    case 4:
        return ElementType::Anemo;
    case 5:
        return ElementType::Cryo;
    case 6:
        return ElementType::Geo;
    case 7:
        return ElementType::Electro;
    case 8:
        return ElementType::Dendro;
    default:
        return ElementType::None;
    }
}