#include <set>

#include "ArtifactBuilder.hpp"
#include <util/Slug.hpp>

ArtifactSet ArtifactBuilder::Build(
    int setId,
    const GameDatabase& database) const
{
    ArtifactSet artifact;

    const auto& set =
        database.GetReliquarySet(setId);

    artifact.id =
        set.setId;


    const auto& affixes =
        database.GetEquipAffixes(
            set.equipAffixId);

    if (!affixes.empty())
    {
        artifact.name =
            database.GetText(
                affixes.front().nameTextMapHash);

        artifact.normalizedName =
            Normalize(artifact.name);
    }

    for (const auto& affix : affixes)
    {
        const auto text =
            database.GetText(
                affix.descTextMapHash);

        if (set.setNeedNum.size() == 1)
        {
            artifact.effect1Pc = text;
            break;
        }

        if (affix.level == 0)
        {
            artifact.effect2Pc = text;
        }
        else
        {
            artifact.effect4Pc = text;
        }
    }


    const auto& reliquaries =
        database.GetReliquaries(setId);
    std::set<int> rarities;

    for (const auto& reliquary : reliquaries)
    {
        rarities.insert(
            reliquary.rankLevel);

        ArtifactPiece piece =
            pieceBuilder.Build(
                reliquary,
                database);

        switch (piece.relicType)
        {
        case ArtifactType::Flower:
            artifact.flower = piece;
            artifact.images.filename_flower =
                reliquary.icon;
            break;

        case ArtifactType::Plume:
            artifact.plume = piece;
            artifact.images.filename_plume =
                reliquary.icon;
            break;

        case ArtifactType::Sands:
            artifact.sands = piece;
            artifact.images.filename_sands =
                reliquary.icon;
            break;

        case ArtifactType::Goblet:
            artifact.goblet = piece;
            artifact.images.filename_goblet =
                reliquary.icon;
            break;

        case ArtifactType::Circlet:
            artifact.circlet = piece;
            artifact.images.filename_circlet =
                reliquary.icon;
            break;

        default:
            break;
        }
    }

    artifact.rarityList.assign(
        rarities.begin(),
        rarities.end());

    return artifact;
}