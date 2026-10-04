#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "input.h"
#include "calculation.h"
#include "arithmeticOperations.h"
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
                  << "1(Arithmetic operations)  "
                  << "2(Modulo)" << std::endl
                  << "3(Exponential)            "
                  << "4(Square Root)  " << std::endl
                  << "5(Logarithm)       " << std::endl;

        int x = validateInput();
        switch (x)
        {
        case 1:
        {
            arithmeticOperations();
            break;
        }
        case 2:
        {
            modulo();
            break;
        }
        case 3:
        {
            exponential();
            break;
        }
        case 4:
        {
            squareRoot();
            break;
        }
        case 5:
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