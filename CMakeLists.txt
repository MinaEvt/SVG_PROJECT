cmake_minimum_required(VERSION 3.10)
project(SVG)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(SVG main.cpp Shapes/Rectangle.cpp Helpers/String.cpp)
