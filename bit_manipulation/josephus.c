#include <stdio.h>
#include <limits.h>

unsigned josephus(unsigned n) {
    if (n == 0)
        return 0;

    unsigned mask = 1u << (sizeof(unsigned) * CHAR_BIT - 1);

    while ((n & mask) == 0)
        mask >>= 1;

    n ^= mask;
    n <<= 1;
    n += 1;

    return n;
}

int main(void) {
    unsigned n;

    printf("Enter n: ");
    scanf("%u", &n);

    printf("Josephus survivor: %u\n", josephus(n));
    return 0;
}
