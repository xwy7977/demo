cmake_minimum_required(VERSION 3.10)
project(demo8)

add_subdirectory(${PROJECT_SOURCE_DIR}/moduleA)
add_subdirectory(${PROJECT_SOURCE_DIR}/moduleB)

add_executable(demo8 main.cpp)

target_link_libraries(demo8 moduleB)

# 使用场景：项目里有多个子模块，且子模块之间有依赖关系，且main.cpp依赖子模块。