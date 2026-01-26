#include <stdio.h>
#include <stdlib.h>

// A linked list (LL) node to store a queue entry.
struct QNode {
    int key;
    struct QNode* next;
};

// The queue: front stores front node, rear stores las node
struct Queue {
    struct QNode *front, *rear;
};

// Create a new node
struct QNode* newNode(int k) {
    struct QNode* temp = malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// Create an empty queue
struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Add an element to the queue
void enQueue(struct Queue* q, int k) {
    struct QNode* temp = newNode(k);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Remove an element from the queue
void deQueue(struct Queue* q) {
    if (q->front == NULL)
        return;

    struct QNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Driver program
int main() {
    struct Queue* q = createQueue();

    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);

    if (q->front)
        printf("Queue Front : %d\n", q->front->key);
    if (q->rear)
        printf("Queue Rear  : %d\n", q->rear->key);

    return 0;
}
