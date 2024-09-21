#include <algorithm>
#include <iostream>
#include <ostream>

#include "INT.hpp"
#include "String.hpp"

std::ostream& operator<<(std::ostream& os ,INT& obj){
    os << obj.number;
    return os;
}

std::ostream& operator<<(std::ostream& os ,STRING& obj){
    os << obj.str << ' ' << obj.size;
    return os;
}

int main(){
    // INT x(8); //param constructor
    // INT y(7); //param constructor
    // y = std::move(x);
    // std::cout<<(x>y);
    STRING string1("Khaled",sizeof("Khaled"));
    STRING string2("Essam",sizeof("Essam"));
    STRING string3("Mohammed",sizeof("Mohammed"));
    STRING string4(string1);
    STRING string5(std::move(string2));
    string3 = std::move(string5); 

    // std::cout<< string1 << std::endl;
    // std::cout<< string2 << std::endl;
    // std::cout<< string3 << std::endl;
    // std::cout<< string4 << std::endl;
    // std::cout<< string5 << std::endl;
    
    return 0;
}
