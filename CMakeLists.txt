cmake_minimum_required(VERSION 2.8)

project(dotenv_example)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dotenv_example
    dotenv.cpp
    dotenv.h
    example/example.cpp
)

if(CMAKE_CXX_COMPILER_ID MATCHES "(GNU|Clang)")
    set_target_properties(dotenv_example PROPERTIES COMPILE_FLAGS -std=c++11)
endif()
