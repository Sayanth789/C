/* Simulation of LL */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


int main() {
    struct Node *head = NULL;

    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    head = n1;

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;

    }

    free(n1);
    free(n2);
    free(n3);

}