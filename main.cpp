#include "Shapes/Container.h"
#include "Helpers/String.h"

bool isCorrectNumberOfShapes(String number){
    //to do 
}

int main() {

    int number_of_shapes;
    std::cout << "Enter number of shapes: " << std::endl;
    std::cin >> number_of_shapes;
    std::cout << "Enter shape: ";
    std::cin >> std::ws;

    Container c;
    while (number_of_shapes > 0) {
        c.createFromConsole();//cant enter in line
        std::cout << "Enter shape: ";
        number_of_shapes--;
    }
    //c.print();

    return 0;
}
