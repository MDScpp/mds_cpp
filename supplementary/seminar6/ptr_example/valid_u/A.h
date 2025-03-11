#include <memory>



struct B;

class A {
    std::unique_ptr<B> uptr_;

public:
    A();
    ~A(){  };
};


struct B {
    
    B(){ ptr = nullptr; }
    void * ptr;
};

std::unique_ptr<B> createB();