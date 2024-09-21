#include <stack>
#include <iostream>

int main(){
    std::stack<int> s;
    // push     inserts element at the top
    for(int i;i<10;i++) 
        s.push(i);
    
    for (auto i )
    {
        /* code */
    }
    
    // top      accesses the top element
    std::cout << "Top = " << s.top() << std::endl;
    // empty    checks whether the container adaptor is empty
    // size     returns the number of elements
    // emplace  constructs element in-place at the top
    // pop      removes the top element
    return 0;
}
