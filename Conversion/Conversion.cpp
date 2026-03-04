#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#include "Methods.h"

int main()
{
    std::string option;
    while (true)
    {
        std::cout << "Please specify the number system of the input number.\n   1) Base 10 (Decimal)\n   2) Base 16 (Hexadecimal)\n   3) QUIT\n";
        std::cin >> option;
        if (option == "1")
        {
            int number;
            std::cout << "Please enter the number in DECIMAL: ";
            std::cin >> number;

            std::string b = trimLeadingZeros(decToBinary(number));;
            std::string hex = trimLeadingZeros(binaryTohexadecimal(b));

            if (b == "")
            {
                b = "0";
            }

            std::cout << "The number you entered is " << b << " in binary and " << hex << " in hexadecimal.\n\n";
        }
        else if (option == "2")
        {
            std::string number;
            std::cout << "Please enter the number in HEXADECIMAL: ";
            std::cin >> number;

            std::string b = trimLeadingZeros(hexToBinary(number));
            int d = binaryToDec(b);

            if (b == "")
            {
                b = "0";
            }

            std::cout << "The number you entered is " << b << " in binary and " << d << " in decimal.\n\n";
        }
        else if (option == "3")
        {
            break;
        }
        else std::cout << "Invalid option. Try again.\n";
    }
}