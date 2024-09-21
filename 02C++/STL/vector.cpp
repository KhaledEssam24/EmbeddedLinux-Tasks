#include <vector>
#include <iostream>

int main(){
    std::vector vec ={10,20,15,5,50};
    std::vector cvec ={10,20,15,5,50};
    bool op =  vec==cvec;
    std::cout<< std::boolalpha << op <<std::endl;

    std::cout<<*(vec.begin())<<std::endl;
    std::cout<<*(vec.rbegin())<<std::endl;
    std::cout<<*(vec.end())<<std::endl;
    std::cout<<*(vec.rend())<<std::endl;
    std::cout<<vec.front()<<std::endl;
    std::cout<<vec.back()<<std::endl;

    std::cout<<vec.at(4)<<std::endl;

    std::cout<<*(vec.data()+5)<<std::endl;      //first element in vector
    std::cout<<*(vec.begin()+5)<<std::endl;    // it's not C it's instant that has members and virtual pointers 
    vec.resize(8,7); //10,20,15,5,50,7,7,7

    vec.push_back(10);  //10,20,15,5,50,7,7,7,10
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();
    vec.pop_back();             //10,20,15,5,50
    vec.emplace_back(55);       //10,20,15,5,50,55
    vec.emplace_back(44);       //10,20,15,5,50,55,44 
    vec.emplace_back(33);       //10,20,15,5,50,55,44,33
    vec.emplace(vec.end(),5);   //10,20,15,5,50,55,44,5
    vec.emplace(vec.begin(),5); //5,10,20,15,5,50,55,44,5
    for (int i : vec)
    {
        std::cout << i << ' ' ;
    }
    std::cout << std::endl; 
    return 0;
}