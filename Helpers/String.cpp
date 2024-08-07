//
// Created by Mina on 16.6.2024 г..
//



#include "String.h"

 String::String() : text(nullptr), size(0) {
    this->text = new char[1];
    this->text[0] = '\0';
}

 String::String(const char *text) {
    this->size = std::strlen(text);
    this->text = new char[this->size + 1];
    std::strcpy(this->text, text);
}

 String::String(const String &other) {
    this->size = other.size;
    this->text = new char[this->size + 1];
    std::strcpy(this->text, other.text);
}

 void String::setText(const char *_text) {
    delete[] this->text;
    this->size = std::strlen(_text);
    this->text = new char[this->size + 1];
    std::strcpy(this->text, _text);

}

const int String::getSize() const {
    return this->size;
}

 const char *String::getText() const {
    return this->text;
}

 String &String::operator=(const String &other) {
    if (this != &other) {
        delete[] this->text;
        this->size = other.size;
        this->text = new char[this->size + 1];
        std::strcpy(this->text, other.text);
    }
    return *this;
}

 String &String::operator=(const char *other) {
    if (this->text == other)
        return *this;

    delete[] this->text;

    if (other) {
        this->size = std::strlen(other);
        this->text = new char[this->size + 1];
        std::strcpy(this->text, other);
    } else {
        this->text = nullptr;
        this->size = 0;
    }

    return *this;
}

 String String::operator+(const String &other) const{
    unsigned int new_size = this->size + other.getSize();
    char *new_text = new char[new_size + 1];
    std::strcpy(new_text, this->text);
    std::strcat(new_text, other.text);
    String new_string(new_text);
    delete[] new_text;
    return new_string;
}

 char String::operator[](int index) const{
    if (index >= 0 && index < static_cast<int>(this->size)) {
        return this->text[index];
    }
    return '\0';
}

 bool String::operator==(const String &other) const{
    return std::strcmp(this->text, other.text) == 0;
}

 std::istream &operator>>(std::istream &in, String &string) {
    char input[MAX_BUFFER];
    in.getline(input, MAX_BUFFER - 1);
    string = input;
    return in;
}

 std::ostream &operator<<(std::ostream &out,const String &string) {
    out << string.getText();
    return out;
}

 bool String::contains(const String &other) const {
    if (other.size > this->size)
        return false;
    if (this->text != nullptr & other.text != nullptr) {
        for (int i = 0; i < this->size; ++i) {
            int j = 0;
            if (this->text[i] == other.text[j]) {
                int k = i;
                while (this->text[i] == other.text[j] && j < other.size) {
                    j++;
                    i++;
                }
                if (j == other.size) {
                    return true;
                } else {
                    i = k;
                }
            }
        }
    }
    return false;
}

 String String::strip(const String &other) const {
    if (!this->text || !other.text)
        return *this;
    if (other.size == 0)
        return *this;
    if (this->size < other.size)
        return *this;
    if (!this->contains(other))
        return *this;

    unsigned int newStrLength = this->size;
    char *helperStr = new char[newStrLength + 1];
    int index = 0;

    for (int i = 0; i < this->size;) {
        int j = 0;
        if (i <= this->size - other.size && std::strncmp(this->text + i, other.text, other.size) == 0) {
            i += other.size;
        } else {
            helperStr[index++] = this->text[i++];
        }
    }
    helperStr[index] = '\0';
    String newString(helperStr);
    delete[] helperStr;
    return newString;
}

 bool String::isNumber() {
    for (int i = 0; i < this->size; ++i) {
        char c = this->text[i];
        if (c >= '0' && c <= '9')
            return true;
    }
    return false;
}

//void String::print() const {
//    if (this->text){
//        std::cout << this->text << std::endl;
//    }else{
//        std::cout << "Empty string" << std::endl;
//    }
//}
