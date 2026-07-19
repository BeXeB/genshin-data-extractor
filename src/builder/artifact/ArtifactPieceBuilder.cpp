#include "ArtifactPieceBuilder.hpp"

#include <stdexcept>

#include "util/EnumConverter.hpp"

ArtifactPiece ArtifactPieceBuilder::Build(
    const ReliquaryExcelConfig& reliquary,
    const GameDatabase& database)
{
    ArtifactPiece piece;

    piece.name =
        database.GetText(
            reliquary.nameTextMapHash);

    piece.description =
        database.GetText(
            reliquary.descTextMapHash);

    piece.relicType =
        ConvertType(
            reliquary.equipType);

    piece.story =
        database.GetReadableTextLoader()
        .Get(
            "Relic",
            reliquary.setId,
            GetPieceNumber(reliquary.icon));

    return piece;
}

ArtifactType ArtifactPieceBuilder::ConvertType(
    const std::string& equipType)
{
    const auto type = ArtifactTypeFromDM(equipType);

    if (type == ArtifactType::Unknown)
    {
        throw std::runtime_error(
            "Unknown artifact type: " + equipType);
    }

    return type;
}

int ArtifactPieceBuilder::GetPieceNumber(
    const std::string& icon)
{
    const auto pos =
        icon.find_last_of('_');

    if (pos == std::string::npos ||
        pos + 1 >= icon.size())
    {
        throw std::runtime_error(
            "Invalid relic icon: " + icon);
    }

    return std::stoi(
        icon.substr(pos + 1));
}