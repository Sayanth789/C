#include <stdio.h>

float power(float x, int y) {
    if (y == 0)
        return 1;

    float temp = power(x, y / 2);

    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

int main() {
    float x = 8;
    int y = 2;

    printf("%.6f\n", power(x, y));   // Output: 64.000000

    // Test negative exponent
    printf("%.6f\n", power(2, -3));  // Output: 0.125000

    return 0;
}
