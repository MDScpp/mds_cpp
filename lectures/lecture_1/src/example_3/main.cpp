//-- main.cpp
#include <iostream>
#include "my_math.h"

int main()
{
    int x = 5, y = 3;
    std::cout   << "Hello: " 
                << add(x, y) 
                << std::endl;

    std::cout   << "World: " 
                << multiply(x, y) 
                << std::endl;
    return 0;
}