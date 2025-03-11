#include <iostream>
#include <new> // Для placement new
#include <utility> // Для std::move


// https://en.cppreference.com/w/cpp/language/new  (см. раздел с placement new)

/* ваш код  (тут буквально одна строка)*/ 
class FixedCapacityVector {
private:

    // тут вам понадобится alignas 

    // ваш код  (создайте буфер под данные, никаких new не нужно )

    std::size_t size_ = 0;; 

    
    T* getPtr(std::size_t index) {
        // ваш код вспомогательная функция (вам нужно привести тип)
    }


public:

    FixedCapacityVector() = default;

    FixedCapacityVector(const FixedCapacityVector&) = delete;
    FixedCapacityVector& operator=(const FixedCapacityVector&) = delete;

    ~FixedCapacityVector() {
        while(size_) pop_back();
    }

    std::size_t capacity(){
        // ваш код //
    }

    size_t size( ) const { /* ваш код */ }

    void push_back(const  T & arg) {
        if (/* ваш код */) {
            throw std::out_of_range("Invalid index");
        }
        /* ваш код */
    }


    void pop_back() {
        /* ваш код */
    }


    T& get(std::size_t index) {
        if (/* ваш код */ ) {
            throw std::out_of_range("Invalid index ");
        }
       /* ваш код */
    }


    // следующие два метода не обязательны для реализации.
    // они на один дополнительный балл, для саморазвития
    
    //void push_back( T && arg) {
    // этот метод реализовывать не нужно, но если хотите то можете сделать, 
    // но чтобы он работал хорошо, нужно использовать std::move  
    // https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D1%8F%D0%BC%D0%B0%D1%8F_%D0%BF%D0%B5%D1%80%D0%B5%D0%B4%D0%B0%D1%87%D0%B0_(C%2B%2B)
    // Особое поведение параметров — временных ссылок
    //}

    // здесь нужно использовать  std::forward<Args>(args)
    // 
    //template <typename... Args>
    //void emplace_back( Args&&... args) {
    //
    //}

};

