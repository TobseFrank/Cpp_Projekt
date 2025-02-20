# Tests CMakeLists.txt 
include(Catch)

set(TEST_MAIN 
    "unit_tests")

set(UNIT_TESTS_SOURCES
    "main.cpp")

set(UNIT_TESTS_INCLUDES 
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

# Create the executable target
add_executable(
    ${TEST_MAIN} 
    ${UNIT_TESTS_SOURCES})

target_include_directories(
    ${TEST_MAIN} PUBLIC 
    ${UNIT_TESTS_INCLUDES})

# Linking libraries to executables
target_link_libraries(
    ${TEST_MAIN} PUBLIC 
    ${LIBRARY_SETTINGS} 
    Catch2::Catch2WithMain)

# Copy the Settings.txt into the tests directory
add_custom_command(TARGET ${TEST_MAIN} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/config/Settings.txt
        ${CMAKE_CURRENT_BINARY_DIR}/Settings.txt)
        
catch_discover_tests(${TEST_MAIN})
