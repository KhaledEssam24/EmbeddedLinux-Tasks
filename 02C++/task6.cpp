#include <iostream>
#include <string>

int sumOfDigits(const std::string& numStr) {
    int sum = 0;
    for (char digit : numStr) {
        if (isdigit(digit)) {
            sum += digit - '0'; 
        }
    }
    return sum;
}

int main() {
    std::string number;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    int result = sumOfDigits(number);

    std::cout << "The sum of the digits is: " << result << std::endl;

    return 0;
}
