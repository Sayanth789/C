#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack* newStack(int capacity) {
    Stack* mystack = malloc(sizeof *mystack);
    if (!mystack) return NULL;
    init_stack(mystack, capacity);
    return mystack;
}

void init_stack(Stack* mystack, int capacity) {
    mystack->top = -1;
    mystack->capacity = capacity;
    mystack->data = malloc(capacity * sizeof(void*));

    mystack->push = push;
    mystack->pop = pop;
    mystack->display = display;
    mystack->peek = peek;
    mystack->isEmpty = isEmpty;
}

void push(Stack* mystack, void* item) {
    if (mystack->top + 1 >= mystack->capacity) {
        printf("Stack overflow\n");
        return;
    }
    mystack->data[++mystack->top] = item;
}

void* pop(Stack* mystack) {
    if (mystack->top < 0) {
        printf("Stack underflow\n");
        return NULL;
    }
    return mystack->data[mystack->top--];
}

void* peek(Stack* mystack) {
    if (mystack->top < 0)
        return NULL;
    return mystack->data[mystack->top];
}

bool isEmpty(Stack* mystack) {
    return mystack->top < 0;
}

void display(Stack* mystack) {
    for (int i = mystack->top; i >= 0; i--) {
        printf("%p ", mystack->data[i]);  // generic-safe
    }
    printf("\n");
}

void freeStack(Stack* mystack) {
    free(mystack->data);
    free(mystack);
}
