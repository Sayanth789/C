// Function Pointers

/*
can be void (*pd) int -> void return type int argument.

char* (*pf)(int*) -> *pf - function pointer, char* -> return type and int* -> type of arg


*/

#include <math.h>
#include <stdio.h>
void add(int arg1, int arg2) {
    printf("Adding (%d, %d)  gives %d\n",arg1, arg2, arg1+arg2);
}

void main() {

    void (*pf)(int, int);
    pf = &add;
    printf("We're about to call someFunction() using a pointer!\n");
    (pf)(5, 4);
    printf("Wow that was cool. Back to main nowThis is from main!\n\n");

}