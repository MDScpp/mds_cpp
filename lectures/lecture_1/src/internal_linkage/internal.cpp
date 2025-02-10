//-- internal.cpp
static int a = 1; 
const float b = 1;

static int func(){ return 3; }

namespace{
    int foo() { return 42;}
}

int foo2(){return func()+foo() ;}