//
// Created by Mina on 28.2.2024 г..
//
#pragma once

#include <iostream>
#include <cstring>

class String {
    char *str;

    friend std::ostream &operator<<(std::ostream &os, const String &obj);

    friend std::istream &operator>>(std::istream &is, String &obj);

public:
    String();

    String(char *val);

    String(const String &other);

    String(String &&source);

    const int getSize() const;

    String &operator=(const String &rhs);

    void setString(const char *text);

    const char *getString() const;

    char operator[](int index);

    bool operator==(const String &other);

    bool operator!=(const String &other);

    bool contain(const String &other) const;

    ~String() {
        delete str;
    }
};