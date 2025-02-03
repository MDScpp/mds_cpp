// compile with: /clr
#include <cstdio>
#include <string>

//extern "C" void my_c_function(int a, int b, int c, long long g) {
//    printf("Hello from C function! %d %lld\n",a,g);
//}

class Subclass{
    public:
    char * some_field_ = nullptr;
    const int level{} ;

    Subclass(  ):level(0){
        printf("create %d\n" , level);
        some_field_ = new char[20];
    }

    Subclass(Subclass  & SubClass ) :level(SubClass.level) {
        some_field_ = SubClass.some_field_;
        SubClass.some_field_ = nullptr;
        printf("move %d\n" , level);
    }

    Subclass(Subclass  && SubClass ) :level(SubClass.level) {
        some_field_ = SubClass.some_field_;
        SubClass.some_field_ = nullptr;
        printf("move %d\n" , level);
    }

    explicit Subclass(const int &level ):level(level){
        printf("create %d\n" , level);
        some_field_ = new char[20];
    }


    ~Subclass(){
        printf("remove level %d\n", level);
        delete[] some_field_;
    }
};


class FooVirt {
    public:
    virtual ~FooVirt() = default;
};

class Foo : public FooVirt
{   
    public:
    void pram_pam(int a){
        int_bla_+=a;
    }
    int int_bla_ = 0;
    char* char_bla_ = nullptr;
    Subclass a_;
    
};


class FooChild: public Foo
{   public:

    int additional_field_ = 0 ;
    Subclass c_ = Subclass(1);

};

int __fastcall my_c_function(int a, int b, int c, long long g, long long h) {
    printf("Hello from C function! %d %lld %lld\n",a,g,h);
    return 0;
}


#include <iostream>

// Declare the C function
//extern "C" void my_c_function();

void remove(Foo* foo_ptr){
    delete foo_ptr;
}

int main() {
    // Define a function pointer type
    using FuncPtr = int ( *)(int a, int b, int c, long long g, long long h);

    // Assign the function pointer
    FuncPtr func = (FuncPtr) &my_c_function;
    Foo* foo_child = new FooChild ;
    Foo* foo = new Foo ;
    // Call the function through the pointer
    func(3,4,5,6,8);

    remove(foo_child);
    remove(foo);
    return 0;
}