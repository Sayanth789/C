#include <stdio.h>

// int main() {
//     int arr[3] = {1,2,3};
//     printf("%p\n", arr);
//     printf("%p\n", &arr[0]);
//     printf("%lu", sizeof(arr));
//     return 0;
// }

int main() {
    int arr[3] = {10, 20, 30};
    
    printf("%p\n", arr);
    printf("%p\n", arr + 1);  // 4 + arr
    printf("%d\n", *(arr + 1)); // = 20

    return 0;
}