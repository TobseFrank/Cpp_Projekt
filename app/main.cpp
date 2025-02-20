#include <iostream>
#include <string>

#include "Settings.h"
#include "LanguageManager.h"
#include "FileNotFoundException.h"
int main(int argc, char *argv[])
{
    int console_level = 2; // Standard: info
    int file_level = 3;    // Standard: warn

    if (argc == 3)
    {
        console_level = std::stoi(argv[1]);
        file_level = std::stoi(argv[2]);
    }
    else if (argc != 1)
    {
        std::cerr << "Usage: " << argv[0] << " [<console_level> <file_level>]\n";
        return 1;
    }

    try
    {
        // Loading of the settings.txt
        Settings &settings = Settings::getInstance(
            static_cast<spdlog::level::level_enum>(console_level),
            static_cast<spdlog::level::level_enum>(file_level));
        settings.readFromFile("Settings.txt");

        // Loading of the choosen Language in the settings.txt
        LanguageManager &languages = LanguageManager::getInstance();
        auto translations = languages.loadTranslations(
            "Languages.csv",
            settings.getLanguageCode());

        std::cout << settings.getProjectName()
                  << " | "
                  << settings.getProjectVersion()
                  << "\n";

        std::cout << translations["hello"]
                  << " "
                  << translations["world"]
                  << "!\n";
    }
    catch (const FileNotFoundException &e)
    {
        std::cin.ignore();
        std::cin.get();
        return 1;
    }

    return 0;
}