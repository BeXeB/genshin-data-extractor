#include "ConstellationExporter.hpp"

nlohmann::json ConstellationExporter::Export(
    const CharacterConstellation &constellation) const
{
    nlohmann::json json;

    json["c1"] = {
        {"name", constellation.c1.name},
        {"descriptionRaw", constellation.c1.descriptionRaw}};
    json["c2"] = {
        {"name", constellation.c2.name},
        {"descriptionRaw", constellation.c2.descriptionRaw}};
    json["c3"] = {
        {"name", constellation.c3.name},
        {"descriptionRaw", constellation.c3.descriptionRaw}};
    json["c4"] = {
        {"name", constellation.c4.name},
        {"descriptionRaw", constellation.c4.descriptionRaw}};
    json["c5"] = {
        {"name", constellation.c5.name},
        {"descriptionRaw", constellation.c5.descriptionRaw}};
    json["c6"] = {
        {"name", constellation.c6.name},
        {"descriptionRaw", constellation.c6.descriptionRaw}};

    nlohmann::json images;

    if (constellation.images.filename_c1)
        images["filename_c1"] = *constellation.images.filename_c1;
    if (constellation.images.filename_c2)
        images["filename_c2"] = *constellation.images.filename_c2;
    if (constellation.images.filename_c3)
        images["filename_c3"] = *constellation.images.filename_c3;
    if (constellation.images.filename_c4)
        images["filename_c4"] = *constellation.images.filename_c4;
    if (constellation.images.filename_c5)
        images["filename_c5"] = *constellation.images.filename_c5;
    if (constellation.images.filename_c6)
        images["filename_c6"] = *constellation.images.filename_c6;

    json["images"] = images;

    return json;
}