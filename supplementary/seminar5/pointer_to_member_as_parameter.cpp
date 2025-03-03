#include <iostream>

template<typename T> // primary template
struct is_void : std::false_type {};
template<>           // explicit specialization for T = void
struct is_void<void> : std::true_type {};

template <class  T>
int countDuplicates(T* begin, T* end) {
    // if (begin == end) return  0;
    int count = 1;
    auto id =  *begin;
    while ( begin + count < end && *(begin + count) == id ) {
        count++;
    }
    return count;
}

template <class  T, int(T::*func)() const>
int countDuplicates(T* begin, T* end) {
    if (begin == end) return  0;
    int count = 1;
    auto id =  (begin->*func)();
    while ( begin + count < end && ((begin + count)->*func)() == id ) {
        count++;
    }
    return count;
}

struct Data {
    int value_;
    int getValue() const  { return value_; }
    bool operator==(const Data& r) const { return this->value_ == r.value_;}
};

int main() {

    // выделение на стеке 
    Data arr[] = { {1}, {1}, {1}, {2}, {2}, {3} };
    int count = countDuplicates<Data, &Data::getValue >(arr, arr + 6);

    std::cout << "Duplicates: " << count << std::endl; 
    return 0;
}