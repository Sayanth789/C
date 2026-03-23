#include <stdio.h>
/* 
we can use flag to make the code to do sorting in 
incresing or decresing order, say if falg is '1' do sorting in 
incresing order, else decresing.

*/


void BubbleSort(int *A, int n, int (*compare)(int, int)) {
    int i, j, temp;

    for (i = 0; i <n; i++) {
        for (j=0; j<n-1; j++) {
            if (compare(A[j],  A[j+1]) > 0) 
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }    
        }
    }
}

int main() {

    int i, A[] = {110, 105, 130, 121, 132, 136};

    BubbleSort(A, 6 , compare);
    for(i = 0; i<6; i++) printf("%d\t", A[i]);
 

}