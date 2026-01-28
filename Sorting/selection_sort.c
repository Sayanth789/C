#include <stdio.h>

// Selection Sort function
void SelectionSort(int A[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        int Imin = i;

        for (j = i + 1; j < size; j++) {
            if (A[j] < A[Imin]) {
                Imin = j;
            }
        }

        int temp = A[Imin];
        A[Imin] = A[i];
        A[i] = temp;
    }
}

int main() {
    int num[10];
    int i;

    printf("Enter an array of size 10:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }

    SelectionSort(num, 10);

    printf("\nAfter Sorting:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t", num[i]);
    }
    printf("\n");

    return 0;
}
