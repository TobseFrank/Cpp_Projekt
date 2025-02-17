# Calculator CMakeLists.txt
set(LIBRARY_SOURCES 
    "calculator.cpp")
set(LIBRARY_INCLUDES
    "./")

# Adding libraries
add_library(${LIBRARY_NAME} STATIC 
    ${LIBRARY_SOURCES})
target_include_directories(${LIBRARY_NAME} PUBLIC 
    ${LIBRARY_INCLUDES})