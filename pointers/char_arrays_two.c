#include <stdio.h>

void print(char* C) {

    // adding a const here as: const char* C will make the code read only.
    

    int i = 0;


    /*while (C[i] != '\0') {
    */

    // or can be written as 
    while (*C != '\0') {

        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main() {
    // this too will work, as the string get stored in the space for array
    char *C = "This will work,  you bet?";
    //  char C[20] = "This is good";
     print(C);
}

