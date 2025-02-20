# App CMakeLists.txt
set(EXE_SOURCES 
    "main.cpp")
set(EXE_INCLUDES
    "./")

# Create the executable target
add_executable(
    ${EXECUTABLE_NAME}
    ${EXE_SOURCES})

# Includes the neccessary includes
target_include_directories(
    ${EXECUTABLE_NAME} PUBLIC 
    ${EXE_INCLUDES})

# Linking libraries to executables
target_link_libraries(
    ${EXECUTABLE_NAME} PUBLIC 
    ${LIBRARY_SETTINGS}
    ${LIBRARY_LANGUAGE_MANAGER})

# Copy the Settings.txt into the target directory
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/config/Settings.txt
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/Settings.txt)

# Copy the Languages.csv into the target directory
add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/config/Languages.csv
        $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>/Languages.csv)