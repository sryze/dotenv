project(dotenv_example)

cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dotenv_example
    dotenv.cpp
    dotenv.h
    example/example.cpp
)