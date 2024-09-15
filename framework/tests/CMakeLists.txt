cmake_minimum_required(VERSION 3.10)
project(cex_tests C)
set(CMAKE_C_STANDARD 11)
add_executable(cex_tests test_dynamic_array.c ../dynamic_array.c ../dynamic_string.c)
