#include <iostream>
#include <algorithm>
#include <vector>

// 4- merge two arrays together
template<typename T>
void merge(const std::vector<T> &vec1,const std::vector<T> &vec2,std::vector<T> &res){
    res.insert(res.end(),vec1.begin(),vec1.end());
    res.insert(res.end(),vec2.begin(),vec2.end());
}


int main(){
    std::vector <float>result;
    merge<float>({1,2,3,4},{5,6.5f,7,8},result);

    for (float i : result)
    {
        std::cout << i << ' ';
    }
    std::cout<<std::endl;
    return 0;
}
