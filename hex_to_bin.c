#include <stdio.h>

void print_bits(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & i);

        if (i % 4 == 0) {
            printf(" "); // this is for readablity 

        }

        // printf("\n");
    }
}


int main() {

    unsigned int num;

    printf("Enter a hex number : ");
    scanf("%x", &num);


    printf("Binary representation: \n");
    print_bits(num);



    return 0;



}