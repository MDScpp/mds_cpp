class Slave {
    public:
    Slave ();
    Slave (size_t size) ;
    ~Slave ();
    Slave (Slave && arg);
    Slave (const  Slave & arg);
    Slave &operator=(const Slave &arg);
    Slave &operator=(Slave &&arg);
    int *p_ = nullptr;
    size_t size_ = 0;
};