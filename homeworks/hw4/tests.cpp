#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp> 
#include <stdexcept>
#include "FixedCapacityVector.h"



struct TestStruct {
    int value;
    
    TestStruct() = delete; 
    TestStruct(int v = 0) : value(v) {  }
    ~TestStruct() {  }
};


struct DestructionCounter {
    static int count;
    int value;
    
    DestructionCounter(int v = 0) : value(v) {  }
    ~DestructionCounter() { count++; }
};

int DestructionCounter::count = 0;


struct InstanceCounter {
    static int count;
    int value;
    
    InstanceCounter(int v = 0) : value(v) { count++;  }
    ~InstanceCounter() { count--; }
};

int InstanceCounter::count = 0;


TEST_CASE("FixedCapacityVector basic functionality") {
    constexpr size_t CAPACITY = 3;
    FixedCapacityVector<int, CAPACITY> vec;

    SECTION("Initial state") {
        REQUIRE(vec.capacity() == CAPACITY);
        REQUIRE(vec.size() == 0);
    }

    SECTION("Add elements with push_back") {
        vec.push_back(10);
        REQUIRE(vec.size() == 1);
        REQUIRE(vec.get(0) == 10);

        vec.push_back(20);
        REQUIRE(vec.size() == 2);
        REQUIRE(vec.get(1) == 20);
    }

    SECTION("Overflow handling") {
        for (size_t i = 0; i < CAPACITY; ++i) {
            vec.push_back(i);
        }
        
        REQUIRE_THROWS_AS(vec.push_back(99), std::out_of_range);
        REQUIRE(vec.size() == CAPACITY);
    }

    SECTION("Pop back operations") {
        vec.push_back(1);
        vec.pop_back();
        REQUIRE(vec.size() == 0);

        vec.pop_back(); // Попытка удалить из пустого вектора
        REQUIRE(vec.size() == 0);
    }

    SECTION("Element access validation") {
        vec.push_back(42);
        REQUIRE(vec.get(0) == 42);
        
        vec.get(0) = 100;
        REQUIRE(vec.get(0) == 100);

        REQUIRE_THROWS_AS(vec.get(1), std::out_of_range);
    }
}


TEST_CASE("FixedCapacityVector with objects") {
    constexpr size_t CAPACITY = 6;

    {
        FixedCapacityVector<DestructionCounter, CAPACITY> vec;

        SECTION("Object lifecycle management") {
            
            REQUIRE(DestructionCounter::count == 0);
            
            vec.push_back(1);
            vec.push_back(2);
            REQUIRE(DestructionCounter::count == 2);
            
            
            vec.pop_back();
            REQUIRE(DestructionCounter::count == 3);
        
            vec.push_back(3);
            REQUIRE(DestructionCounter::count == 4);
        }
    }

    DestructionCounter::count = 0;

    SECTION("Destructor calls") {
        {
            FixedCapacityVector<DestructionCounter, 8> local_vec;
            local_vec.push_back(1);
            local_vec.push_back(2);

            REQUIRE(DestructionCounter::count == 2);
        }
        
        REQUIRE(DestructionCounter::count == 4);
    }


    //{
    //    FixedCapacityVector<InstanceCounter, CAPACITY> vec;
    //    SECTION("Object lifecycle management with emplace_back") {
    //        
    //
    //        REQUIRE(InstanceCounter::count == 0);
    //        
    //        vec.emplace_back(1);
    //        vec.emplace_back(2);
    //        REQUIRE(InstanceCounter::count == 2);
    //    
    //        vec.pop_back();
    //        REQUIRE(InstanceCounter::count == 1);
    //    
    //        vec.emplace_back(3);
    //        REQUIRE(InstanceCounter::count == 2);
    //    }
    //}
    //SECTION("Destructor calls with emplace_back") {
    //    {
    //        FixedCapacityVector<InstanceCounter, 3> local_vec;
    //        local_vec.emplace_back(1);
    //        local_vec.emplace_back(2);
    //        REQUIRE(InstanceCounter::count == 2);
    //    }
    //    
    //    REQUIRE(InstanceCounter::count == 0);
    //}
}

TEST_CASE("Push back with copy semantics") {
    constexpr size_t CAPACITY = 2;
    FixedCapacityVector<std::string, CAPACITY> vec;

    SECTION("Push back lvalue") {
        std::string s = "test_value";
        vec.push_back(s);
        auto p = vec.get(0);
        REQUIRE(vec.get(0) == "test_value");
        REQUIRE(s == "test_value"); // Original value preserved
    }
}