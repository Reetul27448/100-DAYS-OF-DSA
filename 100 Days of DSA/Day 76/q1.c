#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
void DFS(int vertex, int n) {
    visited[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, n);
        }
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1; // Assuming vertices are 1-indexed
        graph[v - 1][u - 1] = 1; // Undirected graph
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n);
            count++;
        }
    }
    
    printf("Number of connected components: %d\n", count);
    
    return 0;
}
