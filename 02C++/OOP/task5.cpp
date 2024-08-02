#include <iostream>
#include <vector>
#include <numeric>

int main(){
    const int start = 1;
    const int end = 10;
    const int size = end - start + 1;

    std::vector<int> vec(size);
    std::iota(vec.begin(),vec.end(),start);
    int sum = std::accumulate(vec.begin(),vec.end(),0);

    std::cout << "sum = " << sum << std::endl;
    return 0;
}
