#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"

typedef struct {
    int id;
    char title[50];
    char author[50];
    int available;  // 1 = available, 0 = issued

} Book;


// Adding book 
void addBook() {
    FILE *fp = fopen(FILE_NAME, "ab");  // append binary


    if (fp  == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Book b;

    printf("Enter Book ID: ");
    scanf("%d", &b.id);


    printf("Enter book title: ");
    scanf(" %49[^\n]", b.title);


    printf("Enter author name: ");
    scanf(" %49[^\n]", b.author);

    b.available = 1;

    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);

    printf("Book added successfully!\n");

}

// Display book 
void displayBooks() {
    FILE *fp = fopen(FILE_NAME, "rb");


    if (fp == NULL) {
        printf("No record found\n");
        return;
    }

    Book b;

    printf("\n----- Library Books -----\n");

    while (fread(&b, sizeof(Book), 1, fp)) {
        printf("ID : %d\n", b.id);
        printf("Title: %s\n", b.title);
        printf("Author: %s\n", b.author);
        printf("Status: %s\n", b.available ? "Available": "Issued");
        printf("------------------------------\n");


    }

    fclose(fp);
}

// Search Book 
void searchBook() {
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    int id, found = 0;
    Book b;

    printf("Enter Book  ID to search: \n");
    scanf("%d", &b.id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id) {
             printf("\nBook Found!\n");
            printf("Title: %s\n", b.title);
            printf("Author: %s\n", b.author);
            printf("Status: %s\n", b.available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
    fclose(fp);

}


// Issue Book 
void issueBook () {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No record found\n");
        return;
    }
    int id, found = 0;
    Book b;

    printf("Enter Book id to issue: ");
    scanf("%d", &b.id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id && b.available == 1) {
            b.available = 0;
            found = 1;
        }

        fwrite(&b, sizeof(Book), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Book issused successfully: \n");
    }
    else {
        printf("Book is not available or not found\n");
    }
}

// Return Book 

void returnBook() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    int id, found = 0;
    Book b;


    printf("Enter Book ID to return: ");
    scanf("%d", &b.id);

    while (fread(&b, sizeof(Book), 1, fp)) {
        if (b.id == id && b.available == 0) {
            b.available = 1;
            found = 1;
        }

        fwrite(&b, sizeof(Book), 1, temp);

    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Book returned successfully!\n");
    else
        printf("Book not found or already available!\n");
    
}

int main() {
    int choice;

    while (1) {
        printf("\n ============= LIBRABRY SYSTEM ==============\n");
         printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;

}