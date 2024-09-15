cmake_minimum_required(VERSION 3.10)
project(cex C)
set(CMAKE_C_STANDARD 11)
add_executable(cex cex.c framework/dynamic_array.c framework/dynamic_string.c components.c ecs/entity.c)
