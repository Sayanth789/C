/* This is level order traversal */


#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

struct  Node* GetNewNode(char data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

// Queue 
struct Queue {
    int front;
    int rear;

    struct Node* items[100];
};

void Enqueue(struct Queue* q, struct Node* node) {
    q->items[++q->rear] = node;
}

void Dequeue(struct Queue* q) {
     q->front++;
}

struct Node* Front(struct Queue* q) {
    return q->items[q->front];
}

int IsEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void LevelOrder(struct Node *root) {
    if (root == NULL)
        return;

    struct Queue q;
    
    q.front = 0;
    q.rear = -1;

    Enqueue(&q, root);
    while (!IsEmpty(&q)) {
        struct Node* current = Front(&q);

        printf("%c ", current->data);

        if (current->left != NULL)
            Enqueue(&q, current->left);
        if (current->right != NULL)
            Enqueue(&q, current->right);
        Dequeue(&q);        
    }
}



int main() {
    struct Node* root = GetNewNode('A');
    

    /*
             A
           /   \
          B     C
         / \   / \
        D   E F   G
    */
   
    root->left = GetNewNode('B');
    root->right = GetNewNode('C');

    root->left->left = GetNewNode('D');
    root->left->right = GetNewNode('E');

    root->right->left = GetNewNode('F');
    root->right->right = GetNewNode('G');

    printf("Level Order Traversal: \n");

    LevelOrder(root);
    printf("\n");
    return 0;

}

