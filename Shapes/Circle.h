//
// Created by Mina on 18.6.2024 г..
//

#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
public:
     void print(std::ostream &out)override;

     void translate(const int vertical, const int horizontal) override;

     void scale(const int width, const int length) override;

     void create(std::istream &in) override;

     void write(std::ostream &out) override;

     bool isCorrectShape() override;

     ~Circle() override = default;

     Circle();

     Circle(int cx, int cy, int r, const String &line, const String &fill);

     Circle(const Circle &other);

     Circle &operator=(const Circle &other);
private:
    int cx;
    int cy;
    int r;
    String line;
    String fill;


};


#endif //SVG_CIRCLE_H
