#include <iostream>
#include <algorithm>

int main(){

    int num1=0,num2=0,num3=0;
    
    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;
    std::cout << "Enter num3: ";
    std::cin >> num3; 
    
    std::cout<<"max number is "<< std::max({num1,num2,num3}) <<std::endl;
    return 0;
}