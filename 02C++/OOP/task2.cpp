#include <iostream>

/**
 * without static keyword segmentation faut occurs that makes sense as
 * there is no reference to local variable after calling function 
 * or to be more elaborative there is reference but garbage. 
 */ 

int& func(){
    static int var = 10;
    std::cout<<"local var = "<<var<<std::endl;
    return var;
}

int main(){

    func() = 15;
    func();
    return 0;
}
