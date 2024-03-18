//
// Created by Mina on 28.2.2024 г..
//

#include "String.h"

#pragma warning (disable: 4996)

const int ONE = 1;

void String::copy(const String &other) {
    this->length = other.length;
    this->str = new char[this->length + ONE];
    strcpy(this->str, other.str);
    this->str[this->length] = '\0';
}

String::String() : str(nullptr), length(0) {
    this->str = new char[ONE];
    this->str[0] = '\0';
}

String::String(const char *val) {
    if (val == nullptr) {
        this->str = new char[ONE];
        this->str[0] = '\0';
        this->length = 0;
    } else {
        this->length = strlen(val);
        this->str = new char[this->length];
        strcpy(str, val);
        this->str[this->length] = '\0';
        //std::cout << "The string passed is: " << str << std::endl;
    }
}

String::String(const String &other) {
    this->copy(other);
}

String::String(String &&source) {
    this->str = source.str;
    source.str = nullptr;
    source.length = 0;
}

String &String::operator=(const String &other) {
    if (this == &other) {
        return *this;
    }
    delete[] this->str;
    this->copy(other);
    return *this;
}

std::istream &operator>>(std::istream &is, String &obj) {
    char buff[String::MAX_BUFF];
    is >> buff;
    obj = String(buff);
    return is;
}

std::ostream &operator<<(std::ostream &os, const String &obj) {
    os << obj.str;
    return os;
}

const int String::getLength() const {
    return this->length;
}

void String::setString(const char *text) {
    if (this->str)
        delete[] this->str;
    this->length = strlen(str);
    this->str = new char[this->length + ONE];
    strcpy(this->str, text);
    this->str[this->length] = '\0';
}

const char *String::getString() const {
    return this->str;
}

char String::operator[](int index) {
    return this->str[index];
}

bool String::operator==(const String &other) {
    return strcmp(this->str, other.str) == 0;
}

bool String::operator!=(const String &other) {
    return !(*this == other);
}

bool String::contains(const String &other) const {
    if (this->length < other.length || other.length == 0)
        return false;
    for (int i = 0; i < this->length; ++i) {
        bool found = true;
        for (int j = 0; j < other.length; ++j) {
            if (this->str[i + j] != other.str[j]) {
                found = false;
                break;
            }
        }
        if (found)
            return true;
    }
    return false;
}

