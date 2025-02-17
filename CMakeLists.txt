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

# Define variable names
set(EXECUTABLE_NAME MyProgramName)
set(LIBRARY_NAME Library)
set(LIBRARY_NAME2 Library2)
set(LIBRARY_NAME3 Library3)

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(app)