//#include "Shapes/Rectangle.cpp"
//#include "Shapes/Line.cpp"
#include "Shapes/Circle.cpp"

int main() {
    //string
//    String str1, str2;
//    std::cin >> str1;
//    std::cin >> str2;
//    std::cout << str1 << ' ' << str2 << std::endl;

//rectangle
//    Rectangle rect(12,13,1,1,"black", "white");
//   // rect.create(std::cin); //does not work
//    //rect.print(std::cout);
//    rect.write(std::cout);
//    rect.translate(10, 10);
//    std::cout<< "rect after translate: ";
//    rect.write(std::cout);
//    rect.scale(100, 100);
//    std::cout << "rect after scale: ";
//    rect.write(std::cout);

//line
//    Line l;
//    l.write(std::cout);
//    l.translate(10, 10);
//    std::cout << "Traslated line: ";
//    l.write(std::cout);
//    l.scale(100, 100);
//    std::cout << "Scaled line: ";
//    l.write(std::cout);

//circle
Circle c;
c.write(std::cout);
c.translate(10, 10);
std::cout << "Translated sircle: ";
c.write(std::cout);
c.scale(100,100);
std::cout << "Scaled sircle: ";
c.write(std::cout);
    return 0;
}
