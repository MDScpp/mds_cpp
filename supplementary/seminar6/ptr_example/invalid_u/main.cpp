#include "A.h"


struct B{
    B(){ ptr = nullptr; }
    void * ptr;
};

std::unique_ptr<B> createB(){
    return std::make_unique<B>();
}

int main(){
    A a;

    return 0;
}



