#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("table.txt", "w");   // open file for writing

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            fprintf(file, "%4d", i * j);   // write to file
        }
        fprintf(file, "\n");   // new line after each row
    }

    fclose(file);  // close file

    printf("Multiplication table saved to table.txt\n");

    return 0;
}