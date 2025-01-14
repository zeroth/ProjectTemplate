#include "mylib/mylib.hpp"
#include <stdexcept>

namespace mylib {

Calculator::Calculator() = default;
Calculator::~Calculator() = default;

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

} // namespace mylib 