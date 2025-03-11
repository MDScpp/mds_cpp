#include <algorithm> // для std::copy, std::move
#include <initializer_list>
#include <stdexcept> // для исключений

template <typename T>
class ToyVector {
private:
    T* data = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void reallocate(size_t new_capacity) {
        T* new_data = new T[new_capacity];

        for (size_t i = 0; i < size_; ++i) {
            new (new_data + i) T(std::move(data[i])); // move-конструктор
            data[i].~T(); 
        }
        
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    // Конструкторы
    ToyVector() = default;
    
    explicit ToyVector(size_t count) 
        : data(new T[count]), size_(count), capacity_(count) {}
    
    ToyVector(std::initializer_list<T> init)
        : data(new T[init.size()]), size_(init.size()), capacity_(init.size()) {
        std::copy(init.begin(), init.end(), data);
    }
    
    // Правило пяти
    ~ToyVector() { 
        clear();
        delete[] data;
    }
    
    ToyVector(const ToyVector& other)
        : data(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_) {
        std::copy(other.data, other.data + size_, data);
    }
    
    ToyVector& operator=(const ToyVector& other) {
        if (this != &other) {
            ToyVector temp(other);
            swap(temp);
        }
        return *this;
    }
    
    ToyVector(ToyVector&& other) noexcept 
        : data(other.data), size_(other.size_), capacity_(other.capacity_) {
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    
    ToyVector& operator=(ToyVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }
    
    // Методы
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            reallocate(capacity_ ? capacity_ * 2 : 1);
        }
        new (data + size_) T(value); // Placement new
        ++size_;
    }
    
    void push_back(T&& value) {
        if (size_ >= capacity_) {
            reallocate(capacity_ ? capacity_ * 2 : 1);
        }
        new (data + size_) T(std::move(value));
        ++size_;
    }
    
    void pop_back() {
        if (size_ > 0) {
            data[--size_].~T();
        }
    }
    
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            reallocate(new_capacity);
        }
    }
    
    void clear() {
        for (size_t i = 0; i < size_; ++i) {
            data[i].~T();
        }
        size_ = 0;
    }
    
    // Доступ к элементам
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    // Итераторы (упрощённые)
    T* begin() { return data; }
    T* end() { return data + size_; }
    const T* begin() const { return data; }
    const T* end() const { return data + size_; }
    
    // Утилиты
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    
    void swap(ToyVector& other) noexcept {
        std::swap(data, other.data);
        std::swap(size_, other.size_);
        std::swap(capacity_, other.capacity_);
    }
};