
#ifndef SVG_STRING_H
#define SVG_STRING_H

#include <iostream>
#include <cstring>

const int MAX_BUFFER = 4096;

class String {
public:
    //default constructor
    String();
    //Constructor with 1 argument
    explicit String(const char *text);
    //Copy constructor
    String(const String &other);

    //Setter
    void setText(const char *text);
    //Getters
    const int getSize() const;
    const char *getText() const;

    //Assignment operators
    String &operator=(const String &other);
    String &operator=(const char *other);
    //operator for string concatenation
    String operator+(const String &other) const;
    //operator for returning a char standing on a given index
    char operator[](int index) const;
    //Operator for comparison between two strings
    bool operator==(const String &other) const;

    //Input and output operators
    friend std::istream &operator>>(std::istream &in, String &string);
    friend std::ostream &operator<<(std::ostream &out, const String &string);

    //check if a string is contained inside another string
    bool contains(const String &other) const;
    //strips a given string by another and returns the stripped one
    String strip(const String &other) const;
    bool isNumber();

    //method to print the string
    //void print() const;

    //Destructor
    inline  ~String() {
        delete[] this->text;
    }
private:
    char *text;
    unsigned int size;

};


#endif // SVG_STRING_H
