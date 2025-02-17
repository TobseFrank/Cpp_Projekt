# App CMakeLists.txt

# Create the executable target
add_executable(${EXECUTABLE_NAME} main.cpp)

# Linking libraries to executables
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME2})