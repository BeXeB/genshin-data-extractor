#include "CharacterBuilder.hpp"

Character CharacterBuilder::Build(
    const AvatarExcelConfig& avatar,
    const GameDatabase& db
) const
{
    Character character;

    character.profile =
        profileBuilder.Build(
            avatar,
            db);



    //
    // Talents
    //
    const auto& skillDepot =
        db.GetSkillDepot(avatar.skillDepotId);

    character.talents =
        talentBuilder.Build(
            skillDepot,
            db);

    //
    // Stats
    //
    character.stats =
        statsBuilder.Build(
            avatar,
            db);

    //
    // Constellations
    //

    character.constellation =
        constellationBuilder.Build(
            skillDepot,
            db);



    return character;
}