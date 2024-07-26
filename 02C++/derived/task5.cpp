#include <iostream>
#include <algorithm>
#include <vector>

// 5-ﬁnd the even and odd numbers in the array

int main(){
    std::vector<int> vec{2,4,1,5,8,7,9};
    auto isEvenOdd = [](int i) {
                        if (i % 2 == 0)
                            std::cout << i << " is even" << std::endl;
                        else
                            std::cout << i << " is odd" << std::endl;
                    };

    for (int i : vec)
    {
        isEvenOdd(i);
    }
    
    return 0;
}