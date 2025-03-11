#include "A.h"


struct B{
    B(){ ptr = nullptr; }
    void * ptr;
};

std::shared_ptr<B> createB(){
    return std::make_shared<B>();
}

int main(){
    A a;

    return 0;
}



