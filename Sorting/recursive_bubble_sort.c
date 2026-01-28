#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSort(int V[], int vt, int pos, int nBubble, int change) {

    // All passes completed
    if (nBubble == vt - 1)
        return;

    // End of one pass
    if (pos == vt - 1 - nBubble) {
        if (change > 0) {
            bubbleSort(V, vt, 0, nBubble + 1, 0);
        }
        return;
    }

    if (V[pos] > V[pos + 1]) {
        swap(&V[pos], &V[pos + 1]);
        change++;
    }

    bubbleSort(V, vt, pos + 1, nBubble, change);
}

int main() {
    int arr[] = {46, 24, 33, 10, 2, 81, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n, 0, 0, 0);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("\n");

    return 0;
}
