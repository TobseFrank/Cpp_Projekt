# Calculator CMakeLists.txt

# Adding libraries
add_library(${LIBRARY_NAME} calculator.cpp)
target_include_directories(${LIBRARY_NAME} PUBLIC "./")