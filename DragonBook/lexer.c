/*
Lexical Analyzer : Is the first stage of compiler.
Its job is to read raw source code and break it into meaningful pieces called tokens.

An eg: 
int x = 10 + 20;

The lexer turns this into a stream of tokens 

[int] [identifier:x] [=] [number:10] [+] [number:20] [;]

What is a lexer: 
The lexrt classifies  pieces of text: gives them a type 
Sometimes it also stores a value (called lexeme or attribute).

What a lexer do:

It removes whitespaces and comments
Groups characters into tokens 
Identifies 
* keywords  
*  identifiers 
* numbers 
* operators 


*/ 


// Lexer

#include <stdio.h>
#include <ctype.h>
#include <string.h>


#define NUM 256 
#define ID 257 

int lineno = 1;
int tokenval = 0;

char lexeme[100];   // to store identifier names 

int lexan() {
    int t;

    // skip whitespaces 
    while (1) {
        t = getchar();

        if (t == ' ' || t == '\t')
            continue;
        else if (t == '\n') {
            lineno++;
            continue;
        
        }
            
        else 
            break;
    }

    // Handle numbers 
    if (isdigit(t)) {
        tokenval = 0;
        do {

            tokenval = tokenval * 10 + (t - '0');
            t = getchar();
        }
        while (isdigit(t));

        ungetc(t, stdin);  // put back extra character 
        return NUM;        
    }

    // Handle Identifiers 
    if (isalpha(t)) {
        int i = 0;

        do {
            lexeme[i++] = t;
            t = getchar();
        } while (isalnum(t));

        lexeme[i] = '\0';
        ungetc(t, stdin);


        return ID;
    }

    // End of file 
    if(t == EOF) {
        return EOF;
    }

    // otherwise return character itself (operator , punctuation).

    return t;
}

int main() {

    int token;

    while ((token = lexan()) != EOF) 
    {

        switch(token) {
            case NUM:
                printf("NUM: %d\n", tokenval);
                break;
            case ID:
                printf("ID : %s\n", lexeme);
                break;    
            default:
                printf("TOKEN: %c\n", token);    
        }
    }
    return 0;
}
