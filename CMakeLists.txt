cmake_minimum_required(VERSION 3.22)

project("Crafting Interpreters")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(lox lox/main.cpp)