//
// Created by Mina on 16.6.2024 г..
//

#include "Rectangle.h"

void Rectangle::print(std::ostream &out) {
    out << "Rectangle: "
    << "width: " << this->width << ' '
    << "height: " << this->height << ' '
    << "x: " << this->x << ' '
    << "y: " << this->y << ' '
    << "line: " << this->line << ' '
    << "fill: " << this->fill << std::endl;
}

void Rectangle::translate(const int vertical, const int horizontal) {
    this->x += horizontal;
    this->y += vertical;
}

void Rectangle::scale(const int width, const int length) {
    this->height *= length;
    this->width *= width;
}

Rectangle::Rectangle()
        : width(0), height(0), x(0), y(0), line("black"), fill("white") {}

Rectangle::Rectangle(const Rectangle &other)
        : width(other.width), height(other.height), x(other.x), y(other.y), line(other.line), fill(other.fill) {}

Rectangle &Rectangle::operator=(const Rectangle &other) {
    if (this != &other) {
        this->width = other.width;
        this->height = other.height;
        this->x = other.x;
        this->y = other.y;
        this->line = other.line;
        this->fill = other.fill;
    }
    return *this;
}

Rectangle::Rectangle(int width, int height, int x, int y, String line, String fill)
        : width(width), height(height), x(x), y(y), line(line), fill(fill) {}


