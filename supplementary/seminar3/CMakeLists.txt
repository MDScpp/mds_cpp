cmake_minimum_required(VERSION 3.10)

project(MyProgram)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-fno-elide-constructors)
endif()

add_executable(my_program main.cpp)
