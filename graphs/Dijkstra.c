
/*Input format:
    First line would contain number n, which represents number of nodes in the graph (1 to n).
    Next n line would represent cost matrix. Where each line, representing a distance vector for that node, will have n numbers (separated by space) to represent direct distance from that node to all other nodes.
    Distance from node to itself is 0 and -1 if there is no direct edge to any node.
    Last line would contain node number of the source whose shortest distance from each other node need to be calculated.

Output format:
    Output is n lines containing 3 information per line (separated by space):
    Destination node, Shortest Distance to that node and path from source to that node.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Edge {
    Node* dest;
    int weight;
} Edge;

struct Node {
    int data;
    Edge** adj_list;
    int connected_vertices;
    int weight;
    int is_visited;
    Node* parent;
};

Node** vertices;
int N;

/* Create an edge */
Edge* createEdge(Node* dest, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->dest = dest;
    e->weight = weight;
    return e;
}

/* Add edge from src to dest */
void addEdge(Node* src, Node* dest, int weight) {
    src->adj_list[src->connected_vertices++] = createEdge(dest, weight);
}

/* Find unvisited node with smallest tentative distance */
Node* findSmallest(void) {
    Node* min = NULL;

    for (int i = 0; i < N; i++) {
        if (!vertices[i]->is_visited && vertices[i]->weight != -1) {
            if (min == NULL || vertices[i]->weight < min->weight) {
                min = vertices[i];
            }
        }
    }
    return min;
}

/* Dijkstra (recursive version, close to your logic) */
void Dijks(Node* start) {
    start->is_visited = 1;

    for (int i = 0; i < start->connected_vertices; i++) {
        Edge* e = start->adj_list[i];
        Node* dest = e->dest;

        if (!dest->is_visited) {
            int new_dist = start->weight + e->weight;
            if (dest->weight == -1 || new_dist < dest->weight) {
                dest->weight = new_dist;
                dest->parent = start;
            }
        }
    }

    Node* next = findSmallest();
    if (next != NULL) {
        Dijks(next);
    }
}

/* Print shortest path */
void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf(" %d", node->data);
}

int main(void) {
    int w;

    scanf("%d", &N);

    /* Allocate vertices */
    vertices = (Node**)malloc(sizeof(Node*) * N);
    for (int i = 0; i < N; i++) {
        vertices[i] = (Node*)malloc(sizeof(Node));
        vertices[i]->data = i + 1;
        vertices[i]->adj_list = (Edge**)malloc(sizeof(Edge*) * N);
        vertices[i]->connected_vertices = 0;
        vertices[i]->weight = -1;
        vertices[i]->is_visited = 0;
        vertices[i]->parent = NULL;
    }

    /* Read adjacency matrix */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &w);

            if (i == j && w != 0) {
                printf("Diagonal must be 0\n");
                exit(1);
            }

            if (w < -1) {
                printf("Invalid weight\n");
                exit(1);
            }

            if (w > 0) {
                addEdge(vertices[i], vertices[j], w);
            }
        }
    }

    int start;
    scanf("%d", &start);

    vertices[start - 1]->weight = 0;
    Dijks(vertices[start - 1]);

    /* Output results */
    for (int i = 0; i < N; i++) {
        printf("Vertex %d | Distance: %d | Path:",
               i + 1,
               vertices[i]->weight);
        printPath(vertices[i]);
        printf("\n");
    }

    return 0;
}
