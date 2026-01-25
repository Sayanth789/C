#include <stdio.h>
#include "stack.h"

int main(void) {
    Stack *s = newStack(5);

    if (!s) {
        printf("Failed to create stack\n");
        return 1;
    }

    int a = 10, b = 20, c = 30;

    s->push(s, &a);
    s->push(s, &b);
    s->push(s, &c);

    printf("Stack contents:\n");
    s->display(s);

    int *top = (int *)s->peek(s);
    if (top)
        printf("Top element: %d\n", *top);

    while (!s->isEmpty(s)) {
        int *val = (int *)s->pop(s);
        printf("Popped: %d\n", *val);
    }

    freeStack(s);
    return 0;
}
