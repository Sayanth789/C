/*
Write a program to read input text, and print each line of test precered by line no:
*/

#include <stdio.h>

#define  MAX_LINE  1014

int main() {
    char line[MAX_LINE];
    int lineno = 1;
    
    printf("Enter text (Ctrl + D / Ctrl+x to end):\n");

    while (fgets(line, MAX_LINE, stdin) != NULL) {
        printf("%d: %s", lineno, line);
        lineno++;
    }

    return 0;
}
