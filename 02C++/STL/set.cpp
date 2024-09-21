#include <set>
#include <unordered_set>
#include <iostream>

#define UNORDERED_SET

void print(auto& container){
    for (auto i : container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

#ifdef ORDERED_SET
int main(){
    std::set<int> s{1,2,3,4,3,6};
    print(s);
    std::cout << s.size() << ' ' << s.max_size() << std::endl; //5 230584300921369395

    // insert	    Insert element 
    s.insert(0);
    s.insert(3);
    s.insert(5);
    print(s); //0,1,2,3,4,5,6 (ordered)
    // erase	    Erase elements 
    s.erase(3);
    print(s);//0,1,2,4,5,6
    // swap	        Swap content 
    std::set<int> ss{11,22,33,44,33,66};
    ss.swap(s);
    print(s);   //11,22,33,44,33,66
    print(ss);  //0,1,2,4,5,6
    // clear	    Clear content 
    ss.clear();
    print(ss);
    // emplace	    Construct and insert element 
    s.emplace(45);//11,22,33,44,45,33,66
    print(s);
    // emplace_hint	Construct and insert element with hint
    s.emplace_hint(s.begin(),80);   //hint like suggestion but if it's wrong then nothing would happen just for optimization 
    print(s);

    // find	        Get iterator to element 
    auto it = s.find(33);
    std::cout << *it << std::endl;
    // count	    Count elements with a specific value 
    std::cout << s.count(22) << ' ' << s.count(21) << std::endl;
    // lower_bound	Return iterator to lower bound 
    // upper_bound	Return iterator to upper bound 
    auto itlow=s.lower_bound (30);
    auto itup =s.upper_bound (60); 
    std::cout << *itlow << ' ' << *itup << std::endl;
    //the same except if the value is the same as set value 
    //example   
    itlow=s.lower_bound (33);
    itup =s.upper_bound (33); 
    std::cout << *itlow << ' ' << *itup << std::endl;
    // equal_range	Get range of equal elements 
    auto ret = s.equal_range(33);
    ret.swap(ret);
    print(s);
    return 0;
}
#else
int main(){
    //no swap 
    //no upper and lower bound 

    std::unordered_set<int> s{1,2,3,4,3,6};
    print(s);
    std::cout << s.size() << ' ' << s.max_size() << std::endl; //5 576460752303423487

    // insert	    Insert element 
    s.insert(0);
    s.insert(3);
    s.insert(5);
    print(s); //5 0 6 4 3 2 1 (unordered)
    // erase	    Erase elements 
    s.erase(3);
    print(s);//5 0 6 4 2 1
    // emplace	    Construct and insert element 
    s.emplace(45);//11,22,33,44,45,33,66
    print(s);
    // emplace_hint	Construct and insert element with hint
    s.emplace_hint(s.end(),80);   //hint like suggestion 
    print(s);
    // find	        Get iterator to element 
    auto it = s.find(80);
    std::cout << *it << std::endl;
    // count	    Count elements with a specific value 
    std::cout << s.count(5) << ' ' << s.count(21) << std::endl;
    // equal_range	Get range of equal elements 
    auto ret = s.equal_range(33);
    ret.swap(ret);
    print(s);

    // bucket_count	        Return number of buckets 
    unsigned n = s.bucket_count();
    std::cout << "myset has " << n << " buckets.\n"; //12

    for (unsigned i=0; i<s.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:";
        for (auto it = s.begin(i); it!=s.end(i); ++it)
            std::cout << " " << *it;
        std::cout << "\n";
        std::cout << "bucket #" << i << " has " << s.bucket_size(i) << " elements.\n";
    }
    //!we have 12 buckets here and through the key of each element in set 
    //!we could pass it to hash formula and get the bucket number to be stored in 
    //?but what if there is collision in a specific bucket ?
    //!the answer is to create linked list in bucket by storing the address of the new bucket in the old bucket.
    //!https://www.youtube.com/watch?v=FsfRsGFHuv4

    // max_bucket_count	    Return maximum number of buckets 
    unsigned n_max = s.max_bucket_count();
    std::cout << "myset has " << n_max << " max buckets.\n"; //4294967295

    // bucket	            Locate element's bucket 
    for (auto i : s)
    {
        std::cout << i << " is in bucket#" << s.bucket(i) << std::endl;
    }
    
    // load_factor	        Return load factor 
    // max_load_factor	    Get or set maximum load factor 
    std::cout << s.load_factor() << ' ' <<s.max_load_factor() << std::endl;  // 0.615385 1

    // rehash	            Set number of buckets 
    s.rehash(20);
    s={1,2,3,4,3,6};
    for (unsigned i=0; i<s.bucket_count(); ++i) {
        std::cout << "bucket #" << i << " contains:";
        for (auto it = s.begin(i); it!=s.end(i); ++it)
            std::cout << " " << *it;
        std::cout << "\n";
        std::cout << "bucket #" << i << " has " << s.bucket_size(i) << " elements.\n";
    }

    std::cout<< s.contains(55) << std::endl;
    std::cout<< s.contains(80) << std::endl;
    return 0;
}
#endif
