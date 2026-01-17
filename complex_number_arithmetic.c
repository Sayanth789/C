#include <stdio.h>
#include <complex.h>
#include <math.h>

int main(void) {
    // I*I
    double complex z1 = I * I;
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    // pow(I, 2)
    double complex z2 = cpow(I, 2);
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

    // Euler formula
    double PI = acos(-1);
    double complex z3 = cexp(I * PI);
    printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

    // Multiply conjugates
    double complex z4 = 1 + 2*I;
    double complex z5 = 1 - 2*I;
    double complex z6 = z4 * z5;
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z6), cimag(z6));

    return 0;
}
