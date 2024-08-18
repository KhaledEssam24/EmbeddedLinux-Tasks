
#include <iostream>
#include <vector>
#include <string>

class backtrace
{
private:
public:
    static std::vector<std::string> vec;
    backtrace(std::string func);
    ~backtrace();
};


#define EnterFn std::cout << "Enter to  [" << __FUNCTION__ << ']'  << std::endl;backtrace bc(__FUNCTION__);
#define EXITFn  std::cout <<  "Exit from [" << __FUNCTION__ << ']' << std::endl;
#define BT      std::cout << "Backtrace as follow : "<<std::endl;for(std::string i: backtrace::vec)std::cout<<i<<std::endl;
