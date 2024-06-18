
#ifndef OOP_2024_STRING_H
#define OOP_2024_STRING_H


#include <iostream>
#include <cstring>

const int MAX_BUFFER = 4096;

class String {
private:
    char *text;
    unsigned int size;
public:
    //default constructor
    String();

    //Constructor with 1 argument
    String(const char *text);

    //Copy constructor
    String(const String &other);

    //Setter
    void setText(const char *text);

    //Getters
    const unsigned int getSize() const;

    const char *getText() const;

    //operator for assigment
    String &operator=(const String &other);

    //operator = with char*
    String &operator=(const char *other);

    //operator for string concatenation
    String operator+(const String &other);

    //operator for returning a char standing on a given index
    char operator[](int index);

    //Operator for comparison between two strings
    bool operator==(const String &other);

    //operator for input and output
    friend std::istream &operator>>(std::istream &in, String &string);

    friend std::ostream &operator<<(std::ostream &out, String &string);

    //check if a string is contained inside another string
    bool contains(const String &other) const;

    //strips a given string by another and returns the stripped one
    String strip(const String &other) const;

    bool isNumber();

    //method to print the string
    //void print() const;

    //Destructor
    ~String() {
        delete[] this->text;
    }


};


#endif //OOP_2024_STRING_H
