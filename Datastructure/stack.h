#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* Forward declaration */
typedef struct Stack Stack;

struct Stack {
    int top;
    int capacity;
    void **data;

    void  (*push)(Stack*, void*);
    void* (*pop)(Stack*);
    void  (*display)(Stack*);
    void* (*peek)(Stack*);
    bool  (*isEmpty)(Stack*);
};

/* Stack creation & initialization */
Stack* newStack(int capacity);
void   init_stack(Stack* stack, int capacity);

/* Stack operations */
void   push(Stack* stack, void* item);
void*  pop(Stack* stack);
void   display(Stack* stack);
void*  peek(Stack* stack);
bool   isEmpty(Stack* stack);

#endif /* STACK_H */
