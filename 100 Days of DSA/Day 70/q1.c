#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int distance[MAX];
void bellmanFord(int n, int m, int edges[MAX][3], int source) {
    for (int i = 0; i < n; i++) {
        distance[i] = 1e9; // Initialize distances to infinity
    }
    distance[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (distance[u] != 1e9 && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (distance[u] != 1e9 && distance[u] + w < distance[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++) {
        if (distance[i] == 1e9) {
            printf("INF ");
        } else {
            printf("%d ", distance[i]);
        }
    }
    printf("\n");
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    int edges[MAX][3];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }
    
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    bellmanFord(n, m, edges, source);
    
    return 0;
}