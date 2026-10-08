#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        if (isdigit(dig) || dig == '.')
        {
            currentNumber += dig;
        }
        else if (dig == '+' || dig == '-' || dig == '*' || dig == '/')
        {
            digits.push_back(stod(currentNumber));
            currentNumber.clear();

            operators.push_back(dig);
        }
    }
    if (!currentNumber.empty())
    {

        digits.push_back(stod(currentNumber));
    }

    if (operators.empty())
    {
        std::cout << "Please enter a operator\n";
    }
    else
    {
        double result;

        for (double dig : digits)
        {
            int i = 0;
            if (operators[i] == '+')
            {
                result = result + dig;
            }
            else if (operators[i] == '-')
            {
                result = result - dig;
            }
            else if (operators[i] == '*')
            {
                result = result * dig;
            }
            else if (operators[i] == '/')
            {
                result = result / dig;
            }
            i++;
        }

        std::cout << std::endl;
        std::cout << "=" << result << std::endl;
    }
}