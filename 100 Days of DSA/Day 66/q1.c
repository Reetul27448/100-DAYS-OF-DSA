#include <stdio.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int DFS(int vertex, int n) {
    visited[vertex] = 1;
    recStack[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1) {
            if (!visited[i] && DFS(i, n)) {
                return 1; // Cycle detected
            } else if (recStack[i]) {
                return 1; // Cycle detected
            }
        }
    }

    recStack[vertex] = 0; // Remove from recursion stack
    return 0;
}
int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    
    // Initialize graph, visited and recStack arrays
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Directed graph
    }
    
    int cycleExists = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, n)) {
                cycleExists = 1;
                break;
            }
        }
    }
    
    if (cycleExists) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}