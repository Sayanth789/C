/* 
Given an unsorted array A, reorder it's elements such that A[0] < A[1] > A[2] < A[3]
Do it in O(n) time with O(1) space.


To do this, we do single pass through the array with clever use 
of comparison and swaps.
*/

#include <stdio.h>


void WiggleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 != 0 && arr[i] < arr[i+1])) {
            // swap arr[i] and arr[i+1] if wiggle condition is violated.
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }
    // printf("\n");
}

int main() {
    int arr[] = {3, 1, 4, 2, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array: [");
    printArray(arr, n);
    printf("]");

    printf("\n");


    WiggleSort(arr, n);
    
    printf("Wiggle Sorted Array: [");
    printArray(arr, n);
    printf("]");
    return 0;
}