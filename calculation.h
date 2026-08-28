#pragma once

#include <iostream>
#include <cmath>

void addi(){
    std::cout << "Addition" << std::endl
              << "Enter 2 numbers\n";
    double num1, num2;
    num1 = validateInput();
    num2 = validateInput();
    std::cout << "= " << num1 + num2 << std::endl;
    
}

void subt()
{
    std::cout << "Subtraction" << std::endl;
    std::cout << "Enter 2 numbers\n";
    double num1, num2;
    num1 = validateInput();
    num2 = validateInput();
    std::cout << "= " << num1 - num2 << std::endl;
    
}

void multi()
{
    std::cout << "Multiplication" << std::endl
              << "Enter 2 numbers\n";
    double num1, num2;
    num1 = validateInput();
    num2 = validateInput();
    std::cout << "= " << num1 * num2 << std::endl;
    
}

void divi()
{
    std::cout << "Division" << std::endl
              << "Enter 2 numbers\n";
    double num1, num2;
    num1 = validateInput();
    num2 = validateInput();
    if (num2 == 0)
    {
        std::cout << "You cannot divide by 0" << std::endl;
    }
    else
    {

        std::cout << "= " << num1 / num2 << std::endl;
    }
   
}

void exponential()
{
    std::cout << "Exponential" << std::endl;
    double num1, num2;
    std::cout << "Enter your base" << std::endl;
    num1 = validateInput();
    std::cout << "Enter your exponent" << std::endl;
    num2 = validateInput();
    std::cout << "= " << pow(num1, num2)
              << "\n";
   
}

void squareRoot()
{
    std::cout << "Square Root" << std::endl;
    double num;
    std::cout << "Enter a number" << std::endl;
    num = validateInput();
    if (num < 0)
    {
        std::cout << "Invalid input for square root" << std::endl;
    }
    else
    {
        std::cout << "= " << sqrt(num) << std::endl;
    }
    
}

void logarithm()
{
    bool valid = false;
    while (!valid)
    {
        std::cout << "Logarithm" << std::endl;
        double num1, num2;
        std::cout << "Enter your base" << std::endl;
        num1 = validateInput();
        std::cout << "Enter your number" << std::endl;
        num2 = validateInput();
        if (num2 <= 0 || num1 <= 0 || num1 == 1)
        {
            std::cout << "Invalid input for logarithm" << std::endl;
        }
        else
        {
            valid = true;
            std::cout << "= " << log(num2) / log(num1) << std::endl;
        }
    }
    
}