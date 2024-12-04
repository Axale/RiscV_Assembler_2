add_executable(main.exe main.cpp)

target_include_directories(main.exe PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/third-party)