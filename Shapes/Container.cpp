//
// Created by Mina on 19.6.2024 г..
//

#include "Container.h"

void Container::clean() {
    for (int i = 0; i < this->size; ++i) {
        delete this->shape[i];//Signal: SIGSEGV (Segmentation fault)
    }
    delete[] this->shape;
    shape = nullptr;
    size = 0;
    cap = 0;
}

void Container::resize() {
    int newCap = 0;
    if (this->cap == 0) {
        newCap = 1;
    } else {
        newCap = this->cap * 2;
    }

    auto **newShape = new Shape *[newCap];
    for (int i = 0; i < this->size; ++i) {
        newShape[i] = this->shape[i];
    }
    delete[] this->shape;
    this->shape = newShape;
    this->cap = newCap;
}

Container::Container() : shape(nullptr), size(0), cap(0) {}

Container::Container(int _cap) : cap(_cap), shape(new Shape *[_cap]), size(0) {}

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
        std::cout << "index " << i << ": " << this->shape[i] << std::endl;
        this->shape[i]->print(std::cout);//(1)The container:
        //index 0: 0x55a1f6ab0730
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


bool isCorrectShape(const String &isShape) {//da go napisha krasivo
    bool isCorrect = false;
    if (isShape == (String) "Rectangle" || isShape == (String) "rectangle" ||
        isShape == (String) "Line" || isShape == (String) "line" ||
        isShape == (String) "Circle" || isShape == (String) "circle" ||
        isShape == (String) "Polygon" || isShape == (String) "polygon")
        isCorrect = true;
    return isCorrect;
}

void Container::createFromConsole() {
    //std::cout << "Enter shape: ";
    String shapeType;
    std::cin >> shapeType;
    if (isCorrectShape(shapeType)) {
        Shape *_shape;
        if (shapeType == (String) "Rectangle" || shapeType == (String) "rectangle") {
            std::cout << "(" << this->size << ")";
            _shape = new Rectangle;
            _shape->create(std::cin);
            this->add(_shape);
            std::cout << "Added: ";
            _shape->print(std::cout);
            delete _shape;
            return;
        }
        if (shapeType == (String) "Line" || shapeType == (String) "line") {
            std::cout << "(" << this->size << ")";
            _shape = new Line;
            _shape->create(std::cin);
            this->add(_shape);
            std::cout << "Added: ";
            _shape->print(std::cout);
            delete _shape;
            return;
        }
        if (shapeType == (String) "Circle" || shapeType == (String) "circle") {
            std::cout << "(" << this->size << ")";
            _shape = new Circle;
            _shape->create(std::cin);
            this->add(_shape);
            std::cout << "Added: ";
            _shape->print(std::cout);
            delete _shape;
            return;
        }
        if (shapeType == (String) "Polygon" || shapeType == (String) "polygon") {
            std::cout << "(" << this->size << ")";
            _shape = new Polygon;
            _shape->create(std::cin);
            this->add(_shape);
            std::cout << "Added: ";
            _shape->print(std::cout);
            delete _shape;
            return;
        }
    } else {
        throw std::invalid_argument("This is not correct shape type!");
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




