/*
write a program that read input lines one by one until end of the 
file, determines the length of each line and then prints out only the 
longest that was found. To simplify assume no outout will be longer than 
1000 characters.

*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1001  // 1000 chars + null terminator

int main() {
    char line[MAXLINE];
    char longest[MAXLINE];
    
    int maxLen = 0;

    while (fgets(line, MAXLINE, stdin) != NULL) {
        int len = strlen(line);

        // remove newline if present
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        if (len > maxLen) {
            maxLen = len;
            strcpy(longest, line);
        }
    }

    if (maxLen > 0) {
        printf("%s\n", longest);
    }

    return 0;
}
