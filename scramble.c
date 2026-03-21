// Yeah from the DOOM's code.


#include <stdio.h>

#define SCRAMBLE(a) \
((((a)&1)<<7) + (((a)&2)<<5) + ((a)&4) + (((a)&8)<<1) \
 + (((a)&16)>>1) + ((a)&32) + (((a)&64)>>5) + (((a)&128)>>7))


 void print_binary(unsigned char n) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
 }


int main() {

    unsigned char a;


    for (a = 0; a < 10; a++) {
        unsigned char result = SCRAMBLE(a);

        print_binary(a);
        printf("   -> ");
        print_binary(result);



        printf(" (%u -> %u)\n", a, result);



    }

    return 0;
}