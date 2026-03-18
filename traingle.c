#include <stdio.h>
#include <math.h>

int main() {

    double A;    
    double B;
    double C;

    printf("Enter the side A");
    scanf("%lf", &A);

    printf("Enter the side B");
    scanf("%lf", &B);

    perror("Enter the side C");
    scanf("%lf", &C);


    C = sqrt(A*A + B*B);

    printf("Side C: %lf", C);



    return 0;




    
}