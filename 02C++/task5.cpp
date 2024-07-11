#include <iostream>
#include <iomanip>

int main() {

    for (int i = 1; i <= 10; i++)
    {   
        for (int j = 1; j <= 10; j++)
        {
            std::cout 
            << std::setw(3) << std::setfill(' ') << i << ' ' << '*' <<  ' ' 
            << std::setw(3) << std::setfill(' ') << j << ' ' << '=' << ' ' 
            << std::setw(3) << std::setfill(' ') << i*j << std::endl;
        }
        std::cout << "*************" << std::endl;
    }
    return 0;
}