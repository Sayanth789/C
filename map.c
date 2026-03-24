#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MapEntry {
    char *key;
    int value;
    struct MapEntry *next;

};


struct Map {

    struct MapEntry *head;
    int count;

    void (*put)(struct Map*, char*, int);
    int  (*get)(struct Map*, char*, int);
    int (*size)(struct Map*);
    void (*dump)(struct Map*);
    void (*del)(struct Map*);    

};

// -------------Function Implementation -------------------------------

void Map_put(struct Map *self, char *key, int value) {
    struct MapEntry *cur;

    for (cur = self->head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->key, key) == 0) {
            cur->value = value;
            return;    
            
        }
          
    }

    cur = malloc(sizeof(*cur));
    cur->key = strdup(key);
    cur->value = value;
    cur->next = self->head;

    self->head = cur;
    self->count++;
}

int Map_get(struct Map *self, char *key, int def) {

    struct MapEntry *cur;

    for (cur = self->head; cur != NULL; cur = cur->next) {
        if (strcmp(cur->key, key) == 0)
            return cur->value;
    }
    return def;
}

int Map_size(struct Map *self) {
    return self->count;
}

void Map_dump(struct Map *self) {

    struct MapEntry *cur;

    printf("{");

    for (cur = self->head; cur!= NULL; cur = cur->next) {
        printf("%s:%d", cur->key, cur->value);
    }

    printf("}\n");
}

void Map_delete(struct Map *self) {
    struct MapEntry *cur = self->head;
    struct MapEntry *next;


    while (cur) {
        next = cur->next;
        free(cur->key);
        free(cur);
        cur = next;
    }
    free(self);
}


/* Constructor */

struct Map *Map_new() {

    struct Map *map = malloc(sizeof(*map));

    map->head = NULL;
    map->count = 0;

    map->put = Map_put;
    map->get  = Map_get;
    map->size = Map_size;
    map->dump = Map_dump;
    map->del  = Map_delete;

    return map;

}


int main(void) {

    struct Map *map = Map_new();
    // struct MapEntry *cur;

    printf("Map test\n");
    map->put(map, "z", 8);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "a", 4);
    map->dump(map);


    printf("size=%d\n", map->size(map));

    printf("z=%d\n", map->get(map, "z", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    /* We have no iterator for the sake of now */
    map->del(map);




}