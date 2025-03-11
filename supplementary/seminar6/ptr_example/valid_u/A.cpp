#include "A.h"


std::unique_ptr<B> createB(){
    auto x = unique_ptr<X>(new X(10));

    return std::make_unique<B>();
}

A::A():uptr_(createB()){

}