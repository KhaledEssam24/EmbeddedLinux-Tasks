#include "backtrace.hpp"

backtrace::backtrace(std::string func)
{
    vec.push_back(func);
}

backtrace::~backtrace()
{
    vec.pop_back();
}

std::vector<std::string> backtrace::vec;

void func1();
void func2();
void func3();

void func1(){
    EnterFn
    func2();
    EXITFn
}
void func2(){
    EnterFn
    func3();
    EXITFn
}
void func3(){
    EnterFn
    BT
    EXITFn
}


int main(){
    EnterFn
    func1();
    EXITFn
}
