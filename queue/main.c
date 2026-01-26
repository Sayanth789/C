#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* helper functions for int data */
void *int_init(void *data) {
    int *value = malloc(sizeof(int));
    *value = *(int *)data;
    return value;
}

void int_destroy(void *data) {
    free(data);
}

int main(void) {
    struct queue *q = queue_init(5);

    if (!q) {
        printf("Failed to create queue\n");
        return 1;
    }

    int a = 10, b = 20, c = 30;

    queue_enqueue(q, queue_node_init(&a, int_init));
    queue_enqueue(q, queue_node_init(&b, int_init));
    queue_enqueue(q, queue_node_init(&c, int_init));

    struct queue_node *node;

    while ((node = queue_dequeue(q)) != NULL) {
        printf("Dequeued: %d\n", *(int *)node->data);
        queue_node_destroy(node, int_destroy);
    }

    queue_destroy(q, int_destroy);

    return 0;
}
