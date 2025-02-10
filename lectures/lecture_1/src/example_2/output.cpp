class FooIfs {
    public:
    virtual ~FooIfs() = default;
};
kaj 0snas)-
int main() {
   int a = (0x1000);
   int b = ((0x1000)*(100) + (a));
   return b + a*10;
}
