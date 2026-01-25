#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

// Delete the first node of a linked list
void delete_first_node(struct node **head) {
    struct node *tmp;

    if (head == NULL || *head == NULL)
        return;

    tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

// Print the linked list
void print_list(struct node *head) {
    printf("H->");

    while (head) {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("||\n");
}

// Insert an element at the front of the list
void insert_front(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Failed to insert element. Out of memory.\n");
        return;
    }

    new_node->val = value;
    new_node->next = *head;
    *head = new_node;
}

int main(void) {
    int count = 0, i, val;
    struct node *head = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter the %dth element: ", i);
        scanf("%d", &val);
        insert_front(&head, val);
    }

    printf("Initial Linked List:\n");
    print_list(head);

    delete_first_node(&head);

    printf("Linked list after first node deleted:\n");
    print_list(head);

    return 0;
}
