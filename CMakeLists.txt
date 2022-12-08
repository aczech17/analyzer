cmake_minimum_required(VERSION 3.23)
project(alex C)

set(CMAKE_C_STANDARD 99)

add_executable(alex alex.c fun_stack.c syntax_parser.c vector.c fun_info.c main.c dict.c)
#add_executable(alex main.c vector.c fun_stack.c)
