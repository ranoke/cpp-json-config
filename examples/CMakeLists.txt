cmake_minimum_required(VERSION 3.7)

include_directories(${CMAKE_SOURCE_DIR}/lib/json/include ${CMAKE_SOURCE_DIR}/lib/logging ${CMAKE_SOURCE_DIR}/include/config)

add_executable(GlobalConfig global.cpp)
target_link_libraries(GlobalConfig JsonConfig)