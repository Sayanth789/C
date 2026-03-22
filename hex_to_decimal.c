#include <stdio.h>

int main()
{
    unsigned int hex;

    printf("Enter a hex number (example: FF or 0xFF): ");
    scanf("%x", &hex);

    printf("Decimal value: %u\n", hex);

    return 0;
}
