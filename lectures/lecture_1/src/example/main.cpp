// Type your code here, or load an example.
unsigned int square(int num) {
    return num * num;
}

unsigned int vabs(int x, int y){
    x-=1; 
    unsigned int sq1 =  square(x);
    unsigned int sq = square(y)+sq1;
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
    return (int) vabs(x,y);
}