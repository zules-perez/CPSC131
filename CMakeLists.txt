cmake_minimum_required(VERSION 3.23)
project(CPSC131)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPSC131
        Graph.cpp
        Graph.h
        main.cpp)
