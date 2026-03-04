#include <stdio.h>
#include <stdlib.h>

#define INF 999999

int* Dijkstra(int *L, int n) {
    int *dist = (int*)malloc(n * sizeof(int));
    int *visited = (int*)malloc(n * sizeof(int));

    int i, count, u, v;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = 0;

    for (count = 0; count < n - 1; count++) {

        int min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (v = 0; v < n; v++) {
            int weight = L[u * n + v];
            if (!visited[v] && weight != -1 &&
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    free(visited);
    return dist;
}

int main() {
    int n = 5, i, j;
    int *d, *g;

    g = (int*)malloc(n * n * sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i * n + j] = -1;

    g[0 * n + 1] = 100; g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;  g[0 * n + 4] = 10;

    g[1 * n + 2] = 20;  g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;  g[4 * n + 3] = 10;

    d = Dijkstra(g, n);

    for (i = 1; i < n; i++)
        printf("%d ", d[i]);

    free(g);
    free(d);

    return 0;
}