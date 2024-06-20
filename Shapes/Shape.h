//
// Created by Mina on 16.6.2024 г..
//
#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H

#include <iostream>
#include "../Helpers/String.h"

class Shape {
public:
    virtual void print(std::ostream &out) = 0;

    virtual void translate(const int vertical, const int horizontal) = 0;

    virtual void scale(const int width, const int length) = 0;

    virtual void create(std::istream &in) = 0;

    virtual void write(std::ostream &out) = 0;

    virtual bool isCorrectShape() = 0;

    virtual ~Shape() = default;
};


#endif //SVG_SHAPE_H
