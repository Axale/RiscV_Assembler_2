add_library(FileIO fileio.cpp)

# Include the directory containing interface.hpp
target_include_directories(FileIO PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(FileIO PRIVATE "${CMAKE_SOURCE_DIR}/modules/interface")