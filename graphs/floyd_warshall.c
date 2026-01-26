#include <stdio.h>
#include <limits.h>

#define INF (INT_MAX / 10)

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    int AdjList[n][n];

    /* Initialize adjacency matrix */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                AdjList[i][j] = INF;
            else
                AdjList[i][j] = 0;
        }
    }

    printf("Enter edges (u v weight) [0-based indexing]:\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        AdjList[u][v] = w;
        AdjList[v][u] = w;   // undirected graph
    }

    /* Floyd–Warshall Algorithm */
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AdjList[i][j] =
                    min(AdjList[i][j],
                        AdjList[i][k] + AdjList[k][j]);
            }
        }
    }

    /* Print result */
    printf("\nAll-pairs shortest paths:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (AdjList[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", AdjList[i][j]);
        }
        printf("\n");
    }

    return 0;
}
