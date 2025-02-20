#include <catch2/catch_test_macros.hpp>

#include "Settings.h"
#include "config.hpp"

TEST_CASE("Project Name")
{
    Settings &s = Settings::getInstance(
        spdlog::level::off,
        spdlog::level::off);
    REQUIRE(s.getProjectName() == PROJECT_NAME);
}

TEST_CASE("Project VERSION")
{
    Settings &s = Settings::getInstance(
        spdlog::level::off,
        spdlog::level::off);
    REQUIRE(s.getProjectVersion() == PROJECT_VERSION);
}

TEST_CASE("Language Code")
{
    Settings &s = Settings::getInstance(
        spdlog::level::off,
        spdlog::level::off);

    REQUIRE(s.getLanguageCode() == "");
    REQUIRE(s.readFromFile("Settings.txt") == true);
    REQUIRE(s.getLanguageCode() == "en");
}