/*
find_file: Locate a previously created file descriptor or
* make a new one if necessary.
*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_HASH 101


typedef struct file_node {
    char *fname;
    struct file_node *flink;
} *file;

int hash_filename(const char *s);
file allocate_file(const char *s);
file find_filename(const char *s);


file file_hash_table[FILE_HASH] = { NULL };




int hash_filename(const char *s) {
    int length = strlen(s);
    if (length == 0)
        return 0;

    return (length + 4 * (s[0] + 4 * s[length/2])) % FILE_HASH;
}

file allocate_file(const char *s) {
    file f = (file)malloc(sizeof(struct file_node));


    if (f == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    f->fname = strdup(s);
    f->flink = NULL;


    return f;
}

file find_filename (const char *s) {
    int hash_value = hash_filename(s);


    file f;

    for ( f = file_hash_table[hash_value]; f != NULL; f=f->flink) {
        if (strcmp(f->fname, s) == 0) {
            return f;
        }
    }
    /* Fine not found so make a new one. */
    f = allocate_file(s);
    f->flink = file_hash_table[hash_value];
    file_hash_table[hash_value] = f;
    return f;

}


int main() {

    file f1 = find_filename("test.txt");
    file f2 = find_filename("hello.c");
    file f3 = find_filename("test.txt");

    printf("File 1: %s\n", f1->fname);
    printf("File 2: %s\n", f2->fname);
    printf("File 3: %s\n", f3->fname);

    if (f1 ==  f3) {
        printf("Same File node reused for test.txt\n");


    }

    return 0;
}