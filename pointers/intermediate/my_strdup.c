#include <stdio.h>
#include <stdlib.h>

char *my_strdup(char *s) {
    int len = 0;
    char *temp = s;

    while (*temp) {
        len++;
        temp++;

    }
    char *copy = malloc(len + 1);
    char *c = copy;

    while (*s) {
        *c = *s;
        c++;
        s++;
    }

    *c = '\0';
    return copy;
}

int main() {
    char s[] = "hi, this is a copy ? ";
    
    char *dup = my_strdup(s);

    printf("Duplicated string %s:\n", dup);

    free(dup);

    return 0;
}