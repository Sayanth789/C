#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct node {
    int vertex;
    struct node *next;
} node;

node *G[MAX];
int visited[MAX];
int n;

/* Function prototypes */
void insert(int vi, int vj);
void readGraph(void);
void DFS(int v);

void readGraph(void) {
    int i, j, vi, vj, no_of_edges;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        G[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        printf("Enter number of edges for vertex %d: ", i);
        scanf("%d", &no_of_edges);

        for (j = 0; j < no_of_edges; j++) {
            printf("Enter edge (u v): ");
            scanf("%d %d", &vi, &vj);

            if (vi >= 0 && vi < n && vj >= 0 && vj < n)
                insert(vi, vj);
            else
                printf("Invalid edge!\n");
        }
    }
}

void insert(int vi, int vj) {
    node *q = malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;

    if (G[vi] == NULL) {
        G[vi] = q;
    } else {
        node *p = G[vi];
        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}

void DFS(int v) {
    node *p;

    visited[v] = 1;
    printf("%d ", v);

    for (p = G[v]; p != NULL; p = p->next) {
        int adj = p->vertex;
        if (!visited[adj])
            DFS(adj);
    }
}

int main(void) {
    int i;

    readGraph();

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);
    printf("\n");

    return 0;
}
