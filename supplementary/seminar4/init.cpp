#include <iostream>


struct Compose {
    Compose(int i): i_(i) { std::cout <<"make Compose "<< i << std::endl; }
    int i_;
    int i2_ ;
};

struct Parent {
    Parent( ):  c1_(1), c_(0) { std::cout <<  "make Parent" << std::endl; }
    Compose c_;
    Compose c1_ = 100;
};

struct Child : Parent{
    Child( ):  c2_(1){  std::cout <<  "make Child" << std::endl; }
    Compose c2_;
};




class AnotherParent{
    public:
    AnotherParent() = default;
    explicit AnotherParent(int val): public_int_(val) { }
    int public_int_ ;
};

class AnotherChild: public AnotherParent {
   public:
   AnotherChild(int & value, float fl) :AnotherParent(value), immutable_(fl) , ref_(value) 
   //, public_int_(10)   error нельзя инициализировать  
    { name_ = "some"; // bed practice 
    }
   public: 
    const float immutable_ ; 
   private:
    std::string name_;
    int& ref_;
};

class IntVector {
    public:
    IntVector(size_t num, double def = 0.){/* */};
};

int sumArr(IntVector const& arr) { /*...*/}


// Инициализация полей происходитт в порядке обьявления этих полей в теле класса !!!!
// порядок в списке инициализации (то что перед телом конструктора )
// не имеет значения 
int main(){
    Child a; 
    sumArr(10); // неявное приведение типов 
}

