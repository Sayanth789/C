#include <stdio.h>

int main() {

    // int numbers[2][3] = {
    //     {1, 2, 3}, {4, 5, 6}
    // };

   
    int numbers[0][0] = 1;
    int numbers[0][1] = 2;
    int numbers[0][2] = 3;
    int numbers[1][0] = 4;
    int numbers[1][1] = 5;
    int numbers[1][2] = 6;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <3; j++) {
            printf("%d", numbers[i][j]);
        }
        printf('\n');
    }


    return 0;

}