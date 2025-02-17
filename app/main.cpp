#include <iostream>
#include <string>

#include "calculator.cpp"
#include "printer.cpp"
#include "settings.h"

int main(){
    std::cout << print("Hello World\n");
    std::cout << std::to_string(mathPlus(10,7)) << "\n";
    std::cout << getProjectName() << "\n";
    std::cout << getProjectVersion() << "\n";

    return 0;
}