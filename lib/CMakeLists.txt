add_library(FileIO fileio.cpp)
target_include_directories(FileIO PUBLIC "${CMAKE_SOURCE_DIR}/include")

add_library(Interface interface.cpp)
target_include_directories(Interface PUBLIC "${CMAKE_SOURCE_DIR}/include")
