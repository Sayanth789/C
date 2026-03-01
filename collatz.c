/* 
The collatz conjucture invlves sequnces defined by the rule.

X_n_+_1 = { X_n_/_2               if X_n is even
            3 X_n + 1           If x is odd
}

The sequence is iterated from an intial value X_0 until it terminates 
// with the value of 1.



*/


#include <stdio.h>

/* Compute the length of COllatz sequences */

unsigned int 

step (unsigned int x ) {
    if (x % 2 == 0) 
    { 
        return ( x / 2);
    }
    else {
        return ( 3 * x + 1);
    }
}

unsigned int 
nseq (unsigned int x0) { 
    unsigned int i = 1, x;

    if (x0 == 1 || x0 == 0) 
        return i;

    x = step (x0);
    
    while (x != 1 && x != 0) {
        x = step (x);
        i++;

    }

    return i;
}

int main (void) {
    unsigned int i , m = 0, im = 0;
    for (i = 1; i < 500000; i++) {
        unsigned int k = nseq (i);

        if (k > m)
            {   
                m = k; 
                im = i;
                printf("sequence length = %u for %u\n", m, im);
        }
    }
    return 0;
}