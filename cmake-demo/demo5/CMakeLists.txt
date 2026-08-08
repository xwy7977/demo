cmake_minimum_required(VERSION 3.10)
project(demo5)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/inc)

# 链接静态库
link_directories(${PROJECT_SOURCE_DIR}/lib)
link_libraries(calc)
add_executable(demo5 ${SRC})

# 使用场景：使用编译好的库。