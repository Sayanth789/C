#include <stdio.h>
#include <stdlib.h>


int main() {

    char characterName [] = "John";
    int characterAge = 35;



    printf("There once was a man named %s ...\n", characterName);
    printf("He was %d years old\n", characterAge);

    // can change or override the age 

    characterAge = 40;
    printf("He really liked his name as %s\n", characterName);
    printf("but he didn't like being at %d\n", characterAge);


    return 0;
}