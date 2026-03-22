#include <stdio.h>

int main() {
    int a = 10;
    int *p;
    a = 10;

    p = &a;

    printf("%p\n", p);   // prints address
    printf("%d\n", *p);  // prints value at that address

    *p = 100;
    // chaning a to 100 


    printf("a = %d\n", a);
    
}