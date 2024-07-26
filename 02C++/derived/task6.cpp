#include <iostream>
#include <algorithm>
#include <vector>

// 6-Write a lambda function to calculate the square of a given number.

int main(){
    auto square = [](auto i){
        return i*i;
    };
    
    int input;
    std::cout<<"Enter the number : ";
    std::cin >> input;
    std::cout<<"square of "<<input<<" is "<<square(input)<<std::endl;
    return 0;
}