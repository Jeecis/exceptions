cmake_minimum_required(VERSION 3.29)
project(Exceptions)

set(CMAKE_CXX_STANDARD 20)

add_executable(Exceptions main.cpp
        ErrorClasses/InvalidDay.cpp
        ErrorClasses/InvalidMonth.cpp
        ErrorClasses/InvalidYear.cpp)
