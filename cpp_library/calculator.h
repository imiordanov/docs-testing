/**
 * @file calculator.h
 * @brief A comprehensive calculator library for basic arithmetic operations
 * @author Your Name
 * @version 1.0.0
 * @date 2025-09-10
 * 
 * This file contains the Calculator class and related utility functions
 * for performing basic mathematical operations with error handling.
 * 
 * @example
 * ```cpp
 * Calculator calc(10.0);
 * calc.add(5.0).multiply(2.0);
 * std::cout << calc.getValue() << std::endl; // Outputs: 30.0
 * ```
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <string>

/**
 * @namespace MathUtils
 * @brief Utility functions for mathematical operations
 * 
 * This namespace contains standalone utility functions that can be used
 * independently of the Calculator class for basic arithmetic operations.
 */
namespace MathUtils {
    /**
     * @brief Adds two numbers together
     * @param a First operand
     * @param b Second operand
     * @return Sum of a and b
     * 
     * @example
     * ```cpp
     * double result = MathUtils::add(3.5, 2.1); // result = 5.6
     * ```
     */
    double add(double a, double b);

    /**
     * @brief Subtracts second number from first number
     * @param a Minuend (number to subtract from)
     * @param b Subtrahend (number to subtract)
     * @return Difference of a and b
     * 
     * @example
     * ```cpp
     * double result = MathUtils::subtract(10.0, 3.0); // result = 7.0
     * ```
     */
    double subtract(double a, double b);

    /**
     * @brief Multiplies two numbers
     * @param a First factor
     * @param b Second factor
     * @return Product of a and b
     * 
     * @example
     * ```cpp
     * double result = MathUtils::multiply(4.0, 2.5); // result = 10.0
     * ```
     */
    double multiply(double a, double b);

    /**
     * @brief Divides first number by second number
     * @param a Dividend (number to be divided)
     * @param b Divisor (number to divide by)
     * @return Quotient of a divided by b
     * @throws std::invalid_argument if divisor is zero
     * 
     * @example
     * ```cpp
     * double result = MathUtils::divide(15.0, 3.0); // result = 5.0
     * ```
     * 
     * @warning Division by zero will throw an exception
     */
    double divide(double a, double b);
}

/**
 * @class Calculator
 * @brief A chainable calculator class for performing arithmetic operations
 * 
 * The Calculator class maintains an internal state and allows chaining
 * of arithmetic operations. It provides a fluent interface for complex
 * calculations while maintaining precision and error handling.
 * 
 * @example Basic usage:
 * ```cpp
 * Calculator calc;
 * calc.setValue(10).add(5).multiply(2).subtract(3);
 * std::cout << calc.getValue() << std::endl; // Outputs: 27
 * ```
 * 
 * @example Error handling:
 * ```cpp
 * Calculator calc(10);
 * try {
 *     calc.divide(0); // Will throw exception
 * } catch (const std::invalid_argument& e) {
 *     std::cout << "Error: " << e.what() << std::endl;
 * }
 * ```
 */
class Calculator {
private:
    double value_; ///< Current value stored in the calculator

public:
    /**
     * @brief Default constructor initializing calculator to zero
     * 
     * Creates a new Calculator instance with an initial value of 0.0.
     * 
     * @example
     * ```cpp
     * Calculator calc; // value = 0.0
     * ```
     */
    Calculator();

    /**
     * @brief Constructor with initial value
     * @param initial_value Starting value for the calculator
     * 
     * Creates a new Calculator instance with the specified initial value.
     * 
     * @example
     * ```cpp
     * Calculator calc(42.5); // value = 42.5
     * ```
     */
    explicit Calculator(double initial_value);

    /**
     * @brief Copy constructor
     * @param other Calculator instance to copy from
     * 
     * Creates a new Calculator instance as a copy of another calculator.
     */
    Calculator(const Calculator& other);

    /**
     * @brief Assignment operator
     * @param other Calculator instance to assign from
     * @return Reference to this calculator
     * 
     * Assigns the value from another calculator to this instance.
     */
    Calculator& operator=(const Calculator& other);

    /**
     * @brief Destructor
     * 
     * Cleans up calculator resources (default destructor).
     */
    ~Calculator() = default;

    /**
     * @brief Gets the current value
     * @return Current calculator value
     * 
     * @example
     * ```cpp
     * Calculator calc(15.5);
     * double current = calc.getValue(); // current = 15.5
     * ```
     */
    double getValue() const;

    /**
     * @brief Sets the calculator value
     * @param value New value to set
     * @return Reference to this calculator for chaining
     * 
     * @example
     * ```cpp
     * Calculator calc;
     * calc.setValue(100.0).add(50.0); // Sets to 100, then adds 50
     * ```
     */
    Calculator& setValue(double value);

    /**
     * @brief Adds a value to the current result
     * @param value Value to add
     * @return Reference to this calculator for chaining
     * 
     * @example
     * ```cpp
     * Calculator calc(10);
     * calc.add(5.5); // Result: 15.5
     * ```
     */
    Calculator& add(double value);

    /**
     * @brief Subtracts a value from the current result
     * @param value Value to subtract
     * @return Reference to this calculator for chaining
     * 
     * @example
     * ```cpp
     * Calculator calc(20);
     * calc.subtract(7.3); // Result: 12.7
     * ```
     */
    Calculator& subtract(double value);

    /**
     * @brief Multiplies the current result by a value
     * @param value Value to multiply by
     * @return Reference to this calculator for chaining
     * 
     * @example
     * ```cpp
     * Calculator calc(6);
     * calc.multiply(1.5); // Result: 9.0
     * ```
     */
    Calculator& multiply(double value);

    /**
     * @brief Divides the current result by a value
     * @param value Value to divide by
     * @return Reference to this calculator for chaining
     * @throws std::invalid_argument if value is zero
     * 
     * @example
     * ```cpp
     * Calculator calc(15);
     * calc.divide(3.0); // Result: 5.0
     * ```
     * 
     * @warning Division by zero throws an exception
     */
    Calculator& divide(double value);

    /**
     * @brief Resets the calculator to zero
     * @return Reference to this calculator for chaining
     * 
     * @example
     * ```cpp
     * Calculator calc(42);
     * calc.reset(); // Result: 0.0
     * ```
     */
    Calculator& reset();

    /**
     * @brief Converts calculator value to string
     * @param precision Number of decimal places (default: 2)
     * @return String representation of the current value
     * 
     * @example
     * ```cpp
     * Calculator calc(3.14159);
     * std::string result = calc.toString(3); // "3.142"
     * ```
     */
    std::string toString(int precision = 2) const;

    /**
     * @brief Equality comparison operator
     * @param other Calculator to compare with
     * @return True if values are equal (within epsilon tolerance)
     * 
     * Uses a small epsilon value for floating-point comparison.
     */
    bool operator==(const Calculator& other) const;

    /**
     * @brief Inequality comparison operator
     * @param other Calculator to compare with
     * @return True if values are not equal
     */
    bool operator!=(const Calculator& other) const;
};

#endif // CALCULATOR_H