// pointers as function arguments or call by referecne.

#include <stdio.h>

void Increment(int *p) {
    /*
    a = a + 1;
    // this is call by value and can't make the desired result.

    
    */

    // but this does -- call by reference 
    // it save lot of memory space.
    *p = (*p) + 1;
  


    // printf("The address of variable a in increment = %p\n", &a);


}

int main() {

    int a;

    a = 10;

    Increment(&a);
    // printf("a = %d", a);
    // printf("The address of variable a in main = %p\n", &a);
    printf("a = %d\n", a);

}

// local variables goes to stack 

/* 

+------------------+
|      Stack       |  ← local variables, function calls
+------------------+
|       Heap       |  ← malloc / dynamic memory
+------------------+
|   BSS Segment    |  ← uninitialized globals
+------------------+
|   Data Segment   |  ← initialized globals
+------------------+
|    Text Segment  |  ← program code
+------------------+


*/