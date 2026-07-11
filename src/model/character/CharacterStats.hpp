#pragma once

#include <optional>
#include <vector>

struct CharacterStat
{
    int level{};

    int ascension{};

    double hp{};

    double attack{};

    double defense{};

    std::optional<double>
        specialized;
};

using CharacterStats =
    std::vector<CharacterStat>;