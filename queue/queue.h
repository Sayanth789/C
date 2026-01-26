#ifndef QUEUE_H
#define QUEUE_H 

typedef void *(*fn_node_data_init)(void *);
typedef void (*fn_node_data_destroy)(void *);


struct queue_node {
    void *data;
    struct queue_node *next;
};


struct queue {
    unsigned int max_size;
    unsigned int size;

    struct queue_node *head;
    struct queue_node *tail;
};


struct queue *queue_init(unsigned int max_size);
void queue_destroy(struct queue *queue, fn_node_data_destroy fn);


struct  queue_node *queue_node_init(void *data, fn_node_data_init fn);
void queue_node_destroy(struct queue_node *node, fn_node_data_destroy fn);

int queue_enqueue(struct queue *queue, struct queue_node *node);
struct queue_node *queue_dequeue(struct queue *queue);

#endif