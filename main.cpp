#include <iostream>
#include "String/String.cpp"

int main() {
    String str = "maika";
    std::cout << str << std::endl;
    std::cout << str.getLenght() << std::endl;
    String str2 = "kurr";
    std::cout << (str != str2) << std::endl;
    std::cout << str2.contains(str) << std::endl;
}
