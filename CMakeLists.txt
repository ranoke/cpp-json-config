cmake_minimum_required(VERSION 3.7)

project(JsonConfigLibrary)

include_directories(lib/json/include lib/logging include)

add_library(JsonConfig STATIC src/Config.cpp src/ConfigFile.cpp)


# compile examples
add_subdirectory(examples)