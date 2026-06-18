/*
What is the range of the floating point types on my machine?
*/

#include <stdio.h>
// The dedicated header for float
#include <float.h>

int main() {
    printf("=============================================================================\n");
    printf("                                     FLOATING-POINT SPECIFICATION             \n");
    printf("=============================================================================\n");

    // Float Specification 

    printf("--- FLOAT   (Single Precision)   -----\n");
    printf("Storage Size  :   %lu bytes\n", sizeof(float));
    printf("Min Positive  :   %e\n", FLT_MIN);
    printf("Max value     :   %e\n", FLT_MAX);
    printf("Precision     : %d decimal digits\n\n", FLT_DIG);

    // 2 Double Specification 

    printf("---- Double (Double Precision)   ----\n");
    printf("Storage Size  : %lu bytes\n", sizeof(double));
    printf("Min Positive   : %e\n", DBL_MIN);
    printf("Max Value    :%e\n", DBL_MAX);
    printf("Precision   : %d decimal digits\n\n", DBL_DIG);

    // 3 Long Double Specification 
    printf("--- Long Double (Extends Precision)    ----\n");
    printf("Storage Size   : %lu bytes\n", sizeof(long double));
    printf("Min Positive    :   %Le\n", LDBL_MIN);
    printf("Max Value      :    %Le\n", LDBL_MAX);
    printf("Precision      : %d decimal digits\n", LDBL_DIG);

    return 0;
}