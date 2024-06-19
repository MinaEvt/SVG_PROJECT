#ifndef SVG_RECTANGLE_H
#define SVG_RECTANGLE_H

//#pragma once

#include "Shape.h"
#include "../Helpers/Points.h"
//#include "../Helpers/String.cpp"

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

    void create(std::istream &in) override;

    void write(std::ostream &out) override;

    bool isCorrectShape() override;

    //default constructor
    Rectangle();

    //constructor with params
    Rectangle(int width, int height, int x, int y, const String &line, const String &fill);

    //copy constructor
    Rectangle(const Rectangle &other);

    // Assignment operator
    Rectangle &operator=(const Rectangle &other);


    ~Rectangle() override = default;

};


#endif //SVG_RECTANGLE_H
