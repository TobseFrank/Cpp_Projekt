# Settings CMakeLists.txt
set(LIBRARY_SOURCES 
    "settings.cpp")
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

# Adding libraries
add_library(${LIBRARY_NAME3} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME3} PUBLIC 
    ${LIBRARY_INCLUDES})