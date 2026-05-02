#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const float EULER = 2.71828f;
const int COUNT = 10;

// Allocate a new array containing `COUNT` values from an exponential series.
float* create_exp() {
    float* dest = malloc(COUNT * sizeof(float));  // New!
    dest[0] = 1.0f;
    for (int i = 1; i < COUNT; ++i) {
        dest[i] = dest[i - 1] * EULER;
    }
    return dest;
}

// Print the first `count` values in a float array.
void print_floats(float *vals, int count) {
    for (int i=0; i < count; i++) {
        printf("%f\n", vals[i]);
    }

    // Let's check what's nearby 
    char *ptr = (char *)vals;
    for (int j=0; j < 100; ++j) {
        char *byte = ptr - j;
        printf("%p: %d %c\n", byte, *byte, *byte);
    } 
}

// Generate a secret 
char *gen_secret() {
    char *secret = malloc(16);
    strcpy(secret, "seekrit!");
    return secret;
}

int main() {
    char *password = gen_secret();
    float *values = create_exp();

    print_floats(values, 10);

    free(values);
    free(password);
    return 0;
}


/*
$ gcc -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -std=c17 -g -fsanitize=address -fsanitize=undefined cache_mem_bug.c -o cmb

*/
