//
// Created by Mina on 16.6.2024 г..
//

#include "Rectangle.h"

Rectangle::Rectangle() : width(0), height(0), x(0), y(0){
    this->line = "black";
    this->fill = "white";

}

Rectangle::Rectangle(Rectangle &other) {
    this->width = other.width;
    this->height = other.width;
    this->x = other.x;
    this->y = other.y;
    this->line = other.line;
    this->fill = other.fill;
}

Rectangle &Rectangle::operator=(Rectangle &other) {
    this->width = other.width;
    this->height = other.width;
    this->x = other.x;
    this->y = other.y;
    this->line = other.line;
    this->fill = other.fill;
    return *this;
}

Rectangle::Rectangle(int width, int height, int x, int y, String line, String fill) {
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    this->line = line;
    this->fill = fill;
}

void Rectangle::print(std::ostream &out) {
    out << "Rectangle: ";
    out << "width: " << this->width << ' ';
    out << "height: " << this->height << ' ';
    out << "x: " << this->x << ' ';
    out << "y: " << this->y << ' ';
    out << "line: " << this->line << ' ';
    out << "fill: " << this->fill << std::endl;
}

//void Rectangle::translate(const int vertical, const int horizontal) {
//
//}
//
//void Rectangle::scale(const int width, const int length) {
//
//}
//
//Shape Rectangle::create() {
//return *this;
//}