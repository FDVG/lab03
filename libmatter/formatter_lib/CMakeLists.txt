cmake_minimum_required(VERSION 2.4)

project(formatter)

include_directories(${PROJECT_SOURCE_DIR})
add_library(formatterlib formatter.cpp)
#target_link_libraries(formatterLib formatterlib)
