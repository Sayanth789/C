#include <stdio.h>
#include <stdlib.h>


double cube(double num) {
    return num * num * num;
    // anything outisde the return statement is not executed.
    printf("This is not going to execute");


}

int main() {

    printf("The cube is %f", cube(3));
}

// always put a space before the %c otherwise it won't work.