#pragma once

#include <cstdint>

#include <nlohmann/json.hpp>

struct ReliquaryCodexExcelConfig
{
    int id{};

    int suitId{};

    int level{};

    int flowerId{};
    int leatherId{};
    int sandId{};
    int cupId{};
    int capId{};

    int sortOrder{};
};

inline void from_json(
    const nlohmann::json &j,
    ReliquaryCodexExcelConfig &codex)
{
    codex.id = j.value("id", 0);
    codex.suitId = j.value("suitId", 0);
    codex.level = j.value("level", 0);
    codex.flowerId = j.value("flowerId", 0);
    codex.leatherId = j.value("leatherId", 0);
    codex.sandId = j.value("sandId", 0);
    codex.cupId = j.value("cupId", 0);
    codex.capId = j.value("capId", 0);
    codex.sortOrder = j.value("sortOrder", 0);
}
