#include <stdio.h>
#define MAX 7

void pigeonhole_sort(int a[], int n);

int main(void) {
    int a[MAX], i, min, max;

    printf("Enter the elements:\n");
    for (i = 0; i < MAX; i++) {
        scanf("%d", &a[i]);
    }

    min = max = a[0];
    for (i = 1; i < MAX; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    pigeonhole_sort(a, MAX);

    printf("Sorted order:\n");
    for (i = 0; i < MAX; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

// Pigeonhole sort implementation
void pigeonhole_sort(int a[], int n) {
    int i, j;
    int min = a[0], max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    int size = max - min + 1;
    int holes[size];

    for (i = 0; i < size; i++)
        holes[i] = 0;

    for (i = 0; i < n; i++)
        holes[a[i] - min]++;

    for (i = 0, j = 0; i < size; i++) {
        while (holes[i]-- > 0) {
            a[j++] = i + min;
        }
    }
}
