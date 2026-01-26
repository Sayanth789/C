#include <stdlib.h>
#include "queue.h"

/* Initialize queue */
struct queue *queue_init(unsigned int max_size) {
    struct queue *queue = malloc(sizeof *queue);

    if (!queue)
        return NULL;

    queue->max_size = max_size;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

/* Destroy queue */
void queue_destroy(struct queue *queue, fn_node_data_destroy fn) {
    struct queue_node *current = queue->head;
    struct queue_node *next;

    while (current) {
        next = current->next;
        queue_node_destroy(current, fn);
        current = next;
    }

    free(queue);
}

/* Initialize node */
struct queue_node *queue_node_init(void *data, fn_node_data_init fn) {
    struct queue_node *node = malloc(sizeof *node);

    if (!node)
        return NULL;

    node->data = (fn) ? fn(data) : data;
    node->next = NULL;

    return node;
}

/* Destroy node */
void queue_node_destroy(struct queue_node *node, fn_node_data_destroy fn) {
    if (fn)
        fn(node->data);

    free(node);
}

/* Enqueue */
int queue_enqueue(struct queue *queue, struct queue_node *node) {
    if (queue->size == queue->max_size)
        return -1;  // queue full

    if (!queue->head) {
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    queue->size++;
    return 0;
}

/* Dequeue */
struct queue_node *queue_dequeue(struct queue *queue) {
    if (queue->size == 0)
        return NULL;

    struct queue_node *node = queue->head;
    queue->head = node->next;

    if (!queue->head)
        queue->tail = NULL;

    queue->size--;
    node->next = NULL;

    return node;
}
