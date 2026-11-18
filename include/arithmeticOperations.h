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
    std::cout << "Arithmetic operations" << std::endl;
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

    double result = 0;

    for (int i = 0; i < operators.size();)
    {
        if (operators[i] == '*')
        {
            digits[i] = digits[i] * digits[i + 1];
            digits.erase(digits.begin() + i + 1);
            operators.erase(operators.begin() + i);
        }
        else if (operators[i] == '/')
        {
            if(digits[i+1] == 0){
                std::cout << "You cant divide by 0" << std::endl;
                return;
            }
            digits[i] = digits[i] / digits[i + 1];
            digits.erase(digits.begin() + i + 1);
            operators.erase(operators.begin() + i);
        }
        else{
            i++;
        }
    }

    while (!operators.empty())
    {

        if (operators[0] == '+')
        {
            digits[0] = digits[0] + digits[1];
            digits.erase(digits.begin() + 1);
            operators.erase(operators.begin());
        }
        else if (operators[0] == '-')
        {
            digits[0] = digits[0] - digits[1];
            digits.erase(digits.begin() + 1);
            operators.erase(operators.begin());
        }
    }
    result = digits[0];
    ans = result;
    std::cout << "=" << result << std::endl;
}