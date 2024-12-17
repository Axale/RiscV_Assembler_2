cmake_minimum_required(VERSION 3.10)
project(assembler)

# Set path to nlohmann_json and find the package
set(nlohmann_json_DIR "${CMAKE_SOURCE_DIR}/cm_mods/installs/json/share/cmake/nlohmann_json")
find_package(nlohmann_json 3.2.0 REQUIRED)

# Define the executable
add_executable(assembler WIN32 "apps/${APP_NAME}/src/main.cpp")
set_target_properties(assembler PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")

# Link libraries to the assembler executable
target_link_libraries(assembler PRIVATE 
    nlohmann_json::nlohmann_json 
    Interface 
    FileIO 
)

# Add subdirectories
add_subdirectory(modules)
add_subdirectory(apps)
add_subdirectory(third-party)
