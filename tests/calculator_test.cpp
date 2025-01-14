#include <gtest/gtest.h>
#include <mylib/mylib.hpp>

class CalculatorTest : public ::testing::Test {
protected:
    mylib::Calculator calc;
};

TEST_F(CalculatorTest, Addition) {
    EXPECT_DOUBLE_EQ(calc.add(2.0, 3.0), 5.0);
    EXPECT_DOUBLE_EQ(calc.add(-2.0, 3.0), 1.0);
}

TEST_F(CalculatorTest, Subtraction) {
    EXPECT_DOUBLE_EQ(calc.subtract(5.0, 3.0), 2.0);
    EXPECT_DOUBLE_EQ(calc.subtract(2.0, 3.0), -1.0);
}

TEST_F(CalculatorTest, Multiplication) {
    EXPECT_DOUBLE_EQ(calc.multiply(2.0, 3.0), 6.0);
    EXPECT_DOUBLE_EQ(calc.multiply(-2.0, 3.0), -6.0);
}

TEST_F(CalculatorTest, Division) {
    EXPECT_DOUBLE_EQ(calc.divide(6.0, 2.0), 3.0);
    EXPECT_DOUBLE_EQ(calc.divide(-6.0, 2.0), -3.0);
    EXPECT_THROW(calc.divide(1.0, 0.0), std::invalid_argument);
} 