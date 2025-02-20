# Language Manager CMakeLists.txt
set(LIBRARY_SOURCES 
    "LanguageManager.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_LANGUAGE_MANAGER} STATIC 
    ${LIBRARY_SOURCES})

# Including extern libraries    
target_link_libraries(
        ${LIBRARY_LANGUAGE_MANAGER} PUBLIC 
        spdlog::spdlog
        ${LIBRARY_FILE_NOT_FOUND_EXCEPTION})    

# Includes the neccessary includes
target_include_directories(${LIBRARY_LANGUAGE_MANAGER} PUBLIC 
    ${LIBRARY_INCLUDES})