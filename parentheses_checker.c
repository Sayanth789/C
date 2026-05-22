/* 
scan from left to right -> if opening symobl add it
to a list

If closing symbol remove last opening symbol in list.

We use stack to store the opened parenthesis as it is FIFO
*/

#include <stdio.h>
#include <string.h>

#define MAX 100 

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top]= c;
}

char pop() {
    if (top == -1){
        return '\0';


    }
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '{' && close == '}') ||
            (open == '(' && close == ')') ||
            (open == '[' && close == ']');
}

int isBalanced(char expr[]) {
    for (int i=0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        // Opening brackets 
        if (ch == '{' || ch == '(' || ch =='[') {
            push(ch);
        }

        // closing brackets 
        else if (ch == '}' || ch == ')' || ch == ']') {
            char topChar = pop();

            if (!isMatching(topChar, ch)) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char expr[MAX];

    printf("Enter expression: ");
    fgets(expr, MAX, stdin);

    if (isBalanced(expr)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced \n");

    }

    return 0;
}