//
// Created by Mina on 18.6.2024 г..
//

#include "Circle.h"

void Circle::print(std::ostream &out) {
    out << "The circle is: "
        << "x1 = " << this->cx
        << " y1 = " << this->cy
        << " x2 = " << this->r
        << " line color = " << this->line
        << " fill color = " << this->fill
        << std::endl;
}

void Circle::translate(const int vertical, const int horizontal) {
    this->cx += horizontal;
    this->cy += horizontal;
}

void Circle::scale(const int width, const int length) {
    this->r *= width;
}

void Circle::write(std::ostream &out) {
    out << "<circle "
        << "r=\"" << this->r << "\" "
        << "cx=\"" << this->cx << "\" "
        << "cy=\"" << this->cy << "\" "
        << "line=\"" << this->line << "\" "
        << "fill=\"" << this->fill << "\" "
        << "/>"
        << std::endl;
}

bool Circle::isCorrectShape() {
    if (this->fill.isNumber())
        return false;
    if (this->line.isNumber())
        return false;
    return true;
}

void Circle::create(std::istream &in) {
    std::cout << "Enter circle ->";
    std::cout << "Enter r: ";
    in >> this->r;
    std::cout << "Enter cx: ";
    in >> this->cx;
    std::cout << "Enter cy: ";
    in >> this->cy;
    std::cout << "Enter linecolor: ";
    std::cin >> std::ws;
    in >> this->line;
    std::cout << "Enter fillcolor: ";
    std::cin >> std::ws;
    in >> this->fill;
    if (!isCorrectShape()) {
        std::cout << "Error! Enter correct circle!" << std::endl;
    }
}

Circle::Circle() : cx(0), cy(0), r(0),line("black"), fill("white"){}

Circle::Circle(const Circle &other)  : cx(other.cx), cy(other.cy), r(other.r),line(other.line), fill(other.fill) {}

Circle::Circle(int cx, int cy, int r,const String &line, const String &fill)  : cx(cx), cy(cy), r(r), line(line),fill(fill){}

Circle &Circle::operator=(const Circle &other) {
    if(this != &other){
        this->cx = other.cx;
        this->cy = other.cy;
        this->r = other.r;
        this->line = other.line;
        this->fill = other.fill;
    }
    return *this;
}