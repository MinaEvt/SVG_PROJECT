//
// Created by Mina on 19.6.2024 г..
//

#ifndef SVG_CONTAINER_H
#define SVG_CONTAINER_H

#include "Circle.h"
#include "Line.h"
#include "Polygon.h"
#include "Rectangle.h"

class Container {
public:
    Container();
    Container(const Container& other);
    Container(int cap);
    void add(Shape *s);
    void remove(Shape *s);
    unsigned int getSize() const;
    void print() const;
    void write(std::ostream &out) const;
    void createFromConsole();
    void translate(int index = -1, int horizontal = 0, int vertical = 0);
    void scale(int index = -1, int width = 1, int height = 1);
    //void group( Point pointTopLeft, Point pointBottomRight);
    //void ungroup(int index);
    //void insert(int indexGroup, int indexElement);
    //void extract(int indexGroup, int idexElement);
    Shape *operator[](unsigned int index);
    Container &operator=(const Container &other);
    ~Container() {
        clean();
    }
private:
    Shape ** shape;
    int size;
    int cap;

    void clean();
    void resize();

};


#endif //SVG_CONTAINER_H

