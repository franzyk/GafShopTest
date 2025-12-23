cmake_minimum_required(VERSION 3.23)
project(NegozioAbbigliamento C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(NegozioAbbigliamento ${SOURCES})

add_custom_command(TARGET NegozioAbbigliamento POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/data
                   $<TARGET_FILE_DIR:NegozioAbbigliamento>/data)
