message("go to model a")

project(moduleA)

add_library(moduleA STATIC 
    src/a.cpp
)

target_include_directories(moduleA PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)