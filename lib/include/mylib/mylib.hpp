#pragma once

#include "mylib_export.hpp"

namespace mylib {

class MYLIB_EXPORT Calculator {
public:
    Calculator();
    ~Calculator();

    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};

} // namespace mylib 