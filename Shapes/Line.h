//
// Created by Mina on 18.6.2024 г..
//

#ifndef SVG_LINE_H
#define SVG_LINE_H

#include "Shape.h"
#include "../Helpers/String.cpp"

class Line : public Shape {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    String line;
public:
    void print(std::ostream &out) override;

    void translate(const int vertical, const int horizontal) override;

    void scale(const int width, const int length) override;

    void create(std::istream &in) override;

    void write(std::ostream &out) override;

    bool isCorrectShape() override;

    Line();

    Line(int x1, int y1, int x2, int y2, const String &line);

    Line(const Line &other);

    Line &operator=(const Line &other);

    ~Line() override = default;
};


#endif //SVG_LINE_H
