#include <stdio.h>

// swap utility
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// find index of smallest element recursively
int search_smallest(int V[], int n, int j, int smallest) {
    if (j >= n)
        return smallest;

    if (V[j] < V[smallest])
        smallest = j;

    return search_smallest(V, n, j + 1, smallest);
}

// recursive selection sort
void recursive_selection_sort(int V[], int n, int index) {
    if (index >= n - 1)
        return;

    int smallest = search_smallest(V, n, index + 1, index);

    if (smallest != index)
        swap(&V[index], &V[smallest]);

    recursive_selection_sort(V, n, index + 1);
}

// print array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    recursive_selection_sort(arr, n, 0);
    printArray(arr, n);

    return 0;
}
