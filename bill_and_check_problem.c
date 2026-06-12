/*

We solve it using a HT: 
Inserting all bill ID to HT.
For every Check 
    Look up the CUstomer ID 
    If found, remove it from the HT.
After processing all checks.
    Every ID remaining in HT represents an unpaid bill.

===============================    ===============================
        PSUEDOCODE   PSUEDOCODE   PSUEDOCODE   PSUEDOCODE   PSUEDOCODE
===============================    ===============================

for each_bill
    hash_insert(bill.customer_id)

for each check
    hash_delete(check.customer_id)

for each remaining entry in hash table
   print unpaid customer 
    
    
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1009 

typedef struct Node {
    int customer_id;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE] = {NULL};

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int customer_id) {
    int index = hash(customer_id);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->customer_id = customer_id;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}


void delete(int customer_id) {
    int index = hash(customer_id);

    Node* current = hashTable[index];
    Node* previous = NULL;

    while (current != NULL) {
        if (current->customer_id == customer_id) {
            if (previous == NULL) {
                hashTable[index] = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void printunPaidCustomers() {
    printf("Customers whoo did not pay:\n");

    for (int i =0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];

        while (current != NULL) {
            printf("%d\n", current->customer_id);
            current = current->next;
        }
    }

}


void freeTable() {
    for (int i =0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];


        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int bills[] = {101, 102, 103, 104, 105};
    int checks[] = {102, 105, 101};


    int numBills = sizeof(bills) / sizeof(bills[0]);
    int numChecks = sizeof(checks) / sizeof(checks[0]);

    // Insert all billed customers 
    for (int i = 0; i < numBills; i++) {
        insert(bills[i]);
    }

    // Remove customers who paid 
    for (int i =0; i < numChecks; i++){
        delete(checks[i]);
    }


    // Remaining customers are unpaid 

    printunPaidCustomers();

    freeTable();

    return 0;
}