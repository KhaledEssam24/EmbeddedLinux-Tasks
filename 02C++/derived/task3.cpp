#include <iostream>
#include <algorithm>
#include <vector>

// 3- delete number in array
template<typename T>
typename std::vector<T>::iterator search_number(std::vector<T>& vec, T number) {
    return std::find(vec.begin(), vec.end(), number);
}

template<typename T>
void erase_number(std::vector<T>& vec, T number) {
    typename std::vector<T>::iterator it = search_number<T>(vec, number);
    if (it != vec.end()) {
        vec.erase(it);
    }
}

int main(){
    int input;
    std::cout<<"Enter the number : ";
    std::cin >> input;

    std::vector <int>vec{1,2,3,4};

    erase_number<int>(vec,input);
    for (int i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl;
    return 0;
}
