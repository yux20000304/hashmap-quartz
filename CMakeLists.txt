cmake_minimum_required(VERSION 3.20)
project(hashmap_quartz C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(hashmap_quartz main.c)
