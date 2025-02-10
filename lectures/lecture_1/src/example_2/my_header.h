#ifndef FOO_IFS_H 
#define FOO_IFS_H 

#define SOME_MAGIC_NUMBER (0x1000)
#define SOMETHING_SENSELESS kaj 0snas)-
// \ - symbol allows to continue 
// from the next line
#define SOMETHING_STRANGE(X,Y) \
    (SOME_MAGIC_NUMBER*(Y) + (X))

#define BAD_ADD(X,Y) \
    Y + X

class FooIfs {
    public:
    virtual ~FooIfs() = default;
};

#endif 