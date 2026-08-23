#include <iostream>
#include <string>
#include <cmath>
#include "input.h"

int main()
{

    int running = 1;
    while (running == 1)
    {
        std::cout << "\n"
                  << "What kind of calculation would you like to perform??" << std::endl
                  << "\n"
                  << "1(Addition)  "
                  << "2(Subtraction)  "
                  << "3(Multiplication)  " << std::endl
                  << "4(Division)  "
                  << "5(Exponential)  "
                  << "6(Square Root)" << std::endl
                  << "7(Logarithm)" << std::endl;

        int x = validateInput();
        switch (x)
        {
        case 1:
        {
            std::cout << "Addition" << std::endl
                      << "Enter 2 numbers\n";
            double num1, num2;
            num1 = validateInput();
            num2 = validateInput();
            std::cout << "= " << num1 + num2 << std::endl;
            break;
        }
        case 2:
        {
            std::cout << "Subtraction" << std::endl;
            std::cout << "Enter 2 numbers\n";
            double num1, num2;
            num1 = validateInput();
            num2 = validateInput();
            std::cout << "= " << num1 - num2 << std::endl;
            break;
        }
        case 3:
        {
            std::cout << "Multiplication" << std::endl
                      << "Enter 2 numbers\n";
            double num1, num2;
            num1 = validateInput();
            num2 = validateInput();
            std::cout << "= " << num1 * num2 << std::endl;
            break;
        }
        case 4:
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
            break;
        }
        case 5:
        {
            std::cout << "Exponential" << std::endl;
            double num1, num2;
            std::cout << "Enter your base" << std::endl;
            num1 = validateInput();
            std::cout << "Enter your exponent" << std::endl;
            num2 = validateInput();
            std::cout << "= " << pow(num1, num2)
                      << "\n";
            break;
        }
        case 6:
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
            break;
        }
        case 7:
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
            break;
        }
        default:
            std::cout << "Invalid input" << std::endl;
            break;
        }
        std::cout << "Continue(1) exit(0)" << std::endl;
        running = validateInput();
    }
    return 0;
}