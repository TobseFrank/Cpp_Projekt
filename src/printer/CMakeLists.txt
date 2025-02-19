# Calculator CMakeLists.txt
set(LIBRARY_SOURCES 
    "printer.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_PRINTER} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_PRINTER} PUBLIC 
    ${LIBRARY_INCLUDES})