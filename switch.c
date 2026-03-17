#include <stdio.h>
#include <stdlib.h>

int main() {

    char grade = 'C';
    switch(grade) {
        case 'A' :
            printf("You did a great job!");
            break;
        case 'B' :
            printf("Youd did alright");
            break;
        case 'C' :
            printf("You did bad");     
            break;   
        case 'F':
            printf("You Failed!");    
            break;
    }


    return 0;
}