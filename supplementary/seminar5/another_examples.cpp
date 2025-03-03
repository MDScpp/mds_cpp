
#include <iostream>
#include <vector>
#include <memory>



template<typename TT>
class MyStorage{
    public:
    TT *ptr_= nullptr;
    int size_ = 0;

    explicit MyStorage(int size ):size_(size) {
        std::cout << "create MyStorage" << std::endl;
        ptr_ =  new TT [size];
    }

    MyStorage(int size, const TT & init ):size_(size) {
        std::cout << "create MyStorage" << std::endl;
        ptr_ =  new TT [size];
        for( auto p= ptr_, end = (ptr_+size) ; p<end ; p++ ){ 
            *p = init;
        }
    }

    ~MyStorage(){
        std::cout << "MyStorage deleted" << std::endl;
        delete ptr_;
    }

    void print(){ 
        for( auto i: *this)
            std::cout << i <<" ";
        std::cout <<std::endl; 
    }

    TT * begin() {return ptr_;}
    TT * end() {return ptr_ + size_; }
};


template<typename T>
class my_unique_ptr{
    
    T * ptr_;
    public:

    my_unique_ptr(const my_unique_ptr &) = delete;
    my_unique_ptr& operator=(const my_unique_ptr&) = delete;

    my_unique_ptr( my_unique_ptr&& right ) noexcept
    : ptr_(right.ptr_) { right.ptr_ = nullptr; }

    T& operator*() const {
        return *ptr_;
    }

    explicit my_unique_ptr( T * ptr ){
        ptr_ = ptr;
    }

    ~my_unique_ptr( ){
        delete ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }

    // тут должно быть еще несколько вспомогательных методов
};


int main (){

    {
        my_unique_ptr<MyStorage<int>> my_ptr(  new MyStorage<int>(20, 12)  );

        std::cout << "size of the unique_ptr: " << sizeof(my_ptr) << std::endl;

        // наш объект (a) мимикрирует под указатель на MyStorage<int>
        // за счет определенного  operator->()
        my_ptr->print();


        int cnt = 0;
        for (auto  &i: *my_ptr ){
            i = cnt++;
        }
        my_ptr->print();

        // здеcь заканчивается блок и время жизни my_ptr подходик к концу
        std::cout << "this is where the block ends and my_ptr's lifetime is coming to an end" << std::endl<< std::endl;
    }
    //здезь my_ptr уже почил в бозе, и всместе с собой он прихватил объект MyStorage<int> 
    std::cout   << "here my_ptr has already died, and along with it it took the MyStorage<int> object" 
                <<  std::endl << std::endl;




    
    MyStorage<int> my(10, 100);

    // так как мы сделали begin() и end() для нашего MyStorage, то можем использовать 
    // Range-based for loop https://en.cppreference.com/w/cpp/language/range-for#top
    for (auto &i : my){
        /* некоторый код */
    }

    // тоже самое, но длиннее 
    {
        auto p = my.begin();
        auto end = my.end();
        for( ; p<end; p++ ){
            int &i = *p;
            {
                /* некоторый код */
            }
        }
    }
}