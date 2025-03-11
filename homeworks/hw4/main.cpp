#include <string>
#include "FixedCapacityVector.h"

struct TestStruct {
    int x_,y_;
    TestStruct() = delete;
    TestStruct(int x) : x_(x),y_(x+1){};

    ~TestStruct(){ std::cout<<"delete\n";}
};

std::ostream & operator<<(std::ostream& os, const TestStruct & s){
    os << "("<<s.x_<<","<<s.y_<<")";
    return os;
}

int main() {
    {
        FixedCapacityVector<TestStruct, 5> arr;
        arr.push_back(42);
        arr.push_back(99);
        arr.push_back(11);

        //try{
        //    std::cout << arr.get(0) << " " << arr.get(1) << " "<< arr.get(4) << std::endl; // 42 99
//
        //}
        //catch(const std::exception& e){
//
        //    std::cerr << e.what() << '\n';
        //}
    }
    {
        FixedCapacityVector<std::string, 2> vec;
        std::string s = "test_value";
        vec.push_back(s);
        std::cout <<  vec.get(0) <<"\n";
        std::cout << "exit"<<"\n";
    }
    std::cout << "exit"<<"\n";
    return 0;
}