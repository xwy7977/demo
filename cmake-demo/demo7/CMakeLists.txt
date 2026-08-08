cmake_minimum_required(VERSION 3.10)
project(demo7)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/inc)

# 这个命令必须放在add_executable之前
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(demo7 ${SRC})


target_link_libraries(demo7 calc)

# 使用场景：使用编译好的动态库。