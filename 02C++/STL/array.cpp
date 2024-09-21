#include <array>
#include <iostream>

int main(){
    std::array<int,5> arr = {10,20,40,30,15};
    std::array<int,5> carr = {10,20,40,30,25};
    bool op =  arr==carr;
    std::cout<< std::boolalpha << op <<std::endl;

    std::cout<<*(arr.begin())<<std::endl;
    std::cout<<*(arr.rbegin())<<std::endl;
    std::cout<<*(arr.end())<<std::endl;
    std::cout<<*(arr.rend())<<std::endl;
    std::cout<<arr.front()<<std::endl;
    std::cout<<arr.back()<<std::endl;
    
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout<<arr.at(i)<<std::endl;
    }

    std::cout<<arr.data()<<std::endl;
    std::cout<<&arr<<std::endl;
    for (auto i : arr)
    {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
    return 0;
}