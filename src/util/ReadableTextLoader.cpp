#include "ReadableTextLoader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>


void ReadableTextLoader::SetPath(
    const std::filesystem::path& path)
{
    basePath = path;
}


std::string ReadableTextLoader::Get(
    const std::string& prefix,
    int id,
    const std::string& language) const
{
    const auto filePath =
        basePath /
        (prefix + std::to_string(id) + "_" + language + ".txt");


    std::ifstream file(filePath);

    if (!file)
    {
        return "";
    }


    std::stringstream buffer;

    buffer << file.rdbuf();

    return buffer.str();
}