# Main CMakeLists.txt

# Minimum required CMake version
cmake_minimum_required(VERSION 3.22)

# Define the project
project(
    CppProjectTemplate 
    VERSION 1.0.0
    LANGUAGES C CXX)

# Define C++ Standarts
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

option(ENABLE_UNIT_TESTING "Enable Unit Testing" On)

# Define variable names
set(EXECUTABLE_NAME MyProgramName)
set(LIBRARY_SETTINGS library_settings)
set(LIBRARY_LANGUAGE_MANAGER library_language_manager)
set(LIBRARY_FILE_NOT_FOUND_EXCEPTION library_file_not_found_exception)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

# Unlocking of the FetchContent moule
include(FetchContent)

# Adding spdlog from github
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.15.1
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(spdlog)

# Adding Catch2 from github
if(ENABLE_UNIT_TESTING)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.8.0
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
endif()

# Adding of the subdirectories
add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)

# Enabilieng of the CTest modules
if(ENABLE_UNIT_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif()