cmake_minimum_required (VERSION 3.24)

project (SVG VERSION 1.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SVG main.cpp
        Helpers/String.cpp
        Helpers/Points.cpp
        Shapes/Line.cpp
        Shapes/Circle.cpp
        Shapes/Rectangle.cpp
        Shapes/Polygon.cpp
        Shapes/Container.cpp
        Shapes/Shape.cpp
        Files/File.cpp
        Files/ShapeFile.cpp
)