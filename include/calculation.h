#pragma once

#include <iostream>
#include <cmath>
#include <vector>

#include "global.h"

void modulo()
{
    std::cout << "Modulo" << std::endl
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
        ans = fmod(num1, num2);
        std::cout << "= " << ans << std::endl;
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
    ans = pow(num1, num2);
    std::cout << "= " << ans << "\n";
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
        ans = sqrt(num);
        std::cout << "= " << ans << std::endl;
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
            ans = log(num2) / log(num1);
            std::cout << "= " << ans << std::endl;
        }
    }
}

void arithmeticOperations()
{
    std::cout << "ArithmeticOperations" << std::endl
              << "Enter expression e.g. 4+5/6" << std::endl;

    while (true)
    {
        std::vector<double> digits;
        std::vector<char> operators;
        std::string input;

        std::getline(std::cin, input);
        std::string currenetNumber;

        for (char character : input)
        {

            if (std::isdigit(character) || character == '.' || character == ',')
            {
                currenetNumber += character == ',' ? '.' : character;
            }
            else if (character == '+' || character == '-' || character == '*' || character == '/')
            {
                if (currenetNumber.empty())
                {
                    std::cout << "Invalid expression" << '\n';
                    break;
                }
                digits.push_back(std::stod(currenetNumber));
                currenetNumber.clear();
                operators.push_back(character);
            }
        }

        if (!currenetNumber.empty())
        {
            digits.push_back(std::stod(currenetNumber));
        }

        if (!digits.empty())
        {
            double result = digits[0];

            for (std::size_t i = 0; i < operators.size(); ++i)
            {
                if (operators[i] == '+')
                    result += digits[i + 1];
                else if (operators[i] == '-')
                    result -= digits[i + 1];
                else if (operators[i] == '*')
                    result *= digits[i + 1];
                else if (operators[i] == '/')
                {
                    if (digits[i + 1] == 0)
                    {
                        std::cout << "You cannot divide by 0" << '\n';
                        return;
                    }
                    result /= digits[i + 1];
                }
            }

            std::cout << "= " << result << '\n';
            return;
        }
    }
}
