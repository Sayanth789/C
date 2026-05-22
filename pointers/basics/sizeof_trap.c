#include <stdio.h>

int main() {
    int arr[5];

    int *p = arr;

    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(p));

    return 0;
}