cmake_minimum_required(VERSION 3.10)

set(nlohmann_json_DIR "${CMAKE_SOURCE_DIR}/cm_mods/installs/json/share/cmake/nlohmann_json")
find_package(nlohmann_json 3.2.0 REQUIRED)
add_executable(main.exe WIN32 "apps/${APP_NAME}/src/main.cpp")
target_link_libraries(main.exe)
target_link_libraries(main.exe PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(main.exe PRIVATE Interface)
target_link_libraries(main.exe PRIVATE FileIO)

project(Assembler)

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(apps)
add_subdirectory(third-party)