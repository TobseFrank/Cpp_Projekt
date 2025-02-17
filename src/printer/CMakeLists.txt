# Calculator CMakeLists.txt
set(LIBRARY_SOURCES 
    "printer.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_NAME2} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME2} PUBLIC 
    ${LIBRARY_INCLUDES})