#include <memory>

struct B;

std::unique_ptr<B> createB();

class A {
    std::unique_ptr<B> uptr_;
    // B::~B() can't be seen from here
public:
    A();
    ~A(){ };
};


