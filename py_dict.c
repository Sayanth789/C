// A simplified python style dictionary.
/* 
It is implemented using the linked list than actual python, which uses hashing.


struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

Each node stores: 
key 
Value 
Pointer to next node 

[z : W] -> [y : B] -> [c : C] -> [a : D]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

struct pydict {
    struct dnode *head;
    struct dnode *tail;
    int count;
};

struct pydict *pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

void pydict_del(struct pydict* self) {
    struct dnode *cur, *next;

    for(cur = self->head; cur; cur = next) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
    }

    free(self);
}

void pydict_print(struct pydict* self)
{
    struct dnode *cur;

    printf("{");

    for(cur = self->head; cur != NULL; cur = cur->next) {

        printf("'%s': '%s'", cur->key, cur->value);

        if(cur->next)
            printf(", ");
    }

    printf("}\n");
}

int pydict_len(const struct pydict* self)
{
    return self->count;
}

struct dnode* pydict_find(struct pydict* self, char *key)
{
    struct dnode *cur;

    for(cur = self->head; cur != NULL; cur = cur->next) {

        if(strcmp(cur->key, key) == 0)
            return cur;
    }

    return NULL;
}

char* pydict_get(struct pydict* self, char *key)
{
    struct dnode *node = pydict_find(self, key);

    if(node)
        return node->value;

    return NULL;
}

void pydict_put(struct pydict* self, char *key, char *value)
{
    struct dnode *node = pydict_find(self, key);

    if(node) {

        free(node->value);
        node->value = strdup(value);
        return;
    }

    node = malloc(sizeof(*node));

    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;

    if(self->tail)
        self->tail->next = node;
    else
        self->head = node;

    self->tail = node;
    self->count++;
}

int main(void)
{
    struct dnode *cur;
    struct pydict *dct = pydict_new();

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);

    pydict_put(dct, "z", "W");
    pydict_print(dct);

    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");

    pydict_print(dct);

    printf("Length = %d\n", pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");

    for(cur = dct->head; cur != NULL ; cur = cur->next ) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);
}