#include <fstream>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Settings.h"
#include "FileNotFoundException.h"
#include "config.hpp"

Settings &Settings::getInstance(spdlog::level::level_enum console_level, spdlog::level::level_enum file_level)
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(console_level);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs\\logfile.txt");
    file_sink->set_level(file_level);

    std::vector<spdlog::sink_ptr> sinks{
        console_sink,
        file_sink};

    auto logger = std::make_shared<spdlog::logger>(
        "multi_logger",
        sinks.begin(),
        sinks.end());

    spdlog::set_default_logger(logger);
    static Settings instance;
    return instance;
}

std::string Settings::getProjectName()
{
    return PROJECT_NAME;
}
std::string Settings::getProjectVersion()
{
    return PROJECT_VERSION;
}

std::string Settings::getLanguageCode() const
{
    return languageCode;
}

void Settings::setLanguageCode(const std::string &languageCode)
{
    this->languageCode = languageCode;
}

bool Settings::readFromFile(const std::string &filePath)
{
    // TODO anständige Lösung finden
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        throw FileNotFoundException(filePath);
    }

    std::getline(
        file,
        languageCode);
    file.close();
    return true;
}
