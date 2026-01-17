#include <stdio.h>
#include <limits.h>

#define MAX 50

int graph[MAX][MAX];
int isvisited[MAX];
int dist[MAX];

int minDistance(int n) {
    int min = INT_MAX;
    int min_vertex = -1;

    for (int v = 0; v < n; v++) {
        if (!isvisited[v] && dist[v] < min) {
            min = dist[v];
            min_vertex = v;
        }
    }
    return min_vertex;
}

void display(int src, int n) {
    printf("\nVertex\tDistance from source %d\n", src);
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijkstra(int src, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        isvisited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(n);
        if (u == -1) break;

        isvisited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!isvisited[v] && graph[u][v] > 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    display(src, n);
}

int main() {
    int n, edges, src;
    int u, v, w;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v w): ");
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(src, n);
    return 0;
}
