#include <stdio.h>

int main() {
    int array[100], search, c, n;


    printf("Enter the number of elements in array\n");
    scanf("%d", &n);

    printf("Enter %d integer(s)\n", n);

    for (c = 0; c < n; c++) 
        scanf("%d", &array[c]); // enter each of the elements in the array.
    
    printf("Enter a number to search\n");
    scanf("%d", &search);     // Enter the elements to be searched.

    for (c = 0; c < n; c++) {
        if (array[c] == search)   // if requied element is found.
        {
            printf("%d is present at locatiion %d.\n", search, c+1);
            break;
        }
    }
    if (c == n) {
        printf("%d isn't present in the array.\n", search);

        return 0;
    }
}