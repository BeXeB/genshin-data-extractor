#pragma once

#include "model/artifact/Artifact.hpp"

#include "database/GameDatabase.hpp"
#include "builder/artifact/ArtifactPieceBuilder.hpp"

class ArtifactBuilder
{
public:
    ArtifactSet Build(
        int setId,
        const GameDatabase& database) const;

private:
    ArtifactPieceBuilder pieceBuilder;
};