#include <stdio.h>
/*
int main() {
    char C[20];
    C[0] = 'J';
    C[1] = 'O';
    C[2] = 'H';
    C[3] = 'N';
    // without the next line it will make a mess.
    C[4] = '\0';   

    printf("%s", C);

}


*/


/* string is a group of characters.

sizeof array >> # characters in string + 1.

Rule of  C strung must be null terminated as \0;

() Arrays and ponters are different types used in a similar manner.
()  Arrays always passed to function by reference.

*/


void print(char* C) {

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
     char C[20] = "This is good";
     print(C);
}