//
// Created by Mina on 18.6.2024 г..
//

#ifndef SVG_POLYGON_H
#define SVG_POLYGON_H


#include "Shape.h"
#include "../Helpers/Points.h"

class Polygon : public Shape {
public:
    void print(std::ostream &out) override;

    void translate(const int vertical, const int horizontal) override;

    void scale(const int width, const int length) override;

    void create(std::istream &in) override;

    void write(std::ostream &out) override;

    bool isCorrectShape() override;

    ~Polygon() override {
        delete[] points;
    }

    Polygon();

    Polygon(const Point &point, int pointsNumber, const String &line, const String &fill);

    Polygon(const Polygon &other);

    Polygon &operator=(const Polygon &other);
private:
    Point *points;
    int pointsNumber;
    String line;
    String fill;

};


#endif //SVG_POLYGON_H
