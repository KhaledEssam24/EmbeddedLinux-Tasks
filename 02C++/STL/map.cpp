#include <map>
#include <iostream>

void print(auto& container){
    for (auto i : container)
    {
        std::cout << i.first << ' ' << i.second << std::endl;
    }
}

class Student{
private:
    std::string name;
    float gpa;
public:
    Student(std::string name,float gpa):name(name),gpa(gpa){}
    bool is_passed(){
        return gpa > 2;
    }
    std::string get_name(){
        return name;
    }
    bool operator<(const Student& student) const{
        return name < student.name;
    }
    friend std::ostream& operator<<(std::ostream& os,const Student& student){
        os<<student.name;
        return os;
    }
};


int main(){
    Student student1("Khaled",3.5);
    Student student2("Essam",2);
    Student student3("Mohammed",1.8);
    std::map <Student,int> ordered_map={
        {student1,5000},
        {student2,15000},
        {student3,10000},
    };
    // print(ordered_map);
    // empty            checks whether the container is empty
    std::cout << "Empty " << ordered_map.empty()<<std::endl;
    // size             returns the number of elements
    std::cout << "Size " << ordered_map.size()<<std::endl;
    // max_size         returns the maximum possible number of elements
    std::cout << "Max_size " << ordered_map.max_size()<<std::endl;
    // insert           inserts elements or nodes(since C++17)
    // insert_or_assign inserts an element or assigns to the current element if the key already exists
    // try_emplace      inserts in-place if the key does not exist, does nothing if the key exists
    // emplace          constructs element in-place
    // emplace_hint     constructs elements in-place using a hint
    ordered_map.insert({Student("Ali",3),8000});
    ordered_map.insert({Student("Ali",3),9000}); //Ignoring (uni_map)
    ordered_map.emplace(Student("Nader",1.1),9000);
    ordered_map.emplace(student3,10000); //!Notice Is there duplication ?
    ordered_map.insert_or_assign(student1,11000); //assign new value
    ordered_map.insert_or_assign(Student("Wael",2.2),12000); //insert new element 
    ordered_map.try_emplace(Student("Ahmed",2.2),17000); 
    print(ordered_map);

    // erase            erases elements
    ordered_map.erase(Student("Ali",3));
    // print(ordered_map);
    // extract          extracts nodes from the container
    auto extracted = ordered_map.extract(Student("Nader",1.1)) ; //erase also
    std::cout<< extracted.key() << std::endl;
    // print(ordered_map);

    // merge            splices nodes from another container
    std::map<Student,int> map2={
        {Student("Kamal",3),900},
        {Student("Saad" ,0.5),2000},
    };
    ordered_map.merge(map2);
    // print(ordered_map);
    // count            returns the number of elements matching specific key
    // find             finds element with specific key
    //! orderde returns 1 if found otherwise 0
    // can be used instead of find
    std::cout << "Count1 " << ordered_map.count(student1) << std::endl;
    std::cout << "Count2 " << ordered_map.count(Student("Hassan" ,0.5)) << std::endl; 
    auto it = ordered_map.find(Student("Hassan" ,0.5));
    //?why are find and count are using < operator instead of 
    if(it==ordered_map.end())
        std::cout << "Not Found" << std::endl;
    else
        std::cout << "Find " << it->first << std::endl;  // Find Saad

    // equal_range      returns range of elements matching a specific key
    //useful for multiset

    // lower_bound      returns an iterator to the first element not less than the given key
    // upper_bound      returns an iterator to the first element greater than the given key
    auto it_low = ordered_map.lower_bound(Student("Mai",4)); //  >=
    auto it_high = ordered_map.upper_bound(Student("Mai",4)); // >
    std::cout << it_low->first << std::endl;
    std::cout << it_high->first << std::endl;
    // clear            clears the contents
    ordered_map.clear();
    return 0;
}