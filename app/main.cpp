#include <iostream>
#include <string>

#include "calculator.cpp"
#include "printer.cpp"

int main(){
    std::cout << print("Hello World\n");
    std::cout << std::to_string(mathPlus(10,7));
    return 0;
}