#include <stdio.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <fenv.h>
// #pragma STDC FENV_ACCESS ON
// Some compilers require this for floating-point exception handling to work properly.

// tgamma() is a C math function that computes the Gamma function.
// The Gamma function extends the factorial to real numbers.

// Γ(n) = (n - 1)!  for positive integers.
// Here "!" means factorial, e.g. n! = n × (n-1) × (n-2) × ... × 1.

// How does this code work? Run it yourself and observe the results.
// Seeing is believing after all.

// Compile and run like this:
// gcc gamma_function.c -o gamma_function -lm
// -lm links the math library required for tgamma() and other math functions.

int main(void)
{
    printf("tgamma(10) = %f, 9!=%f\n", tgamma(10), 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9.0);
    printf("tgamma(0.5) = %f, sqrt(pi) = %f\n", tgamma(0.5), sqrt(acos(-1)));
 
    // special values
    printf("tgamma(+Inf) = %f\n", tgamma(INFINITY));
 
    // error handling
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("tgamma(-1) = %f\n", tgamma(-1));
    if (errno == ERANGE)
        perror("    errno == ERANGE");
    else
        if (errno == EDOM)   perror("    errno == EDOM");
    if (fetestexcept(FE_DIVBYZERO))
        puts("    FE_DIVBYZERO raised");
    else if (fetestexcept(FE_INVALID))
        puts("    FE_INVALID raised");
}
