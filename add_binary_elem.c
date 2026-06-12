/* 
From the problem add_binary_integers.
That asks to take array A and B with integer n, and return array C that  
add elements of A and B.

*/

#include <stdio.h>



void  add_binary_integers(int A[], int B[], int n) {
    int C[n+1];
    int carry = 0;
    for (int i=0; i< n; i++) {
        int sum = A[i] + B[i] + carry;
        C[i] = sum % 2;
        carry = sum / 2;

    }

    C[n] = carry;
   
}

int main() {
    int n = 4;

    int A[] = {1, 0, 1, 1};
    int B[] = {1, 1, 0, 0};

    int C[n + 1];

    add_binary_integers(A, B, n);

    printf("sum: ");
    for (int i=n; i >= 0; i--){
        printf("%d", C[i]);
        
    }
    printf("\n");

    return 0;

}