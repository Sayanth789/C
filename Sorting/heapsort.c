#include <stdio.h>

int main(void)
{
    int heap[50], no, i, j, c, root, temp;

    printf("Enter number of elements: ");
    scanf("%d", &no);

    printf("Enter the elements:\n");
    for (i = 0; i < no; i++)
        scanf("%d", &heap[i]);

    // Build max heap
    for (i = 1; i < no; i++) {
        c = i;
        while (c > 0) {
            root = (c - 1) / 2;
            if (heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        }
    }

    printf("\nHeap array:\n");
    for (i = 0; i < no; i++)
        printf("%d ", heap[i]);

    // Heap sort
    for (j = no - 1; j > 0; j--) {
        temp = heap[0];
        heap[0] = heap[j];
        heap[j] = temp;

        root = 0;
        do {
            c = 2 * root + 1;

            if (c + 1 < j && heap[c] < heap[c + 1])
                c++;

            if (c < j && heap[root] < heap[c]) {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            } else {
                break;
            }
            root = c;
        } while (c < j);
    }

    printf("\nSorted array:\n");
    for (i = 0; i < no; i++)
        printf("%d ", heap[i]);

    printf("\n\nBest = Avg = Worst case = O(n log n)\n");

    return 0;
}
