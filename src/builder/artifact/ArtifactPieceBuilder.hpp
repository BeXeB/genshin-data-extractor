#pragma once

#include "dm/artifact/ReliquaryExcelConfig.hpp"
#include "database/GameDatabase.hpp"

#include "model/artifact/ArtifactSet.hpp"

class ArtifactPieceBuilder
{
public:
    static ArtifactPiece Build(
        const ReliquaryExcelConfig& reliquary,
        const GameDatabase& database);

private:
    static ArtifactType ConvertType(
        const std::string& equipType);
    static int GetPieceNumber(
        const std::string& icon);
};