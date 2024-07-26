#include <iostream>
#include <iomanip>

int main() {
    // header
    std::cout << "---------------------------" << std::endl;
    std::cout << '|' << std::setw(8) << "Char" << std::setw(5) << '|' << std::setw(8) << "ASCII" << std::setw(5) << '|' << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (int i = 33; i < 127; i++) {
        std::cout << '|' << std::setw(8) << (char)i << std::setw(5) << '|' << std::setw(8) << i << std::setw(5) << '|' << std::endl;
    }

    // Footer
    std::cout << "---------------------------" << std::endl;

    return 0;
}
