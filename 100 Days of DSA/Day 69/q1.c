#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int distance[MAX];
void dijkstra(int n, int source) {
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        distance[i] = 1e9; // Initialize distances to infinity
    }
    distance[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDistance = 1e9, minIndex;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                minIndex = i;
            }
        }
        visited[minIndex] = 1;

        for (int j = 0; j < n; j++) {
            if (graph[minIndex][j] && !visited[j] && distance[minIndex] != 1e9 &&
                distance[minIndex] + graph[minIndex][j] < distance[j]) {
                distance[j] = distance[minIndex] + graph[minIndex][j];
            }
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
    
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w; // Directed graph
    }
    
    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    
    dijkstra(n, source);
    
    return 0;
}
