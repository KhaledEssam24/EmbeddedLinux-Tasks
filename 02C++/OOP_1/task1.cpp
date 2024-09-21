#include <csignal>
#include <iostream>
#include <unistd.h>


void interrupt_handler(int signum) {
    std::cout<<"Thanx Bye!"<<std::endl;;
    exit(1);
}

int main() {
    signal(SIGINT,interrupt_handler);
    //program's main loop goes here
    while (1)
    {
        std::cout<<"main loop"<<std::endl;
        sleep(1);
    }
    
    return 0;
}
