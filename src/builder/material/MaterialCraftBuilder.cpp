#include "MaterialCraftBuilder.hpp"


MaterialCraft MaterialCraftBuilder::Build(
    const CombineExcelConfig& combine,
    const GameDatabase& database) const
{
    MaterialCraft craft;

    craft.id =
        combine.resultItemId;

    craft.resultCount =
        combine.resultItemCount;

    craft.moraCost =
        combine.scoinCost;


    for (const auto& input : combine.materialItems)
    {
        if (input.id == 0 || input.count == 0)
            continue;


        Item item;

        item.id =
            input.id;

        item.count =
            input.count;

        const auto& material =
            database.GetMaterial(input.id);

        item.name =
            database.GetText(
                material.nameTextMapHash);

        craft.recipe.push_back(
            item);
    }

    return craft;
}