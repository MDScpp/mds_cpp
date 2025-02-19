#include <iostream>


class Slave {
    
    public:

    Slave ()  {
        std::cout<< "make slave"<<std::endl;
        p_ = new int [100];
        if (p_==nullptr) std::cout<< "bed alloc"<<std::endl;
        else size_ = 100;
    }

    explicit Slave (size_t size)  {
        std::cout<< "make size slave "<<std::endl;
        p_ = new int [size];
        if (p_==nullptr) std::cout<< "bed alloc"<<std::endl;
        else size_ = size;
    }

    Slave (const  Slave & arg)  { 
        // is used for : 
        // Slave b(10) ; 
        // Slave a = b;  <- for this 
        std::cout<< "copy slave "  <<std::endl;
        p_ = new(std::nothrow) int [arg.size_];
        if (p_==nullptr){ 
            std::cout<< "bed alloc "<<std::endl;
            return;
        }
        size_ =  arg.size_;
        for(size_t i=0; i< arg.size_; i++)
            p_[i] = arg.p_[i];
            // *(p_+i) = *(arg.p_+i)
    }

    Slave (Slave && arg)  noexcept {
        std::cout<< "move slave "<<std::endl;
        this->p_ = arg.p_;
        size_ =  arg.size_;
        arg.size_ = 0;
        arg.p_ = nullptr;
    }



    ~Slave ()  {
        std::cout<< "destruct slave "<<std::endl;
        delete[] p_;
    }


    Slave & operator=( const  Slave & arg ){
        // is used for : 
        // Slave b(10) ; 
        // Slave a(199) ;
        // a = b;  <- for this 
        // it is also posiible to have : 
        // a = a; 
        std::cout<< "copy assignment "<<std::endl;
        if (&arg == this)
            return *this;

        // remember to release your own dynamic resources
        // however you can implement more sophisticated logic 
        // to avoid memory allocation and removing, if sizes are equal.
        // but this only makes sense for copying.

        delete[] p_;    

        p_ = new(std::nothrow) int [arg.size_];
        // the same: this->p_ = new(std::nothrow) int [arg.size_];
        if (p_==nullptr){ 
            std::cout<< "bed alloc "<<std::endl;
            return *this;
        }
        size_ =  arg.size_;
        for(size_t i=0; i< arg.size_; i++)
            p_[i] = arg.p_[i];
        
        return *this;
    }


    Slave & operator=(Slave && arg) noexcept {
        // is used for : 
        // Slave a(10) ; 
        // a = Slave(10);  <- for this 
        std::cout<< "move slave assignment"<<std::endl;

        // do not forget to free your ouwn dynamic recources
        // or you can excange recources 
        delete[] p_;


        p_ = arg.p_;
        size_ =  arg.size_;
        arg.size_ = 0;
        arg.p_ = nullptr;
        return *this;
    }
    

    int *p_ = nullptr;
    size_t size_ = 0; 
};


std::ostream & operator<<(std::ostream & str, const Slave &  slave){
    str<< slave.size_ << std::endl;
    return str;
}

class Owner {
    public:
    Slave sss;
};

Owner makeOwner(){
    Owner o ;
    std::cout<< "makeOwner\n";
    return o;
}

Slave makeSlave(){
    Slave a(5);
    std::cout<< "makeSlave\n";
    return a;
}



int main(){
    Slave  sl(10);

    // to enter from value from the command line 
    //size_t array_saize ; 
    //std::cin >> array_saize ;
    //Slave my_slave_object(array_saize);


    // example of exeption catch , you 
    //Slave* slave_ptr = nullptr; 
    //int *int_ptr = nullptr;
    //try{
    //    auto prt = new Slave[4] ;
    //    new int [1000000000000ll];
    //}
    //catch (const std::bad_alloc& e)
    //{
    //    std::cout << "Allocation failed: " << e.what() << '\n';
    //}

    
    try{
        Slave c = Slave(50000000000);
    }catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }

    Slave c = makeSlave();

    Slave a ;
    a = Slave(10);

    std::cin.get();
    return 0; 
}