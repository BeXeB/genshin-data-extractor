#include "SkillsExporter.hpp"

nlohmann::json SkillsExporter::Export(
    const CharacterTalents &skills) const
{
    nlohmann::json json;

    json["combat1"] = {
		{"id", skills.combat1.id},
        {"proudSkillGroupId", skills.combat1.proudSkillGroupId },
        {"name", skills.combat1.name},
        {"descriptionRaw", skills.combat1.descriptionRaw},
        {"attributes", {{"labels", skills.combat1.labels}, {"parameters", skills.combat1.parameters}}}};

    json["combat2"] = {
        {"id", skills.combat2.id},
        {"proudSkillGroupId", skills.combat2.proudSkillGroupId },
        {"name", skills.combat2.name},
        {"descriptionRaw", skills.combat2.descriptionRaw},
        {"attributes", {{"labels", skills.combat2.labels}, {"parameters", skills.combat2.parameters}}}};

    json["combat3"] = {
        {"id", skills.combat3.id},
        {"proudSkillGroupId", skills.combat3.proudSkillGroupId },
        {"name", skills.combat3.name},
        {"descriptionRaw", skills.combat3.descriptionRaw},
        {"attributes", {{"labels", skills.combat3.labels}, {"parameters", skills.combat3.parameters}}}};

    json["passive1"] = {
        {"id", skills.passive1.id },
        {"name", skills.passive1.name},
        {"descriptionRaw", skills.passive1.descriptionRaw}};

    json["passive2"] = {
        {"id", skills.passive2.id },
        {"name", skills.passive2.name},
        {"descriptionRaw", skills.passive2.descriptionRaw}};

    if (skills.passive3)
    {
        json["passive3"] = {
            {"id", skills.passive3->id },
            {"name", skills.passive3->name},
            {"descriptionRaw", skills.passive3->descriptionRaw}};
    }

    if (skills.passive4)
    {
        json["passive4"] = {
            {"id", skills.passive4->id },
            {"name", skills.passive4->name},
            {"descriptionRaw", skills.passive4->descriptionRaw}};
    }

    json["costs"] = skills.costs;

    if (skills.images)
    {
        nlohmann::json images;

        if (skills.images->filename_combat1)
            images["filename_combat1"] = *skills.images->filename_combat1;

        if (skills.images->filename_combat2)
            images["filename_combat2"] = *skills.images->filename_combat2;

        if (skills.images->filename_combat3)
            images["filename_combat3"] = *skills.images->filename_combat3;

        if (skills.images->filename_passive1)
            images["filename_passive1"] = *skills.images->filename_passive1;

        if (skills.images->filename_passive2)
            images["filename_passive2"] = *skills.images->filename_passive2;

        if (skills.images->filename_passive3)
            images["filename_passive3"] = *skills.images->filename_passive3;

        if (skills.images->filename_passive4)
            images["filename_passive4"] = *skills.images->filename_passive4;

        json["images"] = images;
    }

    return json;
}