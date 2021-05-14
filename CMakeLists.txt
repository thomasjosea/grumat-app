cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 14)

project(grumat)

file(GLOB SOURCES
    include/*h
    include/*.cpp)

add_compile_options(-Wall -Wextra -pedantic)

add_executable(grumat main.cc ${SOURCES})