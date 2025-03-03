
#ifndef FILE_INTERFACE_EXAMPLE
#define FILE_INTERFACE_EXAMPLE

#include <iostream>
#include <string>

namespace ir {
using ir_ostream = std::ostream;
using ir_istream = std::istream;

/*
 * writing to file interface
 */

template <typename T>
inline void writeToFile(ir_ostream &os, const T &x) {
    static_assert(!std::is_pointer<T>::value, "pointers is invalid arguments");
    os.write(reinterpret_cast<const char *>(&x), sizeof(x));
};

template <>
inline void writeToFile<std::string>(ir_ostream &os, const std::string &str) {
    auto size = (uint32_t)str.size();
    os.write(reinterpret_cast<char *>(&size), sizeof(size));
    os.write(str.data(), std::streamsize(str.length()));
};



template <class Mod, class... Mods>
void write(ir_ostream &os, const Mod &M, const Mods &...Ms) {
    writeToFile(os, M);
    //std::cout<<"val: "<< M << "\n";
    write(os,Ms...);
}

template <class Mod>
void write(ir_ostream &os, const Mod &M){
    writeToFile(os, M);
    //std::cout<<"val: "<< M << "\n";
}

/*
 * reading from file interface
 */

template <typename T>
inline void readFromFile(ir_istream &os, T &x) {
    static_assert(!std::is_pointer<T>::value, "pointers is invalid arguments");
    os.read(reinterpret_cast<char *>(&x), sizeof(x));
};

template <>
inline void readFromFile<std::string>(ir_istream &os, std::string &str) {
    uint32_t size;
    os.read(reinterpret_cast<char *>(&size), sizeof(size));
    str.resize(size);
    os.read( &str[0], std::streamsize(size));
};



template <class Mod, class... Mods>
void read(ir_istream &os, Mod &M,  Mods &...Ms) {
    readFromFile(os, M);
    //std::cout<<"val: "<< M << "\n";
    read(os, Ms...);
}

template <class Mod>
inline void read(ir_istream &os,  Mod &M){
    readFromFile(os, M);
    //std::cout<<"val: "<< M << "\n";
}
};


#endif  // FILE_INTERFACE_EXAMPLE
