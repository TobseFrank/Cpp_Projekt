# Calculator CMakeLists.txt

# Adding libraries
add_library(${LIBRARY_NAME2} printer.cpp)
target_include_directories(${LIBRARY_NAME2} PUBLIC "./")