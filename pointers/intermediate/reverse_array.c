/*
Here we use no indexing (as a strict restriction) only pointers. 
*/

#include <stdio.h>

int reverse(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    reverse(arr, 5);

    for (int i= 0; i < 5; i++) {
        printf("%d", arr[i]);
        printf("\n");
    }
}
