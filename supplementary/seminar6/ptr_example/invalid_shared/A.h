#include <memory>

struct B;

std::shared_ptr<B> createB();

class A {
    std::shared_ptr<B> uptr_;
    // B::~B() can't be seen from here
public:
    A();
    ~A(){ };
};


