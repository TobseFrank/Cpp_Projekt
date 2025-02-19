#include <catch2/catch_test_macros.hpp>

#include "settings.h"

TEST_CASE("Project Name") {
    REQUIRE(getProjectName() =="CppProjectTemplate");
}

TEST_CASE("Project VERSION") {
    REQUIRE(getProjectVersion()== "1.0.0");
}
