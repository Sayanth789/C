#include <stdio.h>
#include <stdlib.h>


const float EULER = 2.71828f;
const int COUNT = 10;

// Allocate a new array conatining `COUNT` values from an  exponential series.
float *create_exp() {
    float *dest = malloc(COUNT *sizeof(float)); 
    dest[0] = 1.0f;
    for (int i = 1; i < COUNT; ++i) {
        dest[i] = dest[i - 1] * EULER;
    }
    return dest; 
} 

// Print the first `count` values in a float array.

void print_floats(float *vals, int count) {
    for (int i =0; i < count; i++) {
        printf("%f\n", vals[i]);
    }
}

int main() {
    float *values = create_exp();
    print_floats(values, 10);
    free(values);
    return 0;
}