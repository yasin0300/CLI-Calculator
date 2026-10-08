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

    for (char zahl : input)
    {
        if (isdigit(zahl))
        {
            currentNumber += zahl;
        }
        else if (zahl == '+' || zahl == '-' || zahl == '*' || zahl == '/')
        {
            digits.push_back(stod(currentNumber));
            currentNumber.clear();

            operators.push_back(zahl);
        }
    }
    if (!currentNumber.empty())
    {

        digits.push_back(stod(currentNumber));
    }
    double result;
    std::cout << std::endl;
    for (double d : digits)
    {
        std::cout << d << " ";
    }
    std::cout << "" << std::endl;
    for (char o : operators)
    {
        std::cout << o;
    }
    std::cout << std::endl;
    std::cout << result;
    std::cout << std::endl;
}