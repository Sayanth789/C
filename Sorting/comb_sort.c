// Comb sort works to sort an array.

#include <stdio.h>
#include <stdlib.h>

// Function to find the new gap between elements
int newgap(int gap) {
    gap = (gap * 10) / 13; // typical shrink factor 1.3
    if (gap < 1)
        gap = 1;
    return gap;
}

// Comb sort
void combsort(int a[], int aSize) {
    int gap = aSize;
    int i, temp;
    int swapped;

    for(;;) {
        gap = newgap(gap);
        swapped = 0;

        for (i = 0; i < aSize - gap; i++) {
            int j = i + gap;
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swapped = 1;
            }
        }

        if (gap == 1 && !swapped)
            break;
    }
}

// Print array
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n;
    int *a;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Input element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("\nUnsorted list: ");
    printArray(a, n);

    combsort(a, n);

    printf("Sorted list: ");
    printArray(a, n);

    free(a);
    return 0;
}
