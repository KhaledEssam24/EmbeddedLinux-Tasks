#include <iostream>
#include <algorithm>
#include <vector>
// 1- create a function to ﬁnd the maximum number of array

template<typename T> 
T max(const std::vector<T> &vec)
{
    if(!vec.empty()) return *std::max_element(vec.begin(),vec.end());
    else return 0;
}

int main(){
    std::cout << "max = " << max<float>({1,-5,8,9.5}) << std::endl;
    std::cout << "max = " << max<int>({1,-5,14,8,9}) << std::endl;
    std::cout << "max = " << max<int>({}) << std::endl;
    return 0;
}
