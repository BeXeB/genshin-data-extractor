#pragma once

#include <filesystem>
#include <string>

class ReadableTextLoader
{
public:
    void SetPath(
        const std::filesystem::path& path);

    std::string Get(
        const std::string& prefix,
        int id,
        const std::string& language = "EN") const;

private:
    std::filesystem::path basePath;
};