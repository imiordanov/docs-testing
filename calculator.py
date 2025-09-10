"""
A simple calculator module for basic arithmetic operations.

This module provides functions for performing basic mathematical operations
like addition, subtraction, multiplication, and division.

Example:
    >>> from calculator import add, multiply
    >>> add(2, 3)
    5
    >>> multiply(4, 5)
    20
"""

__version__ = "1.0.0"
__author__ = "Your Name"


def add(a: float, b: float) -> float:
    """
    Add two numbers together.
    
    Args:
        a (float): The first number to add.
        b (float): The second number to add.
        
    Returns:
        float: The sum of a and b.
        
    Example:
        >>> add(2.5, 3.7)
        6.2
    """
    return a + b


def subtract(a: float, b: float) -> float:
    """
    Subtract the second number from the first.
    
    Args:
        a (float): The number to subtract from.
        b (float): The number to subtract.
        
    Returns:
        float: The difference of a and b.
        
    Example:
        >>> subtract(10, 3)
        7
    """
    return a - b


def multiply(a: float, b: float) -> float:
    """
    Multiply two numbers together.
    
    Args:
        a (float): The first number to multiply.
        b (float): The second number to multiply.
        
    Returns:
        float: The product of a and b.
        
    Example:
        >>> multiply(4, 2.5)
        10.0
    """
    return a * b


def divide(a: float, b: float) -> float:
    """
    Divide the first number by the second.
    
    Args:
        a (float): The dividend (number to be divided).
        b (float): The divisor (number to divide by).
        
    Returns:
        float: The quotient of a divided by b.
        
    Raises:
        ValueError: If b is zero (division by zero).
        
    Example:
        >>> divide(10, 2)
        5.0
        >>> divide(7, 3)
        2.3333333333333335
    """
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b


class Calculator:
    """
    A simple calculator class that maintains a running total.
    
    This class provides methods for chaining arithmetic operations
    while keeping track of the current value.
    
    Attributes:
        value (float): The current value of the calculator.
        
    Example:
        >>> calc = Calculator(10)
        >>> calc.add(5).multiply(2).value
        30.0
    """
    
    def __init__(self, initial_value: float = 0.0):
        """
        Initialize the calculator with an optional starting value.
        
        Args:
            initial_value (float, optional): The starting value. Defaults to 0.0.
        """
        self.value = initial_value
    
    def add(self, number: float) -> 'Calculator':
        """
        Add a number to the current value.
        
        Args:
            number (float): The number to add.
            
        Returns:
            Calculator: Returns self for method chaining.
        """
        self.value += number
        return self
    
    def subtract(self, number: float) -> 'Calculator':
        """
        Subtract a number from the current value.
        
        Args:
            number (float): The number to subtract.
            
        Returns:
            Calculator: Returns self for method chaining.
        """
        self.value -= number
        return self
    
    def multiply(self, number: float) -> 'Calculator':
        """
        Multiply the current value by a number.
        
        Args:
            number (float): The number to multiply by.
            
        Returns:
            Calculator: Returns self for method chaining.
        """
        self.value *= number
        return self
    
    def divide(self, number: float) -> 'Calculator':
        """
        Divide the current value by a number.
        
        Args:
            number (float): The number to divide by.
            
        Returns:
            Calculator: Returns self for method chaining.
            
        Raises:
            ValueError: If number is zero (division by zero).
        """
        if number == 0:
            raise ValueError("Cannot divide by zero")
        self.value /= number
        return self
    
    def reset(self) -> 'Calculator':
        """
        Reset the calculator value to zero.
        
        Returns:
            Calculator: Returns self for method chaining.
        """
        self.value = 0.0
        return self
    
    def __str__(self) -> str:
        """Return a string representation of the calculator's current value."""
        return f"Calculator(value={self.value})"
    
    def __repr__(self) -> str:
        """Return a detailed string representation of the calculator."""
        return f"Calculator(value={self.value})"


if __name__ == "__main__":
    # Example usage
    print("Function examples:")
    print(f"add(5, 3) = {add(5, 3)}")
    print(f"subtract(10, 4) = {subtract(10, 4)}")
    print(f"multiply(6, 7) = {multiply(6, 7)}")
    print(f"divide(15, 3) = {divide(15, 3)}")
    
    print("\nClass example:")
    calc = Calculator(10)
    result = calc.add(5).multiply(2).subtract(3)
    print(f"Calculator chain result: {result.value}")