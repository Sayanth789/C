#include <stdio.h>

/* Function prototypes */
int mergeSort(int a[], int lb, int ub);
int merge(int a[], int lb, int mid, int ub);

int main(void)
{
    int a[] = {8, 4, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    int noI = mergeSort(a, 0, n - 1);

    printf("Number of inversions are : %d\n", noI);

    return 0;
}

/* Recursive merge sort that returns inversion count */
int mergeSort(int a[], int lb, int ub)
{
    int count = 0;

    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        count += mergeSort(a, lb, mid);
        count += mergeSort(a, mid + 1, ub);
        count += merge(a, lb, mid, ub);
    }

    return count;
}

/* Merge two sorted halves and count inversions */
int merge(int a[], int lb, int mid, int ub)
{
    int count = 0;
    int i = lb, j = mid + 1, k = 0;

    /* Temporary array of correct size */
    int b[ub - lb + 1];

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    /* Copy remaining elements */
    while (i <= mid)
        b[k++] = a[i++];

    while (j <= ub)
        b[k++] = a[j++];

    /* Copy back to original array */
    for (i = lb, k = 0; i <= ub; i++, k++)
        a[i] = b[k];

    return count;
}
