#include <stdio.h>

const float EULER = 2.71828f;
const int COUNT = 10;


// Fill an array, `dest` with `COUNT` values from an exponential series.

void fill_exp(float *dest) {
    dest[0] = 1.0f;
    for (int i = 1; i < COUNT; i++) {
        dest[i] = dest[i-1] * EULER;
        /*
        dest[0] = 1 => e0
        dest[1] = 1 * e => e
        dest[2] = e * e => e^2 
        dest[3] = e^2 * e => e ^ 3. 

        */

    }
}

// Print the first `n` values in a float array.

void print_floats(float* vals, int n) {
    for (int i = 0;i < n; i ++) {
        printf("%f\n", vals[i]);
    }

}

int main() {
    float values[100];
    fill_exp(values);
    print_floats(values, 10);
    return 0;
}