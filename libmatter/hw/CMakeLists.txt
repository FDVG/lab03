cmake_minimum_required(VERSION 2.4)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/formatter_ex_lib)
include_directories(${PROJECT_SOURCE_DIR}/formatter_lib)

add_library(hwlib STATIC formatter_ex_lib/formatter_ex.cpp formatter_ex_lib/formatter_ex.h formatter_lib/formatter.cpp formatter_lib/formatter.h)
add_executable(app hw.cpp)
target_link_libraries(app hwlib)
#target_link_libraries(app applib)
#add_library(formatterexlib formatter_ex.cpp ../formatter_lib/formatter.cpp)
#target_link_libraries(formatterLib formatterlib)
