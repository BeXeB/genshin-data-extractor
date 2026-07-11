#include <iostream>

#include "GameDatabase.hpp"
#include "ProfileBuilder.hpp"
#include "EnumConverter.hpp"

int main()
{
    GameDatabase db;

    try
    {
        db.Load(
            "data/animegamedata2");
    }
    catch (const std::exception &e)
    {
        std::cerr
            << "Failed loading database: "
            << e.what()
            << "\n";

        return 1;
    }

    try
    {
        ProfileBuilder builder;

        for (const auto &[id, avatar] : db.GetAvatars())
        {
            auto profile = builder.Build(avatar, db);

            std::cout << profile.name << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception type: "
                  << typeid(e).name() << '\n';
        std::cerr << "Message: "
                  << e.what() << '\n';

        return 1;
    }

    return 0;
}