#include <fstream>
#include "file_ifs_example.h"




// const char * 
int main(int argc, char **argv) {
    {
        struct {
            double d = 0.35;
            std::string s = "my_init_val";
            int val = 100;
        } ss;
        std::ofstream ofile(std::string("my_bin.file"), std::ios::binary);
        ir::write(ofile, ss.d ,ss.s, ss.val);
    }  

    {
        std::ifstream ifile(std::string("my_bin.file"), std::ios::binary);
        struct {
            double d = 0;
            std::string s = "gol";
            int val = 1;
        } ss;

        ir::read(ifile, ss.d ,ss.s, ss.val);
        std::cout   << ss.d     << std::endl
                    << ss.s     << std::endl
                    << ss.val;
    }

    return 0;
}