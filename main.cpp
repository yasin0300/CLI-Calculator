#include <iostream>
#include <string>
#include <cmath>

#include "input.h"
#include "calculation.h"
#include "global.h"

double ans = 0.0;

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
            addi();
            break;
        }
        case 2:
        {
            subt();
            break;
        }
        case 3:
        {
            multi();
            break;
        }
        case 4:
        {
            divi();
            break;
        }
        case 5:
        {
            exponential();
            break;
        }
        case 6:
        {
            squareRoot();
            break;
        }
        case 7:
        {
            logarithm();
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