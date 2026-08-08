message("go to model b")

project(moduleB)

add_library(moduleB STATIC
    src/b.cpp
)

target_include_directories(moduleB PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(moduleB PUBLIC moduleA)