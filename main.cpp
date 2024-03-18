#include <iostream>
#include "String/String.cpp"

int main() {
    String str = "kur";
    std::cout << str << std::endl;
    std::cout << str.getSize() << std::endl;
    String str2 = "kur";
    std::cout << (str != str2) << std::endl;
}
