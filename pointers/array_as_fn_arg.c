#include <stdio.h>

int sumOfElements(int A[], int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        sum += A[i];



    }
    return sum;


}


int main() {

    int A[] = {2, 4, 6, 8, 10};
    int size = sizeof(A)/sizeof(A[0]);
    int total = sumOfElements(A, size);
    printf("Sum of elements = %d\n", total);
}

/* 
When an array is passed to a function, it decays into a pointer to its first element.
The function receives a copy of that pointer.
Therefore the function can modify the original array elements.

so the arg: sumOfElements(int A[]) will interpretted as  sumOfElements(int *A) by 
the compiler.


<> <> <> 
*/

