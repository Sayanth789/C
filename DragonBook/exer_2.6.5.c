// Extend the lexical anlyzer to recognize the relational operators 
//  < , <= , == , != , >= , >.



#include <stdio.h>
#include <ctype.h>

#define NUM 256 
#define ID 257 

int lineno  = 1;
int tokenval = 0;

char lexeme[100];

int lexan() {
    int t;

    while (1) {
        t = getchar();

        // skip whitespace
        if (t == ' ' || t == '\t') {
            continue;
        }
        else if (t == '\n') {
            lineno++;
            continue;
        }

        // handle comments or division
        else if (t == '/') {
            int next = getchar();

            // single-line comment //
            if (next == '/') {
                while ((t = getchar()) != '\n' && t != EOF);
                if (t == '\n') lineno++;
                continue;
            }

            // multi-line comment /* */
            else if (next == '*') {
                int prev = 0;
                while ((t = getchar()) != EOF) {
                    if (t == '\n') lineno++;

                    if (prev == '*' && t == '/') {
                        break;
                    }
                    prev = t;
                }

                if (t == EOF) {
                    printf("Error: Unterminated comment\n");
                    return EOF;
                }
                continue;
            }

            // division operator
            else {
                ungetc(next, stdin);
                return '/';
            }
        }

        else {
            break;
        }
    }

    // numbers
    if (isdigit(t)) {
        tokenval = 0;
        do {
            tokenval = tokenval * 10 + (t - '0');
            t = getchar();
        } while (isdigit(t));

        ungetc(t, stdin);
        return NUM;
    }

    // identifiers
    if (isalpha(t)) {
        int i = 0;
        do {
            if (i < 99)   // prevent overflow
                lexeme[i++] = t;
            t = getchar();
        } while (isalnum(t));

        lexeme[i] = '\0';
        ungetc(t, stdin);
        return ID;
    }

    if (t == EOF) {
        return EOF;
    }

    return t;
}

int main() {
    int token;

    while ((token = lexan()) != EOF) {
        switch (token) {
            case NUM:
                printf("NUM: %d\n", tokenval);
                break;

            case ID:
                printf("ID: %s\n", lexeme);
                break;

            default:
                printf("TOKEN: %c\n", token);
                break;
        }
    }

    return 0;
}