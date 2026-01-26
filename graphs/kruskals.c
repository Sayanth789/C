#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* -------------------------------------------------
   Utility function: Exit program on memory failure
--------------------------------------------------*/
void leave(void) {
    fprintf(stderr, "Could not allocate memory\n");
    exit(EXIT_FAILURE);
}

/* -------------------------------------------------
   Structure to represent an edge in a graph
   u -> source vertex
   v -> destination vertex
   w -> weight of the edge
--------------------------------------------------*/
struct edge {
    int u, v, w;
};

/* -------------------------------------------------
   Comparator function for qsort
   Sorts edges in ascending order of weight
--------------------------------------------------*/
int edge_comp(const void *a, const void *b) {
    const struct edge *ea = a;
    const struct edge *eb = b;

    return (ea->w > eb->w) - (ea->w < eb->w);
}

/* -------------------------------------------------
   Union-Find / Disjoint Set data structure
--------------------------------------------------*/
struct ufds {
    int *parent;   // Parent of each node
    int *rank;     // Rank (tree height approximation)
    int *size;     // Size of each set
    int num_sets;  // Number of disjoint sets
};

/* -------------------------------------------------
   Initialize Union-Find with n elements
--------------------------------------------------*/
struct ufds *ufds_init(int n) {
    struct ufds *uf = malloc(sizeof *uf);
    if (!uf) leave();

    uf->parent = malloc(sizeof(int) * n);
    uf->rank   = malloc(sizeof(int) * n);
    uf->size   = malloc(sizeof(int) * n);

    if (!uf->parent || !uf->rank || !uf->size)
        leave();

    uf->num_sets = n;

    /* Each element starts in its own set */
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;  // Parent is itself
        uf->rank[i] = 0;    // Initial rank
        uf->size[i] = 1;    // One element per set
    }

    return uf;
}

/* -------------------------------------------------
   Find the representative (root) of a set
   Uses path compression for efficiency
--------------------------------------------------*/
int find_set(int i, struct ufds *uf) {
    if (uf->parent[i] != i)
        uf->parent[i] = find_set(uf->parent[i], uf);

    return uf->parent[i];
}

/* -------------------------------------------------
   Check if two elements belong to the same set
--------------------------------------------------*/
int in_same_set(int i, int j, struct ufds *uf) {
    return find_set(i, uf) == find_set(j, uf);
}

/* -------------------------------------------------
   Union two sets using rank heuristic
--------------------------------------------------*/
void union_set(int i, int j, struct ufds *uf) {
    int ri = find_set(i, uf);
    int rj = find_set(j, uf);

    /* Already in same set */
    if (ri == rj) return;

    /* Attach smaller rank tree under larger rank tree */
    if (uf->rank[ri] < uf->rank[rj]) {
        uf->parent[ri] = rj;
        uf->size[rj] += uf->size[ri];
    } else {
        uf->parent[rj] = ri;
        uf->size[ri] += uf->size[rj];

        if (uf->rank[ri] == uf->rank[rj])
            uf->rank[ri]++;
    }

    uf->num_sets--;
}

/* -------------------------------------------------
   Free Union-Find memory
--------------------------------------------------*/
void ufds_destroy(struct ufds *uf) {
    free(uf->parent);
    free(uf->rank);
    free(uf->size);
    free(uf);
}

/* -------------------------------------------------
   Kruskal's Algorithm
   num_vertices -> number of vertices in graph
   num_edges    -> number of edges
   elist        -> array of edges
   Returns total MST cost
--------------------------------------------------*/
int kruskals(int num_vertices, int num_edges, struct edge *elist) {

    /* Create Union-Find structure */
    struct ufds *uf = ufds_init(num_vertices);
    int cost = 0;

    /* Sort edges by increasing weight */
    qsort(elist, num_edges, sizeof(struct edge), edge_comp);

    /* Process edges in sorted order */
    for (int i = 0; i < num_edges && uf->num_sets > 1; i++) {
        struct edge *e = &elist[i];

        /* Include edge if it does not form a cycle */
        if (!in_same_set(e->u, e->v, uf)) {
            cost += e->w;
            union_set(e->u, e->v, uf);
        }
    }

    ufds_destroy(uf);
    return cost;
}

/* -------------------------------------------------
   Test case
--------------------------------------------------*/
int test1(void) {
    struct edge elist[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int num_vertices = 4;
    int num_edges = sizeof(elist) / sizeof(elist[0]);

    return kruskals(num_vertices, num_edges, elist);
}

/* -------------------------------------------------
   Main function
--------------------------------------------------*/
int main(void) {
    int cost = test1();
    printf("MST cost = %d\n", cost);
    // printf("Kruskal test passed ✔\n");
    return EXIT_SUCCESS;
}
