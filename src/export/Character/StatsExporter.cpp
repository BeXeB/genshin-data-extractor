#include "StatsExporter.hpp"

nlohmann::json StatsExporter::Export(
    const CharacterStats &stats) const
{
    nlohmann::json json = nlohmann::json::object();

    for (const auto &[key, value] : stats)
    {
        json[key] = {
            {"level", value.level},
            {"ascension", value.ascension},
            {"hp", value.hp},
            {"attack", value.attack},
            {"defense", value.defense},
            {"specialized", value.specialized}};
    }

    return json;
}