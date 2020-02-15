cmake_minimum_required(VERSION 2.4)

project(formatter)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(../formatter_lib)

add_library(formatterexlib formatter_ex.cpp ../formatter_lib/formatter.cpp)
#target_link_libraries(formatterLib formatterlib)
