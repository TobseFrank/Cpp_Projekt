# App CMakeLists.txt
set(EXE_SOURCES 
    "main.cpp")
set(EXE_INCLUDES
    "./")

# Create the executable target
add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC 
    ${EXE_INCLUDES})

# Linking libraries to executables
target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
    ${LIBRARY_CALCULATOR}
    ${LIBRARY_PRINTER}
    ${LIBRARY_SETTINGS})