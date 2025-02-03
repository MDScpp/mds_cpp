#include <stdio.h>

extern "C" int my_c_function(int a, int b, int c, long long g, long long h) {
    printf("Hello from C function! %d %lld %lld\n",a,g,h);
    return 0;
}



#include <iostream>

// Declare the C function
//extern "C" void my_c_function();

int main() {
    // Define a function pointer type
    using FuncPtr = int ( *)(int a, int b, int c, long long g, long long h);

    // Assign the function pointer
    FuncPtr func = (FuncPtr) &my_c_function;

    // Call the function through the pointer
    func(3,4,5,6, 8);

    return 0;
}