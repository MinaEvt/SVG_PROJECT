//
// Created by Mina on 19.6.2024 г..
//

#include "Container.h"

void Container::clean() {
    for (int i = 0; i < this->size; ++i) {
        delete this->shape[i];
    }
    delete[] this->shape;
    shape = nullptr;
    size = 0;
    cap = 0;
}

void Container::resize() {
    int newCap;
    if (this->cap == 0) {
        newCap = 1;
    } else {
        newCap = this->cap * 2;
    }

    Shape **newShape = new Shape *[newCap];
    for (int i = 0; i < this->size; ++i) {
        newShape[i] = this->shape[i];
    }
    delete[] this->shape;
    this->shape = newShape;
    this->cap = newCap;
}

Container::Container() : shape(nullptr), size(0), cap(0) {}

Container::Container(int cap) : shape(new Shape *[this->cap]), size(0), cap(cap) {}

Container::Container(const Container &other) : shape(new Shape *[other.cap]), size(other.size), cap(other.cap) {
    for (int i = 0; i < this->size; ++i) {
        shape[i] = other.shape[i];
    }
}

Container &Container::operator=(const Container &other) {
    if (this == &other)
        return *this;

    clean();
    this->shape = new Shape *[other.cap];
    this->size = other.size;
    this->cap = other.cap;
    for (int i = 0; i < this->size; ++i) {
        this->shape[i] = other.shape[i];
    }
    return *this;
}

void Container::add(Shape *s) {
    if (this->size == this->cap)
        resize();
    this->shape[size++] = s;
}

void Container::remove(Shape *s) {
    for (int i = 0; i < this->size; ++i) {
        if (this->shape[i] == s) {
            delete[] shape[i];
            for (int j = i; j < this->size - 1; ++j) {
                this->shape[j] = this->shape[j + 1];
            }
            shape[--size] = nullptr;
            break;
        }
    }
}

unsigned int Container::getSize() const {
    return this->size;
}

void Container::print() const {
    std::cout << "The container: " << std::endl;
    for (int i = 0; i < this->size; ++i) {
        //std::cout << "index " << i << ": " << this->shape[i] << std::endl;
        this->shape[i]->print(std::cout);
    }
}

void Container::write(std::ostream &out) const {
    out << "<svg xmlns=";
    out << "\"http://www.w3.org/2000/svg\"";
    out << ">" << std::endl;
    for (int i = 0; i < this->size; ++i) {
        out << "     ";
        shape[i]->write(out);
    }
    out << "</svg>";
}

void Container::createFromConsole() {
    std::cout << "Enter shape: ";
    String shapeType;
    std::cin >> shapeType;
    Shape *shape;
    if (shapeType == (String) "Rectangle" || shapeType == (String) "rectangle") {
        shape = new Rectangle;
        shape->create(std::cin);
        this->add(shape);
        std::cout << "Added: ";
        shape->print(std::cout);
        std::cout << "(" << this->size << ")";
        delete shape;
        return;
    }
    if (shapeType == (String) "Line" || shapeType == (String) "line") {
        shape = new Line;
        shape->create(std::cin);
        this->add(shape);
        std::cout << "Added: ";
        shape->print(std::cout);
        std::cout << "(" << this->size << ")";
        delete shape;
        return;
    }
    if (shapeType == (String) "Circle" || shapeType == (String) "circle") {
        shape = new Circle;
        shape->create(std::cin);
        this->add(shape);
        std::cout << "Added: ";
        shape->print(std::cout);
        std::cout << "(" << this->size << ")";
        delete shape;
        return;
    }
    if (shapeType == (String) "Polygon" || shapeType == (String) "polygon") {
        shape = new Polygon;
        shape->create(std::cin);
        this->add(shape);
        std::cout << "Added: ";
        shape->print(std::cout);
        std::cout << "(" << this->size << ")";
        delete shape;
        return;
    }
}

void Container::translate(int index, int horizontal, int vertical) {
    if (index == -1) {
        for (int i = 0; i < this->size; ++i) {
            this->shape[i]->translate(horizontal, vertical);
        }
    } else {
        this->shape[index]->translate(horizontal, vertical);
    }
}

void Container::scale(int index, int width, int height) {
    if (index == -1) {
        for (int i = 0; i < this->size; ++i) {
            this->shape[i]->scale(width, height);
        }
    } else {
        this->shape[index]->scale(width, height);
    }
}

//void Container::group(Point pointTopLeft, Point pointBottomRight){
//
//}

Shape *Container::operator[](unsigned int index) {
    return this->shape[index];
}




