cmake_minimum_required(VERSION 3.4)
project(assignmnt_1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES triangular.c)
add_executable(assignmnt_1 ${SOURCE_FILES})