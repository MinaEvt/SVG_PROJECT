//
// Created by Mina on 18.6.2024 г..
//

#include "Line.h"

void Line::print(std::ostream &out) {
    out << "The line is: "
        << "x1 = " << this->x1
        << " y1 = " << this->y1
        << " x2 = " << this->x2
        << " y2 = " << this->y2
        << " linecolor = " << this->line << std::endl;
}

void Line::translate(const int vertical, const int horizontal) {
    this->x1 += horizontal;
    this->y1 += vertical;
    this->x2 += horizontal;
    this->y2 += vertical;
}

void Line::scale(const int width, const int length) {
    this->x2 *= length;
    this->y2 *= length;
}

void Line::write(std::ostream &out) {
    out << "<line "
        << "x1=\"" << this->x1 << "\" "
        << "y1=\"" << this->y1 << "\" "
        << "x2=\"" << this->x2 << "\" "
        << "y2=\"" << this->y2 << "\" "
        << "line=\"" << this->line << "\" "
        << "/>"
        << std::endl;
}

bool Line::isCorrectShape() {
    if (this->line.isNumber())
        return false;
    return true;
}

void Line::create(std::istream &in) {
    std::cout << "Enter line ->";
    std::cout << "Enter x1: ";
    in >> this->x1;
    std::cout << "Enter y1: ";
    in >> this->y1;
    std::cout << "Enter x2: ";
    in >> this->x2;
    std::cout << "Enter y2: ";
    in >> this->y2;
    std::cout << "Enter linecolor: ";
    //std::getline(in, this->line);
    std::cin >> std::ws;
    in >> this->line;//jumps over
    if (!isCorrectShape()) {
        std::cout << "Error! Enter correct line!" << std::endl;
    }
}

//Line::Line() : x1(0), y1(0), x2(0), y2(0), line("black") {}

Line::Line() {
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 0;
    this->y2 = 0;
    this->line = "black";
}

Line::Line(const Line &other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), line(other.line) {}

//Line::Line(int x1, int y1, int x2, int y2, const String &line) : x1(x1), y1(y1), x2(x2), y2(y2), line(line) {}

Line::Line(int x1, int y1, int x2, int y2, const String &line) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->line = line;
}

Line &Line::operator=(const Line &other) {
    if (this != &other) {
        this->x1 = other.x1;
        this->y1 = other.y1;
        this->x2 = other.x2;
        this->y2 = other.y2;
        this->line = other.line;
    }
    return *this;
}