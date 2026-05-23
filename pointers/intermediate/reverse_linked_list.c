#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;

void Insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    struct Node* temp1 = head;

    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void Print() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Reverse() {
    struct Node *next, *prev, *current;
    current = head;
    prev = NULL;
    while (current != NULL) {

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;


    }
    head = prev;
}

int main() {
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(8);

    Print();
    Reverse();

    Print();

    return 0;
}