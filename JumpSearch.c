#include <stdio.h>
#include <math.h>

static int min(int a, int b) {
    return (a < b) ? a : b;
}

int jumpSearch(int arr[], int n, int x) {
    if (n <= 0)
        return -1;

    int step = (int)sqrt(n);
    int prev = 0;

    /* Find the block where element may be present */
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += (int)sqrt(n);

        if (prev >= n)
            return -1;
    }

    /* Linear search within the block */
    while (arr[prev] < x) {
        prev++;

        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;

    return -1;
}

/* Driver program */
int main(void) {
    int arr[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 13;
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = jumpSearch(arr, n, x);

    printf("Number %d is at Index %d\n", x, index);
    return 0;
}
