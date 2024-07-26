#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {-5, 8, 9, 1, 5, 3};

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a < b;
    });
    
    std::cout<<"Ascending Order :";
    for (int i :vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    std::cout<<"Descending Order :";
    for (int i :vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    return 0;
}