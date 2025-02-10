//clang++ godbot.cpp -S -o godbot.s -m64 -masm=intel 
//clang++ godbot.cpp -S -o godbot.s -m64    -mllvm --x86-asm-syntax=intel -fno-verbose-asm -S -fcolor-diagnostics -fno-crash-diagnostics
// Type your code here, or load an example.
typedef unsigned int (*  sqare_ft)(int );

unsigned int square(int num) {
    return num * num;
}

unsigned int vabs(int x, int y){
    unsigned int sq1 = square(x);
    unsigned int sq2 = square(y);
    unsigned int sq = sq1+sq2;
	unsigned int L = 0;
	unsigned int R = sq + 1;
    while (L != R - 1)
    {
        unsigned int M = (L + R) >> 1;
		if (M * M <= sq)
			L = M;
		else
			R = M;
	}
    return L;
}



int main(){
 int x = 100;
 int y = 400;
 int* y_p = (&y) + 100000;
 int r = *y_p;
 return vabs(x,y);
}
