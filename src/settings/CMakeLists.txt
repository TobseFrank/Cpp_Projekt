# Settings CMakeLists.txt
set(LIBRARY_SOURCES 
    "settings.cpp")
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

# Adding libraries
add_library(${LIBRARY_SETTINGS} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_SETTINGS} PUBLIC 
    ${LIBRARY_INCLUDES})