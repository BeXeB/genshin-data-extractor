#include "TalentBuilder.hpp"

#include <stdexcept>


CharacterTalents TalentBuilder::Build(
    const AvatarSkillDepotExcelConfig& skillDepot,
    const GameDatabase& db
) const
{
    CharacterTalents talents;
    TalentImages images;

    talents.id = skillDepot.id;

    auto selectCombatIcon =
        [](const AvatarSkillExcelConfig& skill,
           const std::vector<ProudSkillExcelConfig>& proudSkills)
        {
            if (!skill.skillIcon.empty())
                return std::optional<std::string>{skill.skillIcon};

            for (const auto& proudSkill : proudSkills)
            {
                if (!proudSkill.icon.empty())
                    return std::optional<std::string>{proudSkill.icon};
            }

            return std::optional<std::string>{};
        };

    auto selectPassiveIcon =
        [](const std::vector<ProudSkillExcelConfig>& proudSkills)
        {
            for (const auto& proudSkill : proudSkills)
            {
                if (!proudSkill.icon.empty())
                    return std::optional<std::string>{proudSkill.icon};
            }

            return std::optional<std::string>{};
        };

    std::vector<ProudSkillExcelConfig> costSkills;

    // Normal Attack
    if (skillDepot.skills.size() > 0 &&
        skillDepot.skills[0] != 0)
    {
        auto skill =
            db.GetSkill(skillDepot.skills[0]);

        auto proudSkills =
            db.GetProudSkills(
                skill.proudSkillGroupId);


        talents.combat1 =
            BuildCombatTalent(
                skill,
                proudSkills,
                db);

        images.filename_combat1 =
            selectCombatIcon(
                skill,
                proudSkills);


        // Costs are shared, use Normal Attack
        costSkills = proudSkills;
    }


    // Elemental Skill
    if (skillDepot.skills.size() > 1 &&
        skillDepot.skills[1] != 0)
    {
        auto skill =
            db.GetSkill(skillDepot.skills[1]);

        auto proudSkills =
            db.GetProudSkills(
                skill.proudSkillGroupId);

        talents.combat2 =
            BuildCombatTalent(
                skill,
                proudSkills,
                db);

        images.filename_combat2 =
            selectCombatIcon(
                skill,
                proudSkills);
    }


    // Elemental Burst
    if (skillDepot.energySkill != 0)
    {
        auto skill =
            db.GetSkill(skillDepot.energySkill);

        auto proudSkills =
            db.GetProudSkills(
                skill.proudSkillGroupId);

        talents.combat3 =
            BuildCombatTalent(
                skill,
                proudSkills,
                db);

        images.filename_combat3 =
            selectCombatIcon(
                skill,
                proudSkills);
    }

    std::vector<PassiveTalent> passives;


    for (const auto& passiveGroup :
        skillDepot.passiveSkills)
    {
        if (passiveGroup.passiveSkillGroupId == 0)
            continue;


        auto passiveSkills =
            db.GetProudSkills(
                passiveGroup.passiveSkillGroupId);


        auto passive =
            BuildPassiveTalent(
                passiveSkills,
                db);


        passives.push_back(passive);

        auto passiveIcon =
            selectPassiveIcon(passiveSkills);

        switch (passives.size())
        {
        case 1:
            images.filename_passive1 = passiveIcon;
            break;
        case 2:
            images.filename_passive2 = passiveIcon;
            break;
        case 3:
            images.filename_passive3 = passiveIcon;
            break;
        case 4:
            images.filename_passive4 = passiveIcon;
            break;
        default:
            break;
        }
    }

    if (!costSkills.empty())
    {
        talents.costs =
            GetTalentCosts(
                costSkills,
                db);
    }

    if (passives.size() > 0)
        talents.passive1 = passives[0];

    if (passives.size() > 1)
        talents.passive2 = passives[1];

    if (passives.size() > 2)
        talents.passive3 = passives[2];

    if (passives.size() > 3)
        talents.passive4 = passives[3];

    if (images.filename_combat1 ||
        images.filename_combat2 ||
        images.filename_combat3 ||
        images.filename_passive1 ||
        images.filename_passive2 ||
        images.filename_passive3 ||
        images.filename_passive4)
    {
        talents.images = images;
    }

    return talents;
}

CombatTalent TalentBuilder::BuildCombatTalent(
    const AvatarSkillExcelConfig& skill,
    const std::vector<ProudSkillExcelConfig>& proudSkills,
    const GameDatabase& db
) const
{
    CombatTalent result;

    result.name =
        db.GetText(
            skill.nameTextMapHash);

    result.descriptionRaw =
        db.GetText(
            skill.descTextMapHash);

    if (!proudSkills.empty())
    {
        const auto& first =
            proudSkills.front();

        for (auto hash : first.paramDescList)
        {
            std::string label =
                db.GetText(hash);

            if (label.empty())
                continue;

            result.labels.push_back(label);
        }


        for (const auto& proud : proudSkills)
        {
            for (size_t i = 0;
                i < proud.paramDescList.size();
                i++)
            {
                if (i >= proud.paramList.size())
                    continue;

                std::string label =
                    db.GetText(
                        proud.paramDescList[i]);

                if (label.empty())
                    continue;

                std::string key =
                    "param" + std::to_string(i + 1);

                result.parameters[key]
                    .push_back(
                        proud.paramList[i]);
            }
        }
    }

    return result;
}

PassiveTalent TalentBuilder::BuildPassiveTalent(
    const std::vector<ProudSkillExcelConfig>& proudSkills,
    const GameDatabase& db
) const
{
    PassiveTalent result;


    if (proudSkills.empty())
        return result;


    // Level 1 contains the display information
    const auto& passive =
        proudSkills.front();


    result.name =
        db.GetText(
            passive.nameTextMapHash);


    result.descriptionRaw =
        db.GetText(
            passive.descTextMapHash);

    return result;
}

std::unordered_map<std::string, std::vector<Item>>
TalentBuilder::GetTalentCosts(
    const std::vector<ProudSkillExcelConfig>& proudSkills,
    const GameDatabase& db) const
{
    std::unordered_map<std::string, std::vector<Item>> result;


    for (const auto& skill : proudSkills)
    {
        if (skill.level < 2 ||
            skill.level > 10)
        {
            continue;
        }


        std::string key =
            "lvl" + std::to_string(skill.level);


        auto& costs =
            result[key];


        // Mora
        if (skill.coinCost > 0)
        {
            Item mora;

            mora.id = 202;
            mora.name = "Mora";
            mora.count = skill.coinCost;

            costs.push_back(mora);
        }


        // Materials
        for (const auto& cost : skill.costItems)
        {
            if (cost.id == 0)
                continue;


            auto material =
                db.GetMaterial(cost.id);


            Item item;

            item.id =
                material.id;

            item.name =
                db.GetText(
                    material.nameTextMapHash);

            item.count =
                cost.count;


            costs.push_back(item);
        }
    }


    return result;
}