#include "Slug.hpp"

#include <cctype>
#include <string>

std::string Normalize(const std::string& name)
{
    std::string result;
    result.reserve(name.size());

    for (size_t i = 0; i < name.size(); ++i)
    {
        unsigned char ch = static_cast<unsigned char>(name[i]);

        // ASCII whitespace and symbols
        if (std::isspace(ch) ||
            ch == '\'' ||
            ch == '"' ||
            ch == '`' ||
            ch == ':' ||
            ch == '-')
        {
            continue;
        }

        // UTF-8 dash characters:
        // – U+2013 = E2 80 93
        // — U+2014 = E2 80 94
        if (ch == 0xE2 &&
            i + 2 < name.size() &&
            static_cast<unsigned char>(name[i + 1]) == 0x80 &&
            (static_cast<unsigned char>(name[i + 2]) == 0x93 ||
                static_cast<unsigned char>(name[i + 2]) == 0x94))
        {
            i += 2;
            continue;
        }

        result.push_back(static_cast<char>(std::tolower(ch)));
    }

    return result;
}