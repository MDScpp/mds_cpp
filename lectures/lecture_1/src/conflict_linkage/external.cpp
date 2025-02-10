//-- external.cpp
extern int a ; 
float b ;

int func(){ return 100; }

inline int foo() { return 42;}

inline int goog() { return 100;}

int foo2(){ return func()+foo() ;}