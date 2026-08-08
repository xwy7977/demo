cmake_minimum_required(VERSION 3.10)
project(demo3)

# bin目录下保存最后生成的可执行文件
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 此命令只会包含源文件，不会包含头文件（.h）。
aux_source_directory(src SRC)
message(${SRC}) # ./main.cpp./test1.cpp./test2.cpp

# 指定头文件路径
include_directories(inc)

add_executable(demo3 ${SRC})

# 使用场景：源文件和头文件放在不同目录时。