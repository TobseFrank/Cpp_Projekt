#include <spdlog/spdlog.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "LanguageManager.h"
#include "FileNotFoundException.h"
LanguageManager &LanguageManager::getInstance()
{
    static LanguageManager instance;
    return instance;
}

std::unordered_map<std::string, std::string> LanguageManager::loadTranslations(
    const std::string &filename,
    const std::string &languageCode)
{
    std::unordered_map<std::string, std::string> translations;
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw FileNotFoundException(filename);
    }

    std::string line;
    std::vector<std::string> headers;

    // Read and parse the header
    if (std::getline(file, line))
    {
        std::istringstream headerStream(line);
        std::string header;
        while (std::getline(headerStream, header, ','))
        {
            headers.push_back(header);
        }
    }

    // Find the index of the requested language
    auto langIndex = std::find(headers.begin(), headers.end(), languageCode) - headers.begin();
    if (langIndex == headers.size())
    {
        spdlog::error("Language code '{}' not found in the CSV file", languageCode);
        return translations;
    }

    // Read the translations
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::vector<std::string> values;
        std::string value;

        while (std::getline(iss, value, ','))
        {
            values.push_back(value);
        }

        if (values.size() > langIndex)
        {
            translations[values[0]] = values[langIndex];
        }
    }

    return translations;
}
