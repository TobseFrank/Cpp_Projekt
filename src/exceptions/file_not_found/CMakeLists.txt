# Settings CMakeLists.txt
set(LIBRARY_SOURCES 
    "FileNotFoundException.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_FILE_NOT_FOUND_EXCEPTION} STATIC 
    ${LIBRARY_SOURCES})

# Including extern libraries    
target_link_libraries(
        ${LIBRARY_FILE_NOT_FOUND_EXCEPTION} PUBLIC 
        spdlog::spdlog)    

# Includes the neccessary includes
target_include_directories(${LIBRARY_FILE_NOT_FOUND_EXCEPTION} PUBLIC 
    ${LIBRARY_INCLUDES})