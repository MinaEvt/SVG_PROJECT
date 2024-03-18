//
// Created by Mina on 28.2.2024 г..
//
#pragma once

#include <iostream>
#include <cstring>

class String {
    static const unsigned int MAX_BUFF = 1024;
private:
    char *str;

    unsigned int length;

    void copy(const String &other);

public:
    String();

    String(const char *val);

    String(const String &other);

    String(String &&source);

    const int getLength() const;

    String &operator=(const String &rhs);

    void setString(const char *text);

    const char *getString() const;

    char operator[](int index);

    bool operator==(const String &other);

    bool operator!=(const String &other);

    bool contains(const String &other) const;

    friend std::ostream &operator<<(std::ostream &os, const String &obj);

    friend std::istream &operator>>(std::istream &is, String &obj);

    ~String() {
        delete[] this->str;
    }
};