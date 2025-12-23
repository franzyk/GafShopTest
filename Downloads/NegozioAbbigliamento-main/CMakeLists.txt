cmake_minimum_required(VERSION 3.23)
project(NegozioAbbigliamento C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(NegozioAbbigliamento ${SOURCES})
