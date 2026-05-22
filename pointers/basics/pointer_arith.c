#include <stdio.h>

int main() {
    // int arr[] = {10, 20, 30, 40};
    char *arr[] = {"big", "bang", "blast"};
    char **p = arr;

    printf("%s\n", *p);
    printf("%s\n", *(p + 1));
    printf("%s\n", *(p + 2));


    return 0;

}