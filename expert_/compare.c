#include <stdio.h>

int compare(char *s1, char *s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0') return 0;
        s1++;
        s2++;

    }
    return *s1 - *s2;


}

int main() {
    char s1[] = "cat";  // char *s1 = "cat";
    char s2[] = "car";
    int comp = compare(s1, s2);

    printf("%d\n", comp);
}