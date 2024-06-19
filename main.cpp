//#include "Shapes/Rectangle.cpp"
//#include "Shapes/Line.cpp"
//#include "Shapes/Circle.cpp"
//#include "Helpers/String.cpp"
#include "Shapes/Polygon.cpp"

int main() {
    Polygon p1;
    p1.write(std::cout);
    p1.create(std::cin);
    p1.write(std::cout);
    p1.translate(10,10);
    p1.write(std::cout);
    p1.scale(100, 100);
    p1.write(std::cout);


    return 0;
}
