#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr)/sizeof(arr[0]);

    int *p = arr;

    for (int i = 0; i < size; i++ ) {

        printf("%d\n", *p);
        p++;

    }

   

    return 0;
}