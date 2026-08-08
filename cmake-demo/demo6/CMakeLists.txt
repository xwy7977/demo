cmake_minimum_required(VERSION 3.10)
project(demo6)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/inc)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 动态库
add_library(calc SHARED ${SRC})

# 静态库
# add_library(calc STATIC ${SRC})

# 使用场景：编译成动态库。