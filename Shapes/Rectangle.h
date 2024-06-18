#ifndef OOP_2024_RECTANGLE_H
#define OOP_2024_RECTANGLE_H

#include "Shape.h"
#include "../Helpers/Points.h"
#include "../Helpers/String.cpp"

class Rectangle : public Shape {
private:
    int width;
    int height;
    int x;
    int y;
    String line;
    String fill;
public:
    void print(std::ostream &out) override;
    void translate(const int vertical, const int horizontal) override;
    void scale(const int width, const int length) override;

    //default constructor
    Rectangle();

    //constructor with params
    Rectangle(int width, int height, int x, int y, String line, String fill);

    //copy constructor
    Rectangle(const Rectangle &other);

    // Assignment operator
    Rectangle &operator=(const Rectangle &other);
//    void read();//read from file?
//    void write();//write in file?

    ~Rectangle() override = default;

};


#endif //OOP_2024_RECTANGLE_H
