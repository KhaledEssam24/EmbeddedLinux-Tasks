#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
// 2- create a function to search to the number in the array which number is taken
// from user
template <typename T>
bool search_number(const std::vector<T>& vec, T number) {
    return std::find(vec.begin(), vec.end(), number) != vec.end();
}

int main(){
    float input;
    std::cout<<"Enter the number : ";
    std::cin >> input;

    std::cout << std::boolalpha <<search_number({1,2,3,4,5.5f,9},input) << std::endl;
    return 0;
}
