#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

// ---------------- ADD STUDENT ----------------
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(Student), 1, fp);

    fclose(fp);

    printf("Student added successfully!\n");
}

// ---------------- DISPLAY STUDENTS ----------------
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    Student s;

    printf("\n---- Student List ----\n");

    while (fread(&s, sizeof(Student), 1, fp)) {
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Marks: %.2f\n", s.marks);
        printf("----------------------\n");
    }

    fclose(fp);
}

// ---------------- UPDATE STUDENT ----------------
void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    int id, found = 0;
    Student s;

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter new Age: ");
            scanf("%d", &s.age);

            printf("Enter new Marks: ");
            scanf("%f", &s.marks);

            found = 1;
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Student updated successfully!\n");
    else
        printf("Student not found!\n");
}

// ---------------- DELETE STUDENT ----------------
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No record found!\n");
        return;
    }

    int id, found = 0;
    Student s;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(Student), 1, fp)) {
        if (s.id == id) {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Student deleted!\n");
    else
        printf("Student not found!\n");
}

// ---------------- MAIN MENU ----------------
int main() {
    int choice;

    while (1) {
        printf("\n===== Student System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}