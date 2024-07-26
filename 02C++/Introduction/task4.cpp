#include <iostream>

int main() {
    char letter;
    std::cout << "Enter the letter : "; 
    std::cin >> letter;

    for (char i : "aeiouAEIOU")
    {
        if(i==letter) 
        {
            std::cout << "the letter is Vowel" << std::endl;
            return 0;
        }
    }

    std::cout << "the letter is not Vowel" << std::endl;
    return 0;

}