#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[50];
    char phone[50];
    struct Contact *next;
 
} Contact;

Contact *head = NULL;

//  -----------  CREATING NODE -------------

Contact *createContact() {
    Contact *newNode = (Contact*)malloc(sizeof(Contact));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    printf("Enter Name: ");
    scanf("% 49[^\n]", &newNode->name);

    printf("Enter Phone: ");
    scanf(" %14s", newNode->phone);

    newNode->next = NULL;

    return newNode;

}

//  ADD Contact 

void addContact() {
    Contact *newNode = createContact();
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;

    } else {
        Contact *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Contact added!\n");
}

// Display Contacts 

void displayContacts() {
    if (head == NULL) {
        printf("No contact found\n");
        return;
    }

    Contact *temp = head;

    printf("\n --- Contact List -------\n");

    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf(" ---------------\n");
        temp = temp->next;
    }
}


// Search Contact 

void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf(" 49[^\n]", name);


    Contact *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("\nContact Found\n");
            printf("Name: %s\n",temp->name);
            printf("Phone: %s\n",temp->phone);
            found = 1;
            break;


        }
        temp = temp->next;
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

// Delete Contact 

void deleteContact() {
    char name[50];

    printf("Enter name to delete: ");
    scanf(" %49[^\n]", name);

    Contact *temp = head;
    Contact *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Contact deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;

    }

    printf("Contact Not Found\n");

}

void FreeAll() {
    Contact *temp = head;

    while (temp != NULL) {
        Contact  *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
}

int main() {
    int choice;
    
    while (1) {
         printf("\n===== CONTACT MANAGER =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5:
                FreeAll();
                exit(0);
            default:
                printf("Invalid choice\n");    
        }
    }

    return 0;
}
