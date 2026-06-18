/*
Write a program that read C source code from the stand input and ensure that the braces are paired correctly. 
Note : We need not to worry about braces that appear within comments, string literals, or character constants.

*/

/*
To track whether braces ({ and }) are paired correctly in a source file, we can use a counter approach.
Since braces must nesting-match, every closing brace } must pair with the most recent unmatched opening brace 
{. If our brace count ever drops below zero, or if it doesn't end at exactly zero, the braces are unmatched.

<> <> <> <> <> <> <> 
As per  instructions, the program safely ignores any braces found inside:

    Single-line comments (// ...)

//    Multi-line comments (/* ... */ //)

    //String literals ("...")

    // Character constants ('...')


//                  

#include <stdio.h>
#include <stdbool.h>

int main() {
    int ch;
    int next_ch;
    int brace_count = 0;

    // Tracking line numbers can help pinpoint where an error becomes visible 
    int line_number = 1;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            line_number++;
            continue;
        }

        // 1. Handle Single-line Comments 
        if (ch == '/') {
            next_ch = getchar();
            if (next_ch == '/')  {
                // Skip everything until the end of the line 
                while ((ch = getchar()) != EOF && ch != '\n');
                if (ch == '\n') line_number++;
                continue;
            } else if (next_ch == '*') {
                // 2 Handle Multiline comments (/* ...  */)
                bool in_comment = true;
                while (in_comment && (ch = getchar()) != EOF) {
                    if (ch == '\n') {
                        line_number++;
                    } else if (ch == '*') {
                        next_ch = getchar();
                        if (next_ch == '/') {
                            in_comment = false;
                        }
                        else {
                            ungetc(next_ch, stdin);
                        }
                    }
                }
                continue;
            } else {
                // Not a comment put the character back 
                ungetc(next_ch, stdin);
            }
        }
        // Handle String Literals (" ... ")
        if (ch == '"') {
            while ((ch = getchar()) != EOF && ch != '"') {
                if (ch == '\n') line_number++;
                if (ch == '\\') {
                    // skip escaped characters like \" or 
                    // ch = getchar();
                    if (ch == '\n') line_number++;
                    
                }
            }
            continue;
        }
        
        // 4 Handle Character Constants ('...')
        if (ch == '\'') {
            while ((ch = getchar()) != EOF && ch != '\'') {
                if (ch == '\n') line_number++;
                if (ch == '\\') {
                    // Skip escaped character like \'
                    ch = getchar();
                    if (ch == '\n') line_number++;
                }
            }
            continue;
        }
        // 5 Skip Active Brace 
        if (ch == '{') {
           brace_count++; 
        }
        else if (ch == '}') {
            brace_count--;
            if (brace_count < 0) {
                printf("Error: Unmatched closing brace '}' found near line %d.\n", line_number);
                return 1;
            }
        }
    }
    // Final evalution after reacing End-Of-File (EOF)

    if (brace_count == 0) {
        printf("Suceess: All braces are correctly paired.\n");
        return 0;
    }
    else {
        printf("Error: Missing %d closing brace(s) by the end of the file.\n", brace_count);
        return 1;
    }
} 
