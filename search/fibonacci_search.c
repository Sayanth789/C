#include <stdio.h>

/* Utility function to find minimum of two integers */
int min(int x, int y) {
    return (x < y) ? x : y;
}

/* Fibonacci Search function */
int fibMonaccianSearch(int arr[], int x, int n) {
    int fibMMm2 = 0;   // (m-2)'th Fibonacci No.
    int fibMMm1 = 1;   // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1;  // m'th Fibonacci

    /* fibM is the smallest Fibonacci number >= n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);

        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else {
            return i;
        }
    }

    /* Compare last element */
    if (fibMMm1 && offset + 1 < n && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int main(void) {
    int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 85;

    printf("Found at index: %d\n", fibMonaccianSearch(arr, x, n));
    return 0;
}
