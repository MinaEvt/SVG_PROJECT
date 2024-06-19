//
// Created by Mina on 18.6.2024 г..
//

#include "Polygon.h"

Polygon::Polygon() : points(nullptr), pointsNumber(0), line("black"), fill("white") {}

Polygon::Polygon(const Polygon &other) : pointsNumber(other.pointsNumber), line(other.line), fill(other.fill) {
    points = new Point[this->pointsNumber];
    for (int i = 0; i < this->pointsNumber; ++i) {
        points[i] = other.points[i];
    }
}

Polygon::Polygon(const Point &point, int pointsNumber, const String &line, const String &fill)
        : pointsNumber(pointsNumber), line(line), fill(fill) {
    this->points = new Point[this->pointsNumber];
    for (int i = 0; i < this->pointsNumber; ++i) {
        this->points[i] = point;
    }
}

Polygon &Polygon::operator=(const Polygon &other) {
    if (this != &other) {
        delete[] this->points;

        this->pointsNumber = other.pointsNumber;
        this->line = other.line;
        this->fill = other.fill;

        this->points = new Point[this->pointsNumber];
        for (int i = 0; i < this->pointsNumber; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

void Polygon::print(std::ostream &out) {
    out << "The polygon is: "
        << "Number of points: " << this->pointsNumber;
    for (int i = 0; i < this->pointsNumber; ++i) {
        out << "Point " << i + 1 << ": (" << this->points->x << ", " << this->points->y << " ) ";
    }
    out << "line: " << this->line
        << "fill: " << this->fill
        << std::endl;
}

void Polygon::translate(const int vertical, const int horizontal) {
    for (int i = 0; i < this->pointsNumber; ++i) {
        this->points[i].x += horizontal;
        this->points[i].y += vertical;
    }
}

void Polygon::scale(const int width, const int length) {
    for (int i = 0; i < this->pointsNumber; ++i) {
        this->points[i].x *= width;
        this->points[i].y *= length;
    }
}

void Polygon::create(std::istream &in) {
    std::cout << "Enter polygon ->";
    std::cout << "Enter number of points: ";
    in >> this->pointsNumber;
    delete[] points;
    points = new Point[this->pointsNumber];
    for (int i = 0; i < this->pointsNumber; ++i) {
        std::cout << "Enter x" << i+1 << ": ";
        in >> points[i].x;
        std::cout << std::endl;
        std::cout << "Enter y" << i+1 << ": ";
        in >> points[i].y;
    }
    std::cout << "Enter line: ";
    in >> this->line;
    std::cout << "Enter fill: ";
    in >> this->fill;
    if (!isCorrectShape()) {
        std::cout << "Error! Enter correct line!" << std::endl;
    }
}

bool Polygon::isCorrectShape() {
    if (this->line.isNumber())
        return false;
    if (this->fill.isNumber())
        return false;
    return true;
}

void Polygon::write(std::ostream &out) {
    out << "<polygon ";
    out << "points= \"";
    for (int i = 0; i < this->pointsNumber; ++i) {
        out << points[i].x << "," << points[i].y << ' ';
    }
    out << "\"";
    out << "line=\"" << this->line << "\" "
        << "fill=\"" << this->fill << "\" "
        << "/>"
        << std::endl;
}