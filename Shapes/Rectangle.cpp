//
// Created by Mina on 16.6.2024 г..
//

#include "Rectangle.h"

void Rectangle::print(std::ostream &out) {
    out << "Rectangle: "
        << "width: " << this->width << ' '
        << " height: " << this->height << ' '
        << " x: " << this->x << ' '
        << " y: " << this->y << ' '
        << " line: " << this->line << ' '
        << " fill: " << this->fill << std::endl;
}

void Rectangle::translate(const int vertical, const int horizontal) {
    this->x += horizontal;
    this->y += vertical;
}

void Rectangle::scale(const int width, const int length) {
    this->height *= length;
    this->width *= width;
}

bool Rectangle::isCorrectShape() {
    if (this->fill.isNumber())
        return false;
    if (this->line.isNumber())
        return false;
    return true;
}

void Rectangle::create(std::istream &in) {
    std::cout << "Enter rectangle ->";
    std::cout << "Enter width: ";
    in >> this->width;
    std::cout << "Enter height: ";
    in >> this->height;
    std::cout << "Enter x: ";
    in >> this->x;
    std::cout << "Enter y: ";
    in >> this->y;
    std::cout << "Enter line: ";
    std::cin >> std::ws;
    in >> this->line;
    std::cout << "Enter fill: ";
    std::cin >> std::ws;
    in >> this->fill;
    if (!isCorrectShape()) {
        std::cout << "Error! Enter correct rectangle!" << std::endl;
    }
}

void Rectangle::write(std::ostream &out) {
    out << "<rect "
        << "x=\"" << this->x << "\" "
        << "y=\"" << this->y << "\" "
        << "width=\"" << this->width << "\" "
        << "height=\"" << this->height << "\" "
        << "line=\"" << this->line << "\" "
        << "fill=\"" << this->fill << "\" "
        << "/>"
        << std::endl;
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

Rectangle::Rectangle(int width, int height, int x, int y, const String &line, const String &fill)
        : width(width), height(height), x(x), y(y), line(line), fill(fill) {}


