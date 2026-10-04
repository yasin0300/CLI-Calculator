#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "global.h"

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

            ans = result;
            std::cout << "= " << result << '\n';
            return;
        }
    }
}