/**
 * @file calculator.cpp
 * @brief Implementation of the Calculator class and MathUtils functions
 * @author Your Name
 * @version 1.0.0
 * @date 2025-09-10
 */

#include "calculator.h"
#include <sstream>
#include <iomanip>
#include <cmath>

namespace MathUtils {
    
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (std::abs(b) < 1e-10) {
            throw std::invalid_argument("Division by zero is not allowed");
        }
        return a / b;
    }
}

// Calculator class implementation

Calculator::Calculator() : value_(0.0) {
}

Calculator::Calculator(double initial_value) : value_(initial_value) {
}

Calculator::Calculator(const Calculator& other) : value_(other.value_) {
}

Calculator& Calculator::operator=(const Calculator& other) {
    if (this != &other) {
        value_ = other.value_;
    }
    return *this;
}

double Calculator::getValue() const {
    return value_;
}

Calculator& Calculator::setValue(double value) {
    value_ = value;
    return *this;
}

Calculator& Calculator::add(double value) {
    value_ = MathUtils::add(value_, value);
    return *this;
}

Calculator& Calculator::subtract(double value) {
    value_ = MathUtils::subtract(value_, value);
    return *this;
}

Calculator& Calculator::multiply(double value) {
    value_ = MathUtils::multiply(value_, value);
    return *this;
}

Calculator& Calculator::divide(double value) {
    value_ = MathUtils::divide(value_, value);
    return *this;
}

Calculator& Calculator::reset() {
    value_ = 0.0;
    return *this;
}

std::string Calculator::toString(int precision) const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value_;
    return oss.str();
}

bool Calculator::operator==(const Calculator& other) const {
    const double epsilon = 1e-9;
    return std::abs(value_ - other.value_) < epsilon;
}

bool Calculator::operator!=(const Calculator& other) const {
    return !(*this == other);
}

/**
 * @example calculator_example.cpp
 * Here's a comprehensive example of how to use the Calculator class:
 * 
 * ```cpp
 * #include "calculator.h"
 * #include <iostream>
 * 
 * int main() {
 *     // Create calculator with initial value
 *     Calculator calc(10.0);
 *     
 *     // Chain operations
 *     calc.add(5.0).multiply(2.0).subtract(3.0);
 *     std::cout << "Result: " << calc.getValue() << std::endl; // 27.0
 *     
 *     // Use utility functions
 *     double sum = MathUtils::add(15.5, 7.2);
 *     std::cout << "Sum: " << sum << std::endl; // 22.7
 *     
 *     // Error handling
 *     try {
 *         calc.divide(0.0);
 *     } catch (const std::invalid_argument& e) {
 *         std::cout << "Error: " << e.what() << std::endl;
 *     }
 *     
 *     // String conversion
 *     Calculator precise_calc(3.14159265);
 *     std::cout << "Pi (2 decimals): " << precise_calc.toString(2) << std::endl;
 *     std::cout << "Pi (5 decimals): " << precise_calc.toString(5) << std::endl;
 *     
 *     return 0;
 * }
 * ```
 */