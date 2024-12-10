cmake_minimum_required(VERSION 3.10)
project(assembler)

set(nlohmann_json_DIR "${CMAKE_SOURCE_DIR}/cm_mods/installs/json/share/cmake/nlohmann_json")
find_package(nlohmann_json 3.2.0 REQUIRED)
add_executable(assembler WIN32 "apps/${APP_NAME}/src/main.cpp")

set_target_properties(assembler PROPERTIES
    LINK_FLAGS "/SUBSYSTEM:CONSOLE"
)

target_link_libraries( assembler PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(assembler PRIVATE Interface)
target_link_libraries(assembler PRIVATE FileIO)
target_link_libraries(assembler)


add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(apps)
add_subdirectory(third-party)