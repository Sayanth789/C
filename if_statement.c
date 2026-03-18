#include <stdio.h>

int main() {

    int age;

    printf("\nEnter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("YOu are now signed in");
    }
    else if (age < 0) {
        printf("You are not even born yet..?");
    }
    else {
        printf("You are too young to be a memeber");
    }
}