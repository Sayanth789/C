/*
This is a mini vector using realloc()
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 0;

    for (int i = 0; i < 5; i++) {
        size++;

        arr = realloc(arr, size * sizeof(int));

        arr[size - 1] = i * 10;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    free(arr);
}