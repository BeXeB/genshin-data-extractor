#include "HyperLinkBuilder.hpp"

HyperLink HyperLinkBuilder::Build(
    const HyperLinkNameExcelConfig &dmHyperlink,
    const GameDatabase &database) const
{
    HyperLink hyperlink;

    hyperlink.id =
        dmHyperlink.id;

    hyperlink.name =
        database.GetText(
            dmHyperlink.nameTextMapHash);

    hyperlink.description =
        database.GetText(
            dmHyperlink.descTextMapHash);

    return hyperlink;
}