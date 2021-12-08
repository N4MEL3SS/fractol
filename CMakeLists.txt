cmake_minimum_required(VERSION 3.16)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)
add_executable(fractol main.c)
