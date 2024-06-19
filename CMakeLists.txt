cmake_minimum_required(VERSION 3.10)
project(SVG)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(SVG main.cpp
        Helpers/String.cpp
        Shapes/Rectangle.cpp
        Shapes/Line.cpp
        Shapes/Circle.cpp
        Shapes/Polygon.cpp
)
