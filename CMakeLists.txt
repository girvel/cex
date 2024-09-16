cmake_minimum_required(VERSION 3.10)
project(cex C)
set(CMAKE_C_STANDARD 11)
add_executable(cex cex.c framework/array.c framework/string.c components.c ecs/entity.c ecs/system.c)
