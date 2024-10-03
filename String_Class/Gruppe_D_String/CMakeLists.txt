cmake_minimum_required(VERSION 3.24.2)
project(String_Class)

set(CMAKE_CXX_STANDARD 20)

add_executable(String_Class main.cpp
        String.cpp
        String.h
        doctest.h)
