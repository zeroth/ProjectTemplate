#include <mylib/mylib.hpp>
#include <iostream>

int main() {
    mylib::Calculator calc;
    
    double a = 10.0;
    double b = 5.0;
    
    std::cout << "Calculator Demo\n";
    std::cout << "---------------\n";
    std::cout << a << " + " << b << " = " << calc.add(a, b) << "\n";
    std::cout << a << " - " << b << " = " << calc.subtract(a, b) << "\n";
    std::cout << a << " * " << b << " = " << calc.multiply(a, b) << "\n";
    std::cout << a << " / " << b << " = " << calc.divide(a, b) << "\n";

    return 0;
} 