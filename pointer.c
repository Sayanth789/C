#include <stdio.h>

// we can pass the pointer as an argument to a function.

void printAge(int *pAge) {
    printf("You are: %d years old\n", *pAge);



}


int main() {


    int age = 21;
    int *pAge = &age;

    printf("Address of age: %p\n", &age);
    printf("value of pAge: %p\n", pAge);


    printf("value of the age: %d\n", age);
    printf("value at stored address: %d\n", *pAge);


    return 0;
}