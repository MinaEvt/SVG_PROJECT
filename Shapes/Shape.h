//
// Created by Mina on 16.6.2024 г..
//
#pragma once

#ifndef OOP_2024_SHAPE_H
#define OOP_2024_SHAPE_H
#include <iostream>


class Shape {
public:
    virtual void print(std::ostream &out);
//    virtual Shape create();
//    virtual void translate(const int vertical, const int horizontal);
//    virtual void scale(const int width, const int length);

    virtual ~Shape() = default;

};


#endif //OOP_2024_SHAPE_H
