/*
Input format:
    First line would contain number n, which represents number of nodes in the graph (1 to n).
    Next n line would represent cost matrix. Where each line, representing a distance vector for that node, will have n numbers (separated by space) to represent direct distance from that node to all other nodes.
    Distance from node to itself and to the non-adjacent node must be 0.
Last line would contain the starting node.

Output format:
    Output is n-1 lines containing the edge and weight of that edge (separated by tab) which is included in the minimum spanning tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node Node;

typedef struct Edge {
    Node* dest;
    int weight;
} Edge;

struct Node {
    int data;
    Edge** adj_list;
    int connected_vertices;
    int isVisited;
    int weight;
    Node* parent;
};

Edge* createEdge(Node* dest, int weight) {
    Edge* e = malloc(sizeof(Edge));
    e->dest = dest;
    e->weight = weight;
    return e;
}

void addEdge(Node* src, Node* dest, int weight) {
    src->adj_list[src->connected_vertices++] = createEdge(dest, weight);
}

void prim(Node** vertices, int N) {
    int edges_used = 0;

    while (edges_used < N - 1) {
        int min = INT_MAX;
        Node* next = NULL;
        Node* from = NULL;

        for (int i = 0; i < N; i++) {
            if (vertices[i]->isVisited) {
                for (int j = 0; j < vertices[i]->connected_vertices; j++) {
                    Edge* e = vertices[i]->adj_list[j];
                    if (!e->dest->isVisited && e->weight < min) {
                        min = e->weight;
                        next = e->dest;
                        from = vertices[i];
                    }
                }
            }
        }

        if (next == NULL) {
            printf("Graph is disconnected\n");
            return;
        }

        next->isVisited = 1;
        next->parent = from;
        next->weight = min;
        edges_used++;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Node** vertices = malloc(sizeof(Node*) * N);

    for (int i = 0; i < N; i++) {
        vertices[i] = malloc(sizeof(Node));
        vertices[i]->adj_list = malloc(sizeof(Edge*) * N);
        vertices[i]->data = i + 1;
        vertices[i]->connected_vertices = 0;
        vertices[i]->isVisited = 0;
        vertices[i]->weight = INT_MAX;
        vertices[i]->parent = NULL;
    }

    // adjacency matrix input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int w;
            scanf("%d", &w);
            if (w > 0)
                addEdge(vertices[i], vertices[j], w);
        }
    }

    int start;
    scanf("%d", &start);

    vertices[start - 1]->isVisited = 1;
    vertices[start - 1]->weight = 0;

    prim(vertices, N);

    printf("MST edges:\n");
    for (int i = 0; i < N; i++) {
        if (vertices[i]->parent) {
            printf("%d - %d\t%d\n",
                vertices[i]->parent->data,
                vertices[i]->data,
                vertices[i]->weight);
        }
    }
}
