#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>

#include "global.h"

void arithmeticOperations()
{
    std::string input;
    std::cin.ignore();
    std::getline(std::cin, input);

    std::string currentNumber;
    std::vector<double> digits;
    std::vector<char> operators;

    for (char dig : input)
    {
        if (isdigit(dig))
        {
            currentNumber += dig;
        }
        else if (dig == '.')
        {
            if (std::ranges::find(currentNumber, '.') != currentNumber.end())
            {
                std::cout << "Syntax Error" << std::endl;
                return;
            }

            currentNumber += dig;
        }
        else if (dig == '+' || dig == '-' || dig == '*' || dig == '/')
        {
            if (currentNumber.empty())
            {
                std::cout << "Syntax Error" << std::endl;
                return;
            }

            digits.push_back(std::stod(currentNumber));
            currentNumber.clear();

            operators.push_back(dig);
        }
        else
        {
            std::cout << "Syntax Error" << std::endl;
            return;
        }
    }

    if (!currentNumber.empty())
    {
        digits.push_back(std::stod(currentNumber));
    }

    if (operators.empty())
    {
        std::cout << "Please enter an operator\n";
        return;
    }

    double result = digits[0];

    for (int i = 0; i < operators.size(); i++)
    {
        if (operators[i] == '+')
        {
            result += digits[i + 1];
        }
        else if (operators[i] == '-')
        {
            result -= digits[i + 1];
        }
        else if (operators[i] == '*')
        {
            result *= digits[i + 1];
        }
        else if (operators[i] == '/')
        {
            if (digits[i + 1] == 0)
            {
                std::cout << "Math Error" << std::endl;
                return;
            }

            result /= digits[i + 1];
        }
    }

    std::cout << "=" << result << std::endl;
}