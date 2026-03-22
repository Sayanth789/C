#include <stdio.h>

int main() {

    int a = 10;
    int *p;

    p = &a;

    printf("Address of p is: %p\n", p);
    printf("value at address p is: %p\n", sizeof(int));
    printf("Size of integer is %lu bytes\n", sizeof(int));
    printf("Address of p+1 is: %p\n", p+1);
    printf("value at address p+1 is: %p\n", sizeof(int));



}