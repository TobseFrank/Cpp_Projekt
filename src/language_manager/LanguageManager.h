#pragma once
#include <string>
#include <unordered_map>

class LanguageManager
{
public:
    static LanguageManager &getInstance();

    LanguageManager(const LanguageManager &) = delete;
    LanguageManager &operator=(const LanguageManager &) = delete;

    std::unordered_map<std::string, std::string> LanguageManager::loadTranslations(const std::string &filename, const std::string &languageCode);

private:
    LanguageManager() = default; // Private Konstruktor
};
