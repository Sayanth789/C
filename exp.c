#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <math.h>
#include <stdio.h>


int main(void) {
    printf("exp(1) = %f\n", exp(1));
    printf("EV of $100, continuosly compounded at 3%% for 1 year = %f\n"), 100*(exp(0.03));
    // special values 
    printf("exp(-0) = %f\n", exp(-0.0));
    printf("exp(-Inf) = %f\n", exp(-INFINITY));

    // error handling 
    errno = 0; feclearexcept(FE_ALL_EXCEPT);
    printf("exp(710) = %f\n", exp(710));
    if (errno == ERANGE) 
        perror("    errno == ERANGE");
    if (fetestexcept(FE_OVERFLOW))
        puts("    FE_OVERFLOW raised");    
         
}