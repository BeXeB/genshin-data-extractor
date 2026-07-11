#include "Slug.hpp"

#include <algorithm>
#include <cctype>

std::string Normalize(const std::string& name)
{
    std::string result;
    result.reserve(name.size());

    for (char ch : name)
    {
        if (std::isspace(static_cast<unsigned char>(ch)) ||
            ch == '\'' || ch == '"' || ch == '`' ||
            ch == ':' || ch == '-' || ch == '—')
        {
            continue;
        }

        result.push_back(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
    }

    return result;
}
