#pragma once
#include <string>
#include "spdlog/spdlog.h"

class Settings
{
public:
    static Settings &getInstance(spdlog::level::level_enum console_level, spdlog::level::level_enum file_level);

    Settings(const Settings &) = delete;
    Settings &operator=(const Settings &) = delete;

    bool readFromFile(const std::string &filePath);

    std::string getLanguageCode() const;
    std::string getProjectName();
    std::string getProjectVersion();

private:
    Settings() = default; // Private Konstruktor
    std::string languageCode = "";

    void setLanguageCode(const std::string &languageCode);
};
