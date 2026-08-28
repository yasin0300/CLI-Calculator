#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <numbers>

double validateInput()
{
    std::string input;

    while (true)
    {
        std::cin >> input;

        if (input == "e" || input == "E")
        {
            return std::numbers::e;
        }
        else if(input == "pi" || input == "Pi" || input == "PI"){
            return std::numbers::pi;
        }
        try
        {
            return std::stod(input);
        }
        catch (...)
        {
            std::cout << "Invalid input!" << std::endl
                      << "Please enter a valid number: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}