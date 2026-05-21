#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *result) {
    // Roman symbols and their values
    int values[] =    {1000, 900, 500, 400, 100, 90,  50, 40,  10, 9,   5, 4, 1};
    char *symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    result[0] = '\0'; // initialize empty string

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }
}

int main() {
    int num = 3749;
    char roman[20]; // enough space for the result
    intToRoman(num, roman);
    printf("Roman numeral: %s\n", roman);
    return 0;
}