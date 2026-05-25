/* Write a program to  translate C declaration into English. */
/*
Here's the design. The main data structure is a stack, on which we store tokens that we have
read, while we are reading forward to the identifier. Then we can look at the next token to
the right by reading it, and the next token to the left by popping it off the stack. The data
structure look like this:
*/
/*

struct token {char type; char string [MAXTOKENLEN]; };
// holds tokens we read before reaching first identifier. 

struct token stack[MAXTOKENLENS];

//  holds the token just read. 
struct token this;

// Utility routines 

classify_string(int type) {
    for (int i=0; i < MAXLENGTHS; i++) {
        return stack.type;
    }
}

classify_string
    look at the current token and return a value of "type" "qualifier"
    or "identifier" in this.type


gettoken(int token) {
    for(int i=0; i < MAXLENGTHS; i++) {
        if (stack.type == str) classify_string();
        if (stack.type == token) return NULL;
    }
}

gettoken:
    read the next token into this.string
    if it is alphanumeric, classify_string
    this.type = the token itself; terminate this.string with a nul.
    
read_to_first_identifier:
    gettoken and push it onto the stack until te first identifier is read.
    Print "identifier is", this.string
    gettoken

// parsing routines ....

int deal_with_function_args(int fun_args) {
    if (func_args == '(') {
        return "function returning";
    }
}

deal_with_function_args 
    read past closing ')' print out "function returning"

void deal_with_arrays(char input) {
    if (input == "{size}") 
        return input
}

deal_with_arrays 
    while you've got "{size}" print it out and read past it

void deal_with_any_pointers(int pointer) {
    while (pointer = "*") {
        stack.pop(pointer);
        printf("pointer to");

    }
}    

deal_with_any_pointers 
    while you'e got "*" on the stack print "pointer to" and pop it.

void deal_with_declarator(int type) {
    for (int i =0; i != '\n'; i++) {
        if (this.type == '[') deal_with_arrays();
        else if  (this.type == '(') {deal_with_function_args};
        else deal_with_any_pointers(); 


    }

    if (this.type ==  '(') 
    { 
        this.pop[type];
        gettoken() 
    
    }
    
}

deal_with_declarator
    if this.type is '[' deal_with_arrays
    if this.type is '(' deal_with_function_args
    deal_with_any_pointers
    while there's stuff on the stack
    if it's a '(' 
    pop it and gettoken; it should be the closing ')'
    deal_with_declarator 
    
    else pop it and print int

main
    read_to_first_identifier 
    deal_with_declarator    
*/




//  ***********************************************************************************************************************

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
char prevtoken[MAXTOKEN];

int gettoken(void);
void parse_declarator(void);
void parse_direct_declarator(void);

int gettoken(void) {
    int c;
    char *p = token;

    while ((c = getchar())== ' ' || c == '\t')
        ;
    if (c == EOF) {
        return EOF;
    }
    if (c == '(') {
        if ((c = getchar()) == ')') {
            strcpy(token, "()");
            tokentype = PARENS;
            return tokentype;
        } else {
            ungetc(c, stdin);
            strcpy(token, "(");
            tokentype = '(';
            return tokentype;
        }
    }    
    if (c == '[') {
        *p++ = c;
        while ((c = getchar()) != ']') 
            *p++ = c;
        *p++ = ']';    
        *p = '\0';
            tokentype = BRACKETS;
            return tokentype;
    }
    if (isalpha(c)) {
        *p++ = c;
        while (isalnum(c = getchar()))
            *p++ = c;
        *p = '\0';    
        ungetc(c, stdin);
        tokentype = NAME;
        return tokentype;
    }

    tokentype = c;
    token[0] = c;
    token[1] = '\0';

    return tokentype;
}

void parse_declarator(void) {
    int ns;

    for (ns = 0; tokentype == '*'; ns++) {
        gettoken();
    }

    parse_direct_declarator();

    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

void parse_direct_declarator(void) {
    if (tokentype == '(') {
        gettoken();
        parse_declarator();
        if (tokentype != ')') 
            printf("error: missing )\n");
    } else if (tokentype == NAME) {
        strcpy(name, token);
    }

    while (1){
        gettoken();

        if (tokentype == PARENS)
            strcat(out, " function returning");
        else if (tokentype == BRACKETS) {
            strcat(out, "array");
            strcat(out, token);
            strcat(out, " of");

        }   
        else {
            return;
        } 

    }
}
int main() {
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';

        gettoken();
        parse_declarator();
        
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;

}