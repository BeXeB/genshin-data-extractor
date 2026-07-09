#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    json test =
        {
            {"name", "Hu Tao"},
            {"rarity", 5}};

    std::cout << test.dump(4) << "\n";

    return 0;
}