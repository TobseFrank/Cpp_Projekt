# Configured CMakeLists.txt

# Makes the CMakeLists variables availlable in the code
configure_file(
    "config.hpp.in"
    "${CMAKE_BINARY_DIR}/configured_files/include/config.hpp" ESCAPE_QUOTES
)