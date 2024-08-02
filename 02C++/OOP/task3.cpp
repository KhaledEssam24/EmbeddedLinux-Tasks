#include <iostream>
#include <vector>
#include <numeric>

int main(){
    const int start = 10;
    const int end = 10000;
    const int size = end - start + 1;

    std::vector<int> vec(size);
    std::iota(vec.begin(),vec.end(),start);
    
    for (int i : vec)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
