#include <deque>
#include <iostream>

void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main(){
    std::deque<int> q;
    // assign           assigns values to the container
    q.assign({1,5,3,2});
    // at               access specified element with bounds checking
    // operator[]       access specified element
    for (int i = 0; i < q.size(); i++)
    {
        std::cout<<q[i]<<' '<<q.at(i)<<std::endl;
    }

    // front            access the first element
    // back             access the last element
    std::cout<<q.front()<<' '<<q.back()<<std::endl;
 
    // insert           inserts elements
    // emplace          constructs element in-place
    q.insert(q.end(),6);
    q.insert(q.end(),10);
    q.emplace(q.end(),122);
    print(q);

    // push_front       inserts an element to the beginning
    // emplace_front    constructs an element in-place at the beginning
    // push_back        adds an element to the end
    // emplace_back     constructs an element in-place at the end
    q.push_back(1000);
    q.emplace_back(1001);
    q.push_front(1);
    q.push_front(0);
    print(q);

    // append_range     adds a range of elements to the end
    // prepend_range    adds a range of elements to the beginning
    //!?

    // pop_back         removes the last element
    // pop_front        removes the first element
    q.pop_back();
    q.pop_front();
    print(q);

    // resize           changes the number of elements stored
    std::cout<<"OldSize = "<<q.size()<<std::endl;
    //if the new value is smaller then thrink will happen otherwise expands will happen with elements with zeros 
    q.resize(7); 
    std::cout<<"NewSize = "<<q.size()<<std::endl;
    print(q);
    // swap             swaps the contents
    std::deque<int> q2={2,2,2,2,2,2};
    q2.swap(q);
    // clear            clears the contents
    q.clear();
    print(q2);
    return 0;
}