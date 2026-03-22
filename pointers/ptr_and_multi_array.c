/*
Think of them as array of arrays.

*) Collection of arrays.

<> int B[2][3] is represented in memory as 
B[0][0], B[0][1], B[0][2],  and B[1][0], B[1][1], B[1][2]


for this 
print(B) , print *B. and print B[0] all output 400 as it stores or point to the
first 1D array.
also this too:
print &B[0][0] -> 400.

*/

#include <stdio.h>

int main() {
    int B[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i=0; i<2; i++) 
        for (int j=0; j<3; j++)

            printf("%p -> %d\n",&B[i][j], B[i][j]);
}
