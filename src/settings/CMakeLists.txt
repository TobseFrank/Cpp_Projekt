# Settings CMakeLists.txt
set(LIBRARY_SOURCES 
    "Settings.cpp")
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

# Adding libraries
add_library(${LIBRARY_SETTINGS} STATIC 
    ${LIBRARY_SOURCES})

# Including extern libraries    
target_link_libraries(
        ${LIBRARY_SETTINGS} PUBLIC 
        spdlog::spdlog
        ${LIBRARY_FILE_NOT_FOUND_EXCEPTION})    

# Includes the neccessary includes
target_include_directories(${LIBRARY_SETTINGS} PUBLIC 
    ${LIBRARY_INCLUDES})