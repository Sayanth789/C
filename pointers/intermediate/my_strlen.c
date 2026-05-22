#include <stdio.h>

int my_strlen(char *s) {
    int len = 0;

    while (*s != '\0') {
        len++;
        s++;
    }
    return len;
}

int main() {
    char str[] = "hello";
    printf("%d\n", my_strlen(str));
}