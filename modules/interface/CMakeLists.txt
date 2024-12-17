add_library(Interface interface.cpp)

# Include the directory containing interface.hpp
target_include_directories(Interface PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(Interface PRIVATE "${CMAKE_SOURCE_DIR}/modules/fileio")
