# Tests CMakeLists.txt 
include(Catch)

set(TEST_MAIN "unit_tests")
set(UNIT_TESTS_SOURCES "main.cpp")
set(UNIT_TESTS_INCLUDES "./")

# Create the executable target
add_executable(${TEST_MAIN} ${UNIT_TESTS_SOURCES})
target_include_directories(${TEST_MAIN} PUBLIC ${UNIT_TESTS_INCLUDES})

# Linking libraries to executables
target_link_libraries(${TEST_MAIN} PUBLIC ${LIBRARY_SETTINGS} Catch2::Catch2WithMain)
    
catch_discover_tests(${TEST_MAIN})
