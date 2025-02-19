# Calculator CMakeLists.txt
set(LIBRARY_SOURCES 
    "calculator.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_CALCULATOR} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_CALCULATOR} PUBLIC 
    ${LIBRARY_INCLUDES})