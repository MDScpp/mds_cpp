#include <iostream>

class Base {
public:
    void pub() {std::cout<< "Base\n";}
    void anotherPub() {std::cout<< "Base\n";}
protected:
    void prot() {}
    int i , j;
private:
    void priv() {}
    
};

class Derived: public Base {
    public:
    void pub() {
        Base::pub(); // OK parent class method call 
        anotherPub();  // OK parent class method call 
        // since there is no method with the same name 
        prot(); // OK
        //priv(); // ошибка
        i = 10;
        Base::i = 20; 
        j = 30 ;
    }
    int i;
};


class Derived2: private Base {
    public:
    void thirdPub () {
        Base::pub(); //OK вызов родительского метода
        anotherPub();  // OK вызов родительского метода
        // так как нет метода с таким же именем
        std::cout<< "Derived\n";
        prot(); // OK
    }
};


class AnotherDerived: private Base {
    public:
    using Base::prot;
    void thirdPub () {
        Base::pub(); // OK вызов родительского метода
        anotherPub();  // OK вызов родительского метода
        // так как нет метода с таким же именем
        std::cout<< "Derived\n";
        prot(); // OK
    }
};

class TwiceDerived: public AnotherDerived {
    public:
    void foo () {
        prot() ; // можно вызывать, был открыт в секции public
        // с помощью using
        //anotherPub(); // ошибка, был закрыт в родительско классе
        // базовым спецификатором 
    }
};


class MyClass{
    public:
    class AuxilaryClass{
      public:
      int * begin_; 
      int * end_;
      int * begin(){return begin_;}
      int * end(){return end_;}
    };

    void func() {AuxilaryClass a; }
    protected:
    AuxilaryClass c_;
    int * p_ = nullptr;
};

typedef MyClass::AuxilaryClass NewName;
using  SomeName =  MyClass::AuxilaryClass ;



namespace MyNamespace {
    class SomeTypeName {
      public:
      typedef int NestedType;
      NestedType a;
    };
}
using namespace std; 

//int main(){
//    SomeName a; 
//    MyClass::AuxilaryClass b; 
//    NewName c;
//    return 0;
//}

int main(){
    MyNamespace::SomeTypeName a; // имя SomeTypeName находится в пространстве имен   MyNamespace
    MyNamespace::SomeTypeName::NestedType b; // имя NestedType находится в типе SomeTypeName
     // будет действовать в пределах блока {}
    { 
        using namespace MyNamespace;
        SomeTypeName a1;
        SomeTypeName::NestedType b1;
        // using SomeTypeName::NestedType; //
    }
    // SomeTypeName a2; //ошибка. т.к. вне блока 
}