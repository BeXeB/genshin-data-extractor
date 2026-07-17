#include "WeaponPromoteBuilder.hpp"

#include "database/GameDatabase.hpp"


std::map<std::string, std::vector<Item>>
WeaponPromoteBuilder::Build(
    const GameDatabase& database,
    int weaponPromoteId)
{
    std::map<std::string, std::vector<Item>> costs;

    const auto& promotes =
        database.GetWeaponPromoteInfo(weaponPromoteId);

    auto& moraMaterial =
        database.GetMaterial(202);
    std::string moraName =
        database.GetText(moraMaterial.nameTextMapHash);

    for (const auto& promote : promotes)
    {
        std::vector<Item> items;

        Item mora;
        mora.id = 202;
        mora.name = moraName;
        mora.count = promote.coinCost;
        if (mora.count != 0)
            items.push_back(mora);

        for (const auto& cost : promote.costItems)
        {
            if (cost.id == 0 || cost.count == 0)
                continue;

            const auto& material =
                database.GetMaterial(cost.id);
           
            Item item;

            item.id = material.id;
            item.name =
                database.GetText(
                    material.nameTextMapHash);

            item.count = cost.count;

            items.push_back(
                std::move(item));
        }

        if (!items.empty())
        {
            costs[
                "ascend" +
                    std::to_string(promote.promoteLevel)
            ] = std::move(items);
        }
    }

    return costs;
}