#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{
    std::string binary_string;
    int deciaml;
    int choice;

    std::cout << "Enter 1 for binary to decimal or Enter 2 for decimal or binary : ";
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << "Enter a binary number: ";
        std::cin >> binary_string;

        std::bitset<8> binary(binary_string);

        std::cout << "The decimal value is : "<< binary.to_ulong() << std::endl;
    }
    else if (choice == 2)
    {
        std::cout << "Enter a decimal number: ";
        std::cin >> deciaml;

        std::bitset<8> binaryNumber(deciaml);

        std::cout << "The binary value is : "<< binaryNumber << std::endl;
    }
    else
    {
        std::cout << "Enter Valid Choice " << std::endl;
    }
    return 0;
}