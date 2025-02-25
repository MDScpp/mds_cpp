#include <iostream>


class Ifs  {
    public:
        virtual ~Ifs() = default;
        //virtual void doSomething() = 0;
        virtual void print() = 0; 

    protected:
        int * ptr = nullptr;
        size_t size_ = 0;
};

class AnotherChildPoly : public Ifs{
public:
     ~AnotherChildPoly() {  std::cout << "Another destructor\n";
        delete ptr ; 
    };
    

    void print() override { std::cout << "Another\n"; }

protected:
    int * ptr = nullptr;
    size_t size_ = 0;
};

class ChildPoly : public Ifs {
public:
    ~ChildPoly() override  { std::cout << "Child destructor\n"; };

    void print() override { std::cout << "Child\n"; }
};

void show(AnotherChildPoly* ptr){ ptr->print();}



int main() {
    int size = 3;

    //ParentPoly* a = new AnotherChildPoly ;
    //ParentPoly* b = new ChildPoly ;
    //show(a); show(b);
    //return 0 ;

    Ifs** poly_array = new Ifs* [ size];

    for (int i = 0 ; i<size; i++ ){
        if (i%2 == 0 ) poly_array[i] = new AnotherChildPoly;
        else poly_array[i] = new ChildPoly;
    }

    for (int i = 0 ; i<size; i++ ){
        poly_array[i]->print();
    }

    for (int i = 0 ; i<size; i++ ){
        delete poly_array[i];
    }

    delete[] poly_array;
    return 0 ;
}