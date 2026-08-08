cmake_minimum_required(VERSION 3.10)
project(demo2)

# 此命令只会包含源文件，不会包含头文件（.h）。
aux_source_directory(. SRC)
message(${SRC}) # ./main.cpp./test1.cpp./test2.cpp

add_executable(demo2 ${SRC})

# 使用场景：多个源文件和头文件放在同一目录下。