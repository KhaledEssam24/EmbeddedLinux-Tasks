#include <list>
#include <iostream>

void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main(){
    std::list lst1 = {11,55,6,7,20,0};
    // empty        checks whether the container is empty
    std::cout<<"Is empty = "<< std::boolalpha << lst1.empty() <<std::endl; //false
    // size         returns the number of elements
    std::cout<<"Size = " << lst1.size() <<std::endl; // 6
    // max_size     returns the maximum possible number of elements
    std::cout<<"MaxSize = " << lst1.max_size() <<std::endl;// 384307168202282325
    // insert       inserts elements
    // emplace      constructs element in-place
    //!Note
    /*lst1.insert(lst1.begin() +2 ,44); 
    the std::list in C++ does not support random access using the + operator with its iterators. 
    This is because std::list is a doubly linked list, 
    and its iterators do not allow direct arithmetic operations like those of random-access containers 
    (e.g., std::vector or std::array). To achieve the desired insertion at specific positions,
    you must use the std::advance function to move the iterator to the correct position.*/
    auto it = lst1.begin();
    std::advance(it,2);
    lst1.insert(it ,48);
    std::advance(it,1);//! attention
    lst1.emplace(it ,50);
    print(lst1);
    // erase        erases elements
    lst1.erase(lst1.begin());
    // push_back    adds an element to the end
    // emplace_back constructs an element in-place at the end
    lst1.push_back(80);
    lst1.emplace_back(88);
    print(lst1);
    // push_front   inserts an element to the beginning
    // emplace_front constructs an element in-place at the beginning
    lst1.push_front(-1);
    lst1.emplace_front(-8);
    print(lst1);
    // pop_front    removes the first element
    // pop_back     removes the last element
    lst1.pop_front();
    lst1.pop_back();
    print(lst1);
    std::cout<<"Size = " << lst1.size() <<std::endl; // 6
    // resize       changes the number of elements stored
    lst1.resize(lst1.size()-2);
    lst1.resize(lst1.size()+2);
    print(lst1);
    // clear        clears the contents
    lst1.clear();
    std::cout<<"Size = " << lst1.size() <<std::endl; // 6
    return 0;
}