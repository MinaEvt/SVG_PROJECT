//
// Created by Mina on 28.2.2024 г..
//

#include "String.h"

#pragma warning (disable: 4996)

const int ONE = 1;

String::String() : str{nullptr} {
    str = new char[ONE];
    str[0] = '\0';
}

String::String(char *val) {
    if (val == nullptr){
        str = new char[ONE];
        str[0] = '\0';
    }else{
        str = new char[strlen(val) + ONE];
        strcpy(str, val);
        str[strlen(val)] = '\0';
        //std::cout << "The string passed is: " << str << std::endl;
    }
}

String::String(const String &other) {
    str = new char[strlen(other.str) + ONE];
    strcpy(str, other.str);
    str[strlen(other.str)] =  '\0';
}

String::String(String &&source) {
    str = source.str;
    source.str = nullptr;
}

String& String::operator=(const String& rhs){
    if(this == &rhs){
        return *this;
    }
    delete[] str;
    str = new char[strlen(rhs.str) + ONE];
    strcpy(str, rhs.str);
    return *this;
}

std::istream& operator>>(std::istream& is, String& obj){
char* buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = String{ buff };
    delete[] buff;
    return is;
}

std::ostream& operator<<( std::ostream& os,const String& obj){
    os << obj.str;
    return os;
}

const int String::getSize() const{
    return strlen(str);
}

void String::setString(const char *text) {
    if (this->str){
        delete[] this->str;
    }
    this->str = new char[strlen(str) + ONE];
    strcpy(this->str, text);
}

const char *String::getString() const {
    return this->str;
}

char String::operator[](int index) {
    return this->str[index];
}

bool String::operator==(const String &other) {
    if(strlen(this->str) != other.getSize())
        return false;
    for(int i = 0; i < strlen(this->str); i++){
        if(this->str[i] != other.str[i])
            return false;
    }
    return true;
}

bool String::operator!=(const String &other) {
    return !(operator==(other));
}

bool String::contain(const String &other) const {

}

