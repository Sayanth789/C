#include <stdio.h>

int main() {

    int C[3][2][2] = {{{2, 5}, {7,9}},
                        {{3, 4}, {6, 1}},
                        {{0, 8}, {11, 14}}};

    printf("%d %d %d\n", C, *C, C[0], &C[0][0]);
    printf("%d\n", *(C[0][0]+1));  // 5

    printf("%d\n", *(C[1][0]+1));  // 4?

    printf("%d\n", *(C[2][1]+1));  // 14

    printf("%d\n", *(C[2][0]+1));  /// yeah 8

    printf("%d\n", *(C[1][0]));




}
