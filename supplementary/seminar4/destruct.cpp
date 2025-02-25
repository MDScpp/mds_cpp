#include <iostream>




class Parent {
   public:
    ~Parent() { std::cout << "Parent destructor\n"; }
};

class Child : public Parent {
   public:
    ~Child() { std::cout << "Child destructor\n"; }
};

int main() {
    int i = 100 ;
    Child c;
}