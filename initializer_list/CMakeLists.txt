cmake_minimum_required(VERSION 3.15)

project(initializer_list)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(initializer_list main.cpp initializer_list.hpp)
